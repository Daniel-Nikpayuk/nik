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

	#include nik_typedef(calculus, variable, binding, module)
	#include nik_typedef(calculus, variable, binding, structure)

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Label, typename Value>
	inline static void display(const binding<Label, Value> & b)
	{
		printf("%s", "binding: ");

		printf("%c", '<');
		Label::kind::functor::display(Label());
		printf("%s", ", ");
		Value::kind::functor::display(Value());
		printf("%c", '>');
	}
};

