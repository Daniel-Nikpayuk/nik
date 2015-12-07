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

#include"../../../context/context/constant.h"

// #include"../../../debug.h"

/*
	The general media space should also have its own "register" class, but as the design there is intended
	to be user-friendly "safe" there is a need to keep another register class here. As this is within the
	general context space, it is assumed generic, and so its template parameters should be coded with that in mind.

	As regist types are intended to hold int types, it's more efficient to pass the given value_type instead of
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
			regist:
				typename The minimal specification (axiomatic properties) of a block class are:
				typedefs:
				constructors:
				accessors:
*/
			template<typename size_type>
			struct regist
			{
				typedef meta::constant<size_type> constant;
/*
	less_than_or_equal:

	This is redundant, you can use the unrolling code of arithmetic, but this should be optimized as highly as possible,
	which, given the unrolling nature of its equivalent within arithmetic, it may not be. Test!
*/
				template<typename ValueType>
				static bool less_than_or_equal(ValueType in0, ValueType in1, ValueType in2, ValueType in3)
					{ return (in0 < in2 || (in0 == in2) && in1 <= in3); }

				template<typename ValueType>
				static ValueType shift_up(ValueType in, size_type n)
					{ return in<<n; }

					// common enough to optimize:
				template<typename ValueType>
				static ValueType shift_up(ValueType in)
					{ return in<<constant::half_length; }

				template<typename ValueType>
				static ValueType shift_down(ValueType in, size_type n)
					{ return in>>n; }

					// common enough to optimize:
				template<typename ValueType>
				static ValueType shift_down(ValueType in)
					{ return in>>constant::half_length; }
/*
	Interface Design: Should be oriented around locations similar to array access. Use s,t (s < t) as default location names.

	Should the code here be manually expanded so as to not rely on function calls? Will the compiler optimize?
*/
				template<typename ValueType>
				static ValueType low_pass(size_type t)
					{ return shift_up((ValueType) 1, t)-1; }

				template<typename ValueType>
				static ValueType high_pass(size_type s)
					{ return ~low_pass<ValueType>(s); }

				template<typename ValueType>
				static ValueType band_pass(size_type s, size_type t)
					{ return low_pass<ValueType>(t-s)<<s; }

				template<typename ValueType>
				static ValueType low(ValueType in, size_type t)
					{ return (in & low_pass<ValueType>(t)); }

					// common enough to optimize:
				template<typename ValueType>
				static ValueType low(ValueType in)
					{ return (in & constant::low_pass); }

				template<typename ValueType>
				static ValueType high(ValueType in, size_type s)
					{ return shift_down(in, s); }

					// common enough to optimize:
				template<typename ValueType>
				static ValueType high(ValueType in)
					{ return in>>constant::half_length; }

				template<typename ValueType>
				static ValueType mid(ValueType in, size_type s, size_type t)
					{ return low(shift_down(in, s), t-s); }

				template<size_type N, typename Filler=void>
				struct unroll
				{
/*
	order:

	Finds the index of the leading digit of the register number using the half-point method.
*/
					template<typename ValueType>
					static size_type order(ValueType primary, ValueType secondary)
					{
						ValueType m=mid<ValueType>(secondary, (N>>1), N);
						if (m) primary+=(N>>1);
						else m=mid(secondary, (size_type) 0, (N>>1));

						unroll<(N>>1)>::order(primary, m);
					}
				};

				template<typename Filler>
				struct unroll<0, Filler>
				{
					template<typename ValueType>
					static size_type order(ValueType primary, ValueType secondary)
						{ return primary; }
				};

				template<typename ValueType>
				static ValueType order(ValueType in)
					{ return unroll<constant::register_length>::order((ValueType) 0, in); }
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
					template<typename ValueType>
					static ValueType return_low(ValueType & out, ValueType mid1, ValueType mid2)
					{
						ValueType	little_in1=low(mid1),
								big_in1=high(mid1),
								little_in2=low(mid2),
								big_in2=high(mid2);
						// mid1, mid2 are now free.

						mid2=little_in1*big_in2;
						mid1=big_in1*little_in2+mid2; // possible carry of 1.

						little_in2*=little_in1;
						little_in1=little_in2+shift_up(mid1); // possible carry of 1.

						big_in1*=big_in2;
						// big_in2, is now free.
						big_in2=out+little_in1;

						out=big_in1+
							shift_down(mid1)+
							shift_up(mid1 < mid2)+
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
					template<typename ValueType>
					static ValueType return_high(ValueType & out, ValueType mid1, ValueType mid2)
					{
						ValueType	little_in1=low(mid1),
								big_in1=high(mid1),
								little_in2=low(mid2),
								big_in2=high(mid2);
						// mid1, mid2 are now free.

						mid2=little_in1*big_in2;
						mid1=big_in1*little_in2+mid2; // possible carry of 1.

						little_in2*=little_in1;
						little_in1=little_in2+shift_up(mid1); // possible carry of 1.

						out+=little_in1; // possible carry of 1.

						return big_in1*big_in2+
							shift_down(mid1)+
							shift_up(mid1 < mid2)+
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
					template<typename ValueType>
					static ValueType divisor_equals_2(ValueType & out, ValueType in2)
					{
						out=(in2 & (ValueType) 1);
						return constant::max_binary_power+(in2>>1);
					}
/*
	The case where d is at most a half register can be optimized as follows:

	Let in1=|w3|w2| and in2=|w1|w0| with d=|y1|y0|.
	Since d > in1, we have (|y1| > |w3|) or (|y1|==|w3| and |y0| > |w2|).
	For the "single digit case", this means |y1|=0 which implies |w3|=0 and |y0| > |w2|.
*/
					template<typename ValueType>
					static ValueType half_register_divisor(ValueType & out, ValueType in1, ValueType in2, ValueType d)
					{
						ValueType	little_in2=low(in2),
								big_in2=high(in2);

						// in2 is now free.
						in2=shift_up(in1)+big_in2;
						// in1, high_in2 are now free.
						in1=in2/d; big_in2=in2%d;

						in1<<=constant::half_length;
						(big_in2<<=constant::half_length)+=little_in2;
						// little_in2 is now free.

						little_in2=big_in2/d; out=big_in2%d;

						return in1+little_in2;
					}

/*
	Assumes d >= b/2 and in1 < b/2 and "mid" < d.
*/
					template<typename ValueType>
					static ValueType partial_register_divisor(ValueType & r,
						ValueType in1, ValueType in2, ValueType d, ValueType big_d)
					{
						ValueType	mid=shift_up(in1)+high(in2),
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
					template<typename ValueType>
					static ValueType full_register_divisor(ValueType & r, ValueType in1, ValueType in2, ValueType d)
					{
						ValueType pivot=order(d)+1;
						ValueType scale=constant::register_length-pivot;

							// normalize:
								// one need not worry about the big value of in1 as in1 < d to begin with.
								// if d doesn't "go over" when shifting, neither will in1.
								// normalizing does not change the fact that in1 < d.
						(in1<<=scale)+=high(in2, pivot);
						in2<<=scale;
						d<<=scale;

							// setup:
						ValueType	mid=shift_up(in1)+high(in2),
								big_d=high(d),
								q=shift_up(partial_register_divisor(pivot, high(in1), mid, d, big_d));

						mid=shift_up(pivot)+low(in2);
						q+=partial_register_divisor(r, high(pivot), mid, d, big_d);

						r>>=scale;

						return q;
					}
/*
	return_quotient:

	The return value is the quotient of the division.
	out is the remainder from the division.
	in1 is the first digit of the dividend and is such that in1 != 0.
	in2 is the second digit of the dividend.
	d is the divisor and is such that in1 < d. Given in1 != 0, this implies 2 <= d.
*/
					template<typename ValueType>
					static ValueType return_quotient(ValueType & out, ValueType in1, ValueType in2, ValueType d)
					{
						if (d == (ValueType) 2) return divisor_equals_2(out, in2);
						else if (d < shift_up((ValueType) 1)) return half_register_divisor(out, in1, in2, d);
						else return full_register_divisor(out, in1, in2, d);
					}
				};
			};
		}
	}
}

#endif
