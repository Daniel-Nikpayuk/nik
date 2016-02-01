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

#ifndef CONTEXT_CONTEXT_ARGUMENT_MATH_H
#define CONTEXT_CONTEXT_ARGUMENT_MATH_H

#include"../../constant/constant.h"
#include"../binary/binary.h"

/*
	As optimized (fast) types are intended to hold int types, it's more efficient to pass the given size_type instead of
	a const reference to one.

	Incrementing and decrementing pointers which should otherwise maintain a constant location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. As such, given some routines and subroutines are powerhouse workhorses
	relative to the whole library, it is worth implementing a few to be as processor and memory efficient as possible.
*/

namespace nik
{
 namespace context
 {
  namespace context
  {
   namespace argument
   {
	template<typename size_type>
	struct math
	{
		typedef context::constant<size_type> constant;
		typedef context::binary<size_type> binary;
/*
	less_than_or_equal:

	This is redundant, you can use the unrolling code from arithmetic, but this should be optimized as highly as possible,
	which, given the unrolling nature of its equivalent within arithmetic, it may not be. Test!
*/
		template<typename size_type>
		static bool less_than_or_equal(size_type in0, size_type in1, size_type in2, size_type in3)
			{ return (in0 < in2 || (in0 == in2) && in1 <= in3); }
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
	Adds the initial out value to the return value (carry).
	The return value is the "little" digit.
	out is the "big" digit.
*/
			template<typename size_type>
			static size_type low_return(size_type & out, size_type mid1, size_type mid2)
			{
				size_type	little_in1=binary::low(mid1),
						big_in1=binary::high(mid1),
						little_in2=binary::low(mid2),
						big_in2=binary::high(mid2);
				// mid1, mid2 are now free.

				mid2=little_in1*big_in2;
				mid1=big_in1*little_in2+mid2; // possible carry of 1.

				little_in2*=little_in1;
				little_in1=little_in2+binary::shift_up(mid1); // possible carry of 1.

				big_in1*=big_in2;
				// big_in2, is now free.
				big_in2=out+little_in1;

				out=big_in1+
					binary::shift_down(mid1)+
					binary::shift_up(mid1 < mid2)+
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
			template<typename size_type>
			static size_type high_return(size_type & out, size_type mid1, size_type mid2)
			{
				size_type	little_in1=binary::low(mid1),
						big_in1=binary::high(mid1),
						little_in2=binary::low(mid2),
						big_in2=binary::high(mid2);
				// mid1, mid2 are now free.

				mid2=little_in1*big_in2;
				mid1=big_in1*little_in2+mid2; // possible carry of 1.

				little_in2*=little_in1;
				little_in1=little_in2+binary::shift_up(mid1); // possible carry of 1.

				out+=little_in1; // possible carry of 1.

				return big_in1*big_in2+
					binary::shift_down(mid1)+
					binary::shift_up(mid1 < mid2)+
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
	The case where d == 2 implies in1 == 1:
*/
			struct binary
			{
				template<typename size_type>
				static size_type with_return(size_type & out, size_type in2)
				{
					out=(constant::one & in2);
					return constant::full_register::max_power + (in2 >> constant::one);
				}
			};

			struct half_register
			{
/*
	The case where d is at most a half register can be optimized as follows:

	Let in1=|w3|w2| and in2=|w1|w0| with d=|y1|y0|.
	Since d > in1, we have (|y1| > |w3|) or (|y1|==|w3| and |y0| > |w2|).
	For the "single digit case", this means |y1|=0 which implies |w3|=0 and |y0| > |w2|.
*/
				template<typename size_type>
				static size_type with_return(size_type & out, size_type in1, size_type in2, size_type d)
				{
					size_type	little_in2=binary::low(in2),
							big_in2=binary::high(in2);

					// in2 is now free.
					in2=binary::shift_up(in1)+big_in2;
					// in1, high_in2 are now free.
					in1=in2/d; big_in2=in2%d;

					in1 <<= constant::half_register::length;
					(big_in2 <<= constant::half_register::length) += little_in2;
					// little_in2 is now free.

					little_in2=big_in2/d; out=big_in2%d;

					return in1+little_in2;
				}
			};
/*
	partial register divisor: Knuth register divisor.

	Assumes d >= b/2 and in1 < b/2 and "mid" < d.
*/
			template<typename size_type>
			static size_type partial_register_divisor(size_type & r,
				size_type in1, size_type in2, size_type d, size_type big_d)
			{
				size_type	mid=binary::shift_up(in1)+binary::high(in2),
						q=(in1 < big_d) ? mid/big_d : constant::half_max-1,
						little=0,
						big=multiply::return_high(little, q, d);

				if (!less_than_or_equal(big, little, in1, in2))
				{
					--q;
					little=0;
					big=multiply::return_high(little, q, d);
					if (!less_than_or_equal(big, little, in1, in2))
					{
						--q;
						little=0;
						big=multiply::return_high(little, q, d);
					}
				}

				r=in2-little;

				return q;
			}
/*
	The optimization here is based off of Knuth's normalization approximation for finding the quotient.

	Let in1=|w3|w2| and in2=|w1|w0| with d=|y1|y0|.
	Since d > in1, we have (|y1| > |w3|) or (|y1|==|w3| and |y0| > |w2|).

	In finding the approximate q, under this context, it is implied that q is half register size,
	meaning one must follow through in finding all such digits (in this case, there are two of them) and reassembling.
*/
			template<typename size_type>
			static size_type full_register_divisor(size_type & r, size_type in1, size_type in2, size_type d)
			{
				size_type	pivot=binary::order(d)+1,
						scale=constant::register_length-pivot;

					// normalize:
						// one need not worry about the big value of in1 as in1 < d to begin with.
						// if d doesn't "go over" when shifting, neither will in1.
						// normalizing does not change the fact that in1 < d.
				(in1<<=scale)+=binary::high(in2, pivot);
				in2<<=scale;
				d<<=scale;

					// setup:
				size_type	mid=binary::shift_up(in1)+binary::high(in2),
						big_d=binary::high(d),
						q=binary::shift_up(partial_register_divisor(pivot, binary::high(in1), mid, d, big_d));

				mid=binary::shift_up(pivot)+binary::low(in2);
				q+=partial_register_divisor(r, binary::high(pivot), mid, d, big_d);

				r>>=scale;

				return q;
			}
/*
	Assumes tord >= 1 (size >= 2).
*/
			template<typename size_type, typename WIterator, typename RIterator1, typename RIterator2>
			static bool improve_quotient(size_type & q,
				WIterator t, RIterator1 u, size_type uord, RIterator2 v)
			{
				size_type tc=0;
				fwd_arit::template unroll_0<2>::scale::
					half_register::template no_return<size_type&>(tc, t, v, q);

				size_type uc=(uord == 2) ? *(u+2) : (size_type) 0;
					// this way of using "greater_than" is a small hack.
				if (fwd_arit::template unroll_0<2>::greater_than::
					template fast_return(false, t, tc, u, uc))
				{
					--q;
					return true;
				}
				else return false;
			}
/*
	Assumes uord >= vord >= 1.
	Assumes u has at least either two or three digits dependings on case.
	Assumes v has at least two digits.
*/
			template<typename size_type, typename WIterator, typename RIterator1, typename RIterator2>
			static void knuth_quotient(size_type & q, WIterator t,
				RIterator1 u, size_type uord, RIterator2 v, size_type vord)
			{
				RIterator1 bu=u-1;
				if (uord == vord) q=*u / *v;
				else
				{
					q=(*u < *v) ?
						((*u<<constant::half_register::length) + *bu) / *v :
						constant::half_max-1;
					--bu;
				}

				RIterator2 bv=v-1;
				size_type buord=u-bu;
				if (improve_quotient(q, t, bu, buord, bv))
					improve_quotient(q, t, bu, buord, bv);
			}
/*
	t is expected to be of size L+1 if L < M, of size L otherwise.
	r is expected to be of size L+1 if L < M, of size L otherwise.
*/
			template<typename size_type, typename WIterator1, typename WIterator2, typename RIterator>
			static WIterator2 knuth_remainder(size_type & q, WIterator1 t, WIterator2 r, RIterator d)
			{
				fwd_arit::template unroll_0<L+(L < M)>::scale::
					half_register::no_return((size_type) 0, t, d, q);
				fwd_arit::template unroll_0<L+(L < M)>::assign::minus::
					half_register::no_return((size_type) 0, r, t);

					// r < d at this point.
				return bwd_arit::zero::with_break(r+DORD, r);
			}
/*
	divide:
		L is the block length of the denominator.
			2 <= L
		M is the block length of the numerator.
			L <= M
		N is initialized as M+1-L.
		
		r is the initial location of the overhead value (carry).
			As a block it has length at least L+1.
			To implement under the normal interpretation, copy this to be the prefix of the first L digits of the numerator.
			Digits are shifted into r's register until it is big enough to divide.
		lr is the location of the leading digit of the remainder r.
		q is the final location of the quotient to be determined (it works its way backwards).
			As a block it has length at least M+1-L.
		t is the initial location of a temporary used for internal computations.
			As a block it has length at least L+1.
			Initialization is unnecessary as lazy comparisons are used avoiding values out of bounds.
		n is the digit location of the numerator following the copied prefix digits of the numerator.
			As a block it has length at least M.
		d is the initial location of the denominator.
			As a block it has length at least L+1.
		ld is the location of the leading digit of the divisor d.
			What would be termed "dord" here in this special case is in fact already defined by the template parameter as L-1.

		Assumes (r|n) and d are already normalized for Knuth multiple precision division optimization.

		Body variables are refactored as function parameters for higher entropy as one then defer type constraints (templating).
		On the otherhand, since size_type is a (more-or-less) known type, it can be declared within the body.

		Debugging note: Every function call within needs to be "half_register" robust.
*/
			template<typename size_type>
			static size_type with_return(size_type & r, size_type low, size_type d)
			{
				size_type rord=lr-r;
					// Use of L here is an optimization.
				if (fwd_arit::template unroll_0<L+(L < M)>::
					less_than::fast_return(false, r, rord, d, DORD)) *q=0;
				else
				{
						// Use of L here is an optimization.
					knuth_quotient(*q, t, lr, rord, ld, DORD);
					lr=knuth_remainder(*q, t, r, d);
				}

				WIterator1 olr(lr);
				*bwd_comp::assign::with_return(++lr, olr, r-1)=*n;
				unroll_1<N-1, M, L>::divide::multiple_digit::
					half_register::no_return(r, lr, --q, t, --n, d, ld);
			}
/*
	return_quotient:

	The return value is the quotient of the division.
	out is the remainder from the division.
	in1 is the first digit of the dividend and is such that in1 != 0.
	in2 is the second digit of the dividend.
	d is the divisor and is such that in1 < d. Given in1 != 0, this implies 2 <= d.
*/
			template<typename size_type>
			static size_type return_quotient(size_type & out, size_type in1, size_type in2, size_type d)
			{
				if (d == (size_type) 2) return divisor_equals_2(out, in2);
				else if (d < shift_up((size_type) 1)) return half_register_divisor(out, in1, in2, d);
				else return full_register_divisor(out, in1, in2, d);
			}
		};
	};
   }
  }
 }
}

#endif
