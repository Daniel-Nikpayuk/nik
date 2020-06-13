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

		template<typename, typename = filler> struct type_to_literal;

		template<typename Filler>
		struct type_to_literal<bool, Filler>
		{
			static constexpr const char string_literal[] = "bool";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<char, Filler>
		{
			static constexpr const char string_literal[] = "char";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<unsigned char, Filler>
		{
			static constexpr const char string_literal[] = "unsigned char";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<signed char, Filler>
		{
			static constexpr const char string_literal[] = "signed char";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<wchar_t, Filler>
		{
			static constexpr const char string_literal[] = "wchar_t";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<char16_t, Filler>
		{
			static constexpr const char string_literal[] = "char16_t";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<char32_t, Filler>
		{
			static constexpr const char string_literal[] = "char32_t";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<unsigned short, Filler>
		{
			static constexpr const char string_literal[] = "unsigned short";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<signed short, Filler>
		{
			static constexpr const char string_literal[] = "signed short";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<unsigned int, Filler>
		{
			static constexpr const char string_literal[] = "unsigned int";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<signed int, Filler>
		{
			static constexpr const char string_literal[] = "signed int";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<unsigned long, Filler>
		{
			static constexpr const char string_literal[] = "unsigned long";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<signed long, Filler>
		{
			static constexpr const char string_literal[] = "signed long";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<unsigned long long, Filler>
		{
			static constexpr const char string_literal[] = "unsigned long long";

			template<typename Type> static constexpr Type result = string_literal;
		};

		template<typename Filler>
		struct type_to_literal<signed long long, Filler>
		{
			static constexpr const char string_literal[] = "signed long long";

			template<typename Type> static constexpr Type result = string_literal;
		};

	// symbolic:

/*
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
*/

	// assemblic:

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_bool_literal = a_type_literal
		<
			bool, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_char_literal = a_type_literal
		<
			char, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_char_literal = a_type_literal
		<
			unsigned char, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_signed_char_literal = a_type_literal
		<
			signed char, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_wchar_t_literal = a_type_literal
		<
			wchar_t, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_char16_t_literal = a_type_literal
		<
			char16_t, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_char32_t_literal = a_type_literal
		<
			char32_t, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_short_literal = a_type_literal
		<
			unsigned short, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_signed_short_literal = a_type_literal
		<
			signed short, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_int_literal = a_type_literal
		<
			unsigned int, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_signed_int_literal = a_type_literal
		<
			signed int, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_long_literal = a_type_literal
		<
			unsigned long, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_signed_long_literal = a_type_literal
		<
			signed long, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_unsigned_long_long_literal = a_type_literal
		<
			unsigned long long, Op, Continuation, ListType, Image
		>;

		template
		<
			template<typename> class Op = type_to_literal,
			typename Continuation = ch_a_to_value,
			template<typename...> class ListType = independent_memoization::template pattern_match_types,
			typename Image = const char*
		>
		static constexpr Image a_signed_long_long_literal = a_type_literal
		<
			signed long long, Op, Continuation, ListType, Image
		>;
};
