/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

struct functor
{
	using kind						= module;

	using type						= functor;

	#include nik_typedef(calculus, parameter, constant, module)
	#include nik_typedef(calculus, parameter, constant, structure)

/*
	char:
*/

	inline static void display(const constant<char> &)
	{
		printf("%s", "char");
	}

	template<char Value>
	inline static void display(const constant<char, Value> &)
	{
		printf("%s", "char: ");
		printf("%c", Value);
	}

/*
	signed char:
*/

	inline static void display(const constant<signed char> &)
	{
		printf("%s", "signed char");
	}

	template<signed char Value>
	inline static void display(const constant<signed char, Value> &)
	{
		printf("%s", "signed char: ");
		printf("%c", Value);
	}

/*
	unsigned char:
*/

	inline static void display(const constant<unsigned char> &)
	{
		printf("%s", "unsigned char");
	}

	template<unsigned char Value>
	inline static void display(const constant<unsigned char, Value> &)
	{
		printf("%s", "unsigned char: ");
		printf("%u", Value);
	}

/*
	wchar_t:
*/

	inline static void display(const constant<wchar_t> &)
	{
		printf("%s", "wchar_t");
	}

	template<wchar_t Value>
	inline static void display(const constant<wchar_t, Value> &)
	{
		printf("%s", "wchar_t: ");
		printf("%c", Value);
	}

/*
	char16_t:
*/

	inline static void display(const constant<char16_t> &)
	{
		printf("%s", "char16_t");
	}

	template<char16_t Value>
	inline static void display(const constant<char16_t, Value> &)
	{
		printf("%s", "char16_t: ");
		printf("%u", Value);
	}

/*
	char32_t:
*/

	inline static void display(const constant<char32_t> &)
	{
		printf("%s", "char32_t");
	}

	template<char32_t Value>
	inline static void display(const constant<char32_t, Value> &)
	{
		printf("%s", "char32_t: ");
		printf("%u", Value);
	}

/*
	short:
*/

	inline static void display(const constant<short> &)
	{
		printf("%s", "short");
	}

	template<short Value>
	inline static void display(const constant<short, Value> &)
	{
		printf("%s", "short: ");
		printf("%d", Value);
	}

/*
	unsigned short:
*/

	inline static void display(const constant<unsigned short> &)
	{
		printf("%s", "unsigned short");
	}

	template<unsigned short Value>
	inline static void display(const constant<unsigned short, Value> &)
	{
		printf("%s", "unsigned short: ");
		printf("%u", Value);
	}

/*
	int:
*/

	inline static void display(const constant<int> &)
	{
		printf("%s", "int");
	}

	template<int Value>
	inline static void display(const constant<int, Value> &)
	{
		printf("%s", "int: ");
		printf("%d", Value);
	}

/*
	unsigned int:
*/

	inline static void display(const constant<unsigned int> &)
	{
		printf("%s", "unsigned int");
	}

	template<unsigned int Value>
	inline static void display(const constant<unsigned int, Value> &)
	{
		printf("%s", "unsigned int: ");
		printf("%u", Value);
	}

/*
	long:
*/

	inline static void display(const constant<long> &)
	{
		printf("%s", "long");
	}

	template<long Value>
	inline static void display(const constant<long, Value> &)
	{
		printf("%s", "long: ");
		printf("%ld", Value);
	}

/*
	unsigned long:
*/

	inline static void display(const constant<unsigned long> &)
	{
		printf("%s", "unsigned long");
	}

	template<unsigned long Value>
	inline static void display(const constant<unsigned long, Value> &)
	{
		printf("%s", "unsigned long: ");
		printf("%lu", Value);
	}

/*
	long long:
*/

	inline static void display(const constant<long long> &)
	{
		printf("%s", "long long");
	}

	template<long long Value>
	inline static void display(const constant<long long, Value> &)
	{
		printf("%s", "long long: ");
		printf("%lld", Value);
	}

/*
	unsigned long long:
*/

	inline static void display(const constant<unsigned long long> &)
	{
		printf("%s", "unsigned long long");
	}

	template<unsigned long long Value>
	inline static void display(const constant<unsigned long long, Value> &)
	{
		printf("%s", "unsigned long long: ");
		printf("%llu", Value);
	}

/*
	float: is not valid as a template parameter.
*/

	inline static void display(const constant<float> &)
	{
		printf("%s", "float");
	}

/*
	template<float Value>
	inline static void display(const constant<float, Value> &)
	{
		printf("%s", "float: ");
		printf("%f", Value);
	}
*/

/*
	double: is not valid as a template parameter.
*/

	inline static void display(const constant<double> &)
	{
		printf("%s", "double");
	}

/*
	template<double Value>
	inline static void display(const constant<double, Value> &)
	{
		printf("%s", "double: ");
		printf("%f", Value);
	}
*/

/*
	long double: is not valid as a template parameter.
*/

	inline static void display(const constant<long double> &)
	{
		printf("%s", "long double");
	}

/*
	template<long double Value>
	inline static void display(const constant<long double, Value> &)
	{
		printf("%s", "long double: ");
		printf("%Lf", Value);
	}
*/

/***********************************************************************************************************************/

/*
	bool:
*/

	inline static void display(const constant<bool> &)
	{
		printf("%s", "bool");
	}

	template<bool Value>
	inline static void display(const constant<bool, Value> &)
	{
		printf("%s", "bool: ");
		printf("%s", Value ? "true" : "false");
	}

/*
	char * const: is not valid as a template parameter. ?
*/

	inline static void display(const constant<char * const> &)
	{
		printf("%s", "char * const");
	}

/*
	template<char * const Value>
	inline static void display(const constant<char * const, Value> &)
	{
		printf("%s", "char * const: ");
		printf("%s", Value);
	}
*/
};

