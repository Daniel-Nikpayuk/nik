/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	application_values_eval:

	Careful! design is broken as the input is not resolved beforehand.
*/

	template<typename, typename, typename> struct application_values_eval;

	template<typename Exp, typename... Exps, typename Env, typename Func, template<typename...> class ListType>
	struct application_values_eval<ListType<Exp, Exps...>, Env, Func>
	{
		using first = typename trampoline_eval
		<
			Exp, // first operand
			Env,
			Func,
			stack_depth,
			stack_depth

		>::rtn;

		using rtn = typename if_then_else
		<
			is_error<first>,

			first,

			cons
			<
				first,

				application_values_eval
				<
					ListType<Exps...>, // rest_operands
					Env,
					Func
				>
			>

		>::rtn;
	};

	// The list type returned must be preserved as it might be a continuation.

	template<typename Env, typename Func, template<typename...> class ListType>
	struct application_values_eval<ListType<>, Env, Func>
	{
		using rtn = ListType<>;
	};

/*
	application_apply_primitive:
*/

	template<typename, typename> struct application_apply_primitive;

	template<typename Operator, typename Value, typename... Values, template<typename...> class ListType>
	struct application_apply_primitive<Operator, ListType<Value, Values...>>
	{
		using rtn = typename Value::kind::functor::template apply
		<
			Operator,
			Value, Values...

		>::rtn;
	};

/*
	application_apply_compound:

	Reimplement to handle error returns.
*/

	template<typename Operator, typename Arguments, typename Environment, typename Functor>
	struct application_apply_compound
	{
		using Op	= typename Operator::rtn;
		using Args	= typename Arguments::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using Proc = typename trampoline_eval
		<
			Op,
			Env,
			Func,
			stack_depth,
			stack_depth

		>::rtn;

		using rtn = typename if_then_else
		<
			is_null					// previously called
			<
				cdr<Proc, two>			// (proc, args, body, ...)
			>,

			catenate
			<
				Proc,

				continuation
				<
					Env,
					Args
				>
			>,

			begin_eval
			<
				car<Proc, two>,			// body

				environment_make
				<
					car<Proc, one>,		// args
					Args,
					car<Proc, three>	// env
				>,

				Func
			>

		>::rtn;
	};

/*
	application_eval:
*/

	template<typename Operator, typename Arguments, typename Environment, typename Functor>
	struct application_eval
	{
		using Op	= typename Operator::rtn;
		using Args	= typename Arguments::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using Values	= typename application_values_eval
		<
			Args,
			Env,
			Func

		>::rtn;

		using rtn = typename if_then_else
		<
			is_operate<Op>,

			application_apply_primitive
			<
				Op,
				Values
			>,

			application_apply_compound
			<
				Op,
				Values,
				Env,
				Func
			>

		>::rtn;
	};

