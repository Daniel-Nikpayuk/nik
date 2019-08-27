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

	#include nik_typedef(symbolic, core, kernel, identity)
	#include nik_typedef(symbolic, core, kernel, functor)

	#include nik_typedef(symbolic, calculus, boolean, functor)
	#include nik_typedef(symbolic, calculus, recurse, functor)

	#include nik_typedef(symbolic, calculus, list, structure)

/***********************************************************************************************************************/

/*
	builtin:
*/

	// list:

	struct ch_builtin_list
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<Values...>;
	};

	// cast:

	template<typename Continuation>
	struct cp_builtin_list_to_echo
	{
		template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, Value>;
	};

	template<typename Continuation>
	struct cp_builtin_push_to_list
	{
		template<typename Type, template<Type...> class ListType, typename List, size_type index, Type... Values>
		using result = typename Continuation::template result<Type, ListType, Values...>;
	};

	// length:

	template<typename Continuation>
	struct cp_builtin_length
	{
		template<typename Type, template<Type...> class ListType, typename List, size_type index, Type... Values>
		using result = typename Continuation::template result<size_type, sizeof...(Values)>;
	};

	template<typename Type, typename List, typename Continuation = ch_echo>
	using builtin_length = typename pattern_match_builtin_list<Type, List>::template push_front
	<
		cp_builtin_length<Continuation>, filler, 0
	>;

	// cons, multicons:

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list>
	using builtin_cons = typename pattern_match_builtin_list<Type, List>::template push_front
	<
		cp_builtin_push_to_list<Continuation>, filler, 0, Value
	>;

		// Default Continuation values must be given externally.

	template<typename Type, typename List, typename Continuation, Type... Values>
	using builtin_multicons = typename pattern_match_builtin_list<Type, List>::template push_front
	<
		cp_builtin_push_to_list<Continuation>, filler, 0, Values...
	>;

	// push, multipush:

	template<typename Type, Type Value, typename List, typename Continuation = ch_builtin_list>
	using builtin_push = typename pattern_match_builtin_list<Type, List>::template push_back
	<
		cp_builtin_push_to_list<Continuation>, filler, 0, Value
	>;

		// Default Continuation values must be given externally.

	template<typename Type, typename List, typename Continuation, Type... Values>
	using builtin_multipush = typename pattern_match_builtin_list<Type, List>::template push_back
	<
		cp_builtin_push_to_list<Continuation>, filler, 0, Values...
	>;

	// catenate:

	template<typename Continuation>
	struct cp_builtin_catenate
	{
		template<typename Type, template<Type...> class ListType, typename List, size_type index, Type... Values>
		using result = typename pattern_match_builtin_list<Type, List>::template push_front
		<
			cp_builtin_push_to_list<Continuation>, filler, 0, Values...
		>;
	};

	template<typename Type, typename List1, typename List2, typename Continuation = ch_builtin_list>
	using builtin_catenate = typename pattern_match_builtin_list<Type, List1>::template push_front
	<
		cp_builtin_catenate<Continuation>, List2, 0
	>;

	// map:

		//	For whatever reason if I put ListKind after Continuation
		//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_builtin_map
	{
		template<typename Kind, template<Kind...> class ListKind,
			typename Type, typename Op, typename List, size_type index, Type... Values>
		using result = typename Continuation::template result<Kind, ListKind, Op::value(Values)...>;
	};

	template<typename Kind, template<Kind...> class ListKind,
		typename Type, typename Op, typename List, typename Continuation = ch_builtin_list>
	using builtin_map = typename pattern_match_builtin_list<Type, List>::template map
	<
		Kind, ListKind, cp_builtin_map<Continuation>, Op, filler, 0
	>;

	// relist:

	template<typename Continuation>
	struct cp_builtin_relist
	{
		template<typename Kind, template<Kind...> class ListKind,
			typename Type, typename Op, typename List, size_type index, Type... Values>
		using result = typename Continuation::template result<Kind, ListKind, Values...>;
	};

	template<typename Type, template<Type...> class ListType, typename List, typename Continuation = ch_builtin_list>
	using builtin_relist = typename pattern_match_builtin_list<Type, List>::template map
	<
		Type, ListType, cp_builtin_relist<Continuation>, filler, filler, 0
	>;

	// zip:

		//	For whatever reason if I put ListKind after Continuation
		//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_builtin_zip
	{
		template<typename Kind, template<Kind...> class ListKind,
			typename Type, typename Op, typename List, size_type index, Type... Values>
		using result = typename pattern_match_builtin_list<Type, List>::template zip
		<
			Kind, ListKind, Continuation, Op, Values...
		>;
	};

	template<typename Kind, template<Kind...> class ListKind,
		typename Type, typename Op, typename List1, typename List2, typename Continuation = ch_builtin_list>
	using builtin_zip = typename pattern_match_builtin_list<Type, List1>::template map
	<
		Kind, ListKind, cp_builtin_zip<Continuation>, Op, List2, 0
	>;

	// cdr:

	template<typename Continuation>
	struct cp_builtin_cdr
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, ListType, Values...>;
	};

	template<typename Type, typename List, typename Continuation = ch_builtin_list>
	using builtin_cdr = typename pattern_match_builtin_list<Type, List>::template fold
	<
		cp_builtin_cdr<Continuation>, filler, filler, 0, Type(0)
	>;

	// multicdr:

	template<typename Continuation>
	struct cp_builtin_multicdr
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = builtin_list_if_then_else
		<
			Type, ListType,

			bool(index),

			builtin_fold_if_then
			<
				Type, ListType, bool(index),
				cp_builtin_multicdr<Continuation>, Op, Cond, index-1, Result, Values...
			>,

			Continuation, Values...
		>;
	};

	template<typename Type, typename List, size_type index = 0, typename Continuation = ch_builtin_list>
	using builtin_multicdr = typename pattern_match_builtin_list<Type, List>::template fold
	<
		cp_builtin_multicdr<Continuation>, filler, filler, index, Type(0)
	>;

	// car:

	template<typename Continuation>
	struct cp_builtin_car
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, Value>;
	};

	template<typename Type, typename List, typename Continuation = ch_echo>
	using builtin_car = typename pattern_match_builtin_list<Type, List>::template fold
	<
		cp_builtin_car<Continuation>, filler, filler, 0, Type(0)
	>;

	// multicar:

	template<typename Continuation>
	struct cp_builtin_multicar
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = echo_if_then_else
		<
			Type,

			bool(index),

			builtin_fold_if_then
			<
				Type, ListType, bool(index),
				cp_builtin_multicdr < cp_builtin_list_to_echo < Continuation >>,
				Op, Cond, index-1, Result, Value, Values...
			>,

			Continuation, Value
		>;
	};

	template<typename Type, typename List, size_type index = 0, typename Continuation = ch_echo>
	using builtin_multicar = typename pattern_match_builtin_list<Type, List>::template fold
	<
		cp_builtin_multicar<Continuation>, filler, filler, index, Type(0)
	>;

	// null:

	struct ch_builtin_null
	{
		template<typename Type, template<Type...> class ListType, typename List, size_type index, Type... Values>
		using result = ListType<>;
	};

	template<typename Type, typename List>
	using builtin_null = typename pattern_match_builtin_list<Type, List>::template push_front
	<
		ch_builtin_null, filler, 0
	>;

	// unite:

	template<typename Type, typename List1, Type Value, typename List2, typename Continuation = ch_builtin_list>
	using builtin_unite = typename pattern_match_builtin_list<Type, List1>::template push_back
	<
		cp_builtin_catenate<Continuation>, List2, 0, Value
	>;

	template<typename Type, typename List1, typename List2, typename Continuation, Type... Values>
	using builtin_multiunite = typename pattern_match_builtin_list<Type, List1>::template push_back
	<
		cp_builtin_catenate<Continuation>, List2, 0, Values...
	>;

	// reverse:

	struct ch_let_builtin_reverse
	{
		template<typename Type, template<Type...> class ListType, bool Pred, typename List, size_type index, Type... Values>
		using let_result = if_then_else
		<
			Pred,

			builtin_push_if_then
			<
				Type, ListType, Pred,
				ch_let_builtin_reverse, List, index-1, Values...
			>,

			List
		>;

		template<typename Type, template<Type...> class ListType, typename List, size_type index, Type Value, Type... Values>
		using result = let_result<Type, ListType, bool(index), builtin_cons<Type, Value, List>, index, Values...>;
	};

	struct ch_builtin_reverse
	{
			// sizeof...(Values) is an optimization.

		template<typename Type, template<Type...> class ListType, typename List, size_type index, Type Value, Type... Values>
		using result = typename ch_let_builtin_reverse::template result
		<
			Type, ListType, ListType<>, sizeof...(Values), Value, Values...
		>;
	};

		// The nature of this particular implementation means no continuation is possible.
		// I have implemented the version where it is and it's significantly slower,
		// enough I'm willing to break with the overall design.

	template<typename Type, typename List>
	using builtin_reverse = typename pattern_match_builtin_list<Type, List>::template push_front
	<
		ch_builtin_reverse, filler, 0
	>;

	// fold:

	template<typename Continuation>
	struct cp_let_builtin_fold
	{
		template<typename Type, template<Type...> class ListType,
			bool Pred, typename Op, typename Cond, size_type index, Type Result, Type... Values>
		using let_result = echo_if_then_else
		<
			Type,

			Pred,

			builtin_fold_if_then
			<
				Type, ListType, Pred,
				cp_let_builtin_fold<Continuation>, Op, Cond, index-1, Result, Values...
			>,

			Continuation, Result
		>;

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = let_result<Type, ListType, bool(index), Op, Cond, index, Op::value(Result, Value), Values...>;
	};

	template<typename Continuation>
	struct cp_builtin_fold
	{
			// sizeof...(Values) is an optimization.

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = typename cp_let_builtin_fold<Continuation>::template result
		<
			Type, ListType, Op, Cond, sizeof...(Values), Result, Value, Values...
		>;
	};

	template<typename Type, typename Op, Type Result, typename List, typename Continuation = ch_echo>
	using builtin_fold = typename pattern_match_builtin_list<Type, List>::template fold
	<
		cp_builtin_fold<Continuation>, Op, filler, 0, Result
	>;

	// break_fold:

	template<typename Continuation> struct cp_let_end_builtin_break_fold;

	template<typename Continuation>
	struct cp_let_break_builtin_break_fold
	{
			// if we've reached this point, we know we're not at the End.

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, bool Break, Type Result, Type... Values>
		using let_result = builtin_fold_if_then_else
		<
			Type, ListType,

			Break,

			echo_if_then
			<
				Type, Break, Continuation, Result
			>,

			cp_let_end_builtin_break_fold<Continuation>, Op, Cond, index-1, Result, Values...
		>;

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type... Values>
		using result = let_result<Type, ListType, Op, Cond, index, Cond::value(Result), Result, Values...>;
	};

	template<typename Continuation>
	struct cp_let_end_builtin_break_fold
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, bool End, Type Result, Type... Values>
		using let_result = builtin_fold_if_then_else
		<
			Type, ListType,

			End,

			echo_if_then
			<
				Type, End, Continuation, Result
			>,

			cp_let_break_builtin_break_fold<Continuation>, Op, Cond, index, Result, Values...
		>;

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = let_result<Type, ListType, Op, Cond, index, !bool(index), Op::value(Result, Value), Values...>;
	};

	template<typename Continuation>
	struct cp_builtin_break_fold
	{
			// sizeof...(Values) is an optimization.

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = typename cp_let_end_builtin_break_fold<Continuation>::template result
		<
			Type, ListType, Op, Cond, sizeof...(Values), Result, Value, Values...
		>;
	};

	template<typename Type, typename Op, typename Cond, Type Result, typename List, typename Continuation = ch_echo>
	using builtin_break_fold = typename pattern_match_builtin_list<Type, List>::template fold
	<
		cp_builtin_break_fold<Continuation>, Op, Cond, 0, Result
	>;

	// find:

	template<typename Continuation> struct cp_let_match_builtin_find;

	template<typename Continuation>
	struct cp_let_end_builtin_find
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, bool End, Type Result, Type... Values>
		using let_result = builtin_fold_if_then_else
		<
			Type, ListType,

			End,

			ListType<>,

			cp_let_match_builtin_find<Continuation>, Op, Cond, index-1, Result, Values...
		>;

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type... Values>
		using result = let_result<Type, ListType, Op, Cond, index, !bool(index), Result, Values...>;
	};

	template<typename Continuation>
	struct cp_let_match_builtin_find
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, bool Match, Type Result, Type Value, Type... Values>
		using let_result = builtin_fold_if_then_else
		<
			Type, ListType,

			Match,

			builtin_list_if_then
			<
				Type, ListType, Match, Continuation, Value, Values...
			>,

			cp_let_end_builtin_find<Continuation>, Op, Cond, index, Result, Values...
		>;

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = let_result<Type, ListType, Op, Cond, index, Cond::value(Value), Result, Value, Values...>;
	};

	template<typename Continuation>
	struct cp_builtin_find
	{
			// sizeof...(Values) is an optimization.

		template<typename Type, template<Type...> class ListType,
			typename Op, typename Cond, size_type index, Type Result, Type Value, Type... Values>
		using result = typename cp_let_match_builtin_find<Continuation>::template result
		<
			Type, ListType, Op, Cond, sizeof...(Values), Result, Value, Values...
		>;
	};

	template<typename Type, typename Cond, typename List, typename Continuation = ch_builtin_list>
	using builtin_find = typename pattern_match_builtin_list<Type, List>::template fold
	<
		cp_builtin_find<Continuation>, filler, Cond, 0, Type(0)
	>;

/***********************************************************************************************************************/

/*
	typename:
*/

	// list:

	struct ch_typename_list
	{
		template<template<typename...> class ListType, typename... Values>
		using result = ListType<Values...>;
	};

	// cast:

	struct ch_typename_list_to_ping
	{
		template<template<typename...> class ListType, typename Value, typename... Values>
		using result = Value;
	};

	template<typename Continuation>
	struct cp_typename_push_to_list
	{
		template<template<typename...> class ListType, typename List, size_type index, typename... Values>
		using result = typename Continuation::template result<ListType, Values...>;
	};

	// length:

	template<typename Continuation>
	struct cp_typename_length
	{
		template<template<typename...> class ListType, typename List, size_type index, typename... Values>
		using result = typename Continuation::template result<size_type, sizeof...(Values)>;
	};

	template<typename List, typename Continuation = ch_echo>
	using typename_length = typename pattern_match_typename_list<List>::template push_front
	<
		cp_typename_length<Continuation>, filler, 0
	>;

	// cons, multicons:

	template<typename Value, typename List, typename Continuation = ch_typename_list>
	using typename_cons = typename pattern_match_typename_list<List>::template push_front
	<
		cp_typename_push_to_list<Continuation>, filler, 0, Value
	>;

		// Default Continuation values must be given externally.

	template<typename List, typename Continuation, typename... Values>
	using typename_multicons = typename pattern_match_typename_list<List>::template push_front
	<
		cp_typename_push_to_list<Continuation>, filler, 0, Values...
	>;

	// push, multipush:

	template<typename Value, typename List, typename Continuation = ch_typename_list>
	using typename_push = typename pattern_match_typename_list<List>::template push_back
	<
		cp_typename_push_to_list<Continuation>, filler, 0, Value
	>;

		// Default Continuation values must be given externally.

	template<typename List, typename Continuation, typename... Values>
	using typename_multipush = typename pattern_match_typename_list<List>::template push_back
	<
		cp_typename_push_to_list<Continuation>, filler, 0, Values...
	>;

	// catenate:

	template<typename Continuation>
	struct cp_typename_catenate
	{
		template<template<typename...> class ListType, typename List, size_type index, typename... Values>
		using result = typename pattern_match_typename_list<List>::template push_front
		<
			cp_typename_push_to_list<Continuation>, filler, 0, Values...
		>;
	};

	template<typename List1, typename List2, typename Continuation = ch_typename_list>
	using typename_catenate = typename pattern_match_typename_list<List1>::template push_front
	<
		cp_typename_catenate<Continuation>, List2, 0
	>;

	// map:

		//	For whatever reason if I put ListKind after Continuation
		//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_typename_map
	{
		template<template<typename...> class ListKind,
			typename Op, typename List, size_type index, typename... Values>
		using result = typename Continuation::template result<ListKind, typename Op::template result<Values>...>;
	};

	template<template<typename...> class ListKind,
		typename Op, typename List, typename Continuation = ch_typename_list>
	using typename_map = typename pattern_match_typename_list<List>::template map
	<
		ListKind, cp_typename_map<Continuation>, Op, filler, 0
	>;

	// relist:

	template<typename Continuation>
	struct cp_typename_relist
	{
		template<template<typename...> class ListKind,
			typename Op, typename List, size_type index, typename... Values>
		using result = typename Continuation::template result<ListKind, Values...>;
	};

	template<template<typename...> class ListType, typename List, typename Continuation = ch_typename_list>
	using typename_relist = typename pattern_match_typename_list<List>::template map
	<
		ListType, cp_typename_relist<Continuation>, filler, filler, 0
	>;

	// zip:

		//	For whatever reason if I put ListKind after Continuation
		//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_typename_zip
	{
		template<template<typename...> class ListKind,
			typename Op, typename List, size_type index, typename... Values>
		using result = typename pattern_match_typename_list<List>::template zip
		<
			ListKind, Continuation, Op, Values...
		>;
	};

	template<template<typename...> class ListKind,
		typename Op, typename List1, typename List2, typename Continuation = ch_typename_list>
	using typename_zip = typename pattern_match_typename_list<List1>::template map
	<
		ListKind, cp_typename_zip<Continuation>, Op, List2, 0
	>;

	// cdr:

	template<typename Continuation>
	struct cp_typename_cdr
	{
		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = typename Continuation::template result<ListType, Values...>;
	};

	template<typename List, typename Continuation = ch_typename_list>
	using typename_cdr = typename pattern_match_typename_list<List>::template fold
	<
		cp_typename_cdr<Continuation>, filler, filler, 0, filler
	>;

	// multicdr:

	template<typename Continuation>
	struct cp_typename_multicdr
	{
		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = typename_list_if_then_else
		<
			ListType,

			bool(index),

			typename_fold_if_then
			<
				ListType, bool(index),
				cp_typename_multicdr<Continuation>, Op, Cond, index-1, Result, Values...
			>,

			Continuation, Values...
		>;
	};

	template<typename List, size_type index = 0, typename Continuation = ch_typename_list>
	using typename_multicdr = typename pattern_match_typename_list<List>::template fold
	<
		cp_typename_multicdr<Continuation>, filler, filler, index, filler
	>;

	// car:

	struct ch_typename_car
	{
		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = Value;
	};

	template<typename List>
	using typename_car = typename pattern_match_typename_list<List>::template fold
	<
		ch_typename_car, filler, filler, 0, filler
	>;

	// multicar:

	struct ch_typename_multicar
	{
		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = if_then_else
		<
			bool(index),

			typename_fold_if_then
			<
				ListType, bool(index),
				cp_typename_multicdr < ch_typename_list_to_ping >,
				Op, Cond, index-1, Result, Value, Values...
			>,

			Value
		>;
	};

	template<typename List, size_type index = 0>
	using typename_multicar = typename pattern_match_typename_list<List>::template fold
	<
		ch_typename_multicar, filler, filler, index, filler
	>;

	// null:

	struct ch_typename_null
	{
		template<template<typename...> class ListType, typename List, size_type index, typename... Values>
		using result = ListType<>;
	};

	template<typename List>
	using typename_null = typename pattern_match_typename_list<List>::template push_front
	<
		ch_typename_null, filler, 0
	>;

	// unite:

	template<typename List1, typename Value, typename List2, typename Continuation = ch_typename_list>
	using typename_unite = typename pattern_match_typename_list<List1>::template push_back
	<
		cp_typename_catenate<Continuation>, List2, 0, Value
	>;

	template<typename List1, typename List2, typename Continuation, typename... Values>
	using typename_multiunite = typename pattern_match_typename_list<List1>::template push_back
	<
		cp_typename_catenate<Continuation>, List2, 0, Values...
	>;

	// reverse:

	struct ch_let_typename_reverse
	{
		template<template<typename...> class ListType, bool Pred, typename List, size_type index, typename... Values>
		using let_result = if_then_else
		<
			Pred,

			typename_push_if_then
			<
				ListType, Pred,
				ch_let_typename_reverse, List, index-1, Values...
			>,

			List
		>;

		template<template<typename...> class ListType, typename List, size_type index, typename Value, typename... Values>
		using result = let_result<ListType, bool(index), typename_cons<Value, List>, index, Values...>;
	};

	struct ch_typename_reverse
	{
			// sizeof...(Values) is an optimization.

		template<template<typename...> class ListType, typename List, size_type index, typename Value, typename... Values>
		using result = typename ch_let_typename_reverse::template result
		<
			ListType, ListType<>, sizeof...(Values), Value, Values...
		>;
	};

		// The nature of this particular implementation means no continuation is possible.
		// I have implemented the version where it is and it's significantly slower,
		// enough I'm willing to break with the overall design.

	template<typename List>
	using typename_reverse = typename pattern_match_typename_list<List>::template push_front
	<
		ch_typename_reverse, filler, 0
	>;

	// fold:

	struct ch_let_typename_fold
	{
		template<template<typename...> class ListType,
			bool Pred, typename Op, typename Cond, size_type index, typename Result, typename... Values>
		using let_result = if_then_else
		<
			Pred,

			typename_fold_if_then
			<
				ListType, Pred,
				ch_let_typename_fold, Op, Cond, index-1, Result, Values...
			>,

			Result
		>;

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = let_result<ListType, bool(index), Op, Cond, index, typename Op::template result<Result, Value>, Values...>;
	};

	struct ch_typename_fold
	{
			// sizeof...(Values) is an optimization.

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = typename ch_let_typename_fold::template result
		<
			ListType, Op, Cond, sizeof...(Values), Result, Value, Values...
		>;
	};

	template<typename Op, typename Result, typename List>
	using typename_fold = typename pattern_match_typename_list<List>::template fold
	<
		ch_typename_fold, Op, filler, 0, Result
	>;

	// break_fold:

	struct ch_let_end_typename_break_fold;

	struct ch_let_break_typename_break_fold
	{
			// if we've reached this point, we know we're not at the End.

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename... Values>
		using let_result = typename_fold_if_then_else
		<
			ListType,

			Cond::template result<Result>::value,

			Result,

			ch_let_end_typename_break_fold, Op, Cond, index-1, Result, Values...
		>;

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename... Values>
		using result = let_result<ListType, Op, Cond, index, Result, Values...>;
	};

	struct ch_let_end_typename_break_fold
	{
		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename... Values>
		using let_result = typename_fold_if_then_else
		<
			ListType,

			!bool(index),

			Result,

			ch_let_break_typename_break_fold, Op, Cond, index, Result, Values...
		>;

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = let_result<ListType, Op, Cond, index, typename Op::template result<Result, Value>, Values...>;
	};

	struct ch_typename_break_fold
	{
			// sizeof...(Values) is an optimization.

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = typename ch_let_end_typename_break_fold::template result
		<
			ListType, Op, Cond, sizeof...(Values), Result, Value, Values...
		>;
	};

	template<typename Op, typename Cond, typename Result, typename List>
	using typename_break_fold = typename pattern_match_typename_list<List>::template fold
	<
		ch_typename_break_fold, Op, Cond, 0, Result
	>;

	// find:

	template<typename Continuation> struct cp_let_match_typename_find;

	template<typename Continuation>
	struct cp_let_end_typename_find
	{
		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, bool End, typename Result, typename... Values>
		using let_result = typename_fold_if_then_else
		<
			ListType,

			End,

			ListType<>,

			cp_let_match_typename_find<Continuation>, Op, Cond, index-1, Result, Values...
		>;

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename... Values>
		using result = let_result<ListType, Op, Cond, index, !bool(index), Result, Values...>;
	};

	template<typename Continuation>
	struct cp_let_match_typename_find
	{
		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, bool Match, typename Result, typename Value, typename... Values>
		using let_result = typename_fold_if_then_else
		<
			ListType,

			Match,

			typename_list_if_then
			<
				ListType, Match, Continuation, Value, Values...
			>,

			cp_let_end_typename_find<Continuation>, Op, Cond, index, Result, Values...
		>;

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = let_result<ListType, Op, Cond, index, Cond::template result<Value>::value, Result, Value, Values...>;
	};

	template<typename Continuation>
	struct cp_typename_find
	{
			// sizeof...(Values) is an optimization.

		template<template<typename...> class ListType,
			typename Op, typename Cond, size_type index, typename Result, typename Value, typename... Values>
		using result = typename cp_let_match_typename_find<Continuation>::template result
		<
			ListType, Op, Cond, sizeof...(Values), Result, Value, Values...
		>;
	};

	template<typename Cond, typename List, typename Continuation = ch_typename_list>
	using typename_find = typename pattern_match_typename_list<List>::template fold
	<
		cp_typename_find<Continuation>, filler, Cond, 0, filler
	>;
};

