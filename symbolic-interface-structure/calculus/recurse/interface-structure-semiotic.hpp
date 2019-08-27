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
	using kind		= module;

	using rtn		= structure;

/*
	pattern_match_recurse:

	For whatever reason, if the pattern

		template<...> class

	follows other template parameters it creates an internal compiler error.
	As such I have made the habit of refactoring it to the beginning.
	Unfortunately this makes the grammar more awkward than is preferred.
*/

	template<bool True, typename Filler = filler>
	struct pattern_match_recurse
	{
		using rtn = pattern_match_recurse;

/*
	builtin:
*/

		// echo:

		template
		<
			typename Type,

			typename Antecedent,

			typename Consequent, Type Value

		> using echo = Antecedent;

		// list:

		template
		<
			typename Type, template<Type...> class ListType,

			typename Antecedent,

			typename Consequent, Type... Values

		> using builtin_list = Antecedent;

		// grow:

		template
		<
			typename Type, template<Type...> class ListType,

			typename Antecedent,

			typename Consequent, typename List, size_type count, Type... Values

		> using builtin_push = Antecedent;

		// mutate:

		template
		<
			typename Kind, template<Kind...> class ListKind,

			typename Antecedent,

			typename Consequent, typename Type, typename Op, typename List, size_type count, Type... Values

		> using builtin_map = Antecedent;

		// shrink:

		template
		<
			typename Type, template<Type...> class ListType,

			typename Antecedent,

			typename Consequent, typename Op, typename Cond, size_type count, Type... Values

		> using builtin_fold = Antecedent;

/***********************************************************************************************************************/

/*
	typename:
*/

		// ping:

		template
		<
			typename Antecedent,

			typename Consequent, typename Value

		> using ping = Antecedent;

		// list:

		template
		<
			template<typename...> class ListType,

			typename Antecedent,

			typename Consequent, typename... Values

		> using typename_list = Antecedent;

		// grow:

		template
		<
			template<typename...> class ListType,

			typename Antecedent,

			typename Consequent, typename List, size_type count, typename... Values

		> using typename_push = Antecedent;

		// mutate:

		template
		<
			template<typename...> class ListKind,

			typename Antecedent,

			typename Consequent, typename Op, typename List, size_type count, typename... Values

		> using typename_map = Antecedent;

		// shrink:

		template
		<
			template<typename...> class ListType,

			typename Antecedent,

			typename Consequent, typename Op, typename Cond, size_type count, typename... Values

		> using typename_fold = Antecedent;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename Filler>
	struct pattern_match_recurse<false, Filler>
	{
		using rtn = pattern_match_recurse;

		// echo:

		template
		<
			typename Type,

			typename Antecedent,

			typename Consequent, Type Value

		> using echo = typename Consequent::template result<Type, Value>;

		// list:

		template
		<
			typename Type, template<Type...> class ListType,

			typename Antecedent,

			typename Consequent, Type... Values

		> using builtin_list = typename Consequent::template result<Type, ListType, Values...>;

		// grow:

		template
		<
			typename Type, template<Type...> class ListType,

			typename Antecedent,

			typename Consequent, typename List, size_type count, Type... Values

		> using builtin_push = typename Consequent::template result<Type, ListType, List, count, Values...>;

		// mutate:

		template
		<
			typename Kind, template<Kind...> class ListKind,

			typename Antecedent,

			typename Consequent, typename Type, typename Op, typename List, size_type count, Type... Values

		> using builtin_map = typename Consequent::template result<Kind, ListKind, Type, Op, List, count, Values...>;

		// shrink:

		template
		<
			typename Type, template<Type...> class ListType,

			typename Antecedent,

			typename Consequent, typename Op, typename Cond, size_type count, Type... Values

		> using builtin_fold = typename Consequent::template result<Type, ListType, Op, Cond, count, Values...>;

/***********************************************************************************************************************/

/*
	typename:
*/

		// ping:

		template
		<
			typename Antecedent,

			typename Consequent, typename Value

		> using ping = typename Consequent::template result<Value>;

		// list:

		template
		<
			template<typename...> class ListType,

			typename Antecedent,

			typename Consequent, typename... Values

		> using typename_list = typename Consequent::template result<ListType, Values...>;

		// grow:

		template
		<
			template<typename...> class ListType,

			typename Antecedent,

			typename Consequent, typename List, size_type count, typename... Values

		> using typename_push = typename Consequent::template result<ListType, List, count, Values...>;

		// mutate:

		template
		<
			template<typename...> class ListKind,

			typename Antecedent,

			typename Consequent, typename Op, typename List, size_type count, typename... Values

		> using typename_map = typename Consequent::template result<ListKind, Op, List, count, Values...>;

		// shrink:

		template
		<
			template<typename...> class ListType,

			typename Antecedent,

			typename Consequent, typename Op, typename Cond, size_type count, typename... Values

		> using typename_fold = typename Consequent::template result<ListType, Op, Cond, count, Values...>;
	};
};

