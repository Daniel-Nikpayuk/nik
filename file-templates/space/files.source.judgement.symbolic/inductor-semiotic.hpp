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

struct inductor
{
	#include nik_symbolic_typedef(patronum, natural, kernel, judgement, inductor)

	template<typename Exp>
	using pattern_match_bool_judgement					= pattern_match_judgement<bool, Exp>;

	template<typename Exp>
	using pattern_match_char_judgement					= pattern_match_judgement<char, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_char_judgement				= pattern_match_judgement<unsigned char, Exp>;

	template<typename Exp>
	using pattern_match_signed_char_judgement				= pattern_match_judgement<signed char, Exp>;

	template<typename Exp>
	using pattern_match_wchar_t_judgement					= pattern_match_judgement<wchar_t, Exp>;

	template<typename Exp>
	using pattern_match_char16_t_judgement					= pattern_match_judgement<char16_t, Exp>;

	template<typename Exp>
	using pattern_match_char32_t_judgement					= pattern_match_judgement<char32_t, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_short_judgement				= pattern_match_judgement<unsigned short, Exp>;

	template<typename Exp>
	using pattern_match_signed_short_judgement				= pattern_match_judgement<signed short, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_int_judgement				= pattern_match_judgement<unsigned int, Exp>;

	template<typename Exp>
	using pattern_match_signed_int_judgement				= pattern_match_judgement<signed int, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_long_judgement				= pattern_match_judgement<unsigned long, Exp>;

	template<typename Exp>
	using pattern_match_signed_long_judgement				= pattern_match_judgement<signed long, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_long_long_judgement			= pattern_match_judgement<unsigned long long, Exp>;

	template<typename Exp>
	using pattern_match_signed_long_long_judgement				= pattern_match_judgement<signed long long, Exp>;

	// dependent judgement:

	template<typename Exp>
	using pattern_match_bool_dependent_judgement				= pattern_match_dependent_judgement<bool, Exp>;

	template<typename Exp>
	using pattern_match_char_dependent_judgement				= pattern_match_dependent_judgement<char, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_char_dependent_judgement			= pattern_match_dependent_judgement<unsigned char, Exp>;

	template<typename Exp>
	using pattern_match_signed_char_dependent_judgement			= pattern_match_dependent_judgement<signed char, Exp>;

	template<typename Exp>
	using pattern_match_wchar_t_dependent_judgement				= pattern_match_dependent_judgement<wchar_t, Exp>;

	template<typename Exp>
	using pattern_match_char16_t_dependent_judgement			= pattern_match_dependent_judgement<char16_t, Exp>;

	template<typename Exp>
	using pattern_match_char32_t_dependent_judgement			= pattern_match_dependent_judgement<char32_t, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_short_dependent_judgement			= pattern_match_dependent_judgement<unsigned short, Exp>;

	template<typename Exp>
	using pattern_match_signed_short_dependent_judgement			= pattern_match_dependent_judgement<signed short, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_int_dependent_judgement			= pattern_match_dependent_judgement<unsigned int, Exp>;

	template<typename Exp>
	using pattern_match_signed_int_dependent_judgement			= pattern_match_dependent_judgement<signed int, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_long_dependent_judgement			= pattern_match_dependent_judgement<unsigned long, Exp>;

	template<typename Exp>
	using pattern_match_signed_long_dependent_judgement			= pattern_match_dependent_judgement<signed long, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_long_long_dependent_judgement		= pattern_match_dependent_judgement<unsigned long long, Exp>;

	template<typename Exp>
	using pattern_match_signed_long_long_dependent_judgement		= pattern_match_dependent_judgement<signed long long, Exp>;
};

