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
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, proximity)

	// less than:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_less_than = s_judgment_less_than
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_unsigned_long_judgment_less_than = a_judgment_less_than
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried less than:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_unsigned_long_judgment_less_than = s_curried_judgment_less_than
		<
			unsigned long, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_unsigned_long_judgment_less_than = a_curried_judgment_less_than
		<
			unsigned long, Value1, Value2, Continuation, Kind, Image
		>;

	// less than or equal:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_less_than_or_equal = s_judgment_less_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_unsigned_long_judgment_less_than_or_equal = a_judgment_less_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried less than or equal:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_unsigned_long_judgment_less_than_or_equal = s_curried_judgment_less_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_unsigned_long_judgment_less_than_or_equal = a_curried_judgment_less_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation, Kind, Image
		>;

	// greater than:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_greater_than = s_judgment_greater_than
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_unsigned_long_judgment_greater_than = a_judgment_greater_than
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried greater than:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_unsigned_long_judgment_greater_than = s_curried_judgment_greater_than
		<
			unsigned long, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_unsigned_long_judgment_greater_than = a_curried_judgment_greater_than
		<
			unsigned long, Value1, Value2, Continuation, Kind, Image
		>;

	// greater than or equal:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_greater_than_or_equal = s_judgment_greater_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_unsigned_long_judgment_greater_than_or_equal = a_judgment_greater_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried greater than or equal:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_unsigned_long_judgment_greater_than_or_equal = s_curried_judgment_greater_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_unsigned_long_judgment_greater_than_or_equal = a_curried_judgment_greater_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation, Kind, Image
		>;
};
