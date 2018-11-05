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

	template<typename Exp>
	struct definition_variable
	{
		using Variable = typename car<Exp>::rtn;

		using rtn = typename if_then_else
		<
			is_literal<Variable>,
			Variable,
			car<Variable>

		>::rtn;
	};

/*
	definition_value:
*/

	template<typename Exp>
	struct definition_value
	{
		using Definition	= typename Exp::rtn;
		using Variable		= typename car<Exp>::rtn;
		using Value		= typename cdr<Exp>::rtn;

		using rtn = typename if_then_else
		<
			is_literal<Variable>,
			car<Value>,

			make_lambda
			<
				cdr<Variable>,
				Value
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

