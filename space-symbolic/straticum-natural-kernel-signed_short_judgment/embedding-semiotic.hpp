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
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, embedding)

	// value:

		// symbolic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Judgment,
			typename Continuation = ch_s_values,
			typename Kind = signed short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			Kind (*Op)(signed short) = p_identity<Kind>
		>
		using s_signed_short_judgment_value = s_judgment_value
		<
			signed short, Judgment, Continuation, Kind, ListKind, Op
		>;

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Judgment,
			typename Continuation = ch_a_to_value,
			typename Kind = signed short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			Kind (*Op)(signed short) = p_identity<Kind>,
			typename Image = Kind
		>
		static constexpr Image a_signed_short_judgment_value = a_judgment_value
		<
			signed short, Judgment, Continuation, Kind, ListKind, Op, Image
		>;

	// curried value:

		// symbolic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Judgment,
			typename Continuation = ch_s_values,
			typename Kind = signed short,
			Kind (*Op)(signed short) = p_identity<Kind>
		>
		using s_curried_signed_short_judgment_value = s_curried_judgment_value
		<
			signed short, Judgment, Continuation, Kind, Op
		>;

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Judgment,
			typename Continuation = ch_a_to_value,
			typename Kind = signed short,
			Kind (*Op)(signed short) = p_identity<Kind>,
			typename Image = Kind
		>
		static constexpr Image a_curried_signed_short_judgment_value = a_curried_judgment_value
		<
			signed short, Judgment, Continuation, Kind, Op, Image
		>;
};
