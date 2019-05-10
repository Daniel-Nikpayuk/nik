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
	Let A,B,C be Types, with f : B --> C, the compositional form is

		f_A : (A --> B) x A --> C

		    := f . transit_A,B

	This theorem says we can decompose the combinatorial possibilities
	into the grammatical forms with type input (builtin, typename) composed
	with the appropriate transit grammar (passed: moiz, pose; scoped: turn, call).

	moiz: (c, builtin)   --> typename
	pose: (c, builtin)   --> builtin
	turn: (f, typename)  --> builtin
	call: (f, typename)  --> typename

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

//	#include nik_typedef(symbolic, calculus, product, identity)

	// cons:

	struct echo_echo_cons
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = PairType<ValueX, ValueY>;
	};

	struct echo_ping_cons
	{
		template<typename TypeX, template<TypeX, typename> class PairType, TypeX ValueX, typename BuiltinY>
		using result = PairType<ValueX, BuiltinY>;
	};

	struct ping_echo_cons
	{
		template<typename TypeY, template<typename, TypeY> class PairType, typename BuiltinX, TypeY ValueY>
		using result = PairType<BuiltinX, ValueY>;
	};

	struct ping_ping_cons
	{
		template<template<typename, typename> class PairType, typename BuiltinX, typename BuiltinY>
		using result = PairType<BuiltinX, BuiltinY>;
	};

	// car:

	template<typename Continuation>
	struct builtin_builtin_car
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = typename Continuation::template result<TypeX, TypeY, PairType, ValueX>;
	};

	template<typename Continuation>
	struct builtin_typename_car
	{
		template<typename TypeX, template<TypeX, typename> class PairType, TypeX ValueX, typename TypenameY>
		using result = typename Continuation::template result<TypeX, TypeY, PairType, ValueX>;
	};

	template<typename Continuation>
	struct typename_builtin_car
	{
		template<typename TypeY, template<typename, TypeY> class PairType, typename TypenameX, TypeY ValueY>
		using result = typename Continuation::template result<TypeY, PairType, TypenameX>;
	};

	template<typename Continuation>
	struct typename_typename_car
	{
		template<template<typename, typename> class PairType, typename TypenameX, typename TypenameY>
		using result = typename Continuation::template result<PairType, TypenameX>;
	};

	// cdr:

	template<typename Continuation>
	struct ping_builtin_builtin_cdr
	{
		template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
		using result = typename Continuation::template result<TypeX, TypeY, PairType, ValueX>;
	};

		template<typename Continuation>
		struct ping_builtin_typename_cdr
		{
			template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
			using result = typename Continuation::template result<TypeX, TypeY, PairType, ValueX>;
		};

		template<typename Continuation>
		struct ping_typename_builtin_cdr
		{
			template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
			using result = typename Continuation::template result<TypeX, TypeY, PairType, ValueX>;
		};

		template<typename Continuation>
		struct ping_typename_typename_cdr
		{
			template<typename TypeX, typename TypeY, template<TypeX, TypeY> class PairType, TypeX ValueX, TypeY ValueY>
			using result = typename Continuation::template result<TypeX, TypeY, PairType, ValueX>;
		};
};

