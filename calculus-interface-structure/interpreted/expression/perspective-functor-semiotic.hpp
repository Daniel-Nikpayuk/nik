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

	#include nik_typedef(calculus, interpreted, recursed, identity)

	#define safe_name

		#include nik_typedef(calculus, interpreted, recursed, functor)
		#include nik_typedef(calculus, interpreted, environment, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, expression, structure)

/*
	is_self_evaluating:
*/

	template<typename Exp>
	struct is_self_evaluating
	{
		using rtn = apply
		<
			operate<'|', '|'>,

			is_boolean<Exp>,
			is_number<Exp>,
			is_string<Exp>

		>::rtn;
	};

/*
	evaluate:
*/

	template<typename Exp, typename Env = null_environment>
	struct evaluate
	{
		using rtn = typename intref_evaluate
		<
			if_then
			<
				is_self_evaluating<Exp>,
				Exp

			>, else_then
			<
				is_literal<Exp>, // is_variable
				intenf_lookup<Exp, Env>

			>, else_then
			<
				is_quoted<Exp>,
				car<Exp> // text_of_quotation

			>, else_then
			<
				is_assignment<Exp>,
				evaluate_assignment<Exp, Env>

			>, else_then                          
			<                                     
				is_definition<Exp>,             
				evaluate_definition<Exp, Env>

			>, else_then                          
			<                                     
				is_if<Exp>,             
				evaluate_if<Exp, Env>

			>, else_then                          
			<                                     
				is_lambda<Exp>,             
				make_procedure
				<
					lambda_parameters<Exp>,
					lambda_body<Exp>,
					Env
				>

			>, else_then                          
			<                                     
				is_begin<Exp>,             
				evaluate_sequence
				<
					begin_actions<Exp>,
					Env
				>

			>, else_then                          
			<                                     
				is_cond<Exp>,             
				evaluate
				<
					cond_to_if<Exp>,
					Env
				>

			>, else_then                          
			<                                     
				is_application<Exp>,             
				apply
				<
					evaluate
					<
						get_operator<Exp>,
						Env
					>,

					list_of_values
					<
						get_operands<Exp>,
						Env
					>
				>

			>, then
			<
				undefined
			>

		>::rtn;
	};

	template<typename Env>
	struct evaluate<null_expression, Env>
	{
		using rtn = null_expression;
	};

/*
	interpret:
*/

	template<typename Program, typename = null_environment>
	struct interpret
	{
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp, typename... Exps>
	inline static void display(const expression<Exp, Exps...> & e)
	{
		using is_empty = typename is_null<expression<Exps...>>::rtn;

		Dispatched::functor::display("expression: ");
		Exp::kind::functor::display(Exp());

		if (!is_empty::value) Recursed::functor::display(expression<Exps...>(), ", ");
		Dispatched::functor::display('\n');
	}

	inline static void display(const null_expression &)
	{
		Dispatched::functor::display("expression: null\n");
	}
};

