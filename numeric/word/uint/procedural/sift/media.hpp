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
		Terms:

		unit::semiotic::length
		unit::semiotic::max

		Constraints:

		T = { t <= 0, 0 < t < length, t >= length }

		|T| = 3

		Dispatch:

		[1]	(t <= 0)		->	0
		[1]	(t >= length)		->	max
		[1]	(0 < t < length)	->	low_pass
	*/

	struct low_pass
	{
		static size_type with_return(size_type t)
		{
			static constexpr size_type length = f_semiotic::unit::length;

			if (0 < t && t < length)	return semiotic::low_pass::with_return(t);
			else if (t >= length)		return f_semiotic::unit::max;
			else				return 0;
		}
	};

	/*
		Terms:

		unit::semiotic::length
		unit::semiotic::max

		Constraints:

		S = { s <= 0, 0 < s < length, s >= length }

		|S| = 3

		Dispatch:

		[1]	(s <= 0)		->	max
		[1]	(s >= length)		->	0
		[1]	(0 < s < length)	->	high_pass
	*/

	struct high_pass
	{
		static size_type with_return(size_type s)
		{
			static constexpr size_type length = f_semiotic::unit::length;

			if (0 < s && s < length)	return semiotic::high_pass::with_return(s);
			else if (s >= length)		return f_semiotic::unit::max;
			else				return 0;
		}
	};

	/*
		Terms:

		unit::semiotic::length
		unit::semiotic::max

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

	struct band_pass
	{
		static size_type with_return(size_type s, size_type t)
		{
			static constexpr size_type length = f_semiotic::unit::length;

			size_type lower = (s > t) ? t : s;
			size_type upper = (s > t) ? s : t;
				// lower <= upper

			if (0 < lower && upper < length)				return semiotic::band_pass::with_return(lower, upper);
			else if (0 < lower && lower < length && upper >= length)	return semiotic::high_pass::with_return(lower);
			else if (lower >= length && 0 < upper && upper < length)	return semiotic::low_pass::with_return(upper);
			else if (lower <= 0 && upper >= length)				return f_semiotic::unit::max;
			else								return 0;
		}
	};

	/*
		Terms:

		unit::semiotic::length

		Constraints:

		X = { x == 0, x != 0 }
		T = { t <= 0, 0 < t < length, t >= length }

		|X| = 2, |T| = 3, |XxT| = 6

		Dispatch:

		[4]	(x == 0) || (x != 0 && t <= 0)	->	0
		[1]	(x != 0 && t >= length)		->	x
		[1]	(x != 0 && (0 < t < length)	->	low
	*/

	struct low
	{
		static size_type with_return(size_type x, size_type t)
		{
			static constexpr size_type length = f_semiotic::unit::length;

			if (0 < t && t < length && x)	return semiotic::low::with_return(x, t);
			else if (t >= length && x)	return x;
			else				return 0;
		}

		struct half
		{
			static size_type with_return(size_type x)
			{
				if (x)	return semiotic::low::half::with_return(x);
				else	return 0;
			}
		};
	};

	/*
		Terms:

		unit::semiotic::length

		Constraints:

		X = { x == 0, x != 0 }
		S = { s <= 0, 0 < s < length, s >= length }

		|X| = 2, |S| = 3, |XxS| = 6

		Dispatch:

		[4]	(x == 0) || (x != 0 && s >= length)	->	0
		[1]	(x != 0 && s <= 0)			->	x
		[1]	(x != 0 && (0 < s < length)		->	high
	*/

	struct high
	{
		static size_type with_return(size_type x, size_type s)
		{
			static constexpr size_type length = f_semiotic::unit::length;

			if (0 < s && s < length && x)	return semiotic::high::with_return(x, s);
			else if (s <= 0 && x)		return x;
			else				return 0;
		}

		struct half
		{
			static size_type with_return(size_type x)
			{
				if (x)	return semiotic::high::half::with_return(x);
				else	return 0;
			}
		};
	};

	/*
		Terms:

		unit::semiotic::length

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

	struct band
	{
		static size_type with_return(size_type x, size_type s, size_type t)
		{
			static constexpr size_type length = f_semiotic::unit::length;

			size_type lower = (s > t) ? t : s;
			size_type upper = (s > t) ? s : t;
				// lower <= upper

			if (0 < lower && upper < length)				return semiotic::band::with_return(x, lower, upper);
			else if (0 < lower && lower < length && upper >= length)	return semiotic::high::with_return(x, lower);
			else if (lower >= length && 0 < upper && upper < length)	return semiotic::low::with_return(x, upper);
			else if (lower <= 0 && upper >= length)				return x;
			else								return 0;
		}
	};

	/*
		Terms:

		unit::semiotic::length

		Constraints:

		D = { is_unsigned, !is_unsigned }
		X = { x == min, min < x < 0, x == 0, x > 0 }

		|D| = 2, |X| = 4, |DxX| = 8

		Dispatch:

		[3]	(is_unsigned && x <= 0) || (!is_unsigned && x == 0)	->	0
		[1]	(!is_unsigned && x == min)				->	length
		[2]	(!is_unsigned && (x > 0 || min < x < 0))		->	signed_degree
		[1]	(is_unsigned && x > 0)					->	unsigned_degree
	*/

	struct degree
	{
		static size_type with_return(size_type x)
		{
			static constexpr size_type min = f_semiotic::unit::min;
			static constexpr size_type length = f_semiotic::unit::length;
			static constexpr bool is_unsigned = f_semiotic::unit::is_unsigned;

			if (is_unsigned && x > 0)		return semiotic::template unroll<length>::degree::unsigned_return(0, x);
			else if (!is_unsigned &&
				(x > 0 || min < x && x < 0))	return semiotic::degree::signed_return(x); // could be more efficient!
			else if (!is_unsigned && x == min)	return length;
			else					return 0;
		}
	};
};

