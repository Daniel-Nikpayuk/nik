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
	Reimplement using evaluator ?

template<typename Type>
struct builtin
{
	template<typename T, typename Filler = void>
	strict
	{
		static_assert
		(
			false,
			"not a strict type!"
		);
	};

	template<typename Filler>
	struct strict<char, Filler> { using type = char; };

	template<typename Filler>
	struct strict<signed char, Filler> { using type = signed char; };

	template<typename Filler>
	struct strict<unsigned char, Filler> { using type = unsigned char; };

	template<typename Filler>
	struct strict<wchar_t, Filler> { using type = wchar_t; };

	template<typename Filler>
	struct strict<char16_t, Filler> { using type = char16_t; };

	template<typename Filler>
	struct strict<char32_t, Filler> { using type = char32_t; };

	template<typename Filler>
	struct strict<short, Filler> { using type = short; };

	template<typename Filler>
	struct strict<unsigned short, Filler> { using type = unsigned short; };

	template<typename Filler>
	struct strict<int, Filler> { using type = int; };

	template<typename Filler>
	struct strict<unsigned int, Filler> { using type = unsigned int; };

	template<typename Filler>
	struct strict<long, Filler> { using type = long; };

	template<typename Filler>
	struct strict<unsigned long, Filler> { using type = unsigned long; };

	template<typename Filler>
	struct strict<long long, Filler> { using type = long long; };

	template<typename Filler>
	struct strict<unsigned long long, Filler> { using type = unsigned long long; };

	template<typename Filler>
	struct strict<float, Filler> { using type = float; };

	template<typename Filler>
	struct strict<double, Filler> { using type = double; };

	template<typename Filler>
	struct strict<long double, Filler> { using type = long double; };
};
*/

