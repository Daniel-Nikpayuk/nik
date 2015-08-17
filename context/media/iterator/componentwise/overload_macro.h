/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef CONTEXT_ITERATOR_OVERLOAD_MACRO_H
#define CONTEXT_ITERATOR_OVERLOAD_MACRO_H

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	As far as I know, the C++ standard on templates allows for template functions that differ only in return types.
	I don't yet know how that will work out in practice. It might need to be changed if found too inconvenient.
*/

/*
	There's no need for a "return" version of constant_overload as the out iterator equals the end iterator upon halting.
*/
#define left_overload0(dir, method, op) \
template<typename OutputIterator, typename TerminalIterator> \
static void method(OutputIterator out, TerminalIterator end) \
	{ while (out != end) op(*(out dir)); }

/*
	There's no need for a "return" version of constant_overload as the out iterator equals the end iterator upon halting.
*/
#define right_overload0(dir, method, op) \
template<typename OutputIterator, typename TerminalIterator> \
static void method(OutputIterator out, TerminalIterator end) \
	{ while (out != end) (*(out dir))op; }

/************************************************************************************************************************/

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with OutputIterator as reference (assuming referencing is preferred).
*/
#define void_overload1(dir, method, op) \
template<typename OutputIterator, typename InputIterator, typename TerminalIterator> \
static void method(OutputIterator out, InputIterator in, TerminalIterator end) \
	{ while (in != end) *(out dir)op(*(in dir)); }

/*
	There's no need for a "return" version of const_overload as the out iterator equals the end iterator upon halting.
*/
#define const_overload1(dir, method, op) \
template<typename OutputIterator, typename TerminalIterator, typename ValueType> \
static void method(OutputIterator out, TerminalIterator end, ValueType value) \
	{ while (out != end) *(out dir)op value; }

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but you still prefer a return value, call this macro.
*/
#define return_overload1(dir, method, op) \
template<typename OutputIterator, typename InputIterator, typename TerminalIterator> \
static OutputIterator method(OutputIterator out, InputIterator in, TerminalIterator end) \
	{ while (in != end) *(out dir)op(*(in dir)); return out; }

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with OutputIterator as reference (assuming referencing is preferred).
*/
#define right_void_overload1(dir, method, op, r) \
template<typename OutputIterator, typename InputIterator, typename TerminalIterator> \
static void method(OutputIterator out, InputIterator in, TerminalIterator end) \
	{ while (in != end) *(out dir)op(*(in dir))r; }

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but you still prefer a return value, call this macro.
*/
#define right_return_overload1(dir, method, op, r) \
template<typename OutputIterator, typename InputIterator, typename TerminalIterator> \
static OutputIterator method(OutputIterator out, InputIterator in, TerminalIterator end) \
	{ while (in != end) *(out dir)op(*(in dir))r; return out; }

/************************************************************************************************************************/

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with OutputIterator as reference (assuming referencing is preferred).
*/
#define void_overload2(dir, method, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator> \
static void method(OutputIterator out, InputIterator1 in1, InputIterator2 in2, TerminalIterator end2) \
	{ while (in2 != end2) *(out dir)=(*(in1 dir))op(*(in2 dir)); }

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but you still prefer a return value, call this macro.
*/
#define return_overload2(dir, method, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator> \
static OutputIterator method(OutputIterator out, InputIterator1 in1, InputIterator2 in2, TerminalIterator end2) \
	{ while (in2 != end2) *(out dir)=(*(in1 dir))op(*(in2 dir)); return out; }

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with OutputIterator as reference (assuming referencing is preferred).
*/
#define bracket_void_overload2(dir, method, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator> \
static void method(OutputIterator out, InputIterator1 in1, InputIterator2 in2, TerminalIterator end2) \
	{ while (in2 != end2) *(out dir)=(*(in1 dir))op[*(in2 dir)]; }

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but you still prefer a return value, call this macro.
*/
#define bracket_return_overload2(dir, method, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator> \
static OutputIterator method(OutputIterator out, InputIterator1 in1, InputIterator2 in2, TerminalIterator end2) \
	{ while (in2 != end2) *(out dir)=(*(in1 dir))op[*(in2 dir)]; return out; }

#endif
