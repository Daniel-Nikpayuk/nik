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
	#include nik_symbolic_typedef(patronum, kernel, builtin, inductor)

	// builtin types:

	template<typename Exp> using bool_coinduct_type			= typename dependent_memoization<bool>::template
									  coinduct_type<Exp>;

	template<auto Value> using bool_coinduct_value			= typename dependent_memoization<bool>::template
									  coinduct_values<Value>;

	template<typename Exp> using char_coinduct_type			= typename dependent_memoization<char>::template
									  coinduct_type<Exp>;

	template<auto Value> using char_coinduct_value			= typename dependent_memoization<char>::template
									  coinduct_values<Value>;

	template<typename Exp> using unsigned_char_coinduct_type	= typename dependent_memoization<unsigned char>::template
									  coinduct_type<Exp>;

	template<auto Value> using unsigned_char_coinduct_value		= typename dependent_memoization<unsigned char>::template
									  coinduct_values<Value>;

	template<typename Exp> using signed_char_coinduct_type		= typename dependent_memoization<signed char>::template
									  coinduct_type<Exp>;

	template<auto Value> using signed_char_coinduct_value		= typename dependent_memoization<signed char>::template
									  coinduct_values<Value>;

	template<typename Exp> using wchar_t_coinduct_type		= typename dependent_memoization<wchar_t>::template
									  coinduct_type<Exp>;

	template<auto Value> using wchar_t_coinduct_value		= typename dependent_memoization<wchar_t>::template
									  coinduct_values<Value>;

	template<typename Exp> using char16_t_coinduct_type		= typename dependent_memoization<char16_t>::template
									  coinduct_type<Exp>;

	template<auto Value> using char16_t_coinduct_value		= typename dependent_memoization<char16_t>::template
									  coinduct_values<Value>;

	template<typename Exp> using char32_t_coinduct_type		= typename dependent_memoization<char32_t>::template
									  coinduct_type<Exp>;

	template<auto Value> using char32_t_coinduct_value		= typename dependent_memoization<char32_t>::template
									  coinduct_values<Value>;

	template<typename Exp> using unsigned_short_coinduct_type	= typename dependent_memoization<unsigned short>::template
									  coinduct_type<Exp>;

	template<auto Value> using unsigned_short_coinduct_value	= typename dependent_memoization<unsigned short>::template
									  coinduct_values<Value>;

	template<typename Exp> using signed_short_coinduct_type		= typename dependent_memoization<signed short>::template
									  coinduct_type<Exp>;

	template<auto Value> using signed_short_coinduct_value		= typename dependent_memoization<signed short>::template
									  coinduct_values<Value>;

	template<typename Exp> using unsigned_int_coinduct_type		= typename dependent_memoization<unsigned int>::template
									  coinduct_type<Exp>;

	template<auto Value> using unsigned_int_coinduct_value		= typename dependent_memoization<unsigned int>::template
									  coinduct_values<Value>;

	template<typename Exp> using signed_int_coinduct_type		= typename dependent_memoization<signed int>::template
									  coinduct_type<Exp>;

	template<auto Value> using signed_int_coinduct_value		= typename dependent_memoization<signed int>::template
									  coinduct_values<Value>;

	template<typename Exp> using unsigned_long_coinduct_type	= typename dependent_memoization<unsigned long>::template
									  coinduct_type<Exp>;

	template<auto Value> using unsigned_long_coinduct_value		= typename dependent_memoization<unsigned long>::template
									  coinduct_values<Value>;

	template<typename Exp> using signed_long_coinduct_type		= typename dependent_memoization<signed long>::template
									  coinduct_type<Exp>;

	template<auto Value> using signed_long_coinduct_value		= typename dependent_memoization<signed long>::template
									  coinduct_values<Value>;

	template<typename Exp> using unsigned_long_long_coinduct_type	= typename dependent_memoization<unsigned long long>::template
									  coinduct_type<Exp>;

	template<auto Value> using unsigned_long_long_coinduct_value	= typename dependent_memoization<unsigned long long>::template
									  coinduct_values<Value>;

	template<typename Exp> using signed_long_long_coinduct_type	= typename dependent_memoization<signed long long>::template
									  coinduct_type<Exp>;

	template<auto Value> using signed_long_long_coinduct_value	= typename dependent_memoization<signed long long>::template
									  coinduct_values<Value>;
};

