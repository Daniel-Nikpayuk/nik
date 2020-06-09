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
			typename Continuation = ch_symbolic_values_list,
			template<Type...> class ListType = dependent_memoization<Type>::template pattern_match_values
		>
		using s_judgment_add = typename dependent_memoization<Type>::template
		sf_values_list_zip
		<
			Type, pnkj_navigator_as_p_judgment_add<Type>, Value1, Value2, Continuation, ListType
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_assemblic_value_list,
			template<Type...> class ListType = dependent_memoization<Type>::template pattern_match_values,
			typename Image = Type
		>
		static constexpr Image a_judgment_add = dependent_memoization<Type>::template
		af_values_list_zip
		<
			Type, pnkj_navigator_as_p_judgment_add<Type>, Value1, Value2, Continuation, ListType, Image
		>;

	// curried add:

		// symbolic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_curried_judgment_add = typename dependent_memoization<Type>::template
		sf_values_zip
		<
			Type, pnkj_navigator_as_p_judgment_add<Type>, Value1, Value2, Continuation, Memoizer
		>;

		// assemblic:

		template
		<
			typename Type, typename Value1, typename Value2,
			typename Continuation = ch_assemblic_value,
			typename Image = Type
		>
		static constexpr Image a_curried_judgment_add = dependent_memoization<Type>::template
		af_values_zip
		<
			Type, pnkj_navigator_as_p_judgment_add<Type>, Value1, Value2, Continuation, Image
		>;
};
