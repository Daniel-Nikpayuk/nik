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

template<typename T, typename Filler = void>
struct printer;


template<typename Filler>
struct printer<char, Filler>
{
	static void print() { nik::display << "char"; }
	static void print(char c) { nik::display << "char" << c; }
	static void print(const char *s) { nik::display << "char" << s; }
};

template<typename Filler>
struct printer<signed char, Filler>
{
	static void print() { nik::display << "signed char"; }
	static void print(char c) { nik::display << "signed char" << c; }
	static void print(const char *s) { nik::display << "signed char" << s; }
};

template<typename Filler>
struct printer<unsigned char, Filler>
{
	static void print() { nik::display << "unsigned char"; }
	static void print(char c) { nik::display << "unsigned char" << c; }
	static void print(const char *s) { nik::display << "unsigned char" << s; }
};

template<typename Filler>
struct printer<wchar_t, Filler>
{
	static void print() { nik::display << "wchar_t"; }
	static void print(char c) { nik::display << "wchar_t" << c; }
	static void print(const char *s) { nik::display << "wchar_t" << s; }
};

template<typename Filler>
struct printer<char16_t, Filler>
{
	static void print() { nik::display << "char16_t"; }
	static void print(char c) { nik::display << "char16_t" << c; }
	static void print(const char *s) { nik::display << "char16_t" << s; }
};

template<typename Filler>
struct printer<char32_t, Filler>
{
	static void print() { nik::display << "char32_t"; }
	static void print(char c) { nik::display << "char32_t" << c; }
	static void print(const char *s) { nik::display << "char32_t" << s; }
};

template<typename Filler>
struct printer<short, Filler>
{
	static void print() { nik::display << "short"; }
	static void print(char c) { nik::display << "short" << c; }
	static void print(const char *s) { nik::display << "short" << s; }
};

template<typename Filler>
struct printer<unsigned short, Filler>
{
	static void print() { nik::display << "unsigned short"; }
	static void print(char c) { nik::display << "unsigned short" << c; }
	static void print(const char *s) { nik::display << "unsigned short" << s; }
};

template<typename Filler>
struct printer<int, Filler>
{
	static void print() { nik::display << "int"; }
	static void print(char c) { nik::display << "int" << c; }
	static void print(const char *s) { nik::display << "int" << s; }
};

template<typename Filler>
struct printer<unsigned int, Filler>
{
	static void print() { nik::display << "unsigned int"; }
	static void print(char c) { nik::display << "unsigned int" << c; }
	static void print(const char *s) { nik::display << "unsigned int" << s; }
};

template<typename Filler>
struct printer<long, Filler>
{
	static void print() { nik::display << "long"; }
	static void print(char c) { nik::display << "long" << c; }
	static void print(const char *s) { nik::display << "long" << s; }
};

template<typename Filler>
struct printer<unsigned long, Filler>
{
	static void print() { nik::display << "unsigned long"; }
	static void print(char c) { nik::display << "unsigned long" << c; }
	static void print(const char *s) { nik::display << "unsigned long" << s; }
};

template<typename Filler>
struct printer<long long, Filler>
{
	static void print() { nik::display << "long long"; }
	static void print(char c) { nik::display << "long long" << c; }
	static void print(const char *s) { nik::display << "long long" << s; }
};

template<typename Filler>
struct printer<unsigned long long, Filler>
{
	static void print() { nik::display << "unsigned long long"; }
	static void print(char c) { nik::display << "unsigned long long" << c; }
	static void print(const char *s) { nik::display << "unsigned long long" << s; }
};

template<typename Filler>
struct printer<float, Filler>
{
	static void print() { nik::display << "float"; }
	static void print(char c) { nik::display << "float" << c; }
	static void print(const char *s) { nik::display << "float" << s; }
};

template<typename Filler>
struct printer<double, Filler>
{
	static void print() { nik::display << "double"; }
	static void print(char c) { nik::display << "double" << c; }
	static void print(const char *s) { nik::display << "double" << s; }
};

template<typename Filler>
struct printer<long double, Filler>
{
	static void print() { nik::display << "long double"; }
	static void print(char c) { nik::display << "long double" << c; }
	static void print(const char *s) { nik::display << "long double" << s; }
};

template<typename Filler>
struct printer<bool, Filler>
{
	static void print() { nik::display << "bool"; }
	static void print(char c) { nik::display << "bool" << c; }
	static void print(const char *s) { nik::display << "bool" << s; }
};

template<typename Filler>
struct printer<const char*, Filler>
{
	static void print() { nik::display << "const char*"; }
	static void print(char c) { nik::display << "const char*" << c; }
	static void print(const char *s) { nik::display << "const char*" << s; }
};


