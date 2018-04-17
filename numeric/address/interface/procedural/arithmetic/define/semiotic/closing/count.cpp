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

#define _closing_count_zero(dir, inv, label, rtn, stmt)

#define closing_count_no_break_zero(dir, inv)				_closing_count_zero(dir, inv, no, void, )
#define closing_count_with_break_zero(dir, inv)				_closing_count_zero(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_zero_fast(dir, inv, label, rtn, stmt)

#define closing_count_no_break_zero_fast(dir, inv)			_closing_count_zero_fast(dir, inv, no, void, )
#define closing_count_with_break_zero_fast(dir, inv)			_closing_count_zero_fast(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_equal(dir, inv, label, rtn, stmt)

#define closing_count_no_break_equal(dir, inv)				_closing_count_equal(dir, inv, no, void, )
#define closing_count_with_break_equal(dir, inv)			_closing_count_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_equal_fast(dir, inv, label, rtn, stmt)

#define closing_count_no_break_equal_fast(dir, inv)			_closing_count_equal_fast(dir, inv, no, void, )
#define closing_count_with_break_equal_fast(dir, inv)			_closing_count_equal_fast(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_not_equal(dir, inv, label, rtn, stmt)

#define closing_count_no_break_not_equal(dir, inv)			_closing_count_not_equal(dir, inv, no, void, )
#define closing_count_with_break_not_equal(dir, inv)			_closing_count_not_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_not_equal_fast(dir, inv, label, rtn, stmt)

#define closing_count_no_break_not_equal_fast(dir, inv)			_closing_count_not_equal_fast(dir, inv, no, void, )
#define closing_count_with_break_not_equal_fast(dir, inv)		_closing_count_not_equal_fast(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_less_than(dir, inv, label, rtn, stmt)

#define closing_count_no_return_less_than(dir, inv)			_closing_count_less_than(dir, inv, no, void, )
#define closing_count_with_return_less_than(dir, inv)			_closing_count_less_than(dir, inv, with, WPointer, return out;)
#define closing_count_fast_return_less_than(dir, inv)			_closing_count_less_than(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_less_than_or_equal(dir, inv, label, rtn, stmt)

#define closing_count_no_return_less_than_or_equal(dir, inv)		_closing_count_less_than_or_equal(dir, inv, no, void, )
#define closing_count_with_return_less_than_or_equal(dir, inv)		_closing_count_less_than_or_equal(dir, inv, with, WPointer, return out;)
#define closing_count_fast_return_less_than_or_equal(dir, inv)		_closing_count_less_than_or_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_greater_than(dir, inv, label, rtn, stmt)

#define closing_count_no_return_greater_than(dir, inv)			_closing_count_greater_than(dir, inv, no, void, )
#define closing_count_with_return_greater_than(dir, inv)		_closing_count_greater_than(dir, inv, with, WPointer, return out;)
#define closing_count_fast_return_greater_than(dir, inv)		_closing_count_greater_than(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_greater_than_or_equal(dir, inv, label, rtn, stmt)

#define closing_count_no_return_greater_than_or_equal(dir, inv)		_closing_count_greater_than_or_equal(dir, inv, no, void, )
#define closing_count_with_return_greater_than_or_equal(dir, inv)	_closing_count_greater_than_or_equal(dir, inv, with, WPointer, return out;)
#define closing_count_fast_return_greater_than_or_equal(dir, inv)	_closing_count_greater_than_or_equal(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_plus(dir, inv, label, rtn, stmt)

#define closing_count_no_return_plus(dir, inv)				_closing_count_plus(dir, inv, no, void, )
#define closing_count_with_return_plus(dir, inv)			_closing_count_plus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_plus_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_plus_half(dir, inv)			_closing_count_plus_half(dir, inv, no, void, )
#define closing_count_with_return_plus_half(dir, inv)			_closing_count_plus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_minus(dir, inv, label, rtn, stmt)

#define closing_count_no_return_minus(dir, inv)				_closing_count_minus(dir, inv, no, void, )
#define closing_count_with_return_minus(dir, inv)			_closing_count_minus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_minus_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_minus_half(dir, inv)			_closing_count_minus_half(dir, inv, no, void, )
#define closing_count_with_return_minus_half(dir, inv)			_closing_count_minus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_scale(dir, inv, label, rtn, stmt)

#define closing_count_no_return_scale(dir, inv)				_closing_count_scale(dir, inv, no, void, )
#define closing_count_with_return_scale(dir, inv)			_closing_count_scale(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_scale_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_scale_half(dir, inv)			_closing_count_scale_half(dir, inv, no, void, )
#define closing_count_with_return_scale_half(dir, inv)			_closing_count_scale_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_multiply(dir, inv, label, rtn, stmt)

#define closing_count_no_return_multiply(dir, inv)			_closing_count_multiply(dir, inv, no, void, )
#define closing_count_with_return_multiply(dir, inv)			_closing_count_multiply(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_multiply_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_multiply_half(dir, inv)			_closing_count_multiply_half(dir, inv, no, void, )
#define closing_count_with_return_multiply_half(dir, inv)		_closing_count_multiply_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_divide(dir, inv, label, rtn, stmt)

#define closing_count_no_return_divide(dir, inv)			_closing_count_divide(dir, inv, no, void, )
#define closing_count_with_return_divide(dir, inv)			_closing_count_divide(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_divide_half_digit(dir, inv, label, rtn, stmt)

#define closing_count_no_return_divide_half_digit(dir, inv)		_closing_count_divide_half_digit(dir, inv, no, void, )
#define closing_count_with_return_divide_half_digit(dir, inv)		_closing_count_divide_half_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_divide_single_digit(dir, inv, label, rtn, stmt)

#define closing_count_no_return_divide_single_digit(dir, inv)		_closing_count_divide_single_digit(dir, inv, no, void, )
#define closing_count_with_return_divide_single_digit(dir, inv)		_closing_count_divide_single_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_divide_single_digit_half(dir, inv)	_closing_count_divide_single_digit_half(dir, inv, no, void, )
#define closing_count_with_return_divide_single_digit_half(dir, inv)	_closing_count_divide_single_digit_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_radix(dir, inv, label, rtn, stmt)

#define closing_count_no_return_radix(dir, inv)				_closing_count_radix(dir, inv, no, void, )
#define closing_count_with_return_radix(dir, inv)			_closing_count_radix(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_radix_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_radix_half(dir, inv)			_closing_count_radix_half(dir, inv, no, void, )
#define closing_count_with_return_radix_half(dir, inv)			_closing_count_radix_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_plus(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_plus(dir, inv)			_closing_count_assign_plus(dir, inv, no, void, )
#define closing_count_with_return_assign_plus(dir, inv)			_closing_count_assign_plus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_plus_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_plus_half(dir, inv)		_closing_count_assign_plus_half(dir, inv, no, void, )
#define closing_count_with_return_assign_plus_half(dir, inv)		_closing_count_assign_plus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_minus(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_minus(dir, inv)			_closing_count_assign_minus(dir, inv, no, void, )
#define closing_count_with_return_assign_minus(dir, inv)		_closing_count_assign_minus(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_minus_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_minus_half(dir, inv)		_closing_count_assign_minus_half(dir, inv, no, void, )
#define closing_count_with_return_assign_minus_half(dir, inv)		_closing_count_assign_minus_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_scale(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_scale(dir, inv)			_closing_count_assign_scale(dir, inv, no, void, )
#define closing_count_with_return_assign_scale(dir, inv)		_closing_count_assign_scale(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_scale_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_scale_half(dir, inv)		_closing_count_assign_scale_half(dir, inv, no, void, )
#define closing_count_with_return_assign_scale_half(dir, inv)		_closing_count_assign_scale_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_multiply(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_multiply(dir, inv)		_closing_count_assign_multiply(dir, inv, no, void, )
#define closing_count_with_return_assign_multiply(dir, inv)		_closing_count_assign_multiply(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_multiply_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_multiply_half(dir, inv)		_closing_count_assign_multiply_half(dir, inv, no, void, )
#define closing_count_with_return_assign_multiply_half(dir, inv)	_closing_count_assign_multiply_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_divide(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_divide(dir, inv)			_closing_count_assign_divide(dir, inv, no, void, )
#define closing_count_with_return_assign_divide(dir, inv)		_closing_count_assign_divide(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_divide_half_digit(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_divide_half_digit(dir, inv)	_closing_count_assign_divide_half_digit(dir, inv, no, void, )
#define closing_count_with_return_assign_divide_half_digit(dir, inv)	_closing_count_assign_divide_half_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_divide_single_digit(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_divide_single_digit(dir, inv)	_closing_count_assign_divide_single_digit(dir, inv, no, void, )
#define closing_count_with_return_assign_divide_single_digit(dir, inv)	_closing_count_assign_divide_single_digit(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_divide_single_digit_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_divide_single_digit_half(dir, inv)	_closing_count_assign_divide_single_digit_half(dir, inv, no, void, )
#define closing_count_with_return_assign_divide_single_digit_half(dir, inv)	_closing_count_assign_divide_single_digit_half(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_radix(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_radix(dir, inv)			_closing_count_assign_radix(dir, inv, no, void, )
#define closing_count_with_return_assign_radix(dir, inv)		_closing_count_assign_radix(dir, inv, with, WPointer, return out;)

/***********************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_count_assign_radix_half(dir, inv, label, rtn, stmt)

#define closing_count_no_return_assign_radix_half(dir, inv)		_closing_count_assign_radix_half(dir, inv, no, void, )
#define closing_count_with_return_assign_radix_half(dir, inv)		_closing_count_assign_radix_half(dir, inv, with, WPointer, return out;)

