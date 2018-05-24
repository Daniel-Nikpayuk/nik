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

	A variable is {n,u,l,b}-free (neither, upper, lower, both) based on its half-registers,
	and whether or not that information is not yet redundant.

	Note: This is a source code optimization, as far as I can tell,
	there's no difference in reducing memory or processor cycles.
*/

static reg_type three_halves(reg_type & r, reg_type n1, reg_type n0, reg_type d)
{
		  // r  is b-free.
		  // n1 is u-free.
		  // n0 is n-free.

	r	= (n1 << half_length::value) + (n0 >> half_length::value);	// dividend1
		  // r  is n-free.
		  // n1 is b-free.
		  // n0 is u-free.

	n1	= r / d;							// quotient1
		  // r  is n-free.
		  // n1 is u-free.
		  // n0 is u-free.

	r	= r % d;							// remainder1
		  // r  is u-free.
		  // n1 is u-free.
		  // n0 is u-free.

	n0	= (r << half_length::value) + (low_pass::value & n0);		// dividend0
		  // r  is b-free.
		  // n1 is u-free.
		  // n0 is n-free.

	r	= n0 / d;							// quotient0
		  // r  is u-free.
		  // n1 is u-free.
		  // n0 is n-free.

	n0	= n0 % d;							// remainder0
		  // r  is u-free.
		  // n1 is u-free.
		  // n0 is u-free.

	n1	= (n1 << half_length::value) + r;
		  // r  is b-free.
		  // n1 is n-free.
		  // n0 is u-free.

	r	= n0;
		  // r  is u-free.
		  // n1 is n-free.
		  // n0 is b-free.

	return n1;
}

