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

	#define safe_name

		#include nik_typedef(calculus, perspective, builtin, functor)

	#undef safe_name

	#include nik_typedef(calculus, builtin, literal, structure)
	#include nik_typedef(calculus, builtin, literal, identity)

/*
	cons:
*/

				  template<register_type Value, typename List>
	using cons		= perbuf_cons<register_type, Value, List>;

/*
	car:
*/

				  template<typename List>
	using car		= perbuf_car<register_type, List>;

/*
	cdr:
*/

				  template<typename List>
	using cdr		= perbuf_cdr<register_type, List>;

/*
	catenate:
*/

				  template<typename List1, typename List2, typename... Lists>
	using catenate		= perbuf_catenate<register_type, List1, List2, Lists...>;

/*
	push:
*/

				  template<register_type Value, typename List>
	using push		= perbuf_push<register_type, Value, List>;

/*
	at:
*/

				  template<register_type Value, typename List>
	using at		= perbuf_at<register_type, Value, List>;

/*
	length:
*/

				  template<typename List>
	using length		= perbuf_length<register_type, List>;

/*
	apply:
*/

				  template<typename... Exps>
	using apply		= perbuf_apply<register_type, Exps...>;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<register_type... Values>
	inline static void display(const literal<Values...> & b)
	{
		using is_empty = typename is_null<literal<Values...>>::rtn;
		const act<register_type> a;

		Builtin::functor::display("literal:");

		if (is_empty::value)	Builtin::functor::display(" null");
		else			Builtin::functor::display(a, b);
	}
};

