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
	Interface Design: Should be oriented around "locations"---similar to array access.
	Use s,t (s < t) as default location names.

	If you go "over", it's not equivalent to "wrapping around".
	Think of it like an infinite array going in both directions, but in the end we only filter
	within the scope of the processor memory.
*/

template<size_type t>
struct low_pass
{
	static constexpr size_type t1=(t < unit::semiotic::length) ? t : 0;

	enum : size_type
	{
		value = t < unit::semiotic::length ?
				semiotic::template low_pass_1<t1>::value
			: unit::semiotic::max
	};
};

/*
template<size_type s>
struct high_pass
{
	enum : size_type
	{
		value = unit::media::max & ~low_pass<s>::value
	};
};

template<size_type s, size_type t>
struct band_pass
{
	static constexpr size_type lower=(s > t) ? t+1 : s;
	static constexpr size_type upper=(s > t) ? s+1 : t;
		// lower <= upper

	static constexpr size_type diff=upper-lower;
		// 0 <= diff

	enum : size_type
	{
		value = diff ?
			diff < unit::media::length ?
				lower ?
					(unit::media::max >> (unit::media::length-diff)) << lower
				: 0
			: lower ?
				unit::media::max << lower : 0
			: 0
	};
};

template<size_type x, size_type t>
struct low
{
	enum : size_type
	{
		value = (x & low_pass<t>::value)
	};
};

template<size_type x, size_type s>
struct high
{
	enum : size_type
	{
		value = over::media::template right_shift<x, s>::value
	};
};

template<size_type x, size_type s, size_type t>
struct band
{
	static constexpr size_type lower=math::media::template max<(s > t) ? t+1 : s, 0>::value;
	static constexpr size_type upper=math::media::template min<(s > t) ? s+1 : t, unit::media::length>::value;
		// 0 <= lower <= upper <= length

	static constexpr size_type diff=upper-lower;
		// 0 <= diff <= length-lower <= length

	enum : size_type
	{
		value = diff ?
			diff < unit::media::length ?
				upper < unit::media::length ?
					(x & (1 << upper) - 1) >> lower
				:
					x >> lower
			: x
			: 0
	};
};

template<size_type x>
struct lower_half
{
	enum : size_type
	{
		value = low<x, unit::half::length>::value
	};
};

template<size_type x>
struct upper_half
{
	enum : size_type
	{
		value = high<x, unit::half::length>::value
	};
};

template<size_type x>
struct order
{
	enum : size_type
	{
		value = semiotic::template fast_order<0, x, unit::length>::value
	};
};
*/

