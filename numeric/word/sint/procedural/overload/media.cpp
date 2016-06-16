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

		unit::semiotic::length

		Constraints:

		{ x < 0, x == 0, x > 0 } x { n <= 0, 0 < n < length, n >= length }

		Dispatch:

		[4]	n >= length || (n > 0 && x == 0)	->	0
		[3]	(n <= 0)				->	x
		[2]	(0 < n < length) && (x != 0)		->	<<
	*/

	struct left_shift
	{
		static size_type with_return(size_type x, size_type n)
		{
			if (0 < n && n < fs_policy::unit::length && x)		return x << n;
			else if (n <= 0)					return x;
			else							return 0;
		}

		struct half
		{
			static size_type with_return(size_type x)
			{
				if (x)	return x << fs_policy::unit::half::length;
				else	return 0;
			}
		};
	};

	/*
		Terms:

		unit::semiotic::length

		Constraints:

		{ x < 0, x == 0, x > 0 } x { n <= 0, 0 < n < length, n >= length }

		Dispatch:

		[4]	n >= length || (n > 0 && x == 0)	->	0
		[3]	(n <= 0)				->	x
		[2]	(0 < n < length) && (x != 0)		->	>>
	*/

	struct right_shift
	{
		static size_type with_return(size_type x, size_type n)
		{
			if (0 < n && n < fs_policy::unit::length && x)		return semiotic::right_shift::with_return(x, n);
			else if (n <= 0)					return x;
			else							return 0;
		}

		struct half
		{
			static size_type with_return(size_type x)
			{
				if (x)	return semiotic::right_shift::half::with_return(x, fs_policy::unit::half::length);
				else	return 0;
			}
		};
	};
};

