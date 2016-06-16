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

struct sift
{
	/*
		Interface Design: Should be oriented around "locations"---similar to array access.
		Use s,t (s < t) as default location names.

		If you go "over", it's not equivalent to "wrapping around".
		Think of it like an infinite array going in both directions, but in the end we only filter
		within the scope of the processor memory.
	*/

	/*
		Terms:

		semiotic::unit::length
		semiotic::unit::max

		Constraints:

		T = { t <= 0, 0 < t < length, t >= length }

		|T| = 3

		Dispatch:

		[1]	(t <= 0)		->	0
		[1]	(t >= length)		->	max
		[1]	(0 < t < length)	->	low_pass
	*/

	template<size_type t>
	class low_pass
	{
		static constexpr size_type st = t <= 0
						|| t >= semiotic::unit::length ? 0 : t;

		public: enum : size_type
		{
			value = t <= 0 ? 0 :
				t >= semiotic::unit::length ? semiotic::unit::max :
					semiotic::template low_pass<st>::value
		};
	};

	/*
		Terms:

		semiotic::unit::length
		semiotic::unit::max

		Constraints:

		S = { s <= 0, 0 < s < length, s >= length }

		|S| = 3

		Dispatch:

		[1]	(s <= 0)		->	max
		[1]	(s >= length)		->	0
		[1]	(0 < s < length)	->	high_pass
	*/

	template<size_type s>
	struct high_pass
	{
		enum : size_type
		{
			value = s <= 0 ? semiotic::unit::max :
				s >= semiotic::unit::length ? 0 :
					semiotic::template high_pass<s>::value
		};
	};

	/*
		Terms:

		semiotic::unit::length
		semiotic::unit::max

		Constraints:

		S = { s <= 0, 0 < s < length, s >= length }
		T = { t <= 0, 0 < t < length, t >= length }

		|S| = 3, |T| = 3, |SxT| = 9

		Dispatch:

		[2]	(s <= 0	&& t <= 0) || (s >= length && t >= length)	->	0
		[2]	(s <= 0	&& t >= length) || (s >= length && t <= 0)	->	max
		[1]	(0 < s < length) && (t <= 0)				->	low_pass(s)
		[1]	(s <= 0) && (0 < t < length)				->	low_pass(t)
		[1]	(0 < s < length) && (t >= length)			->	high_pass(s)
		[1]	(s >= length) && (0 < t < length)			->	high_pass(t)
		[1]	(0 < s < length) && (0 < t < length)			->	band_pass(min(s,t), max(s,t))
	*/

	template<size_type s, size_type t>
	struct band_pass
	{
		static constexpr size_type length = semiotic::unit::length;

		static constexpr size_type lower = (s > t) ? t : s;
		static constexpr size_type upper = (s > t) ? s : t;
			// lower <= upper

		static constexpr size_type left = semiotic::template low_pass<upper>::value;
		static constexpr size_type right = semiotic::template high_pass<lower>::value;

		enum : size_type
		{
			value = (upper <= 0) || (lower >= length) ? 0 :
				(lower <= 0 && upper >= length) ? semiotic::unit::max :
				(lower >= length && 0 < upper && upper < length) ? left :
				(0 < lower && lower < length && upper >= length) ? right :
					semiotic::template band_pass<lower, upper>::value
		};
	};

	/*
		Terms:

		semiotic::unit::length

		Constraints:

		X = { x == 0, x != 0 }
		T = { t <= 0, 0 < t < length, t >= length }

		|X| = 2, |T| = 3, |XxT| = 6

		Dispatch:

		[4]	(x == 0) || (x != 0 && t <= 0)	->	0
		[1]	(x != 0 && t >= length)		->	x
		[1]	(x != 0 && (0 < t < length)	->	low
	*/

	template<size_type x, size_type t>
	struct low
	{
		enum : size_type
		{
			value = !x || t <= 0 ? 0 :
				t >= semiotic::unit::length ? x :
					semiotic::template low<x, t>::value
		};
	};

	/*
		Terms:

		semiotic::unit::length

		Constraints:

		X = { x == 0, x != 0 }
		S = { s <= 0, 0 < s < length, s >= length }

		|X| = 2, |S| = 3, |XxS| = 6

		Dispatch:

		[4]	(x == 0) || (x != 0 && s >= length)	->	0
		[1]	(x != 0 && s <= 0)			->	x
		[1]	(x != 0 && (0 < s < length)		->	high
	*/

	template<size_type x, size_type s>
	struct high
	{
		enum : size_type
		{
			value = !x || s >= semiotic::unit::length ? 0 :
				s <= 0 ? x :
					semiotic::template high<x, s>::value
		};
	};

	/*
		Terms:

		semiotic::unit::length

		Constraints:

		S = { s <= 0, 0 < s < length, s >= length }
		T = { t <= 0, 0 < t < length, t >= length }

		|S| = 3, |T| = 3, |SxT| = 9

		Dispatch:

		[2]	(s <= 0	&& t <= 0) || (s >= length && t >= length)	->	0
		[2]	(s <= 0	&& t >= length) || (s >= length && t <= 0)	->	x
		[1]	(0 < s < length) && (t <= 0)				->	low(x, s)
		[1]	(s <= 0) && (0 < t < length)				->	low(x, t)
		[1]	(0 < s < length) && (t >= length)			->	high(x, s)
		[1]	(s >= length) && (0 < t < length)			->	high(x, t)
		[1]	(0 < s < length) && (0 < t < length)			->	band(x, min(s,t), max(s,t))
	*/

	template<size_type x, size_type s, size_type t>
	struct band
	{
		static constexpr size_type length = semiotic::unit::length;

		static constexpr size_type lower = (s > t) ? t : s;
		static constexpr size_type upper = (s > t) ? s : t;
			// lower <= upper

		static constexpr size_type left = semiotic::template low<x, upper>::value;
		static constexpr size_type right = semiotic::template high<x, lower>::value;

		enum : size_type
		{
			value = (upper <= 0) || (lower >= length) ? 0 :
				(lower <= 0 && upper >= length) ? x :
				(lower >= length && 0 < upper && upper < length) ? left :
				(0 < lower && lower < length && upper >= length) ? right :
					semiotic::template band<x, lower, upper>::value
		};
	};

	/*
		Terms:

		Constraints:

		X = { x == 0, x != 0 }

		|X| = 2

		Dispatch:

		[1]	(x == 0)	->	0
		[1]	(x != 0)	->	lower_half
	*/

	template<size_type x>
	struct lower_half
	{
		enum : size_type
		{
			value = !x ? 0 :
					semiotic::template lower_half<x>::value
		};
	};

	/*
		Terms:

		Constraints:

		X = { x == 0, x != 0 }

		|X| = 2

		Dispatch:

		[1]	(x == 0)	->	0
		[1]	(x != 0)	->	upper_half
	*/

	template<size_type x>
	struct upper_half
	{
		enum : size_type
		{
			value = !x ? 0 :
					semiotic::template upper_half<x>::value
		};
	};

	/*
		Terms:

		semiotic::unit::length

		Constraints:

		D = { is_unsigned, !is_unsigned }
		X = { x == min, min < x < 0, x == 0, x > 0 }

		|D| = 2, |X| = 4, |DxX| = 8

		Dispatch:

		[3]	(is_unsigned && x <= 0) || (!is_unsigned && x == 0)	->	0
		[2]	(!is_unsigned && (x > 0 || min < x < 0))		->	signed_degree
		[1]	(!is_unsigned && x == min)				->	length
		[1]	(is_unsigned && x > 0)					->	unsigned_degree
	*/

	template<size_type x>
	class degree
	{
		static constexpr size_type min = semiotic::unit::min;
		static constexpr size_type length = semiotic::unit::length;
		static constexpr bool is_unsigned = semiotic::unit::is_unsigned;

		static constexpr size_type unsigned_degree = semiotic::template unsigned_degree<0, x, length>::value;
		static constexpr size_type signed_degree = semiotic::template signed_degree<0, x>::value;

		public: enum : size_type
		{
			value = (is_unsigned && x <= 0) || (!is_unsigned && !x) ? 0 :
				!is_unsigned ?  x == min ? length : signed_degree
				: unsigned_degree
		};
	};
};

