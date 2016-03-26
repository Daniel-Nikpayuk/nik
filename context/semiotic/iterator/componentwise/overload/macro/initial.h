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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_OVERLOAD_INITIAL_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_OVERLOAD_INITIAL_H

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.
*/

#define initial_no_return_0(dir, op) \
template<typename WIterator, typename ValueType> \
static void no_return(WIterator out, ValueType in) \
	{ }

#define initial_with_return_0(dir, op) \
template<typename WIterator, typename ValueType> \
static WIterator with_return(WIterator out, ValueType in) \
	{ return out; }

#define initial_no_return_left_0(dir, op) \
template<typename WIterator> \
static void no_return(WIterator out) \
	{ }

#define initial_no_return_right_0(dir, op) \
template<typename WIterator> \
static void no_return(WIterator out) \
	{ }

/************************************************************************************************************************/

#define initial_no_return_1(dir, op) \
template<typename WIterator, typename RIterator> \
static void no_return(WIterator out, RIterator in) \
	{ }

#define initial_with_return_1(dir, op) \
template<typename WIterator, typename RIterator> \
static WIterator with_return(WIterator out, RIterator in) \
	{ return out; }

#define initial_no_return_right_1(dir, op, r) \
template<typename WIterator, typename RIterator> \
static void no_return(WIterator out, RIterator in) \
	{ }

#define initial_with_return_right_1(dir, op, r) \
template<typename WIterator, typename RIterator> \
static WIterator with_return(WIterator out, RIterator in) \
	{ return out; }

/************************************************************************************************************************/

#define initial_no_return_2(dir, op) \
template<typename WIterator, typename RIterator1, typename RIterator2> \
static void no_return(WIterator out, RIterator1 in1, RIterator2 in2) \
	{ }

#define initial_with_return_2(dir, op) \
template<typename WIterator, typename RIterator1, typename RIterator2> \
static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2) \
	{ return out; }

#define initial_no_return_bracket_2(dir, op) \
template<typename WIterator, typename RIterator1, typename RIterator2> \
static void no_return(WIterator out, RIterator1 in1, RIterator2 in2) \
	{ }

#define initial_with_return_bracket_2(dir, op) \
template<typename WIterator, typename RIterator1, typename RIterator2> \
static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2) \
	{ return out; }

#endif
