/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef NIK_NUMERIC_PROCESSOR_PARAMETER_LIMITS_H
#define NIK_NUMERIC_PROCESSOR_PARAMETER_LIMITS_H

#include<climits>
#include<cfloat>

/*
	limits: (taken from: http://en.cppreference.com/w/cpp/types/limits)

	Differs from processor limits in that the emphasis is on templates (meta),
	which is to say: typological information. Processor orients its information around processor limits.

	Is defaulting to "char" a best policy?
*/

namespace nik
{
 namespace numeric
 {
  namespace processor
  {
   namespace parameter
   {
/*
	default:
*/
	template<typename SizeType>
	struct limits
	{
		typedef SizeType size_type;

		static const size_type max=CHAR_MAX;
	};
/*
	specializations:
*/
	template<>
	struct limits<char>
		{ static const char max=CHAR_MAX; };
	template<>
	struct limits<signed char>
		{ static const signed char max=SCHAR_MAX; };
	template<>
	struct limits<unsigned char>
		{ static const unsigned char max=UCHAR_MAX; };
	template<>
	struct limits<wchar_t>
		{ static const wchar_t max=WCHAR_MAX; };
	template<>
	struct limits<char16_t>
		{ static const char16_t max=UINT_LEAST16_MAX; };
	template<>
	struct limits<char32_t>
		{ static const char32_t max=UINT_LEAST32_MAX; };
	template<>
	struct limits<short>
		{ static const short max=SHRT_MAX; };
/*
		redundant:
	template<>
	struct limits<signed short>
		{ static const signed short max=SHRT_MAX; };
*/
	template<>
	struct limits<unsigned short>
		{ static const unsigned short max=USHRT_MAX; };
	template<>
	struct limits<int>
		{ static const int max=INT_MAX; };
/*
		redundant:
	template<>
	struct limits<signed int>
		{ static const signed int max=INT_MAX; };
*/
	template<>
	struct limits<unsigned int>
		{ static const unsigned int max=UINT_MAX; };
	template<>
	struct limits<long>
		{ static const long max=LONG_MAX; };
/*
		redundant:
	template<>
	struct limits<signed long>
		{ static const signed long max=LONG_MAX; };
*/
	template<>
	struct limits<unsigned long>
		{ static const unsigned long max=ULONG_MAX; };
	template<>
	struct limits<long long>
		{ static const long long max=LLONG_MAX; };
/*
		redundant:
	template<>
	struct limits<signed long long>
		{ static const signed long long max=LLONG_MAX	; };
*/
	template<>
	struct limits<unsigned long long>
		{ static const unsigned long long max=ULLONG_MAX; };
	template<>
	struct limits<float>
		{ static constexpr float max=FLT_MAX; };
	template<>
	struct limits<double>
		{ static constexpr double max=DBL_MAX; };
	template<>
	struct limits<long double>
		{ static constexpr long double max=LDBL_MAX; };
   }
  }
 }
}

#endif
