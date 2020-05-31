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

struct identity
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_assemblic_typedef(patronum, natural, kernel, judgement, identity)

	// is equal:

		// symbolic:

		template<char Value1, char Value2, typename Continuation = ch_symbolic_values>
		using s_is_char_equal = s_is_equal<char, Value1, Value2, Continuation>;

		template<unsigned char Value1, unsigned char Value2, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_char_equal = s_is_equal<unsigned char, Value1, Value2, Continuation>;

		template<signed char Value1, signed char Value2, typename Continuation = ch_symbolic_values>
		using s_is_signed_char_equal = s_is_equal<signed char, Value1, Value2, Continuation>;

		template<wchar_t Value1, wchar_t Value2, typename Continuation = ch_symbolic_values>
		using s_is_wchar_t_equal = s_is_equal<wchar_t, Value1, Value2, Continuation>;

		template<char16_t Value1, char16_t Value2, typename Continuation = ch_symbolic_values>
		using s_is_char16_t_equal = s_is_equal<char16_t, Value1, Value2, Continuation>;

		template<char32_t Value1, char32_t Value2, typename Continuation = ch_symbolic_values>
		using s_is_char32_t_equal = s_is_equal<char32_t, Value1, Value2, Continuation>;

		template<unsigned short Value1, unsigned short Value2, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_short_equal = s_is_equal<unsigned short, Value1, Value2, Continuation>;

		template<signed short Value1, signed short Value2, typename Continuation = ch_symbolic_values>
		using s_is_signed_short_equal = s_is_equal<signed short, Value1, Value2, Continuation>;

		template<unsigned int Value1, unsigned int Value2, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_int_equal = s_is_equal<unsigned int, Value1, Value2, Continuation>;

		template<signed int Value1, signed int Value2, typename Continuation = ch_symbolic_values>
		using s_is_signed_int_equal = s_is_equal<signed int, Value1, Value2, Continuation>;

		template<unsigned long Value1, unsigned long Value2, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_long_equal = s_is_equal<unsigned long, Value1, Value2, Continuation>;

		template<signed long Value1, signed long Value2, typename Continuation = ch_symbolic_values>
		using s_is_signed_long_equal = s_is_equal<signed long, Value1, Value2, Continuation>;

		template<unsigned long long Value1, unsigned long long Value2, typename Continuation = ch_symbolic_values>
		using s_is_unsigned_long_long_equal = s_is_equal<unsigned long long, Value1, Value2, Continuation>;

		template<signed long long Value1, signed long long Value2, typename Continuation = ch_symbolic_values>
		using s_is_signed_long_long_equal = s_is_equal<signed long long, Value1, Value2, Continuation>;

		// assemblic:

			// is not implemented as it's better to use constexpr functions.

		// procedural:

		static constexpr bool (*p_is_char_equal)(char, char) =
		p_is_equal<char>;

		static constexpr bool (*p_is_unsigned_char_equal)(unsigned char, unsigned char) =
		p_is_equal<unsigned char>;

		static constexpr bool (*p_is_signed_char_equal)(signed char, signed char) =
		p_is_equal<signed char>;

		static constexpr bool (*p_is_wchar_t_equal)(wchar_t, wchar_t) =
		p_is_equal<wchar_t>;

		static constexpr bool (*p_is_char16_t_equal)(char16_t, char16_t) =
		p_is_equal<char16_t>;

		static constexpr bool (*p_is_char32_t_equal)(char32_t, char32_t) =
		p_is_equal<char32_t>;

		static constexpr bool (*p_is_unsigned_short_equal)(unsigned short, unsigned short) =
		p_is_equal<unsigned short>;

		static constexpr bool (*p_is_signed_short_equal)(signed short, signed short) =
		p_is_equal<signed short>;

		static constexpr bool (*p_is_unsigned_int_equal)(unsigned int, unsigned int) =
		p_is_equal<unsigned int>;

		static constexpr bool (*p_is_signed_int_equal)(signed int, signed int) =
		p_is_equal<signed int>;

		static constexpr bool (*p_is_unsigned_long_equal)(unsigned long, unsigned long) =
		p_is_equal<unsigned long>;

		static constexpr bool (*p_is_signed_long_equal)(signed long, signed long) =
		p_is_equal<signed long>;

		static constexpr bool (*p_is_unsigned_long_long_equal)(unsigned long long, unsigned long long) =
		p_is_equal<unsigned long long>;

		static constexpr bool (*p_is_signed_long_long_equal)(signed long long, signed long long) =
		p_is_equal<signed long long>;
};

