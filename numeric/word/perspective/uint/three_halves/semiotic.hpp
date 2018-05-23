/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
	Concept:

	|w3|w2|w1|w0| / |y1|y0|, where w3 == 0, y1 == 0, w2 < y0.

	eg.	0129 / 03
	neg.	0715 / 06
*/

enum struct Policy : size_type
{
	specification,
	optimization,

	dimension // filler
};

template
<
	typename WordType,
	Policy policy = Policy::optimization

> struct three_halves;

/*
*/

template<size_type length>
struct debug			// temporary to test these functions.
{
};

template
<
	size_type length
//	size_type length,
//	template<class, size_type> typename Word

> struct three_halves
<
	debug<length>,
//	Word<bit<bool>, length>,
	Policy::specification
>
{
	using reg_type		= typename byte_type<length>::rtn;
	using half_length	= typename byte_type<length>::half::length;
	using low_pass		= typename byte_type<length>::low_pass;

/*
	Let	n1=|w3|w2|
	and	n0=|w1|w0|
	with	 d=|y1|y0|

	rem	is the remainder and is offered for runtime optimization.
*/

	static reg_type divide(reg_type & rem, reg_type n1, reg_type n0, reg_type d)
	{
		reg_type	upper_n0	= (n0 >> half_length::value),
				lower_n0	= (low_pass::value & n0);

		// n0 is now free.
		n0 = (n1 << half_length::value) + upper_n0;
		// n1, upper_n0 are now free.
		n1 = n0 / d; upper_n0 = n0 % d;

		(upper_n0 <<= half_length::value) += lower_n0;
		// lower_n0 is now free.

		lower_n0 = upper_n0 / d; rem = upper_n0 % d;

		return (n1 <<= half_length::value) + lower_n0;
	}
};

/*
*/

template
<
	size_type length
//	size_type length,
//	template<class, size_type> typename Word

> struct three_halves
<
	debug<length>,
//	Word<bit<bool>, length>,
	Policy::optimization
>
{
	using reg_type		= typename byte_type<length>::rtn;
	using half_length	= typename byte_type<length>::half::length;
	using low_pass		= typename byte_type<length>::low_pass;

/*
	Let	n1=|w3|w2|
	and	n0=|w1|w0|
	with	 d=|y1|y0|

	rem	is the remainder and is offered for runtime optimization.
*/

	static reg_type divide(reg_type & rem, reg_type n1, reg_type n0, reg_type d)
	{
		reg_type	upper_n0	= (n0 >> half_length::value),
				lower_n0	= (low_pass::value & n0);

		// n0 is now free.
		n0 = (n1 << half_length::value) + upper_n0;
		// n1, upper_n0 are now free.
		n1 = n0 / d; upper_n0 = n0 % d;

		(upper_n0 <<= half_length::value) += lower_n0;
		// lower_n0 is now free.

		lower_n0 = upper_n0 / d; rem = upper_n0 % d;

		return (n1 <<= half_length::value) + lower_n0;
	}
};

