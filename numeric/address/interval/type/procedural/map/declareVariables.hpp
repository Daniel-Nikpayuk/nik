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
	size_type outDirection = traits::out_direction,
	size_type outMemory = traits::out_memory,
	size_type outPointer = traits::out_pointer

> struct declareVariables { };


/***********************************************************************************************************************/


template<typename traits, size_type outDirection, size_type outPointer>
struct declareVariables<traits, outDirection, ArgPointer::mutate, outPointer>
{
	typedef typename traits::out_type out_type;

	declareVariables(out_type & origin, out_type & out)
	{
		out = origin;
	}
};


/***********************************************************************************************************************/


template<typename traits>
struct declareVariables<traits, ArgPointer::forward, ArgPointer::allocate, ArgPointer::segment>
{
	typedef typename traits::value_type value_type;
	typedef typename traits::out_type out_type;

	declareVariables(out_type & origin, size_type length, size_type offset, out_type & out)
	{
		origin = new value_type[length];
		out = origin + offset;
	}
};


