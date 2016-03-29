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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_MACRO_POST_TEST_DEFINE_COUNT_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_MACRO_POST_TEST_DEFINE_COUNT_H

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	The ordering of "op" then "new" is intentional as it provides higher composability of these methods.
	As "out" is assign shifted when its "+out" is allocated, there is no need to increment seperately.
*/

#define post_test_count_no_return_0(dir, op)

#define post_test_count_with_return_0(dir, op)

#define post_test_count_no_return_left_0(dir, op)

#define post_test_count_with_return_left_0(dir, op)

#define post_test_count_no_return_right_0(dir, op)

#define post_test_count_with_return_right_0(dir, op)

/************************************************************************************************************************/

#define post_test_count_no_return_1(dir, op) \
template<typename WPointer, typename RIterator, typename ERIterator> \
static void no_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	do \
	{ \
		++count; dir##dir(in); \
		out=dir(out)=new WPointer(); \
		(*out)op(*in); \
	} \
	while (in != end); \
}

#define post_test_count_with_return_1(dir, op) \
template<typename WPointer, typename RIterator, typename ERIterator> \
static WPointer with_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	do \
	{ \
		++count; dir##dir(in); \
		out=dir(out)=new WPointer(); \
		(*out)op(*in); \
	} \
	while (in != end); \
 \
	return out; \
}

#define post_test_count_no_return_right_1(dir, op, r) \
template<typename WPointer, typename RIterator, typename ERIterator> \
static void no_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	do \
	{ \
		++count; dir##dir(in); \
		out=dir(out)=new WPointer(); \
		(*out)op(*in)r; \
	} \
	while (in != end); \
}

#define post_test_count_with_return_right_1(dir, op, r) \
template<typename WPointer, typename RIterator, typename ERIterator> \
static WPointer with_return(size_type & count, WPointer out, RIterator in, ERIterator end) \
{ \
	do \
	{ \
		++count; dir##dir(in); \
		out=dir(out)=new WPointer(); \
		*(out)op(*in)r; \
	} \
	while (in != end); \
 \
	return out; \
}

/************************************************************************************************************************/

#define post_test_count_no_return_2(dir, op) \
template<typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static void no_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	do \
	{ \
		++count; dir##dir(in1); dir##dir(in2); \
		out=dir(out)=new WPointer(); \
		(*out)=(*in1)op(*in2); \
	} \
	while (in2 != end2); \
}

#define post_test_count_with_return_2(dir, op) \
template<typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static WPointer with_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	do \
	{ \
		++count; dir##dir(in1); dir##dir(in2); \
		out=dir(out)=new WPointer(); \
		(*out)=(*in1)op(*in2); \
	} \
	while (in2 != end2); \
 \
	return out; \
}

#define post_test_count_no_return_bracket_2(dir, op) \
template<typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static void no_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	do \
	{ \
		++count; dir##dir(in1); dir##dir(in2); \
		out=dir(out)=new WPointer(); \
		(*out)=(*in1)op[*in2]; \
	} \
	while (in2 != end2); \
}

#define post_test_count_with_return_bracket_2(dir, op) \
template<typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
static WPointer with_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \
{ \
	do \
	{ \
		++count; dir##dir(in1); dir##dir(in2); \
		out=dir(out)=new WPointer(); \
		(*out)=(*in1)op[*in2]; \
	} \
	while (in2 != end2); \
 \
	return out; \
}

/************************************************************************************************************************/

#define post_test_count_no_return_new_0(dir) \
template<typename Pointer, typename WPointer, typename EWPointer> \
static void no_return(size_type & count, WPointer out, EWPointer end) \
{ \
	do \
	{ \
		++count; dir##dir(out); \
		*out=new Pointer(); \
	} \
	while (out != end); \
}

#define post_test_count_with_return_new_0(dir) \
template<typename Pointer, typename WPointer, typename EWPointer> \
static WPointer with_return(size_type & count, WPointer out, EWPointer end) \
{ \
	do \
	{ \
		++count; dir##dir(out); \
		*out=new Pointer(); \
	} \
	while (out != end); \
 \
	return out; \
}

#define post_test_count_no_return_delete_0(dir) \
template<typename WPointer, typename EWPointer> \
static void no_return(size_type & count, WPointer out, EWPointer end) \
{ \
	do \
	{ \
		WPointer current=out; \
		++count; dir##dir(out); \
		delete *current; \
		delete current; \
	} \
	while (out != end); \
}

#define post_test_count_with_return_delete_0(dir) \
template<typename WPointer, typename EWPointer> \
static WPointer with_return(size_type & count, WPointer out, EWPointer end) \
{ \
	do \
	{ \
		WPointer current=out; \
		++count; dir##dir(out); \
		delete *current; \
		delete current; \
	} \
	while (out != end); \
 \
	return out; \
}

#endif
