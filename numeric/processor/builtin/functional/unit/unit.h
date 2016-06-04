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

#ifndef NIK_NUMERIC_PROCESSOR_BUILTIN_FUNCTIONAL_UNIT_H
#define NIK_NUMERIC_PROCESSOR_BUILTIN_FUNCTIONAL_UNIT_H

#include<climits>
#include<cfloat>

#include"../meta/meta.h"

/*
	limits: (taken from: http://en.cppreference.com/w/cpp/types/limits)

	char
	signed char
	unsigned char
	wchar_t
	char16_t
	char32_t
	short
		signed short // redundant
	unsigned short
	int
		signed int // redundant
	unsigned int
	long
		signed long // redundant
	unsigned long
	long long
		signed long long // redundant
	unsigned long long
	float
	double
	long double
*/

namespace nik
{
 namespace numeric
 {
  namespace processor
  {
   namespace builtin
   {
    namespace functional
    {
/*
	default:
*/
	template<typename SizeType>
	struct unit
	{
		typedef SizeType size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic { };

		struct media { };
	};

/*
	specializations:
*/

	template<>
	struct unit<char>
	{
		typedef char size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=CHAR_MIN;
			static constexpr size_type max=CHAR_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<signed char>
	{
		typedef signed char size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=SCHAR_MIN;
			static constexpr size_type max=SCHAR_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<unsigned char>
	{
		typedef unsigned char size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=0;
			static constexpr size_type max=UCHAR_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<wchar_t>
	{
		typedef wchar_t size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=WCHAR_MIN;
			static constexpr size_type max=WCHAR_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<char16_t>
	{
		typedef char16_t size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=0;
			static constexpr size_type max=UINT_LEAST16_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<char32_t>
	{
		typedef char32_t size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=0;
			static constexpr size_type max=UINT_LEAST32_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<short>
	{
		typedef short size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=SHRT_MIN;
			static constexpr size_type max=SHRT_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

//	redundant: template<> struct unit<signed long long>;

	template<>
	struct unit<unsigned short>
	{
		typedef unsigned short size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=0;
			static constexpr size_type max=USHRT_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<int>
	{
		typedef int size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=INT_MIN;
			static constexpr size_type max=INT_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

//	redundant: template<> struct unit<signed long long>;

	template<>
	struct unit<unsigned int>
	{
		typedef unsigned int size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=0;
			static constexpr size_type max=UINT_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<long>
	{
		typedef long size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=LONG_MIN;
			static constexpr size_type max=LONG_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

//	redundant: template<> struct unit<signed long long>;

	template<>
	struct unit<unsigned long>
	{
		typedef unsigned long size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=0;
			static constexpr size_type max=ULONG_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<long long>
	{
		typedef long long size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=LLONG_MIN;
			static constexpr size_type max=LLONG_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

//	redundant: template<> struct unit<signed long long>;

	template<>
	struct unit<unsigned long long>
	{
		typedef unsigned long long size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=0;
			static constexpr size_type max=ULLONG_MAX;

			#include"semiotic.cpp"
		};

		struct media
		{
			#include"media.cpp"
		};
	};

	template<>
	struct unit<float>
	{
		typedef float size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=FLT_MIN;
			static constexpr size_type max=FLT_MAX;

//			#include"semiotic.cpp"
		};

		struct media
		{
//			#include"media.cpp"
		};
	};

	template<>
	struct unit<double>
	{
		typedef double size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=DBL_MIN;
			static constexpr size_type max=DBL_MAX;

//			#include"semiotic.cpp"
		};

		struct media
		{
//			#include"media.cpp"
		};
	};

	template<>
	struct unit<long double>
	{
		typedef long double size_type;

		typedef functional::meta<size_type> meta;

		struct semiotic
		{
			static constexpr size_type min=LDBL_MIN;
			static constexpr size_type max=LDBL_MAX;

//			#include"semiotic.cpp"
		};

		struct media
		{
//			#include"media.cpp"
		};
	};
    }
   }
  }
 }
}

#endif
