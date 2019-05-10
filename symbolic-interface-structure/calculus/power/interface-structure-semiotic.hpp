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

/*
	builtin_list:
*/

	template<typename, typename>
	struct builtin_list
	{
		using rtn = builtin_list;

		// identify:

		template
		<
			template<bool> class signature

			//      signature: id.

		> using match = signature<false>;
	};

	template<typename Type, Type... Values, template<Type...> class ListType>
	struct builtin_list<Type, ListType<Values...>>
	{
		using rtn = builtin_list;

		// identify:

		template
		<
			template<bool> class signature

			//      signature: id.

		> using match = signature<true>;

		// grow:

		template
		<
			template<typename Kind, template<Kind...> class ListKind, Kind...> class signature,
			Type... Args

				//   signature: cons, multicons, car, cdr, null, length.

		> using push_front = signature<Type, ListType, Args..., Values...>;

		template
		<
			template<typename Kind, template<Kind...> class ListKind, Kind...> class signature,
			Type... Args

				//  signature: push, multipush.

		> using push_back = signature<Type, ListType, Values..., Args...>;

		template
		<
			template<typename Kind, typename Object, Kind...> class signature,
			typename List, Type... Args

				//   signature: catenate.

		> using join_front = signature<Type, List, Args..., Values...>;

		template
		<
			template<typename Kind, typename Object, Kind...> class signature,
			typename List, Type... Args

				//  signature: unite, multiunite.

		> using join_back = signature<Type, List, Values..., Args...>;

		// mutate:

		template
		<
			template
			<
				typename Kind0,
				template<Kind0...> class ListKind0,
				template<Kind0...> class ListKind1,
				Kind0...

			> class signature,

			template<Type...> class ListType0

			//     signature: name, rename.

		> using wrap = signature<Type, ListType0, ListType, Values...>;

		template
		<
			template
			<
				typename Kind0, template<Kind0...> class ListKind0,
				typename Kind1, typename Func, Kind1...

			> class signature,

			typename Kind, template<Kind...> class ListKind,
			typename Op

			//    signature: map.

		> using map = signature<Kind, ListKind, Type, Op, Values...>;

			//  no signature, but required for zip (signature).

		template<typename Kind, template<Kind...> class ListKind, typename Op, Type... Args>
		using bimap = ListKind<Op::value(Args, Values)...>;

		template
		<
			template
			<
				typename Kind0, template<Kind0...> class ListKind0,
				typename Kind1, typename Func, typename Object, Kind1...

			> class signature,

			typename Kind, template<Kind...> class ListKind,
			typename Op, typename List

			//    signature: zip.

		> using zip = signature<Kind, ListKind, Type, Op, List, Values...>;

		// shrink:

		template
		<
			template<typename Kind0, template<Kind0...> class ListKind0, size_type index, Kind0...> class signature,
			size_type count

			//    signature: multicar, multicdr.

		> using pop = signature<Type, ListType, count, Values...>;

		template
		<
			template<typename Kind0, typename Func, Kind0 Arg0, size_type index, Kind0...> class signature,
			typename Op, Type Arg, size_type count

			//     signature: fold.

		> using fold = signature<Type, Op, Arg, count, Values...>;
	};

/*
	typename_list:
*/

	template<typename>
	struct typename_list
	{
		using rtn = typename_list;

		// identify:

		template
		<
			template<bool> class signature

			//      signature: id.

		> using match = signature<false>;
	};

	template<typename... Values, template<typename...> class ListType>
	struct typename_list<ListType<Values...>>
	{
		using rtn = typename_list;

		// identify:

		template
		<
			template<bool> class signature

			//      signature: id.

		> using match = signature<true>;

		// grow:

		template
		<
			template<template<typename...> class ListKind, typename...> class signature,
			typename... Args

				//   signature: cons, multicons, car, cdr, null, length.

		> using push_front = signature<ListType, Args..., Values...>;

		template
		<
			template<template<typename...> class ListKind, typename...> class signature,
			typename... Args

				//  signature: push, multipush.

		> using push_back = signature<ListType, Values..., Args...>;

		template
		<
			template<typename Object, typename...> class signature,
			typename List, typename... Args

				//   signature: catenate.

		> using join_front = signature<List, Args..., Values...>;

		template
		<
			template<typename Object, typename...> class signature,
			typename List, typename... Args

				//  signature: unite, multiunite.

		> using join_back = signature<List, Values..., Args...>;

		// mutate:

		template
		<
			template
			<
				template<typename...> class ListKind0,
				template<typename...> class ListKind1,
				typename...

			> class signature,

			template<typename...> class ListType0

			//     signature: name, rename.

		> using wrap = signature<ListType0, ListType, Values...>;

		template
		<
			template
			<
				template<typename...> class ListKind0,
				typename Func, typename...

			> class signature,

			template<typename...> class ListKind,
			typename Op

			//    signature: map.

		> using map = signature<ListKind, Op, Values...>;

			//  no signature, but required for zip (signature).

		template<template<typename...> class ListKind, typename Op, typename... Args>
		using bimap = ListKind<typename Op::template instance<Args, Values>...>;

		template
		<
			template
			<
				template<typename...> class ListKind0,
				typename Func, typename Object, typename...

			> class signature,

			template<typename...> class ListKind,
			typename Op, typename List

			//    signature: zip.

		> using zip = signature<ListKind, Op, List, Values...>;

		// shrink:

		template
		<
			template<template<typename...> class ListKind0, size_type index, typename...> class signature,
			size_type count

			//    signature: multicar, multicdr.

		> using pop = signature<ListType, count, Values...>;

		template
		<
			template<typename Func, typename Arg0, size_type index, typename...> class signature,
			typename Op, typename Arg, size_type count

			//     signature: fold.

		> using fold = signature<Op, Arg, count, Values...>;
	};


	struct skip
	{
		using kind					= module;

		using rtn					= skip;
	};
};

