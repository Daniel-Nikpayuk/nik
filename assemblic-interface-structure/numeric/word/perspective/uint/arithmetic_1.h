/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
************************************************************************************************************************/

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
	Assumes t has at least two digits.
	Assumes u has at least two digits;
		at least three digits if (uord == 2).
	Assumes v has at least two digits.
*/
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static bool improve_quotient(ValueType & q, WIterator t, RIterator1 u, RIterator2 v, size_type uord)
				{
					ValueType tc=0;
					fwd_arit::template unroll_0<2>::scale::template no_return<ValueType&>(tc, t, v, q);

					ValueType uc=(uord == 2) ? *(u+2) : (ValueType) 0;
						// this way of using "greater_than" is a small hack.
					if (fwd_arit::template unroll_0<2>::greater_than::template fast_return(false, t, u, tc, uc))
					{
						--q;
						return true;
					}
					else return false;
				}
/*
	Assumes t has at least two digits.
	Assumes u has at least two digits;
		at least 3 digits if (uord != vord).
	Assumes v has at least two digits.
*/
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static void knuth_quotient(ValueType & q, WIterator t,
					RIterator1 u, RIterator2 v, size_type uord, size_type vord)
				{
					RIterator1 bu=u-1;
					if (uord == vord) q=*u / *v;
					else
					{
						q=(*u < *v) ?
							c_policy::arg_math::divide::with_return(*u, *bu, *v) :
								c_policy::unit::max_size;
						--bu;
					}

					RIterator2 bv=v-1;
					size_type buord=u-bu;
					if (improve_quotient(q, t, bu, bv, buord))
						improve_quotient(q, t, bu, bv, buord);
				}
/*
	t is expected to be of size L+1 if L < M, of size L otherwise.
	r is expected to be of size L+1 if L < M, of size L otherwise.
	d is expected to be of size L+1 if L < M, of size L otherwise.
*/
				template<typename ValueType, typename WIterator1, typename WIterator2, typename RIterator>
				static WIterator2 knuth_remainder(ValueType & q,
					WIterator1 t, WIterator1 tend, WIterator2 r, WIterator2 lr, RIterator d, RIterator dend)
				{
					fwd_arit::scale::no_return((ValueType) 0, t, d, dend, q);
					fwd_arit::assign::minus::no_return((ValueType) 0, r, t, tend);

						// r < d at this point.
					return bwd_arit::zero::with_break(lr, r);
				}
/*
	no_return:
*/
				template<typename WIterator1, typename WIterator2,
					typename WIterator3, typename RIterator1, typename RIterator2>
				static void no_return(WIterator1 r, WIterator1 lr, WIterator1 rend,
					WIterator2 q, WIterator3 t, WIterator3 tend, RIterator1 n, RIterator1 nend,
						RIterator2 d, RIterator2 ld, RIterator2 dend)
				{
					size_type dord=ld-d;
					WIterator1 br=r-1;

					while (n != nend)
					{
						size_type rord=lr-r;
						if (fwd_arit::less_than::fast_return(false, r, d, rord, dord)) *q=0;
						else
						{
							knuth_quotient(*q, t, lr, ld, rord, dord);
							lr=knuth_remainder(*q, t, tend, r, lr, d, dend);
						}

						WIterator1 olr(lr);
						*bwd_over::assign::with_return(++lr, olr, br)=*n;
						--q; --n;
					}
				}
			};

