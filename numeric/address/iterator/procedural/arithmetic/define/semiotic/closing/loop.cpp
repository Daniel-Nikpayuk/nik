/************************************************************************************************************************
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
************************************************************************************************************************/

/*
	This code is not intended to be used standalone.
	It needs to be equipped with a context to be interpreted by the compiler.
*/

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	As "out" is assign shifted when its "dir(out)" is allocated, there is no need to increment seperately.
*/

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_zero(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_zero(dir, inv)				_closing_loop_zero(dir, inv, no, void, )
#define closing_loop_with_break_zero(dir, inv)				_closing_loop_zero(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

// these don't belong here in the long run. They belong in "segment"

#define closing_loop_no_break_zero_fast(dir, inv) \
template<typename RIterator, typename EIterator> \
static bool no_break(bool carry, RIterator in, EIterator end) \
{ \
	while (in != end) \
	{ \
		carry=carry && !*in; \
		dir##dir(in); \
	} \
 \
	return carry; \
} \

#define closing_loop_with_break_zero_fast(dir, inv) \
template<typename RIterator, typename EIterator> \
static bool with_break(RIterator in, EIterator end) \
{ \
	while (in != end) \
	{ \
		if (*in) return false; \
		dir##dir(in); \
	} \
 \
	return true; \
} \

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_equal(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_equal(dir, inv)				_closing_loop_equal(dir, inv, no, void, )
#define closing_loop_with_break_equal(dir, inv)				_closing_loop_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_equal_fast(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_equal_fast(dir, inv)			_closing_loop_equal_fast(dir, inv, no, void, )
#define closing_loop_with_break_equal_fast(dir, inv)			_closing_loop_equal_fast(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_not_equal(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_not_equal(dir, inv)			_closing_loop_not_equal(dir, inv, no, void, )
#define closing_loop_with_break_not_equal(dir, inv)			_closing_loop_not_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_not_equal_fast(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_not_equal_fast(dir, inv)			_closing_loop_not_equal_fast(dir, inv, no, void, )
#define closing_loop_with_break_not_equal_fast(dir, inv)		_closing_loop_not_equal_fast(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_less_than(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_less_than(dir, inv)			_closing_loop_less_than(dir, inv, no, void, )
#define closing_loop_with_return_less_than(dir, inv)			_closing_loop_less_than(dir, inv, with, WPointer, return out;)
#define closing_loop_fast_return_less_than(dir, inv)			_closing_loop_less_than(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_less_than_or_equal(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_less_than_or_equal(dir, inv)		_closing_loop_less_than_or_equal(dir, inv, no, void, )
#define closing_loop_with_return_less_than_or_equal(dir, inv)		_closing_loop_less_than_or_equal(dir, inv, with, WPointer, return out;)
#define closing_loop_fast_return_less_than_or_equal(dir, inv)		_closing_loop_less_than_or_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_greater_than(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_greater_than(dir, inv)			_closing_loop_greater_than(dir, inv, no, void, )
#define closing_loop_with_return_greater_than(dir, inv)			_closing_loop_greater_than(dir, inv, with, WPointer, return out;)
#define closing_loop_fast_return_greater_than(dir, inv)			_closing_loop_greater_than(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_greater_than_or_equal(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_greater_than_or_equal(dir, inv)		_closing_loop_greater_than_or_equal(dir, inv, no, void, )
#define closing_loop_with_return_greater_than_or_equal(dir, inv)	_closing_loop_greater_than_or_equal(dir, inv, with, WPointer, return out;)
#define closing_loop_fast_return_greater_than_or_equal(dir, inv)	_closing_loop_greater_than_or_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_plus(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_plus(dir, inv)				_closing_loop_plus(dir, inv, no, void, )
#define closing_loop_with_return_plus(dir, inv)				_closing_loop_plus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_plus_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_plus_half(dir, inv)			_closing_loop_plus_half(dir, inv, no, void, )
#define closing_loop_with_return_plus_half(dir, inv)			_closing_loop_plus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_minus(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_minus(dir, inv)				_closing_loop_minus(dir, inv, no, void, )
#define closing_loop_with_return_minus(dir, inv)			_closing_loop_minus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_minus_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_minus_half(dir, inv)			_closing_loop_minus_half(dir, inv, no, void, )
#define closing_loop_with_return_minus_half(dir, inv)			_closing_loop_minus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_scale(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_scale(dir, inv)				_closing_loop_scale(dir, inv, no, void, )
#define closing_loop_with_return_scale(dir, inv)			_closing_loop_scale(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_scale_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_scale_half(dir, inv)			_closing_loop_scale_half(dir, inv, no, void, )
#define closing_loop_with_return_scale_half(dir, inv)			_closing_loop_scale_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_multiply(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_multiply(dir, inv)			_closing_loop_multiply(dir, inv, no, void, )
#define closing_loop_with_return_multiply(dir, inv)			_closing_loop_multiply(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_multiply_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_multiply_half(dir, inv)			_closing_loop_multiply_half(dir, inv, no, void, )
#define closing_loop_with_return_multiply_half(dir, inv)		_closing_loop_multiply_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_divide(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_divide(dir, inv)				_closing_loop_divide(dir, inv, no, void, )
#define closing_loop_with_return_divide(dir, inv)			_closing_loop_divide(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	rc is the second carry value.
		Set this to zero for the "normal" interpretation.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator.
	d is the half digit denominator.
*/

/*
	Constraints:

*/

#define _closing_loop_divide_half_digit(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WValueType1, typename WValueType2, \
	typename WPointer, typename RIterator, typename ERIterator, typename RValueType> \
static rtn label##_return(WValueType1 r, WValueType2 rc, WPointer q, RIterator n, ERIterator end, RValueType d) \
{ \
	while (n != end) \
	{ \
		if (rc) *q=wufs_policy::math::divide::half::with_return(rc, rc, r, d); \
		else if (r >= d) { *q=r/d; rc=r%d; } \
		else { *q=0; rc=r; } \
 \
		r=*n; \
		q=dir(q)=new WNode; \
		dir##dir(n); \
	} \
 \
	stmt \
}

#define closing_loop_no_return_divide_half_digit(dir, inv)		_closing_loop_divide_half_digit(dir, inv, no, void, )
#define closing_loop_with_return_divide_half_digit(dir, inv)		_closing_loop_divide_half_digit(dir, inv, with, WPointer, return q;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_divide_single_digit(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_divide_single_digit(dir, inv)		_closing_loop_divide_single_digit(dir, inv, no, void, )
#define closing_loop_with_return_divide_single_digit(dir, inv)		_closing_loop_divide_single_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_divide_single_digit_half(dir, inv)	_closing_loop_divide_single_digit_half(dir, inv, no, void, )
#define closing_loop_with_return_divide_single_digit_half(dir, inv)	_closing_loop_divide_single_digit_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

// change zero to segment::zero

#define _closing_loop_radix(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WValueType, typename WPointer, typename EWPointer, typename ValueType> \
static rtn label##_return(WPointer out, WPointer in, EWPointer end, ValueType base) \
{ \
	WPointer out1, end1; \
 \
	while (!zero::fast::closing::with_break(in, end)) \
	{ \
		*out=*in; \
		out1=new WNode; \
//		end1=divide::half_digit::closing::consume::as::closed::template \
		end1=divide::half_digit::closing::template with_return<WNode, WValueType>(*out, 0, out1, +in, end, base); \
 \
		WPointer current=out; \
		out=new WNode; \
		dir(out)=current; \
 \
//		delete in; \
		identity::clear::closed::template no_return(in, end); \
		in=out1; \
		end=end1; \
	} \
 \
	identity::clear::closed::template no_return(out1, end1); \
 \
	stmt \
}

#define closing_loop_no_return_radix(dir, inv)				_closing_loop_radix(dir, inv, no, void, )
#define closing_loop_with_return_radix(dir, inv)			_closing_loop_radix(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_radix_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_radix_half(dir, inv)			_closing_loop_radix_half(dir, inv, no, void, )
#define closing_loop_with_return_radix_half(dir, inv)			_closing_loop_radix_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_plus(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_plus(dir, inv)			_closing_loop_assign_plus(dir, inv, no, void, )
#define closing_loop_with_return_assign_plus(dir, inv)			_closing_loop_assign_plus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_plus_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_plus_half(dir, inv)		_closing_loop_assign_plus_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_plus_half(dir, inv)		_closing_loop_assign_plus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_minus(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_minus(dir, inv)			_closing_loop_assign_minus(dir, inv, no, void, )
#define closing_loop_with_return_assign_minus(dir, inv)			_closing_loop_assign_minus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_minus_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_minus_half(dir, inv)		_closing_loop_assign_minus_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_minus_half(dir, inv)		_closing_loop_assign_minus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_scale(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_scale(dir, inv)			_closing_loop_assign_scale(dir, inv, no, void, )
#define closing_loop_with_return_assign_scale(dir, inv)			_closing_loop_assign_scale(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_scale_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_scale_half(dir, inv)		_closing_loop_assign_scale_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_scale_half(dir, inv)		_closing_loop_assign_scale_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_multiply(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_multiply(dir, inv)		_closing_loop_assign_multiply(dir, inv, no, void, )
#define closing_loop_with_return_assign_multiply(dir, inv)		_closing_loop_assign_multiply(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_multiply_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_multiply_half(dir, inv)		_closing_loop_assign_multiply_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_multiply_half(dir, inv)		_closing_loop_assign_multiply_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_divide(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_divide(dir, inv)			_closing_loop_assign_divide(dir, inv, no, void, )
#define closing_loop_with_return_assign_divide(dir, inv)		_closing_loop_assign_divide(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_divide_half_digit(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_divide_half_digit(dir, inv)	_closing_loop_assign_divide_half_digit(dir, inv, no, void, )
#define closing_loop_with_return_assign_divide_half_digit(dir, inv)	_closing_loop_assign_divide_half_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_divide_single_digit(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_divide_single_digit(dir, inv)	_closing_loop_assign_divide_single_digit(dir, inv, no, void, )
#define closing_loop_with_return_assign_divide_single_digit(dir, inv)	_closing_loop_assign_divide_single_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_divide_single_digit_half(dir, inv)	_closing_loop_assign_divide_single_digit_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_divide_single_digit_half(dir, inv)	_closing_loop_assign_divide_single_digit_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_radix(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_radix(dir, inv)			_closing_loop_assign_radix(dir, inv, no, void, )
#define closing_loop_with_return_assign_radix(dir, inv)			_closing_loop_assign_radix(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_radix_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_radix_half(dir, inv)		_closing_loop_assign_radix_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_radix_half(dir, inv)		_closing_loop_assign_radix_half(dir, inv, with, WPointer, return out;)

