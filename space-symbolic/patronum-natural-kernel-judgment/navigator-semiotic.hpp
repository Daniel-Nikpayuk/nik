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
		using s_judgment_add = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_add<Type>,
			Continuation
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
		static constexpr Image a_judgment_add = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_add<Type>,
			Continuation
		>;

	// curried add:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values
		>
		using s_curried_judgment_add = typename independent_memoization::template
		sf_values_zip
		<
			Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_add<Type>,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Image = Type
		>
		static constexpr Image a_curried_judgment_add = independent_memoization::template
		af_values_zip
		<
			Image, Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_add<Type>,
			Continuation
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
		using s_judgment_subtract = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_subtract<Type>,
			Continuation
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
		static constexpr Image a_judgment_subtract = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_subtract<Type>,
			Continuation
		>;

	// curried subtract:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values
		>
		using s_curried_judgment_subtract = typename independent_memoization::template
		sf_values_zip
		<
			Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_subtract<Type>,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Image = Type
		>
		static constexpr Image a_curried_judgment_subtract = independent_memoization::template
		af_values_zip
		<
			Image, Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_subtract<Type>,
			Continuation
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
		using s_judgment_multiply = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_multiply<Type>,
			Continuation
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
		static constexpr Image a_judgment_multiply = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_multiply<Type>,
			Continuation
		>;

	// curried multiply:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values
		>
		using s_curried_judgment_multiply = typename independent_memoization::template
		sf_values_zip
		<
			Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_multiply<Type>,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Image = Type
		>
		static constexpr Image a_curried_judgment_multiply = independent_memoization::template
		af_values_zip
		<
			Image, Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_multiply<Type>,
			Continuation
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
		using s_judgment_divide = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_divide<Type>,
			Continuation
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
		static constexpr Image a_judgment_divide = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_divide<Type>,
			Continuation
		>;

	// curried divide:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values
		>
		using s_curried_judgment_divide = typename independent_memoization::template
		sf_values_zip
		<
			Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_divide<Type>,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Image = Type
		>
		static constexpr Image a_curried_judgment_divide = independent_memoization::template
		af_values_zip
		<
			Image, Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_divide<Type>,
			Continuation
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
		using s_judgment_modulo = typename independent_memoization::template
		sf_values_list_zip
		<
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_modulo<Type>,
			Continuation
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
		static constexpr Image a_judgment_modulo = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Kind, ListKind,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_modulo<Type>,
			Continuation
		>;

	// curried modulo:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values
		>
		using s_curried_judgment_modulo = typename independent_memoization::template
		sf_values_zip
		<
			Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_modulo<Type>,
			Continuation
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			typename Image = Type
		>
		static constexpr Image a_curried_judgment_modulo = independent_memoization::template
		af_values_zip
		<
			Image, Type,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_modulo<Type>,
			Continuation
		>;
};
