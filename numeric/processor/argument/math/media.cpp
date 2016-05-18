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
	multiply:

	Has been optimized, but it might just be better to not reuse variables for reading clarity,
	and just let the compiler optimize.

	if 1 < base, then 0 < base-1.
	Since -1 < 1, then base-1 < base+1.
	Hence (base-1)^2 < base^2-1.
	Thus carry < base^2.
*/

struct multiply
{
/*
	Reverify this is optimized.
*/
	static size_type low_return(size_type mid1, size_type mid2)
	{
		size_type	little_in1=a_binary::semiotic::low(mid1),
				big_in1=a_binary::semiotic::high(mid1),
				little_in2=a_binary::semiotic::low(mid2),
				big_in2=a_binary::semiotic::high(mid2);
		// mid1, mid2 are now free.

		mid2=little_in1*big_in2;
		mid1=big_in1*little_in2+mid2; // possible carry of 1.

		little_in2*=little_in1;

		return little_in2+a_binary::semiotic::shift_up(mid1);
	}
/*
	Adds the initial out value to the return value (carry).
	The return value is the "little" digit.
	out is the "big" digit.
*/
	static size_type low_return(size_type & out, size_type mid1, size_type mid2)
	{
		size_type	little_in1=a_binary::semiotic::low(mid1),
				big_in1=a_binary::semiotic::high(mid1),
				little_in2=a_binary::semiotic::low(mid2),
				big_in2=a_binary::semiotic::high(mid2);
		// mid1, mid2 are now free.

		mid2=little_in1*big_in2;
		mid1=big_in1*little_in2+mid2; // possible carry of 1.

		little_in2*=little_in1;
		little_in1=little_in2+a_binary::semiotic::shift_up(mid1); // possible carry of 1.

		big_in1*=big_in2;
		// big_in2, is now free.
		big_in2=out+little_in1;

		out=big_in1+
			a_binary::semiotic::shift_down(mid1)+
			a_binary::semiotic::shift_up(mid1 < mid2)+
			(little_in1 < little_in2)+
			(big_in2 < little_in1);
		// uses mid1, mid2, little_in1, big_in1, little_in2, big_in2, 

		return big_in2;
	}
/*
	Adds to the existing out regardless of its initial value.
	The return value is the "big" digit.
	out is the "little" digit.
	This is intuitively opposite of what it should be, but implements recursively/iteratively better when unrolling.
*/
	static size_type high_return(size_type & out, size_type mid1, size_type mid2)
	{
		size_type	little_in1=a_binary::semiotic::low(mid1),
				big_in1=a_binary::semiotic::high(mid1),
				little_in2=a_binary::semiotic::low(mid2),
				big_in2=a_binary::semiotic::high(mid2);
		// mid1, mid2 are now free.

		mid2=little_in1*big_in2;
		mid1=big_in1*little_in2+mid2; // possible carry of 1.

		little_in2*=little_in1;
		little_in1=little_in2+a_binary::semiotic::shift_up(mid1); // possible carry of 1.

		out+=little_in1; // possible carry of 1.

		return big_in1*big_in2+
			a_binary::semiotic::shift_down(mid1)+
			a_binary::semiotic::shift_up(mid1 < mid2)+
			(little_in1 < little_in2)+
			(out < little_in1);
		// uses mid1, mid2, little_in1, big_in1, little_in2, big_in2, 
	}
};

/*
	divide:

	These algorithms are highly optimized and only work (semantically) if (in1|in2 >= d) where (in1 != 0), and (in1 < d).

	The cases d == 0 , d == 1 are not covered as no optimized algorithms are required.
*/

struct divide
{
/*
	return_quotient:

	The return value is the quotient of the division.
	out is the remainder from the division.
	in1 is the first digit of the dividend and is such that in1 != 0.
	in2 is the second digit of the dividend.
	d is the divisor and is such that in1 < d. Given in1 != 0, this implies 2 <= d.
			template<typename size_type>
			static size_type return_quotient(size_type & out, size_type in1, size_type in2, size_type d)
			{
				if (d == (size_type) 2) return divisor_equals_2(out, in2);
				else if (d < shift_up((size_type) 1)) return half::with_return(out, in1, in2, d);
				else return with_return(out, in1, in2, d);
			}
*/
};

