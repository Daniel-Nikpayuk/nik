/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Narratively speaking, "if_then_else" is built from "cpr", but given its frequency of use
	it is optimized here.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, core, kernel, identity)

	#include nik_typedef(symbolic, calculus, boolean, structure)

/*
	if_then_else:
*/

	template<bool Pred, typename Ante, typename Conse>
	using if_then_else = typename pattern_match_boolean<Pred>::template conditional
	<
		Ante, Conse
	>;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

/*
	inline static void display(const False &)
	{
		Kernel::functor::display("False");
	}

	inline static void display(const True &)
	{
		Kernel::functor::display("True");
	}
*/
};

