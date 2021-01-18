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

struct identity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// :

		// symbolic:

		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_typename_stem = typename pattern_match_typename_stem_<Type, Exp>::template
		s_match_induct
		<
			Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Type, typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_typename_stem = pattern_match_typename_stem_<Type, Exp>::template
		a_match_induct
		<
			Continuation, Image
		>;
};
