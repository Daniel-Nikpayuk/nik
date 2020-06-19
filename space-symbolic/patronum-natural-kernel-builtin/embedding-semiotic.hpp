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

	// type literal:

		// symbolic:

		template
		<
			typename Type, template<typename> class Op,
			typename Continuation = ch_s_values,
			typename Kind = const char*
		>
		using s_type_literal = typename independent_memoization::template
		pattern_match_types<Type>::template
		sf_t_map_v_mutate_induct
		<
			Continuation, Kind, Op
		>;

		// assemblic:

		template
		<
			typename Type, template<typename> class Op,
			typename Continuation = ch_a_to_value,
			typename Kind = const char*,
			typename Image = Kind
		>
		static constexpr Image a_type_literal = independent_memoization::template
		pattern_match_types<Type>::template
		af_t_map_v_mutate_induct
		<
			Continuation, Image, Kind, Op
		>;
};
