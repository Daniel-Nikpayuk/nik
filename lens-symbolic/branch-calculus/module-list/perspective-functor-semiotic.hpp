/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	I've considered aliasing the redundant pattern

		pattern_match_*<...>::template op<signature, ....>

	but it actually slows compile times down significantly enough
	to warrant leaving as is (though I might at a future date use macros).

	Clustered signatures aren't the only signatures: echo and list.

	Using delayed conditional efficiently requires a very narrow interpretation:

	1. Due to parameter packs, the conditional grammar itself can only allow for tail recursion.
	2. Specialized versions of the conditional can then be created to simulate complex head signatures,
	   but in order to maintain efficiency:
		a) policy needs to be decided on "letting" the predicate which otherwise is placed redundantly.
		b) although head recursion is now possible, in order to minimize nesting depth all recursive
		   functions that can be put in tail recursive form should be.

	The naming convention for X_to_X is to reduce the redundant information by shortening it to X.
	For example "list_to_list" becomes "list". This convention holds because such forms are commonly
	the default option in continuation passing and so user-friendly names are privileged.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, core, kernel, identity)
	#include nik_typedef(symbolic, core, kernel, functor)

	#include nik_typedef(symbolic, calculus, boolean, functor)
	#include nik_typedef(symbolic, calculus, tail, functor)

	#include nik_typedef(symbolic, calculus, list, structure)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	// downcast:

	struct ch_list
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<Values...>;
	};

	using ch_list_to_list = ch_list;

	template<typename Continuation>
	struct cp_grow_to_list
	{
		template<typename Type, template<Type...> class ListType, typename List, Type... Values>
		using result = typename Continuation::template result<Type, ListType, Values...>;
	};

	template<typename Continuation>
	struct cp_mutate_to_list
	{
		template<typename Kind, template<Kind...> class ListKind,
				typename Type, template<Type...> class ListType,
					typename Op, typename List, Kind... Values>
		using result = typename Continuation::template result<Kind, ListKind, Values...>;
	};

	template<typename Continuation>
	struct cp_shrink_to_list
	{
		template<typename Type, template<Type...> class ListType,
				typename Op_Cond, size_type count, typename List, Type... Values>
		using result = typename Continuation::template result<Type, ListType, Values...>;
	};

	template<typename Continuation>
	struct cp_patch_to_list
	{
		template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
				typename Op_Cond, size_type count, typename OutList, typename InList, Type... Values>
		using result = typename pattern_match_list<Kind, OutList>::template to_grow__prepend
		<
			cp_grow_to_list<Continuation>, filler
		>;
	};

/*
	grow:
*/

	struct ch_list_null
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = ListType<>;
	};

	using ch_list_to_list_null = ch_list_null;

	struct ch_grow_to_list_null // grow_to_list . list_to_list_null
	{
		template<typename Type, template<Type...> class ListType, typename List, Type... Values>
		using result = ListType<>;
	};

	// null:

	template<typename Type, typename List>
	using null = typename pattern_match_list<Type, List>::template to_grow__prepend
	<
		ch_grow_to_list_null, filler
	>;

	// multicons:

		// Default Continuation values must be given externally.

	template<typename Type, typename List, typename Continuation, Type... Values>
	using multicons = typename pattern_match_list<Type, List>::template to_grow__prepend
	<
		cp_grow_to_list<Continuation>, filler, Values...
	>;

	// cons:

	template<typename Type, Type Value, typename List, typename Continuation = ch_list>
	using cons = typename pattern_match_list<Type, List>::template to_grow__prepend
	<
		cp_grow_to_list<Continuation>, filler, Value
	>;

	// car:

	template<typename Continuation>
	struct cp_list_to_echo_car
	{
		template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, Value>;
	};

	template<typename Continuation>
	struct cp_grow_to_echo_car // grow_to_list . list_to_echo_car
	{
		template<typename Type, template<Type...> class ListType, typename List, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, Value>;
	};

	template<typename Type, typename List, typename Continuation = ch_echo>
	using car = typename pattern_match_list<Type, List>::template to_grow__prepend
	<
		cp_grow_to_echo_car<Continuation>, filler
	>;

	// cdr:

	template<typename Continuation>
	struct cp_list_cdr
	{
		template<typename Type, template<Type...> class ListType, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, ListType, Values...>;
	};

	template<typename Continuation>
	using cp_list_to_list_cdr = cp_list_cdr<Continuation>;

	template<typename Continuation>
	struct cp_grow_to_list_cdr // grow_to_list . list_to_list_cdr
	{
		template<typename Type, template<Type...> class ListType, typename List, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, ListType, Values...>;
	};

	template<typename Type, typename List, typename Continuation = ch_list>
	using cdr = typename pattern_match_list<Type, List>::template to_grow__prepend
	<
		cp_grow_to_list_cdr<Continuation>, filler
	>;

	// length:

	template<typename Continuation>
	struct cp_list_to_echo_length
	{
		template<typename Type, template<Type...> class ListType, Type... Values>
		using result = typename Continuation::template result<size_type, sizeof...(Values)>;
	};

	template<typename Continuation>
	struct cp_grow_to_echo_length // grow_to_list . list_to_echo_length
	{
		template<typename Type, template<Type...> class ListType, typename List, Type... Values>
		using result = typename Continuation::template result<size_type, sizeof...(Values)>;
	};

	template<typename Type, typename List, typename Continuation = ch_echo>
	using length = typename pattern_match_list<Type, List>::template to_grow__prepend
	<
		cp_grow_to_echo_length<Continuation>, filler
	>;

	// catenate:

	template<typename Continuation>
	struct cp_grow_to_list_catenate
	{
		template<typename Type, template<Type...> class ListType, typename List, Type... Values>
		using result = typename pattern_match_list<Type, List>::template to_grow__prepend
		<
			cp_grow_to_list<Continuation>, filler, Values...
		>;
	};

	template<typename Type, typename List1, typename List2, typename Continuation = ch_list>
	using catenate = typename pattern_match_list<Type, List1>::template to_grow__prepend
	<
		cp_grow_to_list_catenate<Continuation>, List2
	>;

	// multipush:

		// Default Continuation values must be given externally.

	template<typename Type, typename List, typename Continuation, Type... Values>
	using multipush = typename pattern_match_list<Type, List>::template to_grow__append
	<
		cp_grow_to_list<Continuation>, filler, Values...
	>;

	// push:

	template<typename Type, Type Value, typename List, typename Continuation = ch_list>
	using push = typename pattern_match_list<Type, List>::template to_grow__append
	<
		cp_grow_to_list<Continuation>, filler, Value
	>;

	// multiunite:

	template<typename Type, typename List1, typename List2, typename Continuation, Type... Values>
	using multiunite = typename pattern_match_list<Type, List1>::template to_grow__append
	<
		cp_grow_to_list_catenate<Continuation>, List2, Values...
	>;

	// unite:

	template<typename Type, typename List1, Type Value, typename List2, typename Continuation = ch_list>
	using unite = typename pattern_match_list<Type, List1>::template to_grow__append
	<
		cp_grow_to_list_catenate<Continuation>, List2, Value
	>;

/***********************************************************************************************************************/

	// zip:

		//	For whatever reason if I put ListKind after Continuation
		//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_mutate_to_list_zip
	{
		template<typename Kind, template<Kind...> class ListKind,
				typename Type, template<Type...> class ListType,
					typename Op, typename List, Type... Values>
		using result = typename pattern_match_list<Type, List>::template internal_zip
		<
			Kind, ListKind, Continuation, Op, Values...
		>;
	};

	template<typename Kind, template<Kind...> class ListKind, typename Type,
			typename Op, typename List1, typename List2, typename Continuation = ch_list>
	using zip = typename pattern_match_list<Type, List1>::template to_mutate
	<
		Kind, ListKind, cp_mutate_to_list_zip<Continuation>, Op, List2
	>;

	// map:

		//	For whatever reason if I put ListKind after Continuation
		//	in the following it produces an internal compiler error.

	template<typename Continuation>
	struct cp_mutate_to_list_map
	{
		template<typename Kind, template<Kind...> class ListKind,
				typename Type, template<Type...> class ListType,
					typename Op, typename List, Type... Values>
		using result = typename Continuation::template result<Kind, ListKind, Op::value(Values)...>;
	};

	template<typename Kind, template<Kind...> class ListKind, typename Type,
			typename Op, typename List, typename Continuation = ch_list>
	using map = typename pattern_match_list<Type, List>::template to_mutate
	<
		Kind, ListKind, cp_mutate_to_list_map<Continuation>, Op, filler
	>;

	// rename:

	template<typename Continuation>
	struct cp_mutate_to_list_rename
	{
		template<typename Kind, template<Kind...> class ListKind,
				typename Type, template<Type...> class ListType,
					typename Op, typename List, Type... Values>
		using result = typename Continuation::template result<Kind, ListKind, Values...>;
	};

	template<typename Kind, template<Kind...> class ListKind, typename List, typename Continuation = ch_list>
	using rename = typename pattern_match_list<Kind, List>::template to_mutate
	<
		Kind, ListKind, cp_mutate_to_list_rename<Continuation>, filler, filler
	>;

/***********************************************************************************************************************/

	// split_fold:

	template<typename Continuation>
	struct cp_shrink_split_fold
	{
		struct end
		{
			template<typename Type, template<Type...> class ListType, typename Kind,
				typename Op_Cond, size_type count, Kind Moment, Type... Values>
			using result = shrink_if_then_else
			<
				Type, ListType,

				!bool(count), // End

				shrink_if_then
				<
					Type, ListType, !bool(count), Kind, Continuation, Op_Cond, count, Moment, Values...
				>,

				cp_shrink_split_fold<Continuation>, Kind, Op_Cond, count-1, Moment, Values...
			>;
		};

		struct match
		{
			template<typename Type, template<Type...> class ListType, typename Kind,
				bool Match, typename Op_Cond, size_type count, Kind Moment, Type... Values>
			using result = typename if_then_else
			<
				Match,

				Continuation,

				end

			>::template result
			<
				Type, ListType, Kind, Op_Cond, count, Moment, Values...
			>;
		};

		template<typename Type, template<Type...> class ListType, typename Kind,
			typename Op_Cond, size_type count, Kind Moment, Type Value, Type... Values>
		using result = typename Op_Cond::template result
		<
			Type, ListType, match, Op_Cond, count, Moment, Value, Values...
		>;
	};

	template<typename Continuation>
	using cp_shrink_to_shrink_split_fold = cp_shrink_split_fold<Continuation>;

		// length - 1 is an optimization.

	template<typename Kind, typename Type, typename Op_Cond, Kind Moment, typename List, typename Continuation = ch_list>
	using split_fold = typename pattern_match_list<Type, List>::template to_shrink
	<
		cp_shrink_split_fold < cp_shrink_to_list < Continuation >>,
			Kind, Op_Cond, length<Type, List>::value - 1, Moment
	>;

	// fold:

/*
	template<typename Continuation>
	struct cp_shrink_to_echo_car // shrink_to_list . list_to_echo_car
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, size_type count, typename List, Type Value, Type... Values>
		using result = typename Continuation::template result<Type, Value>;
	};

	template<typename Continuation>
	struct cp_shrink_fold__end
	{
			// if we've reached this point, we know we've not yet found an end.

		template<typename Type, template<Type...> class ListType,
			bool End, typename Op, size_type count, typename List, Type Moment, Type... Values>
		using let_result = shrink_if_then_else
		<
			Type, ListType,

			End,

			shrink_if_then
			<
				Type, ListType, End, Continuation, Op, count, List, Moment, Values...
			>,

			cp_shrink_fold__end<Continuation>, Op, count-1, List, Moment, Values...
		>;

		template<typename Type, template<Type...> class ListType,
			typename Op, size_type count, typename List, Type Moment, Type Value, Type... Values>
		using result = let_result<Type, ListType, !bool(count), Op, count, List, Op::value(Moment, Value), Values...>;
	};

	template<typename Continuation>
	struct cp_length_shrink_fold
	{
			// sizeof...(Values) is an optimization.

		template<typename Type, template<Type...> class ListType,
			typename Op, size_type count, typename List, Type Moment, Type Value, Type... Values>
		using result = typename cp_shrink_fold__end<Continuation>::template result
		<
			Type, ListType, Op, sizeof...(Values), List, Moment, Value, Values...
		>;
	};

	template<typename Continuation>
	struct cp_shrink_fold
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, size_type count, typename List, Type Moment, Type... Values>
		using result = typename cp_shrink_fold__end<Continuation>::template result
		<
			Type, ListType, Op, count, List, Moment, Values...
		>;
	};

	using shrink_to_shrink = shrink;

	template<typename Type, typename Op, Type Moment, typename List, typename Continuation = ch_echo>
	using fold = typename pattern_match_list<Type, List>::template to_shrink
	<
		cp_length_shrink_fold < cp_shrink_to_echo_car < Continuation >>,
		Op, 0, filler, Moment
	>;
*/

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
	template<typename Type, template<Type...> class ListType,
		typename Op, size_type depth, typename List, Type... Values>
	struct ch_shrink
	{
		using rtn = shrink;

		template
		<
			template<typename> class Proc, typename Continuation, size_type count,

		> using apply = typename Continuation::template trampoline
		<
			Type, ListType, Proc, Op, count, depth, List, Values...
		>;
	};

	using shrink_to_shrink = shrink;

		// assumes count > depth on first call.

	template<typename Continuation>
	struct cp_shrink_trampoline
	{
		template<typename Type, template<Type...> class ListType, template<typename> class Proc,
			typename Op, size_type count, size_type depth, typename List, Type... Values>
		using recurse result = shrink_if_then_else
		<
			(count > depth),

			trampoline_shrink_if_then
			<
				Type ListType, (count > depth),
				cp_shrink_trampoline<Continuation>, Proc, Op, count, depth, List, Values...
			>,

			Proc<Continuation>, Type ListType, Op, count, List, Values...
		>;

		template<template<typename> class Proc, size_type count, typename Shrink>
		using let_result = typename Shrink::template trampoline
		<
			recurse_result
		>;

		template<typename Type, template<Type...> class ListType, template<typename> class Proc,
			typename Op, size_type count, size_type depth, typename List, Type... Values>
		using result = let_result
		<
			Proc, count - depth,
			typename Proc<ch_shrink>::template result<Type, ListType, Op, depth, List, Values...>
		>;
	};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	template<typename Type, typename Op, Type Moment, typename List, typename Continuation = ch_echo>
	using trampoline_fold = typename pattern_match_list<Type, List>::template to_shrink
	<
		cp_length_shrink_fold<Continuation>, Op, 0, filler, Moment
	>;
*/

	// find:

/*
	template<typename Continuation> struct cp_shrink_find__match;

	template<typename Continuation>
	struct cp_shrink_find__end
	{
		template<typename Type, template<Type...> class ListType,
			typename Cond, size_type count, typename List, Type... Values>
		using result = shrink_if_then_else
		<
			Type, ListType,

			bool(count), // NotEnd

			shrink_if_then
			<
				Type, ListType, bool(count),
				cp_shrink_find__match<Continuation>,
				Cond, count-1, List, Values...
			>,

			Continuation, Cond, count, List, Values...
		>;
	};

	template<typename Continuation>
	struct cp_shrink_find__match
	{
		template<typename Type, template<Type...> class ListType,
			bool Match, typename Cond, size_type count, typename List, Type Value, Type... Values>
		using let_result = shrink_if_then_else
		<
			Type, ListType,

			Match,

			shrink_if_then
			<
				Type, ListType, Match, Continuation, Cond, count, List, Value, Values...
			>,

			cp_shrink_find__end<Continuation>, Cond, count, List, Values...
		>;

		template<typename Type, template<Type...> class ListType,
			typename Cond, size_type count, typename List, Type Value, Type... Values>
		using result = let_result<Type, ListType, Cond::value(Value), Cond, count, List, Value, Values...>;
	};

	template<typename Continuation>
	struct cp_shrink_find
	{
			// sizeof...(Values) is an optimization.

		template<typename Type, template<Type...> class ListType,
			typename Cond, size_type count, typename List, Type Value, Type... Values>
		using result = typename cp_shrink_find__match<Continuation>::template result
		<
			Type, ListType, Cond, sizeof...(Values), List, Value, Values...
		>;
	};

	using shrink_to_shrink = shrink;

	template<typename Type, typename Cond, typename List, typename Continuation = ch_list>
	using find = typename pattern_match_list<Type, List>::template to_shrink
	<
		cp_shrink_find < cp_shrink_to_list < Continuation >>, Cond, 0, filler
	>;
*/

	// multicdr:

/*
	template<typename Continuation>
	struct cp_shrink_to_list_multicdr
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, size_type count, typename List, Type Value, Type... Values>
		using result = list_if_then_else
		<
			Type, ListType,

			bool(count), // NotEnd

			shrink_if_then
			<
				Type, ListType, bool(count),
				cp_shrink_to_list_multicdr<Continuation>, Op, count-1, List, Values...
			>,

			Continuation, Values...
		>;
	};

	template<typename Type, typename List, size_type count = 0, typename Continuation = ch_list>
	using multicdr = typename pattern_match_list<Type, List>::template to_shrink
	<
		cp_shrink_to_list_multicdr<Continuation>, filler, count, filler
	>;
*/

	// multicar:

/*
	template<typename Continuation>
	struct cp_shrink_to_echo_multicar
	{
		template<typename Type, template<Type...> class ListType,
			typename Op, size_type count, typename List, Type Value, Type... Values>
		using result = echo_if_then_else
		<
			Type,

			bool(count), // NotEnd

			shrink_if_then
			<
				Type, ListType, bool(count),
				cp_shrink_to_list_multicdr < cp_list_to_echo_car < Continuation >>,
				Op, count-1, List, Value, Values...
			>,

			Continuation, Value
		>;
	};

	template<typename Type, typename List, size_type count = 0, typename Continuation = ch_echo>
	using multicar = typename pattern_match_list<Type, List>::template to_shrink
	<
		cp_shrink_to_echo_multicar<Continuation>, filler, count, filler
	>;
*/

	// reverse:

/*
	struct ch_shrink_to_list_reverse__end
	{
		template<typename Type, template<Type...> class ListType,
			bool NotEnd, typename Op, size_type count, typename List, Type... Values>
		using let_result = if_then_else
		<
			NotEnd,

			shrink_if_then
			<
				Type, ListType, NotEnd,
				ch_shrink_to_list_reverse__end, Op, count-1, List, Values...
			>,

			List
		>;

		template<typename Type, template<Type...> class ListType,
			typename Op, size_type count, typename List, Type Value, Type... Values>
		using result = let_result<Type, ListType, bool(count), Op, count, cons<Type, Value, List>, Values...>;
	};

	struct ch_shrink_to_list_reverse
	{
			// sizeof...(Values) is an optimization.

		template<typename Type, template<Type...> class ListType,
			typename Op, size_type count, typename List, Type Value, Type... Values>
		using result = typename ch_shrink_to_list_reverse__end::template result
		<
			Type, ListType, Op, sizeof...(Values), ListType<>, Value, Values...
		>;
	};

		// The nature of this particular implementation means no continuation is possible.
		// I have implemented the version where it is and it's significantly slower,
		// enough I'm willing to break with the overall design.

	template<typename Type, typename List>
	using reverse = typename pattern_match_list<Type, List>::template to_shrink
	<
		ch_shrink_to_list_reverse, filler, 0, filler
	>;
*/

/***********************************************************************************************************************/

	// split_zip:

/*
	template<typename Continuation> struct cp_split_zip__match;

	template<typename Continuation>
	struct cp_split_zip__end
	{
		template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
			typename Op_Cond, size_type count, typename OutList, typename InList, Type... Values>
		using result = typename if_then_else
		<
			bool(count), // NotEnd

			cp_split_zip__match<Continuation>,

			Continuation

		>::template result
		<
			Kind, ListKind, Type, ListType, Op_Cond, count-1, OutList, InList, Values...
		>;
	};

	template<typename Continuation>
	struct cp_split_zip__match
	{
		struct let_result
		{
			template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
				bool Match, typename Op_Cond, size_type count, typename OutList, typename InList, Type... Values>
			using result = typename if_then_else
			<
				Match,

				Continuation,

				cp_split_zip__end<Continuation>

			>::template result
			<
				Kind, ListKind, Type, ListType, Op_Cond, count, OutList, InList, Values...
			>;
		};

		template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
			typename Op_Cond, size_type count, typename OutList, typename InList, Type Value, Type... Values>
		using result = typename Op_Cond::template result
		<
			Kind, ListKind, Type, ListType, let_result, Op_Cond, count, OutList, InList, Value, Values...
		>;
	};

	template<typename Continuation>
	struct cp_split_zip
	{
			// sizeof...(Values) is an optimization.

		template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
			typename Op_Cond, size_type count, typename OutList, typename InList, Type Value, Type... Values>
		using result = typename cp_split_zip__match<Continuation>::template result
		<
			Kind, ListKind, Type, ListType, Op_Cond, sizeof...(Values), ListKind<>, InList, Value, Values...
		>;
	};

	using patch_to_patch = patch;

	template<typename Kind, template<Kind...> class ListKind,
		typename Type, typename Op_Cond, typename List1, typename List2, typename Continuation = ch_list>
	using split_zip = typename pattern_match_list<Type, List1>::template to_patch
	<
		Kind, ListKind, cp_split_zip < cp_patch_to_list < Continuation >>, Op_Cond, 0, filler, List2
	>;

	using patch_to_patch = patch;
*/

	// split_map:

/*
	template<typename Continuation> struct cp_split_map__match;

	template<typename Continuation>
	struct cp_split_map__end
	{
		template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
			typename Op_Cond, size_type count, typename OutList, typename InList, Type... Values>
		using result = typename if_then_else
		<
			bool(count), // NotEnd

			cp_split_map__match<Continuation>,

			Continuation

		>::template result
		<
			Kind, ListKind, Type, ListType, Op_Cond, count-1, OutList, InList, Values...
		>;
	};

	template<typename Continuation>
	struct cp_split_map__match
	{
		struct let_result
		{
			template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
				bool Match, typename Op_Cond, size_type count, typename OutList, typename InList, Type... Values>
			using result = typename if_then_else
			<
				Match,

				Continuation,

				cp_split_map__end<Continuation>

			>::template result
			<
				Kind, ListKind, Type, ListType, Op_Cond, count, OutList, InList, Values...
			>;
		};

		template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
			typename Op_Cond, size_type count, typename OutList, typename InList, Type Value, Type... Values>
		using result = typename Op_Cond::template result
		<
			Kind, ListKind, Type, ListType, let_result, Op_Cond, count, OutList, InList, Value, Values...
		>;
	};

	template<typename Continuation>
	struct cp_split_map
	{
			// sizeof...(Values) is an optimization.

		template<typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,
			typename Op_Cond, size_type count, typename OutList, typename InList, Type Value, Type... Values>
		using result = typename cp_split_map__match<Continuation>::template result
		<
			Kind, ListKind, Type, ListType, Op_Cond, sizeof...(Values), ListKind<>, InList, Value, Values...
		>;
	};

	using patch_to_patch = patch;

	template<typename Kind, template<Kind...> class ListKind,
		typename Type, typename Op_Cond, typename List, typename Continuation = ch_list>
	using split_map = typename pattern_match_list<Type, List>::template to_patch
	<
		Kind, ListKind, cp_split_map < cp_patch_to_list < Continuation >>, Op_Cond, 0, filler, filler
	>;

	using patch_to_patch = patch;
*/
};

