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

	// add:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_add = typename Continuation::template result
		<
			Kind, ListKind, Type, Value1 + Value2
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr Type p_judgment_add(Type Value1, Type Value2) { return Value1 + Value2; }

	// subtract:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_subtract = typename Continuation::template result
		<
			Kind, ListKind, Type, Value1 - Value2
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr Type p_judgment_subtract(Type Value1, Type Value2) { return Value1 - Value2; }

	// multiply:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_multiply = typename Continuation::template result
		<
			Kind, ListKind, Type, Value1 * Value2
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr Type p_judgment_multiply(Type Value1, Type Value2) { return Value1 * Value2; }

	// divide:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_divide = typename Continuation::template result
		<
			Kind, ListKind, Type, Value1 / Value2
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr Type p_judgment_divide(Type Value1, Type Value2) { return Value1 / Value2; }

	// modulo:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = Type,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_modulo = typename Continuation::template result
		<
			Kind, ListKind, Type, Value1 % Value2
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr Type p_judgment_modulo(Type Value1, Type Value2) { return Value1 % Value2; }
};
