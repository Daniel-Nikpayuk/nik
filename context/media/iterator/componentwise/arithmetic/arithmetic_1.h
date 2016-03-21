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

#ifndef CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_ARITHMETIC_1_H
#define CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_ARITHMETIC_1_H

// overhead dependencies:

#include"arithmetic_0.h"

#include"../../../../context/policy/policy.h"
#include"../../../../semiotic/iterator/componentwise/policy/policy.h"

// for debugging:

//#include"../../../context/display/display.h"

// Clean up the typedefs/usings namespace stuff.

/*
	The main difference between "overload" and "arithmetic" from an algorithmic lens is that with overload is
	each location is conditionally independent, whereas arithmetic is similar but also dependent on the previous value
	(recursive; maybe the simplest variety of recursive?).

	Incrementing and decrementing pointers which should otherwise maintain a c_policy::unit location is bad practice in general,
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
    namespace componentwise
    {
     namespace forward
     {
	template<typename SizeType>
	struct arithmetic_1 : public arithmetic_0<SizeType>
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::componentwise::policy<size_type> s_comp_policy;

		typedef arithmetic_0<size_type> fwd_arit;

		struct scale
		{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	end1 is the end location of the input containing structure.
	in2 is the c_policy::unit scalar value.
*/
			template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
			static void no_return(WIterator out, RIterator in1, ERIterator end1, ValueType in2, ValueType & carry)
			{
				carry=0;
				s_comp_policy::fwd_arit::scale::no_return(carry, out, in1, end1, in2);
			}

			template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
			static void no_return(WIterator out, RIterator in1, ERIterator end1, ValueType in2)
				{ s_comp_policy::fwd_arit::scale::no_return((ValueType) 0, out, in1, end1, in2); }
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	end1 is the end location of the input containing structure.
	in2 is the c_policy::unit scalar value.
*/
			template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
			static WIterator with_return(WIterator out, RIterator in1, ERIterator end1, ValueType in2, ValueType & carry)
			{
				carry=0;
				return s_comp_policy::fwd_arit::scale::with_return(carry, out, in1, end1, in2);
			}

			template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
			static WIterator with_return(WIterator out, RIterator in1, ERIterator end1, ValueType in2)
				{ return s_comp_policy::fwd_arit::scale::with_return((ValueType) 0, out, in1, end1, in2); }
		};

		struct assign
		{
			struct scale
			{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	end1 is the end location of the input containing structure.
	in2 is the c_policy::unit scalar value.
*/
				template<typename WIterator, typename EIterator, typename ValueType>
				static void no_return(WIterator out, EIterator end, ValueType in, ValueType & carry)
				{
					carry=0;
					s_comp_policy::fwd_arit::assign::scale::no_return(carry, out, end, in);
				}

				template<typename ValueType, typename WIterator, typename EIterator>
				static void no_return(WIterator out, EIterator end, ValueType in)
					{ s_comp_policy::fwd_arit::assign::scale::no_return((ValueType) 0, out, end, in); }
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

			struct scale
			{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.
*/
				template<typename WIterator, typename RIterator, typename ValueType>
				static void no_return(WIterator out, RIterator in1, ValueType in2, ValueType & carry)
				{
					carry=0;
					s_comp_policy::fwd_arit::scale::no_return(carry, out, in1, in2);
				}

				template<typename ValueType, typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in1, ValueType in2)
					{ s_comp_policy::fwd_arit::scale::no_return((ValueType) 0, out, in1, in2); }
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.
*/
				template<typename WIterator, typename RIterator, typename ValueType>
				static WIterator with_return(WIterator out, RIterator in1, ValueType in2, ValueType & carry)
				{
					carry=0;
					return s_comp_policy::fwd_arit::scale::with_return(carry, out, in1, in2);
				}

				template<typename ValueType, typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in1, ValueType in2)
					{ return s_comp_policy::fwd_arit::scale::with_return((ValueType) 0, out, in1, in2); }
			};

			struct assign
			{
				struct scale
				{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.
*/
					template<typename WIterator, typename ValueType>
					static void no_return(WIterator out, ValueType in, ValueType & carry)
					{
						carry=0;
						s_comp_policy::fwd_arit::assign::scale::no_return(carry, out, in);
					}

					template<typename ValueType, typename WIterator>
					static void no_return(WIterator out, ValueType in)
						{ s_comp_policy::fwd_arit::assign::scale::no_return((ValueType) 0, out, in); }
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.
*/
					template<typename WIterator, typename ValueType>
					static WIterator with_return(WIterator out, ValueType in, ValueType & carry)
					{
						carry=0;
						return s_comp_policy::fwd_arit::assign::scale::with_return(carry, out, in);
					}

					template<typename ValueType, typename WIterator>
					static WIterator with_return(WIterator out, ValueType in)
						{ return s_comp_policy::fwd_arit::assign::scale::with_return((ValueType) 0, out, in); }
				};
			};
		};
	};
     }

     namespace backward
     {
	template<typename SizeType>
	struct arithmetic_1 : public arithmetic_0<SizeType>
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::componentwise::policy<size_type> s_comp_policy;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef arithmetic_0<size_type> bwd_arit;

		struct divide
		{
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the half digit denominator.
*/
			struct half_digit
			{
				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static void no_return(WIterator q, RIterator n, ERIterator end, ValueType d, ValueType & r)
				{
					r=*n;
					s_comp_policy::bwd_arit::divide::half_digit::no_return((ValueType) 0, r, q, --n, end, d);
				}

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static void no_return(WIterator q, RIterator n, ERIterator end, ValueType d)
				{
					ValueType r=*n;
					s_comp_policy::bwd_arit::divide::half_digit::no_return((ValueType) 0, r, q, --n, end, d);
				}

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static WIterator with_return(WIterator q, RIterator n, ERIterator end, ValueType d, ValueType & r)
				{
					r=*n;
					return s_comp_policy::bwd_arit::divide::half_digit::with_return((ValueType) 0, r, q, --n, end, d);
				}

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static WIterator with_return(WIterator q, RIterator n, ERIterator end, ValueType d)
				{
					ValueType r=*n;
					return s_comp_policy::bwd_arit::divide::half_digit::with_return((ValueType) 0, r, q, --n, end, d);
				}
			};
/*
	rc is the higher carry value.
		Set this to zero for the "normal" interpretation.
		Values are shifted into it from the lower carry until big enough to divide.
	r is the lower carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
			struct single_digit
			{
				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static void no_return(WIterator q, RIterator n, ERIterator end, ValueType d, ValueType & r)
				{
					r=*n;
					s_comp_policy::bwd_arit::divide::single_digit::no_return((ValueType) 0, r, q, --n, end, d);
				}

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static void no_return(WIterator q, RIterator n, ERIterator end, ValueType d)
				{
					ValueType r=*n;
					s_comp_policy::bwd_arit::divide::single_digit::no_return((ValueType) 0, r, q, --n, end, d);
				}

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static WIterator with_return(WIterator q, RIterator n, ERIterator end, ValueType d, ValueType & r)
				{
					r=*n;
					return s_comp_policy::bwd_arit::divide::single_digit::with_return((ValueType) 0, r, q, --n, end, d);
				}

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static WIterator with_return(WIterator q, RIterator n, ERIterator end, ValueType d)
				{
					ValueType r=*n;
					return s_comp_policy::bwd_arit::divide::single_digit::with_return((ValueType) 0, r, q, --n, end, d);
				}
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
				struct half
				{
					template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
					static void no_return(WIterator q, RIterator n, ERIterator end, ValueType d, ValueType & r)
					{
						r=*n;
						s_comp_policy::bwd_arit::divide::single_digit::half::no_return(r, q, --n, end, d);
					}

					template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
					static void no_return(WIterator q, RIterator n, ERIterator end, ValueType d)
					{
						ValueType r=*n;
						s_comp_policy::bwd_arit::divide::single_digit::half::no_return(r, q, --n, end, d);
					}

					template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
					static WIterator with_return(WIterator q, RIterator n, ERIterator end, ValueType d, ValueType & r)
					{
						r=*n;
						return s_comp_policy::bwd_arit::divide::single_digit::half::with_return(r, q, --n, end, d);
					}

					template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
					static WIterator with_return(WIterator q, RIterator n, ERIterator end, ValueType d)
					{
						ValueType r=*n;
						return s_comp_policy::bwd_arit::divide::single_digit::half::with_return(r, q, --n, end, d);
					}
				};
			};
		};

		struct assign
		{
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
		struct unroll_1 : public bwd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using bwd_unroll=typename bwd_arit::template unroll_0<K, J, I>;

			struct divide
			{
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the half digit denominator.
*/
				struct half_digit
				{
					template<typename WIterator, typename RIterator, typename ValueType>
					static void no_return(WIterator q, RIterator n, ValueType d, ValueType & r)
					{
						r=*n;
						s_comp_policy::bwd_arit::divide::half_digit::no_return((ValueType) 0, r, q, --n, d);
					}

					template<typename WIterator, typename RIterator, typename ValueType>
					static void no_return(WIterator q, RIterator n, ValueType d)
					{
						ValueType r=*n;
						s_comp_policy::bwd_arit::divide::half_digit::no_return((ValueType) 0, r, q, --n, d);
					}

					template<typename WIterator, typename RIterator, typename ValueType>
					static WIterator with_return(WIterator q, RIterator n, ValueType d, ValueType & r)
					{
						r=*n;
						return s_comp_policy::bwd_arit::divide::half_digit::with_return((ValueType) 0, r, q, --n, d);
					}

					template<typename WIterator, typename RIterator, typename ValueType>
					static WIterator with_return(WIterator q, RIterator n, ValueType d)
					{
						ValueType r=*n;
						return s_comp_policy::bwd_arit::divide::half_digit::with_return((ValueType) 0, r, q, --n, d);
					}
				};
/*
	rc is the higher carry value.
		Set this to zero for the "normal" interpretation.
		Values are shifted into it from the lower carry until big enough to divide.
	r is the lower carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
				struct single_digit
				{
					template<typename WIterator, typename RIterator, typename ValueType>
					static void no_return(WIterator q, RIterator n, ValueType d, ValueType & r)
					{
						r=*n;
						s_comp_policy::bwd_arit::divide::single_digit::no_return((ValueType) 0, r, q, --n, d);
					}

					template<typename WIterator, typename RIterator, typename ValueType>
					static void no_return(WIterator q, RIterator n, ValueType d)
					{
						ValueType r=*n;
						s_comp_policy::bwd_arit::divide::single_digit::no_return((ValueType) 0, r, q, --n, d);
					}

					template<typename WIterator, typename RIterator, typename ValueType>
					static WIterator with_return(WIterator q, RIterator n, ValueType d, ValueType & r)
					{
						r=*n;
						return s_comp_policy::bwd_arit::divide::single_digit::with_return((ValueType) 0, r, q, --n, d);
					}

					template<typename WIterator, typename RIterator, typename ValueType>
					static WIterator with_return(WIterator q, RIterator n, ValueType d)
					{
						ValueType r=*n;
						return s_comp_policy::bwd_arit::divide::single_digit::with_return((ValueType) 0, r, q, --n, d);
					}
/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/
					struct half
					{
						template<typename WIterator, typename RIterator, typename ValueType>
						static void no_return(WIterator q, RIterator n, ValueType d, ValueType & r)
						{
							r=*n;
							s_comp_policy::bwd_arit::divide::single_digit::half::no_return(r, q, --n, d);
						}

						template<typename WIterator, typename RIterator, typename ValueType>
						static void no_return(WIterator q, RIterator n, ValueType d)
						{
							ValueType r=*n;
							s_comp_policy::bwd_arit::divide::single_digit::half::no_return(r, q, --n, d);
						}

						template<typename WIterator, typename RIterator, typename ValueType>
						static WIterator with_return(WIterator q, RIterator n, ValueType d, ValueType & r)
						{
							r=*n;
							return s_comp_policy::bwd_arit::divide::single_digit::half::with_return(r, q, --n, d);
						}

						template<typename WIterator, typename RIterator, typename ValueType>
						static WIterator with_return(WIterator q, RIterator n, ValueType d)
						{
							ValueType r=*n;
							return s_comp_policy::bwd_arit::divide::single_digit::half::with_return(r, q, --n, d);
						}
					};
				};
			};
		};
	};
     }

     namespace bidirectional
     {
	template<typename SizeType>
	struct arithmetic_1 : public arithmetic_0<SizeType>
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::componentwise::policy<size_type> s_comp_policy;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef arithmetic_0<size_type> bid_arit;

		struct multiply
		{
/*
	Set out identically equal to zero for the normal interpretation.
	Set the arguement out2=out1 for the normal interpretation.
*/
			template<typename ValueType, typename WIterator, typename EWIterator, typename WIterator1,
				typename RIterator1, typename ERIterator1, typename RIterator2, typename ERIterator2>
			static void no_return(WIterator out, EWIterator end, WIterator1 out1,
				RIterator1 in1, ERIterator1 end1, RIterator2 in2, ERIterator2 end2)
			{
				s_comp_policy::fwd_comp::repeat::no_return(out, end, (ValueType) 0);
				s_comp_policy::bid_arit::multiply::no_return(out, out1, out1, in1, end1, in2, end2);
			}

			struct half
			{
/*
	Set out identically equal to zero for the normal interpretation.
	Set out2=out1 for the normal interpretation.
*/
				template<typename ValueType, typename WIterator, typename EWIterator, typename WIterator1,
					typename RIterator1, typename ERIterator1, typename RIterator2, typename ERIterator2>
				static void no_return(WIterator out, EWIterator end, WIterator1 out1,
					RIterator1 in1, ERIterator1 end1, RIterator2 in2, ERIterator2 end2)
				{
					s_comp_policy::fwd_comp::repeat::no_return(out, end, (ValueType) 0);
					s_comp_policy::bid_arit::multiply::half::no_return(out, out1, out1, in1, end1, in2, end2);
				}
			};
		};

		struct assign
		{
			struct multiply
			{
/*
	Set out identically equal to zero for the normal interpretation.
	Set the arguement out2=out1 for the normal interpretation.
*/
				template<typename ValueType, typename WIterator, typename EWIterator,
					typename WIterator1, typename WIterator2, typename EWIterator2,
					typename RIterator1, typename ERIterator1, typename RIterator2, typename ERIterator2>
				static void no_return(WIterator out, EWIterator end, WIterator1 out1,
					WIterator2 out2, EWIterator2 end2, RIterator1 in1, ERIterator1 end1)
				{
					s_comp_policy::fwd_comp::assign::no_return(out2, out, end);
					s_comp_policy::fwd_comp::repeat::no_return(out, end, (ValueType) 0);
					s_comp_policy::bid_arit::assign::multiply::no_return(out, out1, out1, out2, end2, in1, end1);
				}

				struct half
				{
/*
	Set out identically equal to zero for the normal interpretation.
	Set out2=out1 for the normal interpretation.
*/
					template<typename ValueType, typename WIterator, typename EWIterator,
						typename WIterator1, typename WIterator2, typename EWIterator2,
						typename RIterator1, typename ERIterator1, typename RIterator2, typename ERIterator2>
					static void no_return(WIterator out, EWIterator end, WIterator1 out1,
						WIterator1 out2, EWIterator2 end2, RIterator1 in1, ERIterator1 end1)
					{
						s_comp_policy::fwd_comp::assign::no_return(out2, out, end);
						s_comp_policy::fwd_comp::repeat::no_return(out, end, (ValueType) 0);
						s_comp_policy::bid_arit::assign::multiply::half::no_return(out, out1, out1, out2, end2, in1, end1);
					}
				};
			};
		};

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public bwd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using bwd_unroll=typename bwd_arit::template unroll_0<K, J, I>;
		};
	};
     }

     namespace random_access
     {
	template<typename SizeType>
	struct arithmetic_1 : public arithmetic_0<SizeType>
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::componentwise::policy<size_type> s_comp_policy;

		typedef forward::arithmetic_1<size_type> fwd_arit;
		typedef backward::arithmetic_1<size_type> bwd_arit;
		typedef bidirectional::arithmetic_1<size_type> bid_arit;
		typedef arithmetic_0<size_type> rnd_arit;

		struct divide
		{
/*
	L is the specification block length of the denominator.
		2 <= L
	M is the specification block length of the numerator.
		L <= M
	N is initialized as M-L+1.

	r is the initial location of the overhead value (carry; remainder).
		To implement under the normal interpretation, copy this to be
		the leading digits of the numerator---the same length as the denominator.
	lr is the location of the leading digit of the overhead value (carry; remainder).
	q is the final location of the quotient to be determined (it works its way backwards).
	t is the initial location of a temporary used for internal computations.
		Initialization is unnecessary as lazy comparisons are used avoiding values out of bounds.
	n is the digit location within the numerator following the digits already held within the remainder.
	d is the initial location of the denominator (divisor).
		Initializing the final location to zero is necessary only if (L < M); see the notes below.
	ld is the location of the leading digit of the denominator (divisor).

	Assumes (r|n) >= d, and that they are already normalized for Knuth multiple precision division optimization.

	Block length for the above arguments is conditional upon the block length of the carry,
	because the intention of the carry is to shift digits into its register until it is big enough to divide by
	the divisor. The carry length is itself conditional upon the template parameters:

	(L == M):

		r
			As (r|n) >= d then no extra digits will be shifted into r
			and so r only needs to be of block size L.
		q
			As a block it has implementation length M-L+1.
		t
			As a block it has implementation length L.
		n
			As a block it has implementation length M-L (as it is not the full numerator).
		d
			As a block it has implementation length L.

	(L < M):

		r
			This is equivalent to (L+1 <= M). No assumptions can be made as to whether or not an additional digit
			will be shifted into the register, and as such as a block it has implementation length L+1.
		q
			As a block it has implementation length M-L+1.
		t
			As a block it has implementation length L+1. It is used as memory for the value q'*d
			within the knuth_remainder subroutine, where q' is the local quotient within that iteration.
			We know that q'*d < r, but as r is of block length L+1 we have to allow for the possibility
			q'*d is of block length L+1.
		n
			As a block it has implementation length M-L (as it is not the full numerator).
		d
			As a block it has implementation length L+1. It is used to generate q'*d mapping onto
			a block length of size L+1 within the knuth_remainder subroutine, as such it needs its
			to be of the same length where its leading digit is set to zero.

	What is termed "dord" here is refactored as the compile-time constant set to value L-1.

	Body variables are refactored as function parameters for higher entropy as one then defer type constraints (templating).
	On the otherhand, since size_type is a (more-or-less) known type, it can be declared within the body.
*/
			struct multiple_digit
			{
/*
	no_return:
*/
				template<typename WIterator1, typename WIterator2,
					typename WIterator3, typename RIterator1, typename RIterator2>
				static void no_return(WIterator1 r, WIterator1 rend,
					WIterator2 q, WIterator3 t, WIterator3 tend, RIterator1 n, RIterator1 nend,
						RIterator2 d, RIterator2 dend)
				{
					RIterator2 ld=s_comp_policy::bwd_arit::zero::with_break(dend-1, d);
					WIterator1 lr=r+(ld-d);

					size_type	rank=c_policy::arg_bin::order(*ld)+1,
							power=c_policy::unit::length-rank;

					if (power)
					{
						*(lr+1)=c_policy::arg_bin::high(*n, rank); // need to know lr+1 exists!
						n=bwd_arit::left_shift::with_return(lr, r-1, n, nend, power);

						*r=c_policy::arg_bin::high(*n, rank);
						bwd_arit::assign::left_shift::no_return(n, nend, power);

						bwd_arit::assign::left_shift::no_return(ld, d-1, power);
						if (*(lr+1)) ++lr; // need to know lr+1 exists!
					}

					s_comp_policy::rnd_arit::divide::multiple_digit::no_return(r, lr, rend, q, t, tend, n, nend, d, ld, dend);

					if (power) bwd_arit::assign::right_shift::no_return(r, rend, power);
				}

				struct half
				{
/*
	no_return:
*/
					template<typename WIterator1, typename WIterator2,
						typename WIterator3, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 r, WIterator1 lr, WIterator1 rend,
						WIterator2 q, WIterator3 t, WIterator3 tend, RIterator1 n, RIterator1 nend,
							RIterator2 d, RIterator2 ld, RIterator2 dend)
					{
						s_comp_policy::rnd_arit::divide::multiple_digit::half::
							no_return(r, lr, rend, q, t, tend, n, nend, d, ld, dend);
					}
				};
			};
		};

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_1 : public rnd_arit::template unroll_0<N, M, L>
		{
			template<size_type K, size_type J=0, size_type I=0>
			using rnd_unroll=typename rnd_arit::template unroll_0<K, J, I>;

			struct divide
			{
/*
		L is the specification block length of the denominator.
			2 <= L
		M is the specification block length of the numerator.
			L <= M
		N is initialized as M-L+1.

		r is the initial location of the overhead value (carry; remainder).
			To implement under the normal interpretation, copy this to be
			the leading digits of the numerator---the same length as the denominator.
		lr is the location of the leading digit of the overhead value (carry; remainder).
		q is the final location of the quotient to be determined (it works its way backwards).
		t is the initial location of a temporary used for internal computations.
			Initialization is unnecessary as lazy comparisons are used avoiding values out of bounds.
		n is the digit location within the numerator following the digits already held within the remainder.
		d is the initial location of the denominator (divisor).
			Initializing the final location to zero is necessary only if (L < M); see the notes below.
		ld is the location of the leading digit of the denominator (divisor).

		Assumes (r|n) >= d, and that they are already normalized for Knuth multiple precision division optimization.

		Block length for the above arguments is conditional upon the block length of the carry,
		because the intention of the carry is to shift digits into its register until it is big enough to divide by
		the divisor. The carry length is itself conditional upon the template parameters:

		(L == M):

			r
				As (r|n) >= d then no extra digits will be shifted into r
				and so r only needs to be of block size L.
			q
				As a block it has implementation length M-L+1.
			t
				As a block it has implementation length L.
			n
				As a block it has implementation length M-L (as it is not the full numerator).
			d
				As a block it has implementation length L.

		(L < M):

			r
				This is equivalent to (L+1 <= M). No assumptions can be made as to whether or not an additional digit
				will be shifted into the register, and as such as a block it has implementation length L+1.
			q
				As a block it has implementation length M-L+1.
			t
				As a block it has implementation length L+1. It is used as memory for the value q'*d
				within the knuth_remainder subroutine, where q' is the local quotient within that iteration.
				We know that q'*d < r, but as r is of block length L+1 we have to allow for the possibility
				q'*d is of block length L+1.
			n
				As a block it has implementation length M-L (as it is not the full numerator).
			d
				As a block it has implementation length L+1. It is used to generate q'*d mapping onto
				a block length of size L+1 within the knuth_remainder subroutine, as such it needs its
				to be of the same length where its leading digit is set to zero.

		What is termed "dord" here is refactored as the compile-time constant set to value L-1.

		Body variables are refactored as function parameters for higher entropy as one then defer type constraints (templating).
		On the otherhand, since size_type is a (more-or-less) known type, it can be declared within the body.
*/
				struct multiple_digit
				{
/*
	no_return:
*/
					template<typename WIterator1, typename WIterator2,
						typename WIterator3, typename RIterator1, typename RIterator2>
					static void no_return(WIterator1 r, WIterator1 lr,
						WIterator2 q, WIterator3 t, RIterator1 n, RIterator2 d, RIterator2 ld)
					{
						s_comp_policy::rnd_arit::divide::multiple_digit::no_return(r, lr, q, t, n, d, ld);
					}

					struct half
					{
/*
	Debugging note: Every function call within needs to be robust against its "half" version.
*/
						template<typename WIterator1, typename WIterator2,
							typename WIterator3, typename RIterator1, typename RIterator2>
						static void no_return(WIterator1 r, WIterator1 lr,
							WIterator2 q, WIterator3 t, RIterator1 n, RIterator2 d, RIterator2 ld)
						{
							s_comp_policy::rnd_arit::divide::multiple_digit::half::no_return(r, lr, q, t, n, d, ld);
						}
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
}

#endif
