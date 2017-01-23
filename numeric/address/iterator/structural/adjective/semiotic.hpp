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
	Adjective Associations:

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
	Adjective Attributes:
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


using bit = typename bitmask::template bit<Association>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type bitmask, typename T> struct Adjective;
// { static_assert(true, "this variant is not implemented."); }; // should be false.


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<typename T> struct Adjective<0, T> { static constexpr size_type bitmask = 0; };


/***********************************************************************************************************************/


static constexpr size_type Segment		= bit::template list_cast<Association::segment>::rtn;
static constexpr size_type AllocateSegment	= bit::template list_cast<Association::allocate, Association::segment>::rtn;
static constexpr size_type DeallocateSegment	= bit::template list_cast<Association::deallocate, Association::segment>::rtn;

template<typename Filler>
struct Adjective<Segment, Filler>
{
	static constexpr size_type bitmask = Segment;

	static Adjective<AllocateSegment, Filler> with(size_type l, size_type o = 0)
	{
		return Adjective<AllocateSegment, Filler>(l, o);
	}

	template<typename T>
	static Adjective<DeallocateSegment, T> with(T *o)
	{
		return Adjective<DeallocateSegment, T>(o);
	}
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


template<typename T>
struct Adjective<DeallocateSegment, T>
{
	static constexpr size_type bitmask = DeallocateSegment;

	T *origin;

	Adjective(T *o) : origin(o) { }
};


template<typename Filler>
struct Adjective<AllocateSegment, Filler>
{
	static constexpr size_type bitmask = AllocateSegment;

	size_type length;
	size_type offset;

	Adjective(size_type l, size_type o) : length(l), offset(o) { }
};


/************************************************************************************************************************
							3
************************************************************************************************************************/


static constexpr size_type ForwardAllocateHook	= bit::template list_cast
<
	Association::forward,
	Association::allocate,
	Association::hook

>::rtn;

template<typename T> struct Adjective<ForwardAllocateHook, T> { static constexpr size_type bitmask = ForwardAllocateHook; };


/************************************************************************************************************************
							4
************************************************************************************************************************/


template<size_type bitmask, typename... params>
using dispatch = typename bit::template pattern<bitmask>::template dispatch<params...>;

template<size_type bitmask, typename T = void>
struct Adjective : public dispatch
<
	bitmask,

	Adjective<AllocateSegment, T>,
	Adjective<DeallocateSegment, T>,

	Adjective<ForwardAllocateHook, T>,

	Adjective<0, T>

>::rtn { };


