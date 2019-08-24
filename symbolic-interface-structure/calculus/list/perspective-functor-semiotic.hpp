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
	#include nik_typedef(symbolic, calculus, recurse, functor)

	#include nik_typedef(symbolic, calculus, list, structure)

/***********************************************************************************************************************/

/*
	dispatch:
*/

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

		struct ch_builtin_fold
		{
			template<typename Type, template<typename Kind, Kind, typename> class Op,
					size_type count, typename Result, Type Value, Type... Values>
			using result = typename dispatch<(count > 1)>::ch_builtin_fold::template result
			<
				Type, Op, count-1,
				Op<Type, Value, Result>, Values...
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

		template<typename Continuation>
		struct cp_builtin_break_fold
		{
			template<typename Type, typename Pred, typename Op, size_type count, Type Result, Type... Values>
			using let_result = builtin_break_fold_if_then_else
			<
				Type,

				Pred::value(Result),

				Continuation, Result,

				typename dispatch<(count > 1)>::template cp_builtin_break_fold<Continuation>, Pred, Op, count-1,

				Values...
			>;

			template<typename Type, typename Pred, typename Op, size_type count, Type Result, Type Value, Type... Values>
			using result = let_result<Type, Pred, Op, count, Op::value(Result, Value), Values...>;
		};

		template<typename Continuation>
		struct cp_builtin_find
		{
			template<typename Type, template<Type...> class ListType,
				typename Pred, size_type count, Type Value, Type... Values>
			using result = builtin_find_if_then_else
			<
				Type, ListType,

				Pred::value(Value),

				Continuation, Value,

				typename dispatch<(count > 1)>::template cp_builtin_find<Continuation>, Pred, count-1,

				Values...
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

		struct ch_typename_break_fold
		{
			template<template<typename> class Pred, template<typename, typename> class Op,
					size_type count, typename Result, typename... Values>
			using let_result = typename_break_fold_if_then_else
			<
				Pred<Result>::value,

				Result,

				typename dispatch<(count > 1)>::ch_typename_break_fold, Pred, Op, count-1,

				Values...
			>;

			template<template<typename> class Pred, template<typename, typename> class Op,
					size_type count, typename Result, typename Value, typename... Values>
			using result = let_result<Pred, Op, count, Op<Result, Value>, Values...>;
		};

		template<typename Continuation>
		struct cp_typename_find
		{
			template<template<typename...> class ListType,
				template<typename> class Pred, size_type count, typename Value, typename... Values>
			using result = typename_find_if_then_else
			<
				ListType,

				Pred<Value>::value,

				Continuation, Value,

				typename dispatch<(count > 1)>::template cp_typename_find<Continuation>, Pred, count-1,

				Values...
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

		struct ch_builtin_fold
		{
			template<typename Type, template<typename Kind, Kind, typename> class Op,
					size_type count, typename Result, Type... Values>
			using result = Result;
		};

		template<typename Continuation>
		struct cp_builtin_fold
		{
			template<typename Type, typename Op, size_type count, Type Result, Type... Values>
			using result = typename Continuation::template result<Type, Result>;
		};

		template<typename Continuation>
		struct cp_builtin_break_fold
		{
			template<typename Type, typename Pred, typename Op, size_type count, Type Result, Type... Values>
			using result = typename Continuation::template result<Type, Result>;
		};

		template<typename Continuation>
		struct cp_builtin_find
		{
			template<typename Type, template<Type...> class ListType, typename Pred, size_type count, Type... Values>
			using result = ListType<>;
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

		struct ch_typename_break_fold
		{
			template<template<typename> class Pred, template<typename, typename> class Op,
					size_type count, typename Result, typename... Values>
			using result = Result;
		};

		template<typename Continuation>
		struct cp_typename_find
		{
			template<template<typename...> class ListType, template<typename> class Pred, size_type count, typename... Values>
			using result = ListType<>;
		};
	};

/***********************************************************************************************************************/

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

	template<typename Type, typename List, typename Continuation = ch_echo>
	using builtin_length = typename pattern_match_builtin_list<Type, List>::template push_front
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

		// the unusual form of cp_multicons is meant for composition.

	template<typename Continuation>
	struct cp_builtin_multicons
	{
		template<typename Type, typename List, Type... Values>
		using result = typename pattern_match_builtin_list<Type, List>::template push_front
		<
			Continuation, Values...
		>;
	};

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list>
	using builtin_cons = typename pattern_match_builtin_list<Type, List>::template push_front
	<
		Continuation, Value
	>;

	template<typename Type, typename List, typename Continuation = ch_builtin_list, Type... Values>
	using builtin_multicons = typename cp_builtin_multicons<Continuation>::template result
	<
		Type, List, Values...
	>;

	// push, multipush:

		// the unusual form of cp_multipush is meant for composition.

	template<typename Continuation>
	struct cp_builtin_multipush
	{
		template<typename Type, typename List, Type... Values>
		using result = typename pattern_match_builtin_list<Type, List>::template push_back
		<
			Continuation, Values...
		>;
	};

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list>
	using builtin_push = typename pattern_match_builtin_list<Type, List>::template push_back
	<
		Continuation, Value
	>;

	template<typename Type, typename List, typename Continuation = ch_builtin_list, Type... Values>
	using builtin_multipush = typename cp_builtin_multipush<Continuation>::template result
	<
		Type, List, Values...
	>;

	// catenate:

	template<typename Type, typename List1, typename List2, typename Continuation = ch_builtin_list>
	using builtin_catenate = typename pattern_match_builtin_list<Type, List1>::template join_front
	<
		cp_builtin_multicons<Continuation>, List2
	>;

	// map:

	//	For whatever reason if I put Kind after Continuation
	//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_builtin_map
	{
		template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, Type... Values>
		using result = typename Continuation::template result<Kind, ListKind, Op::value(Values)...>;
	};

	template<typename Kind, template<Kind...> class ListKind, typename Type,
			typename Op, typename List, typename Continuation = ch_builtin_list>
	using builtin_map = typename pattern_match_builtin_list<Type, List>::template map
	<
		Kind, ListKind, cp_builtin_map<Continuation>, Op
	>;

	// rename:

	template<typename Continuation>
	struct cp_builtin_relist
	{
		template<typename Type, template<Type...> class ListType0, template<Type...> class ListType1, Type... Values>
		using result = typename Continuation::template result<Type, ListType0, Values...>;
	};

	template<typename Type, template<Type...> class ListType, typename List, typename Continuation = ch_builtin_list>
	using builtin_relist = typename pattern_match_builtin_list<Type, List>::template wrap
	<
		cp_builtin_relist<Continuation>, ListType
	>;

	// zip:

	//	For whatever reason if I put Kind after Continuation
	//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_builtin_zip
	{
		template<typename Kind, template<Kind...> class ListKind, typename Type, typename Op, typename List, Type... Values>
		using result = typename pattern_match_builtin_list<Type, List>::template zip
		<
			Kind, ListKind, Continuation, Op, Values...
		>;
	};

	template<typename Kind, template<Kind...> class ListKind, typename Type,
			typename Op, typename List1, typename List2, typename Continuation = ch_builtin_list>
	using builtin_zip = typename pattern_match_builtin_list<Type, List1>::template bimap
	<
		Kind, ListKind, cp_builtin_zip<Continuation>, Op, List2
	>;

	// car, multicar:

	template<typename Continuation>
	struct cp_builtin_car
	{
		static constexpr size_type index = 0;

		template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
		using result = typename dispatch<bool(index)>::template cp_builtin_car<Continuation>::template result
		<
			Type, ListType, index, Value, Values...
		>;
	};

	template<typename Continuation>
	struct cp_builtin_multicar
	{
		template<typename Type, template<Type...> class ListType, size_type index, Type Value, Type... Values>
		using result = typename dispatch<bool(index)>::template cp_builtin_car<Continuation>::template result
		<
			Type, ListType, index, Value, Values...
		>;
	};

	template<typename Type, typename List, size_type index = 0, typename Continuation = ch_echo>
	using builtin_car = typename pattern_match_builtin_list<Type, List>::template pop
	<
		cp_builtin_multicar<Continuation>, index
	>;

	// cdr, multicdr:

	template<typename Continuation>
	struct cp_builtin_cdr
	{
		static constexpr size_type index = 0;

		template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
		using result = typename dispatch<bool(index)>::template cp_builtin_cdr<Continuation>::template result
		<
			Type, ListType, index, Value, Values...
		>;
	};

	template<typename Continuation>
	struct cp_builtin_multicdr
	{
		template<typename Type, template<Type...> class ListType, size_type index, Type Value, Type... Values>
		using result = typename dispatch<bool(index)>::template cp_builtin_cdr<Continuation>::template result
		<
			Type, ListType, index, Value, Values...
		>;
	};

	template<typename Type, typename List, size_type index = 0, typename Continuation = ch_builtin_list>
	using builtin_cdr = typename pattern_match_builtin_list<Type, List>::template pop
	<
		cp_builtin_multicdr<Continuation>, index
	>;

	// null:

	struct ch_builtin_null
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<>;
	};

	template<typename Type, typename List>
	using builtin_null = typename pattern_match_builtin_list<Type, List>::template push_front
	<
		ch_builtin_null
	>;

	// unite:

	template<typename Type, typename List1, Type Value, typename List2, typename Continuation = ch_builtin_list>
	using builtin_unite = typename pattern_match_builtin_list<Type, List1>::template join_back
	<
		cp_builtin_multicons<Continuation>, List2, Value
	>;

	template<typename Type, typename List1, typename List2, typename Continuation = ch_builtin_list, Type... Values>
	using builtin_multiunite = typename pattern_match_builtin_list<Type, List1>::template join_back
	<
		cp_builtin_multicons<Continuation>, List2, Values...
	>;

	// reverse:

	struct ch_builtin_reverse
	{
		template<typename Type, size_type length, typename Result, Type... Values>
		using let_result = typename dispatch<bool(length)>::ch_builtin_fold::template result
		<
			Type, builtin_cons, length, Result, Values...
		>;

		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = let_result<Type, sizeof...(Values), ListType<>, Values...>;
	};

	template<typename Type, typename List>
	using builtin_reverse = typename pattern_match_builtin_list<Type, List>::template push_front
	<
		ch_builtin_reverse
	>;

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

	template<typename Type, typename Op, Type Value, typename List, typename Continuation = ch_echo>
	using builtin_fold = typename pattern_match_builtin_list<Type, List>::template fold
	<
		cp_builtin_fold<Continuation>, Op, Value
	>;

	// break_fold:

	template<typename Continuation>
	struct cp_builtin_break_fold
	{
		template<typename Type, typename Pred, typename Op, size_type length, Type Value, Type... Values>
		using let_result = typename dispatch<bool(length)>::template cp_builtin_break_fold<Continuation>::template result
		<
			Type, Pred, Op, length, Value, Values...
		>;

		template<typename Type, typename Pred, typename Op, Type Value, Type... Values>
		using result = let_result<Type, Pred, Op, sizeof...(Values), Value, Values...>;
	};

	template<typename Type, typename Pred, typename Op, Type Value, typename List, typename Continuation = ch_echo>
	using builtin_break_fold = typename pattern_match_builtin_list<Type, List>::template break_fold
	<
		cp_builtin_break_fold<Continuation>, Pred, Op, Value
	>;

	// find:

	template<typename Continuation>
	struct cp_builtin_find
	{
		template<typename Type, template<Type...> class ListType, typename Pred, size_type length, Type... Values>
		using let_result = typename dispatch<bool(length)>::template cp_builtin_find<Continuation>::template result
		<
			Type, ListType, Pred, length, Values...
		>;

		template<typename Type, template<Type...> class ListType, typename Pred, Type... Values>
		using result = let_result<Type, ListType, Pred, sizeof...(Values), Values...>;
	};

	template<typename Type, typename Pred, typename List, typename Continuation = ch_builtin_list>
	using builtin_find = typename pattern_match_builtin_list<Type, List>::template find
	<
		cp_builtin_find<Continuation>, Pred
	>;

/*
	precompose:

		The precompose grammar can only be implemented if you can pattern match a function object type,
		but this standard currently doesn't address that in full.

	// passive:

	// active:
*/

/***********************************************************************************************************************/

/*
	typename:
*/

	// length:

	template<typename Continuation>
	struct cp_typename_length
	{
		template<template<typename...> class ListType, typename... Values>
		using result = typename Continuation::template result<size_type, sizeof...(Values)>;
	};

	template<typename List, typename Continuation = ch_echo>
	using typename_length = typename pattern_match_typename_list<List>::template push_front
	<
		cp_typename_length<Continuation>
	>;

	// list:

	struct ch_typename_list
	{
		template<template<typename...> class ListType, typename... Values>
		using result = ListType<Values...>;
	};

	// cons, multicons:

		// the unusual form of cp_multicons is meant for composition.

	template<typename Continuation>
	struct cp_typename_multicons
	{
		template<typename List, typename... Values>
		using result = typename pattern_match_typename_list<List>::template push_front
		<
			Continuation, Values...
		>;
	};

	template<typename Value, typename List, typename Continuation = ch_typename_list>
	using typename_cons = typename pattern_match_typename_list<List>::template push_front
	<
		Continuation, Value
	>;

	template<typename List, typename Continuation = ch_typename_list, typename... Values>
	using typename_multicons = typename cp_typename_multicons<Continuation>::template result
	<
		List, Values...
	>;

	// push, multipush:

		// the unusual form of cp_multipush is meant for composition.

	template<typename Continuation>
	struct cp_typename_multipush
	{
		template<typename List, typename... Values>
		using result = typename pattern_match_typename_list<List>::template push_back
		<
			Continuation, Values...
		>;
	};

	template<typename Value, typename List, typename Continuation = ch_typename_list>
	using typename_push = typename pattern_match_typename_list<List>::template push_back
	<
		Continuation, Value
	>;

	template<typename List, typename Continuation = ch_typename_list, typename... Values>
	using typename_multipush = typename cp_typename_multipush<Continuation>::template result
	<
		List, Values...
	>;

	// catenate:

	template<typename List1, typename List2, typename Continuation = ch_typename_list>
	using typename_catenate = typename pattern_match_typename_list<List1>::template join_front
	<
		cp_typename_multicons<Continuation>, List2
	>;

	// map:

	//	For whatever reason if I put Kind after Continuation
	//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_typename_map
	{
		template<template<typename...> class ListKind, template<typename> class Op, typename... Values>
		using result = typename Continuation::template result<ListKind, Op<Values>...>;
	};

	template<template<typename...> class ListKind, template<typename> class Op, typename List, typename Continuation = ch_typename_list>
	using typename_map = typename pattern_match_typename_list<List>::template map
	<
		ListKind, cp_typename_map<Continuation>, Op
	>;

	// rename:

	template<typename Continuation>
	struct cp_typename_relist
	{
		template<template<typename...> class ListType0, template<typename...> class ListType1, typename... Values>
		using result = typename Continuation::template result<ListType0, Values...>;
	};

	template<template<typename...> class ListType, typename List, typename Continuation = ch_typename_list>
	using typename_relist = typename pattern_match_typename_list<List>::template wrap
	<
		cp_typename_relist<Continuation>, ListType
	>;

	// zip:

	//	For whatever reason if I put Kind after Continuation
	//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_typename_zip
	{
		template<template<typename...> class ListKind, template<typename, typename> class Op, typename List, typename... Values>
		using result = typename pattern_match_typename_list<List>::template zip
		<
			ListKind, Continuation, Op, Values...
		>;
	};

	template<template<typename...> class ListKind, template<typename, typename> class Op,
			typename List1, typename List2, typename Continuation = ch_typename_list>
	using typename_zip = typename pattern_match_typename_list<List1>::template bimap
	<
		ListKind, cp_typename_zip<Continuation>, Op, List2
	>;

	// car, multicar:

	struct ch_typename_car
	{
		static constexpr size_type index = 0;

		template<template<typename...> class ListType, typename Value, typename... Values>
		using result = typename dispatch<bool(index)>::ch_typename_car::template result
		<
			ListType, index, Value, Values...
		>;
	};

	struct ch_typename_multicar
	{
		template<template<typename...> class ListType, size_type index, typename Value, typename... Values>
		using result = typename dispatch<bool(index)>::ch_typename_car::template result
		<
			ListType, index, Value, Values...
		>;
	};

	template<typename List, size_type index = 0>
	using typename_car = typename pattern_match_typename_list<List>::template pop
	<
		ch_typename_multicar, index
	>;

	// cdr, multicdr:

	template<typename Continuation>
	struct cp_typename_cdr
	{
		static constexpr size_type index = 0;

		template<template<typename...> class ListType, typename Value, typename... Values>
		using result = typename dispatch<bool(index)>::template cp_typename_cdr<Continuation>::template result
		<
			ListType, index, Value, Values...
		>;
	};

	template<typename Continuation>
	struct cp_typename_multicdr
	{
		template<template<typename...> class ListType, size_type index, typename Value, typename... Values>
		using result = typename dispatch<bool(index)>::template cp_typename_cdr<Continuation>::template result
		<
			ListType, index, Value, Values...
		>;
	};

	template<typename List, size_type index = 0, typename Continuation = ch_typename_list>
	using typename_cdr = typename pattern_match_typename_list<List>::template pop
	<
		cp_typename_multicdr<Continuation>, index
	>;

	// null:

	struct ch_typename_null
	{
		template<template<typename...> class ListType, typename... Values>
		using result = ListType<>;
	};

	template<typename List>
	using typename_null = typename pattern_match_typename_list<List>::template push_front
	<
		ch_typename_null
	>;

	// unite:

	template<typename List1, typename Value, typename List2, typename Continuation = ch_typename_list>
	using typename_unite = typename pattern_match_typename_list<List1>::template join_back
	<
		cp_typename_multicons<Continuation>, List2, Value
	>;

	template<typename List1, typename List2, typename Continuation = ch_typename_list, typename... Values>
	using typename_multiunite = typename pattern_match_typename_list<List1>::template join_back
	<
		cp_typename_multicons<Continuation>, List2, Values...
	>;

	// reverse:

	struct ch_typename_reverse
	{
		template<size_type length, typename Result, typename... Values>
		using let_result = typename dispatch<bool(length)>::ch_typename_fold::template result
		<
			typename_cons, length, Result, Values...
		>;

		template<template<typename...> class ListType, typename... Values>
		using result = let_result<sizeof...(Values), ListType<>, Values...>;
	};

	template<typename List>
	using typename_reverse = typename pattern_match_typename_list<List>::template push_front
	<
		ch_typename_reverse
	>;

	// fold:

	struct ch_typename_fold
	{
		template<template<typename, typename> class Op, size_type length, typename Value, typename... Values>
		using let_result = typename dispatch<bool(length)>::ch_typename_fold::template result
		<
			Op, length, Value, Values...
		>;

		template<template<typename, typename> class Op, typename Value, typename... Values>
		using result = let_result<Op, sizeof...(Values), Value, Values...>;
	};

	template<template<typename, typename> class Op, typename Value, typename List>
	using typename_fold = typename pattern_match_typename_list<List>::template fold
	<
		ch_typename_fold, Op, Value
	>;

	// break_fold:

	struct ch_typename_break_fold
	{
		template<template<typename> class Pred, template<typename, typename> class Op,
				size_type length, typename Value, typename... Values>
		using let_result = typename dispatch<bool(length)>::ch_typename_break_fold::template result
		<
			Pred, Op, length, Value, Values...
		>;

		template<template<typename> class Pred, template<typename, typename> class Op, typename Value, typename... Values>
		using result = let_result<Pred, Op, sizeof...(Values), Value, Values...>;
	};

	template<template<typename> class Pred, template<typename, typename> class Op, typename Value, typename List>
	using typename_break_fold = typename pattern_match_typename_list<List>::template break_fold
	<
		ch_typename_break_fold, Pred, Op, Value
	>;

	// find:

	template<typename Continuation>
	struct cp_typename_find
	{
		template<template<typename...> class ListType, template<typename> class Pred, size_type length, typename... Values>
		using let_result = typename dispatch<bool(length)>::template cp_typename_find<Continuation>::template result
		<
			ListType, Pred, length, Values...
		>;

		template<template<typename...> class ListType, template<typename> class Pred, typename... Values>
		using result = let_result<ListType, Pred, sizeof...(Values), Values...>;
	};

	template<template<typename> class Pred, typename List, typename Continuation = ch_typename_list>
	using typename_find = typename pattern_match_typename_list<List>::template find
	<
		cp_typename_find<Continuation>, Pred
	>;
};

