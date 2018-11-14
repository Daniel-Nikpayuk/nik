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

	#define safe_name

		#include nik_typedef(calculus, constant, recursed, identity)
		#include nik_typedef(calculus, constant, recursed, functor)

		#include nik_typedef(calculus, interpreted, environment, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, quote, identity)
	#include nik_typedef(calculus, interpreted, assignment, identity)
	#include nik_typedef(calculus, interpreted, assignment, functor)
	#include nik_typedef(calculus, interpreted, definition, identity)
	#include nik_typedef(calculus, interpreted, definition, functor)
	#include nik_typedef(calculus, interpreted, conditional, identity)
	#include nik_typedef(calculus, interpreted, conditional, functor)
	#include nik_typedef(calculus, interpreted, lambda, identity)
	#include nik_typedef(calculus, interpreted, lambda, functor)
	#include nik_typedef(calculus, interpreted, begin, identity)
	#include nik_typedef(calculus, interpreted, begin, functor)
	#include nik_typedef(calculus, interpreted, application, identity)
	#include nik_typedef(calculus, interpreted, application, functor)

	#include nik_typedef(calculus, interpreted, expression, structure)
	#include nik_typedef(calculus, interpreted, expression, identity)

/*
	evaluate:
*/

	template<typename Expression, typename Environment = null_environment>
	struct evaluate
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;

		using rtn = typename conref_evaluate
		<
			if_then
			<
				is_self_evaluating<Exp>,
				Exp

			>, else_then
			<
				conrei_is_literal<Exp>, // is_variable
				intenf_lookup<Exp, Env>

			>, else_then
			<
				is_quote<Exp>,
				conref_car<Exp> // text_of_quotation

			>, else_then
			<
				is_assignment<Exp>,
				evaluate_assignment<Exp, Env, functor>

			>, else_then
			<
				is_value_definition<Exp>,
				evaluate_value_definition<Exp, Env, functor>

			>, else_then
			<
				is_if_<Exp>,
				evaluate_if_<Exp, Env, functor>

			>, else_then
			<
				is_lambda<Exp>,
				make_procedure
				<
					conref_car<Exp>, // lambda_arguments
					conref_cdr<Exp>, // lambda_body
					functor,
					Env,
					null_frame
				>

			>, else_then
			<
				is_begin<Exp>,
				evaluate_sequence
				<
					Exp, // begin_actions
					Env,
					functor
				>

			>, else_then
			<
				is_cond<Exp>,
				evaluate
				<
					cond_to_if_<Exp>,
					Env
				>

			>, else_then
			<
				is_application<Exp>,
				evaluate_application
				<
					conref_car<Exp>, // operator
					conref_cdr<Exp>, // operands
					Env,
					functor
				>

			>, then
			<
				error<'u', 'n', 'k', 'n', 'o', 'w', 'n',
					' ', 'e', 'x', 'p', 'r', 'e', 's', 's', 'i', 'o', 'n', ' ', 't', 'y', 'p', 'e'>
			>

		>::rtn;
	};

	template<typename Env>
	struct evaluate<null_expression, Env>
	{
		using rtn = boolean<false>;
	};

/*
	interpret:
*/

	template<typename Program, typename Env = null_environment>
	struct interpret
	{
		using rtn = typename evaluate
		<
			make_begin<Program>,
			Env
 
		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp, typename... Exps>
	inline static void display(const expression<Exp, Exps...> & e)
	{
		using is_empty = typename conrei_is_null<expression<Exps...>>::rtn;

		Dispatched::functor::display("expression:\n ");

		Recursed::functor::display(expression<Exp, Exps...>(), ", ");
		Dispatched::functor::display('\n');
	}

	inline static void display(const null_expression &)
	{
		Dispatched::functor::display("expression: null\n");
	}
};

