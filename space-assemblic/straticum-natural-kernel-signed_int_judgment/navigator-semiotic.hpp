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

		template<signed int Value1, signed int Value2, typename Continuation = ch_symbolic_values>
		using s_signed_int_judgment_add = sf_judgment_add
		<
			signed int, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed int (*p_signed_int_judgment_add)(signed int, signed int) =
			p_judgment_add<signed int>;

	// subtract:

		// symbolic:

		template<signed int Value1, signed int Value2, typename Continuation = ch_symbolic_values>
		using s_signed_int_judgment_subtract = sf_judgment_subtract
		<
			signed int, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed int (*p_signed_int_judgment_subtract)(signed int, signed int) =
			p_judgment_subtract<signed int>;

	// multiply:

		// symbolic:

		template<signed int Value1, signed int Value2, typename Continuation = ch_symbolic_values>
		using s_signed_int_judgment_multiply = sf_judgment_multiply
		<
			signed int, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed int (*p_signed_int_judgment_multiply)(signed int, signed int) =
			p_judgment_multiply<signed int>;

	// divide:

		// symbolic:

		template<signed int Value1, signed int Value2, typename Continuation = ch_symbolic_values>
		using s_signed_int_judgment_divide = sf_judgment_divide
		<
			signed int, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed int (*p_signed_int_judgment_divide)(signed int, signed int) =
			p_judgment_divide<signed int>;

	// modulo:

		// symbolic:

		template<signed int Value1, signed int Value2, typename Continuation = ch_symbolic_values>
		using s_signed_int_judgment_modulo = sf_judgment_modulo
		<
			signed int, Value1, Value2, Continuation
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed int (*p_signed_int_judgment_modulo)(signed int, signed int) =
			p_judgment_modulo<signed int>;
};
