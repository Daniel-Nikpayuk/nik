/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	#include"perspective-functor-environment.hpp"
	#include"perspective-functor-trampoline.hpp"
	#include"perspective-functor-lambda.hpp"
	#include"perspective-functor-definition.hpp"
	#include"perspective-functor-assignment.hpp"
	#include"perspective-functor-if_.hpp"
	#include"perspective-functor-begin.hpp"
	#include"perspective-functor-cond.hpp"
	#include"perspective-functor-application.hpp"

/*
	applicative order eval:
*/

	template<typename Expression, typename Environment = null_environment>
	struct eval
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;

		using rtn = cases
		<
			if_then
			<
				is_self_evaluating<Exp>,
				Exp

			>, else_then
			<
				is_literal<Exp>,				// is_variable
				environment_lookup<Exp, Env>

			>, else_then
			<
				is_<Exp, continuation>,
				begin_eval
				<
					car<Exp, one>,				// body

					environment_make
					<
						car<Exp>,			// args
						car<Exp, three>,		// values
						car<Exp, two>			// env
					>,

					functor
				>

			>, else_then
			<
				is_tagged<Exp, quote>,
				car<Exp, one>					// text_of_quotation

			>, else_then
			<
				is_tagged<Exp, set>,
				assignment_eval
				<
					cdr<Exp>,
					Env,
					functor
				>

			>, else_then
			<
				is_value_definition<Exp>,
				definition_define_value
				<
					cdr<Exp>,
					Env,
					functor
				>

			>, else_then
			<
				is_tagged<Exp, if_>,
				if__eval
				<
					cdr<Exp>,
					Env,
					functor
				>

			>, else_then
			<
				is_tagged<Exp, lambda>,
				procedure_make
				<
					car<Exp, one>,				// lambda_arguments
					cdr<Exp, one>,				// lambda_body
					Env
				>

			>, else_then
			<
				is_tagged<Exp, begin>,
				begin_eval
				<
					cdr<Exp>,				// begin_actions
					Env,
					functor
				>

			>, else_then
			<
				is_tagged<Exp, cond>,
				trampoline_eval
				<
					cond_to_if_
					<
						cdr<Exp>
					>,

					Env,
					functor,
					stack_depth,
					stack_depth
				>

			>, else_then
			<
				is_application<Exp>,
				application_eval
				<
					car<Exp>,				// operator
					cdr<Exp>,				// operands
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
		using rtn = error_null_expression;
	};

/*
	interpret:
*/

/*
	template<typename Program, typename Env = null_environment>
	struct interpret
	{
		using rtn = typename trampoline_eval
		<
			cons
			<
				begin,
				Program
			>,

			Env,
			functor,
			stack_depth,
			stack_depth
 
		>::rtn;
	};
*/

	#include"perspective-functor-display.hpp"
};

