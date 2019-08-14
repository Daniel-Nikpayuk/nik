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
	This branch is the (near) untyped calculus. The only "types" are distinct grammatical
	forms, so "copair" in this context is only relevant if the input takes distinct
	grammatical forms.
*/

/*
	Is this worth declaring?

	Copairs are only intended for when the grammatical forms differ, but in the case of the two projections
	it's the same.

	template<typename TypeX, typename TypeY, typename Copair, typename Pair>
	using builtin_builtin_cpr = typename memoized_builtin_builtin_pair<TypeX, TypeY, Pair>::template pop
	<
		typename_copair_cdr<Copair>
	>;
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

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, kernel, core, functor)

	#include nik_typedef(symbolic, calculus, product, structure)
	#include nik_typedef(symbolic, calculus, product, functor)

/*
	echo_left_inject:
*/

	struct cp_echo_left_inject
	{
		template<typename Type, template<bool, Type> class CopairType, Type Value>
		using result = CopairType<false, Value>;
	};

/*
	ping_left_inject:
*/

	struct cp_ping_left_inject
	{
		template<template<bool, typename> class CopairType, typename Value>
		using result = CopairType<false, Value>;
	};

/*
	echo_right_inject:
*/

	struct cp_echo_right_inject
	{
		template<typename Type, template<bool, Type> class CopairType, Type Value>
		using result = CopairType<true, Value>;
	};

/*
	ping_right_inject:
*/

	struct cp_ping_right_inject
	{
		template<template<bool, typename> class CopairType, typename Value>
		using result = CopairType<true, Value>;
	};

/*
	builtin_copair_car:
*/

	template<typename Type, typename Copair, typename Continuation = cp_moiz>
	using builtin_copair_car = builtin_builtin_car<bool, Type, Copair, Continuation>;

/*
	typename_copair_car:
*/

	template<typename Copair>
	using typename_copair_car = builtin_typename_car<bool, Copair>;

/*
	builtin_copair_cdr:
*/

	template<typename Type, typename Copair, typename Continuation = cp_moiz>
	using builtin_copair_cdr = builtin_builtin_cdr<bool, Type, Copair, Continuation>;

/*
	typename_copair_cdr:
*/

	template<typename Copair>
	using typename_copair_cdr = builtin_typename_cdr<bool, Copair>;

/*
	builtin_builtin_cpr:

	Continuations are necessarily embedded into the Projection.
*/

	template<typename TypeX, typename TypeY, typename Projection, typename Pair>
	using builtin_builtin_cpr = typename memoized_builtin_builtin_pair<TypeX, TypeY, Pair>::template pop
	<
		Projection
	>;

/*
	builtin_typename_cpr:

	Continuations are necessarily embedded into the Projection.
*/

	template<typename TypeX, typename Projection, typename Pair>
	using builtin_typename_cpr = typename memoized_builtin_typename_pair<TypeX, Pair>::template pop
	<
		Projection
	>;

/*
	typename_builtin_cpr:

	Continuations are necessarily embedded into the Projection.
*/

	template<typename TypeY, typename Projection, typename Pair>
	using typename_builtin_cpr = typename memoized_typename_builtin_pair<TypeY, Pair>::template pop
	<
		Projection
	>;

/*
	typename_typename_cpr:

	Continuations are necessarily embedded into the Projection.
*/

	template<typename Projection, typename Pair>
	using typename_typename_cpr = typename memoized_typename_typename_pair<Pair>::template pop
	<
		Projection
	>;
};

