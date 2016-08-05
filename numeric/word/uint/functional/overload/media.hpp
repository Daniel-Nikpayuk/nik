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

struct overload
{
	/*
		Terms:
	
		semiotic::unit::length
	
		Constraints:
	
		{ x < 0, x == 0, x > 0 } x { n <= 0, 0 < n < length, n >= length }
	
		Dispatch:
	
		[4]	n >= length || (n > 0 && x == 0)	->	0
		[3]	(n <= 0)				->	x
		[2]	(0 < n < length) && (x != 0)		->	<<
	*/
	
	template<size_type x, size_type n>
	class left_shift
	{
		static constexpr size_type sx = !x ? 0 : x;
		static constexpr size_type sn = n <= 0
						|| n >= semiotic::unit::length ? 0: n;
	
		public: enum : size_type
		{
			value = n <= 0 ? x :
				n >= semiotic::unit::length
					|| !x ? 0 :
				semiotic::template left_shift<sx, sn>::value
		};
	};
	
	/*
		Terms:
	
		semiotic::unit::length
	
		Constraints:
	
		{ x < 0, x == 0, x > 0 } x { n <= 0, 0 < n < length, n >= length }
	
		Dispatch:
	
		[4]	n >= length || (n > 0 && x == 0)	->	0
		[3]	(n <= 0)				->	x
		[2]	(0 < n < length) && (x != 0)		->	>>
	*/
	
	template<size_type x, size_type n>
	class right_shift
	{
		static constexpr size_type sx = !x ? 0 : x;
		static constexpr size_type sn = n <= 0
						|| n >= semiotic::unit::length ? 0: n;
	
		public: enum : size_type
		{
			value = n <= 0 ? x :
				n >= semiotic::unit::length
					|| !x ? 0 :
				semiotic::template right_shift<sx, sn>::value
		};
	};
};

