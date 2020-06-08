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
			signed long Value1, signed long Value2,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_long_judgment_add = sf_judgment_add
		<
			signed long, Value1, Value2, Continuation, Memoizer
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed long (*p_signed_long_judgment_add)(signed long, signed long) =
			p_judgment_add<signed long>;

	// subtract:

		// symbolic:

		template
		<
			signed long Value1, signed long Value2,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_long_judgment_subtract = sf_judgment_subtract
		<
			signed long, Value1, Value2, Continuation, Memoizer
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed long (*p_signed_long_judgment_subtract)(signed long, signed long) =
			p_judgment_subtract<signed long>;

	// multiply:

		// symbolic:

		template
		<
			signed long Value1, signed long Value2,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_long_judgment_multiply = sf_judgment_multiply
		<
			signed long, Value1, Value2, Continuation, Memoizer
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed long (*p_signed_long_judgment_multiply)(signed long, signed long) =
			p_judgment_multiply<signed long>;

	// divide:

		// symbolic:

		template
		<
			signed long Value1, signed long Value2,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_long_judgment_divide = sf_judgment_divide
		<
			signed long, Value1, Value2, Continuation, Memoizer
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed long (*p_signed_long_judgment_divide)(signed long, signed long) =
			p_judgment_divide<signed long>;

	// modulo:

		// symbolic:

		template
		<
			signed long Value1, signed long Value2,
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_long_judgment_modulo = sf_judgment_modulo
		<
			signed long, Value1, Value2, Continuation, Memoizer
		>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr signed long (*p_signed_long_judgment_modulo)(signed long, signed long) =
			p_judgment_modulo<signed long>;
};
