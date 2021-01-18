/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	Only a "least common multiple" signature is defined in the following.
*/

	template<bool True, typename Filler = filler>
	struct pattern_match_recurse
	{
		using rtn = pattern_match_recurse;

	// builtin:

		template
		<
			typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,

			typename Antecedent,

			typename Consequent, typename Op_Cond, size_type count, typename List0, typename List1,

				Type... Values

		> using builtin_conditional = Antecedent;

	// typename:

		template
		<
			template<typename...> class ListKind, template<typename...> class ListType,

			typename Antecedent,

			typename Consequent, typename Op_Cond, typename Side, size_type count, typename List0, typename List1,

				typename... Values

		> using typename_conditional = Antecedent;
	};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

	template<typename Filler>
	struct pattern_match_recurse<false, Filler>
	{
		using rtn = pattern_match_recurse;

	// builtin:

		template
		<
			typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,

			typename Antecedent,

			typename Consequent, typename Op_Cond, typename Side, size_type count, typename List0, typename List1,

				Type... Values

		> using builtin_conditional = typename Consequent::template result
		<
			Kind, ListKind, Type, ListType, Op_Cond, Side, count, List0, List1, Values...
		>;

	// typename:

		template
		<
			template<typename...> class ListKind, template<typename...> class ListType,

			typename Antecedent,

			typename Consequent, typename Op_Cond, typename Side, size_type count, typename List0, typename List1,

				typename... Values

		> using typename_conditional = typename Consequent::template result
		<
			ListKind, ListType, Op_Cond, Side, count, List0, List1, Values...
		>;
	};
};

