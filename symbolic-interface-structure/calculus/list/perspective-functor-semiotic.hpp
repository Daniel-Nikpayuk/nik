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

		template<typename Continuation>
		struct cp_builtin_fold 
		{
			template<typename Type, typename Op, size_type count, Type Result, Type Value, Type... Values>
			using result = typename dispatch<(count > 1)>::template cp_builtin_fold<Continuation>::template result
			<
				Type, Op, count-1,
				Op::value(Result, Value), Values...
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

		struct ch_typename_fold 
		{
			template<template<typename, typename> class Op, size_type count,
					typename Result, typename Value, typename... Values>
			using result = typename dispatch<(count > 1)>::ch_typename_fold::template result
			<
				Op, count-1,
				Op<Result, Value>, Values...
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

		template<typename Continuation>
		struct cp_builtin_fold
		{
			template<typename Type, typename Op, size_type count, Type Result, Type... Values>
			using result = typename Continuation::template result<Type, Result>;
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

		struct ch_typename_fold
		{
			template<template<typename, typename> class Op, size_type count, typename Result, typename... Values>
			using result = Result;
		};
	};

/*
	builtin:
*/

	// length:

	template<typename Continuation>
	struct cp_builtin_length
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = typename Continuation::template result<size_type, sizeof...(Values)>;
	};

	template<typename List, typename Continuation = ch_echo>
	using builtin_length = typename pattern_match_builtin_list<List>::template push_front
	<
		cp_builtin_length<Continuation>
	>;

	// list:

	struct ch_builtin_list
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<Values...>;
	};

	// cons, multicons:

	template<typename Continuation>
	struct cp_builtin_multicons
	{
		template<typename Type, typename List, Type... Values>
		using result = typename pattern_match_builtin_list<List>::template push_front
		<
			Continuation, Values...
		>;
	};

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list>
	using builtin_cons = typename pattern_match_builtin_list<List>::template push_front
	<
		Continuation, Value
	>;

	template<typename Type, typename List, typename Continuation = ch_builtin_list, Type... Values>
	using builtin_multicons = typename cp_builtin_multicons<Continuation>::template result
	<
		Type, List, Values...
	>;

	// push, multipush:

	template<typename Continuation>
	struct cp_builtin_multipush
	{
		template<typename Type, typename List, Type... Values>
		using result = typename pattern_match_builtin_list<List>::template push_back
		<
			Continuation, Values...
		>;
	};

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list>
	using builtin_push = typename pattern_match_builtin_list<List>::template push_back
	<
		Continuation, Value
	>;

	template<typename Type, typename List, typename Continuation = ch_builtin_list, Type... Values>
	using builtin_multipush = typename cp_builtin_multipush<Continuation>::template result
	<
		Type, List, Values...
	>;

	// catenate:

	template<typename List1, typename List2, typename Continuation = ch_builtin_list>
	using builtin_catenate = typename pattern_match_builtin_list<List1>::template join_front
	<
		cp_builtin_multicons<Continuation>, List2
	>;

	// map:

	template<typename Continuation>
	struct cp_builtin_map
	{
		template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, Type... Values>
		using result = typename Continuation::template result<Kind, ListKind, Op::value(Values)...>;
	};

	template<typename Kind, template<Kind...> class ListKind, typename Op, typename List, typename Continuation = ch_builtin_list>
	using builtin_map = typename pattern_match_builtin_list<List>::template map
	<
		Kind, cp_builtin_map<Continuation>, ListKind, Op
	>;

	// rename:

	template<typename Continuation>
	struct cp_builtin_relist 
	{
		template<typename Type, template<Type...> class ListType0, template<Type...> class ListType1, Type... Values>
		using result = typename Continuation::template result<Type, ListType0, Values...>;
	};

	template<typename Type, template<Type...> class ListType, typename List, typename Continuation = ch_builtin_list>
	using builtin_relist = typename pattern_match_builtin_list<List>::template wrap
	<
		cp_builtin_relist<Continuation>, ListType
	>;

	// zip:

	template<typename Continuation>
	struct cp_builtin_zip 
	{
		template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, typename List, Type... Values>
		using result = typename pattern_match_builtin_list<List>::template zip
		<
			Kind, Continuation, ListKind, Op, Values...
		>;
	};

	template<typename Kind, template<Kind...> class ListKind,
			typename Op, typename List1, typename List2, typename Continuation = ch_builtin_list>
	using builtin_zip = typename pattern_match_builtin_list<List1>::template bimap
	<
		Kind, cp_builtin_zip<Continuation>, ListKind, Op, List2
	>;

	// car, multicar:

	template<typename List, size_type index = 0, typename Continuation = ch_echo>
	using builtin_car = typename pattern_match_builtin_list<List>::template pop
	<
		typename dispatch<bool(index)>::template cp_builtin_car<Continuation>,

		index
	>;

	// cdr, multicdr:

	template<typename List, size_type index = 0, typename Continuation = ch_builtin_list>
	using builtin_cdr = typename pattern_match_builtin_list<List>::template pop
	<
		typename dispatch<bool(index)>::template cp_builtin_cdr<Continuation>,

		index
	>;

	// null:

	struct ch_builtin_null
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<>;
	};

	template<typename List>
	using builtin_null = typename pattern_match_builtin_list<List>::template push_front
	<
		ch_builtin_null
	>;

	// unite:

	template<typename Type, typename List1, Type Value, typename List2, typename Continuation = ch_builtin_list>
	using builtin_unite = typename pattern_match_builtin_list<List1>::template join_back
	<
		cp_builtin_multicons<Continuation>, List2, Value
	>;

	template<typename Type, typename List1, typename List2, typename Continuation = ch_builtin_list, Type... Values>
	using builtin_multiunite = typename pattern_match_builtin_list<List1>::template join_back
	<
		cp_builtin_multicons<Continuation>, List2, Values...
	>;

	// reverse:

	// find:

	// fold:

	template<typename Continuation>
	struct cp_builtin_fold 
	{
		template<typename Type, typename Op, size_type length, Type Value, Type... Values>
		using let_result = typename dispatch<bool(length)>::template cp_builtin_fold<Continuation>::template result
		<
			Type, Op, length, Value, Values...
		>;

		template<typename Type, typename Op, Type Value, Type... Values>
		using result = let_result<Type, Op, sizeof...(Values), Value, Values...>;
	};

	template<typename Type, Type Value, typename Op, typename List, typename Continuation = ch_echo>
	using builtin_fold = typename pattern_match_builtin_list<List>::template fold
	<
		cp_builtin_fold<Continuation>, Op, Value
	>;
};

/*
	precompose:

		The precompose grammar can only be implemented if you can pattern match a function object type,
		but this standard currently doesn't address that in full.

	// passive:

	// active:
*/

