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
			unsigned short Value1, unsigned short Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_short_judgment_add = sf_judgment_add
		<
			unsigned short, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned short (*p_unsigned_short_judgment_add)(unsigned short, unsigned short) =
			p_judgment_add<unsigned short>;

	// subtract:

		// symbolic:

		template
		<
			unsigned short Value1, unsigned short Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_short_judgment_subtract = sf_judgment_subtract
		<
			unsigned short, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned short (*p_unsigned_short_judgment_subtract)(unsigned short, unsigned short) =
			p_judgment_subtract<unsigned short>;

	// multiply:

		// symbolic:

		template
		<
			unsigned short Value1, unsigned short Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_short_judgment_multiply = sf_judgment_multiply
		<
			unsigned short, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned short (*p_unsigned_short_judgment_multiply)(unsigned short, unsigned short) =
			p_judgment_multiply<unsigned short>;

	// divide:

		// symbolic:

		template
		<
			unsigned short Value1, unsigned short Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_short_judgment_divide = sf_judgment_divide
		<
			unsigned short, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned short (*p_unsigned_short_judgment_divide)(unsigned short, unsigned short) =
			p_judgment_divide<unsigned short>;

	// modulo:

		// symbolic:

		template
		<
			unsigned short Value1, unsigned short Value2,
			typename Continuation = ch_s_match_to_value,
			typename Kind = unsigned short,
			template<Kind...> class ListKind = dependent_memoization<Kind>::template pattern_match_values
		>
		using s_unsigned_short_judgment_modulo = sf_judgment_modulo
		<
			unsigned short, Value1, Value2, Continuation, Kind, ListKind
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr unsigned short (*p_unsigned_short_judgment_modulo)(unsigned short, unsigned short) =
			p_judgment_modulo<unsigned short>;
};
