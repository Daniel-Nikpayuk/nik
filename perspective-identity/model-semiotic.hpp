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

struct model
{
	#include nik_library_typedef(perspective, identity, structure)

	#include nik_library_typedef(perspective, identity, functor)

	// division_is_implemented:

	template<typename Division, typename Continuation = ch_bool>
	static constexpr bool division_is_implemented = Division::template result
	<
		Continuation
	>;

	// module_is_implemented:

	template<typename Module, typename Continuation = ch_bool>
	static constexpr bool module_is_implemented = Module::template result
	<
		Continuation
	>;

	// equal:

	template<typename Kind1, typename Kind2, typename Continuation = ch_bool>
	static constexpr bool equal = cs_equal<Kind1, Kind2>::template result
	<
		Continuation
	>;

	// not_equal:

	template<typename Kind1, typename Kind2, typename Continuation = ch_bool>
	static constexpr bool not_equal = cs_equal<Kind1, Kind2>::template result
	<
		cp_negate<Continuation>
	>;

	// is_global_size_type:

	template<typename Kind, typename Continuation = ch_bool>
	static constexpr bool is_global_size_type = cs_equal<Kind, global_size_type>::template result
	<
		Continuation
	>;

	// is_voidptr:

	template<typename Kind, typename Continuation = ch_bool>
	static constexpr bool is_voidptr = cs_equal<Kind, voidptr>::template result
	<
		Continuation
	>;

	// is_global_filler:

	template<typename Kind, typename Continuation = ch_bool>
	static constexpr bool is_global_filler = cs_equal<Kind, global_filler>::template result
	<
		Continuation
	>;

	// is_filler:

	template<typename Kind, typename Continuation = ch_bool>
	static constexpr bool is_filler = cs_equal<Kind, filler>::template result
	<
		Continuation
	>;
};

