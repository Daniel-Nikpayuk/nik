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

#define safe_name

	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, proximity)

#undef safe_name

	// less than:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_less_than = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_proximity_as_p_judgment_less_than<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_less_than = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_proximity_as_p_judgment_less_than<Type>
		>;

	// curried less than:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_judgment_less_than = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_proximity_as_p_judgment_less_than<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_less_than = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_proximity_as_p_judgment_less_than<Type>
		>;

	// less than or equal:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_less_than_or_equal = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_proximity_as_p_judgment_less_than_or_equal<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_less_than_or_equal = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_proximity_as_p_judgment_less_than_or_equal<Type>
		>;

	// curried less than or equal:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_judgment_less_than_or_equal = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_proximity_as_p_judgment_less_than_or_equal<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_less_than_or_equal = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_proximity_as_p_judgment_less_than_or_equal<Type>
		>;

	// greater than:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_greater_than = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_proximity_as_p_judgment_greater_than<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_greater_than = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_proximity_as_p_judgment_greater_than<Type>
		>;

	// curried greater than:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_judgment_greater_than = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_proximity_as_p_judgment_greater_than<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_greater_than = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_proximity_as_p_judgment_greater_than<Type>
		>;

	// greater than or equal:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_greater_than_or_equal = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_proximity_as_p_judgment_greater_than_or_equal<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_greater_than_or_equal = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_proximity_as_p_judgment_greater_than_or_equal<Type>
		>;

	// curried greater than or equal:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool
		>
		using s_curried_judgment_greater_than_or_equal = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_proximity_as_p_judgment_greater_than_or_equal<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_greater_than_or_equal = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_proximity_as_p_judgment_greater_than_or_equal<Type>
		>;
};
