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

	struct skip
	{
		using kind					= module;

		using rtn					= skip;
	};

/*
	memoized_builtin_list:
*/

	template<typename, typename>
	struct memoized_builtin_list
	{
		using rtn = memoized_builtin_list;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename Type, Type... Values, template<Type...> class ListType>
	struct memoized_builtin_list<Type, ListType<Values...>>
	{
		using rtn = memoized_builtin_list;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// grow:

		template
		<
			typename Continuation, Type... Args

				//   signature: cons, multicons, car, cdr, null, length.

		> using push_front = typename Continuation::template result<Type, ListType, Args..., Values...>;

		template
		<
			typename Continuation, Type... Args

				//  signature: push, multipush.

		> using push_back = typename Continuation::template result<Type, ListType, Values..., Args...>;

		template
		<
			typename Continuation, typename List, Type... Args

				//   signature: catenate.

		> using join_front = typename Continuation::template result<Type, List, Args..., Values...>;

		template
		<
			typename Continuation, typename List, Type... Args

				//  signature: unite, multiunite.

		> using join_back = typename Continuation::template result<Type, List, Values..., Args...>;

		// mutate:

		template
		<
			typename Continuation, template<Type...> class ListType0

			//     signature: name, rename.

		> using wrap = typename Continuation::template result<Type, ListType0, ListType, Values...>;

		template
		<
			typename Continuation, typename Kind, template<Kind...> class ListKind, typename Op

			//    signature: map.

		> using map = typename Continuation::template result<Kind, ListKind, Type, Op, Values...>;

			//  no signature, but required for zip (signature).

		template<typename Kind, template<Kind...> class ListKind, typename Op, Type... Args>
		using bimap = ListKind<Op::value(Args, Values)...>;

		template
		<
			typename Continuation, typename Kind, template<Kind...> class ListKind, typename Op, typename List

			//    signature: zip.

		> using zip = typename Continuation::template result<Kind, ListKind, Type, Op, List, Values...>;

		// shrink:

		template
		<
			typename Continuation, size_type count

			//    signature: multicar, multicdr.

		> using pop = typename Continuation::template result<Type, ListType, count, Values...>;

		template
		<
			typename Continuation, typename Op, Type Arg, size_type count

			//     signature: fold.

		> using fold = typename Continuation::template result<Type, Op, Arg, count, Values...>;
	};

/*
	memoized_typename_list:
*/

	template<typename>
	struct memoized_typename_list
	{
		using rtn = memoized_typename_list;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<false>;
	};

	template<typename... Values, template<typename...> class ListType>
	struct memoized_typename_list<ListType<Values...>>
	{
		using rtn = memoized_typename_list;

		// identify:

		template
		<
			typename Continuation

			//      signature: id.

		> using match = typename Continuation::template result<true>;

		// grow:

		template
		<
			typename Continuation, typename... Args

				//   signature: cons, multicons, car, cdr, null, length.

		> using push_front = typename Continuation::template result<ListType, Args..., Values...>;

		template
		<
			typename Continuation, typename... Args

				//  signature: push, multipush.

		> using push_back = typename Continuation::template result<ListType, Values..., Args...>;

		template
		<
			typename Continuation, typename List, typename... Args

				//   signature: catenate.

		> using join_front = typename Continuation::template result<List, Args..., Values...>;

		template
		<
			typename Continuation, typename List, typename... Args

				//  signature: unite, multiunite.

		> using join_back = typename Continuation::template result<List, Values..., Args...>;

		// mutate:

		template
		<
			typename Continuation, template<typename...> class ListType0

			//     signature: name, rename.

		> using wrap = typename Continuation::template result<ListType0, ListType, Values...>;

		template
		<
			typename Continuation, template<typename...> class ListKind, typename Op

			//    signature: map.

		> using map = typename Continuation::template result<ListKind, Op, Values...>;

			//  no signature, but required for zip (signature).

		template<template<typename...> class ListKind, typename Op, typename... Args>
		using bimap = ListKind<typename Op::template instance<Args, Values>...>;

		template
		<
			typename Continuation, template<typename...> class ListKind, typename Op, typename List

			//    signature: zip.

		> using zip = typename Continuation::template result<ListKind, Op, List, Values...>;

		// shrink:

		template
		<
			typename Continuation, size_type count

			//    signature: multicar, multicdr.

		> using pop = typename Continuation::template result<ListType, count, Values...>;

		template
		<
			typename Continuation, typename Op, typename Arg, size_type count

			//     signature: fold.

		> using fold = typename Continuation::template result<Op, Arg, count, Values...>;
	};
};

