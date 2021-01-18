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

struct proximity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)

	// less than:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_less_than = typename Continuation::template result
		<
			Kind, ListKind, bool, (Value1 < Value2)
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr bool p_judgment_less_than(Type Value1, Type Value2) { return (Value1 < Value2); }

	// less than or equal:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_less_than_or_equal = typename Continuation::template result
		<
			Kind, ListKind, bool, (Value1 <= Value2)
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr bool p_judgment_less_than_or_equal(Type Value1, Type Value2) { return (Value1 <= Value2); }

	// greater than:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_greater_than = typename Continuation::template result
		<
			Kind, ListKind, bool, (Value1 > Value2)
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr bool p_judgment_greater_than(Type Value1, Type Value2) { return (Value1 > Value2); }

	// greater than or equal:

		// symbolic:

		template
		<
			typename Type, Type Value1, Type Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = bool,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using sf_judgment_greater_than_or_equal = typename Continuation::template result
		<
			Kind, ListKind, bool, (Value1 >= Value2)
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		template<typename Type>
		static constexpr bool p_judgment_greater_than_or_equal(Type Value1, Type Value2) { return (Value1 >= Value2); }
};
