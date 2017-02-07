/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	adjective Associations:

				Strongly typed for improved type checking.

				Parameter pack being "typename..." requires adj_lists
				as enums themselves don't count as typenames.
*/


enum struct Association : size_type
{
	forward,
	backward,

	closing,
	closed,
	opening,
	open,

	mutate,
	allocate,

	immutate,
	deallocate,

	segment,
	hook,
	link,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	adjective Attributes:
				TUPLE/LIST data structures are appropriate here because resolution
				occurs during compile-time and the size is expected to be small.

*/


enum struct Attribute : size_type
{
	direction,
	interval,
	image,
	iterator,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... params>
struct adjective;


template<typename L>
struct adjective<L> { using type = L; };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


using AllocateSegment = adj_list<Association::allocate, Association::segment>;


using DeallocateSegment = adj_list<Association::deallocate, Association::segment>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							1
************************************************************************************************************************/


/************************************************************************************************************************
							2
************************************************************************************************************************/


template<typename T>
struct adjective<AllocateSegment, T>
{
	using type = AllocateSegment;

	T length;
	T offset;

	adjective(T l, T o) : length(l), offset(o) { }
};


template<typename T>
struct adjective<DeallocateSegment, T>
{
	using type = DeallocateSegment;

	T *origin;

	adjective(T *o) : origin(o) { }
};


/************************************************************************************************************************
							3
************************************************************************************************************************/


/************************************************************************************************************************
							4
************************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


