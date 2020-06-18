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
	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, inductor)

#define safe_name

	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, navigator)

#undef safe_name

	// logical not:

		// symbolic:

		template
		<
			typename Value,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment
		>
		using s_bool_judgment_not = typename independent_memoization::template
		sf_values_list_map
		<
			Kind, ListKind,
			bool, Value,
			snkbj_navigator_as_p_bool_judgment_not,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment,
			typename Image = Kind
		>
		static constexpr Image a_bool_judgment_not = independent_memoization::template
		af_values_list_map
		<
			Image,
			Kind, ListKind,
			bool, Value,
			snkbj_navigator_as_p_bool_judgment_not,
			Continuation
		>;

	// curried logical not:

		// symbolic:

		template
		<
			typename Value,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_not = typename independent_memoization::template
		sf_values_map
		<
			Kind,
			bool, Value,
			snkbj_navigator_as_p_bool_judgment_not,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_not = independent_memoization::template
		af_values_map
		<
			Image, Kind,
			bool, Value,
			snkbj_navigator_as_p_bool_judgment_not,
			Continuation
		>;

	// logical and:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment
		>
		using s_bool_judgment_and = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_and,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment,
			typename Image = Kind
		>
		static constexpr Image a_bool_judgment_and = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_and,
			Continuation
		>;

	// curried logical and:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_and = typename independent_memoization::template
		sf_values_zip
		<
			Kind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_and,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_and = independent_memoization::template
		af_values_zip
		<
			Image, Kind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_and,
			Continuation
		>;

	// logical or:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment
		>
		using s_bool_judgment_or = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_or,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment,
			typename Image = Kind
		>
		static constexpr Image a_bool_judgment_or = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_or,
			Continuation
		>;

	// curried logical or:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_or = typename independent_memoization::template
		sf_values_zip
		<
			Kind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_or,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_or = independent_memoization::template
		af_values_zip
		<
			Image, Kind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_or,
			Continuation
		>;

	// logical implies:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment
		>
		using s_bool_judgment_implies = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_implies,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment,
			typename Image = Kind
		>
		static constexpr Image a_bool_judgment_implies = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_implies,
			Continuation
		>;

	// curried logical implies:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_implies = typename independent_memoization::template
		sf_values_zip
		<
			Kind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_implies,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_implies = independent_memoization::template
		af_values_zip
		<
			Image, Kind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_implies,
			Continuation
		>;

	// logical equivalent:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment
		>
		using s_bool_judgment_equivalent = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_equivalent,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment,
			typename Image = Kind
		>
		static constexpr Image a_bool_judgment_equivalent = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_equivalent,
			Continuation
		>;

	// curried logical equivalent:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_equivalent = typename independent_memoization::template
		sf_values_zip
		<
			Kind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_equivalent,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_equivalent = independent_memoization::template
		af_values_zip
		<
			Image, Kind,
			bool, Value1,
			bool, Value2,
			snkbj_navigator_as_p_bool_judgment_equivalent,
			Continuation
		>;
};
