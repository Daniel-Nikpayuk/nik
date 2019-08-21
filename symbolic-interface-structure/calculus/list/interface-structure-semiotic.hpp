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

	struct not_found					{ };

	template<typename...> struct act			{ };
	template<typename...> struct pass			{ };

/*
	pattern_match_builtin_list:
*/

	template<typename>
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
	struct pattern_match_builtin_list<ListType<Values...>>
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

			//     signature: relist.

		> using wrap = typename Continuation::template result<Type, ListType0, ListType, Values...>;

		template
		<
				// For whatever reason if I put Kind after Continuation
				// in the following it produces an internal compiler error.

			typename Kind, typename Continuation, template<Kind...> class ListKind, typename Op

			//    signature: map.

		> using map = typename Continuation::template result<Kind, ListKind, Type, Op, Values...>;

		template
		<
				// For whatever reason if I put Kind after Continuation
				// in the following it produces an internal compiler error.

			typename Kind, typename Continuation, template<Kind...> class ListKind, typename Op, typename List

			//    signature: zip.

		> using bimap = typename Continuation::template result<Kind, ListKind, Type, Op, List, Values...>;

		template
		<
			typename Kind, typename Continuation, template<Kind...> class ListKind, typename Op, Type... Args

			//  no signature, but required for bimap (signature).
		>
		using zip = typename Continuation::template result<Kind, ListKind, Op::value(Args, Values)...>;

		// shrink:

		template
		<
			typename Continuation, size_type count

			//    signature: multicar, multicdr.

		> using pop = typename Continuation::template result<Type, ListType, count, Values...>;

		template
		<
			typename Continuation, typename Op, Type Arg

			//     signature: fold.

		> using fold = typename Continuation::template result<Type, Op, Arg, Values...>;
	};

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

			//     signature: relist.

		> using wrap = typename Continuation::template result<ListType0, ListType, Values...>;

		template
		<
			typename Continuation, template<typename...> class ListKind, typename Op

			//    signature: map.

		> using map = typename Continuation::template result<ListKind, Op, Values...>;

		template
		<
			typename Continuation, template<typename...> class ListKind,
				template<typename, typename> class Op, typename List

			//    signature: zip.

		> using bimap = typename Continuation::template result<ListKind, Op, List, Values...>;

		template
		<
			typename Continuation, template<typename...> class ListKind,
				template<typename, typename> class Op, typename... Args

			//  no signature, but required for bimap (signature).

		> using zip = typename Continuation::template result<ListKind, Op<Args, Values>...>;

		// shrink:

		template
		<
			typename Continuation, size_type count

			//    signature: multicar, multicdr.

		> using pop = typename Continuation::template result<ListType, count, Values...>;

		template
		<
			typename Continuation, typename Op, typename Arg

			//     signature: fold.

		> using fold = typename Continuation::template result<Op, Arg, Values...>;
	};
};

