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

	As "out" is assign shifted when its "+out" is allocated, there is no need to increment seperately.
*/

/************************************************************************************************************************/

/*
	Constraints:

	[in, end), in != end
*/

#define _closing_unroll_pop_left(interval, dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	stmt zip::unroll<N>::assign::interval::template label##_return<WNode>(out, +in, end); \
}

#define closing_unroll_no_return_pop_left(interval, dir, inv)		_closing_unroll_pop_left(interval, dir, inv, no, void, )
#define closing_unroll_with_return_pop_left(interval, dir, inv)		_closing_unroll_pop_left(interval, dir, inv, with, WPointer, return)

/************************************************************************************************************************/

/*
	Constraints:

	[in, end), in != end
*/

#define _closing_loop_pop_right(interval, dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (dir(in) != end) \
	{ \
		*out=*in; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	*out=*in; \
 \
	stmt \
}

#define closing_loop_no_return_pop_right(interval, dir, inv)	_closing_loop_pop_right(interval, dir, inv, no, void, )
#define closing_loop_with_return_pop_right(interval, dir, inv)	_closing_loop_pop_right(interval, dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, N)
*/

#define _closing_unroll_0(method, dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename ValueType> \
static rtn label##_return(WPointer out, ValueType in) \
{ \
	(*out)op(in); \
	out=dir(out)=new WNode; \
 \
	stmt unroll<N-1>::method::label##_return(out, in); \
}

#define closing_unroll_no_return_0(method, dir, inv, op)		_closing_unroll_0(method, dir, inv, op, no, void, )
#define closing_unroll_with_return_0(method, dir, inv, op)		_closing_unroll_0(method, dir, inv, op, with, WPointer, return)

