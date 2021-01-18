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

struct model
{
	#include nik_lens_typedef(symbolic, perspective, functor, structure)

	// kind:

	template<typename Symbol, typename Continuation = ch_symbol_to_kind>
	using kind = typename memoized_symbol<universe, Symbol>::template induct
	<
		Continuation
	>;

	// type:

	template<typename Symbol, typename Continuation = ch_symbol_to_type>
	using type = typename memoized_symbol<auto, Symbol>::template induct
	<
		Continuation
	>;

	// value:

	template<typename Type, typename Symbol, typename Continuation = ch_symbol_to_value>
	static constexpr Type value = memoized_symbol<Type, Symbol>::template induct
	<
		Continuation
	>;

	// auto_value:

	template<typename Symbol, typename Continuation = ch_symbol_to_value>
	static constexpr auto auto_value = value<type<Symbol>, Symbol, Continuation>;
};

