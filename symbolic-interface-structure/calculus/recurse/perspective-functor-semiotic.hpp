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
	head_if_then_else:
*/

	template<bool Pred, template<typename> class Ante, typename Value, typename Conse>
	using head_if_then_else = typename pattern_match_recurse<Pred>::template transit_reflex_conditional
	<
		Ante, Value,

		Conse
	>;

/*
	tail_if_then_else:
*/

	template<bool Pred, typename Ante, template<typename, typename...> class Conse, typename Value, typename... Values>
	using tail_if_then_else = typename pattern_match_recurse<Pred>::template reflex_transit_conditional
	<
		Ante,

		Conse, Value, Values...
	>;

/*
	handle_if_then_else:
*/

	template<bool Pred, template<typename> class Ante, typename Ante_Value,
		template<typename, typename...> class Conse, typename Value, typename... Values>
	using handle_if_then_else = typename pattern_match_recurse<Pred>::template transit_transit_conditional
	<
		Ante, Ante_Value,

		Conse, Value, Values...
	>;

/*
	builtin_break_fold_if_then_else:
*/

	template
	<
		typename Type,

		bool Pred,

		typename Ante_Continuation, Type Value,

		typename Conse_Continuation, typename Cond, typename Op, size_type count,

		Type... Values
	>
	using builtin_break_fold_if_then_else = typename pattern_match_recurse<Pred>::template builtin_break_fold_conditional
	<
		Type,

		Ante_Continuation, Value,

		Conse_Continuation, Cond, Op, count,

		Values...
	>;

/*
	typename_break_fold_if_then_else:
*/

	template
	<
		bool Pred,

		typename Value,

		typename Conse_Continuation, template<typename> class Cond, template<typename, typename> class Op, size_type count,

		typename... Values
	>
	using typename_break_fold_if_then_else = typename pattern_match_recurse<Pred>::template typename_break_fold_conditional
	<
		Value,

		Conse_Continuation, Cond, Op, count,

		Values...
	>;

/*
	builtin_find_if_then_else:
*/

	template
	<
		typename Type, template<Type...> class ListType,

		bool Pred,

		typename Ante_Continuation, Type Value,

		typename Conse_Continuation, typename Cond, size_type count,

		Type... Values
	>
	using builtin_find_if_then_else = typename pattern_match_recurse<Pred>::template builtin_find_conditional
	<
		Type, ListType,

		Ante_Continuation, Value,

		Conse_Continuation, Cond, count,

		Values...
	>;

/*
	typename_find_if_then_else:
*/

	template
	<
		template<typename...> class ListType,

		bool Pred,

		typename Ante_Continuation, typename Value,

		typename Conse_Continuation, template<typename> class Cond, size_type count,

		typename... Values
	>
	using typename_find_if_then_else = typename pattern_match_recurse<Pred>::template typename_find_conditional
	<
		ListType,

		Ante_Continuation, Value,

		Conse_Continuation, Cond, count,

		Values...
	>;
};

/*
	Combinatorial acknowledgement:

	echo_echo_if_then_else		echo_ping_if_then_else		ping_echo_if_then_else		ping_ping_if_then_else
	echo_pose_if_then_else		echo_moiz_if_then_else		ping_pose_if_then_else		ping_moiz_if_then_else
	echo_turn_if_then_else		echo_call_if_then_else		ping_turn_if_then_else		ping_call_if_then_else

	pose_echo_if_then_else		pose_ping_if_then_else		moiz_echo_if_then_else		moiz_ping_if_then_else
	pose_pose_if_then_else		pose_moiz_if_then_else		moiz_pose_if_then_else		moiz_moiz_if_then_else
	pose_turn_if_then_else		pose_call_if_then_else		moiz_turn_if_then_else		moiz_call_if_then_else

	turn_echo_if_then_else		turn_ping_if_then_else		call_echo_if_then_else		call_ping_if_then_else
	turn_pose_if_then_else		turn_moiz_if_then_else		call_pose_if_then_else		call_moiz_if_then_else
	turn_turn_if_then_else		turn_call_if_then_else		call_turn_if_then_else		call_call_if_then_else
*/

