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

	The ordering of "op" then "new" is intentional as it provides higher composability of these methods.
	As "out" is assign shifted when its "+out" is allocated, there is no need to increment seperately.
*/

/************************************************************************************************************************/

#define _opening_unroll_0(method, dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename ValueType> \
static rtn label##_return(WPointer out, ValueType in) \
{ \
	out=dir(out)=new WNode; \
	(*out)op(in); \
 \
	stmt unroll<N-1>::method::label##_return(out, in); \
}

#define opening_unroll_no_return_0(method, dir, inv, op)		_opening_unroll_0(method, dir, inv, op, no, void, )
#define opening_unroll_with_return_0(method, dir, inv, op)		_opening_unroll_0(method, dir, inv, op, with, WPointer, return)

/************************************************************************************************************************/

#define _opening_unroll_lr_0(method, dir, inv, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	out=dir(out)=new WNode; \
	lp(*out)rp; \
 \
	stmt unroll<N-1>::method::label##_return(out); \
}

#define opening_unroll_no_return_left_0(method, dir, inv, op)		_opening_unroll_lr_0(method, dir, inv, no, void, , op, )
#define opening_unroll_with_return_left_0(method, dir, inv, op)		_opening_unroll_lr_0(method, dir, inv, with, WPointer, return, op, )

#define opening_unroll_no_return_right_0(method, dir, inv, op)		_opening_unroll_lr_0(method, dir, inv, no, void, , , op)
#define opening_unroll_with_return_right_0(method, dir, inv, op)	_opening_unroll_lr_0(method, dir, inv, with, WPointer, return, , op)

/************************************************************************************************************************/

#define _opening_unroll_new_0(method, dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	out=dir(out)=new WNode; \
	*out=new Node(); \
 \
	stmt unroll<N-1>::method::label##_return(out); \
}

#define opening_unroll_no_return_new_0(method, dir, inv)		_opening_unroll_new_0(method, dir, inv, no, void, )
#define opening_unroll_with_return_new_0(method, dir, inv)		_opening_unroll_new_0(method, dir, inv, with, WPointer, return)

/************************************************************************************************************************/

#define _opening_unroll_new_brackets_0(method, dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type in) \
{ \
	out=dir(out)=new WNode; \
	*out=new Node[in]; \
 \
	stmt unroll<N-1>::method::label##_return(out, in); \
}

#define opening_unroll_no_return_new_brackets_0(method, dir, inv)	_opening_unroll_new_brackets_0(method, dir, inv, no, void, )
#define opening_unroll_with_return_new_brackets_0(method, dir, inv)	_opening_unroll_new_brackets_0(method, dir, inv, with, WPointer, return)

/************************************************************************************************************************/

/*
	The only form that satifies the design constraints exists already as the "closing" version.
*/

#define _opening_unroll_delete_0(method, dir, inv, op, label, rtn, stmt)

#define opening_unroll_no_return_delete_0(method, dir, inv)		_opening_unroll_delete_0(method, dir, inv, , no, void, )
#define opening_unroll_with_return_delete_0(method, dir, inv)		_opening_unroll_delete_0(method, dir, inv, , with, WPointer, return)

#define opening_unroll_no_return_delete_brackets_0(method, dir, inv)	_opening_unroll_delete_0(method, dir, inv, [], no, void, )
#define opening_unroll_with_return_delete_brackets_0(method, dir, inv)	_opening_unroll_delete_0(method, dir, inv, [], with, WPointer, return)

/************************************************************************************************************************/

#define _opening_unroll_lr_1(method, dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	dir##dir(in); \
	out=dir(out)=new WNode; \
	lp(*out)op(*in)rp; \
 \
	stmt unroll<N-1>::method::label##_return(out, in); \
}

#define opening_unroll_no_return_1(method, dir, inv, op)		_opening_unroll_lr_1(method, dir, inv, op, no, void, , , )
#define opening_unroll_with_return_1(method, dir, inv, op)		_opening_unroll_lr_1(method, dir, inv, op, with, WPointer, return, , )

#define opening_unroll_no_return_right_1(method, dir, inv, op, r)	_opening_unroll_lr_1(method, dir, inv, op, no, void, , , r)
#define opening_unroll_with_return_right_1(method, dir, inv, op, r)	_opening_unroll_lr_1(method, dir, inv, op, with, WPointer, return, , r)

/************************************************************************************************************************/

#define _opening_unroll_new_brackets_1(method, dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer, typename RPointer> \
static rtn label##_return(WPointer out, RPointer in) \
{ \
	dir##dir(in); \
	out=dir(out)=new WNode; \
	*out=new Node[*in]; \
 \
	stmt unroll<N-1>::method::label##_return(out, in); \
}

#define opening_unroll_no_return_new_brackets_1(method, dir, inv)	_opening_unroll_new_brackets_1(method, dir, inv, no, void, )
#define opening_unroll_with_return_new_brackets_1(method, dir, inv)	_opening_unroll_new_brackets_1(method, dir, inv, with, WPointer, return)

/************************************************************************************************************************/

#define _opening_unroll_2(method, dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2) \
{ \
	dir##dir(in2); dir##dir(in1); \
	out=dir(out)=new WNode; \
	(*out)=(*in1)op(*in2); \
 \
	stmt unroll<N-1>::method::label##_return(out, in1, in2); \
}

#define opening_unroll_no_return_2(method, dir, inv, op)		_opening_unroll_2(method, dir, inv, op, no, void, )
#define opening_unroll_with_return_2(method, dir, inv, op)		_opening_unroll_2(method, dir, inv, op, with, WPointer, return)

/************************************************************************************************************************/

#define _opening_unroll_brackets_2(method, dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2) \
{ \
	dir##dir(in2); dir##dir(in1); \
	out=dir(out)=new WNode; \
	(*out)=(*in1)op[*in2]; \
 \
	stmt unroll<N-1>::method::label##_return(out, in1, in2); \
}

#define opening_unroll_no_return_brackets_2(method, dir, inv, op)	_opening_unroll_brackets_2(method, dir, inv, op, no, void, )
#define opening_unroll_with_return_brackets_2(method, dir, inv, op)	_opening_unroll_brackets_2(method, dir, inv, op, with, WPointer, return)

