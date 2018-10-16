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
	using kind						= module;

	using type						= functor;

	#include nik_typedef(calculus, variable, label, module)
	#include nik_typedef(calculus, variable, label, structure)
	#include nik_typedef(calculus, variable, label, alias)

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<char Char, char... Chars>
	inline static void display(const label<Char, Chars...> & l)
	{
		printf("%s", "label: ");

		printf("%c", '"');
		label_print(l);
		printf("%c", '"');
	}

	inline static void display(const null_label & l)
	{
		printf("%s", "label: null\n");
	}

	template<char Char, char... Chars>
	inline static void label_print(const label<Char, Chars...> &)
	{
		printf("%c", Char);

		label_print(label<Chars...>());
	}

	inline static void label_print(const null_label &)
	{
		// do nothing.
	}
};
