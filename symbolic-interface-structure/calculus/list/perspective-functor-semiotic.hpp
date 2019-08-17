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
	I've considered refactoring the redundant pattern

		pattern_match_*<...>::template op<signature, ....>

	but it actually slows compile times down significantly enough
	to warrant leaving as is (though I might at a future date use macros).
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, core, kernel, functor)

	#include nik_typedef(symbolic, calculus, list, structure)

	// dispatch:

	template<bool True, typename Filler = void>
	struct dispatch
	{
		// builtin:

		template<typename Continuation>
		struct cp_builtin_car
		{
			template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
			using result = typename dispatch<(count > 1)>::template cp_builtin_car<Continuation>::template result
			<
				Type, ListType, count-1, Values...
			>;
		};

		template<typename Continuation>
		struct cp_builtin_cdr
		{
			template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
			using result = typename dispatch<(count > 1)>::template cp_builtin_cdr<Continuation>::template result
			<
				Type, ListType, count-1, Values...
			>;
		};

		// typename:

		struct ch_typename_car
		{
			template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
			using result = typename dispatch<(count > 1)>::ch_typename_car::template result
			<
				ListType, count-1, Values...
			>;
		};

		template<typename Continuation>
		struct cp_typename_cdr
		{
			template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
			using result = typename dispatch<(count > 1)>::template cp_typename_cdr<Continuation>::template result
			<
				ListType, count-1, Values...
			>;
		};
	};

	template<typename Filler>
	struct dispatch<false, Filler>
	{
		// builtin:

		template<typename Continuation>
		struct cp_builtin_car
		{
			template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
			using result = typename Continuation::template result<Type, Value>;
		};

		template<typename Continuation>
		struct cp_builtin_cdr
		{
			template<typename Type, template<Type...> class ListType, size_type count, Type Value, Type... Values>
			using result = typename Continuation::template result<Type, ListType, Values...>;
		};

		// typename:

		struct ch_typename_car
		{
			template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
			using result = Value;
		};

		template<typename Continuation>
		struct cp_typename_cdr
		{
			template<template<typename...> class ListType, size_type count, typename Value, typename... Values>
			using result = typename Continuation::template result<ListType, Values...>;
		};
	};

/*
	builtin:
*/

	// cons:

	struct ch_builtin_list_cons
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<Values...>;
	};

	template<typename Continuation>
	struct cp_builtin_list_cons
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = typename Continuation::template result<Type, ListType, Values...>;
	};

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list_cons>
	using builtin_list_cons = typename pattern_match_builtin_list<List>::template push_front
	<
		Continuation, Value
	>;

	// car:

	template<typename List, size_type index = 0, typename Continuation = ch_echo>
	using builtin_list_car = typename pattern_match_builtin_list<List>::template pop
	<
		typename dispatch<bool(index)>::template cp_builtin_car<Continuation>,

		index
	>;

	// cdr:

	template<typename List, size_type index = 0, typename Continuation = ch_builtin_list_cons>
	using builtin_list_cdr = typename pattern_match_builtin_list<List>::template pop
	<
		typename dispatch<bool(index)>::template cp_builtin_cdr<Continuation>,

		index
	>;

	// null:

	struct ch_builtin_list_null
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<>;
	};

	template<typename List>
	using builtin_list_null = typename pattern_match_builtin_list<List>::template push_front
	<
		ch_builtin_list_null
	>;

	// length:

	template<typename Continuation>
	struct cp_builtin_list_length
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = typename Continuation::template result<size_type, sizeof...(Values)>;
	};

	template<typename List, typename Continuation = ch_echo>
	using builtin_list_length = typename pattern_match_builtin_list<List>::template push_front
	<
		cp_builtin_list_length<Continuation>
	>;

	// catenate:

	template<typename Continuation>
	struct cp_builtin_list_catenate
	{
		template<typename Type, typename List, Type... Values>
		using result = typename pattern_match_builtin_list<List>::template push_front
		<
			cp_builtin_list_cons<Continuation>, Values...
		>;
	};

	template<typename List1, typename List2, typename Continuation = ch_builtin_list_cons>
	using builtin_list_catenate = typename pattern_match_builtin_list<List1>::template join_front
	<
		cp_builtin_list_catenate<Continuation>, List2
	>;

	// push:

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list_cons>
	using builtin_list_push = typename pattern_match_builtin_list<List>::template push_back
	<
		Continuation, Value
	>;

	// precompose:


	// passive:


	// active:
};

