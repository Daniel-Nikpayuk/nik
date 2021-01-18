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
	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, inductor)

#define safe_name

	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, embedding)

#undef safe_name

	// value:

		// symbolic:

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Judgment,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = pattern_match_bool_judgment,
			Kind (*Op)(bool) = p_identity<Kind>,
			typename Image = Kind
		>
		static constexpr Image a_bool_judgment_value = dependent_memoization<bool>::template
		pattern_match_values_list<Judgment>::template
		af_v_map_v_mutate_induct
		<
			Continuation, Image, Kind, ListKind, Op
		>;

	// curried value:

		// symbolic:

		// assemblic:

			// optimized to assume Judgment is in fact a judgment.

		template
		<
			typename Judgment,
			typename Continuation = ch_a_to_value,
			typename Kind = bool,
			Kind (*Op)(bool) = p_identity<Kind>,
			typename Image = Kind
		>
		static constexpr Image a_curried_bool_judgment_value = Judgment::template
		af_v_map_v_mutate_induct
		<
			Continuation, Image, Kind, Op
		>;

	// if then else:

		// symbolic:

		template
		<
			typename Value, typename Antecedent, typename Consequent,
			typename Continuation = ch_s_type
		>
		using s_bool_judgment_if_then_else = snkbj_embedding_as_s_bool_judgment_if_then_else
		<
			a_bool_judgment_value<Value>, Antecedent, Consequent, Continuation
		>;

	// curried if then else:

		// symbolic:

		template
		<
			typename Value, typename Antecedent, typename Consequent,
			typename Continuation = ch_s_type
		>
		using s_curried_bool_judgment_if_then_else = snkbj_embedding_as_s_bool_judgment_if_then_else
		<
			a_curried_bool_judgment_value<Value>, Antecedent, Consequent, Continuation
		>;
};
