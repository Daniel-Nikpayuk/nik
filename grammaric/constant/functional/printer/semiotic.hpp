/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename expression>
struct printer
{
	template<typename T, typename Filler = void>
	struct strict;

	template<typename Filler>
	struct strict<char, Filler>
	{
		static void print() { nik::display << "char"; }

		template<typename U>
		static void print(U u) { nik::display << "char" << u; }
	};

	template<typename Filler>
	struct strict<signed char, Filler>
	{
		static void print() { nik::display << "signed char"; }

		template<typename U>
		static void print(U u) { nik::display << "signed char" << u; }
	};

	template<typename Filler>
	struct strict<unsigned char, Filler>
	{
		static void print() { nik::display << "unsigned char"; }

		template<typename U>
		static void print(U u) { nik::display << "unsigned char" << u; }
	};

	template<typename Filler>
	struct strict<wchar_t, Filler>
	{
		static void print() { nik::display << "wchar_t"; }

		template<typename U>
		static void print(U u) { nik::display << "wchar_t" << u; }
	};

	template<typename Filler>
	struct strict<char16_t, Filler>
	{
		static void print() { nik::display << "char16_t"; }

		template<typename U>
		static void print(U u) { nik::display << "char16_t" << u; }
	};

	template<typename Filler>
	struct strict<char32_t, Filler>
	{
		static void print() { nik::display << "char32_t"; }

		template<typename U>
		static void print(U u) { nik::display << "char32_t" << u; }
	};

	template<typename Filler>
	struct strict<short, Filler>
	{
		static void print() { nik::display << "short"; }

		template<typename U>
		static void print(U u) { nik::display << "short" << u; }
	};

	template<typename Filler>
	struct strict<unsigned short, Filler>
	{
		static void print() { nik::display << "unsigned short"; }

		template<typename U>
		static void print(U u) { nik::display << "unsigned short" << u; }
	};

	template<typename Filler>
	struct strict<int, Filler>
	{
		static void print() { nik::display << "int"; }

		template<typename U>
		static void print(U u) { nik::display << "int" << u; }
	};

	template<typename Filler>
	struct strict<unsigned int, Filler>
	{
		static void print() { nik::display << "unsigned int"; }

		template<typename U>
		static void print(U u) { nik::display << "unsigned int" << u; }
	};

	template<typename Filler>
	struct strict<long, Filler>
	{
		static void print() { nik::display << "long"; }

		template<typename U>
		static void print(U u) { nik::display << "long" << u; }
	};

	template<typename Filler>
	struct strict<unsigned long, Filler>
	{
		static void print() { nik::display << "unsigned long"; }

		template<typename U>
		static void print(U u) { nik::display << "unsigned long" << u; }
	};

	template<typename Filler>
	struct strict<long long, Filler>
	{
		static void print() { nik::display << "long long"; }

		template<typename U>
		static void print(U u) { nik::display << "long long" << u; }
	};

	template<typename Filler>
	struct strict<unsigned long long, Filler>
	{
		static void print() { nik::display << "unsigned long long"; }

		template<typename U>
		static void print(U u) { nik::display << "unsigned long long" << u; }
	};

	template<typename Filler>
	struct strict<float, Filler>
	{
		static void print() { nik::display << "float"; }

		template<typename U>
		static void print(U u) { nik::display << "float" << u; }
	};

	template<typename Filler>
	struct strict<double, Filler>
	{
		static void print() { nik::display << "double"; }

		template<typename U>
		static void print(U u) { nik::display << "double" << u; }
	};

	template<typename Filler>
	struct strict<long double, Filler>
	{
		static void print() { nik::display << "long double"; }

		template<typename U>
		static void print(U u) { nik::display << "long double" << u; }
	};

	template<typename Filler>
	struct strict<bool, Filler>
	{
		static void print() { nik::display << "bool"; }

		template<typename U>
		static void print(U u) { nik::display << "bool" << u; }
	};

	template<typename Filler>
	struct strict<const char*, Filler>
	{
		static void print() { nik::display << "const char*"; }

		template<typename U>
		static void print(U u) { nik::display << "const char*" << u; }
	};

	static void print()
	{
		strict<typename expression::rtn::type>::print();
	}
};

