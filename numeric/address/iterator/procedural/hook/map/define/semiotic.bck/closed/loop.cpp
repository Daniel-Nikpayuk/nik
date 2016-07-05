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

/*
	The main design point when it comes to conversions is that the context is preserved/modified, and only
	the filler end points are gained or lost:

	[x, y) --> [x, y-1]
	[x, y) --> (x-1, y-1]
	[x, y) --> (x-1, y)
*/

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> [out, out + n]
*/

#define _closed_loop_0(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename ValueType> \
static rtn label##_return(WPointer out, size_type n, ValueType in) \
{ \
	while (n) \
	{ \
		(*out)op(in); \
		out=dir(out)=new WNode; \
		--n; \
	} \
 \
	(*out)op(in); \
 \
	stmt \
}

#define closed_loop_no_return_0(dir, inv, op)				_closed_loop_0(dir, inv, op, no, void, )
#define closed_loop_with_return_0(dir, inv, op)				_closed_loop_0(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> [out, out + n+1)
*/

#define _closed_loop_as_closing_0(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename ValueType> \
static rtn label##_return(WPointer out, size_type n, ValueType in) \
{ \
	++n; \
 \
	while (n) \
	{ \
		(*out)op(in); \
		out=dir(out)=new WNode; \
		--n; \
	} \
 \
	stmt \
}

#define closed_loop_no_return_as_closing_0(dir, inv, op)		_closed_loop_as_closing_0(dir, inv, op, no, void, )
#define closed_loop_with_return_as_closing_0(dir, inv, op)		_closed_loop_as_closing_0(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

#define _closed_loop_as_closed_0(dir, inv, op, label, rtn, stmt)

#define closed_loop_no_return_as_closed_0(dir, inv, op)			_closed_loop_as_closed_0(dir, inv, op, no, void, )
#define closed_loop_with_return_as_closed_0(dir, inv, op)		_closed_loop_as_closed_0(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> (out, out + n+1]
*/

#define _closed_loop_as_opening_0(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename ValueType> \
static rtn label##_return(WPointer out, size_type n, ValueType in) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out=dir(out)=new WNode; \
		(*out)op(in); \
		--n; \
	} \
 \
	stmt \
}

#define closed_loop_no_return_as_opening_0(dir, inv, op)		_closed_loop_as_opening_0(dir, inv, op, no, void, )
#define closed_loop_with_return_as_opening_0(dir, inv, op)		_closed_loop_as_opening_0(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> (out, out + n+2)
*/

#define _closed_loop_as_open_0(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename ValueType> \
static rtn label##_return(WPointer out, size_type n, ValueType in) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out=dir(out)=new WNode; \
		(*out)op(in); \
		--n; \
	} \
 \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_as_open_0(dir, inv, op)			_closed_loop_as_open_0(dir, inv, op, no, void, )
#define closed_loop_with_return_as_open_0(dir, inv, op)			_closed_loop_as_open_0(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> [out, out + n]
*/

#define _closed_loop_lr_0(dir, inv, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n) \
{ \
	while (n) \
	{ \
		lp(*out)rp; \
		out=dir(out)=new WNode; \
		--n; \
	} \
 \
	lp(*out)rp; \
 \
	stmt \
}

#define closed_loop_no_return_left_0(dir, inv, op)			_closed_loop_lr_0(dir, inv, no, void, , op, )
#define closed_loop_with_return_left_0(dir, inv, op)			_closed_loop_lr_0(dir, inv, with, WPointer, return out;, op, )

#define closed_loop_no_return_right_0(dir, inv, op)			_closed_loop_lr_0(dir, inv, no, void, , , op)
#define closed_loop_with_return_right_0(dir, inv, op)			_closed_loop_lr_0(dir, inv, with, WPointer, return out;, , op)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> [out, out + n+1)
*/

#define _closed_loop_lr_as_closing_0(dir, inv, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n) \
{ \
	++n; \
 \
	while (n) \
	{ \
		lp(*out)rp; \
		out=dir(out)=new WNode; \
		--n; \
	} \
 \
	stmt \
}

#define closed_loop_no_return_left_as_closing_0(dir, inv, op)		_closed_loop_lr_as_closing_0(dir, inv, no, void, , op, )
#define closed_loop_with_return_left_as_closing_0(dir, inv, op)		_closed_loop_lr_as_closing_0(dir, inv, with, WPointer, return out;, op, )

#define closed_loop_no_return_right_as_closing_0(dir, inv, op)		_closed_loop_lr_as_closing_0(dir, inv, no, void, , , op)
#define closed_loop_with_return_right_as_closing_0(dir, inv, op)	_closed_loop_lr_as_closing_0(dir, inv, with, WPointer, return out;, , op)

/************************************************************************************************************************/

#define _closed_loop_lr_as_closed_0(dir, inv, label, rtn, stmt, lp, rp)

#define closed_loop_no_return_left_as_closed_0(dir, inv, op)		_closed_loop_lr_as_closed_0(dir, inv, no, void, , op, )
#define closed_loop_with_return_left_as_closed_0(dir, inv, op)		_closed_loop_lr_as_closed_0(dir, inv, with, WPointer, return out;, op, )

#define closed_loop_no_return_right_as_closed_0(dir, inv, op)		_closed_loop_lr_as_closed_0(dir, inv, no, void, , , op)
#define closed_loop_with_return_right_as_closed_0(dir, inv, op)		_closed_loop_lr_as_closed_0(dir, inv, with, WPointer, return out;, , op)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> (out, out + n+1]
*/

#define _closed_loop_lr_as_opening_0(dir, inv, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out=dir(out)=new WNode; \
		lp(*out)rp; \
		--n; \
	} \
 \
	stmt \
}

#define closed_loop_no_return_left_as_opening_0(dir, inv, op)		_closed_loop_lr_as_opening_0(dir, inv, no, void, , op, )
#define closed_loop_with_return_left_as_opening_0(dir, inv, op)		_closed_loop_lr_as_opening_0(dir, inv, with, WPointer, return out;, op, )

#define closed_loop_no_return_right_as_opening_0(dir, inv, op)		_closed_loop_lr_as_opening_0(dir, inv, no, void, , , op)
#define closed_loop_with_return_right_as_opening_0(dir, inv, op)	_closed_loop_lr_as_opening_0(dir, inv, with, WPointer, return out;, , op)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> (out, out + n+2)
*/

#define _closed_loop_lr_as_open_0(dir, inv, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out=dir(out)=new WNode; \
		lp(*out)rp; \
		--n; \
	} \
 \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_left_as_open_0(dir, inv, op)		_closed_loop_lr_as_open_0(dir, inv, no, void, , op, )
#define closed_loop_with_return_left_as_open_0(dir, inv, op)		_closed_loop_lr_as_open_0(dir, inv, with, WPointer, return out;, op, )

#define closed_loop_no_return_right_as_open_0(dir, inv, op)		_closed_loop_lr_as_open_0(dir, inv, no, void, , , op)
#define closed_loop_with_return_right_as_open_0(dir, inv, op)		_closed_loop_lr_as_open_0(dir, inv, with, WPointer, return out;, , op)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> [out, out + n]
*/

#define _closed_loop_new_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n) \
{ \
	while (n) \
	{ \
		*out=new Node(); \
		out=dir(out)=new WNode; \
		--n; \
	} \
 \
	*out=new Node(); \
 \
	stmt \
}

#define closed_loop_no_return_new_0(dir, inv)				_closed_loop_new_0(dir, inv, no, void, )
#define closed_loop_with_return_new_0(dir, inv)				_closed_loop_new_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> [out, out + n+1)
*/

#define _closed_loop_new_as_closing_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n) \
{ \
	++n; \
 \
	while (n) \
	{ \
		*out=new Node(); \
		out=dir(out)=new WNode; \
		--n; \
	} \
 \
	stmt \
}

#define closed_loop_no_return_new_as_closing_0(dir, inv)		_closed_loop_new_as_closing_0(dir, inv, no, void, )
#define closed_loop_with_return_new_as_closing_0(dir, inv)		_closed_loop_new_as_closing_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

#define _closed_loop_new_as_closed_0(dir, inv, label, rtn, stmt)

#define closed_loop_no_return_new_as_closed_0(dir, inv)			_closed_loop_new_as_closed_0(dir, inv, no, void, )
#define closed_loop_with_return_new_as_closed_0(dir, inv)		_closed_loop_new_as_closed_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> (out, out + n+1]
*/

#define _closed_loop_new_as_opening_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out=dir(out)=new WNode; \
		*out=new Node(); \
		--n; \
	} \
 \
	stmt \
}

#define closed_loop_no_return_new_as_opening_0(dir, inv)		_closed_loop_new_as_opening_0(dir, inv, no, void, )
#define closed_loop_with_return_new_as_opening_0(dir, inv)		_closed_loop_new_as_opening_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> (out, out + n+2)
*/

#define _closed_loop_new_as_open_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out=dir(out)=new WNode; \
		*out=new Node(); \
		--n; \
	} \
 \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_new_as_open_0(dir, inv)			_closed_loop_new_as_open_0(dir, inv, no, void, )
#define closed_loop_with_return_new_as_open_0(dir, inv)			_closed_loop_new_as_open_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> [out, out + n]
*/

#define _closed_loop_new_brackets_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n, size_type in) \
{ \
	while (n) \
	{ \
		*out=new Node[in]; \
		out=dir(out)=new WNode; \
		--n; \
	} \
 \
	*out=new Node[in]; \
 \
	stmt \
}

#define closed_loop_no_return_new_brackets_0(dir, inv)			_closed_loop_new_brackets_0(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_0(dir, inv)		_closed_loop_new_brackets_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> [out, out + n+1)
*/

#define _closed_loop_new_brackets_as_closing_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n, size_type in) \
{ \
	++n; \
 \
	while (n) \
	{ \
		*out=new Node[in]; \
		out=dir(out)=new WNode; \
		--n; \
	} \
 \
	stmt \
}

#define closed_loop_no_return_new_brackets_as_closing_0(dir, inv)	_closed_loop_new_brackets_as_closing_0(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_as_closing_0(dir, inv)	_closed_loop_new_brackets_as_closing_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

#define _closed_loop_new_brackets_as_closed_0(dir, inv, label, rtn, stmt)

#define closed_loop_no_return_new_brackets_as_closed_0(dir, inv)	_closed_loop_new_brackets_as_closed_0(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_as_closed_0(dir, inv)	_closed_loop_new_brackets_as_closed_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> (out, out + n+1]
*/

#define _closed_loop_new_brackets_as_opening_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n, size_type in) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out=dir(out)=new WNode; \
		*out=new Node[in]; \
		--n; \
	} \
 \
	stmt \
}

#define closed_loop_no_return_new_brackets_as_opening_0(dir, inv)	_closed_loop_new_brackets_as_opening_0(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_as_opening_0(dir, inv)	_closed_loop_new_brackets_as_opening_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[0, n] --> (out, out + n+2)
*/

#define _closed_loop_new_brackets_as_open_0(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer> \
static rtn label##_return(WPointer out, size_type n, size_type in) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out=dir(out)=new WNode; \
		*out=new Node[in]; \
		--n; \
	} \
 \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_new_brackets_as_open_0(dir, inv)		_closed_loop_new_brackets_as_open_0(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_as_open_0(dir, inv)	_closed_loop_new_brackets_as_open_0(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[out, end] --> [out, end]
*/

#define _closed_loop_delete_0(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename EWPointer> \
static rtn label##_return(WPointer out, EWPointer end) \
{ \
	while (out != end) \
	{ \
		WPointer current=out; \
		dir##dir(out); \
		delete op *current; \
		delete current; \
	} \
 \
	delete op *out; \
	delete out; \
 \
	stmt \
}

#define closed_loop_no_return_delete_0(dir, inv)			_closed_loop_delete_0(dir, inv, , no, void, )
#define closed_loop_with_return_delete_0(dir, inv)			// would return a deallocated memory location!

#define closed_loop_no_return_delete_brackets_0(dir, inv)		_closed_loop_delete_0(dir, inv, [], no, void, )
#define closed_loop_with_return_delete_brackets_0(dir, inv)		// would return a deallocated memory location!

/************************************************************************************************************************/

#define _closed_loop_delete_as_closing_0(dir, inv, op, label, rtn, stmt)

#define closed_loop_no_return_delete_as_closing_0(dir, inv)		_closed_loop_delete_as_closing_0(dir, inv, , no, void, )
#define closed_loop_with_return_delete_as_closing_0(dir, inv)		// would return a deallocated memory location!

#define closed_loop_no_return_delete_brackets_as_closing_0(dir, inv)	_closed_loop_delete_as_closing_0(dir, inv, [], no, void, )
#define closed_loop_with_return_delete_brackets_as_closing_0(dir, inv)	// would return a deallocated memory location!

/************************************************************************************************************************/

#define _closed_loop_delete_as_closed_0(dir, inv, op, label, rtn, stmt)

#define closed_loop_no_return_delete_as_closed_0(dir, inv)		_closed_loop_delete_as_closed_0(dir, inv, , no, void, )
#define closed_loop_with_return_delete_as_closed_0(dir, inv)		// would return a deallocated memory location!

#define closed_loop_no_return_delete_brackets_as_closed_0(dir, inv)	_closed_loop_delete_as_closed_0(dir, inv, [], no, void, )
#define closed_loop_with_return_delete_brackets_as_closed_0(dir, inv)	// would return a deallocated memory location!

/************************************************************************************************************************/

#define _closed_loop_delete_as_opening_0(dir, inv, op, label, rtn, stmt)

#define closed_loop_no_return_delete_as_opening_0(dir, inv)		_closed_loop_delete_as_opening_0(dir, inv, , no, void, )
#define closed_loop_with_return_delete_as_opening_0(dir, inv)		// would return a deallocated memory location!

#define closed_loop_no_return_delete_brackets_as_opening_0(dir, inv)	_closed_loop_delete_as_opening_0(dir, inv, [], no, void, )
#define closed_loop_with_return_delete_brackets_as_opening_0(dir, inv)	// would return a deallocated memory location!

/************************************************************************************************************************/

#define _closed_loop_delete_as_open_0(dir, inv, op, label, rtn, stmt)

#define closed_loop_no_return_delete_as_open_0(dir, inv)		_closed_loop_delete_as_open_0(dir, inv, , no, void, )
#define closed_loop_with_return_delete_as_open_0(dir, inv)		// would return a deallocated memory location!

#define closed_loop_no_return_delete_brackets_as_open_0(dir, inv)	_closed_loop_delete_as_open_0(dir, inv, [], no, void, )
#define closed_loop_with_return_delete_brackets_as_open_0(dir, inv)	// would return a deallocated memory location!

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[in, end] --> [out, out + (end-in)]
*/

#define _closed_loop_lr_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	lp(*out)op(*in)rp; \
 \
	stmt \
}

#define closed_loop_no_return_1(dir, inv, op)				_closed_loop_lr_1(dir, inv, op, no, void, , , )
#define closed_loop_with_return_1(dir, inv, op)				_closed_loop_lr_1(dir, inv, op, with, WPointer, return out;, , )

#define closed_loop_no_return_right_1(dir, inv, op, r)			_closed_loop_lr_1(dir, inv, op, no, void, , , r)
#define closed_loop_with_return_right_1(dir, inv, op, r)		_closed_loop_lr_1(dir, inv, op, with, WPointer, return out;, , r)

/************************************************************************************************************************/

/*
	Constraints:

	[in, end] --> [out, out + (end-in)+1)
*/

#define _closed_loop_lr_as_closing_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	lp(*out)op(*in)rp; \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_as_closing_1(dir, inv, op)		_closed_loop_lr_as_closing_1(dir, inv, op, no, void, , , )
#define closed_loop_with_return_as_closing_1(dir, inv, op)		_closed_loop_lr_as_closing_1(dir, inv, op, with, WPointer, return out;, , )

#define closed_loop_no_return_right_as_closing_1(dir, inv, op, r)	_closed_loop_lr_as_closing_1(dir, inv, op, no, void, , , r)
#define closed_loop_with_return_right_as_closing_1(dir, inv, op, r)	_closed_loop_lr_as_closing_1(dir, inv, op, with, WPointer, return out;, , r)

/************************************************************************************************************************/

#define _closed_loop_lr_as_closed_1(dir, inv, op, label, rtn, stmt, lp, rp)

#define closed_loop_no_return_as_closed_1(dir, inv, op)			_closed_loop_lr_as_closed_1(dir, inv, op, no, void, , , )
#define closed_loop_with_return_as_closed_1(dir, inv, op)		_closed_loop_lr_as_closed_1(dir, inv, op, with, WPointer, return out;, , )

#define closed_loop_no_return_right_as_closed_1(dir, inv, op, r)	_closed_loop_lr_as_closed_1(dir, inv, op, no, void, , , r)
#define closed_loop_with_return_right_as_closed_1(dir, inv, op, r)	_closed_loop_lr_as_closed_1(dir, inv, op, with, WPointer, return out;, , r)

/************************************************************************************************************************/

/*
	Constraints:

	[in, end] --> (out, out + (end-in)+1]
*/

#define _closed_loop_lr_as_opening_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		lp(*out)op(*in)rp; \
		dir##dir(in); \
	} \
 \
	out=dir(out)=new WNode; \
	lp(*out)op(*in)rp; \
 \
	stmt \
}

#define closed_loop_no_return_as_opening_1(dir, inv, op)		_closed_loop_lr_as_opening_1(dir, inv, op, no, void, , , )
#define closed_loop_with_return_as_opening_1(dir, inv, op)		_closed_loop_lr_as_opening_1(dir, inv, op, with, WPointer, return out;, , )

#define closed_loop_no_return_right_as_opening_1(dir, inv, op, r)	_closed_loop_lr_as_opening_1(dir, inv, op, no, void, , , r)
#define closed_loop_with_return_right_as_opening_1(dir, inv, op, r)	_closed_loop_lr_as_opening_1(dir, inv, op, with, WPointer, return out;, , r)

/************************************************************************************************************************/

/*
	Constraints:

	[in, end] --> (out, out + (end-in)+2)
*/

#define _closed_loop_lr_as_open_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		lp(*out)op(*in)rp; \
		dir##dir(in); \
	} \
 \
	out=dir(out)=new WNode; \
	lp(*out)op(*in)rp; \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_as_open_1(dir, inv, op)			_closed_loop_lr_as_open_1(dir, inv, op, no, void, , , )
#define closed_loop_with_return_as_open_1(dir, inv, op)			_closed_loop_lr_as_open_1(dir, inv, op, with, WPointer, return out;, , )

#define closed_loop_no_return_right_as_open_1(dir, inv, op, r)		_closed_loop_lr_as_open_1(dir, inv, op, no, void, , , r)
#define closed_loop_with_return_right_as_open_1(dir, inv, op, r)	_closed_loop_lr_as_open_1(dir, inv, op, with, WPointer, return out;, , r)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[in, end] --> [out, out + (end-in)]
*/

#define _closed_loop_new_brackets_1(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer, typename RPointer, typename ERPointer> \
static rtn label##_return(WPointer out, RPointer in, ERPointer end) \
{ \
	while (in != end) \
	{ \
		*out=new Node[*in]; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	*out=new Node[*in]; \
 \
	stmt \
}

#define closed_loop_no_return_new_brackets_1(dir, inv)			_closed_loop_new_brackets_1(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_1(dir, inv)		_closed_loop_new_brackets_1(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in, end] --> [out, out + (end-in)+1)
*/

#define _closed_loop_new_brackets_as_closing_1(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer, typename RPointer, typename ERPointer> \
static rtn label##_return(WPointer out, RPointer in, ERPointer end) \
{ \
	while (in != end) \
	{ \
		*out=new Node[*in]; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	*out=new Node[*in]; \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_new_brackets_as_closing_1(dir, inv)	_closed_loop_new_brackets_as_closing_1(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_as_closing_1(dir, inv)	_closed_loop_new_brackets_as_closing_1(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

#define _closed_loop_new_brackets_as_closed_1(dir, inv, label, rtn, stmt)

#define closed_loop_no_return_new_brackets_as_closed_1(dir, inv)	_closed_loop_new_brackets_as_closed_1(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_as_closed_1(dir, inv)	_closed_loop_new_brackets_as_closed_1(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in, end] --> (out, out + (end-in)+1]
*/

#define _closed_loop_new_brackets_as_opening_1(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer, typename RPointer, typename ERPointer> \
static rtn label##_return(WPointer out, RPointer in, ERPointer end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		*out=new Node[*in]; \
		dir##dir(in); \
	} \
 \
	out=dir(out)=new WNode; \
	*out=new Node[*in]; \
 \
	stmt \
}

#define closed_loop_no_return_new_brackets_as_opening_1(dir, inv)	_closed_loop_new_brackets_as_opening_1(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_as_opening_1(dir, inv)	_closed_loop_new_brackets_as_opening_1(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in, end] --> (out, out + (end-in)+2)
*/

#define _closed_loop_new_brackets_as_open_1(dir, inv, label, rtn, stmt) \
template<typename Node, typename WNode, typename WPointer, typename RPointer, typename ERPointer> \
static rtn label##_return(WPointer out, RPointer in, ERPointer end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		*out=new Node[*in]; \
		dir##dir(in); \
	} \
 \
	out=dir(out)=new WNode; \
	*out=new Node[*in]; \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_new_brackets_as_open_1(dir, inv)		_closed_loop_new_brackets_as_open_1(dir, inv, no, void, )
#define closed_loop_with_return_new_brackets_as_open_1(dir, inv)	_closed_loop_new_brackets_as_open_1(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[in2, end2] --> [out, out + (end2-in2)]
*/

#define _closed_loop_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		*out=(*in1)op(*in2); \
		out=dir(out)=new WNode; \
		dir##dir(in1); dir##dir(in2); \
	} \
 \
	*out=(*in1)op(*in2); \
 \
	stmt \
}

#define closed_loop_no_return_2(dir, inv, op)				_closed_loop_2(dir, inv, op, no, void, )
#define closed_loop_with_return_2(dir, inv, op)				_closed_loop_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in2, end2] --> [out, out + (end2-in2)+1)
*/

#define _closed_loop_as_closing_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		*out=(*in1)op(*in2); \
		out=dir(out)=new WNode; \
		dir##dir(in1); dir##dir(in2); \
	} \
 \
	*out=(*in1)op(*in2); \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_as_closing_2(dir, inv, op)		_closed_loop_as_closing_2(dir, inv, op, no, void, )
#define closed_loop_with_return_as_closing_2(dir, inv, op)		_closed_loop_as_closing_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

#define _closed_loop_as_closed_2(dir, inv, op, label, rtn, stmt)

#define closed_loop_no_return_as_closed_2(dir, inv, op)			_closed_loop_as_closed_2(dir, inv, op, no, void, )
#define closed_loop_with_return_as_closed_2(dir, inv, op)		_closed_loop_as_closed_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in2, end2] --> (out, out + (end2-in2)+1]
*/

#define _closed_loop_as_opening_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		out=dir(out)=new WNode; \
		*out=(*in1)op(*in2); \
		dir##dir(in1); dir##dir(in2); \
	} \
 \
	out=dir(out)=new WNode; \
	*out=(*in1)op(*in2); \
 \
	stmt \
}

#define closed_loop_no_return_as_opening_2(dir, inv, op)		_closed_loop_as_opening_2(dir, inv, op, no, void, )
#define closed_loop_with_return_as_opening_2(dir, inv, op)		_closed_loop_as_opening_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in2, end2] --> (out, out + (end2-in2)+2)
*/

#define _closed_loop_as_open_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		out=dir(out)=new WNode; \
		*out=(*in1)op(*in2); \
		dir##dir(in1); dir##dir(in2); \
	} \
 \
	out=dir(out)=new WNode; \
	*out=(*in1)op(*in2); \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_as_open_2(dir, inv, op)			_closed_loop_as_open_2(dir, inv, op, no, void, )
#define closed_loop_with_return_as_open_2(dir, inv, op)			_closed_loop_as_open_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	Constraints:

	[in2, end2] --> [out, out + (end2-in2)]
*/

#define _closed_loop_brackets_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		*out=(*in1)op[*in2]; \
		out=dir(out)=new WNode; \
		dir##dir(in1); dir##dir(in2); \
	} \
 \
	*out=(*in1)op[*in2]; \
 \
	stmt \
}

#define closed_loop_no_return_brackets_2(dir, inv, op)			_closed_loop_brackets_2(dir, inv, op, no, void, )
#define closed_loop_with_return_brackets_2(dir, inv, op)		_closed_loop_brackets_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in2, end2] --> [out, out + (end2-in2)+1)
*/

#define _closed_loop_brackets_as_closing_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		*out=(*in1)op[*in2]; \
		out=dir(out)=new WNode; \
		dir##dir(in1); dir##dir(in2); \
	} \
 \
	*out=(*in1)op[*in2]; \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_brackets_as_closing_2(dir, inv, op)	_closed_loop_brackets_as_closing_2(dir, inv, op, no, void, )
#define closed_loop_with_return_brackets_as_closing_2(dir, inv, op)	_closed_loop_brackets_as_closing_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

#define _closed_loop_brackets_as_closed_2(dir, inv, op, label, rtn, stmt)

#define closed_loop_no_return_brackets_as_closed_2(dir, inv, op)	_closed_loop_brackets_as_closed_2(dir, inv, op, no, void, )
#define closed_loop_with_return_brackets_as_closed_2(dir, inv, op)	_closed_loop_brackets_as_closed_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in2, end2] --> (out, out + (end2-in2)+1]
*/

#define _closed_loop_brackets_as_opening_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		out=dir(out)=new WNode; \
		*out=(*in1)op[*in2]; \
		dir##dir(in1); dir##dir(in2); \
	} \
 \
	out=dir(out)=new WNode; \
	*out=(*in1)op[*in2]; \
 \
	stmt \
}

#define closed_loop_no_return_brackets_as_opening_2(dir, inv, op)	_closed_loop_brackets_as_opening_2(dir, inv, op, no, void, )
#define closed_loop_with_return_brackets_as_opening_2(dir, inv, op)	_closed_loop_brackets_as_opening_2(dir, inv, op, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

	[in2, end2] --> (out, out + (end2-in2)+2)
*/

#define _closed_loop_brackets_as_open_2(dir, inv, op, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		out=dir(out)=new WNode; \
		*out=(*in1)op[*in2]; \
		dir##dir(in1); dir##dir(in2); \
	} \
 \
	out=dir(out)=new WNode; \
	*out=(*in1)op[*in2]; \
	out=dir(out)=new WNode; \
 \
	stmt \
}

#define closed_loop_no_return_brackets_as_open_2(dir, inv, op)		_closed_loop_brackets_as_open_2(dir, inv, op, no, void, )
#define closed_loop_with_return_brackets_as_open_2(dir, inv, op)	_closed_loop_brackets_as_open_2(dir, inv, op, with, WPointer, return out;)

