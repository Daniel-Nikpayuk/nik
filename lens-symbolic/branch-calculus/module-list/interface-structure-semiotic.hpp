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

struct structure
{
	using kind						= module;

	using rtn						= structure;

//	template<typename...> struct act			{ };
//	template<typename...> struct pass			{ };

/***********************************************************************************************************************/

/*
	pattern_match_list:

	Specifying the Type at the front of pattern_match_list is necessary for variadic grammar during
	the special case when (Values...) is empty, otherwise the compiler cannot deduce Type.

	For whatever reason, if the pattern

		template<...> class

	follows other template parameters it creates an internal compiler error.
	As such I have made the habit of refactoring it to the beginning.
	Unfortunately this makes the grammar more awkward than is preferred.
*/

	template<typename, typename>
	struct pattern_match_list
	{
		using rtn = pattern_match_list;

	// to_match: id.

		template
		<
			typename Continuation

		> using to_match = typename Continuation::template result<false>;
	};

	template<typename Type, template<Type...> class ListType, Type... Values>
	struct pattern_match_list<Type, ListType<Values...>>
	{
		using rtn = pattern_match_list;

	// to_match: id.

		template
		<
			typename Continuation

		> using to_match = typename Continuation::template result<true>;

	// to_grow__prepend: null, multicons, cons, car, cdr, length, catenate.

		template
		<
			typename Continuation, typename List, Type... Args

		> using to_grow__prepend = typename Continuation::template result
		<
			Type, ListType, List, Args..., Values...
		>;

	// to_grow__append: multipush, push, multiunite, unite.

		template
		<
			typename Continuation, typename List, Type... Args

		> using to_grow__append = typename Continuation::template result
		<
			Type, ListType, List, Values..., Args...
		>;

	// internal_zip: no signature, but required to implement zip (signature).

		template
		<
				// For whatever reason if I put ListKind after Continuation
				// in the following it produces an internal compiler error.

			typename Kind, template<Kind...> class ListKind,

			typename Continuation, typename Op, Type... Args
		>
		using internal_zip = typename Continuation::template result<Kind, ListKind, Op::value(Args, Values)...>;

	// to_mutate: zip, map, rename.

		template
		<
				// For whatever reason if I put ListKind after Continuation
				// in the following it produces an internal compiler error.

			typename Kind, template<Kind...> class ListKind,

			typename Continuation, typename Op, typename List

		> using to_mutate = typename Continuation::template result
		<
			Kind, ListKind, Type, ListType, Op, List, Values...
		>;

	// to_shrink: split_fold, fold, find, multicdr, multicar, reverse.

		template
		<
			typename Continuation, typename Kind,

			typename Op_Cond, size_type count, Kind... Moment

		> using to_shrink = typename Continuation::template result
		<
			Type, ListType, Kind, Op_Cond, count, Moment..., Values...
		>;

	// to_patch: split_zip, split_map.

		template
		<
				// For whatever reason if I put ListKind after Continuation
				// in the following it produces an internal compiler error.

			typename Kind, template<Kind...> class ListKind,

			typename Continuation, typename Op_Cond, size_type count, typename List0, typename List1

		> using to_patch = typename Continuation::template result
		<
			Kind, ListKind, Type, ListType, Op_Cond, count, List0, List1, Values...
		>;
	};
};

