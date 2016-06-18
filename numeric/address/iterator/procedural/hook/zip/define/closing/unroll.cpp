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

/************************************************************************************************************************/

#define _closing_unroll_lr_0(method, dir, inv, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	lp(*out)rp; \
	out=dir(out)=new WNode; \
 \
	stmt unroll<N-1>::method::label##_return(out); \
}

#define closing_unroll_no_return_left_0(method, dir, inv, op)		_closing_unroll_lr_0(method, dir, inv, no, void, , op, )
#define closing_unroll_with_return_left_0(method, dir, inv, op)		_closing_unroll_lr_0(method, dir, inv, with, WPointer, return, op, )

#define closing_unroll_no_return_right_0(method, dir, inv, op)		_closing_unroll_lr_0(method, dir, inv, no, void, , , op)
#define closing_unroll_with_return_right_0(method, dir, inv, op)	_closing_unroll_lr_0(method, dir, inv, with, WPointer, return, , op)

/************************************************************************************************************************/

#define _closing_unroll_new_0(method, dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	*out=new Node(); \
	out=dir(out)=new WNode; \
 \
	stmt unroll<N-1>::method::label##_return(out); \
}

#define closing_unroll_no_return_new_0(method, dir, inv)		_closing_unroll_new_0(method, dir, inv, no, void, )
#define closing_unroll_with_return_new_0(method, dir, inv)		_closing_unroll_new_0(method, dir, inv, with, WPointer, return)

/************************************************************************************************************************/

#define _closing_unroll_new_brackets_0(method, dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type in) \
{ \
	*out=new Node[in]; \
	out=dir(out)=new WNode; \
 \
	stmt unroll<N-1>::method::label##_return(out, in); \
}

#define closing_unroll_no_return_new_brackets_0(method, dir, inv)	_closing_unroll_new_brackets_0(method, dir, inv, no, void, )
#define closing_unroll_with_return_new_brackets_0(method, dir, inv)	_closing_unroll_new_brackets_0(method, dir, inv, with, WPointer, return)

/************************************************************************************************************************/

#define _closing_unroll_delete_0(method, dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	WPointer current=out; \
	dir##dir(out); \
	delete op *current; \
	delete current; \
 \
	stmt unroll<N-1>::method::label##_return(out); \
}

#define closing_unroll_no_return_delete_0(method, dir, inv)		_closing_unroll_delete_0(method, dir, inv, , no, void, )
#define closing_unroll_with_return_delete_0(method, dir, inv)		_closing_unroll_delete_0(method, dir, inv, , with, WPointer, return)

#define closing_unroll_no_return_delete_brackets_0(method, dir, inv)	_closing_unroll_delete_0(method, dir, inv, [], no, void, )
#define closing_unroll_with_return_delete_brackets_0(method, dir, inv)	_closing_unroll_delete_0(method, dir, inv, [], with, WPointer, return)

/************************************************************************************************************************/

#define _closing_unroll_lr_1(method, dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	lp(*out)op(*in)rp; \
	out=dir(out)=new WNode; \
	dir##dir(in); \
 \
	stmt unroll<N-1>::method::label##_return(out, in); \
}

#define closing_unroll_no_return_1(method, dir, inv, op)		_closing_unroll_lr_1(method, dir, inv, op, no, void, , , )
#define closing_unroll_with_return_1(method, dir, inv, op)		_closing_unroll_lr_1(method, dir, inv, op, with, WPointer, return, , )

#define closing_unroll_no_return_right_1(method, dir, inv, op, r)	_closing_unroll_lr_1(method, dir, inv, op, no, void, , , r)
#define closing_unroll_with_return_right_1(method, dir, inv, op, r)	_closing_unroll_lr_1(method, dir, inv, op, with, WPointer, return, , r)

/************************************************************************************************************************/

#define _closing_unroll_new_brackets_1(method, dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer, typename RPointer> \
static rtn label##_return(WPointer out, RPointer in) \
{ \
	*out=new Node[*in]; \
	out=dir(out)=new WNode; \
	dir##dir(in); \
 \
	stmt unroll<N-1>::method::label##_return(out, in); \
}

#define closing_unroll_no_return_new_brackets_1(method, dir, inv)	_closing_unroll_new_brackets_1(method, dir, inv, no, void, )
#define closing_unroll_with_return_new_brackets_1(method, dir, inv)	_closing_unroll_new_brackets_1(method, dir, inv, with, WPointer, return)

/************************************************************************************************************************/

#define _closing_unroll_2(method, dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2) \
{ \
	(*out)=(*in1)op(*in2); \
	out=dir(out)=new WNode; \
	dir##dir(in1); dir##dir(in2); \
 \
	stmt unroll<N-1>::method::label##_return(out, in1, in2); \
}

#define closing_unroll_no_return_2(method, dir, inv, op)		_closing_unroll_2(method, dir, inv, op, no, void, )
#define closing_unroll_with_return_2(method, dir, inv, op)		_closing_unroll_2(method, dir, inv, op, with, WPointer, return)

/************************************************************************************************************************/

#define _closing_unroll_brackets_2(method, dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2) \
{ \
	(*out)=(*in1)op[*in2]; \
	out=dir(out)=new WNode; \
	dir##dir(in1); dir##dir(in2); \
 \
	stmt unroll<N-1>::method::label##_return(out, in1, in2); \
}

#define closing_unroll_no_return_brackets_2(method, dir, inv, op)	_closing_unroll_brackets_2(method, dir, inv, op, no, void, )
#define closing_unroll_with_return_brackets_2(method, dir, inv, op)	_closing_unroll_brackets_2(method, dir, inv, op, with, WPointer, return)

