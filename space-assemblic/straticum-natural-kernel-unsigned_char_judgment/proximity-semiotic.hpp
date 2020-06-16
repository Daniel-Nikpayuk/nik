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
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, proximity)

	// less than:

		// symbolic:

		template
		<
			unsigned char Value1, unsigned char Value2,
			typename Continuation = ch_s_values
		>
		using s_unsigned_char_judgment_less_than = sf_judgment_less_than
		<
			unsigned char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_unsigned_char_judgment_less_than)(unsigned char, unsigned char) =
			p_judgment_less_than<unsigned char>;

	// less than or equal:

		// symbolic:

		template
		<
			unsigned char Value1, unsigned char Value2,
			typename Continuation = ch_s_values
		>
		using s_unsigned_char_judgment_less_than_or_equal = sf_judgment_less_than_or_equal
		<
			unsigned char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_unsigned_char_judgment_less_than_or_equal)(unsigned char, unsigned char) =
			p_judgment_less_than_or_equal<unsigned char>;

	// greater than:

		// symbolic:

		template
		<
			unsigned char Value1, unsigned char Value2,
			typename Continuation = ch_s_values
		>
		using s_unsigned_char_judgment_greater_than = sf_judgment_greater_than
		<
			unsigned char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_unsigned_char_judgment_greater_than)(unsigned char, unsigned char) =
			p_judgment_greater_than<unsigned char>;

	// greater than or equal:

		// symbolic:

		template
		<
			unsigned char Value1, unsigned char Value2,
			typename Continuation = ch_s_values
		>
		using s_unsigned_char_judgment_greater_than_or_equal = sf_judgment_greater_than_or_equal
		<
			unsigned char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_unsigned_char_judgment_greater_than_or_equal)(unsigned char, unsigned char) =
			p_judgment_greater_than_or_equal<unsigned char>;
};
