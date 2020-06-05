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

struct identity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// is_equal:

		// symbolic:

		template<typename Type1, typename Type2, typename Continuation = ch_symbolic_values>
		using s_is_equal = typename dependent_memoization<Type1>::template pattern_match_types<Type2>::template
		symbolic_match
		<
			Continuation
		>;

		// assemblic:

		template<typename Type1, typename Type2, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_equal = dependent_memoization<Type1>::template pattern_match_types<Type2>::template
		assemblic_match
		<
			Continuation
		>;
};
