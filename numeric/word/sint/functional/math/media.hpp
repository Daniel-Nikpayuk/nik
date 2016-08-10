/************************************************************************************************************************
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
************************************************************************************************************************/

struct math
{
	template<size_type x>
	struct is_odd
		{ enum : size_type { value=x % 2 }; };

	template<size_type x>
	struct is_even
		{ enum : size_type { value=!(x % 2) }; };

	template<size_type x>
	struct is_negative
		{ enum : size_type { value=x < 0 }; };

	template<size_type x>
	struct is_positive
		{ enum : size_type { value=x > 0 }; };

	template<size_type x>
	struct abs
		{ enum : size_type { value=(x > 0) ? x : -x }; };

	template<size_type x, size_type y>
	struct min
		{ enum : size_type { value=(x < y) ? x : y }; };

	template<size_type x, size_type y>
	struct max
		{ enum : size_type { value=(x > y) ? x : y }; };

	/*
		Terms:

		semiotic::unit::square::max

		Constraints:

		{ x < -max, -max <= x <= max, x > max }

		Dispatch:

		[2]	(x < max || x > max)	->	0
		[1]	(-max <= x <= max)	->	square
	*/

	template<size_type x>
	class square
	{
		static constexpr size_type sx = x <= semiotic::unit::overflow::square::lower
						|| x >= semiotic::unit::overflow::square::upper ? 0 : x;

		public: enum : size_type
		{
			value = x <= semiotic::unit::overflow::square::lower
					|| x >= semiotic::unit::overflow::square::upper ? 0 :
				x*x
		};
	};

	template<size_type a, size_type b>
	class gcd
	{
		public: enum : size_type
		{
			value = !a && !b ? 0 :
				semiotic::template gcd<a, b>::value
		};
	};

	/*
		Terms:

		Constraints:

		B = { b <= under(e), under(e) < b < -2, b == -2, b == -1, b == 0, b == 1, b == 2, 2 < b < over(e), b >= over(e) }
		E = { e <= -length, -length < e < 0, e == 0, e == 1, 1 < e < length, e == length, e > length }

		|B| = 9, |E| = 7, |BxE| = 63

		Dispatch:

		[15]	(b == 0 && e > 1) || (e < 0 && |b| >= 2)						->	0
		[14]	(e == 0) || (e != 1 && b == 1)								->	1
		[15]	(b == 0 && e < 0) || ((1 < e < length) && (b <= under(e) || b >= over(e))) ||
			(e > length && |b| >= 2) || (e == length && (b == 2 || |b| > 2))			->	undefined
		[9]	(e == 1)										->	b
		[5]	(b == -1) && (e < 0 || e > 1)								->	(-1)^|e|
		[1]	(b == -2) && (e = length)								->	-2^length
		[1]	(1 < e < length) && (b == -2)								->	(-1)^e * 2^e
		[1]	(1 < e < length) && (b == 2)								->	2^e
		[1]	(1 < e < length) && (under(e) < b < -2)							->	(-1)^e * |b|^e
		[1]	(1 < e < length) && (2 < b < over(e))							->	b^e
	*/

	template<size_type b, size_type e>
	class exp
	{
		static constexpr size_type abs_b = abs<b>::value;
		static constexpr size_type abs_e = abs<e>::value;
		static constexpr size_type sign = b < 0 ? 1 - 2 * (e % 2) : 1;
		static constexpr size_type overload = e <= 1 ? 0 : pow(2, double(semiotic::unit::length)/e);

		public: enum : size_type
		{
			value = e == 1 ? b :
				!e || b == 1 ? 1 :
				(e > 1 && !b) || (e < 0 && abs_b >= 2) ? 0 :
				!semiotic::unit::is_unsigned && b == -1 ? sign :
				e == semiotic::unit::length && !semiotic::unit::is_unsigned && b == -2 ? semiotic::unit::tail :
				1 < e && e < semiotic::unit::length ?
					abs_b == 2 ? sign << e :
					-overload-1 < b && b < -2 ?
						sign*semiotic::template exp<1, abs_b, e>::value
					: 2 < b && b < overload ?
						semiotic::template exp<1, abs_b, e>::value
					: 0 // undefined!
				: 0 // undefined!
		};
	};
};

