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

	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, navigator)

#undef safe_name

	// logical not:

		// symbolic:

/*
		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			template<Type...> class ListType = dependent_memoization<Type>::template pattern_match_values
		>
		using s_judgment_add = typename independent_memoization::template
		sf_values_list_map
		<
			Type, ListType,
			Type, Value1,
			Type, Value2,
			pnkj_navigator_as_p_judgment_add<Type>,
			Continuation
		>;
*/

		// assemblic:

	// logical and:

		// symbolic:

		template
		<
			typename Value1, typename Value2,
			typename Continuation = ch_s_values,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
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

/*
		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_a_to_value,
			template<Type...> class ListType = dependent_memoization<Type>::template pattern_match_values,
			typename Image = Type
		>
		static constexpr Image a_judgment_add = independent_memoization::template
		af_values_list_zip
		<
			Image,
			Type, ListType,
			Type, Value1,
			Type, Value2,
			snkbj_navigator_as_p_bool_judgment_and,
			Continuation
		>;

	// curried logical and:

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
			snkbj_navigator_as_p_bool_judgment_and,
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
			snkbj_navigator_as_p_bool_judgment_and,
			Continuation
		>;
*/

/***********************************************************************************************************************/

	// logical or:

		// symbolic:

		// assemblic:

	// curried logical or:

		// symbolic:

		// assemblic:

	// logical implies:

		// symbolic:

		// assemblic:

	// curried logical implies:

		// symbolic:

		// assemblic:

	// logical equivalent:

		// symbolic:

		// assemblic:

	// curried logical equivalent:

		// symbolic:

		// assemblic:
};
