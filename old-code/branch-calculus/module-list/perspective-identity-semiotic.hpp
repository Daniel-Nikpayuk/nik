/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Assumes no evaluation for all tests.
*/

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(symbolic, core, kernel, identity)

	#include nik_typedef(symbolic, calculus, list, structure)

/***********************************************************************************************************************/

	// is_null:

	template<typename Continuation>
	struct cp_builtin_is_null
	{
		template<typename Type, template<Type...> class ListType, typename List, Type... Values>
		using result = typename Continuation::template result<!bool(sizeof...(Values))>;
	};

	template<typename Type, typename List, typename Continuation = ch_bool_echo>
	using builtin_is_null = typename pattern_match_builtin_list<Type, List>::template push_back
	<
		cp_builtin_is_null<Continuation>, filler, 0
	>;

/***********************************************************************************************************************/

/*
	typename:

	// is_null:

	template<typename Continuation>
	struct cp_typename_is_null
	{
		template<template<typename...> class ListType, typename List, typename... Values>
		using result = typename Continuation::template result<!bool(sizeof...(Values))>;
	};

	template<typename List, typename Continuation = ch_bool_echo>
	using typename_is_null = typename pattern_match_typename_list<List>::template push_back
	<
		cp_typename_is_null<Continuation>, filler, 0
	>;
*/
};

/*
		// implements with empty lists.

	template
	<
		typename Type, template<Type...> class ListType0, template<Type...> class ListType1, Type... Values,
		typename Continuation = ch_bool_echo
	>
	using builtin_list_name = typename memoized_couple<ListType0<>, ListType1<>>::template match
	<
		Continuation
	>;

		// implements with empty lists.

	template
	<
		template<typename...> class ListType0, template<typename...> class ListType1, typename... Values,
		typename Continuation = ch_bool_echo
	>
	using typename_list_name = typename memoized_couple<ListType0<>, ListType1<>>::template match
	<
		Continuation
	>;

	// is_list_type:

	template<typename Type, typename Exp, typename Continuation = ch_bool_echo>
	using is_list_type = typename memoized_list<Type, Exp>::template match
	<
		Continuation
	>;

	// is_null_type:

	template<typename Type, typename Exp, typename Continuation = ch_bool_echo>
	using is_null_type = typename memoized_list<Type, Exp>::template match
	<
		is_null<Continuation>
	>;

	// is_struct_type:

	template<typename Type, typename Exp, template<Type...> class label, typename Continuation = ch_bool_echo>
	using is_struct_type = typename memoized_list<Type, Exp>::template match
	<
		is_list_name, label
	>;

	// act:

	template<typename Exp>
	using act_id = typename memoized_list<Exp>::template wrap
	<
		list_name, act
	>;

	// pass:

	template<typename Exp>
	using pass_id = typename memoized_list<Exp>::template wrap
	<
		list_name, pass
	>;

	// is_name:

	template<typename Exp, template<typename> class name_id>
	using is_name = typename memoized_conditional
	<
		memoized_list<Exp>::template match<list_id>::value

	>::template left_inject
	<
		name_id, Exp,

		memoized_value<bool, false>
	>;

	// is_act:

	template<typename Exp>
	using is_act = is_name<Exp, act_id>;

	// is_pass:

	template<typename Exp>
	using is_pass = is_name<Exp, pass_id>;
*/

/*
	Passive/active comparisons would only be provided
	for convenience if they were used often enough.
*/

