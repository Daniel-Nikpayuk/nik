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

template<Association... params>
using list_cast = typename bit::template list_cast<params...>;

template<size_type mask>
using pattern = typename bit::template pattern<mask>;

template<size_type mask, typename... params>
using match = typename pattern<mask>::template match<params...>;

template<size_type mask, typename S>
using tail = typename pattern<mask>::template tail<S::bitmask>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


struct Segment // mutate, immuate
{
	static constexpr size_type bitmask = list_cast
	<
		Association::segment

	>::rtn;
};

struct MutateSegment
{
	static constexpr size_type bitmask = list_cast
	<
		Association::mutate,
		Association::segment

	>::rtn;
};

struct AllocateSegment
{
	static constexpr size_type bitmask = list_cast
	<
		Association::allocate,
		Association::segment

	>::rtn;
};

struct DeallocateSegment
{
	static constexpr size_type bitmask = list_cast
	<
		Association::deallocate,
		Association::segment

	>::rtn;
};

// alias from "enumerator" module ?

struct Closing
{
	static constexpr size_type bitmask = list_cast
	<
		Association::closing

	>::rtn;
};

struct Closed
{
	static constexpr size_type bitmask = list_cast
	<
		Association::closed

	>::rtn;
};

struct Opening
{
	static constexpr size_type bitmask = list_cast
	<
		Association::opening

	>::rtn;
};

struct Open
{
	static constexpr size_type bitmask = list_cast
	<
		Association::open

	>::rtn;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename... params> struct Adjective;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


struct Adjective_Forward
{
	static constexpr size_type bitmask = list_cast
	<
		Association::forward

	>::rtn;
};

struct Adjective_Backward { };

struct Adjective_Deallocate { };

struct Adjective_Segment { };


struct Adjective_ForwardAllocateHook
{
	static constexpr size_type bitmask = list_cast
	<
		Association::forward,
		Association::allocate,
		Association::hook

	>::rtn;
};

struct Adjective_ForwardAllocateLink
{
	static constexpr size_type bitmask = list_cast
	<
		Association::forward,
		Association::allocate,
		Association::link

	>::rtn;
};

struct Adjective_ForwardDeallocateHook
{
	static constexpr size_type bitmask = list_cast
	<
		Association::forward,
		Association::deallocate,
		Association::hook

	>::rtn;
};

struct Adjective_ForwardDeallocateLink
{
	static constexpr size_type bitmask = list_cast
	<
		Association::forward,
		Association::deallocate,
		Association::link

	>::rtn;
};



struct Adjective_BackwardAllocateHook
{
	static constexpr size_type bitmask = list_cast
	<
		Association::backward,
		Association::allocate,
		Association::hook

	>::rtn;
};

struct Adjective_BackwardAllocateLink
{
	static constexpr size_type bitmask = list_cast
	<
		Association::backward,
		Association::allocate,
		Association::link

	>::rtn;
};

struct Adjective_BackwardDeallocateHook
{
	static constexpr size_type bitmask = list_cast
	<
		Association::backward,
		Association::deallocate,
		Association::hook

	>::rtn;
};

struct Adjective_BackwardDeallocateLink
{
	static constexpr size_type bitmask = list_cast
	<
		Association::backward,
		Association::deallocate,
		Association::link

	>::rtn;
};

template<size_type mask>
struct Adjective_Coarse :

		public match
		<
			mask,

			Adjective_ForwardAllocateHook,
			Adjective_ForwardAllocateLink,

			Adjective_ForwardDeallocateHook,
			Adjective_ForwardDeallocateLink,

			Adjective_Forward,

			Adjective_BackwardAllocateHook,
			Adjective_BackwardAllocateLink,

			Adjective_BackwardDeallocateHook,
			Adjective_BackwardDeallocateLink,

			Adjective_Backward

		>::rtn

	{ };

/************************************************************************************************************************
							1
************************************************************************************************************************/


template<size_type mask>
struct Adjective<mask, Segment> : // mutate, immuate

		public Adjective_Segment
{
	static constexpr size_type bitmask = Segment::bitmask;

	static constexpr size_type allocate_mask = mask | AllocateSegment::bitmask;
	static constexpr size_type deallocate_mask = mask | DeallocateSegment::bitmask;

	using Interval = typename match<mask, Closing, Closed, Opening, Open>::rtn;

	static Adjective<allocate_mask, Interval> cast(size_type l, size_type o = 0)
	{
		return Adjective<allocate_mask, Interval>(l, o);
	}

	template<typename T>
	static Adjective<deallocate_mask, Interval, T> cast(T *o)
	{
		return Adjective<deallocate_mask, Interval, T>(o);
	}
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


template<size_type mask, typename T>
struct Adjective<mask, DeallocateSegment, T> :

		public Adjective_Segment
{
	static constexpr size_type bitmask = DeallocateSegment::bitmask;

	T *origin;

	Adjective(T *o) : origin(o) { }
};


template<size_type mask>
struct Adjective<mask, AllocateSegment> :

		public Adjective_Segment
{
	static constexpr size_type bitmask = AllocateSegment::bitmask;

	size_type length;
	size_type offset;

	Adjective(size_type l, size_type o) : length(l), offset(o) { }
};


/************************************************************************************************************************
							3
************************************************************************************************************************/


/************************************************************************************************************************
							4
************************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename S>
using Adjective_Tail = Adjective< tail<mask, S>::rtn, S>;

template<size_type mask, typename S, typename T>
using Adjective_Tail_T = Adjective< tail<mask, S>::rtn, S, T>;

template<size_type mask, typename T>
using match_deallocate = typename match
<
	mask,

	Adjective_Tail_T<mask, DeallocateSegment, T>

>::rtn;

template<size_type mask>
using match_iterator = typename match
<
	mask,

	Adjective_Tail<mask, AllocateSegment>,
	Adjective_Tail<mask, Segment>,

	Adjective_Coarse<mask>

>::rtn;

// partition implies no need for a default value.

template<size_type mask>
using match_interval = typename match
<
	mask,

	Adjective<mask, Closing>,
	Adjective<mask, Closed>,
	Adjective<mask, Opening>,
	Adjective<mask, Open>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename Interval>
struct Adjective<mask, Interval> : public match_iterator<mask>
{
	static constexpr size_type bitmask = Interval::bitmask;

	Adjective() : match_iterator<mask>() { }
	Adjective(size_type l, size_type o) : match_iterator<mask>(l, o) { }
};

template<size_type mask, typename Interval, typename T>
struct Adjective<mask, Interval, T> : public match_deallocate<mask, T>
{
	static constexpr size_type bitmask = Interval::bitmask;

	Adjective(T *o) : match_deallocate<mask, T>(o) { }
};


/***********************************************************************************************************************/


template<size_type mask>
struct Adjective<mask> : public match_interval<mask> { };


