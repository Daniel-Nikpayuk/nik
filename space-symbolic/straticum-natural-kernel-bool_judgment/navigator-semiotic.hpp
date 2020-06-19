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

			// reimplement with patronum embedding value ?

		template
		<
			typename Value,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment
		>
		using s_bool_judgment_not = typename dependent_memoization<bool>::template
		pattern_match_values_list<Value>::template
		sf_v_map_v_mutate_induct
		<
			Continuation, Kind, ListKind, snkbj_navigator_as_p_bool_judgment_not
		>;

		// assemblic:

		template
		<
			typename Value,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment,
			typename Image = Kind
		>
		static constexpr Image a_bool_judgment_not = dependent_memoization<bool>::template
		pattern_match_values_list<Value>::template
		af_v_map_v_mutate_induct
		<
			Continuation, Image, Kind, ListKind, snkbj_navigator_as_p_bool_judgment_not
		>;

	// curried logical not:

		// symbolic:

		template
		<
			typename Value,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_not = typename Value::template
		sf_v_map_v_mutate_induct
		<
			Continuation, Kind, snkbj_navigator_as_p_bool_judgment_not
		>;

		// assemblic:

		template
		<
			typename Value,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_not = Value::template
		af_v_map_v_mutate_induct
		<
			Continuation, Image, Kind, snkbj_navigator_as_p_bool_judgment_not
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
		using s_bool_judgment_and = typename dependent_memoization<bool>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, bool, Value2, snkbj_navigator_as_p_bool_judgment_and
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
		static constexpr Image a_bool_judgment_and = dependent_memoization<bool>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, bool, Value2, snkbj_navigator_as_p_bool_judgment_and
		>;

	// curried logical and:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_and = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, bool, Value2, snkbj_navigator_as_p_bool_judgment_and
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_and = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, bool, Value2, snkbj_navigator_as_p_bool_judgment_and
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
		using s_bool_judgment_or = typename dependent_memoization<bool>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, bool, Value2, snkbj_navigator_as_p_bool_judgment_or
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
		static constexpr Image a_bool_judgment_or = dependent_memoization<bool>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, bool, Value2, snkbj_navigator_as_p_bool_judgment_or
		>;

	// curried logical or:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_or = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, bool, Value2, snkbj_navigator_as_p_bool_judgment_or
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_or = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, bool, Value2, snkbj_navigator_as_p_bool_judgment_or
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
		using s_bool_judgment_implies = typename dependent_memoization<bool>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, bool, Value2, snkbj_navigator_as_p_bool_judgment_implies
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
		static constexpr Image a_bool_judgment_implies = dependent_memoization<bool>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, bool, Value2, snkbj_navigator_as_p_bool_judgment_implies
		>;

	// curried logical implies:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_implies = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, bool, Value2, snkbj_navigator_as_p_bool_judgment_implies
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_implies = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, bool, Value2, snkbj_navigator_as_p_bool_judgment_implies
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
		using s_bool_judgment_equivalent = typename dependent_memoization<bool>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, bool, Value2, snkbj_navigator_as_p_bool_judgment_equivalent
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
		static constexpr Image a_bool_judgment_equivalent = dependent_memoization<bool>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, bool, Value2, snkbj_navigator_as_p_bool_judgment_equivalent
		>;

	// curried logical equivalent:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_bool_judgment_equivalent = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, bool, Value2, snkbj_navigator_as_p_bool_judgment_equivalent
		>;

		// assemblic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_equivalent = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, bool, Value2, snkbj_navigator_as_p_bool_judgment_equivalent
		>;
};
