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

	#include nik_typedef(calculus, interpreted, error, structure)

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

/*
	template<char... Chars>
	inline static void display(const error<Chars...> & e)
	{
		using is_empty = typename is_null<error<Chars...>>::rtn;

		Dispatched::functor::display("error:");

		if (is_empty::value)	Dispatched::functor::display(" null");
		else			Passive::functor::display(char(), e);
	}
*/
};
