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

#ifndef CONTEXT_ITERATOR_ARITHMETIC_1_H
#define CONTEXT_ITERATOR_ARITHMETIC_1_H

// Clean up the typedefs/usings namespace stuff.

#include"arithmetic_0.h"

#include"../../../semiotic/regist/regist.h"
#include"../componentwise/componentwise.h"

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
				struct arithmetic_1 : public arithmetic_0<size_type>
				{
					typedef meta::constant<size_type> constant;
					typedef semiotic::regist<size_type> regist;
					typedef recursive<size_type> fwd_recu;

					static const size_type register_length=constant::register_length;

					using arithmetic_0<size_type>::bit_right_shift;
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
					struct unroll_1 : public unroll_0<N, Filler>
					{
/*
*/
						template<typename Iterator>
						static bool equal(Iterator in1, Iterator in2)
							{ return (*in1 == *in2) && unroll<N-1>::equal(++in1, ++in2); }
/*
*/
						template<typename Iterator>
						static bool not_equal(Iterator in1, Iterator in2)
							{ return (*in1 != *in2) || unroll<N-1>::not_equal(++in1, ++in2); }
/*
	Choice of (*out < *in2) is intentional as it provides higher entropy---it allows in1 == out (but in2 != out).
*/
						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
						{
							*out=*in1 + *in2 + carry;
							unroll<N-1>::plus(++out, ++in1, ++in2, (*out < *in2));
						}

						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void plus_assign(OutputIterator out, InputIterator in, ValueType carry)
						{
							*out+=*in + carry;
							unroll<N-1>::plus_assign(++out, ++in, (*out < *in));
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
							unroll<N-1>::minus(++out, ++in1, ++in2, (tmp < *in2 || *in1 < *out));
						}
/*
	Obfuscated code ?
*/
						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void scale(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
							{ unroll<N-1>::scale(++out, ++in1, in2,
								regist::multiply::return_high(*out=carry, *in1, in2)); }

						template<size_type M, typename SubFiller=void>
						struct subroll
						{
/*
	Does not assume anything about the existing value of out1.

	Is it worth testing for *in2 == 0 ?
*/
							template<typename OutputIterator, typename InputIterator>
							static void asterisk(OutputIterator out1,
								OutputIterator out2, InputIterator in1, InputIterator in2)
							{
								unroll<M>::scale(fwd_recu::template unroll<N-M>::
									repeat_return(out2, 0), in1, *in2, (size_type) 0);
								plus_assign(out1, out2, 0);
								subroll<M-1>::asterisk(out1, out2, in1, ++in2);
							}
						};

						template<typename SubFiller>
						struct subroll<1, SubFiller>
						{
							template<typename OutputIterator, typename InputIterator>
							static void asterisk(OutputIterator out1,
								OutputIterator out2, InputIterator in1, InputIterator in2)
							{
								unroll<1>::scale(fwd_recu::template unroll<N-1>::
									repeat_return(out2, 0), in1, *in2, (size_type) 0);
								plus_assign(out1, out2, 0);
							}
						};
					};

					template<typename Filler>
					struct unroll<1, Filler>
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

/*
	Obfuscated code ?
*/
						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void scale(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
							{ regist::multiply::return_high(*out=carry, *in1, in2); }
					};
				};
			}

			namespace backward
			{
				template<typename size_type>
				struct arithmetic_1 : public arithmetic_0<size_type>
				{
					typedef meta::constant<size_type> constant;
					typedef recursive<size_type> bwd_recu;

					static const size_type register_length=constant::register_length;
/*
	Assumes (in) iteratively greater than (end).
*/
					template<typename OutputIterator, typename InputIterator, typename TerminalIterator>
					static void bit_left_shift(OutputIterator out, InputIterator in, TerminalIterator end, size_type n)
					{
						size_type N=register_length-n;
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
					struct unroll
					{
/*
*/
						template<typename Iterator>
						static bool less_than(Iterator in1, Iterator in2)
						{
							if (*in1 != *in2) return (*in1 < *in2);
							else return unroll<N-1>::less_than(--in1, --in2);
						}
/*
*/
						template<typename Iterator>
						static bool less_than_or_equal(Iterator in1, Iterator in2)
						{
							if (*in1 != *in2) return (*in1 < *in2);
							else return unroll<N-1>::less_than_or_equal(--in1, --in2);
						}
/*
*/
						template<typename Iterator>
						static bool greater_than(Iterator in1, Iterator in2)
						{
							if (*in1 != *in2) return (*in1 > *in2);
							else return unroll<N-1>::greater_than(--in1, --in2);
						}
/*
*/
						template<typename Iterator>
						static bool greater_than_or_equal(Iterator in1, Iterator in2)
						{
							if (*in1 != *in2) return (*in1 > *in2);
							else return unroll<N-1>::greater_than_or_equal(--in1, --in2);
						}

						template<typename Iterator>
						static Iterator significant_digit(Iterator in)
						{
							if (*in) return in;
							else return unroll<N-1>::significant_digit(--in);
						}
					};

					template<typename Filler>
					struct unroll<1, Filler>
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
				struct arithmetic_1 : public arithmetic_0<size_type>
				{
					typedef meta::constant<size_type> constant;

					typedef forward::arithmetic_1<size_type> fwd_arit;
					typedef backward::arithmetic_1<size_type> bwd_arit;

					typedef forward::componentwise fwd_comp;
					typedef backward::componentwise bwd_comp;

					typedef forward::recursive<size_type> fwd_recu;
					typedef backward::recursive<size_type> bwd_recu;

					static const size_type register_length=constant::register_length;
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Keep in mind technically you cannot say out+diff > out-1 because if (out == 0) it could wrap around due to modular arithmetic.
	Otherwise, because the comparison used is (!=) it still works.
*/
					template<typename OutputIterator>
					static void left_shift_assign(OutputIterator out, size_type length, size_type arr, size_type bit)
					{
						size_type last(length-1), diff(last-arr);
						bwd_arit::template bit_left_shift<OutputIterator, OutputIterator,
							const OutputIterator>(out+last, out+diff, out-1, bit);
						fwd_comp::repeat<OutputIterator, const OutputIterator>(out, out+arr, 0);
					}
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Keep in mind technically you cannot say out+diff > out-1 because if (out == 0) it could wrap around due to modular arithmetic.
	Otherwise, because the comparison used is (!=) it still works.

	*** Needs to test if &out == &in, a problematic case. Such code NOT yet implemented.
*/
					template<typename OutputIterator, typename InputIterator>
					static void left_shift(OutputIterator out,
						InputIterator in, size_type length, size_type arr, size_type bit)
					{
						size_type last(length-1), diff(last-arr);
						bwd_arit::template bit_left_shift<OutputIterator, InputIterator,
							const InputIterator>(out+last, in+diff, in-1, bit);
						fwd_comp::repeat<OutputIterator, const OutputIterator>(out, out+arr, 0);
					}
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.
*/
					template<typename OutputIterator>
					static void right_shift_assign(OutputIterator out, size_type length, size_type arr, size_type bit)
					{
						size_type last(length-1), diff(last-arr);
						fwd_arit::template bit_right_shift<OutputIterator, OutputIterator,
							const OutputIterator>(out, out+arr, out+length, bit);
						bwd_comp::repeat<OutputIterator, const OutputIterator>(out+last, out+diff, 0);
					}

/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	*** Needs to test if &out == &in, a problematic case. Such code NOT yet implemented.
*/
					template<typename OutputIterator, typename InputIterator>
					static void right_shift(OutputIterator out,
						InputIterator in, size_type length, size_type arr, size_type bit)
					{
						size_type last(length-1), diff(last-arr);
						fwd_arit::template bit_right_shift<OutputIterator, InputIterator,
							const InputIterator>(out, in+arr, in+length, bit);
						bwd_comp::repeat<OutputIterator, const OutputIterator>(out+last, out+diff, 0);
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
					struct unroll
					{
						template<size_type M, typename SubFiller=void>
						struct subroll
						{
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Hasn't been tested.
*/
							template<typename OutputIterator, typename ValueType>
							static void left_shift_assign(OutputIterator out)
							{
								bwd_recu::template unroll<N-M>::assign(out+(N-1), out+(M-1));
								fwd_recu::template unroll<M>::repeat(out, 0);
							}
						};

						template<typename SubFiller>
						struct subroll<1, SubFiller>
						{
							template<typename OutputIterator, typename ValueType>
							static void left_shift_assign(OutputIterator out)
							{
								bwd_recu::template unroll<N-1>::assign(out+(N-1), out);
								fwd_recu::template unroll<1>::repeat(out, 0);
							}
						};
					};

					template<typename Filler>
					struct unroll<1, Filler>
					{
					};
				};
			}
		}
	}
}

#endif
