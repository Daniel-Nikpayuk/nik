/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, core, kernel, functor)

	#include nik_typedef(symbolic, calculus, pair, structure)

/*
	cons:
*/

	struct ch_builtin_builtin_cons
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = PairType<ValueX, ValueY>;
	};

	struct ch_builtin_typename_cons
	{
		template<typename TypeX, template<TypeX, typename> class PairType, TypeX ValueX, typename BuiltinY>
		using result = PairType<ValueX, BuiltinY>;
	};

	struct ch_typename_builtin_cons
	{
		template<typename TypeY, template<typename, TypeY> class PairType, typename BuiltinX, TypeY ValueY>
		using result = PairType<BuiltinX, ValueY>;
	};

	struct ch_typename_typename_cons
	{
		template<template<typename, typename> class PairType, typename BuiltinX, typename BuiltinY>
		using result = PairType<BuiltinX, BuiltinY>;
	};

/*
	template<template<typename, typename> class PairType, >
	using builtin_builtin_car = typename pattern_match_builtin_builtin_pair<Pair>::template pop
	<
		cp_builtin_builtin_car<Continuation>
	>;
*/

/*
	car:
*/

	template<typename Continuation>
	struct cp_builtin_builtin_car
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = typename Continuation::template result<TypeX, ValueX>;
	};

	template<typename Pair, typename Continuation = ch_echo>
	using builtin_builtin_car = typename pattern_match_builtin_builtin_pair<Pair>::template pop
	<
		cp_builtin_builtin_car<Continuation>
	>;

	//

	template<typename Continuation>
	struct cp_builtin_typename_car
	{
		template<typename TypeX, template<TypeX, typename> class PairType, TypeX ValueX, typename TypenameY>
		using result = typename Continuation::template result<TypeX, ValueX>;
	};

	template<typename Pair, typename Continuation = ch_echo>
	using builtin_typename_car = typename pattern_match_builtin_typename_pair<Pair>::template pop
	<
		cp_builtin_typename_car<Continuation>
	>;

	//

	struct ch_typename_builtin_car
	{
		template<typename TypeY, template<typename, TypeY> class PairType, typename TypenameX, TypeY ValueY>
		using result = TypenameX;
	};

	template<typename Pair>
	using typename_builtin_car = typename pattern_match_typename_builtin_pair<Pair>::template pop
	<
		ch_typename_builtin_car
	>;

	//

	struct ch_typename_typename_car
	{
		template<template<typename, typename> class PairType, typename TypenameX, typename TypenameY>
		using result = TypenameX;
	};

	template<typename Pair>
	using typename_typename_car = typename pattern_match_typename_typename_pair<Pair>::template pop
	<
		ch_typename_typename_car
	>;

/*
	cdr:
*/

	template<typename Continuation>
	struct cp_builtin_builtin_cdr
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = typename Continuation::template result<TypeY, ValueY>;
	};

	template<typename Pair, typename Continuation = ch_echo>
	using builtin_builtin_cdr = typename pattern_match_builtin_builtin_pair<Pair>::template pop
	<
		cp_builtin_builtin_cdr<Continuation>
	>;

	struct ch_builtin_typename_cdr
	{
		template<typename TypeX, template<TypeX, typename> class PairType, TypeX ValueX, typename TypenameY>
		using result = TypenameY;
	};

	template<typename Pair>
	using builtin_typename_cdr = typename pattern_match_builtin_typename_pair<Pair>::template pop
	<
		ch_builtin_typename_cdr
	>;

	template<typename Continuation>
	struct cp_typename_builtin_cdr
	{
		template<typename TypeY, template<typename, TypeY> class PairType, typename TypenameX, TypeY ValueY>
		using result = typename Continuation::template result<TypeY, ValueY>;
	};

	template<typename Pair, typename Continuation = ch_echo>
	using typename_builtin_cdr = typename pattern_match_typename_builtin_pair<Pair>::template pop
	<
		cp_typename_builtin_cdr<Continuation>
	>;

	struct ch_typename_typename_cdr
	{
		template<template<typename, typename> class PairType, typename TypenameX, typename TypenameY>
		using result = TypenameY;
	};

	template<typename Pair>
	using typename_typename_cdr = typename pattern_match_typename_typename_pair<Pair>::template pop
	<
		ch_typename_typename_cdr
	>;

/*
	left_type:
*/

	struct ch_builtin_builtin_left_type
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = TypeX;
	};

	template<typename Pair>
	using builtin_builtin_left_type = typename pattern_match_builtin_builtin_pair<Pair>::template pop
	<
		ch_builtin_builtin_left_type
	>;

	//

	struct ch_builtin_typename_left_type
	{
		template<typename TypeX, template<TypeX, typename> class PairType, TypeX ValueX, typename BuiltinY>
		using result = TypeX;
	};

	template<typename Pair>
	using builtin_typename_left_type = typename pattern_match_builtin_typename_pair<Pair>::template pop
	<
		ch_builtin_typename_left_type
	>;

/*
	right_type:
*/

	struct ch_builtin_builtin_right_type
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = TypeY;
	};

	template<typename Pair>
	using builtin_builtin_right_type = typename pattern_match_builtin_builtin_pair<Pair>::template pop
	<
		ch_builtin_builtin_right_type
	>;

	//

	struct ch_typename_builtin_right_type
	{
		template<typename TypeY, template<typename, TypeY> class PairType, typename BuiltinX, TypeY ValueY>
		using result = TypeY;
	};

	template<typename Pair>
	using typename_builtin_right_type = typename pattern_match_typename_builtin_pair<Pair>::template pop
	<
		ch_typename_builtin_right_type
	>;
};

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

