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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_1_H
#define CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_1_H

// overhead dependencies:

#include"arithmetic_0.h"

#include"../componentwise/componentwise.h"

// for debugging:
#include"../../../../media/generic/display/display.h"

// Clean up the typedefs/usings namespace stuff.

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
  namespace semiotic
  {
   namespace iterator
   {
    namespace forward
    {
	template<typename size_type>
	struct arithmetic_1 : public arithmetic_0<size_type>
	{
		typedef meta::constant<size_type> constant;

		typedef componentwise<size_type> fwd_comp;
		typedef arithmetic_0<size_type> fwd_arit;
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

			template<size_type M, typename SubFiller=void>
			struct subroll_1 : public fwd_arit::template unroll_0<N, Filler>::template subroll_0<M, SubFiller>
			{
				struct multiply
				{
					struct half_register
					{
/*
	out1 is the carry, but is semantically meaningful as the proper output.
		Does not assume anything about the existing value of out1.
	out2 is meant to be a temporary variable.

	Is it worth testing for *in2 == 0 ?
*/
						template<typename WIterator1, typename WIterator2, typename RIterator1, typename RIterator2>
						static void no_return(WIterator1 out1, WIterator2 out2, RIterator1 in1, RIterator2 in2)
						{
							unroll_0<M>::scale::half_register::no_return(0,
								fwd_comp::template unroll<N-M>::repeat::with_return(out2, 0), in1, *in2);
							fwd_unroll<N>::assign::plus::half_register::no_return(0, out1, out2);
							subroll_1<M-1>::multiply::half_register::no_return(out1, out2, in1, ++in2);
						}
					};
				};
			};

			template<typename SubFiller>
			struct subroll_1<0, SubFiller>
			{
				struct multiply
				{
					struct half_register
					{
						template<typename WIterator1, typename WIterator2, typename RIterator1, typename RIterator2>
						static void multiply(WIterator1 out1, WIterator2 out2, RIterator1 in1, RIterator2 in2)
							{ }
					};
				};
			};
		};

		template<typename Filler>
		struct unroll_1<0, Filler>
		{
		};
	};
    }

    namespace backward
    {
	template<typename size_type>
	struct arithmetic_1 : public arithmetic_0<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist; // does not allow "redeclaration" without the additional scope.

		typedef forward::componentwise<size_type> fwd_comp;
		typedef componentwise<size_type> bwd_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef arithmetic_0<size_type> bwd_arit;
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
	Is it worth having both a half_register as well as full_register version?
		One can always use the Knuth normalization trick so as to have only the full_register version.
*/
				struct single_digit
				{
					struct half_register
					{
/*
	"carry" is a memory optimization hack. When calling this function, carry needs to be set to *in.
		Reimplement this to be the remainder similar to the multiple_digit implementation.
	"out" is the retainer of the returned quotient.
	Assumes "in" is the leftmost digit of the structure.

	Is optimized to assume 0 <= carry < d.

	Assumes "d" is the divisor and that in >= 3.
	If d == 1 why use this at all?
	If d == 2 use bit shifting.
*/
						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator no_return(ValueType carry, WIterator out, RIterator in, ValueType d)
						{
							if (carry) *out=regist::divide::half_register_divisor(carry, carry, *in, d);
							else if (*in < d) { *out=0; carry=*in; }
							else { *out=*in/d; carry=*in%d; }

							return unroll_1<N-1>::divide::single_digit::
								half_register::no_return(carry, --out, --in, d);
						}
					};
				};

				struct multiple_digit
				{
					struct half_register
					{
/*
	"carry" is a memory optimization hack. When calling this function, carry needs to be set to *in.
		Reimplement this to be the remainder similar to the multiple_digit implementation.
	"out" is the retainer of the returned quotient.
	Assumes "in" is the leftmost digit of the structure.

	Assumes "d" is the divisor and that in >= 3.
	If d == 1 why use this at all?
	If d == 2 use bit shifting.
*/
						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator no_return(ValueType carry, WIterator out, RIterator in, ValueType d)
						{
							if (carry) *out=regist::divide::full_register_divisor(carry, carry, *in, d);
							else if (*in < d) { *out=0; carry=*in; }
							else { *out=*in/d; carry=*in%d; }

							return unroll_1<N-1>::divide::multiple_digit::
								half_register::no_return(carry, --out, --in, d);
						}
					};
				};
			};

			template<size_type M, typename SubFiller=void>
			struct subroll_1 : public fwd_arit::template unroll_0<N, Filler>::template subroll_0<M, SubFiller>
			{
			};

			template<typename SubFiller>
			struct subroll_1<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_1<0, Filler>
		{
			struct divide
			{
				struct single_digit
				{
					struct half_register
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator no_return(ValueType carry, WIterator out, RIterator in, ValueType d)
							{ return out; }
					};
				};

				struct multiple_digit
				{
					struct half_register
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator no_return(ValueType carry, WIterator out, RIterator in, ValueType d)
							{ return out; }
					};
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
		typedef semiotic::regist<size_type> regist; // does not allow "redeclaration" without the additional scope.

		typedef forward::componentwise<size_type> fwd_comp;
		typedef backward::componentwise<size_type> bwd_comp;
		typedef componentwise<size_type> bid_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef arithmetic_0<size_type> bid_arit;

		template<size_type N, typename Filler=void>
		struct unroll_1 : public bwd_arit::template unroll_0<N, Filler>
		{
			template<size_type M>
			using bwd_unroll=typename bwd_arit::template unroll_0<M>;
			template<size_type M, typename SubFiller=void>
			struct subroll_1 : public fwd_arit::template unroll_0<N, Filler>::template subroll_0<M, SubFiller>
			{
			};

			template<typename SubFiller>
			struct subroll_1<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_1<0, Filler>
		{
		};
	};
    }

    namespace random_access
    {
	template<typename size_type>
	struct arithmetic_1 : public arithmetic_0<size_type>
	{
		typedef meta::constant<size_type> constant;
		typedef semiotic::regist<size_type> regist; // does not allow "redeclaration" without the additional scope.

		typedef forward::componentwise<size_type> fwd_comp;
		typedef backward::componentwise<size_type> bwd_comp;
		typedef bidirectional::componentwise<size_type> bid_comp;
		typedef componentwise<size_type> rnd_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef bidirectional::arithmetic_1<size_type> bid_arit;
		typedef arithmetic_0<size_type> rnd_arit;

		template<size_type N, typename Filler=void>
		struct unroll_1 : public rnd_arit::template unroll_0<N, Filler>
		{
			template<size_type M>
			using rnd_unroll=typename rnd_arit::template unroll_0<M>;

			template<size_type M, typename SubFiller=void>
			struct subroll_1 : public fwd_arit::template unroll_0<N, Filler>::template subroll_0<M, SubFiller>
			{
			};

			template<typename SubFiller>
			struct subroll_1<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_1<0, Filler>
		{
		};
	};
    }
   }
  }
 }
}

#endif
