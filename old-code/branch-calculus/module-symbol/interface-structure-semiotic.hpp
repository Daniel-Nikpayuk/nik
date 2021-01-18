/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct structure
{
	template<typename, typename>
	struct memoized_symbol
	{
		template<typename Continuation>
		using match = typename Continuation::template result<false>;
	};

	template<template<typename> class symbol, typename Kind>
	struct memoized_symbol<universe, symbol<Kind>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		template<typename Continuation>
		using induct = typename Continuation::template result<universe, symbol, Kind>;
	};

	template<typename Type, template<Type> class symbol, Type Value>
	struct memoized_symbol<Type, symbol<Value>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		template<typename Continuation>
		static constexpr auto induct = Continuation::template result<Type, symbol, Value>;
	};

	template<typename Type, template<Type> class symbol, Type Value>
	struct memoized_symbol<auto, symbol<Value>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		template<typename Continuation>
		using induct = typename Continuation::template result<Type, symbol, Value>;
	};

	//

	struct ch_universe_symbol_to_type
	{
		template<typename Type, template<Type> class symbol, Type Value>
		using result = Type;
	};

	struct ch_builtin_symbol_to_type
	{
		template<typename Type, template<Type> class symbol, Type Value>
		using result = Type;
	};

	struct ch_builtin_symbol_to_value
	{
		template<typename Type, template<Type> class symbol, Type Value>
		static constexpr Type result = Value;
	};
};

