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

		template<typename Type, typename Op, Type Result, size_type count, Type Value, Type... Values>
		using builtin_list_fold = typename dispatch<(count > 1)>::template builtin_list_fold
		<
			Type, Op,
			Op::value(Result, Value),
			count-1, Values...
		>;

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

		template<typename Op, typename Result, size_type count, typename Value, typename... Values>
		using typename_list_fold = typename dispatch<(count > 1)>::template typename_list_fold
		<
			Op,
			typename Op::template instance<Result, Value>,
			count-1, Values...
		>;
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

		template<typename Type, typename Op, Type Result, size_type count, Type... Values>
		using builtin_list_fold = memoized_value<Type, Result>;

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

		template<typename Op, typename Result, size_type count, typename... Values>
		using typename_list_fold = Result;
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

	// unite:

	template<typename List1, typename Type, Type Value, typename List2, typename Continuation = ch_builtin_list_cons>
	using builtin_list_unite = typename pattern_match_builtin_list<List1>::template join_back
	<
		cp_builtin_list_catenate<Continuation>, List2, Value
	>;

	// push:

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list_cons>
	using builtin_list_push = typename pattern_match_builtin_list<List>::template push_back
	<
		Continuation, Value
	>;

	template<typename Type, template<Type...> class ListType0, template<Type...> class ListType1, Type... Values>
	using builtin_list_rename = ListType0<Values...>;

	template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, Type... Values>
	using builtin_list_map = ListKind<Op::value(Values)...>;

	template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, typename List, Type... Values>
	using builtin_list_zip = typename structure::template builtin_list<Type, List>::template bimap<Kind, ListKind, Op, Values...>;

	template<typename Type, typename List1, typename List2, Type... Values>
	using reflex_list_multiunite = typename pattern_match_builtin_list<Type, List1>::template join_back
	<
		list_catenate,

		List2, Values...
	>;

	// relabel:

	template<typename Type, typename List, template<Type...> class name>
	using reflex_list_rename = typename pattern_match_builtin_list<Type, List>::template wrap
	<
		list_rename, Type, name
	>;

	// map:

/*
	template<typename Type, typename Op, typename List>
	using map = typename structure::template pattern_match_builtin_list<Type, List>::template map<Op>;

	template
	<
		typename Kind, template<Kind...> class ListKind,
		typename Type, template<Type...> class ListType,

		typename Op, List, size_type length
	>
	using let_map = typename structure::template pattern_match_builtin_list<Type, List>::template recursive_binary_fapply
	<
		structure::template dispatch<bool(length)>::template map,

		Kind, ListKind, Op, length
	>;

	template
	<
		typename Kind, template<Kind...> class ListKind,
		typename Type, template<Type...> class ListType,
		typename Op, typename List1, typename List2
	>
	using map = let_map
	<
		Kind, ListKind, Type, ListType,

		typename structure::template pattern_match_operator<Op>::apply,

		ListKind<>, List1, List2,

		length<Type, List1>::value
	>;
*/

	// zip:

/*
	template<size_type length, typename Type, typename Op, typename List1, typename List2, typename... Lists>
	using let_apply = typename structure::template dispatch<Type, bool(length)>::template apply<length, Op, List1, List2, Lists...>;

	template<typename Type, typename Op, typename List1, typename List2, typename... Lists>
	using apply = let_apply<sizeof...(Lists), Type, Op, List1, List2, Lists...>;
*/

/*
	template<typename Kind, typename Type, typename Op, typename List0, typename List1, typename List2, size_type length>
	using let_apply = typename structure::template pattern_match_builtin_list<Type, List1>::template recursive_binary_packwise
	<
		structure::template dispatch<bool(length)>::template apply,

		Kind, Op, List0, List2, length
	>;

	template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, typename List1, typename List2>
	using apply = let_apply
	<
		Kind, Type,

		typename structure::template pattern_match_operator<Op>::apply,

		ListKind<>, List1, List2,

		length<Type, List1>::value
	>;
*/

	template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, typename List1, typename List2>
	using reflex_list_zip = typename pattern_match_builtin_list<Type, List1>::template zip
	<
		list_zip,

		Kind, ListKind, Op,

		List2
	>;

	// fold:

	template<typename Type, typename Op, typename List, Type seed, size_type length>
	using let_list_fold = typename pattern_match_builtin_list<Type, List>::template fold
	<
		dispatch<bool(length)>::template list_fold,

		Op,

		seed, length
	>;

	template<typename Type, typename Op, typename List, Type seed>
	using reflex_list_fold = let_list_fold<Type, Op, List, seed, length<Type, List>::value>;



/*
	template<typename Type, size_type count, typename List1, typename List2, typename... Lists>
	using let_multicatenate = typename structure::template dispatch<bool(count)>::template multicatenate
	<
		Type, count, List1, List2, Lists...
	>;

	template<typename Type, typename List1, typename List2, typename... Lists>
	using multicatenate = let_multicatenate<Type, sizeof...(Lists), List1, List2, Lists...>;
*/


/*
	template<typename Exp>
	using recall = typename pattern_match_typename_list<Exp>::template wrap
	<
		chain_rename, call
	>;
*/


};

/*
	precompose:

		The precompose grammar can only be implemented if you can pattern match a function object type,
		but this standard currently doesn't address that in full.

	// passive:

	// active:
*/

