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

struct inductor
{
	#include nik_symbolic_typedef(patronum, kernel, builtin, alias)

	template<typename, typename = filler>
	struct memoized_curried_pair
	{
		template<typename Continuation, typename Inductor = typename PK_Builtin_SS::inductor>
		using match = typename Continuation::template result<Inductor, bool, false>;
	};

	template<typename Memoized_Type>
	struct memoized_curried_pair<Memoized_Type, sfinae_try<Memoized_Type::template dependent_induct>>
	{
		template<typename Continuation, typename Judgement = builtin_inductor<bool>>
		using match = typename Continuation::template result<Judgement, bool, true>;

		template<typename Continuation, typename Inductor = typename PK_Builtin_SS::inductor>
		using induct = typename Memoized_Type::template dependent_induct<Continuation, Inductor>;
	};

	template<typename, typename = filler>
	struct memoized_pair
	{
		template<typename Continuation, typename Inductor = typename PK_Builtin_SS::inductor>
		using match = typename Continuation::template result<Inductor, bool, false>;
	};

	template<template<typename, typename> class Pair, typename Type_A, typename Type_B>
	struct memoized_pair<Pair<Type_A, Type_B>>
	{
		template<typename Continuation, typename Inductor = typename PK_Builtin_SS::inductor>
		using match = typename Continuation::template result<Inductor, bool, true>;

		template<typename Continuation, typename Inductor = typename PK_Builtin_SS::inductor>
		using induct = typename Continuation::template result<Inductor, Type_A, Type_B>;
	};
};

