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

		struct multiply
		{
			struct half_register
			{
/*
				template<typename WIterator1, typename WIterator2,
					typename RIterator1, typename EIterator1, typename RIterator2, typename EIterator2>
				static void no_return(WIterator1 out1, WIterator2 out2,
					RIterator1 in1, EIterator1 end1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						fwd_arit::assign::plus::half_register::no_return(0, out1, out2,
							fwd_arit::scale::half_register::no_return(0,
								fwd_comp::repeat::with_return(out2, 0),
								in1, end1, *in2);
							);
						++in2;
					}
				}
*/
			};
		};
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Explicit specialization isn't allowed. Template parameters are of an arbitrary but fixed type.
			As such one factoring all such parameters into a single template is effective.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public fwd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using fwd_unroll=typename fwd_arit::template unroll_0<K, J, I>;
/*
	N is initially the length of in1.
	M is the length of in1.
	L is the length of in2. It is assumed M >= L.

	out1 is the carry, but is semantically meaningful as the proper output.
		Does not assume anything about the existing value of out1.
	out2 is meant to be a temporary variable.

	Is it worth testing for *in2 == 0 ?
*/
			template<typename ValueType>
			struct multiply
			{
				struct half_register
				{
					template<typename WIterator1, typename WIterator2, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 out1, WIterator2 out2, RIterator1 in1, RIterator2 in2)
					{
						fwd_unroll<M+N-L>::scale::half_register::no_return((ValueType) 0,
							fwd_comp::template unroll<L-N>::repeat::with_return(out2, (ValueType) 0),
							in1, *in2);
						fwd_unroll<M>::assign::plus::half_register::no_return((ValueType) 0, out1, out2);
						unroll_1<N-1, M, L>::template multiply<ValueType>::
							half_register::no_return(out1, out2, in1, ++in2);
					}
				};
			};

			struct assign
			{
			};
		};

		template<size_type M, size_type L>
		struct unroll_1<0, M, L> : public fwd_arit::template unroll_0<0, M, L>
		{
			template<typename ValueType>
			struct multiply
			{
				struct half_register
				{
					template<typename WIterator1, typename WIterator2, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 out1, WIterator2 out2, RIterator1 in1, RIterator2 in2)
						{ }
				};
			};

			struct assign
			{
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

		typedef forward::componentwise<size_type> fwd_comp;
		typedef componentwise<size_type> bwd_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef arithmetic_0<size_type> bwd_arit;
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Explicit specialization isn't allowed. Template parameters are of an arbitrary but fixed type.
			As such one factoring all such parameters into a single template is effective.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public bwd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using bwd_unroll=typename bwd_arit::template unroll_0<K, J, I>;

			struct divide
			{
				struct single_digit
				{
					struct half_register
					{
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into r's register until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(ValueType r, WIterator q, RIterator n, ValueType d)
						{
							if (r < d) *q=0;
							else { *q=r/d; r=r%d; }

							(r<<=constant::half_length)+=*n;
							unroll_1<N-1>::divide::single_digit::half_register::no_return(r, --q, --n, d);
						}

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(ValueType r, WIterator q, RIterator n, ValueType d)
						{
							if (r < d) *q=0;
							else { *q=r/d; r=r%d; }

							(r<<=constant::half_length)+=*n;
							return unroll_1<N-1>::divide::single_digit::half_register::no_return(r, --q, --n, d);
						}
					};
				};
			};
		};

		template<size_type M, size_type L>
		struct unroll_1<0, M, L> : public bwd_arit::template unroll_0<0, M, L>
		{
			struct divide
			{
				struct single_digit
				{
					struct half_register
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(ValueType r, WIterator q, RIterator n, ValueType d)
							{ }

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(ValueType r, WIterator q, RIterator n, ValueType d)
							{ return q; }
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

		typedef forward::componentwise<size_type> fwd_comp;
		typedef backward::componentwise<size_type> bwd_comp;
		typedef componentwise<size_type> bid_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef arithmetic_0<size_type> bid_arit;

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public bwd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using bwd_unroll=typename bwd_arit::template unroll_0<K, J, I>;
		};

		template<size_type M, size_type L>
		struct unroll_1<0, M, L> : public bwd_arit::template unroll_0<0, M, L>
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

		typedef forward::componentwise<size_type> fwd_comp;
		typedef backward::componentwise<size_type> bwd_comp;
		typedef bidirectional::componentwise<size_type> bid_comp;
		typedef componentwise<size_type> rnd_comp;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef bidirectional::arithmetic_1<size_type> bid_arit;
		typedef arithmetic_0<size_type> rnd_arit;

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public rnd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using rnd_unroll=typename rnd_arit::template unroll_0<K, J, I>;

			struct divide
			{
				struct multiple_digit
				{
					struct half_register
					{
						#define DORD L-1
/*
	Assumes tord >= 1 (size >= 2).
*/
						template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
						static bool improve_quotient(ValueType & q,
							WIterator t, RIterator1 u, size_type uord, RIterator2 v)
						{
							ValueType tc=0;
							fwd_arit::template unroll_0<2>::scale::
								half_register::template no_return<ValueType&>(tc, t, v, q);

							ValueType uc=(uord == 2) ? *(u+2) : (ValueType) 0;
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
						template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
						static void knuth_quotient(ValueType & q, WIterator t,
							RIterator1 u, size_type uord, RIterator2 v, size_type vord)
						{
							RIterator1 bu=u-1;
							if (uord == vord) q=*u / *v;
							else
							{
								q=(*u < *v) ?
									((*u<<constant::half_length) + *bu) / *v :
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
						template<typename ValueType, typename WIterator1, typename WIterator2, typename RIterator>
						static WIterator2 knuth_remainder(ValueType & q, WIterator1 t, WIterator2 r, RIterator d)
						{
							fwd_arit::template unroll_0<L+(L < M)>::scale::
								half_register::no_return((ValueType) 0, t, d, q);
							fwd_arit::template unroll_0<L+(L < M)>::assign::minus::
								half_register::no_return((ValueType) 0, r, t);

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
						template<typename WIterator1, typename WIterator2,
							typename WIterator3, typename RIterator1, typename RIterator2>
						static void no_return(WIterator1 r, WIterator1 lr,
							WIterator2 q, WIterator3 t, RIterator1 n, RIterator2 d, RIterator2 ld)
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

						#undef DORD
					};
				};
			};
		};

		template<size_type M, size_type L>
		struct unroll_1<0, M, L> : public rnd_arit::template unroll_0<0, M, L>
		{
			struct divide
			{
				struct multiple_digit
				{
					struct half_register
					{
						template<typename WIterator1, typename WIterator2,
							typename WIterator3, typename RIterator1, typename RIterator2>
						static void no_return(WIterator1 r, WIterator1 lr,
							WIterator2 q, WIterator3 t, RIterator1 n, RIterator2 d, RIterator2 ld)
								{ }
					};
				};
			};
		};
	};
    }
   }
  }
 }
}

#endif
