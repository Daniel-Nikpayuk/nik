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
	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgment, inductor)

	// judgment value:

		// symbolic:

		template
		<
			bool Value,
			typename Continuation = ch_s_values
		>
		using sf_bool_judgment_value = typename Continuation::template result
		<
			bool,
			pattern_match_bool_judgment,
			Value
		>;

	// if then else:

		// symbolic:

		template
		<
			bool Value, typename Antecedent, typename Consequent,
			typename Continuation = ch_s_type
		>
		using s_bool_judgment_if_then_else = typename pattern_match_bool_judgment<Value>::template
		s_induct
		<
			Continuation, Antecedent, Consequent
		>;

	// display:

		// procedural:

		static constexpr void p_bool_judgment_display(bool v) { printf("%s", v ? "true" : "false"); }
};
