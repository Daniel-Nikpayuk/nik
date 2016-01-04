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

#ifndef CONTEXT_MEDIA_ITERATOR_ARITHMETIC_H
#define CONTEXT_MEDIA_ITERATOR_ARITHMETIC_H

#include"../../../semiotic/regist/regist.h"
#include"../../../semiotic/iterator/componentwise/componentwise.h"

// Clean up the typedefs/usings namespace stuff.

#include"../../../semiotic/iterator/arithmetic/arithmetic.h"

/*
	The main difference between "componentwise" and "arithmetic" from an algorithmic lens is that with componentwise is
	each location is conditionally independent, whereas arithmetic is similar but also dependent on the previous value
	(recursive; maybe the simplest variety of recursive?).

	Incrementing and decrementing pointers which should otherwise maintain a constant location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using these such unrolling in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.
*/

namespace nik
{
 namespace context
 {
  namespace media
  {
   namespace iterator
   {
    namespace forward
    {
	template<typename size_type>
	struct arithmetic : public semiotic::iterator::forward::arithmetic<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist;

		typedef semiotic::iterator::forward::componentwise<size_type> fwd_comp;
		typedef semiotic::iterator::forward::arithmetic<size_type> fwd_arit;
/*
	Copies from in1--end1 to out moving right, as well as shifting by n what it copies; continues after by repeating 0 until end.

	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Does not test if &out == &in1, a problematic case.

	I don't know how it will interpret an OutputIterator double reference in case the initial OutputIterator is implicitly a reference.
*/
		template<typename OutputIterator, typename TerminalIterator, typename InputIterator, typename TerminalIterator1>
		static void right_shift(OutputIterator out, TerminalIterator end, InputIterator in1, TerminalIterator1 end1, size_type n)
		{
			fwd_arit::right_shift::template no_return<OutputIterator &, InputIterator &, InputIterator, TerminalIterator1>(
				out, in1, ++InputIterator(in1), end1, n, constant::register_length-n);
			*out=(*in1>>n);
			fwd_comp::repeat::no_return(out, end, 0);
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
		struct unroll : public fwd_arit::template unroll<N, Filler>
		{
			template<size_type M>
			using fwd_unroll=typename fwd_arit::template unroll<M, Filler>;
/*
	Obfuscated code ?
*/
			struct scale
			{
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void no_return(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ unroll<N-1>::scale::no_return(++out, ++in1, in2,
						regist::multiply::return_high(*out=carry, *in1, in2)); }

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ return unroll<N-1>::scale::with_return(++out, ++in1, in2,
						regist::multiply::return_high(*out=carry, *in1, in2)); }
			};

			template<size_type M, typename SubFiller=void>
			struct subroll
			{
/*
	Does not assume anything about the existing value of out1.

	Is it worth testing for *in2 == 0 ?
*/
				template<typename OutputIterator1, typename OutputIterator2, typename InputIterator1, typename InputIterator2>
				static void multiply(OutputIterator1 out1, OutputIterator2 out2, InputIterator1 in1, InputIterator2 in2)
				{
					unroll<M>::scale::no_return(fwd_comp::
						template unroll<N-M>::repeat::with_return(out2, 0), in1, *in2, 0);
					fwd_unroll<N>::assign::plus::no_return(out1, out2, 0);
					subroll<M-1>::multiply(out1, out2, in1, ++in2);
				}
			};

			template<typename SubFiller>
			struct subroll<1, SubFiller>
			{
				template<typename OutputIterator1, typename OutputIterator2, typename InputIterator1, typename InputIterator2>
				static void multiply(OutputIterator1 out1, OutputIterator2 out2, InputIterator1 in1, InputIterator2 in2)
				{
					unroll<1>::scale::no_return(fwd_comp::
						template unroll<N-1>::repeat::with_return(out2, 0), in1, *in2, 0);
					fwd_unroll<N>::assign::plus::no_return(out1, out2, 0);
				}
			};
		};

		template<typename Filler>
		struct unroll<1, Filler>
		{
/*
	Obfuscated code ?
*/
			struct scale
			{
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void no_return(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ regist::multiply::return_high(*out=carry, *in1, in2); }

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ regist::multiply::return_high(*out=carry, *in1, in2); return ++out; }
			};
		};
	};
    }

    namespace backward
    {
	template<typename size_type>
	struct arithmetic : public semiotic::iterator::backward::arithmetic<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist;

		typedef semiotic::iterator::backward::componentwise<size_type> bwd_comp;
		typedef semiotic::iterator::backward::arithmetic<size_type> bwd_arit;
/*
	Copies from in1--end1 to out moving left, as well as shifting by n what it copies; continues after by repeating 0 until end.

	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.

	Does not test if &out == &in1, a problematic case.

	I don't know how it will interpret an OutputIterator double reference in case the initial OutputIterator is implicitly a reference.
*/
		template<typename OutputIterator, typename TerminalIterator, typename InputIterator, typename TerminalIterator1>
		static void left_shift(OutputIterator out, TerminalIterator end, InputIterator in1, TerminalIterator1 end1, size_type n)
		{
			bwd_arit::left_shift::template no_return<OutputIterator &, InputIterator &, InputIterator, TerminalIterator1>(
				out, in1, --InputIterator(in1), end1, n, constant::register_length-n);
			*out=(*in1<<n);
			bwd_comp::repeat::no_return(out, end, 0);
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
		struct unroll : public bwd_arit::template unroll<N, Filler>
		{
			template<size_type M>
			using bwd_unroll=typename bwd_arit::template unroll<M>;

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
						if (carry) *out=regist::divide::half_register_divisor(carry, carry, *in, d);
						else if (*in < d) { *out=0; carry=*in; }
						else { *out=*in/d; carry=*in%d; }

						return unroll<N-1>::divide::single_digit::half_register_divisor(--out, --in, d, carry);
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
						if (carry) *out=regist::divide::full_register_divisor(carry, carry, *in, d);
						else if (*in < d) { *out=0; carry=*in; }
						else { *out=*in/d; carry=*in%d; }

						return unroll<N-1>::divide::single_digit::full_register_divisor(--out, --in, d, carry);
					}
				};

				struct partial_digit
				{
				};
			};
		};

		template<typename Filler>
		struct unroll<1, Filler>
		{
			struct divide
			{
				struct single_digit
				{
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static ValueType half_register_divisor(OutputIterator out,
						InputIterator in, ValueType d, ValueType carry)
					{
						if (carry) *out=regist::divide::half_register_divisor(carry, carry, *in, d);
						else if (*in < d) { *out=0; carry=*in; }
						else { *out=*in/d; carry=*in%d; }

						return carry;
					}

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static ValueType full_register_divisor(OutputIterator out,
						InputIterator in, ValueType d, ValueType carry)
					{
						if (carry) *out=regist::divide::full_register_divisor(carry, carry, *in, d);
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
	struct arithmetic : public semiotic::iterator::bidirectional::arithmetic<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist;

		typedef semiotic::iterator::forward::componentwise<size_type> fwd_comp;
		typedef semiotic::iterator::backward::componentwise<size_type> bwd_comp;
		typedef semiotic::iterator::bidirectional::componentwise<size_type> bid_comp;

		typedef semiotic::iterator::forward::arithmetic<size_type> fwd_arit;
		typedef semiotic::iterator::backward::arithmetic<size_type> bwd_arit;
		typedef semiotic::iterator::bidirectional::arithmetic<size_type> bid_arit;
	};
    }

    namespace random_access
    {
	template<typename size_type>
	struct arithmetic : public semiotic::iterator::random_access::arithmetic<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist;

		typedef semiotic::iterator::forward::componentwise<size_type> fwd_comp;
		typedef semiotic::iterator::backward::componentwise<size_type> bwd_comp;
		typedef semiotic::iterator::bidirectional::componentwise<size_type> bid_comp;
		typedef semiotic::iterator::random_access::componentwise<size_type> rnd_comp;

		typedef semiotic::iterator::forward::arithmetic<size_type> fwd_arit;
		typedef semiotic::iterator::backward::arithmetic<size_type> bwd_arit;
		typedef semiotic::iterator::bidirectional::arithmetic<size_type> bid_arit;
		typedef semiotic::iterator::random_access::arithmetic<size_type> rnd_arit;

		template<size_type N, typename Filler=void>
		struct unroll : public rnd_arit::template unroll<N, Filler>
		{
			template<size_type M>
			using rnd_unroll=typename rnd_arit::template unroll<M>;
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
				template<typename OutputIterator1,
					typename OutputIterator2, typename OutputIterator3, typename OutputIterator4>
				static void multiple_digit(OutputIterator1 q, OutputIterator2 r, OutputIterator3 n, OutputIterator4 d)
				{
					size_type scale=constant::register_length-
						regist::order(*bwd_arit::template bwd_unroll<N>::order(d))-1;
				}
			};

			template<size_type M, typename SubFiller=void>
			struct subroll
			{
			};

			template<typename SubFiller>
			struct subroll<1, SubFiller>
			{
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
}

#endif
