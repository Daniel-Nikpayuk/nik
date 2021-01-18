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

struct embedding
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// type:

		// symbolic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_s_grow_to_type
		>
		using s_judgment_type = typename dependent_memoization<Type>::template
		pattern_match_values_list<Judgment>::template
		s_front_grow_induct
		<
			Continuation, filler
		>;

	// value:

		// symbolic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_s_values,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			Kind (*Op)(Type) = p_identity<Kind>
		>
		using s_judgment_value = typename dependent_memoization<Type>::template
		pattern_match_values_list<Judgment>::template
		sf_v_map_v_mutate_induct
		<
			Continuation, Kind, ListKind, Op
		>;

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values,
			Kind (*Op)(Type) = p_identity<Kind>,
			typename Image = Kind
		>
		static constexpr Image a_judgment_value = dependent_memoization<Type>::template
		pattern_match_values_list<Judgment>::template
		af_v_map_v_mutate_induct
		<
			Continuation, Image, Kind, ListKind, Op
		>;

	// curried type:

		// symbolic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_s_grow_to_type
		>
		using s_curried_judgment_type = typename Judgment::template
		s_front_grow_induct
		<
			Continuation, filler
		>;

	// curried value:

		// symbolic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_s_values,
			typename Kind = Type,
			Kind (*Op)(Type) = p_identity<Kind>
		>
		using s_curried_judgment_value = typename Judgment::template
		sf_v_map_v_mutate_induct
		<
			Continuation, Kind, Op
		>;

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_a_to_value,
			typename Kind = Type,
			Kind (*Op)(Type) = p_identity<Kind>,
			typename Image = Kind
		>
		static constexpr Image a_curried_judgment_value = Judgment::template
		af_v_map_v_mutate_induct
		<
			Continuation, Image, Kind, Op
		>;
};
