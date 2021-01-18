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

struct proximity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, proximity)

	// less than:

		// symbolic:

		template
		<
			signed int Value1, signed int Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_less_than = sf_judgment_less_than
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_signed_int_judgment_less_than)(signed int, signed int) =
			p_judgment_less_than<signed int>;

	// less than or equal:

		// symbolic:

		template
		<
			signed int Value1, signed int Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_less_than_or_equal = sf_judgment_less_than_or_equal
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_signed_int_judgment_less_than_or_equal)(signed int, signed int) =
			p_judgment_less_than_or_equal<signed int>;

	// greater than:

		// symbolic:

		template
		<
			signed int Value1, signed int Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_greater_than = sf_judgment_greater_than
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_signed_int_judgment_greater_than)(signed int, signed int) =
			p_judgment_greater_than<signed int>;

	// greater than or equal:

		// symbolic:

		template
		<
			signed int Value1, signed int Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_greater_than_or_equal = sf_judgment_greater_than_or_equal
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_signed_int_judgment_greater_than_or_equal)(signed int, signed int) =
			p_judgment_greater_than_or_equal<signed int>;
};
