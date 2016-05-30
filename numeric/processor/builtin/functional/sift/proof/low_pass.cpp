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

	t > 0
	>>> 0

	t < length
	>>> max
*/

template<size_type t>
struct low_pass
{
	enum : size_type
	{
		value = unit::media::max >> (unit::media::length - t)
	};
};

/*
	requires:

	t < length
	>>> max
*/

template<size_type t>
struct low_pass_1
{
	static constexpr size_type t1=(t > 0) ? t : 0;

	enum : size_type
	{
		value = t > 0 ?
				low_pass<t1>::value
			: 0
	};
};

/*
	requires:

	t > 0
	>>> 0
*/

template<size_type t>
struct low_pass_1_1
{
	static constexpr size_type t1=(t < unit::semiotic::length) ? t : 0;

	enum : size_type
	{
		value = t < unit::media::length ?
				low_pass<t1>::value
			: unit::media::max
	};
};

