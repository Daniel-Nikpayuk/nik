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

struct identity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, judgement, inductor)

	// is judgement:

		// symbolic:

		template<typename Type, typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_judgement = typename pattern_match_judgement<Type, Exp>::template
		symbolic_match
		<
			Continuation
		>;

		// assemblic:

		template<typename Type, typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_judgement = pattern_match_judgement<Type, Exp>::template
		assemblic_match
		<
			Continuation
		>;

	// is dependent judgement:

		// symbolic:

		template<typename Type, typename Exp, typename Continuation = ch_symbolic_values>
		using s_is_dependent_judgement = typename pattern_match_dependent_judgement<Type, Exp>::template
		symbolic_match
		<
			Continuation
		>;

		// assemblic:

		template<typename Type, typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_dependent_judgement = pattern_match_dependent_judgement<Type, Exp>::template
		assemblic_match
		<
			Continuation
		>;
};

