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

#ifndef CONTEXT_BLOCK_H
#define CONTEXT_BLOCK_H

#include<stddef.h>
#include<stdio.h>

/*
	As block types are intended to hold int types, it's more efficient to pass the given value_type instead of
	a const reference to one.
*/

namespace nik
{
	namespace context
	{
/*
			block:
				The minimal specification (axiomatic properties) of a block class are:
				typedefs:
				constructors:
				accessors:
*/
		template<typename T, size_t N>
		struct block
		{
/*
	Assumes ascending order.
	
	Incrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			static bool equal(const T *in1, const T *in2)
				{ return (*in1 == *in2) && block<T, N-1>::equal(++in1, ++in2); }
/*
	Assumes ascending order.
	
	Incrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			static bool not_equal(const T *in1, const T *in2)
				{ return (*in1 != *in2) || block<T, N-1>::not_equal(++in1, ++in2); }
/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			static bool less_than(const T *in1, const T *in2)
			{
				if (*in1 != *in2) return (*in1 < *in2);
				else return block<T, N-1>::less_than(--in1, --in2);
			}
/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			static bool less_than_or_equal(const T *in1, const T *in2)
			{
				if (*in1 != *in2) return (*in1 < *in2);
				else return block<T, N-1>::less_than_or_equal(--in1, --in2);
			}
/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			static bool greater_than(const T *in1, const T *in2)
			{
				if (*in1 != *in2) return (*in1 > *in2);
				else return block<T, N-1>::greater_than(--in1, --in2);
			}
/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			static bool greater_than_or_equal(const T *in1, const T *in2)
			{
				if (*in1 != *in2) return (*in1 > *in2);
				else return block<T, N-1>::greater_than_or_equal(--in1, --in2);
			}
/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			static void _print_verbatim(const char *format, const T *in)
			{
				printf(format, *in);
				block<T, N-1>::_print_verbatim(format, --in);
			}

			template<typename Block>
			static void print_verbatim(const char *format, const Block & b) { _print_verbatim(format, b.array); }
/*
	Assumes ascending order.
	
	Incrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			static void copy(T *out, const T *in)
			{
				*out=*in;
				block<T, N-1>::copy(++out, ++in);
			}
		};

		template<typename T>
		struct block<T, 1>
		{
			static bool equal(const T *in1, const T *in2) { return (*in1 == *in2); }
			static bool not_equal(const T *in1, const T *in2) { return (*in1 != *in2); }

			static bool less_than(const T *in1, const T *in2) { return (*in1 < *in2); }
			static bool less_than_or_equal(const T *in1, const T *in2) { return (*in1 <= *in2); }
			static bool greater_than(const T *in1, const T *in2) { return (*in1 > *in2); }
			static bool greater_than_or_equal(const T *in1, const T *in2) { return (*in1 >= *in2); }

			static void _print_verbatim(const char *format, const T *in) { printf(format, *in); }

			static void copy(T *out, const T *in) { *out=*in; }
		};
	}
}

#endif
