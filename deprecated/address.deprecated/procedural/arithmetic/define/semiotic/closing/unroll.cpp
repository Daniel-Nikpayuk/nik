/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#define _closing_unroll_zero(dir, inv, label, rtn, stmt)

#define closing_unroll_no_break_zero(dir, inv)				_closing_unroll_zero(dir, inv, no, void, )
#define closing_unroll_with_break_zero(dir, inv)			_closing_unroll_zero(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_zero_fast(dir, inv, label, rtn, stmt)

#define closing_unroll_no_break_zero_fast(dir, inv)			_closing_unroll_zero_fast(dir, inv, no, void, )
#define closing_unroll_with_break_zero_fast(dir, inv)			_closing_unroll_zero_fast(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_equal(dir, inv, label, rtn, stmt)

#define closing_unroll_no_break_equal(dir, inv)				_closing_unroll_equal(dir, inv, no, void, )
#define closing_unroll_with_break_equal(dir, inv)			_closing_unroll_equal(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_equal_fast(dir, inv, label, rtn, stmt)

#define closing_unroll_no_break_equal_fast(dir, inv)			_closing_unroll_equal_fast(dir, inv, no, void, )
#define closing_unroll_with_break_equal_fast(dir, inv)			_closing_unroll_equal_fast(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_not_equal(dir, inv, label, rtn, stmt)

#define closing_unroll_no_break_not_equal(dir, inv)			_closing_unroll_not_equal(dir, inv, no, void, )
#define closing_unroll_with_break_not_equal(dir, inv)			_closing_unroll_not_equal(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_not_equal_fast(dir, inv, label, rtn, stmt)

#define closing_unroll_no_break_not_equal_fast(dir, inv)		_closing_unroll_not_equal_fast(dir, inv, no, void, )
#define closing_unroll_with_break_not_equal_fast(dir, inv)		_closing_unroll_not_equal_fast(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_less_than(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_less_than(dir, inv)			_closing_unroll_less_than(dir, inv, no, void, )
#define closing_unroll_with_return_less_than(dir, inv)			_closing_unroll_less_than(dir, inv, with, WPointer, return)
#define closing_unroll_fast_return_less_than(dir, inv)			_closing_unroll_less_than(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_less_than_or_equal(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_less_than_or_equal(dir, inv)		_closing_unroll_less_than_or_equal(dir, inv, no, void, )
#define closing_unroll_with_return_less_than_or_equal(dir, inv)		_closing_unroll_less_than_or_equal(dir, inv, with, WPointer, return)
#define closing_unroll_fast_return_less_than_or_equal(dir, inv)		_closing_unroll_less_than_or_equal(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_greater_than(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_greater_than(dir, inv)			_closing_unroll_greater_than(dir, inv, no, void, )
#define closing_unroll_with_return_greater_than(dir, inv)		_closing_unroll_greater_than(dir, inv, with, WPointer, return)
#define closing_unroll_fast_return_greater_than(dir, inv)		_closing_unroll_greater_than(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_greater_than_or_equal(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_greater_than_or_equal(dir, inv)	_closing_unroll_greater_than_or_equal(dir, inv, no, void, )
#define closing_unroll_with_return_greater_than_or_equal(dir, inv)	_closing_unroll_greater_than_or_equal(dir, inv, with, WPointer, return)
#define closing_unroll_fast_return_greater_than_or_equal(dir, inv)	_closing_unroll_greater_than_or_equal(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_plus(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_plus(dir, inv)				_closing_unroll_plus(dir, inv, no, void, )
#define closing_unroll_with_return_plus(dir, inv)			_closing_unroll_plus(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_plus_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_plus_half(dir, inv)			_closing_unroll_plus_half(dir, inv, no, void, )
#define closing_unroll_with_return_plus_half(dir, inv)			_closing_unroll_plus_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_minus(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_minus(dir, inv)			_closing_unroll_minus(dir, inv, no, void, )
#define closing_unroll_with_return_minus(dir, inv)			_closing_unroll_minus(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_minus_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_minus_half(dir, inv)			_closing_unroll_minus_half(dir, inv, no, void, )
#define closing_unroll_with_return_minus_half(dir, inv)			_closing_unroll_minus_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_scale(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_scale(dir, inv)			_closing_unroll_scale(dir, inv, no, void, )
#define closing_unroll_with_return_scale(dir, inv)			_closing_unroll_scale(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_scale_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_scale_half(dir, inv)			_closing_unroll_scale_half(dir, inv, no, void, )
#define closing_unroll_with_return_scale_half(dir, inv)			_closing_unroll_scale_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_radix(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_radix(dir, inv)			_closing_unroll_radix(dir, inv, no, void, )
#define closing_unroll_with_return_radix(dir, inv)			_closing_unroll_radix(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_radix_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_radix_half(dir, inv)		_closing_unroll_radix_half(dir, inv, no, void, )
#define closing_unroll_with_return_radix_half(dir, inv)		_closing_unroll_radix_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_divide(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_divide(dir, inv)			_closing_unroll_divide(dir, inv, no, void, )
#define closing_unroll_with_return_divide(dir, inv)			_closing_unroll_divide(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_divide_half_digit(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_divide_half_digit(dir, inv)		_closing_unroll_divide_half_digit(dir, inv, no, void, )
#define closing_unroll_with_return_divide_half_digit(dir, inv)		_closing_unroll_divide_half_digit(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_divide_single_digit(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_divide_single_digit(dir, inv)		_closing_unroll_divide_single_digit(dir, inv, no, void, )
#define closing_unroll_with_return_divide_single_digit(dir, inv)	_closing_unroll_divide_single_digit(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_divide_single_digit_half(dir, inv)	_closing_unroll_divide_single_digit_half(dir, inv, no, void, )
#define closing_unroll_with_return_divide_single_digit_half(dir, inv)	_closing_unroll_divide_single_digit_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_multiply(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_multiply(dir, inv)			_closing_unroll_multiply(dir, inv, no, void, )
#define closing_unroll_with_return_multiply(dir, inv)			_closing_unroll_multiply(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_multiply_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_multiply_half(dir, inv)		_closing_unroll_multiply_half(dir, inv, no, void, )
#define closing_unroll_with_return_multiply_half(dir, inv)		_closing_unroll_multiply_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_plus(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_plus(dir, inv)			_closing_unroll_assign_plus(dir, inv, no, void, )
#define closing_unroll_with_return_assign_plus(dir, inv)		_closing_unroll_assign_plus(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_plus_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_plus_half(dir, inv)		_closing_unroll_assign_plus_half(dir, inv, no, void, )
#define closing_unroll_with_return_assign_plus_half(dir, inv)		_closing_unroll_assign_plus_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_minus(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_minus(dir, inv)			_closing_unroll_assign_minus(dir, inv, no, void, )
#define closing_unroll_with_return_assign_minus(dir, inv)		_closing_unroll_assign_minus(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_minus_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_minus_half(dir, inv)		_closing_unroll_assign_minus_half(dir, inv, no, void, )
#define closing_unroll_with_return_assign_minus_half(dir, inv)		_closing_unroll_assign_minus_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_scale(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_scale(dir, inv)			_closing_unroll_assign_scale(dir, inv, no, void, )
#define closing_unroll_with_return_assign_scale(dir, inv)		_closing_unroll_assign_scale(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_scale_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_scale_half(dir, inv)		_closing_unroll_assign_scale_half(dir, inv, no, void, )
#define closing_unroll_with_return_assign_scale_half(dir, inv)		_closing_unroll_assign_scale_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_multiply(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_multiply(dir, inv)		_closing_unroll_assign_multiply(dir, inv, no, void, )
#define closing_unroll_with_return_assign_multiply(dir, inv)		_closing_unroll_assign_multiply(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_multiply_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_multiply_half(dir, inv)		_closing_unroll_assign_multiply_half(dir, inv, no, void, )
#define closing_unroll_with_return_assign_multiply_half(dir, inv)	_closing_unroll_assign_multiply_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_divide(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_divide(dir, inv)		_closing_unroll_assign_divide(dir, inv, no, void, )
#define closing_unroll_with_return_assign_divide(dir, inv)		_closing_unroll_assign_divide(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_divide_half_digit(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_divide_half_digit(dir, inv)	_closing_unroll_assign_divide_half_digit(dir, inv, no, void, )
#define closing_unroll_with_return_assign_divide_half_digit(dir, inv)	_closing_unroll_assign_divide_half_digit(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_divide_single_digit(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_divide_single_digit(dir, inv)	_closing_unroll_assign_divide_single_digit(dir, inv, no, void, )
#define closing_unroll_with_return_assign_divide_single_digit(dir, inv)	_closing_unroll_assign_divide_single_digit(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_divide_single_digit_half(dir, inv)	_closing_unroll_assign_divide_single_digit_half(dir, inv, no, void, )
#define closing_unroll_with_return_assign_divide_single_digit_half(dir, inv)	_closing_unroll_assign_divide_single_digit_half(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_radix(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_radix(dir, inv)			_closing_unroll_radix(dir, inv, no, void, )
#define closing_unroll_with_return_radix(dir, inv)			_closing_unroll_radix(dir, inv, with, WPointer, return)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_radix_half(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_radix_half(dir, inv)		_closing_unroll_radix_half(dir, inv, no, void, )
#define closing_unroll_with_return_radix_half(dir, inv)		_closing_unroll_radix_half(dir, inv, with, WPointer, return)

