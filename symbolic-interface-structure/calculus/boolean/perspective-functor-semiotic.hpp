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
	Narratively speaking, "conditional" is built from "cpr", but given its frequency of use
	it is optimized here.
*/

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

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, kernel, core, functor)

	#include nik_typedef(symbolic, calculus, conditional, structure)

/*
	echo:

	better to use (Pred ? Ante : Conse) grammar directly.
*/

	struct echo_if_then_else
	{
		template<typename Type>
		static constexpr Type value(bool Pred, Type Ante, Type Conse)
		{
			return (Pred ? Ante : Conse);
		}
	};

/*
	ping:
*/

	template<bool Pred, typename Ante, typename Conse>
	using ping_if_then_else = typename memoized_conditional<Pred>::template reflex
	<
		Ante, Conse
	>;

/*
	call:
*/

	template<bool Pred, typename Ante, typename Conse>
	using call_if_then_else = call
	<
		ping_if_then_else<Pred, Ante, Conse>
	>;

	template<bool Pred, typename Ante, typename Conse>
	using head_if_then_else = typename memoized_conditional<Pred>::template left_transit
	<
		call, Ante,
		Conse
	>;

	template<bool Pred, typename Ante, typename Conse>
	using tail_if_then_else = typename memoized_conditional<Pred>::template right_transit
	<
		Ante,
		call, Conse
	>;
};

