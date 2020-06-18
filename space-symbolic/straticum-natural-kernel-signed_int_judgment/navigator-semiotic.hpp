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

struct navigator
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, navigator)

	// add:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_add = s_judgment_add
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_signed_int_judgment_add = a_judgment_add
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried add:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int
		>
		using s_curried_signed_int_judgment_add = s_curried_judgment_add
		<
			signed int, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			typename Image = Kind
		>
		static constexpr Image a_curried_signed_int_judgment_add = a_curried_judgment_add
		<
			signed int, Value1, Value2, Continuation, Kind, Image
		>;

	// subtract:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_subtract = s_judgment_subtract
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_signed_int_judgment_subtract = a_judgment_subtract
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried subtract:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int
		>
		using s_curried_signed_int_judgment_subtract = s_curried_judgment_subtract
		<
			signed int, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			typename Image = Kind
		>
		static constexpr Image a_curried_signed_int_judgment_subtract = a_curried_judgment_subtract
		<
			signed int, Value1, Value2, Continuation, Kind, Image
		>;

	// multiply:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_multiply = s_judgment_multiply
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_signed_int_judgment_multiply = a_judgment_multiply
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried multiply:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int
		>
		using s_curried_signed_int_judgment_multiply = s_curried_judgment_multiply
		<
			signed int, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			typename Image = Kind
		>
		static constexpr Image a_curried_signed_int_judgment_multiply = a_curried_judgment_multiply
		<
			signed int, Value1, Value2, Continuation, Kind, Image
		>;

	// divide:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_divide = s_judgment_divide
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_signed_int_judgment_divide = a_judgment_divide
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried divide:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int
		>
		using s_curried_signed_int_judgment_divide = s_curried_judgment_divide
		<
			signed int, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			typename Image = Kind
		>
		static constexpr Image a_curried_signed_int_judgment_divide = a_curried_judgment_divide
		<
			signed int, Value1, Value2, Continuation, Kind, Image
		>;

	// modulo:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_signed_int_judgment_modulo = s_judgment_modulo
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_signed_int_judgment_modulo = a_judgment_modulo
		<
			signed int, Value1, Value2, Continuation, Kind, ListKind, Image
		>;

	// curried modulo:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = signed int
		>
		using s_curried_signed_int_judgment_modulo = s_curried_judgment_modulo
		<
			signed int, Value1, Value2, Continuation, Kind
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = signed int,
			typename Image = Kind
		>
		static constexpr Image a_curried_signed_int_judgment_modulo = a_curried_judgment_modulo
		<
			signed int, Value1, Value2, Continuation, Kind, Image
		>;
};
