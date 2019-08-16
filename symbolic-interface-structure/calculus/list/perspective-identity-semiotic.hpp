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
	Assumes no evaluation for all tests.
*/

struct identity
{
	using kind		= module;

	using rtn		= identity;

	#include nik_typedef(calculus, perspective, dispatched, identity)

	#include nik_typedef(calculus, untyped, neutral, structure)

	// list:

	template<typename Type, template<Type...> class ListType, Type... Values, typename Continuation = ch_bool_echo>
	using builtin_list_null = typename Continuation::template result<bool(sizeof...(Values))>;

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

	// chain:

	template<template<typename...> class ListType, typename... Values, typename Continuation = ch_bool_echo>
	using typename_list_null = typename Continuation::template result<bool(sizeof...(Values))>;

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

/*
	is_skip:
*/

	template<typename Exp>
	using is_skip = is_equal<Exp, skip>;

/*
	is_list_type:
*/

	template<typename Type, typename Exp, typename Continuation = ch_bool_echo>
	using is_list_type = typename memoized_list<Type, Exp>::template match
	<
		Continuation
	>;

/*
	is_null_type:
*/

	template<typename Type, typename Exp, typename Continuation = ch_bool_echo>
	using is_null_type = typename memoized_list<Type, Exp>::template match
	<
		is_null<Continuation>
	>;

/*
	is_struct_type:
*/

	template<typename Type, typename Exp, template<Type...> class label, typename Continuation = ch_bool_echo>
	using is_struct_type = typename memoized_list<Type, Exp>::template match
	<
		is_list_name, label
	>;

	// act:

	template<typename Exp>
	using act_id = typename memoized_chain<Exp>::template wrap
	<
		chain_name, act
	>;

	// pass:

	template<typename Exp>
	using pass_id = typename memoized_chain<Exp>::template wrap
	<
		chain_name, pass
	>;

/*
	is_name:
*/

	template<typename Exp, template<typename> class name_id>
	using is_name = typename memoized_conditional
	<
		memoized_chain<Exp>::template match<chain_id>::value

	>::template left_inject
	<
		name_id, Exp,

		memoized_value<bool, false>
	>;

/*
	is_act:
*/

	template<typename Exp>
	using is_act = is_name<Exp, act_id>;

/*
	is_pass:
*/

	template<typename Exp>
	using is_pass = is_name<Exp, pass_id>;

/*
	Passive/active comparisons would only be provided
	for convenience if they were used often enough.
*/

};
