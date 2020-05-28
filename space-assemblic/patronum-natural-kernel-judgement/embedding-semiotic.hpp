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

struct embedding
{
	#include nik_symbolic_typedef(patronum, kernel, judgement, inductor)

	template<template<typename Kind, Kind> class Judgement, typename Type, Type Value>
	using judgement_make = typename ch_judgement::template result
	<
		Judgement, Type, Value
	>;

	template<typename Judgement, typename Continuation = ch_judgement_type>
	using judgement_type = typename memoized_judgement<Judgement>::template type_induct
	<
		Continuation
	>;

	template<typename Memoized_Value, typename Continuation = ch_value>
	static constexpr type<Memoized_Value> value = Memoized_Value::template induct
	<
		Continuation
	>;
};

