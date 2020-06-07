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

struct proximity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, proximity)

	// less than:

		// symbolic:

		template<unsigned long Value1, unsigned long Value2, typename Continuation = ch_symbolic_values>
		using s_unsigned_long_judgment_less_than = sf_judgment_less_than
		<
			unsigned long, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_unsigned_long_judgment_less_than)(unsigned long, unsigned long) =
			p_judgment_less_than<unsigned long>;

	// less than or equal:

		// symbolic:

		template<unsigned long Value1, unsigned long Value2, typename Continuation = ch_symbolic_values>
		using s_unsigned_long_judgment_less_than_or_equal = sf_judgment_less_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_unsigned_long_judgment_less_than_or_equal)(unsigned long, unsigned long) =
			p_judgment_less_than_or_equal<unsigned long>;

	// greater than:

		// symbolic:

		template<unsigned long Value1, unsigned long Value2, typename Continuation = ch_symbolic_values>
		using s_unsigned_long_judgment_greater_than = sf_judgment_greater_than
		<
			unsigned long, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_unsigned_long_judgment_greater_than)(unsigned long, unsigned long) =
			p_judgment_greater_than<unsigned long>;

	// greater than or equal:

		// symbolic:

		template<unsigned long Value1, unsigned long Value2, typename Continuation = ch_symbolic_values>
		using s_unsigned_long_judgment_greater_than_or_equal = sf_judgment_greater_than_or_equal
		<
			unsigned long, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_unsigned_long_judgment_greater_than_or_equal)(unsigned long, unsigned long) =
			p_judgment_greater_than_or_equal<unsigned long>;
};
