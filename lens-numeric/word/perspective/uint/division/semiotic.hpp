/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Let	n1=|w3|w2|
	and	n0=|w1|w0|
	with	 d=|y1|y0|

	r	is the remainder and is offered for runtime optimization.
*/

template<size_type reg_length, Performance performance = Performance::specification> /* typename WordType,*/
struct division
{
	using reg_type				= typename byte_type<reg_length>::reg_type;
	using root_length			= typename byte_type<reg_length>::half_type::length;
	using root_max				= typename byte_type<reg_length>::half_type::max;
	using low_pass				= typename byte_type<reg_length>::low_pass;

	using zero				= typename Constant::template zero<reg_type>;
	using one				= typename Constant::template one<reg_type>;

	//

	using uint_multiplication		= multiplication<reg_length, performance>;

/*
	Concept:

	|w3|w2|w1|w0| / |y1|y0|, where w3 == 0, y1 == 0, w2 < y0.

	eg.	0129 / 03
	neg.	0715 / 06
*/

	struct root_type
	{
		static reg_type divide(reg_type & r, reg_type n1, reg_type n0, reg_type d)
		{
			reg_type	upper_n1	= (n1 >> root_length::value),
					lower_n1	= (low_pass::value & n1),

					upper_n0	= (n0 >> root_length::value),
					lower_n0	= (low_pass::value & n0),

					dividend1	= (lower_n1 << root_length::value) + upper_n0,
					quotient1	= dividend1 / d,
					remainder1	= dividend1 % d,

					dividend0	= (remainder1 << root_length::value) + lower_n0,
					quotient0	= dividend0 / d,
					remainder0	= dividend0 % d,

					quotient	= (quotient1 << root_length::value) + quotient0,
					remainder	= remainder0;

			r = remainder;

			return quotient;
		}
	};

/***********************************************************************************************************************/

/*
	intuition:	In two digit root_type division, if the first two numerator digits are greater than or equal
			we simply divide, otherwise we would add an extra root_type digit. This algorithm covers this case.

	algorithm:

	| n1 | n0 |				|w2||w1|w0|
	___________		___		___________
                     		___	                
	|    d    |				    |y1|y0|

	Constraints:		|w2|w1| < |y1|y0|

				floor(root_type/2) <= y1

	lemmata:		w2 == y1 and w1 < y1,	(eg. 13 < 14),
	or 		 	w2  < y1		(eg. 03 < 14)
*/

	struct knuth
	{
		inline static bool greater_than(reg_type l1, reg_type l0, reg_type r1, reg_type r0)
		{
			return (l1 != r1) ? (l1 > r1) : (l0 > r0);
		}

		inline static bool refine(reg_type & quotient, reg_type y1, reg_type dividend)
		{
			reg_type	product		 = quotient * y1,

					value		 = (product > dividend);

					quotient	-= value;

			return value;
		}

		static reg_type divide(reg_type & remainder, reg_type n1, reg_type n0, reg_type d)
		{
			reg_type	w2			 = n1,
					w1			 = (n0 >> root_length::value),
					w0			 = (low_pass::value & n0),

					y1			 = (d >> root_length::value),
					y0			 = (low_pass::value & d),

					dividend		 = (w2 << root_length::value) + w1,
					quotient		 = (w2 == y1) ? root_max::value : (dividend / y1),

					upper,
					lower;

			if (!refine(quotient, y1, dividend) || !refine(quotient, y1, dividend))
			{
					lower			 = uint_multiplication::multiply(upper, quotient, d);
					quotient		-= greater_than(upper, lower, n1, n0);
			}

					lower			 = uint_multiplication::multiply(upper, quotient, d);
					remainder		 = n0 - lower;

			return quotient;
		}
	};

/*
	algorithm:

	|  n1 |  n0 |				|w3|w2||w1|w0|		|w3|w2||w1|w0|		|w3|w2||w1|w0|
	_____________		___		______________		______________		______________
                     		___	                                                                   
	|     d     |				|y1|y0|			    |y1|y0|		       |y1|y0|

	Constraints:		|w3|w2| < |y1|y0|

				floor(root_type/2) <= y1

	lemmata:		w3 == y1 and w2 < y1,	(eg. 13 < 14),
	or 		 	w3  < y1		(eg. 03 < 14)
*/

	static reg_type divide(reg_type & remainder, reg_type n1, reg_type n0, reg_type d)
	{
		reg_type	w3			= (n1 >> root_length::value),
				w2			= (low_pass::value & n1),

				w1			= (n0 >> root_length::value),
				w0			= (low_pass::value & n0),

				y1			= (d >> root_length::value),
				y0			= (low_pass::value & d),

				dividend1		= (w2 << root_length::value) + w1,
				quotient1		= knuth::divide(remainder, w3, dividend1, d),

				dividend01		= (remainder >> root_length::value),
				dividend00		= (remainder << root_length::value) + w0,
				quotient0		= knuth::divide(remainder, dividend01, dividend00, d),

				quotient		= (quotient1 << root_length::value) + quotient0;

		return quotient;
	}
};

/***********************************************************************************************************************/

/*
	Let	n1=|w3|w2|
	and	n0=|w1|w0|
	with	 d=|y1|y0|

	r	is the remainder and is offered for runtime optimization.

	A variable is {n,u,l,b}-free (neither, upper, lower, both) based on its root_type,
	and whether or not that information is not yet redundant.

	Note: This is a source code optimization, as far as I can tell,
	there's no difference in reducing memory or processor cycles.
*/

template<size_type reg_length> /* typename WordType */
struct division<reg_length, Performance::optimization>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;
	using root_length			= typename byte_type<reg_length>::half_type::length;
	using low_pass				= typename byte_type<reg_length>::low_pass;

	//

	struct root_type
	{
		static reg_type divide(reg_type & r, reg_type n1, reg_type n0, reg_type d)
		{
				  // r  is b-free.
				  // n1 is u-free.
				  // n0 is n-free.

			r	= (n1 << root_length::value) + (n0 >> root_length::value);	// dividend1
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

			n0	= (r << root_length::value) + (low_pass::value & n0);		// dividend0
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

			n1	= (n1 << root_length::value) + r;
				  // r  is b-free.
				  // n1 is n-free.
				  // n0 is u-free.

			r	= n0;
				  // r  is u-free.
				  // n1 is n-free.
				  // n0 is b-free.

			return n1;
		}
	};
};

