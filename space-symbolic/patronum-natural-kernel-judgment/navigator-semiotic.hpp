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

struct navigator
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

#define safe_name

	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, navigator)

#undef safe_name

	// add:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_add = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_add<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_add = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_add<Type>
		>;

	// curried add:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type
		>
		using s_curried_judgment_add = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_navigator_as_p_judgment_add<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_add = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_navigator_as_p_judgment_add<Type>
		>;

	// subtract:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_subtract = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_subtract<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_subtract = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_subtract<Type>
		>;

	// curried subtract:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type
		>
		using s_curried_judgment_subtract = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_navigator_as_p_judgment_subtract<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_subtract = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_navigator_as_p_judgment_subtract<Type>
		>;

	// multiply:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_multiply = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_multiply<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_multiply = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_multiply<Type>
		>;

	// curried multiply:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type
		>
		using s_curried_judgment_multiply = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_navigator_as_p_judgment_multiply<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_multiply = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_navigator_as_p_judgment_multiply<Type>
		>;

	// divide:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_divide = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_divide<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_divide = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_divide<Type>
		>;

	// curried divide:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type
		>
		using s_curried_judgment_divide = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_navigator_as_p_judgment_divide<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_divide = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_navigator_as_p_judgment_divide<Type>
		>;

	// modulo:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_judgment_modulo = typename dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_list_zip_induct<Continuation>,
			Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_modulo<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			typename Image = Kind
		>
		static constexpr Image a_judgment_modulo = dependent_memoization<Type>::template
		pattern_match_values_list<Value1>::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_list_zip_induct<Continuation>,
			Image, Kind, ListKind, Type, Value2, pnkj_navigator_as_p_judgment_modulo<Type>
		>;

	// curried modulo:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type
		>
		using s_curried_judgment_modulo = typename Value1::template
		s_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_sf_values_zip_induct<Continuation>,
			Kind, Type, Value2, pnkj_navigator_as_p_judgment_modulo<Type>
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = Type,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_modulo = Value1::template
		a_vv_zip_v_mutate_induct
		<
			typename independent_memoization::template cp_af_values_zip_induct<Continuation>,
			Image, Kind, Type, Value2, pnkj_navigator_as_p_judgment_modulo<Type>
		>;
};
