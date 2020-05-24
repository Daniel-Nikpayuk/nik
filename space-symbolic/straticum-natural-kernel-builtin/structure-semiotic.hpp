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
	#include nik_symbolic_typedef(patronum, kernel, builtin, structure)

	// builtin judgements:

	template<bool Value>			using make_bool_judgement			= make_judgement<bool, Value>;
	template<char Value>			using make_char_judgement			= make_judgement<char, Value>;
	template<unsigned char Value>		using make_unsigned_char_judgement		= make_judgement<unsigned char, Value>;
	template<signed char Value>		using make_signed_char_judgement		= make_judgement<signed char, Value>;
	template<wchar_t Value>			using make_wchar_t_judgement			= make_judgement<wchar_t, Value>;
	template<char16_t Value>		using make_char16_t_judgement			= make_judgement<char16_t, Value>;
	template<char32_t Value>		using make_char32_t_judgement			= make_judgement<char32_t, Value>;
	template<unsigned short Value>		using make_unsigned_short_judgement		= make_judgement<unsigned short, Value>;
	template<signed short Value>		using make_signed_short_judgement		= make_judgement<signed short, Value>;
	template<unsigned int Value>		using make_unsigned_int_judgement		= make_judgement<unsigned int, Value>;
	template<signed int Value>		using make_signed_int_judgement			= make_judgement<signed int, Value>;
	template<unsigned long Value>		using make_unsigned_long_judgement		= make_judgement<unsigned long, Value>;
	template<signed long Value>		using make_signed_long_judgement		= make_judgement<signed long, Value>;
	template<unsigned long long Value>	using make_unsigned_long_long_judgement		= make_judgement<unsigned long long, Value>;
	template<signed long long Value>	using make_signed_long_long_judgement		= make_judgement<signed long long, Value>;
};

