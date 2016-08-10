/************************************************************************************************************************
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
************************************************************************************************************************/

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

/*
	out_memory != deallocate,
	in_memory != allocate
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type out_interval, size_type in_interval, typename Filler = void>
struct _loop { };


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


/*
template<typename Filler>
struct _loop<ArgPointer::closing, ArgPointer::closing, Filler>
{
	static typename out_type::pointer map(typename out_type::pointer out, size_type m, size_type n)
	{
		while (m != n)
		{
			*out = m;

			out=+out=new out_type;
			++m;
		}

		return out;
	}
};
*/


template<typename Filler>
struct _loop<ArgPointer::closing, ArgPointer::closing, Filler>
{
	using unary_arguments = _unary_arguments<out_memory, out_pointer, in_memory, in_pointer, count_policy>;

	static unary_arguments map(typename out_type::pointer out, size_type m, size_type n)
	{
		unary_arguments args(out);

		while (m != n)
		{
			*args.out = m;

			args.out=+args.out=new out_type;
			++m;
		}

		return args;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


using loop = _loop<out_interval, in_interval>;


