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


template
<
	typename traits,
	size_type outMemory = traits::out_memory,
	size_type outPointer = traits::out_pointer

> struct subjectArgs { };


/***********************************************************************************************************************/


template<typename traits, size_type outPointer>
struct subjectArgs<traits, ArgPointer::mutate, outPointer>
{
	typedef typename traits::out_type out_type;

	out_type origin;
	out_type out;

	subjectArgs(out_type o) : origin(o), out(o) { }

	subjectArgs(const subjectArgs & args) : origin(args.origin), out(args.out) { }
};


/***********************************************************************************************************************/


template<typename traits>
struct subjectArgs<traits, ArgPointer::allocate, ArgPointer::segment>
{
	typedef typename traits::value_type value_type;
	typedef typename traits::out_type out_type;

	out_type origin;
	out_type out;

	subjectArgs(size_type length, size_type offset)
	{
		origin = new value_type[length];
		out = origin + offset;
	}

	subjectArgs(const subjectArgs & args) : origin(args.origin), out(args.out) { }
};


