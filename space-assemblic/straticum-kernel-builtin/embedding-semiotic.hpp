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
	#include nik_assemblic_typedef(patronum, kernel, builtin, inductor)
	#include nik_assemblic_typedef(straticum, kernel, builtin, inductor)

	// builtin types literal:

	static constexpr const char string_literal_bool[] = "bool";

	template<typename Continuation>
	static constexpr const char* (*literal_bool)() =
	ch_inductor<bool>::template memoized_type<bool>::template induct
	<
		Continuation, string_literal_bool
	>;

	//

	static constexpr const char string_literal_char[] = "char";

	template<typename Continuation>
	static constexpr const char* (*literal_char)() =
	ch_inductor<char>::template memoized_type<char>::template induct
	<
		Continuation, string_literal_char
	>;

	//

	static constexpr const char string_literal_unsigned_char[] = "unsigned char";

	template<typename Continuation>
	static constexpr const char* (*literal_unsigned_char)() =
	ch_inductor<unsigned char>::template memoized_type<unsigned char>::template induct
	<
		Continuation, string_literal_unsigned_char
	>;

	//

	static constexpr const char string_literal_signed_char[] = "signed char";

	template<typename Continuation>
	static constexpr const char* (*literal_signed_char)() =
	ch_inductor<signed char>::template memoized_type<signed char>::template induct
	<
		Continuation, string_literal_signed_char
	>;

	//

	static constexpr const char string_literal_wchar_t[] = "wchar_t";

	template<typename Continuation>
	static constexpr const char* (*literal_wchar_t)() =
	ch_inductor<wchar_t>::template memoized_type<wchar_t>::template induct
	<
		Continuation, string_literal_wchar_t
	>;

	//

	static constexpr const char string_literal_char16_t[] = "char16_t";

	template<typename Continuation>
	static constexpr const char* (*literal_char16_t)() =
	ch_inductor<char16_t>::template memoized_type<char16_t>::template induct
	<
		Continuation, string_literal_char16_t
	>;

	//

	static constexpr const char string_literal_char32_t[] = "char32_t";

	template<typename Continuation>
	static constexpr const char* (*literal_char32_t)() =
	ch_inductor<char32_t>::template memoized_type<char32_t>::template induct
	<
		Continuation, string_literal_char32_t
	>;

	//

	static constexpr const char string_literal_unsigned_short[] = "unsigned short";

	template<typename Continuation>
	static constexpr const char* (*literal_unsigned_short)() =
	ch_inductor<unsigned short>::template memoized_type<unsigned short>::template induct
	<
		Continuation, string_literal_unsigned_short
	>;

	//

	static constexpr const char string_literal_signed_short[] = "signed short";

	template<typename Continuation>
	static constexpr const char* (*literal_signed_short)() =
	ch_inductor<signed short>::template memoized_type<signed short>::template induct
	<
		Continuation, string_literal_signed_short
	>;

	//

	static constexpr const char string_literal_unsigned_int[] = "unsigned int";

	template<typename Continuation>
	static constexpr const char* (*literal_unsigned_int)() =
	ch_inductor<unsigned int>::template memoized_type<unsigned int>::template induct
	<
		Continuation, string_literal_unsigned_int
	>;

	//

	static constexpr const char string_literal_signed_int[] = "signed int";

	template<typename Continuation>
	static constexpr const char* (*literal_signed_int)() =
	ch_inductor<signed int>::template memoized_type<signed int>::template induct
	<
		Continuation, string_literal_signed_int
	>;

	//

	static constexpr const char string_literal_unsigned_long[] = "unsigned long";

	template<typename Continuation>
	static constexpr const char* (*literal_unsigned_long)() =
	ch_inductor<unsigned long>::template memoized_type<unsigned long>::template induct
	<
		Continuation, string_literal_unsigned_long
	>;

	//

	static constexpr const char string_literal_signed_long[] = "signed long";

	template<typename Continuation>
	static constexpr const char* (*literal_signed_long)() =
	ch_inductor<signed long>::template memoized_type<signed long>::template induct
	<
		Continuation, string_literal_signed_long
	>;

	//

	static constexpr const char string_literal_unsigned_long_long[] = "unsigned long long";

	template<typename Continuation>
	static constexpr const char* (*literal_unsigned_long_long)() =
	ch_inductor<unsigned long long>::template memoized_type<unsigned long long>::template induct
	<
		Continuation, string_literal_unsigned_long_long
	>;

	//

	static constexpr const char string_literal_signed_long_long[] = "signed long long";

	template<typename Continuation>
	static constexpr const char* (*literal_signed_long_long)() =
	ch_inductor<signed long long>::template memoized_type<signed long long>::template induct
	<
		Continuation, string_literal_signed_long_long
	>;

	// void_ptr values:

	template<auto Value, typename Continuation>
	static void display_void_ptr() { printf("%p", memoized_void_ptr<Value>::template induct<Continuation>()); }
};

