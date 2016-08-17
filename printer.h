/************************************************************************************************************************
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
************************************************************************************************************************/

#include<stdio.h>

namespace nik
{
	constexpr void *null_ptr=0;

	constexpr char endl='\n';

	template<typename S, typename T>
	const S & operator << (const S & s, const T & v)
	{
		s.print(v);

		return s;
	}

	struct builtin_printer
	{
		static void print(char v) { printf("%c", v); }
		static void print(signed char v) { printf("%c", v); }
		static void print(unsigned char v) { printf("%u", v); }
		static void print(wchar_t v) { printf("%c", v); }
		static void print(char16_t v) { printf("%u", v); }
		static void print(char32_t v) { printf("%u", v); }
		static void print(short v) { printf("%d", v); }
		static void print(unsigned short v) { printf("%u", v); }
		static void print(int v) { printf("%d", v); }
		static void print(unsigned int v) { printf("%u", v); }
		static void print(long v) { printf("%ld", v); }
		static void print(unsigned long v) { printf("%lu", v); }
		static void print(long long v) { printf("%lld", v); }
		static void print(unsigned long long v) { printf("%llu", v); }
		static void print(float v) { printf("%f", v); }
		static void print(double v) { printf("%f", v); }
		static void print(long double v) { printf("%Lf", v); }

		static void print(bool v) { printf("%s", v? "true" : "false"); }
		static void print(const char *v) { printf("%s", v); }

	} builtin;

	struct parameter_printer
	{
		template<typename size_type, size_type... params>
		struct unroll { };

		template<typename size_type, size_type current, size_type... params>
		struct unroll<size_type, current, params...>
		{
			static void print()
			{
				builtin_printer::print(current);
				builtin_printer::print(' ');
				unroll<size_type, params...>::print();
			}
		};

		template<typename size_type>
		struct unroll<size_type>
		{
			static void print()
			{
				builtin_printer::print('\n');
			}
		};

		template<typename size_type, size_type... params>
		static void print()
		{
			unroll<size_type, params...>::print();
		}
	};

	struct verbatim_printer : public builtin_printer
	{
		using builtin_printer::print;

		template<typename Container>
		static void print(const Container & c) { Container::verbatim(c); }

	} verbatim;

	struct display_printer : public builtin_printer
	{
		using builtin_printer::print;

		template<typename Container>
		static void print(const Container & c) { Container::display(c); }

	} display;
}

