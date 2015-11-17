/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef CONTEXT_SEMIOTIC_REGIST_H
#define CONTEXT_SEMIOTIC_REGIST_H

#include<stddef.h>

#include"../../../context/context/binary.h"

/*
	As block types are intended to hold int types, it's more efficient to pass the given value_type instead of
	a const reference to one.

	Incrementing and decrementing pointers which should otherwise maintain a constant location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using these block classes in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.
*/

namespace nik
{
	namespace context
	{
		namespace semiotic
		{
/*
			block:
				typename The minimal specification (axiomatic properties) of a block class are:
				typedefs:
				constructors:
				accessors:
*/
			template<typename size_type>
			struct regist
			{
				typedef context::meta::constant<size_type> constant;
				typedef context::meta::binary<size_type> binary;
/*
	times:

	Has been optimized, but it might just be better to not reuse variables for reading clarity,
	and just let the compiler optimize.

	if 1 < base, then 0 < base-1.
	Since -1 < 1, then base-1 < base+1.
	Hence (base-1)^2 < base^2-1.
	Thus carry < base^2.
*/
/*
	Adds the initial out value to the return value (carry).
	The return value is the "low" digit.
	out is the "high" digit.
*/
				template<typename ValueType>
				static ValueType times_return_low(ValueType & out, ValueType mid1, ValueType mid2)
				{
					ValueType	low_in1 =(binary::template left_half<mid1>::value),
							high_in1=(binary::template right_half<mid1>::value);
					ValueType	low_in2 =(binary::template left_half<mid2>::value),
							high_in2=(binary::template right_half<mid2>::value);
					// mid1, mid2 are now free.

					mid2=low_in1*high_in2;
					mid1=high_in1*low_in2+mid2; // possible carry of 1.

					low_in2*=low_in1;
					low_in1=low_in2+(mid1<<constant::half_length); // possible carry of 1.

					high_in1*=high_in2;
					// high_in2, is now free.
					high_in2=out+low_in1;

					out=high_in1+
						(mid1>>constant::half_length)+
						((mid1 < mid2)<<constant::half_length)+
						(low_in1 < low_in2)+
						(high_in2 < low_in1);
					// uses mid1, mid2, low_in1, high_in1, low_in2, high_in2, 

					return high_in2;
				}
/*
	Adds to the existing out regardless of its initial value.
	The return value is the "high" digit.
	out is the "low" digit.
	This is intuitively opposite of what it should be, but implements recursively/iteratively better when unrolling.
*/
				template<typename ValueType>
				static ValueType times_return_high(ValueType & out, ValueType mid1, ValueType mid2)
				{
					ValueType	low_in1 =(binary::template left_half<mid1>::value),
							high_in1=(binary::template right_half<mid1>::value);
					ValueType	low_in2 =(binary::template left_half<mid2>::value),
							high_in2=(binary::template right_half<mid2>::value);
					// mid1, mid2 are now free.

					mid2=low_in1*high_in2;
					mid1=high_in1*low_in2+mid2; // possible carry of 1.

					low_in2*=low_in1;
					low_in1=low_in2+(mid1<<constant::half_length); // possible carry of 1.

					out+=low_in1; // possible carry of 1.

					return high_in1*high_in2+
						(mid1>>constant::half_length)+
						((mid1 < mid2)<<constant::half_length)+
						(low_in1 < low_in2)+
						(out < low_in1);
					// uses mid1, mid2, low_in1, high_in1, low_in2, high_in2, 
				}

/*
	The return value is the quotient of the division.
	out is the remainder from the division.
	in1 is the first digit of the dividend with base as size_type.
	in2 is the second digit of the dividend with base as size_type.
	d is the divisor.

	This algorithm is highly optimized and only works (semantically) if in1 < d.

	Let in1=|w3|w2| and in2=|w1|w0| with d=|y1|y0|.
	Since in1 < d, then (|y1| > |w3|) or (|y1|==|w3| and |y0| > |w2|).
	For the "single digit case", this means |y1|=0 which implies |w3|=0 and |y0| > |w2|.
	This is used to optimize the single digit case.
*/
				template<typename ValueType>
				static ValueType quotient_remainder(ValueType & out, ValueType in1, ValueType in2, ValueType d)
				{
					if (!d || d == 1)
					{ // these cases make no sense for this particular optimized version of division.
						out=0;
						return 0;
					}
					else if (d == 2)
					{ // this meeans (in1 == 1):
						out=(in2 & 1);
						return (in2>>1)+((in1 & 1)<<(constant::register_length-1));
					}
					else
					{
						ValueType	low_in2 =(binary::template left_half<in2>::value),
								high_in2=(binary::template right_half<in2>::value);

						if (d < constant::half_length)
						{
							// in2 is now free.
							in2=(in1<<constant::half_length)+high_in2;
							// in1, high_in2 are now free.
							in1=in2/d; high_in2=in2%d;

							in1<<=constant::half_length;
							(high_in2<<=constant::half_length)+=low_in2;
							// low_in2 is now free.

							low_in2=high_in2/d; out=high_in2%d;

							return in1+low_in2;
						}
						else
						{
							ValueType	low_in1 =(binary::template left_half<in1>::value),
									high_in1=(binary::template right_half<in1>::value);

//							ValueType sub2(0), sub1=times(sub2, in1, r);
						}
					}
				}
/*
				template<typename ValueType>
				static ValueType quotient_remainder(ValueType & out,
					ValueType in1, ValueType in2, ValueType d, ValueType q, ValueType r)
				{
					if (r == d)
					{ // assumption is the compiler will optimize '/','%' operations.
						r=in2/d;
						out=in2%d;
						return in1*(++q)+r;
					}
					else
					{
						ValueType low, high=times(low, in1, r);
						ValueType high1=high*r, high_q=high1/d, high_r=high1%d;
						ValueType low_q=low/d, low_r=low%d;

						ValueType r1=high_r+low_r;
						ValueType q1=high*q+high_q+low_q+(r1 < high_r);

						high1=in2/d;
						out=r1+in2%d;
						return in1*q+q1+high1+(out < r1);
					}
				}
*/
			};
		}
	}
}

#endif
