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
	Create a grammatical compose operator, to shortform f . transit.
*/

/*
	Combinatorial acknowledgement:

	echo_echo_cons			echo_ping_cons			ping_echo_cons			ping_ping_cons
	echo_pose_cons			echo_moiz_cons			ping_pose_cons			ping_moiz_cons
	echo_turn_cons			echo_call_cons			ping_turn_cons			ping_call_cons

	pose_echo_cons			pose_ping_cons			moiz_echo_cons			moiz_ping_cons
	pose_pose_cons			pose_moiz_cons			moiz_pose_cons			moiz_moiz_cons
	pose_turn_cons			pose_call_cons			moiz_turn_cons			moiz_call_cons

	turn_echo_cons			turn_ping_cons			call_echo_cons			call_ping_cons
	turn_pose_cons			turn_moiz_cons			call_pose_cons			call_moiz_cons
	turn_turn_cons			turn_call_cons			call_turn_cons			call_call_cons
*/

/*
	The main intention in defining these functions are for grammatical
	formalization, though some of them will be used regularly in practice.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, kernel, core, structure)

/*
	echo:
*/

	struct echo
	{
		template<typename Type>
		static constexpr Type value(const Type Value)
		{
			return Value;
		}
	};

/*
	ping:
*/

	template<typename Type>
	using ping = Type;

/*
	moiz:
*/

	struct cp_moiz
	{
		template<typename Type, Type Value>
		using result = memoized_value<Type, Value>;
	};

/*
	pose:

	Continuation passing grammar is secondary here, and is not part of the grammatical formalization.
*/

	template<typename Op, typename Return, typename Type, Type Value, typename Continuation = cp_moiz>
	using pose = typename Continuation::template result<Return, Op::value(Value)>;

/*
	turn:

	Continuation passing grammar is secondary here, and is not part of the grammatical formalization.
*/

	template<typename Type, typename Struct, typename Continuation = cp_moiz>
	using turn = typename Continuation::template result<Type, Struct::value>;

/*
	call:
*/

	template<typename Dual>
	using call = typename Dual::rtn;

/*
	dereference:
*/

	template<typename Type>
	using dereference = typename memoized_pointer<Type>::template pop
	<
		ping
	>;
};

