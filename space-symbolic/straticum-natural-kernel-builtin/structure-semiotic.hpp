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

struct structure
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, structure)

	// bool judgments:

		// symbolic:

		template
		<
			bool Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_bool_to_judgment = s_to_judgment<bool, Value, Continuation>;

		// assemblic:

		template
		<
			bool Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = bool
		>
		static constexpr Image a_bool_to_judgment = a_to_judgment
		<
			bool, Value, Continuation, Image
		>;

	// int judgments:

		// symbolic:

		template
		<
			unsigned char Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_unsigned_char_to_judgment = s_to_judgment<unsigned char, Value, Continuation>;

		template
		<
			signed char Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_signed_char_to_judgment = s_to_judgment<signed char, Value, Continuation>;

		template
		<
			unsigned short Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_unsigned_short_to_judgment = s_to_judgment<unsigned short, Value, Continuation>;

		template
		<
			signed short Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_signed_short_to_judgment = s_to_judgment<signed short, Value, Continuation>;

		template
		<
			unsigned int Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_unsigned_int_to_judgment = s_to_judgment<unsigned int, Value, Continuation>;

		template
		<
			signed int Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_signed_int_to_judgment = s_to_judgment<signed int, Value, Continuation>;

		template
		<
			unsigned long Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_unsigned_long_to_judgment = s_to_judgment<unsigned long, Value, Continuation>;

		template
		<
			signed long Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_signed_long_to_judgment = s_to_judgment<signed long, Value, Continuation>;

		template
		<
			unsigned long long Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_unsigned_long_long_to_judgment = s_to_judgment<unsigned long long, Value, Continuation>;

		template
		<
			signed long long Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_signed_long_long_to_judgment = s_to_judgment<signed long long, Value, Continuation>;

		// assemblic:

		template
		<
			unsigned char Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = unsigned char
		>
		static constexpr Image a_unsigned_char_to_judgment = a_to_judgment
		<
			unsigned char, Value, Continuation, Image
		>;

		template
		<
			signed char Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = signed char
		>
		static constexpr Image a_signed_char_to_judgment = a_to_judgment
		<
			signed char, Value, Continuation, Image
		>;

		template
		<
			unsigned short Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = unsigned short
		>
		static constexpr Image a_unsigned_short_to_judgment = a_to_judgment
		<
			unsigned short, Value, Continuation, Image
		>;

		template
		<
			signed short Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = signed short
		>
		static constexpr Image a_signed_short_to_judgment = a_to_judgment
		<
			signed short, Value, Continuation, Image
		>;

		template
		<
			unsigned int Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = unsigned int
		>
		static constexpr Image a_unsigned_int_to_judgment = a_to_judgment
		<
			unsigned int, Value, Continuation, Image
		>;

		template
		<
			signed int Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = signed int
		>
		static constexpr Image a_signed_int_to_judgment = a_to_judgment
		<
			signed int, Value, Continuation, Image
		>;

		template
		<
			unsigned long Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = unsigned long
		>
		static constexpr Image a_unsigned_long_to_judgment = a_to_judgment
		<
			unsigned long, Value, Continuation, Image
		>;

		template
		<
			signed long Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = signed long
		>
		static constexpr Image a_signed_long_to_judgment = a_to_judgment
		<
			signed long, Value, Continuation, Image
		>;

		template
		<
			unsigned long long Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = unsigned long long
		>
		static constexpr Image a_unsigned_long_long_to_judgment = a_to_judgment
		<
			unsigned long long, Value, Continuation, Image
		>;

		template
		<
			signed long long Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = signed long long
		>
		static constexpr Image a_signed_long_long_to_judgment = a_to_judgment
		<
			signed long long, Value, Continuation, Image
		>;

	// char judgments:

		// symbolic:

		template
		<
			char Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_char_to_judgment = s_to_judgment<char, Value, Continuation>;

		template
		<
			wchar_t Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_wchar_t_to_judgment = s_to_judgment<wchar_t, Value, Continuation>;

		template
		<
			char16_t Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_char16_t_to_judgment = s_to_judgment<char16_t, Value, Continuation>;

		template
		<
			char32_t Value,
			typename Continuation = ch_s_grow_to_values
		>
		using s_char32_t_to_judgment = s_to_judgment<char32_t, Value, Continuation>;

		// assemblic:

		template
		<
			char Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = char
		>
		static constexpr Image a_char_to_judgment = a_to_judgment
		<
			char, Value, Continuation, Image
		>;

		template
		<
			wchar_t Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = wchar_t
		>
		static constexpr Image a_wchar_t_to_judgment = a_to_judgment
		<
			wchar_t, Value, Continuation, Image
		>;

		template
		<
			char16_t Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = char16_t
		>
		static constexpr Image a_char16_t_to_judgment = a_to_judgment
		<
			char16_t, Value, Continuation, Image
		>;

		template
		<
			char32_t Value,
			typename Continuation = ch_a_grow_to_value,
			typename Image = char32_t
		>
		static constexpr Image a_char32_t_to_judgment = a_to_judgment
		<
			char32_t, Value, Continuation, Image
		>;
};
