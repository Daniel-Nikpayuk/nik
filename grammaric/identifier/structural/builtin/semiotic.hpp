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
struct builtin
{
	static_assert
	(
		false,
		"not a builtin type!"
	);
};

/***********************************************************************************************************************/
/***********************************************************************************************************************/

template<typename Filler>
struct builtin<char, Filler> { using type = char; };

template<typename Filler>
struct builtin<signed char, Filler> { using type = signed char; };

template<typename Filler>
struct builtin<unsigned char, Filler> { using type = unsigned char; };

template<typename Filler>
struct builtin<wchar_t, Filler> { using type = wchar_t; };

template<typename Filler>
struct builtin<char16_t, Filler> { using type = char16_t; };

template<typename Filler>
struct builtin<char32_t, Filler> { using type = char32_t; };

template<typename Filler>
struct builtin<short, Filler> { using type = short; };

template<typename Filler>
struct builtin<unsigned short, Filler> { using type = unsigned short; };

template<typename Filler>
struct builtin<int, Filler> { using type = int; };

template<typename Filler>
struct builtin<unsigned int, Filler> { using type = unsigned int; };

template<typename Filler>
struct builtin<long, Filler> { using type = long; };

template<typename Filler>
struct builtin<unsigned long, Filler> { using type = unsigned long; };

template<typename Filler>
struct builtin<long long, Filler> { using type = long long; };

template<typename Filler>
struct builtin<unsigned long long, Filler> { using type = unsigned long long; };

template<typename Filler>
struct builtin<float, Filler> { using type = float; };

template<typename Filler>
struct builtin<double, Filler> { using type = double; };

template<typename Filler>
struct builtin<long double, Filler> { using type = long double; };

