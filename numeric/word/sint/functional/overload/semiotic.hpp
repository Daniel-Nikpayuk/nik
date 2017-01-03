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

struct overload
{
	/*
		Constraints:

		(0 < n < length) && (x != 0)
	*/

	template<size_type x, size_type n>
	struct left_shift
	{
		enum : size_type { value = x << n };
	};

	/*
		Constraints:

		(0 < n < length) && (x != 0)
	*/

	template<size_type x, size_type n>
	struct right_shift
	{
		enum : size_type
		{
			value = x < 0 ?
				-(-x >> n) :
				x >> n
		};
	};
};

