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
	#include nik_assemblic_typedef(straticum, natural, kernel, bool_judgement, inductor)

	// if then else:

			// this grammatical construct breaks the standard nomenclature
			// due to its history and importance within programming literature.

		// symbolic:

		template<bool Value, typename Antecedent, typename Consequent, typename Continuation = ch_symbolic_type>
		using if_then_else = typename pattern_match_bool_judgement<Value>::template
		symbolic_induct
		<
			Continuation, Antecedent, Consequent
		>;

	// fast if then else:

		// symbolic:

		template<bool True, typename = filler>
		struct fast_match_bool_judgement
		{
			template<typename Antecedent, typename Consequent>
			using symbolic_induct = Antecedent;
		};

		template<typename Filler>
		struct fast_match_bool_judgement<false, Filler>
		{
			template<typename Antecedent, typename Consequent>
			using symbolic_induct = Consequent;
		};

		template<bool Value, typename Antecedent, typename Consequent>
		using fast_if_then_else = typename fast_match_bool_judgement<Value>::template
		symbolic_induct
		<
			Antecedent, Consequent
		>;

	// display:

		// procedural:

		static constexpr void p_bool_judgement_display(bool v) { printf("%s", v ? "true" : "false"); }
};
