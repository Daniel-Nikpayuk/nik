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

	#include nik_typedef(calculus, builtin, integer32, structure)

/*
	apply:
*/

				  template<typename... Exps>
	using apply		= typename Builtin::functor::template apply<register_type, Exps...>;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<register_type Value, register_type... Values>
	inline static void display(const integer32<Value, Values...> &)
	{
		printf("%s", "integer32: ");
		Builtin::functor::display(Value);
		print(integer32<Values...>());
	}

	inline static void display(const null_integer32 &)
	{
		printf("%s", "integer32: null");
	}

	template<register_type Value, register_type... Values>
	inline static void print(const integer32<Value, Values...> &)
	{
		printf("%s", " ");
		Builtin::functor::display(Value);
		print(integer32<Values...>());
	}

	inline static void print(const null_integer32 &)
	{
		// do nothing.
	}
};

