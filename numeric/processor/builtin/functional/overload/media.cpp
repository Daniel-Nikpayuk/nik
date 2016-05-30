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

template<size_type x, size_type n>
struct left_shift
{
	static constexpr size_type n1=(n < unit::semiotic::length) ? n : 0;

	enum : size_type
	{
		value = n < unit::semiotic::length ?
				semiotic::template left_shift_2<x, n1>::value
			: 0
	};
};

template<size_type x, size_type n>
struct right_shift
{
	static constexpr size_type n1=(n < unit::semiotic::length) ? n : 0;

	enum : size_type
	{
		value = n < unit::semiotic::length ?
			semiotic::template right_shift_2<x, n1>::value
			: 0
	};
};

