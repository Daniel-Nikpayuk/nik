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
	Within a completely formal implementation, a "dual" function or grammar point would be declared and defined here.

		dual : ( A | (B-->C)xB )	:=	transit		for function object input,
							reflex		otherwise.

	This function would not only be useful in defining "eval", it is also needed here for tail recursion.

		tail_if = dual . if
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, calculus, recurse, structure)

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

		typename Consequent, typename List, size_type count, Type... Values

	> using builtin_push_if_then_else = typename pattern_match_recurse<Pred>::template builtin_push
	<
		Type, ListType,

		Antecedent,

		Consequent, List, count, Values...
	>;

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Consequent, typename List, size_type count, Type... Values

	> using builtin_push_if_then = typename pattern_match_recurse<!Pred>::template builtin_push
	<
		Type, ListType,

		filler,

		Consequent, List, count, Values...
	>;

	// mutate:

	template
	<
		typename Kind, template<Kind...> class ListKind,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Type, typename Op, typename List, size_type count, Type... Values

	> using builtin_map_if_then_else = typename pattern_match_recurse<Pred>::template builtin_map
	<
		Kind, ListKind,

		Antecedent,

		Consequent, Type, Op, List, count, Values...
	>;

	template
	<
		typename Kind, template<Kind...> class ListKind,

		bool Pred,

		typename Consequent, typename Type, typename Op, typename List, size_type count, Type... Values

	> using builtin_map_if_then = typename pattern_match_recurse<!Pred>::template builtin_map
	<
		Kind, ListKind,

		filler,

		Consequent, Type, Op, List, count, Values...
	>;

	// shrink:

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op, typename Cond, size_type count, Type... Values

	> using builtin_fold_if_then_else = typename pattern_match_recurse<Pred>::template builtin_fold
	<
		Type, ListType,

		Antecedent,

		Consequent, Op, Cond, count, Values...
	>;

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Consequent, typename Op, typename Cond, size_type count, Type... Values

	> using builtin_fold_if_then = typename pattern_match_recurse<!Pred>::template builtin_fold
	<
		Type, ListType,

		filler,

		Consequent, Op, Cond, count, Values...
	>;

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

		typename Consequent, typename List, size_type count, typename... Values

	> using typename_push_if_then_else = typename pattern_match_recurse<Pred>::template typename_push
	<
		ListType,

		Antecedent,

		Consequent, List, count, Values...
	>;

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Consequent, typename List, size_type count, typename... Values

	> using typename_push_if_then = typename pattern_match_recurse<!Pred>::template typename_push
	<
		ListType,

		filler,

		Consequent, List, count, Values...
	>;

	// mutate:

	template
	<
		template<typename...> class ListKind,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op, typename List, size_type count, typename... Values

	> using typename_map_if_then_else = typename pattern_match_recurse<Pred>::template typename_map
	<
		ListKind,

		Antecedent,

		Consequent, Op, List, count, Values...
	>;

	template
	<
		template<typename...> class ListKind,

		bool Pred,

		typename Consequent, typename Op, typename List, size_type count, typename... Values

	> using typename_map_if_then = typename pattern_match_recurse<!Pred>::template typename_map
	<
		ListKind,

		filler,

		Consequent, Op, List, count, Values...
	>;

	// shrink:

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Antecedent,

		typename Consequent, typename Op, typename Cond, size_type count, typename... Values

	> using typename_fold_if_then_else = typename pattern_match_recurse<Pred>::template typename_fold
	<
		ListType,

		Antecedent,

		Consequent, Op, Cond, count, Values...
	>;

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Consequent, typename Op, typename Cond, size_type count, typename... Values

	> using typename_fold_if_then = typename pattern_match_recurse<!Pred>::template typename_fold
	<
		ListType,

		filler,

		Consequent, Op, Cond, count, Values...
	>;
};

/*
	Combinatorial acknowledgement:
*/

