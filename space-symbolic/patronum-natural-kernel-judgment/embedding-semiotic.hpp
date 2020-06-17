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

struct embedding
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// judgment type:

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

	// judgment value:

		// symbolic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_s_grow_to_values
		>
		using s_judgment_value = typename dependent_memoization<Type>::template
		pattern_match_values_list<Judgment>::template
		s_front_grow_induct
		<
			Continuation, filler
		>;

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_a_grow_to_value,
			typename Image = Type
		>
		static constexpr Image a_judgment_value = dependent_memoization<Type>::template
		pattern_match_values_list<Judgment>::template
		a_front_grow_induct
		<
			Continuation, Image, filler
		>;

	// curried judgment type:

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

	// curried judgment value:

			// optimized to assume Judgment is in fact a judgment.

		// symbolic:

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_s_grow_to_values
		>
		using s_curried_judgment_value = typename Judgment::template
		s_front_grow_induct
		<
			Continuation, filler
		>;

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Type, typename Judgment,
			typename Continuation = ch_a_grow_to_value,
			typename Image = Type
		>
		static constexpr Image a_curried_judgment_value = Judgment::template
		a_front_grow_induct
		<
			Continuation, Image, filler
		>;
};
