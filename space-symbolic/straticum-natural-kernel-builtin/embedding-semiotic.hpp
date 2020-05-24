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
	#include nik_symbolic_typedef(patronum, kernel, builtin, inductor)
	#include nik_symbolic_typedef(patronum, kernel, builtin, embedding)

	// builtin types to literal:

		// It would be preferrable to pass the string literals directly as a template parameter then to specialize
		// each type_to_string_literal directly (it would fit this library narrative design better), but only
		// C++20 and greater allow for it.

	static constexpr const char string_literal_bool[] = "bool";

	template<typename Continuation = ch_coinduct_value>
	using bool_literal = type_literal<bool, string_literal_bool, Continuation>;

	//

	static constexpr const char string_literal_char[] = "char";

	template<typename Continuation = ch_coinduct_value>
	using char_literal = type_literal<char, string_literal_char, Continuation>;

	//

	static constexpr const char string_literal_unsigned_char[] = "unsigned char";

	template<typename Continuation = ch_coinduct_value>
	using unsigned_char_literal = type_literal<unsigned char, string_literal_unsigned_char, Continuation>;

	//

	static constexpr const char string_literal_signed_char[] = "signed char";

	template<typename Continuation = ch_coinduct_value>
	using signed_char_literal = type_literal<signed char, string_literal_signed_char, Continuation>;

	//

	static constexpr const char string_literal_wchar_t[] = "wchar_t";

	template<typename Continuation = ch_coinduct_value>
	using wchar_t_literal = type_literal<wchar_t, string_literal_wchar_t, Continuation>;

	//

	static constexpr const char string_literal_char16_t[] = "char16_t";

	template<typename Continuation = ch_coinduct_value>
	using char16_t_literal = type_literal<char16_t, string_literal_char16_t, Continuation>;

	//

	static constexpr const char string_literal_char32_t[] = "char32_t";

	template<typename Continuation = ch_coinduct_value>
	using char32_t_literal = type_literal<char32_t, string_literal_char32_t, Continuation>;

	//

	static constexpr const char string_literal_unsigned_short[] = "unsigned short";

	template<typename Continuation = ch_coinduct_value>
	using unsigned_short_literal = type_literal<unsigned short, string_literal_unsigned_short, Continuation>;

	//

	static constexpr const char string_literal_signed_short[] = "signed short";

	template<typename Continuation = ch_coinduct_value>
	using signed_short_literal = type_literal<signed short, string_literal_signed_short, Continuation>;

	//

	static constexpr const char string_literal_unsigned_int[] = "unsigned int";

	template<typename Continuation = ch_coinduct_value>
	using unsigned_int_literal = type_literal<unsigned int, string_literal_unsigned_int, Continuation>;

	//

	static constexpr const char string_literal_signed_int[] = "signed int";

	template<typename Continuation = ch_coinduct_value>
	using signed_int_literal = type_literal<signed int, string_literal_signed_int, Continuation>;

	//

	static constexpr const char string_literal_unsigned_long[] = "unsigned long";

	template<typename Continuation = ch_coinduct_value>
	using unsigned_long_literal = type_literal<unsigned long, string_literal_unsigned_long, Continuation>;

	//

	static constexpr const char string_literal_signed_long[] = "signed long";

	template<typename Continuation = ch_coinduct_value>
	using signed_long_literal = type_literal<signed long, string_literal_signed_long, Continuation>;

	//

	static constexpr const char string_literal_unsigned_long_long[] = "unsigned long long";

	template<typename Continuation = ch_coinduct_value>
	using unsigned_long_long_literal = type_literal<unsigned long long, string_literal_unsigned_long_long, Continuation>;

	//

	static constexpr const char string_literal_signed_long_long[] = "signed long long";

	template<typename Continuation = ch_coinduct_value>
	using signed_long_long_literal = type_literal<signed long long, string_literal_signed_long_long, Continuation>;
};

