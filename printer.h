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

namespace nik
{
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

	//

	template<typename T, typename Filler = void> struct type_printer;

	template<typename Filler>
	struct type_printer<char, Filler>
	{
		static void print() { builtin_printer::print("char"); }
	};

	template<typename Filler>
	struct type_printer<signed char, Filler>
	{
		static void print() { builtin_printer::print("signed char"); }
	};

	template<typename Filler>
	struct type_printer<unsigned char, Filler>
	{
		static void print() { builtin_printer::print("unsigned char"); }
	};

	template<typename Filler>
	struct type_printer<wchar_t, Filler>
	{
		static void print() { builtin_printer::print("wchar_t"); }
	};

	template<typename Filler>
	struct type_printer<char16_t, Filler>
	{
		static void print() { builtin_printer::print("char16_t"); }
	};

	template<typename Filler>
	struct type_printer<char32_t, Filler>
	{
		static void print() { builtin_printer::print("char32_t"); }
	};

	template<typename Filler>
	struct type_printer<short, Filler>
	{
		static void print() { builtin_printer::print("short"); }
	};

	template<typename Filler>
	struct type_printer<unsigned short, Filler>
	{
		static void print() { builtin_printer::print("unsigned short"); }
	};

	template<typename Filler>
	struct type_printer<int, Filler>
	{
		static void print() { builtin_printer::print("int"); }
	};

	template<typename Filler>
	struct type_printer<unsigned int, Filler>
	{
		static void print() { builtin_printer::print("unsigned int"); }
	};

	template<typename Filler>
	struct type_printer<long, Filler>
	{
		static void print() { builtin_printer::print("long"); }
	};

	template<typename Filler>
	struct type_printer<unsigned long, Filler>
	{
		static void print() { builtin_printer::print("unsigned long"); }
	};

	template<typename Filler>
	struct type_printer<long long, Filler>
	{
		static void print() { builtin_printer::print("long long"); }
	};

	template<typename Filler>
	struct type_printer<unsigned long long, Filler>
	{
		static void print() { builtin_printer::print("unsigned long long"); }
	};

	template<typename Filler>
	struct type_printer<float, Filler>
	{
		static void print() { builtin_printer::print("float"); }
	};

	template<typename Filler>
	struct type_printer<double, Filler>
	{
		static void print() { builtin_printer::print("double"); }
	};

	template<typename Filler>
	struct type_printer<long double, Filler>
	{
		static void print() { builtin_printer::print("long double"); }
	};

	template<typename Filler>
	struct type_printer<bool, Filler>
	{
		static void print() { builtin_printer::print("bool"); }
	};

	template<typename Filler>
	struct type_printer<const char*, Filler>
	{
		static void print() { builtin_printer::print("const char*"); }
	};

/*
	struct parameter_printer
	{
		template<typename enum_type, enum_type... params> struct unroll;

		template<typename enum_type, enum_type current, enum_type... params>
		struct unroll<enum_type, current, params...>
		{
			static void print()
			{
				builtin_printer::print(current);
				builtin_printer::print(' ');
				unroll<enum_type, params...>::print();
			}
		};

		template<typename enum_type>
		struct unroll<enum_type>
		{
			static void print()
			{
				builtin_printer::print('\n');
			}
		};

		template<typename enum_type, enum_type... params>
		static void print()
		{
			unroll<enum_type, params...>::print();
		}
	};
*/

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

