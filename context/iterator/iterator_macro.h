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

#ifndef CONTEXT_ITERATOR_MACRO_H
#define CONTEXT_ITERATOR_MACRO_H

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.
*/

#define overload1(method, op) \
template<typename OutputIterator, typename InputIterator> \
static OutputIterator method(OutputIterator out, InputIterator in, const InputIterator end) \
	{ while (in != end) *(out++)op(*(in++)); return out; }

#define overload2(method, op) \
template<typename OutputIterator, typename InputIterator1, typename InputIterator2> \
static OutputIterator method(OutputIterator out, InputIterator1 in1, InputIterator2 in2, const InputIterator2 end2) \
	{ while (in2 != end2) *(out++)=(*(in1++))op(*(in2++)); return out; }

#endif
