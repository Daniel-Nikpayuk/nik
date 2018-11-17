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

	#include nik_typedef(calculus, interpreted, normal, structure)
	#include nik_typedef(calculus, interpreted, normal, identity)

	#include"error-functor-semiotic.hpp"
	#include"environment-functor-semiotic.hpp"
	#include"quote-functor-semiotic.hpp"
	#include"lambda-functor-semiotic.hpp"
	#include"definition-functor-semiotic.hpp"
	#include"assignment-functor-semiotic.hpp"
	#include"if_-functor-semiotic.hpp"
	#include"begin-functor-semiotic.hpp"
	#include"cond-functor-semiotic.hpp"
	#include"application-functor-semiotic.hpp"

/*
	normal order evaluation:
*/

	template<typename Expression, typename Environment = null_environment>
	struct eval
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;

		using rtn = typename evaluate
		<
			if_then
			<
				is_self_evaluating<Exp>,
				Exp

			>, else_then
			<
				is_literal<Exp>, // is_variable
				environment_lookup<Exp, Env>

			>, else_then
			<
				is_quote<Exp>,
				car<Exp> // text_of_quotation

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
				procedure_make
				<
					car<Exp>, // lambda_arguments
					cdr<Exp>, // lambda_body
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
					car<Exp>, // operator
					cdr<Exp>, // operands
					Env,
					functor
				>

			>, then
			<
				error_unknown_expression_type
			>

		>::rtn;
	};

	template<typename Env>
	struct eval<null_expression, Env>
	{
		using rtn = boolean<false>;
	};

/*
	template<typename, typename = null_environment, size_type...> struct trampoline;

	template<typename Program, typename Env>
	struct trampoline<Program, Env>
	{
		using rtn = error<'n', 'e', 's', 't', 'i', 'n', 'g', ' ',
					'd', 'e', 'p', 't', 'h', ' ',
					'r', 'e', 'a', 'c', 'h', 'e', 'd'>; // "nesting depth reached"
	};

	template<typename Program, typename Env, size_type depth, size_type... depths>
	struct trampoline<Program, Env, depth, depths...>
	{
		using Continuation = typename evaluate
		<
			make_begin<Program>,
			Env
 
		>::rtn;

		using rtn = typename if_then_else
		<
			is_continuation<first>,

			if_then_else
			<
				(depth == 0),

				trampoline
				<
					car<Continuation>,	// Program
					car<Continuation, one>,	// Env,

					depths...
				>,

				trampoline
				<
					car<Continuation>,	// Program
					car<Continuation, one>,	// Env,

					depths...
				>,
			>,

			Continuation

		>::rtn;
	};
*/

	template<typename Program, typename Env = null_environment>
	struct interpret
	{
		using rtn = typename eval
		<
			relabel<Program, begin>,
			Env
 
		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

/*
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
*/
};

