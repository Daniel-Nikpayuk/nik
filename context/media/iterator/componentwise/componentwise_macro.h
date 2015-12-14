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

#ifndef CONTEXT_ITERATOR_COMPONENTWISE_MACRO_H
#define CONTEXT_ITERATOR_COMPONENTWISE_MACRO_H

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.
*/

/*
	There's no need for a "return" version of const_overload as the out iterator equals the end iterator upon halting.
*/
#define no_return_0(dir, op) \
template<typename OutputIterator, typename TerminalIterator, typename ValueType> \
static void no_return(OutputIterator out, TerminalIterator end, ValueType value) \
{ \
	while (out != end) \
	{ \
		(*out)op(value); \
		dir(out); \
	} \
}

/*
	There's no need for a "return" version of const_overload as the out iterator equals the end iterator upon halting.
*/
#define with_return_0(dir, op) \
template<typename OutputIterator, typename TerminalIterator, typename ValueType> \
static OutputIterator with_return(OutputIterator out, TerminalIterator end, ValueType value) \
{ \
	while (out != end) \
	{ \
		(*out)op(value); \
		dir(out); \
	} \
 \
	return out; \
}

/*
	There's no need for a "return" version of constant_overload as the out iterator equals the end iterator upon halting.
*/
#define no_return_left_0(dir, op) \
template<typename OutputIterator, typename TerminalIterator> \
static void no_return(OutputIterator out, TerminalIterator end) \
{ \
	while (out != end) \
	{ \
		op(*out); \
		dir(out); \
	} \
}

/*
	There's no need for a "return" version of constant_overload as the out iterator equals the end iterator upon halting.
*/
#define no_return_right_0(dir, op) \
template<typename OutputIterator, typename TerminalIterator> \
static void no_return(OutputIterator out, TerminalIterator end) \
{ \
	while (out != end) \
	{ \
		(*out)op; \
		dir(out); \
	} \
}

/************************************************************************************************************************/

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with OutputIterator as reference (assuming referencing is preferred).
*/
#define no_return_1(dir, op) \
template<typename OutputIterator, typename InputIterator, typename TerminalIterator> \
static void no_return(OutputIterator out, InputIterator in, TerminalIterator end) \
{ \
	while (in != end) \
	{ \
		(*out)op(*in); \
		dir(out); dir(in); \
	} \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but you still prefer a return value, call this macro.
*/
#define with_return_1(dir, op) \
template<typename OutputIterator, typename InputIterator, typename TerminalIterator> \
static OutputIterator with_return(OutputIterator out, InputIterator in, TerminalIterator end) \
{ \
	while (in != end) \
	{ \
		(*out)op(*in); \
		dir(out); dir(in); \
	} \
 \
	return out; \
}

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with OutputIterator as reference (assuming referencing is preferred).
*/
#define no_return_right_1(dir, op, r) \
template<typename OutputIterator, typename InputIterator, typename TerminalIterator> \
static void no_return(OutputIterator out, InputIterator in, TerminalIterator end) \
{ \
	while (in != end) \
	{ \
		(*out)op(*in)r; \
		dir(out); dir(in); \
	} \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but you still prefer a return value, call this macro.
*/
#define with_return_right_1(dir, op, r) \
template<typename OutputIterator, typename InputIterator, typename TerminalIterator> \
static OutputIterator with_return(OutputIterator out, InputIterator in, TerminalIterator end) \
{ \
	while (in != end) \
	{ \
		*(out)op(*in)r; \
		dir(out); dir(in); \
	} \
 \
	return out; \
}

/************************************************************************************************************************/

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with OutputIterator as reference (assuming referencing is preferred).
*/
#define no_return_2(dir, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator> \
static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, TerminalIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		(*out)=(*in1)op(*in2); \
		dir(out); dir(in1); dir(in2); \
	} \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but you still prefer a return value, call this macro.
*/
#define with_return_2(dir, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator> \
static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, TerminalIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		(*out)=(*in1)op(*in2); \
		dir(out); dir(in1); dir(in2); \
	} \
 \
	return out; \
}

/*
	1. If you don't have any interest in the final out value (as it has been incremented) call this macro.
	2. If you have interest in the final out value, but have no interest in a return,
		call this macro with OutputIterator as reference (assuming referencing is preferred).
*/
#define no_return_bracket_2(dir, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator> \
static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, TerminalIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		(*out)=(*in1)op[*in2]; \
		dir(out); dir(in1); dir(in2); \
	} \
}

/*
	1. If you have an interest in the final out value, but you don't want to reference, call this macro.
	2. If you have an interest in the final out value, and you do want to reference,
		but you still prefer a return value, call this macro.
*/
#define with_return_bracket_2(dir, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator> \
static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, TerminalIterator end2) \
{ \
	while (in2 != end2) \
	{ \
		(*out)=(*in1)op[*in2]; \
		dir(out); dir(in1); dir(in2); \
	} \
 \
	return out; \
}

#endif
