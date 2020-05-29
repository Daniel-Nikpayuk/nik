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

	// The general nik algorithmic paradigm is ignored here as it is intended for the nik narrative design.
	// Notably, the issue here is we have implemented judgements as specialized lists in order to privilege
	// meta C++ minimal memoization best practices, but we otherwise don't yet have the necessary boolean
	// operators.

#define NIK_ONE 1

struct identity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, embedding)

	#include nik_symbolic_typedef(patronum, natural, kernel, judgement, inductor)

	// is judgement:

		// assemblic:

		// The expectation is && short circuits so if Exp is not even a values list there's no issue.

		template<typename Type, typename Exp, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_judgement = pattern_match_judgement<Type, Exp>::template
		assemblic_match
		<
			Continuation

		> && dependent_memoization<Type>::template a_length<Type, Exp, Continuation> == NIK_ONE;

		// symbolic:

		template<typename Exp, typename Type, typename Continuation = ch_symbolic_values>
		using s_is_judgement = typename Continuation::template result
		<
			pnkb_inductor_ss, bool, a_is_judgement<Exp, Type>
		>;

	// is dependent judgement:

		// assemblic:

		template<typename Exp, typename Type, typename Continuation = ch_assemblic_value>
		static constexpr bool a_is_dependent_judgement = a_is_judgement<Exp, Type, Continuation> &&
		pattern_match_dependent_induct<Exp>::template assemblic_match
		<
			Continuation
		>;

		// symbolic:

		template<typename Exp, typename Type, typename Continuation = ch_symbolic_values>
		using s_is_dependent_judgement = typename Continuation::template result
		<
			pnkb_inductor_ss, bool, a_is_dependent_judgement<Exp, Type>
		>;
};

#undef NIK_ONE

