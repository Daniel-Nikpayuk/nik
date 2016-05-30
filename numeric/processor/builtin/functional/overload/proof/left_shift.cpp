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

/*
	requires:

	(x != 0 && n > 0)
	>>> x

	n < length
	>>> 0
*/

template<size_type x, size_type n>
struct left_shift
{
	enum : size_type { value = x << n };
};

/*
	requires:

	(x != 0 && n > 0)
	>>> x

	n < length
	>>> 0
*/

template<size_type x, size_type n>
struct left_shift_1
{
	static constexpr size_type s=1-2*(x < 0);
	static constexpr size_type x1=math::media::template abs<x>::value;

	enum : size_type { value = s*left_shift<x1, n>::value };
};

/*
	mitigates:

	(x != 0 && n > 0)
	>>> x

	requires:

	n < length
	>>> 0
*/

template<size_type x, size_type n>
struct left_shift_2
{
	static constexpr size_type x1=x ? x : 0;
	static constexpr size_type n1=(n > 0) ? n : 0;

	enum : size_type
	{
		value = (x && n > 0) ?
				left_shift_1<x1, n1>::value
			: x
	};
};

/*
	mitigates:

	n < length
	>>> 0

	requires:

	(x != 0 && n > 0)
	>>> x
*/

template<size_type x, size_type n>
struct left_shift_2_1
{
	static constexpr size_type n1=(n < unit::semiotic::length) ? n : 0;

	enum : size_type
	{
		value = n < unit::semiotic::length ?
				left_shift_1<x, n1>::value
			: 0
	};
};

