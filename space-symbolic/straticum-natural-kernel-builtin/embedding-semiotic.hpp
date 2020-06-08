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

struct embedding
{
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, natural, kernel, builtin, embedding)

	// builtin types to literal:

		// It would be preferrable to pass the string literals directly as a template parameter then to specialize
		// each type_to_string_literal directly (it would fit this library narrative design better), but only
		// C++20 and greater allow for it.

		static constexpr const char string_literal_bool[]			= "bool";
		static constexpr const char string_literal_char[]			= "char";
		static constexpr const char string_literal_unsigned_char[]		= "unsigned char";
		static constexpr const char string_literal_signed_char[]		= "signed char";
		static constexpr const char string_literal_wchar_t[]			= "wchar_t";
		static constexpr const char string_literal_char16_t[]			= "char16_t";
		static constexpr const char string_literal_char32_t[]			= "char32_t";
		static constexpr const char string_literal_unsigned_short[]		= "unsigned short";
		static constexpr const char string_literal_signed_short[]		= "signed short";
		static constexpr const char string_literal_unsigned_int[]		= "unsigned int";
		static constexpr const char string_literal_signed_int[]			= "signed int";
		static constexpr const char string_literal_unsigned_long[]		= "unsigned long";
		static constexpr const char string_literal_signed_long[]		= "signed long";
		static constexpr const char string_literal_unsigned_long_long[]		= "unsigned long long";
		static constexpr const char string_literal_signed_long_long[]		= "signed long long";

	// symbolic:

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_bool_literal = s_type_literal
		<
			bool, string_literal_bool, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_char_literal = s_type_literal
		<
			char, string_literal_char, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_unsigned_char_literal = s_type_literal
		<
			unsigned char, string_literal_unsigned_char, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_char_literal = s_type_literal
		<
			signed char, string_literal_signed_char, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_wchar_t_literal = s_type_literal
		<
			wchar_t, string_literal_wchar_t, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_char16_t_literal = s_type_literal
		<
			char16_t, string_literal_char16_t, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_char32_t_literal = s_type_literal
		<
			char32_t, string_literal_char32_t, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_unsigned_short_literal = s_type_literal
		<
			unsigned short, string_literal_unsigned_short, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_short_literal = s_type_literal
		<
			signed short, string_literal_signed_short, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_unsigned_int_literal = s_type_literal
		<
			unsigned int, string_literal_unsigned_int, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_int_literal = s_type_literal
		<
			signed int, string_literal_signed_int, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_unsigned_long_literal = s_type_literal
		<
			unsigned long, string_literal_unsigned_long, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_long_literal = s_type_literal
		<
			signed long, string_literal_signed_long, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_unsigned_long_long_literal = s_type_literal
		<
			unsigned long long, string_literal_unsigned_long_long, Continuation, Memoizer
		>;

		template
		<
			typename Continuation = ch_symbolic_values,
			template<typename> class Memoizer = dependent_memoization
		>
		using s_signed_long_long_literal = s_type_literal
		<
			signed long long, string_literal_signed_long_long, Continuation, Memoizer
		>;

	// assemblic:

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_bool_literal = a_type_literal
		<
			bool, string_literal_bool, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_char_literal = a_type_literal
		<
			char, string_literal_char, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_char_literal = a_type_literal
		<
			unsigned char, string_literal_unsigned_char, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_signed_char_literal = a_type_literal
		<
			signed char, string_literal_signed_char, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_wchar_t_literal = a_type_literal
		<
			wchar_t, string_literal_wchar_t, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_char16_t_literal = a_type_literal
		<
			char16_t, string_literal_char16_t, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_char32_t_literal = a_type_literal
		<
			char32_t, string_literal_char32_t, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_short_literal = a_type_literal
		<
			unsigned short, string_literal_unsigned_short, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_signed_short_literal = a_type_literal
		<
			signed short, string_literal_signed_short, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_int_literal = a_type_literal
		<
			unsigned int, string_literal_unsigned_int, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_signed_int_literal = a_type_literal
		<
			signed int, string_literal_signed_int, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_long_literal = a_type_literal
		<
			unsigned long, string_literal_unsigned_long, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_signed_long_literal = a_type_literal
		<
			signed long, string_literal_signed_long, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_long_long_literal = a_type_literal
		<
			unsigned long long, string_literal_unsigned_long_long, Continuation, Image
		>;

		template
		<
			typename Continuation = ch_assemblic_value,
			typename Image = const char*
		>
		static constexpr Image a_signed_long_long_literal = a_type_literal
		<
			signed long long, string_literal_signed_long_long, Continuation, Image
		>;
};
