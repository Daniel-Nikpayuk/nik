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

template
<
	size_type length,
	template<class, size_type> typename Word

> struct three_halves
<
	Word<bit<bool>, length>,
	Policy::specification
>
{
	using reg_type = typename byte_type<length>::rtn;

/*
	Let	in1=|w3|w2|
	and	in2=|w1|w0|
	with	  d=|y1|y0|

	out	is the remainder and is offered for runtime optimization.
*/

	static reg_type divide(reg_type & out, reg_type in1, reg_type in2, reg_type d)
	{
		reg_type	little_in2	= (f_semiotic::unit::filter::low_pass & in2),
				big_in2		= (in2 >> f_semiotic::unit::half::length);

		// in2 is now free.
		in2 = (in1 << f_semiotic::unit::half::length) + big_in2;
		// in1, big_in2 are now free.
		in1 = in2/d; big_in2 = in2%d;

		(big_in2 <<= f_semiotic::unit::half::length) += little_in2;
		// little_in2 is now free.

		little_in2 = big_in2/d; out = big_in2%d;

		return (in1 <<= f_semiotic::unit::half::length) + little_in2;
	}
};

/*
*/

template
<
	size_type length,
	template<class, size_type> typename Word

> struct three_halves
<
	Word<bit<bool>, length>,
	Policy::optimization
>
{
	using reg_type = typename byte_type<length>::rtn;

/*
	Let	in1=|w3|w2|
	and	in2=|w1|w0|
	with	  d=|y1|y0|
*/

	static reg_type divide(reg_type & out, reg_type in1, reg_type in2, reg_type d)
	{
		reg_type	little_in2	= (f_semiotic::unit::filter::low_pass & in2),
				big_in2		= (in2 >> f_semiotic::unit::half::length);

		// in2 is now free.
		in2 = (in1 << f_semiotic::unit::half::length) + big_in2;
		// in1, big_in2 are now free.
		in1 = in2/d; big_in2 = in2%d;

		(big_in2 <<= f_semiotic::unit::half::length) += little_in2;
		// little_in2 is now free.

		little_in2 = big_in2/d; out = big_in2%d;

		return (in1 <<= f_semiotic::unit::half::length) + little_in2;
	}
};

