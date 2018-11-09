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

		#include nik_typedef(calculus, interpreted, binding, functor)
		#include nik_typedef(calculus, interpreted, environment, functor)

	#undef safe_name

	#include nik_typedef(calculus, interpreted, lambda, functor)

	#include nik_typedef(calculus, interpreted, definition, structure)
	#include nik_typedef(calculus, interpreted, definition, identity)

/*
	evaluate_value_definition:
*/

	template<typename Expression, typename Environment, typename Functor>
	struct evaluate_value_definition
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename intenf_define
		<
			car<Exp>, // definition_variable

			typename Func::template evaluate
			<
				car<Exp, one>, // definition_value
				Env
			>,

			Env

		>::rtn;
	};

/*
	evaluate_compound_definition:
*/

	template<typename...> struct evaluate_compound_definition;

	template<typename Expression1, typename Functor, typename Expression2>
	struct evaluate_compound_definition<Expression1, Functor, Expression2>
	{
		using Exp	= typename Expression1::rtn;
		using Func	= typename Functor::rtn;
		using Frame	= typename Expression2::rtn;

		using Params	= typename car<Exp>::rtn;

		using rtn = typename cons
		<
			intbif_construct // make_binding
			<
				car<Params>, // definition_variable

				make_procedure
				<
					cdr<Params>, // lambda_arguments
					cdr<Exp>, // lambda_body
					Func
				>
			>,

			Frame

		>::rtn;
	};

	template<typename Expression1, typename Functor, typename Environment, typename Expression2>
	struct evaluate_compound_definition<Expression1, Functor, Environment, Expression2>
	{
		using Exp	= typename Expression1::rtn;
		using Func	= typename Functor::rtn;
		using Env	= typename Environment::rtn;
		using Frame	= typename Expression2::rtn;

		using Params	= typename car<Exp>::rtn;

		using rtn = typename intenf_define
		<
			car<Params>, // definition_variable

			make_procedure
			<
				cdr<Params>, // lambda_arguments
				cdr<Exp>, // lambda_body
				Func,
				Env,
				Frame
			>,

			Env

		>::rtn;
	};

/*
	evaluate_compound_definitions:
*/

	template<typename Exps1, typename Functor, typename Exps2 = null_frame>
	struct evaluate_compound_definitions
	{
		using Sequence	= typename Exps1::rtn;
		using Func	= typename Functor::rtn;
		using Frame	= typename Exps2::rtn;

		template<typename Exp1, typename Exp2>
		struct recurse
		{
			using first = typename Exp1::rtn;

			using rtn = typename evaluate_compound_definitions
			<
				Exp2, // rest
				Func,

				if_then_else
				<
					is_compound_definition<first>,

					evaluate_compound_definition
					<
						first,
						Func,
						Frame
					>,

					Frame
				>

			>::rtn;
		};

		using rtn = typename if_then_else
		<
			is_null<Sequence>,
			Frame,

			recurse
			<
				car<Sequence>,
				cdr<Sequence>
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp, typename... Exps>
	inline static void display(const define<Exp, Exps...> & e)
	{
		using is_empty = typename is_null<define<Exps...>>::rtn;

		Dispatched::functor::display("definition: ");
		Exp::kind::functor::display(Exp());

		if (!is_empty::value) Recursed::functor::display(define<Exps...>(), ", ");
		Dispatched::functor::display('\n');
	}

	inline static void display(const define<> &)
	{
		Dispatched::functor::display("definition: null\n");
	}
};

