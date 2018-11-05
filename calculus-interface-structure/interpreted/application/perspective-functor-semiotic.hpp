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

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(calculus, constant, recursed, identity)
	#include nik_typedef(calculus, constant, recursed, functor)

	#define safe_name

		#include nik_typedef(calculus, interpreted, environment, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, lambda, identity)
	#include nik_typedef(calculus, interpreted, lambda, functor)
	#include nik_typedef(calculus, interpreted, begin, identity)
	#include nik_typedef(calculus, interpreted, begin, functor)

	#include nik_typedef(calculus, interpreted, application, identity)

/*
	list_of_values:
*/

	template<typename Expressions, typename Environment, typename Functor>
	struct list_of_values
	{
		using Exps	= typename Expressions::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename if_then_else
		<
			is_null<Exps>, // has_no_operands
			null_list,

			cons
			<
				typename Func::template evaluate
				<
					car<Exps>, // first operand
					Env
				>,

				list_of_values
				<
					cdr<Exps>, // rest_operands
					Env,
					Func
				>
			>

		>::rtn;
	};

/*
	apply_operate:

	Assumes the template parameters have already been 
*/

	template<typename Operate, typename Arguments>
	struct apply_operate
	{
		template<typename> struct strict;

		template<typename Value, typename... Values, template<typename...> class Sequence>
		struct strict<Sequence<Value, Values...>>
		{
			using rtn = typename Value::kind::functor::template apply
			<
				typename Operate::rtn, Value, Values...

			>::rtn;
		};

		using rtn = typename strict
		<
			typename Arguments::rtn

		>::rtn;
	};

/*
	apply:
*/

	template<typename Procedure, typename Arguments>
	struct apply
	{
		using Proc	= typename Procedure::rtn;
		using Values	= typename Arguments::rtn;

		using rtn = typename evaluate
		<
			if_then
			<
				is_operate<Proc>, // is_primitive
				apply_operate<Proc, Values>

			>, else_then
			<
				is_compound<Proc>,

				evaluate_sequence
				<
					procedure_body<Proc>,

					intenf_construct // extend_environment
					<
						procedure_arguments<Proc>,
						Values,
						procedure_environment<Proc>
					>,

					procedure_functor<Proc>
				>

			>, then
			<
				error<'u', 'n', 'k', 'n', 'o', 'w', 'n',
					' ', 'p', 'r', 'o', 'c', 'e', 'd', 'u', 'r', 'e', ' ', 't', 'y', 'p', 'e'>
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

/*
	template<typename Exp>
	inline static void display(const <Exp> &)
	{
		Dispatched::functor::display("");
		Exp::kind::functor::display(Exp());
	}
*/
};

