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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_EXCLUSIVE_UNROLL_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_EXCLUSIVE_UNROLL_H

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	The ordering of "op" then "new" is intentional as it provides higher composability of these methods.
	As "out" is assign shifted when its "+out" is allocated, there is no need to increment seperately.

	unroll:
			Compiler constraints require factoring out the size_type parameter, for the partial specializations of unroll.
			I have therefore factored it out as the templated "extend" struct. Notice the semantics of the word "extend"
			itself are a signifier of the overhead word space, which is to say it's a metaname.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/

/*
	There's no need for a "return" version of const_overload as the out iterator equals the end iterator upon halting.
*/
#define unroll_no_return_0(method, dir, op) \
template<typename WPointer, typename ValueType> \
static void no_return(WPointer out, ValueType in) \
{ \
	out=dir(out)=new WPointer(); \
	(*out)op(in); \
	unroll<N-1>::method::no_return(out, in); \
}

/*
	There's no need for a "return" version of const_overload as the out iterator equals the end iterator upon halting.
*/
#define unroll_with_return_0(method, dir, op) \
template<typename WPointer, typename ValueType> \
static WPointer with_return(WPointer out, ValueType in) \
{ \
	out=dir(out)=new WPointer(); \
	(*out)op(in); \
	return unroll<N-1>::method::with_return(out, in); \
}

/*
	There's no need for a "return" version of constant_overload as the out iterator equals the end iterator upon halting.
*/
#define unroll_no_return_left_0(method, dir, op) \
template<typename WPointer> \
static void no_return(WPointer out) \
{ \
	out=dir(out)=new WPointer(); \
	op(*out); \
	unroll<N-1>::method::no_return(out); \
}

/*
	There's no need for a "return" version of constant_overload as the out iterator equals the end iterator upon halting.
*/
#define unroll_no_return_right_0(method, dir, op) \
template<typename WPointer> \
static void no_return(WPointer out) \
{ \
	out=dir(out)=new WPointer(); \
	(*out)op; \
	unroll<N-1>::method::no_return(out); \
}

/************************************************************************************************************************/

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with WPointer as reference (assuming referencing is preferred).
*/
#define unroll_no_return_1(method, dir, op) \
template<typename WPointer, typename RIterator> \
static void no_return(WPointer out, RIterator in) \
{ \
	dir##dir(in); \
	out=dir(out)=new WPointer(); \
	(*out)op(*in); \
	unroll<N-1>::method::no_return(out, in); \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but in addition you still require a return value, call this macro.
*/
#define unroll_with_return_1(method, dir, op) \
template<typename WPointer, typename RIterator> \
static WPointer with_return(WPointer out, RIterator in) \
{ \
	dir##dir(in); \
	out=dir(out)=new WPointer(); \
	(*out)op(*in); \
	return unroll<N-1>::method::with_return(out, in); \
}

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with WPointer as reference (assuming referencing is preferred).
*/
#define unroll_no_return_right_1(method, dir, op, r) \
template<typename WPointer, typename RIterator> \
static void no_return(WPointer out, RIterator in) \
{ \
	dir##dir(in); \
	out=dir(out)=new WPointer(); \
	(*out)op(*in)r; \
	unroll<N-1>::method::no_return(out, in); \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but in addition you still require a return value, call this macro.
*/
#define unroll_with_return_right_1(method, dir, op, r) \
template<typename WPointer, typename RIterator> \
static WPointer with_return(WPointer out, RIterator in) \
{ \
	dir##dir(in); \
	out=dir(out)=new WPointer(); \
	*(out)op(*in)r; \
	return unroll<N-1>::method::with_return(out, in); \
}

/************************************************************************************************************************/

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with WPointer as reference (assuming referencing is preferred).
*/
#define unroll_no_return_2(method, dir, op) \
template<typename WPointer, typename RIterator1, typename RIterator2> \
static void no_return(WPointer out, RIterator1 in1, RIterator2 in2) \
{ \
	dir##dir(in1); dir##dir(in2); \
	out=dir(out)=new WPointer(); \
	(*out)=(*in1)op(*in2); \
	unroll<N-1>::method::no_return(out, in1, in2); \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but in addition you still require a return value, call this macro.
*/
#define unroll_with_return_2(method, dir, op) \
template<typename WPointer, typename RIterator1, typename RIterator2> \
static WPointer with_return(WPointer out, RIterator1 in1, RIterator2 in2) \
{ \
	dir##dir(in1); dir##dir(in2); \
	out=dir(out)=new WPointer(); \
	(*out)=(*in1)op(*in2); \
	return unroll<N-1>::method::with_return(out, in1, in2); \
}

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with WPointer as reference (assuming referencing is preferred).
*/
#define unroll_no_return_bracket_2(method, dir, op) \
template<typename WPointer, typename RIterator1, typename RIterator2> \
static void no_return(WPointer out, RIterator1 in1, RIterator2 in2) \
{ \
	dir##dir(in1); dir##dir(in2); \
	out=dir(out)=new WPointer(); \
	(*out)=(*in1)op[*in2]; \
	unroll<N-1>::method::no_return(out, in1, in2); \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but in addition you still require a return value, call this macro.
*/
#define unroll_with_return_bracket_2(method, dir, op) \
template<typename WPointer, typename RIterator1, typename RIterator2> \
static WPointer with_return(WPointer out, RIterator1 in1, RIterator2 in2) \
{ \
	dir##dir(in1); dir##dir(in2); \
	out=dir(out)=new WPointer(); \
	(*out)=(*in1)op[*in2]; \
	return unroll<N-1>::method::with_return(out, in1, in2); \
}

#endif
