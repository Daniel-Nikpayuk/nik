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
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, identity)

	// is judgment:

		// symbolic:

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_is_unsigned_short_judgment = s_is_judgment
		<
			unsigned short, Exp, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_unsigned_short_judgment = a_is_judgment
		<
			unsigned short, Exp, Continuation, Image
		>;

	// is curried judgment:

		// symbolic:

		template
		<
			typename Exp,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool
		>
		using s_is_curried_unsigned_short_judgment = s_is_curried_judgment
		<
			unsigned short, Exp, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Exp,
			typename Continuation = ch_a_value,
			typename Image = bool
		>
		static constexpr Image a_is_curried_unsigned_short_judgment = a_is_curried_judgment
		<
			unsigned short, Exp, Continuation, Image
		>;
};
