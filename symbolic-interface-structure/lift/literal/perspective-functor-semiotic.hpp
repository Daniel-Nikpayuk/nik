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

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#define safe_name

		#include nik_typedef(calculus, typed, neutral, functor)
		#include nik_typedef(calculus, constant, operate, functor)

	#undef safe_name

	#include nik_typedef(calculus, constant, literal, structure)
	#include nik_typedef(calculus, constant, literal, identity)

/*
	cons:
*/

				  template<register_type Value, typename List>
	using cons		= typnef_cons<register_type, Value, List>;

/*
	car:
*/

				  template<typename List, size_type index = 0>
	using car		= typnef_car<register_type, List, index>;

/*
	cdr:
*/

				  template<typename List, size_type index = 0>
	using cdr		= typnef_cdr<register_type, List, index>;

/*
	push:
*/

				  template<register_type Value, typename List>
	using push		= typnef_push<register_type, Value, List>;

/*
	length:
*/

				  template<typename List>
	using length		= typnef_length<register_type, List>;

/*
	catenate:
*/

				  template<typename List1, typename List2, typename... Lists>
	using catenate		= typnef_catenate<register_type, List1, List2, Lists...>;

/*
	apply:
*/

				  template<typename Op, typename... Lists>
	using apply		= typnef_apply<register_type, Op, Lists...>;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<register_type... Values>
	inline static void display(const literal<Values...> & l)
	{
		static constexpr bool is_empty = is_null<literal<Values...>>::value;

		Dispatched::functor::display("literal: ");

		if (is_empty)	Dispatched::functor::display(" null");
		else		Passive::functor::display(register_type(), l, "");
	}
};

