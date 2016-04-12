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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_MACRO_DEFINE_INITIAL_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_MACRO_DEFINE_INITIAL_H

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	The ordering of "op" then "new" is intentional as it provides higher composability of these methods.
	As "out" is assign shifted when its "+out" is allocated, there is no need to increment seperately.
*/

#define initial_no_return_0(op) \
template<typename WNode, typename WPointer, typename ValueType> \
static void no_return(WPointer out, ValueType in) \
	{ }

#define initial_with_return_0(op) \
template<typename WNode, typename WPointer, typename ValueType> \
static WPointer with_return(WPointer out, ValueType in) \
	{ return out; }

#define initial_no_return_left_0(op) \
template<typename WNode, typename WPointer> \
static void no_return(WPointer out) \
	{ }

#define initial_with_return_left_0(op) \
template<typename WNode, typename WPointer> \
static WPointer with_return(WPointer out) \
	{ return out; }

#define initial_no_return_right_0(op) \
template<typename WNode, typename WPointer> \
static void no_return(WPointer out) \
	{ }

#define initial_with_return_right_0(op) \
template<typename WNode, typename WPointer> \
static WPointer with_return(WPointer out) \
	{ return out; }

#define initial_no_return_new_0(op) \
template<typename Node, typename WNode, typename WPointer> \
static void no_return(WPointer out) \
	{ }

#define initial_with_return_new_0(op) \
template<typename Node, typename WNode, typename WPointer> \
static WPointer with_return(WPointer out) \
	{ return out; }

#define initial_no_return_delete_0(op) \
template<typename WNode, typename WPointer> \
static void no_return(WPointer out) \
	{ }

#define initial_with_return_delete_0(op) \
template<typename WNode, typename WPointer> \
static WPointer with_return(WPointer out) \
	{ return out; }

#define initial_no_return_new_brackets_0(op) \
template<typename Node, typename WNode, typename WPointer> \
static void no_return(WPointer out, size_type in) \
	{ }

#define initial_with_return_new_brackets_0(op) \
template<typename Node, typename WNode, typename WPointer> \
static WPointer with_return(WPointer out, size_type in) \
	{ return out; }

#define initial_no_return_delete_brackets_0(op) \
template<typename WNode, typename WPointer> \
static void no_return(WPointer out) \
	{ }

#define initial_with_return_delete_brackets_0(op) \
template<typename WNode, typename WPointer> \
static WPointer with_return(WPointer out) \
	{ return out; }

/************************************************************************************************************************/

#define initial_no_return_1(op) \
template<typename WNode, typename WPointer, typename RIterator> \
static void no_return(WPointer out, RIterator in) \
	{ }

#define initial_with_return_1(op) \
template<typename WNode, typename WPointer, typename RIterator> \
static WPointer with_return(WPointer out, RIterator in) \
	{ return out; }

#define initial_no_return_right_1(op, r) \
template<typename WNode, typename WPointer, typename RIterator> \
static void no_return(WPointer out, RIterator in) \
	{ }

#define initial_with_return_right_1(op, r) \
template<typename WNode, typename WPointer, typename RIterator> \
static WPointer with_return(WPointer out, RIterator in) \
	{ return out; }

#define initial_no_return_new_brackets_1(op) \
template<typename Node, typename WNode, typename WPointer, typename RPointer> \
static void no_return(WPointer out, RPointer in) \
	{ }

#define initial_with_return_new_brackets_1(op) \
template<typename Node, typename WNode, typename WPointer, typename RPointer> \
static WPointer with_return(WPointer out, RPointer in) \
	{ return out; }

/************************************************************************************************************************/

#define initial_no_return_2(op) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static void no_return(WPointer out, RIterator1 in1, RIterator2 in2) \
	{ }

#define initial_with_return_2(op) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static WPointer with_return(WPointer out, RIterator1 in1, RIterator2 in2) \
	{ return out; }

#define initial_no_return_brackets_2(op) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static void no_return(WPointer out, RIterator1 in1, RIterator2 in2) \
	{ }

#define initial_with_return_brackets_2(op) \
template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2> \
static WPointer with_return(WPointer out, RIterator1 in1, RIterator2 in2) \
	{ return out; }

#endif
