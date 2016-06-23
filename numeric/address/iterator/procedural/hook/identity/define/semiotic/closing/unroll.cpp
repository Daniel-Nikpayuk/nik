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

////////////////////////////// Set up but not yet analyzed or coded!!!!!

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

#define _closing_unroll_clear(dir, inv, label, rtn, stmt) \
template<typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	delete (out)dir##dir; \
 \
	stmt unroll<N-1>::clear::closing::label##_return(out); \
}

#define closing_unroll_no_return_clear(dir, inv)			_closing_unroll_clear(dir, inv, no, void, )
#define closing_unroll_with_return_clear(dir, inv)			_closing_unroll_clear(dir, inv, with, WPointer, return)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_close_left(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_close_left(dir, inv)			_closing_unroll_close_left(dir, inv, no, void, )
#define closing_unroll_with_return_close_left(dir, inv)		_closing_unroll_close_left(dir, inv, with, WPointer, return)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_close_right(dir, inv, label, rtn, stmt) \
template<typename WPointer> \
static rtn label##_return(WPointer out) \
{ \
	out+=N-1; \
	delete dir(out); \
 \
	stmt \
}

#define closing_unroll_no_return_close_right(dir, inv)			_closing_unroll_close_right(dir, inv, no, void, )
#define closing_unroll_with_return_close_right(dir, inv)		_closing_unroll_close_right(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_open_left(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer> \
static rtn label##_return(WPointer in) \
{ \
	WPointer out=new WNode; \
	dir(out)=in; \
 \
	stmt \
}

#define closing_unroll_no_return_open_left(dir, inv)			_closing_unroll_open_left(dir, inv, no, void, )
#define closing_unroll_with_return_open_left(dir, inv)			_closing_unroll_open_left(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_open_right(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_open_right(dir, inv)			_closing_unroll_open_right(dir, inv, no, void, )
#define closing_unroll_with_return_open_right(dir, inv)		_closing_unroll_open_right(dir, inv, with, WPointer, return)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_as_closing(dir, inv, label, rtn, stmt)

#define closing_unroll_no_return_assign_as_closing(dir, inv)		_closing_unroll_assign_as_closing(dir, inv, no, void, )
#define closing_unroll_with_return_assign_as_closing(dir, inv)		_closing_unroll_assign_as_closing(dir, inv, with, WPointer, return)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_as_closed(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn _##label##_return(WPointer out, RIterator in) \
{ \
	*out=*in; \
	out=dir(out)=new WNode; \
	dir##dir(in); \
 \
	stmt unroll<N-1>::clear::closing::label##_return(out); \
} \
 \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	*unroll<N-1>::clear::closing::_with_return(out)=*in; \
 \
	stmt \
}

#define closing_unroll_no_return_assign_as_closed(dir, inv)		_closing_unroll_assign_as_closed(dir, inv, no, void, )
#define closing_unroll_with_return_assign_as_closed(dir, inv)		_closing_unroll_assign_as_closed(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_as_opening(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn _##label##_return(WPointer out, RIterator in) \
{ \
	*out=*in; \
	out=dir(out)=new WNode; \
	dir##dir(in); \
 \
	stmt unroll<N-1>::clear::closing::label##_return(out); \
} \
 \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	out=dir(out)=new WNode; \
	*unroll<N-1>::clear::closing::_with_return(out)=*in; \
 \
	stmt \
}

#define closing_unroll_no_return_assign_as_opening(dir, inv)		_closing_unroll_assign_as_opening(dir, inv, no, void, )
#define closing_unroll_with_return_assign_as_opening(dir, inv)		_closing_unroll_assign_as_opening(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_assign_as_open(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	out=dir(out)=new WNode; \
	stmt zip::template unroll<N>::assign::closing::template label##_return<WNode>(out, in); \
}

#define closing_unroll_no_return_assign_as_open(dir, inv)		_closing_unroll_assign_as_open(dir, inv, no, void, )
#define closing_unroll_with_return_assign_as_open(dir, inv)		_closing_unroll_assign_as_open(dir, inv, with, WPointer, return)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_catenate_with_closing(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	out=search::template unroll<N>::find::index::before::end::with_return(out); \
	delete dir(out); \
	dir(out)=in; \
 \
	stmt \
}

#define closing_unroll_no_return_catenate_with_closing(dir, inv)	_closing_unroll_catenate_with_closing(dir, inv, no, void, )
#define closing_unroll_with_return_catenate_with_closing(dir, inv)	_closing_unroll_catenate_with_closing(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_catenate_with_closed(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	out=search::template unroll<N>::find::index::before::end::with_return(out); \
	delete dir(out); \
	dir(out)=in; \
 \
	stmt \
}

#define closing_unroll_no_return_catenate_with_closed(dir, inv)	_closing_unroll_catenate_with_closed(dir, inv, no, void, )
#define closing_unroll_with_return_catenate_with_closed(dir, inv)	_closing_unroll_catenate_with_closed(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_catenate_with_opening(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	out=search::template unroll<N>::find::index::before::end::with_return(out); \
	delete dir(out); \
	dir(out)=dir(in); \
	delete in; \
 \
	stmt \
}

#define closing_unroll_no_return_catenate_with_opening(dir, inv)	_closing_unroll_catenate_with_opening(dir, inv, no, void, )
#define closing_unroll_with_return_catenate_with_opening(dir, inv)	_closing_unroll_catenate_with_opening(dir, inv, with, WPointer, return out;)

/************************************************************************************************************************/

/*
	Constraints:

*/

#define _closing_unroll_catenate_with_open(dir, inv, label, rtn, stmt) \
template<typename WNode, typename WPointer, typename RIterator> \
static rtn label##_return(WPointer out, RIterator in) \
{ \
	out=search::template unroll<N>::find::index::before::end::with_return(out); \
	delete dir(out); \
	dir(out)=dir(in); \
	delete in; \
 \
	stmt \
}

#define closing_unroll_no_return_catenate_with_open(dir, inv)		_closing_unroll_catenate_with_open(dir, inv, no, void, )
#define closing_unroll_with_return_catenate_with_open(dir, inv)	_closing_unroll_catenate_with_open(dir, inv, with, WPointer, return out;)

