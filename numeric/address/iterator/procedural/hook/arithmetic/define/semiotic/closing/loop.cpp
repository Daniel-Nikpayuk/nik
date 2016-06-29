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

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_zero(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_zero(dir, inv)				_closing_loop_zero(dir, inv, no, void, )
#define closing_loop_with_break_zero(dir, inv)				_closing_loop_zero(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_zero_fast(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_zero_fast(dir, inv)			_closing_loop_zero_fast(dir, inv, no, void, )
#define closing_loop_with_break_zero_fast(dir, inv)			_closing_loop_zero_fast(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_equal(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_equal(dir, inv)				_closing_loop_equal(dir, inv, no, void, )
#define closing_loop_with_break_equal(dir, inv)				_closing_loop_equal(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_equal_fast(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_equal_fast(dir, inv)			_closing_loop_equal_fast(dir, inv, no, void, )
#define closing_loop_with_break_equal_fast(dir, inv)			_closing_loop_equal_fast(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_not_equal(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_not_equal(dir, inv)			_closing_loop_not_equal(dir, inv, no, void, )
#define closing_loop_with_break_not_equal(dir, inv)			_closing_loop_not_equal(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_not_equal_fast(dir, inv, label, rtn, stmt)

#define closing_loop_no_break_not_equal_fast(dir, inv)			_closing_loop_not_equal_fast(dir, inv, no, void, )
#define closing_loop_with_break_not_equal_fast(dir, inv)		_closing_loop_not_equal_fast(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_less_than(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_less_than(dir, inv)			_closing_loop_less_than(dir, inv, no, void, )
#define closing_loop_with_return_less_than(dir, inv)			_closing_loop_less_than(dir, inv, with, WPointer, return out;)
#define closing_loop_fast_return_less_than(dir, inv)			_closing_loop_less_than(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_less_than_or_equal(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_less_than_or_equal(dir, inv)		_closing_loop_less_than_or_equal(dir, inv, no, void, )
#define closing_loop_with_return_less_than_or_equal(dir, inv)		_closing_loop_less_than_or_equal(dir, inv, with, WPointer, return out;)
#define closing_loop_fast_return_less_than_or_equal(dir, inv)		_closing_loop_less_than_or_equal(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_greater_than(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_greater_than(dir, inv)			_closing_loop_greater_than(dir, inv, no, void, )
#define closing_loop_with_return_greater_than(dir, inv)			_closing_loop_greater_than(dir, inv, with, WPointer, return out;)
#define closing_loop_fast_return_greater_than(dir, inv)			_closing_loop_greater_than(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_greater_than_or_equal(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_greater_than_or_equal(dir, inv)		_closing_loop_greater_than_or_equal(dir, inv, no, void, )
#define closing_loop_with_return_greater_than_or_equal(dir, inv)	_closing_loop_greater_than_or_equal(dir, inv, with, WPointer, return out;)
#define closing_loop_fast_return_greater_than_or_equal(dir, inv)	_closing_loop_greater_than_or_equal(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_plus(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_plus(dir, inv)				_closing_loop_plus(dir, inv, no, void, )
#define closing_loop_with_return_plus(dir, inv)				_closing_loop_plus(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_plus_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_plus_half(dir, inv)			_closing_loop_plus_half(dir, inv, no, void, )
#define closing_loop_with_return_plus_half(dir, inv)			_closing_loop_plus_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_minus(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_minus(dir, inv)				_closing_loop_minus(dir, inv, no, void, )
#define closing_loop_with_return_minus(dir, inv)			_closing_loop_minus(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_minus_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_minus_half(dir, inv)			_closing_loop_minus_half(dir, inv, no, void, )
#define closing_loop_with_return_minus_half(dir, inv)			_closing_loop_minus_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_scale(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_scale(dir, inv)				_closing_loop_scale(dir, inv, no, void, )
#define closing_loop_with_return_scale(dir, inv)			_closing_loop_scale(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_scale_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_scale_half(dir, inv)			_closing_loop_scale_half(dir, inv, no, void, )
#define closing_loop_with_return_scale_half(dir, inv)			_closing_loop_scale_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_divide(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_divide(dir, inv)				_closing_loop_divide(dir, inv, no, void, )
#define closing_loop_with_return_divide(dir, inv)			_closing_loop_divide(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_divide_half_digit(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_divide_half_digit(dir, inv)		_closing_loop_divide_half_digit(dir, inv, no, void, )
#define closing_loop_with_return_divide_half_digit(dir, inv)		_closing_loop_divide_half_digit(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_divide_single_digit(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_divide_single_digit(dir, inv)		_closing_loop_divide_single_digit(dir, inv, no, void, )
#define closing_loop_with_return_divide_single_digit(dir, inv)		_closing_loop_divide_single_digit(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to zero for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	out is the highest location of the quotient to be determined.
	in is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/

/*
	Constraints:

*/

#define _closing_loop_divide_single_digit_half(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WValueType, typename WPointer, typename RIterator, typename ERIterator, typename RValueType> \
static rtn label##_return(WValueType carry, WPointer out, RIterator in, ERIterator end, RValueType d) \
{ \
	while (in != end) \
	{ \
		if (carry >= d) \
		{ \
			*out=carry/d; \
			carry=carry%d; \
			out=dir(out)=new WNode; \
		} \
 \
		(carry <<= wufs_policy::unit::half::length) += *in; \
		dir##dir(in); \
	} \
 \
	stmt \
}

/*
	r is the carry value, which is also semantically meaningful as the remainder.
		Set this to the first digit of the numerator for the "normal" interpretation.
		Digits are shifted into the carry's registers until big enough to divide.
	q is the highest location of the quotient to be determined.
	n is the second highest digit location of the numerator as an N block.
	d is the single digit denominator.
*/

/*
	Constraints:

*/

/*
#define _closing_loop_divide_single_digit_half(dir, inv, label, rtn, stmt) \
template<typename ValueType, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(ValueType r, WPointer q, RIterator n, ERIterator end, ValueType d) \
{ \
	while (n != end) \
	{ \
		if (r < d) *q=0; \
		else { *q=r/d; r=r%d; } \
 \
		(r<<=wufs_policy::unit::half::length)+=*n; \
		--q; --n; \
	} \
 \
	stmt \
}
*/

#define closing_loop_no_return_divide_single_digit_half(dir, inv)	_closing_loop_divide_single_digit_half(dir, inv, no, void, )
#define closing_loop_with_return_divide_single_digit_half(dir, inv)	_closing_loop_divide_single_digit_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_multiply(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_multiply(dir, inv)			_closing_loop_multiply(dir, inv, no, void, )
#define closing_loop_with_return_multiply(dir, inv)			_closing_loop_multiply(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_multiply_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_multiply_half(dir, inv)			_closing_loop_multiply_half(dir, inv, no, void, )
#define closing_loop_with_return_multiply_half(dir, inv)		_closing_loop_multiply_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_plus(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_plus(dir, inv)			_closing_loop_assign_plus(dir, inv, no, void, )
#define closing_loop_with_return_assign_plus(dir, inv)			_closing_loop_assign_plus(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_plus_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_plus_half(dir, inv)		_closing_loop_assign_plus_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_plus_half(dir, inv)		_closing_loop_assign_plus_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_minus(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_minus(dir, inv)			_closing_loop_assign_minus(dir, inv, no, void, )
#define closing_loop_with_return_assign_minus(dir, inv)			_closing_loop_assign_minus(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_minus_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_minus_half(dir, inv)		_closing_loop_assign_minus_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_minus_half(dir, inv)		_closing_loop_assign_minus_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_scale(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_scale(dir, inv)			_closing_loop_assign_scale(dir, inv, no, void, )
#define closing_loop_with_return_assign_scale(dir, inv)			_closing_loop_assign_scale(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_scale_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_scale_half(dir, inv)		_closing_loop_assign_scale_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_scale_half(dir, inv)		_closing_loop_assign_scale_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_divide(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_divide(dir, inv)			_closing_loop_assign_divide(dir, inv, no, void, )
#define closing_loop_with_return_assign_divide(dir, inv)		_closing_loop_assign_divide(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_divide_half_digit(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_divide_half_digit(dir, inv)	_closing_loop_assign_divide_half_digit(dir, inv, no, void, )
#define closing_loop_with_return_assign_divide_half_digit(dir, inv)	_closing_loop_assign_divide_half_digit(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_divide_single_digit(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_divide_single_digit(dir, inv)	_closing_loop_assign_divide_single_digit(dir, inv, no, void, )
#define closing_loop_with_return_assign_divide_single_digit(dir, inv)	_closing_loop_assign_divide_single_digit(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_divide_single_digit_half(dir, inv)	_closing_loop_assign_divide_single_digit_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_divide_single_digit_half(dir, inv)	_closing_loop_assign_divide_single_digit_half(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_multiply(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_multiply(dir, inv)		_closing_loop_assign_multiply(dir, inv, no, void, )
#define closing_loop_with_return_assign_multiply(dir, inv)		_closing_loop_assign_multiply(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_loop_assign_multiply_half(dir, inv, label, rtn, stmt)

#define closing_loop_no_return_assign_multiply_half(dir, inv)		_closing_loop_assign_multiply_half(dir, inv, no, void, )
#define closing_loop_with_return_assign_multiply_half(dir, inv)		_closing_loop_assign_multiply_half(dir, inv, with, WPointer, return out;)

