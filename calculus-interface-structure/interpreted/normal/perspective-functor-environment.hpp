/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
**
** This file is part of nik.
**
** nik is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
**
** nik is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
** of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with nik. If not, see
** <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

/*
	Notes:

	Parameters are evaluated in the methods to which they are passed.
*/

/*
	binding:
*/

	template<typename Exp1, typename Exp2>
	struct binding_make
	{
		using rtn = binding
		<
			typename Exp1::rtn,
			typename Exp2::rtn
		>;
	};

	template<typename Exp>
	struct binding_variable
	{
		using rtn = typename Exp::rtn::variable;
	};

	template<typename Exp>
	struct binding_value
	{
		using rtn = typename Exp::rtn::value;
	};

/*
	frame:
*/

//	Takes a list of variables as well as a list of values and creates
//	a frame of bindings. This implementation assumes the variable
//	and value lists are the same size.

	template<typename Exp1, typename Exp2>
	struct frame_make
	{
		using VariableList	= typename Exp1::rtn;
		using ValueList		= typename Exp2::rtn;

		using rtn = typename if_then_else
		<
			is_null<VariableList>,
			null_frame,
			cons
			<
				binding_make
				<
					car<VariableList>,
					car<ValueList>
				>,

				frame_make
				<
					cdr<VariableList>,
					cdr<ValueList>
				>
			>

		>::rtn;
	};

	template<typename Exp1, typename Exp2, typename Exp3>
	struct frame_split
	{
		using Variable	= typename Exp1::rtn;
		using Frame1	= typename Exp2::rtn;
		using Frame2	= typename Exp3::rtn;

		template<typename SubExp1, typename SubExp2>
		struct recurse
		{
			using first	= typename SubExp1::rtn;
			using rest	= typename SubExp2::rtn;

			using rtn = typename if_then_else
			<
				is_equal
				<
					Variable,
					binding_variable<first>
				>,

				list<first, Frame1, rest>,

				frame_split
				<
					Variable,
					push<first, Frame1>,
					rest
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Frame2>,

			list
			<
				error_unbound_variable,
				Frame1,
				null_frame
			>,

			recurse
			<
				car<Frame2>,
				cdr<Frame2>
			>

		>::rtn;
	};

/*
	environment:
*/

	template<typename VariableList, typename ValueList, typename Env = null_environment>
	struct environment_make
	{
		using rtn = typename cons
		<
			frame_make
			<
				VariableList,
				ValueList
			>,

			Env

		>::rtn;
	};

	template<typename Exp1, typename Exp2, typename Exp3>
	struct environment_split
	{
		using Variable	= typename Exp1::rtn;
		using Env1	= typename Exp2::rtn;
		using Env2	= typename Exp3::rtn;

		template<typename SubExp1, typename SubExp2>
		struct recurse
		{
			using first	= typename SubExp1::rtn;
			using rest	= typename SubExp2::rtn;

			using result = typename frame_split
			<
				Variable,
				null_frame,
				first

			>::rtn;

			using rtn = typename if_then_else
			<
				is_error
				<
					car<result>
				>,

				environment_split
				<
					Variable,
					push<Env1, first>,
					rest
				>,

				catenate
				<
					result,
					list<Env1, rest>
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Env2>,

			list
			<
				error_unbound_variable,
				Env1,
				Env2
			>,

			recurse
			<
				car<Env2>,
				cdr<Env2>
			>

		>::rtn;
	};

	template<typename Variable, typename Env>
	struct environment_lookup
	{
		using rtn = typename binding_value
		<
			car
			<
				environment_split
				<
					Variable,
					null_environment,
					Env
				>
			>

		>::rtn;

		static_assert
		(
			!is_error<rtn>::rtn::value,
			"variable lookup error!"
		);
	};

	template<typename Exp1, typename Exp2, typename Exp3>
	struct environment_set
	{
		using Variable	= typename Exp1::rtn;
		using Value	= typename Exp2::rtn;
		using Env	= typename Exp3::rtn;

		using Tuple	= typename environment_split
		<
			Variable,
			null_environment,
			Env

		>::rtn;

		using Type	= typename car<Tuple>::rtn;

		using rtn	= typename if_then_else
		<
			is_error<Type>,

			Type,

			unite
			<
				car<Tuple, three>,

				unite
				<
					car<Tuple, one>,
					binding<Variable, Value>,
					car<Tuple, two>
				>,

				car<Tuple, four>
			>

		>::rtn;

		static_assert
		(
			!is_error<rtn>::rtn::value,
			"variable assignment error!"
		);
	};

	template<typename Exp1, typename Exp2, typename Exp3>
	struct environment_define
	{
		using Variable	= typename Exp1::rtn;
		using Value	= typename Exp2::rtn;
		using Env	= typename Exp3::rtn;

		template<typename SubExp1, typename SubExp2>
		struct local
		{
			using first = typename SubExp1::rtn;
			using rest = typename SubExp2::rtn;

			using Tuple = typename frame_split
			<
				Variable,
				null_frame,
				first

			>::rtn;

			using rtn = typename cons
			<
				if_then_else
				<
					is_error
					<
						car<Tuple>
					>,

					cons
					<
						binding<Variable, Value>,
						first
					>,

					unite
					<
						car<Tuple, one>,
						binding<Variable, Value>,
						car<Tuple, two>
					>
				>,

				rest

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Env>,

			environment
			<
				frame
				<
					binding<Variable, Value>
				>
			>,

			local
			<
				car<Env>,
				cdr<Env>
			>

		>::rtn;

		static_assert
		(
			!is_error<rtn>::rtn::value,
			"variable assignment error!"
		);
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Variable, typename Value>
	inline static void display(const binding<Variable, Value> & b)
	{
		Dispatched::functor::display("binding:\n <\n  ");
		Variable::kind::functor::display(Variable());
		Dispatched::functor::display(",\n  ");
		Value::kind::functor::display(Value());
		Dispatched::functor::display("\n >\n");
	}

	template<typename Binding, typename... Bindings>
	inline static void display(const frame<Binding, Bindings...> & f)
	{
		using is_empty = typename is_null<frame<Bindings...>>::rtn;

		Dispatched::functor::display("frame:\n ");
		Recursed::functor::display(frame<Binding, Bindings...>(), ", ");
	}

	inline static void display(const null_frame &)
	{
		Dispatched::functor::display("frame: null");
	}

	template<typename Frame, typename... Frames>
	inline static void display(const environment<Frame, Frames...> & e)
	{
		using is_empty = typename is_null<environment<Frames...>>::rtn;

		Dispatched::functor::display("environment:\n ");
		Recursed::functor::display(environment<Frame, Frames...>(), ", ");
	}

	inline static void display(const null_environment &)
	{
		Dispatched::functor::display("environment: null");
	}

