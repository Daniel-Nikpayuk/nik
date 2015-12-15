/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

#ifndef CONTEXT_META_NUMERIC_LIMITS_H
#define CONTEXT_META_NUMERIC_LIMITS_H

#include<climits>
#include<cfloat>

namespace nik
{
	namespace context
	{
		namespace meta
		{
/*
		taken from: http://en.cppreference.com/w/cpp/types/numeric_limits
*/
			template<typename SizeType> struct numeric_limits { static SizeType max() { return CHAR_MAX; } };

			template<> struct numeric_limits<char> { static char max() { return CHAR_MAX; } };
			template<> struct numeric_limits<signed char> { static signed char max() { return SCHAR_MAX; } };
			template<> struct numeric_limits<unsigned char> { static unsigned char max() { return UCHAR_MAX; } };
			template<> struct numeric_limits<wchar_t> { static wchar_t max() { return WCHAR_MAX; } };
			template<> struct numeric_limits<char16_t> { static char16_t max() { return UINT_LEAST16_MAX; } };
			template<> struct numeric_limits<char32_t> { static char32_t max() { return UINT_LEAST32_MAX; } };
			template<> struct numeric_limits<short> { static short max() { return SHRT_MAX; } };
//	redundant:
//			template<> struct numeric_limits<signed short> { static signed short max() { return SHRT_MAX; } };
			template<> struct numeric_limits<unsigned short> { static unsigned short max() { return USHRT_MAX; } };
			template<> struct numeric_limits<int> { static int max() { return INT_MAX; } };
//	redundant:
//			template<> struct numeric_limits<signed int> { static signed int max() { return INT_MAX; } };
			template<> struct numeric_limits<unsigned int> { static unsigned int max() { return UINT_MAX; } };
			template<> struct numeric_limits<long> { static long max() { return LONG_MAX; } };
//	redundant:
//			template<> struct numeric_limits<signed long> { static signed long max() { return LONG_MAX; } };
			template<> struct numeric_limits<unsigned long> { static unsigned long max() { return ULONG_MAX; } };
			template<> struct numeric_limits<long long> { static long long max() { return LLONG_MAX; } };
//	redundant:
//			template<> struct numeric_limits<signed long long> { static signed long long max() { return LLONG_MAX	; } };
			template<> struct numeric_limits<unsigned long long> { static unsigned long long max() { return ULLONG_MAX; } };
			template<> struct numeric_limits<float> { static float max() { return FLT_MAX; } };
			template<> struct numeric_limits<double> { static double max() { return DBL_MAX; } };
			template<> struct numeric_limits<long double> { static long double max() { return LDBL_MAX; } };
		}
	}
}

#endif
