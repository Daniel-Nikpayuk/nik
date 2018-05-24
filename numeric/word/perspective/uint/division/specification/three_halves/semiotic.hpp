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

/***********************************************************************************************************************/

/*
	Let	n1=|w3|w2|
	and	n0=|w1|w0|
	with	 d=|y1|y0|

	r	is the remainder and is offered for runtime optimization.
*/

static reg_type three_halves(reg_type & r, reg_type n1, reg_type n0, reg_type d)
{
	reg_type	upper_n1	= (n1 >> half_length::value),
			lower_n1	= (low_pass::value & n1),

			upper_n0	= (n0 >> half_length::value),
			lower_n0	= (low_pass::value & n0),

			dividend1	= (lower_n1 << half_length::value) + upper_n0,
			quotient1	= dividend1 / d,
			remainder1	= dividend1 % d,

			dividend0	= (remainder1 << half_length::value) + lower_n0,
			quotient0	= dividend0 / d,
			remainder0	= dividend0 % d,

			quotient	= (quotient1 << half_length::value) + quotient0,
			remainder	= remainder0;

	r = remainder;

	return quotient;
}

