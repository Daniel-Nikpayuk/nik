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
	#include nik_symbolic_typedef(patronum, natural, kernel, judgment, inductor)

	template<typename Exp>
	using pattern_match_bool_judgment					= pattern_match_judgment<bool, Exp>;

	template<typename Exp>
	using pattern_match_char_judgment					= pattern_match_judgment<char, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_char_judgment				= pattern_match_judgment<unsigned char, Exp>;

	template<typename Exp>
	using pattern_match_signed_char_judgment				= pattern_match_judgment<signed char, Exp>;

	template<typename Exp>
	using pattern_match_wchar_t_judgment					= pattern_match_judgment<wchar_t, Exp>;

	template<typename Exp>
	using pattern_match_char16_t_judgment					= pattern_match_judgment<char16_t, Exp>;

	template<typename Exp>
	using pattern_match_char32_t_judgment					= pattern_match_judgment<char32_t, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_short_judgment				= pattern_match_judgment<unsigned short, Exp>;

	template<typename Exp>
	using pattern_match_signed_short_judgment				= pattern_match_judgment<signed short, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_int_judgment				= pattern_match_judgment<unsigned int, Exp>;

	template<typename Exp>
	using pattern_match_signed_int_judgment				= pattern_match_judgment<signed int, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_long_judgment				= pattern_match_judgment<unsigned long, Exp>;

	template<typename Exp>
	using pattern_match_signed_long_judgment				= pattern_match_judgment<signed long, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_long_long_judgment			= pattern_match_judgment<unsigned long long, Exp>;

	template<typename Exp>
	using pattern_match_signed_long_long_judgment				= pattern_match_judgment<signed long long, Exp>;

	// dependent judgment:

	template<typename Exp>
	using pattern_match_bool_dependent_judgment				= pattern_match_dependent_judgment<bool, Exp>;

	template<typename Exp>
	using pattern_match_char_dependent_judgment				= pattern_match_dependent_judgment<char, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_char_dependent_judgment			= pattern_match_dependent_judgment<unsigned char, Exp>;

	template<typename Exp>
	using pattern_match_signed_char_dependent_judgment			= pattern_match_dependent_judgment<signed char, Exp>;

	template<typename Exp>
	using pattern_match_wchar_t_dependent_judgment				= pattern_match_dependent_judgment<wchar_t, Exp>;

	template<typename Exp>
	using pattern_match_char16_t_dependent_judgment			= pattern_match_dependent_judgment<char16_t, Exp>;

	template<typename Exp>
	using pattern_match_char32_t_dependent_judgment			= pattern_match_dependent_judgment<char32_t, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_short_dependent_judgment			= pattern_match_dependent_judgment<unsigned short, Exp>;

	template<typename Exp>
	using pattern_match_signed_short_dependent_judgment			= pattern_match_dependent_judgment<signed short, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_int_dependent_judgment			= pattern_match_dependent_judgment<unsigned int, Exp>;

	template<typename Exp>
	using pattern_match_signed_int_dependent_judgment			= pattern_match_dependent_judgment<signed int, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_long_dependent_judgment			= pattern_match_dependent_judgment<unsigned long, Exp>;

	template<typename Exp>
	using pattern_match_signed_long_dependent_judgment			= pattern_match_dependent_judgment<signed long, Exp>;

	template<typename Exp>
	using pattern_match_unsigned_long_long_dependent_judgment		= pattern_match_dependent_judgment<unsigned long long, Exp>;

	template<typename Exp>
	using pattern_match_signed_long_long_dependent_judgment		= pattern_match_dependent_judgment<signed long long, Exp>;
};

