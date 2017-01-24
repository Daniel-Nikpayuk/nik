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


template<size_type mask, typename... params> struct Adjective;


/************************************************************************************************************************
							1
************************************************************************************************************************/


struct Adjective_Null { };


/***********************************************************************************************************************/


struct Segment
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Association::segment

	>::rtn;
};

struct AllocateSegment { };
struct DeallocateSegment { };

template<size_type mask>
struct Adjective<mask, Segment>
{
	static constexpr size_type bitmask = Segment::bitmask;

	static Adjective<mask, AllocateSegment> with(size_type l, size_type o = 0)
	{
		return Adjective<mask, AllocateSegment>(l, o);
	}

	template<typename T>
	static Adjective<mask, DeallocateSegment, T> with(T *o)
	{
		return Adjective<mask, DeallocateSegment, T>(o);
	}
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


template<size_type mask, typename T>
struct Adjective<mask, DeallocateSegment, T>
{
	T *origin;

	Adjective(T *o) : origin(o) { }
};


template<size_type mask>
struct Adjective<mask, AllocateSegment>
{
	size_type length;
	size_type offset;

	Adjective(size_type l, size_type o) : length(l), offset(o) { }
};


/************************************************************************************************************************
							3
************************************************************************************************************************/


struct Adjective_ForwardAllocateHook
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Association::forward,
		Association::allocate,
		Association::hook

	>::rtn;
};


/************************************************************************************************************************
							4
************************************************************************************************************************/


template<size_type mask>
using pattern = typename bit::template pattern<mask>;

template<size_type mask, typename... params>
using match = typename pattern<mask>::template match<params...>;

struct Closing
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Association::closing

	>::rtn;
};

struct Closed
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Association::closed

	>::rtn;
};

struct Opening
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Association::opening

	>::rtn;
};

struct Open
{
	static constexpr size_type bitmask = bit::template list_cast
	<
		Association::open

	>::rtn;
};

template<size_type mask, typename Interval>
struct Adjective<mask, Interval> : public match
<
	mask,

	Adjective
	<
		pattern<mask>::template tail<Segment::bitmask>::rtn,
		Segment
	>,

	Adjective_ForwardAllocateHook,

	Adjective_Null

>::rtn { };


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
struct Adjective<mask> : public match
<
	mask,

	Adjective
	<
		pattern<mask>::template tail<Closing::bitmask>::rtn,
		Closing
	>,

	Adjective
	<
		pattern<mask>::template tail<Closed::bitmask>::rtn,
		Closed
	>,

	Adjective
	<
		pattern<mask>::template tail<Opening::bitmask>::rtn,
		Opening
	>,

	Adjective
	<
		pattern<mask>::template tail<Open::bitmask>::rtn,
		Open
	>,

	Adjective_Null

>::rtn { };


