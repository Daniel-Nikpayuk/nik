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

#ifndef CONTEXT_BLOCK_H
#define CONTEXT_BLOCK_H

#include<stddef.h>

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
/*
			block:
				typename The minimal specification (axiomatic properties) of a block class are:
				typedefs:
				constructors:
				accessors:
*/
		template<typename size_type>
		struct block
		{
			static const size_type bit_length = (8*sizeof(size_type));
			static const size_type half_length = (bit_length>>1);
			static const size_type low_pass = ((size_type) 1<<half_length)-1;

/*
	Has been optimized, but it might just be better to not reuse variables for reading clarity,
	and just let the compiler optimize.

	Adds to the existing out regardless of its initial value.


	if 1 < base, then 0 < base-1.
	Since -1 < 1, then base-1 < base+1.
	Hence (base-1)^2 < base^2-1.
	Thus carry < base^2.
*/
			template<typename ValueType>
			static ValueType times(ValueType & out, ValueType mid1, ValueType mid2)
			{
				ValueType low_in1=(low_pass & mid1), high_in1 = (mid1>>half_length);
				ValueType low_in2=(low_pass & mid2), high_in2 = (mid2>>half_length);
					// mid1, mid2 are now free.

				mid2=low_in1*high_in2;
				mid1=high_in1*low_in2+mid2; // possible carry of 1.

				low_in2*=low_in1;
				low_in1=low_in2+(mid1<<half_length); // possible carry of 1.

				out+=low_in1; // possible carry of 1.

				return high_in1*high_in2+
					(mid1>>half_length)+
					((mid1 < mid2)<<half_length)+
					(low_in1 < low_in2)+
					(out < low_in1);
			}
/*
	recursive:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The recursive struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
			template<size_type N, typename Filler=void>
			struct recursive
			{
/*
	Assumes ascending order.
*/
				template<typename Iterator>
				static bool equal(Iterator in1, Iterator in2)
					{ return (*in1 == *in2) && recursive<N-1>::equal(++in1, ++in2); }
/*
	Assumes ascending order.
*/
				template<typename Iterator>
				static bool not_equal(Iterator in1, Iterator in2)
					{ return (*in1 != *in2) || recursive<N-1>::not_equal(++in1, ++in2); }
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool less_than(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					else return recursive<N-1>::less_than(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool less_than_or_equal(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					else return recursive<N-1>::less_than_or_equal(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool greater_than(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					else return recursive<N-1>::greater_than(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool greater_than_or_equal(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					else return recursive<N-1>::greater_than_or_equal(--in1, --in2);
				}
/*
	Assumes ascending order.
*/
				template<typename OutputIterator, typename InputIterator>
				static void copy(OutputIterator out, InputIterator in)
				{
					*out=*in;
					recursive<N-1>::copy(++out, ++in);
				}
/*
	Assumes ascending order.
*/
				template<typename Iterator, typename ValueType>
				static void assign(Iterator out, ValueType in)
				{
					*out=in;
					recursive<N-1>::assign(++out, in);
				}
/*
	Assumes ascending order.
*/
				template<typename Iterator, typename ValueType>
				static Iterator rep(Iterator out, ValueType in)
				{
					*out=in;
					return recursive<N-1>::rep(++out, in);
				}
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.
				static void left_shift(typename Block::pointer out,
					typename Block::size_type in, typename Block::value_type carry)
				{
					typename Block::value_type new_carry=*out>>(bit_length-in);
					(*out<<=in)+=carry;
					recursive<Block, N-1>::left_shift(++out, ++in);
				}
		
				static void left_shift(typename Block::pointer out,
					typename Block::size_type in, typename Block::value_type carry)
				{
					typename Block::value_type new_carry=*out>>(bit_length-in);
					(*out<<=in)+=carry;
					recursive<Block, N-1>::left_shift(++out, ++in);
				}
*/
/*
	Assumes ascending order.
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
				{
					*out=*in1 + *in2 + carry;
					recursive<N-1>::plus(++out, ++in1, ++in2, (*out < *in1));
				}
/*
	Assumes ascending order.

	Obfuscated code ?
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void scale(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
					{ recursive<N-1>::scale(++out, ++in1, ++in2, times(*out=carry, *in1, *in2)); }
/*
				static void asterisk
				{
					recursive<N>::scale(recursive<N-M>::rep(out, 0), in)
				}
*/
			};

			template<typename Filler>
			struct recursive<1, Filler>
			{
				template<typename Iterator>
				static bool equal(Iterator in1, Iterator in2) { return (*in1 == *in2); }
				template<typename Iterator>
				static bool not_equal(Iterator in1, Iterator in2) { return (*in1 != *in2); }

				template<typename Iterator>
				static bool less_than(Iterator in1, Iterator in2) { return (*in1 < *in2); }
				template<typename Iterator>
				static bool less_than_or_equal(Iterator in1, Iterator in2) { return (*in1 <= *in2); }
				template<typename Iterator>
				static bool greater_than(Iterator in1, Iterator in2) { return (*in1 > *in2); }
				template<typename Iterator>
				static bool greater_than_or_equal(Iterator in1, Iterator in2) { return (*in1 >= *in2); }

				template<typename OutputIterator, typename InputIterator>
				static void copy(OutputIterator out, InputIterator in) { *out=*in; }
				template<typename Iterator, typename ValueType>
				static void assign(Iterator out, ValueType in) { *out=in; }
				template<typename Iterator, typename ValueType>
				static Iterator rep(Iterator out, ValueType in) { *out=in; return out; }

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
					{ *out=*in1 + *in2 + carry; }
/*
	Obfuscated code ?
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void scale(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
					{ times(*out=carry, *in1, *in2); }
			};
		};
	}
}

#endif
