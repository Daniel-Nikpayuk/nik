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

	// logical not:

		// symbolic:

		template<bool Value, typename Continuation = ch_symbolic_values>
		using sf_bool_judgment_not = typename Continuation::template result<pnkb_inductor_ss, bool, !Value>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool p_bool_judgment_not(bool Value) { return !Value; }

	// logical and:

		// symbolic:

		template<bool Value1, bool Value2, typename Continuation = ch_symbolic_values>
		using sf_bool_judgment_and = typename Continuation::template result<pnkb_inductor_ss, bool, Value1 && Value2>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool p_bool_judgment_and(bool Value1, bool Value2) { return Value1 && Value2; }

	// logical or:

		// symbolic:

		template<bool Value1, bool Value2, typename Continuation = ch_symbolic_values>
		using sf_bool_judgment_or = typename Continuation::template result<pnkb_inductor_ss, bool, Value1 || Value2>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool p_bool_judgment_or(bool Value1, bool Value2) { return Value1 || Value2; }

	// logical implies:

		// symbolic:

		template<bool Value1, bool Value2, typename Continuation = ch_symbolic_values>
		using sf_bool_judgment_implies = typename Continuation::template result<pnkb_inductor_ss, bool, !Value1 || Value2>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool p_bool_judgment_implies(bool Value1, bool Value2) { return !Value1 || Value2; }

	// logical equivalent:

		// symbolic:

		template<bool Value1, bool Value2, typename Continuation = ch_symbolic_values>
		using sf_bool_judgment_equivalent = typename Continuation::template result<pnkb_inductor_ss, bool, Value1 == Value2>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool p_bool_judgment_equivalent(bool Value1, bool Value2) { return Value1 == Value2; }
};
