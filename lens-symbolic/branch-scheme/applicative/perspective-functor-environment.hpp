/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*/

	struct map_to_binding
	{
		template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
			typename Cond, typename Result, nik::global_size_type index, Type... Values>
		using result = binding<Result, ListType<Values...>>;
	};

/*
	binding:
*/

	template<typename Var, typename Val>
	using binding_make = binding<Var, Val>;

	template<typename Binding>
	using binding_variable = typename_typename_car<Binding>;

	template<typename Exp>
	using binding_value = typename_typename_cdr<Binding>;

/*
	frame:
*/

	// make:

		//	Takes a list of variables as well as a list of values and creates
		//	a frame of bindings. This implementation assumes the variable
		//	and value lists are the same size.

	template<typename VarList, typename ValList>
	using frame_make = typename_zip<frame, binding_make, VarList, ValList>;

	// split:

		// necessary to simulate mutable lists.

	template<typename Var>
	struct frame_split_cond
	{
		template<typename Binding>
		using result = is_equal
		<
			binding_variable<Binding>, Var
		>;
	};

	template<typename Var, typename Frame>
	using frame_split = typename_split<frame_split_cond<Var>, Frame, map_to_binding>;

/*
	environment:
*/

	// make:

	template<typename VariableList, typename ValueList, typename Env = null_environment>
	using environment_make = typename_cons
	<
		frame_make
		<
			VariableList,
			ValueList
		>,

		Env
	>;

	// split:

		// necessary to simulate mutable lists.

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

	// lookup:

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

	// set:

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

	// define:

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

