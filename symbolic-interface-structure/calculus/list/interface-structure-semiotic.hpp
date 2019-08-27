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

struct structure
{
	using kind						= module;

	using rtn						= structure;

	template<typename...> struct act			{ };
	template<typename...> struct pass			{ };

/***********************************************************************************************************************/

/*
	pattern_match_builtin_list:

	Specifying the Type at the front of builtin is necessary for variadic grammar during
	the special case when (Values...) is empty, otherwise the compiler cannot deduce Type.

	For whatever reason, if the pattern

		template<...> class

	follows other template parameters it creates an internal compiler error.
	As such I have made the habit of refactoring it to the beginning.
	Unfortunately this makes the grammar more awkward than is preferred.
*/

	template<typename, typename>
	struct pattern_match_builtin_list
	{
		using rtn = pattern_match_builtin_list;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename Type, template<Type...> class ListType, Type... Values>
	struct pattern_match_builtin_list<Type, ListType<Values...>>
	{
		using rtn = pattern_match_builtin_list;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// grow:

		template
		<
			typename Continuation, typename List, size_type count, Type... Args

				//   signature: length, cons, multicons, catenate, null.

		> using push_front = typename Continuation::template result<Type, ListType, List, count, Args..., Values...>;

		template
		<
			typename Continuation, typename List, size_type count, Type... Args

				//  signature: push, multipush, unite, multiunite.

		> using push_back = typename Continuation::template result<Type, ListType, List, count, Values..., Args...>;

		// mutate:

		template
		<
			typename Kind, template<Kind...> class ListKind,

			typename Continuation, typename Op, Type... Args

			//  no signature, but required to implement zip (signature).
		>
		using zip = typename Continuation::template result<Kind, ListKind, Op::value(Args, Values)...>;

		template
		<
				// For whatever reason if I put ListKind after Continuation
				// in the following it produces an internal compiler error.

			typename Kind, template<Kind...> class ListKind,

			typename Continuation, typename Op, typename List, size_type count

			//    signature: map, relist, zip.

		> using map = typename Continuation::template result<Kind, ListKind, Type, Op, List, count, Values...>;

		// shrink:

		template
		<
			typename Continuation, typename Op, typename Cond, size_type count, Type Arg

			//     signature: fold, break_fold, find, car, multicar, cdr, multicdr.

		> using fold = typename Continuation::template result<Type, ListType, Op, Cond, count, Arg, Values...>;
	};

/***********************************************************************************************************************/

/*
	pattern_match_typename_list:
*/

	template<typename>
	struct pattern_match_typename_list
	{
		using rtn = pattern_match_typename_list;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename... Values, template<typename...> class ListType>
	struct pattern_match_typename_list<ListType<Values...>>
	{
		using rtn = pattern_match_typename_list;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// grow:

		template
		<
			typename Continuation, typename List, size_type count, typename... Args

				//   signature: length, cons, multicons, catenate, null.

		> using push_front = typename Continuation::template result<ListType, List, count, Args..., Values...>;

		template
		<
			typename Continuation, typename List, size_type count, typename... Args

				//  signature: push, multipush, unite, multiunite.

		> using push_back = typename Continuation::template result<ListType, List, count, Values..., Args...>;

		// mutate:

		template
		<
			template<typename...> class ListKind,

			typename Continuation, typename Op, typename... Args

			//  no signature, but required to implement zip (signature).
		>
		using zip = typename Continuation::template result<ListKind, typename Op::template result<Args, Values>...>;

		template
		<
				// For whatever reason if I put ListKind after Continuation
				// in the following it produces an internal compiler error.

			template<typename...> class ListKind,

			typename Continuation, typename Op, typename List, size_type count

			//    signature: map, relist, zip.

		> using map = typename Continuation::template result<ListKind, Op, List, count, Values...>;

		// shrink:

		template
		<
			typename Continuation, typename Op, typename Cond, size_type count, typename Arg

			//     signature: fold, break_fold, find, car, multicar, cdr, multicdr.

		> using fold = typename Continuation::template result<ListType, Op, Cond, count, Arg, Values...>;
	};
};

