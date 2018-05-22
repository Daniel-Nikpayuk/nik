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
*/

template
<
	size_type N,
	typename Filler = void
>
struct builtin;

/*
	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long
*/

template
<
	typename Filler
>
struct builtin
<
	Byte::value << Zero::value,
	Filler
>
{
	using rtn = unsigned char;
};

template
<
	typename Filler
>
struct builtin
<
	Byte::value << One::value,
	Filler
>
{
	using rtn = unsigned short;
};


template
<
	typename Filler
>
struct builtin
<
	Byte::value << Two::value,
	Filler
>
{
	using rtn = unsigned int;
};


template
<
	typename Filler
>
struct builtin
<
	Byte::value << Three::value,
	Filler
>
{
	using rtn = unsigned long;
};

/*
*/

		  template<size_type N>
using byte_type = builtin<N>;

