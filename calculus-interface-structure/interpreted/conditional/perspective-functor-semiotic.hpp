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

	#include nik_typedef(calculus, constant, recursed, functor)

	#include nik_typedef(calculus, interpreted, conditional, structure)

/*
	if__alternative:
*/

	template<typename Exp>
	struct if__alternative
	{
		using exp_cdr = typename cdr_at<Exp>::rtn;

		using rtn = typename if_then_else
		<
			is_null
			<
				cdr<exp_cdr>
			>,

			boolean<false>,


		>::rtn;
	};

/*
	evaluate_if:
*/

	template<typename Expression, typename Environment, typename Functor>
	struct evaluate_if_
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename if_then_else
		<
			Functor::evaluate // is_true
			<
				typename car<Exp>::rtn, // if_predicate
				Env
			>,

			Functor::evaluate
			<
				typename at<one, Exp>::rtn, // if_consequent
				Env
			>,

			Functor::evaluate
			<
				typename at<two, Exp>::rtn, // if_alternative
				Env
			>

		>::rtn;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Exp>
	inline static void display(const cond<Exp> &)
	{
		Dispatched::functor::display("");
		Exp::kind::functor::display(Exp());
	}
};

