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

/*
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using type		= functor;

	#include nik_typedef(calculus, untyped, conditional, structure)

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Pred, typename Exp>
	inline static void display(const if_then<Pred, Exp> &)
	{
		Dispatched::functor::display("if_then: ");

		Pred::kind::functor::display(Pred());
		Dispatched::functor::display(" ? ");

		Exp::kind::functor::display(Exp());
	}

	template<typename Pred, typename Exp>
	inline static void display(const else_then<Pred, Exp> &)
	{
		Dispatched::functor::display("else_then: ");

		Pred::kind::functor::display(Pred());
		Dispatched::functor::display(" : ");

		Exp::kind::functor::display(Exp());
	}

	template<typename Exp>
	inline static void display(const then<Exp> &)
	{
		Dispatched::functor::display("then: ");

		Exp::kind::functor::display(Exp());
	}
};

