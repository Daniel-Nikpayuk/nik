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

#include"../../../semiotic/regist/regist.h"
#include"../componentwise/componentwise.h"

// Clean up the typedefs/usings namespace stuff.

#include"arithmetic_0.h"

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

					typedef arithmetic_0<size_type> fwd_arit;
/*
	From in1--end1, shifts by n and stores starting at out; continues by repeating 0 until end.

	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Does not test if &out == &in, a problematic case.
*/
					template<typename OutputIterator, typename InputIterator, typename TerminalIterator>
					static void right_shift(OutputIterator out,
						OutputIterator end, InputIterator in1, TerminalIterator end1, size_type n)
					{
						fwd_comp::repeat::no_return(
							fwd_arit::right_shift::with_return(out,
								in1, ++InputIterator(in1), end1, n, constant::register_length-n),
							end, 0);
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
					struct unroll_1 : public fwd_arit::template unroll_0<N, Filler>
					{
						template<size_type M>
						using fwd_unroll=typename fwd_arit::template unroll_0<M, Filler>;
/*
	Obfuscated code ?
*/
						struct scale
						{
							template<typename OutputIterator, typename InputIterator, typename ValueType>
							static void no_return(OutputIterator out,
								InputIterator in1, ValueType in2, ValueType carry)
									{ unroll_1<N-1>::scale::no_return(++out, ++in1, in2,
										regist::multiply::return_high(*out=carry, *in1, in2)); }

							template<typename OutputIterator, typename InputIterator, typename ValueType>
							static OutputIterator with_return(OutputIterator out,
								InputIterator in1, ValueType in2, ValueType carry)
									{ return unroll_1<N-1>::scale::with_return(++out, ++in1, in2,
										regist::multiply::return_high(*out=carry, *in1, in2)); }
						};

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
								unroll_1<M>::scale::no_return(fwd_comp::
									template unroll<N-M>::repeat::with_return(out2, 0), in1, *in2, 0);
								fwd_unroll<N>::assign::plus::no_return(out1, out2, 0);
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
								unroll_1<1>::scale::no_return(fwd_comp::
									template unroll<N-1>::repeat::with_return(out2, 0), in1, *in2, 0);
								fwd_unroll<N>::assign::plus::no_return(out1, out2, 0);
							}
						};
					};

					template<typename Filler>
					struct unroll_1<1, Filler>
					{
/*
	Obfuscated code ?
*/
						struct scale
						{
							template<typename OutputIterator, typename InputIterator, typename ValueType>
							static void no_return(OutputIterator out,
								InputIterator in1, ValueType in2, ValueType carry)
									{ regist::multiply::return_high(*out=carry, *in1, in2); }

							template<typename OutputIterator, typename InputIterator, typename ValueType>
							static OutputIterator with_return(OutputIterator out,
								InputIterator in1, ValueType in2, ValueType carry)
									{ regist::multiply::return_high(*out=carry, *in1, in2); return ++out; }
						};
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

					typedef arithmetic_0<size_type> bwd_arit;
/*
	From in1--end1, shifts by n and stores starting at out; continues by repeating 0 until end.

	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Does not test if &out == &in, a problematic case.

	**** needs fixing.
*/
					template<typename OutputIterator, typename InputIterator, typename TerminalIterator>
					static void left_shift(OutputIterator out,
						OutputIterator end, InputIterator in1, TerminalIterator end1, size_type n)
					{
						bwd_comp::repeat::no_return(
							bwd_arit::left_shift::with_return(out,
								in1, --InputIterator(in1), end1, n, constant::register_length-n),
							end, 0);
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
					struct unroll_1 : public bwd_arit::template unroll_0<N, Filler>
					{
						template<size_type M>
						using bwd_unroll=typename bwd_arit::template unroll_0<M>;

						struct divide
						{
/*
	Given the nature of single digit division, the return value is the remainder.
*/
							struct single_digit
							{
/*
	"out" is the retainer of the returned quotient.
	"carry" is a memory optimization hack. When calling this function, carry needs to be set to *in.
	Assumes "in" is the leftmost digit of the structure.

	Is optimized to assume 0 <= carry < d.

	Assumes "d" is the divisor and that in >= 3.
	If d == 1 why use this at all?
	If d == 2 use bit shifting.
*/
								template<typename OutputIterator, typename InputIterator, typename ValueType>
								static ValueType half_register_divisor(OutputIterator out,
									InputIterator in, ValueType d, ValueType carry)
								{
									if (carry) *out=regist::divide::
										half_register_divisor(carry, carry, *in, d);
									else if (*in < d) { *out=0; carry=*in; }
									else { *out=*in/d; carry=*in%d; }

									return unroll_1<N-1>::divide::single_digit::
										half_register_divisor(--out, --in, d, carry);
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
									if (carry) *out=regist::divide::
										full_register_divisor(carry, carry, *in, d);
									else if (*in < d) { *out=0; carry=*in; }
									else { *out=*in/d; carry=*in%d; }

									return unroll_1<N-1>::divide::single_digit::
										full_register_divisor(--out, --in, d, carry);
								}
							};

							struct partial_digit
							{
							};
						};
					};

					template<typename Filler>
					struct unroll_1<1, Filler>
					{
						struct divide
						{
							struct single_digit
							{
								template<typename OutputIterator, typename InputIterator, typename ValueType>
								static ValueType half_register_divisor(OutputIterator out,
									InputIterator in, ValueType d, ValueType carry)
								{
									if (carry) *out=regist::divide::
										half_register_divisor(carry, carry, *in, d);
									else if (*in < d) { *out=0; carry=*in; }
									else { *out=*in/d; carry=*in%d; }

									return carry;
								}

								template<typename OutputIterator, typename InputIterator, typename ValueType>
								static ValueType full_register_divisor(OutputIterator out,
									InputIterator in, ValueType d, ValueType carry)
								{
									if (carry) *out=regist::divide::
										full_register_divisor(carry, carry, *in, d);
									else if (*in < d) { *out=0; carry=*in; }
									else { *out=*in/d; carry=*in%d; }

									return carry;
								}
							};

							struct partial_digit
							{
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
					typedef meta::constant<size_type> constant;
					typedef semiotic::regist<size_type> regist;

					typedef forward::componentwise<size_type> fwd_comp;
					typedef backward::componentwise<size_type> bwd_comp;
					typedef componentwise<size_type> bid_comp;

					typedef forward::arithmetic_1<size_type> fwd_arit;
					typedef backward::arithmetic_1<size_type> bwd_arit;
					typedef arithmetic_0<size_type> bid_arit;
				};
			}

			namespace random_access
			{
				template<typename size_type>
				struct arithmetic_1 : public arithmetic_0<size_type>
				{
					typedef meta::constant<size_type> constant;
					typedef semiotic::regist<size_type> regist;

					typedef forward::componentwise<size_type> fwd_comp;
					typedef backward::componentwise<size_type> bwd_comp;
					typedef bidirectional::componentwise<size_type> bid_comp;
					typedef random_access::componentwise<size_type> rnd_comp;

					typedef forward::arithmetic_1<size_type> fwd_arit;
					typedef backward::arithmetic_1<size_type> bwd_arit;
					typedef bidirectional::arithmetic_1<size_type> bid_arit;
					typedef arithmetic_0<size_type> rnd_arit;

					template<size_type N, typename Filler=void>
					struct unroll_1 : public rnd_arit::template unroll_0<N, Filler>
					{
						template<size_type M>
						using rnd_unroll=typename rnd_arit::template unroll_0<M>;
/*
	q is the quotient.
	r is the remainder.
	n is the dividend,
	d is the divisor.

	They are typed as OutputIterators as it is assumed they are safe for modification.
	In practice this means providing a deep copy if necessary when passing const references as input.

	Assumes b < d <= n.
*/
						struct divide
						{
							template<typename OutputIterator>
							static void multiple_digit(OutputIterator q,
								OutputIterator r, OutputIterator n, OutputIterator d)
							{
								size_type scale=constant::register_length-
									regist::order(*bwd_arit::template bwd_unroll<N>::order(d))-1;
							}
						};

						template<size_type M, typename SubFiller=void>
						struct subroll_1
						{
						};

						template<typename SubFiller>
						struct subroll_1<1, SubFiller>
						{
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
