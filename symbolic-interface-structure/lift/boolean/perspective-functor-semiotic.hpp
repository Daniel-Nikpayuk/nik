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

	#include nik_typedef(symbolic, core, kernel, identity)

	#include nik_typedef(symbolic, calculus, list, module)
	#include nik_typedef(symbolic, calculus, list, functor)

	#define safe_name

		#include nik_typedef(symbolic, lift, operate, functor)

	#undef safe_name

	#include nik_typedef(symbolic, lift, boolean, structure)

/*
	length:
*/

				  template<typename List>
	using length		= builtin_length<register_type, List>;

/*
	cons:
*/

				  template<register_type Value, typename List>
	using cons		= builtin_cons<register_type, Value, List>;

/*
	push:
*/

				  template<register_type Value, typename List>
	using push		= builtin_push<register_type, Value, List>;

/*
	car:
*/

				  template<typename List, size_type index = 0>
	using car		= builtin_multicar<register_type, List, index>;

/*
	cdr:
*/

				  template<typename List, size_type index = 0>
	using cdr		= builtin_multicdr<register_type, List, index>;

/*
	short_circuit:
*/

	template<typename Op, typename Boolean>
	using short_circuit = typename ch_bool_echo::template result
	<
		(lifopf_car<Op>::value == '&' && !car<Boolean>::value)	||
		(lifopf_car<Op>::value == '|' && car<Boolean>::value)
	>;

/*
	apply:

		given this typename monoid is intended to be used repeatedly within fold,
		it actually makes sense to memoize a bit here.
*/

	template<typename Op>
	struct zip
	{
		using binary = lifopf_binary<Op>;

		template<typename List1, typename List2>
		using result = builtin_zip<register_type, boolean, register_type, binary, List1, List2>;
	};

	template<typename Op>
	struct circuit
	{
		template<typename Boolean>
		using result = short_circuit<Op, Boolean>;
	};

	template<typename Op, typename Boolean0, typename Boolean1, typename... Booleans>
	using apply = typename List::functor::ch_typename_break_fold::template result
	<
		typename_filler, zip<Op>, circuit<Op>, sizeof...(Booleans), Boolean0, Boolean1, Booleans...
	>;

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

};

