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
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, navigator)

	// add:

		// symbolic:

		template
		<
			unsigned long Value1, unsigned long Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_add = sf_judgment_add
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned long (*p_unsigned_long_judgment_add)(unsigned long, unsigned long) =
			p_judgment_add<unsigned long>;

	// subtract:

		// symbolic:

		template
		<
			unsigned long Value1, unsigned long Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_subtract = sf_judgment_subtract
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned long (*p_unsigned_long_judgment_subtract)(unsigned long, unsigned long) =
			p_judgment_subtract<unsigned long>;

	// multiply:

		// symbolic:

		template
		<
			unsigned long Value1, unsigned long Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_multiply = sf_judgment_multiply
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned long (*p_unsigned_long_judgment_multiply)(unsigned long, unsigned long) =
			p_judgment_multiply<unsigned long>;

	// divide:

		// symbolic:

		template
		<
			unsigned long Value1, unsigned long Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_divide = sf_judgment_divide
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned long (*p_unsigned_long_judgment_divide)(unsigned long, unsigned long) =
			p_judgment_divide<unsigned long>;

	// modulo:

		// symbolic:

		template
		<
			unsigned long Value1, unsigned long Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned long,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_long_judgment_modulo = sf_judgment_modulo
		<
			unsigned long, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned long (*p_unsigned_long_judgment_modulo)(unsigned long, unsigned long) =
			p_judgment_modulo<unsigned long>;
};
