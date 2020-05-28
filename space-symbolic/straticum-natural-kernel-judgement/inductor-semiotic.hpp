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
	template<auto Value> using bool_pattern_match_value			= typename dependent_memoization<bool>::template
										  pattern_match_values<Value>;

	template<auto Value> using bool_pattern_match_value			= typename dependent_memoization<bool>::template
										  pattern_match_values<Value>;

	template<auto Value> using char_pattern_match_value			= typename dependent_memoization<char>::template
										  pattern_match_values<Value>;

	template<auto Value> using unsigned_pattern_match_coinduct_value	= typename dependent_memoization<unsigned char>::template
										  pattern_match_values<Value>;

	template<auto Value> using signed_pattern_match_coinduct_value		= typename dependent_memoization<signed char>::template
										  pattern_match_values<Value>;

	template<auto Value> using wchar_pattern_match_coinduct_value		= typename dependent_memoization<wchar_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using char16_pattern_match_coinduct_value		= typename dependent_memoization<char16_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using char32_pattern_match_coinduct_value		= typename dependent_memoization<char32_t>::template
										  pattern_match_values<Value>;

	template<auto Value> using unsigned_pattern_match_coinduct_value	= typename dependent_memoization<unsigned short>::template
										  pattern_match_values<Value>;

	template<auto Value> using signed_pattern_match_coinduct_value		= typename dependent_memoization<signed short>::template
										  pattern_match_values<Value>;

	template<auto Value> using unsigned_pattern_match_coinduct_value	= typename dependent_memoization<unsigned int>::template
										  pattern_match_values<Value>;

	template<auto Value> using signed_pattern_match_coinduct_value		= typename dependent_memoization<signed int>::template
										  pattern_match_values<Value>;

	template<auto Value> using unsigned_pattern_match_coinduct_value	= typename dependent_memoization<unsigned long>::template
										  pattern_match_values<Value>;

	template<auto Value> using signed_pattern_match_coinduct_value		= typename dependent_memoization<signed long>::template
										  pattern_match_values<Value>;

	template<auto Value> using unsigned_pattern_match_long_coinduct_value	= typename dependent_memoization<unsigned long long>::template
										  pattern_match_values<Value>;

	template<auto Value> using signed_pattern_match_long_coinduct_value	= typename dependent_memoization<signed long long>::template
										  pattern_match_values<Value>;
};

