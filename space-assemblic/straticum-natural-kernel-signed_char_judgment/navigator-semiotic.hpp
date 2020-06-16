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
	#include nik_assemblic_typedef(patronum, natural, kernel, judgment, navigator)

	// add:

		// symbolic:

		template
		<
			signed char Value1, signed char Value2,
			typename Continuation = ch_s_values
		>
		using s_signed_char_judgment_add = sf_judgment_add
		<
			signed char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed char (*p_signed_char_judgment_add)(signed char, signed char) =
			p_judgment_add<signed char>;

	// subtract:

		// symbolic:

		template
		<
			signed char Value1, signed char Value2,
			typename Continuation = ch_s_values
		>
		using s_signed_char_judgment_subtract = sf_judgment_subtract
		<
			signed char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed char (*p_signed_char_judgment_subtract)(signed char, signed char) =
			p_judgment_subtract<signed char>;

	// multiply:

		// symbolic:

		template
		<
			signed char Value1, signed char Value2,
			typename Continuation = ch_s_values
		>
		using s_signed_char_judgment_multiply = sf_judgment_multiply
		<
			signed char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed char (*p_signed_char_judgment_multiply)(signed char, signed char) =
			p_judgment_multiply<signed char>;

	// divide:

		// symbolic:

		template
		<
			signed char Value1, signed char Value2,
			typename Continuation = ch_s_values
		>
		using s_signed_char_judgment_divide = sf_judgment_divide
		<
			signed char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed char (*p_signed_char_judgment_divide)(signed char, signed char) =
			p_judgment_divide<signed char>;

	// modulo:

		// symbolic:

		template
		<
			signed char Value1, signed char Value2,
			typename Continuation = ch_s_values
		>
		using s_signed_char_judgment_modulo = sf_judgment_modulo
		<
			signed char, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed char (*p_signed_char_judgment_modulo)(signed char, signed char) =
			p_judgment_modulo<signed char>;
};
