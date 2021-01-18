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

/*
	Within a completely formal implementation, a "dual" function or grammar point would be declared and defined here.

		dual : ( A | (B-->C) x B )	:=	transit		for function object input,
							reflex		otherwise.

	This function would not only be useful in defining "eval", it is also needed here for tail recursion.

		tail_if = dual . if
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, calculus, recurse, structure)

/***********************************************************************************************************************/

/*
	builtin:
*/

	// echo:

	template
	<
		typename Type,

		bool Pred,

		typename Antecedent,

		typename Consequent, Type Value

	> using echo_if_then_else = typename pattern_match_recurse<Pred>::template echo
	<
		Type,
		Antecedent,
		Consequent, Value
	>;

	template
	<
		typename Type,

		bool Pred,

		typename Consequent, Type Value

	> using echo_if_then = typename pattern_match_recurse<!Pred>::template echo
	<
		Type,
		filler,
		Consequent, Value
	>;

	// list:

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, Type... Values

	> using builtin_list_if_then_else = typename pattern_match_recurse<Pred>::template builtin_list
	<
		Type, ListType,
		Antecedent,
		Consequent, Values...
	>;

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Consequent, Type... Values

	> using builtin_list_if_then = typename pattern_match_recurse<!Pred>::template builtin_list
	<
		Type, ListType,
		filler,
		Consequent, Values...
	>;

	// grow:

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename List, Type... Values

	> using builtin_grow_if_then_else = typename pattern_match_recurse<Pred>::template builtin_grow
	<
		Type, ListType,
		Antecedent,
		Consequent, List, Values...
	>;

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Consequent, typename List, Type... Values

	> using builtin_grow_if_then = typename pattern_match_recurse<!Pred>::template builtin_grow
	<
		Type, ListType,
		filler,
		Consequent, List, Values...
	>;

	// mutate:

	template
	<
		typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op, typename List, Type... Values

	> using builtin_mutate_if_then_else = typename pattern_match_recurse<Pred>::template builtin_mutate
	<
		Kind, ListKind, Type, ListType,
		Antecedent,
		Consequent, Op, List, Values...
	>;

	template
	<
		typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,

		bool Pred,

		typename Consequent, typename Op, typename List, Type... Values

	> using builtin_mutate_if_then = typename pattern_match_recurse<!Pred>::template builtin_mutate
	<
		Kind, ListKind, Type, ListType,
		filler,
		Consequent, Op, List, Values...
	>;

	// shrink:

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op_Cond, size_type count, typename List, Type... Values

	> using builtin_shrink_if_then_else = typename pattern_match_recurse<Pred>::template builtin_shrink
	<
		Type, ListType,
		Antecedent,
		Consequent, Op_Cond, count, List, Values...
	>;

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Consequent, typename Op_Cond, size_type count, typename List, Type... Values

	> using builtin_shrink_if_then = typename pattern_match_recurse<!Pred>::template builtin_shrink
	<
		Type, ListType,
		filler,
		Consequent, Op_Cond, count, List, Values...
	>;

	// split:

	template
	<
		typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op_Cond, typename Side, size_type count, typename List0, typename List1,

			Type... Values

	> using builtin_split_if_then_else = typename pattern_match_recurse<Pred>::template builtin_split
	<
		Kind, ListKind, Type, ListType,
		Antecedent,
		Consequent, Op_Cond, Side, count, List0, List1, Values...
	>;

	template
	<
		typename Kind, template<Kind...> class ListKind, typename Type, template<Type...> class ListType,

		bool Pred,

		typename Consequent, typename Op_Cond, typename Side, size_type count, typename List0, typename List1,

			Type... Values

	> using builtin_split_if_then = typename pattern_match_recurse<!Pred>::template builtin_split
	<
		Kind, ListKind, Type, ListType,
		filler,
		Consequent, Op_Cond, Side, count, List0, List1, Values...
	>;

/***********************************************************************************************************************/

/*
	typename:
*/

	// ping:

	template
	<
		bool Pred,

		typename Antecedent,

		typename Consequent, typename Value

	> using ping_if_then_else = typename pattern_match_recurse<Pred>::template ping
	<
		Antecedent,
		Consequent, Value
	>;

	template
	<
		bool Pred,

		typename Consequent, typename Value

	> using ping_if_then = typename pattern_match_recurse<!Pred>::template ping
	<
		filler,
		Consequent, Value
	>;

	// list:

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename... Values

	> using typename_list_if_then_else = typename pattern_match_recurse<Pred>::template typename_list
	<
		ListType,
		Antecedent,
		Consequent, Values...
	>;

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Consequent, typename... Values

	> using typename_list_if_then = typename pattern_match_recurse<!Pred>::template typename_list
	<
		ListType,
		filler,
		Consequent, Values...
	>;

	// grow:

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename List, typename... Values

	> using typename_grow_if_then_else = typename pattern_match_recurse<Pred>::template typename_grow
	<
		ListType,
		Antecedent,
		Consequent, List, Values...
	>;

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Consequent, typename List, typename... Values

	> using typename_grow_if_then = typename pattern_match_recurse<!Pred>::template typename_grow
	<
		ListType,
		filler,
		Consequent, List, Values...
	>;

	// mutate:

	template
	<
		template<typename...> class ListKind, template<typename...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op, typename List, typename... Values

	> using typename_mutate_if_then_else = typename pattern_match_recurse<Pred>::template typename_mutate
	<
		ListKind, ListType,
		Antecedent,
		Consequent, Op, List, Values...
	>;

	template
	<
		template<typename...> class ListKind, template<typename...> class ListType,

		bool Pred,

		typename Consequent, typename Op, typename List, typename... Values

	> using typename_mutate_if_then = typename pattern_match_recurse<!Pred>::template typename_mutate
	<
		ListKind, ListType,
		filler,
		Consequent, Op, List, Values...
	>;

	// shrink:

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op_Cond, size_type count, typename List, typename... Values

	> using typename_shrink_if_then_else = typename pattern_match_recurse<Pred>::template typename_shrink
	<
		ListType,
		Antecedent,
		Consequent, Op_Cond, count, List, Values...
	>;

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Consequent, typename Op_Cond, size_type count, typename List, typename... Values

	> using typename_shrink_if_then = typename pattern_match_recurse<!Pred>::template typename_shrink
	<
		ListType,
		filler,
		Consequent, Op_Cond, count, List, Values...
	>;

	// split:

	template
	<
		template<typename...> class ListKind, template<typename...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op_Cond, typename Side, size_type count, typename List0, typename List1,

			typename... Values

	> using typename_split_if_then_else = typename pattern_match_recurse<Pred>::template typename_split
	<
		ListKind, ListType,
		Antecedent,
		Consequent, Op_Cond, Side, count, List0, List1, Values...
	>;

	template
	<
		template<typename...> class ListKind, template<typename...> class ListType,

		bool Pred,

		typename Consequent, typename Op_Cond, typename Side, size_type count, typename List0, typename List1,

			typename... Values

	> using typename_split_if_then = typename pattern_match_recurse<!Pred>::template typename_split
	<
		ListKind, ListType,
		filler,
		Consequent, Op_Cond, Side, count, List0, List1, Values...
	>;
};

/*
	Combinatorial acknowledgement:
*/

