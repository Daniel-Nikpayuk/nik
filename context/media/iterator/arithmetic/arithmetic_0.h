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

#ifndef CONTEXT_ITERATOR_ARITHMETIC_0_H
#define CONTEXT_ITERATOR_ARITHMETIC_0_H

#include<stddef.h>

// Clean up the typedefs/usings namespace stuff.

// overhead dependencies:
#include"../../../context/constant.h"

/*
	Incrementing and decrementing pointers which should otherwise maintain a constant location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using these such unrolling in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.

	The main difference between "componentwise" and "arithmetic" from an algorithmic lens is that componentwise is each location
	is conditionally independent, whereas arithmetic is similar but also dependent on the previous value (recursive; maybe the
	simplest variety of recursive?).
*/

namespace nik
{
	namespace context
	{
		namespace iterator
		{
			namespace forward
			{
				template<typename size_type>
				struct arithmetic_0
				{
					typedef meta::constant<size_type> constant;
/*
	Assumes (in) iteratively greater than (end).
*/
					template<typename OutputIterator, typename InputIterator, typename TerminalIterator>
					static void bit_right_shift(OutputIterator out, InputIterator in, TerminalIterator end, size_type n)
					{
						size_type N=constant::register_length-n;
						*out=(*in>>n);
						++in;

						while (in != end)
						{
							*out+=(*in<<N);
							*(++out)=(*in>>n);
							++in;
						}
					}

/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
					template<size_type N, typename Filler=void>
					struct unroll_0
					{
/*
*/
						template<typename Iterator>
						static bool equal(Iterator in1, Iterator in2)
							{ return (*in1 == *in2) && unroll_0<N-1>::equal(++in1, ++in2); }
/*
*/
						template<typename Iterator>
						static bool not_equal(Iterator in1, Iterator in2)
							{ return (*in1 != *in2) || unroll_0<N-1>::not_equal(++in1, ++in2); }
/*
	Choice of (*out < *in2) is intentional as it provides higher entropy---it allows in1 == out (but in2 != out).
*/
						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
						{
							*out=*in1 + *in2 + carry;
							unroll_0<N-1>::plus(++out, ++in1, ++in2, (*out < *in2));
						}

						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void plus_assign(OutputIterator out, InputIterator in, ValueType carry)
						{
							*out+=*in + carry;
							unroll_0<N-1>::plus_assign(++out, ++in, (*out < *in));
						}

/*
	In this case, *out+(*in2+carry)=*in1 implies a new carry if: *in1 < *out or *in1 < (*in2+carry)
	but there's the special case that (*in2+carry) already wraps around [(*in2+carry) < *in2, carry].
	In which case---given 0 <= carry <= 1---it's automatic that there's a new carry (but no need
	of worry about a "double carry" because (*in2+carry) if wrapped around would equal zero.

	Because use of *in1 can't be avoided in the new carry test, it requires out and in1 cannot be shallow copies.

	The assumption is addition is no less optimal than subtraction as the algorithm
	should require fewer tests, hence: *out=*in1-(*in2+carry) instead of *out=*in1-*in2-carry.
*/
						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void minus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
						{
							ValueType tmp(*in2+carry);
							*out=*in1 - tmp;
							unroll_0<N-1>::minus(++out, ++in1, ++in2, (tmp < *in2 || *in1 < *out));
						}
					};

					template<typename Filler>
					struct unroll_0<1, Filler>
					{
						template<typename Iterator>
						static bool equal(Iterator in1, Iterator in2) { return (*in1 == *in2); }
						template<typename Iterator>
						static bool not_equal(Iterator in1, Iterator in2) { return (*in1 != *in2); }

						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
							{ *out=*in1 + *in2 + carry; }

						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void plus_assign(OutputIterator out, InputIterator in, ValueType carry)
							{ *out+=*in + carry; }

						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void minus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
							{ *out=*in1 - (*in2 + carry); }
					};
				};
			}

			namespace backward
			{
				template<typename size_type>
				struct arithmetic_0
				{
					typedef meta::constant<size_type> constant;
/*
	Assumes (in) iteratively greater than (end).
*/
					template<typename OutputIterator, typename InputIterator, typename TerminalIterator>
					static void bit_left_shift(OutputIterator out, InputIterator in, TerminalIterator end, size_type n)
					{
						size_type N=constant::register_length-n;
						*out=(*in<<n);
						--in;

						while (in != end)
						{
							*out+=(*in>>N);
							*(--out)=(*in<<n);
							--in;
						}
					}

/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
					template<size_type N, typename Filler=void>
					struct unroll_0
					{
/*
*/
						template<typename Iterator>
						static bool less_than(Iterator in1, Iterator in2)
						{
							if (*in1 != *in2) return (*in1 < *in2);
							else return unroll_0<N-1>::less_than(--in1, --in2);
						}
/*
*/
						template<typename Iterator>
						static bool less_than_or_equal(Iterator in1, Iterator in2)
						{
							if (*in1 != *in2) return (*in1 < *in2);
							else return unroll_0<N-1>::less_than_or_equal(--in1, --in2);
						}
/*
*/
						template<typename Iterator>
						static bool greater_than(Iterator in1, Iterator in2)
						{
							if (*in1 != *in2) return (*in1 > *in2);
							else return unroll_0<N-1>::greater_than(--in1, --in2);
						}
/*
*/
						template<typename Iterator>
						static bool greater_than_or_equal(Iterator in1, Iterator in2)
						{
							if (*in1 != *in2) return (*in1 > *in2);
							else return unroll_0<N-1>::greater_than_or_equal(--in1, --in2);
						}

						template<typename Iterator>
						static Iterator significant_digit(Iterator in)
						{
							if (*in) return in;
							else return unroll_0<N-1>::significant_digit(--in);
						}
					};

					template<typename Filler>
					struct unroll_0<1, Filler>
					{
						template<typename Iterator>
						static bool less_than(Iterator in1, Iterator in2) { return (*in1 < *in2); }
						template<typename Iterator>
						static bool less_than_or_equal(Iterator in1, Iterator in2) { return (*in1 <= *in2); }
						template<typename Iterator>
						static bool greater_than(Iterator in1, Iterator in2) { return (*in1 > *in2); }
						template<typename Iterator>
						static bool greater_than_or_equal(Iterator in1, Iterator in2) { return (*in1 >= *in2); }

						template<typename Iterator>
						static Iterator significant_digit(Iterator in) { return in; }
					};
				};
			}

			namespace bidirectional
			{
				template<typename size_type>
				struct arithmetic_0
				{
				};
			}
		}
	}
}

#endif
