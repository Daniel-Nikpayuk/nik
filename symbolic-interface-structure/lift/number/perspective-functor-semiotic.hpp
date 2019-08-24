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

	#include nik_typedef(symbolic, calculus, list, functor)

	#include nik_typedef(symbolic, lift, operate, module)

	#include nik_typedef(symbolic, lift, number, structure)

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
	using car		= builtin_car<register_type, List, index>;

/*
	cdr:
*/

				  template<typename List, size_type index = 0>
	using cdr		= builtin_cdr<register_type, List, index>;

/*
	apply:

		given this typename monoid is intended to be used repeatedly within fold,
		it actually makes sense to memoize a bit here.
*/

	template<typename Op>
	struct dispatch
	{
		using binary = typename Operate::functor::template binary<Op>;

		template<typename List1, typename List2>
		using zip = builtin_zip<register_type, number, register_type, binary, List1, List2>;

		template<typename Value, typename List>
		using apply = typename_fold<zip, Value, List>;
	};

	template<typename Op, typename Value, typename List>
	using apply = typename dispatch<Op>::template apply
	<
		Value, List
	>;

/*
	increment:

	Technically this is a specialization of apply, but given its frequency
	of use as an iterator I've reimplemented it to optimize.

	#define ONE 1

	template<typename Type, typename> struct increment;

	template
	<
		typename Type, Type Value,
		template<Type...> class Constant
	>
	struct increment
	<
		Type,
		Constant<Value>
	>
	{
		using rtn = Constant
		<
			Value + Type(ONE)
		>;
	};
*/

/*
	decrement:

	Technically this is a specialization of apply, but given its frequency
	of use as an iterator I've reimplemented it to optimize.

	template<typename Type, typename> struct decrement;

	template
	<
		typename Type, Type Value,
		template<Type...> class Constant
	>
	struct decrement
	<
		Type,
		Constant<Value>
	>
	{
		using rtn = Constant
		<
			Value - Type(ONE)
		>;
	};

	#undef ONE
*/

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

};

