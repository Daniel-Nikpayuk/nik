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

	using type		= functor;

	#include nik_typedef(calculus, constant, recursed, functor)
	#include nik_typedef(calculus, interpreted, environment, functor)

	#include nik_typedef(calculus, interpreted, definition, structure)

/*
	evaluate_definition:
*/

	template<typename Exp, typename Env, typename Functor>
	struct evaluate_definition
	{
		using rtn = typename define_variable
		<
			typename car<Exp>::rtn, // definition_variable

			Functor::evaluate
			<
				typename at<one, Exp>::rtn, // definition_value
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

