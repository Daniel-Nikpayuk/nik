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
					typedef componentwise<size_type> fwd_comp;

					typedef arithmetic_0<size_type> arit_0;
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
					struct unroll_1 : public arit_0::template unroll_0<N, Filler>
					{
/*
	Obfuscated code ?
*/
						template<typename OutputIterator, typename InputIterator, typename ValueType>
						static void scale(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
							{ unroll_1<N-1>::scale(++out, ++in1, in2,
								regist::multiply::return_high(*out=carry, *in1, in2)); }

						template<size_type M, typename SubFiller=void>
						struct subroll_1
						{
/*
	Does not assume anything about the existing value of out1.

	Is it worth testing for *in2 == 0 ?
*/
							template<typename OutputIterator, typename InputIterator>
							static void multiply(OutputIterator out1,
								OutputIterator out2, InputIterator in1, InputIterator in2)
							{
								unroll_1<M>::scale(fwd_comp::template unroll<N-M>::
									repeat::with_return(out2, 0), in1, *in2, (size_type) 0);
								plus_assign(out1, out2, 0);
								subroll_1<M-1>::multiply(out1, out2, in1, ++in2);
							}
						};

						template<typename SubFiller>
						struct subroll_1<1, SubFiller>
						{
							template<typename OutputIterator, typename InputIterator>
							static void multiply(OutputIterator out1,
								OutputIterator out2, InputIterator in1, InputIterator in2)
							{
								unroll_1<1>::scale(fwd_comp::template unroll<N-1>::
									repeat::with_return(out2, 0), in1, *in2, (size_type) 0);
								plus_assign(out1, out2, 0);
							}
						};
					};

					template<typename Filler>
					struct unroll_1<1, Filler>
					{
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
					typedef semiotic::regist<size_type> regist;
					typedef componentwise<size_type> bwd_comp;

					typedef arithmetic_0<size_type> arit_0;

					template<size_type N, typename Filler=void>
					struct unroll_1 : public arit_0::template unroll_0<N, Filler>
					{
						template<typename OutputIterator>
						static OutputIterator order(OutputIterator out)
						{
							if (*out) return out;
							else return unroll_1<N-1>::order(--out);
						}

						struct divide
						{
							struct single_digit
							{
								template<typename OutputIterator, typename InputIterator, typename ValueType>
								static ValueType half_register_divisor(OutputIterator out,
									InputIterator in, ValueType d, ValueType carry)
								{
									if (carry)
									{
										if (carry < d)
										{
											// carry is assumed more current than *in.
											--out; --in;
											*out=regist::divide::half_register_divisor(
												carry, ValueType(carry), *in, d);
											return unroll_1<N-1>::divide::single_digit::
												half_register_divisor(out, in, d, carry);
										}
										else
										{
											*out=carry/d;
											carry=carry%d;
											return unroll_1<N-1>::divide::single_digit::
												half_register_divisor(out, in, d, carry);
										}
									}
									else
									{
										*out=0;
										return unroll_1<N-1>::divide::single_digit::
											half_register_divisor(--out, --in, d, *in);
									}
								}

/*
	"out" is the retainer of the returned quotient.
	"carry" is a memory optimization hack. When calling this function, carry needs to be set to *in.
	Assumes "in" is the leftmost digit of the structure.

	Assumes "d" is the divisor and that in >= 3.
	If d == 1 why use this at all?
	If d == 2 use bit shifting.
*/
								template<typename OutputIterator, typename InputIterator, typename ValueType>
								static ValueType full_register_divisor(OutputIterator out,
									InputIterator in, ValueType d, ValueType carry)
								{
									if (carry)
									{
										if (carry < d)
										{
											// carry is assumed more current than *in.
											--out; --in;
											*out=regist::divide::full_register_divisor(
												carry, ValueType(carry), *in, d);
											return unroll_1<N-1>::divide::single_digit::
												full_register_divisor(out, in, d, carry);
										}
										else
										{
											*out=carry/d;
											carry=carry%d;
											return unroll_1<N-1>::divide::single_digit::
												full_register_divisor(out, in, d, carry);
										}
									}
									else
									{
										*out=0;
										return unroll_1<N-1>::divide::single_digit::
											full_register_divisor(--out, --in, d, *in);
									}
								}
							};
						};
					};

					template<typename Filler>
					struct unroll_1<1, Filler>
					{
						template<typename OutputIterator>
						static OutputIterator order(OutputIterator out)
							{ return out; }

						struct divide
						{
							struct single_digit
							{
								template<typename OutputIterator, typename InputIterator, typename ValueType>
								static ValueType half_register_divisor(OutputIterator out,
									InputIterator in, ValueType d, ValueType carry)
								{
									if (carry < d)
									{
										*out=0;
										return carry;
									}
									else
									{
										*out=carry/d;
										return carry%d;
									}
								}

								template<typename OutputIterator, typename InputIterator, typename ValueType>
								static ValueType full_register_divisor(OutputIterator out,
									InputIterator in, ValueType d, ValueType carry)
								{
									if (carry < d)
									{
										*out=0;
										return carry;
									}
									else
									{
										*out=carry/d;
										return carry%d;
									}
								}
							};
						};
					};
				};
			}

			namespace bidirectional
			{
				template<typename size_type>
				struct arithmetic_1 : public arithmetic_0<size_type>
				{
				};
			}

			namespace random_access
			{
				template<typename size_type>
				struct arithmetic_1 : public arithmetic_0<size_type>
				{
					typedef meta::constant<size_type> constant;

					typedef forward::arithmetic_1<size_type> fwd_arit;
					typedef backward::arithmetic_1<size_type> bwd_arit;

					typedef forward::componentwise<size_type> fwd_comp;
					typedef backward::componentwise<size_type> bwd_comp;

					typedef arithmetic_0<size_type> arit_0;
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.
*/
					template<typename OutputIterator, typename InputIterator, typename TerminalIterator>
					static void left_shift_assign(OutputIterator out, InputIterator in, TerminalIterator end, size_type n)
					{
						bwd_arit::template bit_left_shift(out, in, end, n);
						fwd_comp::repeat::no_return(end+1, end+(out-in), 0);
					}
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Does not test if &out == &in, a problematic case.
*/
					template<typename OutputIterator, typename InputIterator>
					static void left_shift(OutputIterator out,
						InputIterator in, size_type length, size_type arr, size_type bit)
					{
						size_type last(length-1), diff(last-arr);
						bwd_arit::template bit_left_shift<OutputIterator, InputIterator,
							const InputIterator>(out+last, in+diff, in-1, bit);
						fwd_comp::repeat::no_return(out, 0);
					}
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	*** Currently broken as componentwise definitions have changed.
*/
					template<typename OutputIterator>
					static void right_shift_assign(OutputIterator out, size_type length, size_type arr, size_type bit)
					{
						size_type last(length-1), diff(last-arr);
						fwd_arit::template bit_right_shift<OutputIterator, OutputIterator,
							const OutputIterator>(out, out+arr, out+length, bit);
						bwd_comp::repeat::no_return(out+last, 0);
					}

/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	*** Needs to test if &out == &in, a problematic case. Such code NOT yet implemented.

	*** Currently broken as componentwise definitions have changed.
*/
					template<typename OutputIterator, typename InputIterator>
					static void right_shift(OutputIterator out,
						InputIterator in, size_type length, size_type arr, size_type bit)
					{
						size_type last(length-1), diff(last-arr);
						fwd_arit::template bit_right_shift<OutputIterator, InputIterator,
							const InputIterator>(out, in+arr, in+length, bit);
						bwd_comp::repeat::no_return(out+last, 0);
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
					struct unroll_1 : public arit_0::template unroll_0<N, Filler>
					{
						template<size_type M, typename SubFiller=void>
						struct subroll_1
						{
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Hasn't been tested.

	*** Currently broken as componentwise definitions have changed.
*/
							template<typename OutputIterator, typename ValueType>
							static void left_shift_assign(OutputIterator out)
							{
								bwd_comp::template unroll<N-M>::assign::no_return(out+(N-1), out+(M-1));
								fwd_comp::template unroll<M>::repeat::no_return(out, 0);
							}
						};
						template<typename SubFiller>
						struct subroll_1<1, SubFiller>
						{
/*
	*** Currently broken as componentwise definitions have changed.
*/
							template<typename OutputIterator, typename ValueType>
							static void left_shift_assign(OutputIterator out)
							{
								bwd_comp::template unroll<N-1>::assign::no_return(out+(N-1), out);
								fwd_comp::template unroll<1>::repeat::no_return(out, 0);
							}
						};
					};

					template<typename Filler>
					struct unroll_1<1, Filler>
					{
					};
				};
			}
		}
	}
}

#endif
