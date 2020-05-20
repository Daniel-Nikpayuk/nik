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
	template<typename>
	struct memoized_judgement
	{
		template<typename Continuation, template<typename Kind, Kind> class Judgement>
		using match = typename Continuation::template result<Judgement, bool, false>;
	};

	template<typename Type, template<typename Kind, Kind> class Judgement, Type Value>
	struct memoized_judgement<Judgement<Type, Value>>
	{
		template<typename Continuation, template<typename Kind, Kind> class Saying>
		using match = typename Continuation::template result<Saying, bool, true>;

		template<typename Continuation>
		using type_induct = typename Continuation::template result
		<
			Judgement, Type, Value
		>;

		template<typename Continuation>
		static constexpr Type value_induct = Continuation::template result
		<
			Judgement, Type, Value
		>;
	};

	//

	struct ch_judgement
	{
		template<template<typename Kind, Kind> class Judgement, typename Type, Type Value>
		using result = Judgement<Type, Value>;
	};
};

