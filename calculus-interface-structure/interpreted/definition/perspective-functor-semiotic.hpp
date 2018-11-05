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

	#include nik_typedef(calculus, interpreted, lambda, functor)

	#include nik_typedef(calculus, interpreted, definition, structure)

/*
	definition_variable:
*/

	template<typename Expression>
	struct definition_variable
	{
		using Exp		= typename Expression::rtn;
		using VariableExp	= typename Exp::variable;

		using rtn = typename if_then_else
		<
			is_literal<VariableExp>,
			VariableExp,
			car<VariableExp>

		>::rtn;
	};

/*
	definition_value:
*/

	template<typename Expression>
	struct definition_value
	{
		using Exp		= typename Expression::rtn;
		using VariableExp	= typename Exp::variable;
		using ValueExp		= typename Exp::value;

		using rtn = typename if_then_else
		<
			is_literal<VariableExp>,
			ValueExp,

			make_lambda
			<
				cdr<VariableExp>,
				ValueExp
			>

		>::rtn;
	};

/*
	evaluate_definition:
*/

	template<typename Expression, typename Environment, typename Functor>
	struct evaluate_definition
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename intenf_define
		<
			definition_variable<Exp>,

			typename Func::template evaluate
			<
				definition_value<Exp>,
				Env
			>,

			Env

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp1, typename Exp2>
	inline static void display(const define<Exp1, Exp2> &)
	{
		Dispatched::functor::display("define: ");
		Exp1::kind::functor::display(Exp1());
		Dispatched::functor::display(" as ");
		Exp2::kind::functor::display(Exp2());
	}
};

