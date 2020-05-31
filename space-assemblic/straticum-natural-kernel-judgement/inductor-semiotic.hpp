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
	// implemented at a lower level for performance:

	template<auto Value> using pattern_match_char_value			= typename dependent_memoization<char>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_char_value		= typename dependent_memoization<unsigned char>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_char_value		= typename dependent_memoization<signed char>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_wchar_t_value			= typename dependent_memoization<wchar_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_char16_t_value			= typename dependent_memoization<char16_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_char32_t_value			= typename dependent_memoization<char32_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_short_value		= typename dependent_memoization<unsigned short>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_short_value		= typename dependent_memoization<signed short>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_int_value		= typename dependent_memoization<unsigned int>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_int_value		= typename dependent_memoization<signed int>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_long_value		= typename dependent_memoization<unsigned long>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_long_value		= typename dependent_memoization<signed long>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_unsigned_long_long_value	= typename dependent_memoization<unsigned long long>::template
										  pattern_match_values<Value>;

	template<auto Value> using pattern_match_signed_long_long_value		= typename dependent_memoization<signed long long>::template
										  pattern_match_values<Value>;
};

