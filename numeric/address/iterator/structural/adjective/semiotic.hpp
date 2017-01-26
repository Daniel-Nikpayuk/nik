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


using bitmask = typename bit::template bitmask<Association>;

template<Association... params>
using list_cast = typename bitmask::template list_cast<params...>;

template<size_type mask>
using pattern = typename bitmask::template pattern<mask>;

template<size_type mask, size_type... params>
using match = typename pattern<mask>::template match<params...>;

template<size_type mask, typename... params>
using dispatch = typename pattern<mask>::template dispatch<params...>;

template<size_type base, size_type mask>
using apply = typename pattern<base>::template apply<mask>;

template<size_type mask, size_type base>
using deduct = typename pattern<mask>::template deduct<base>;


/************************************************************************************************************************
							direction
************************************************************************************************************************/


static constexpr size_type		Forward

= list_cast
<
	Association::forward

>::rtn;

static constexpr size_type		ForwardAllocateHook

= list_cast
<
	Association::forward,
	Association::allocate,
	Association::hook

>::rtn;

static constexpr size_type		ForwardAllocateLink

= list_cast
<
	Association::forward,
	Association::allocate,
	Association::link

>::rtn;

static constexpr size_type		ForwardDeallocateHook

= list_cast
<
	Association::forward,
	Association::deallocate,
	Association::hook

>::rtn;

static constexpr size_type		ForwardDeallocateLink

= list_cast
<
	Association::forward,
	Association::deallocate,
	Association::link

>::rtn;

static constexpr size_type		Backward

= list_cast
<
	Association::backward

>::rtn;

static constexpr size_type		BackwardAllocateHook

= list_cast
<
	Association::backward,
	Association::allocate,
	Association::hook

>::rtn;

static constexpr size_type		BackwardAllocateLink

= list_cast
<
	Association::backward,
	Association::allocate,
	Association::link

>::rtn;

static constexpr size_type		BackwardDeallocateHook

= list_cast
<
	Association::backward,
	Association::deallocate,
	Association::hook

>::rtn;

static constexpr size_type		BackwardDeallocateLink

= list_cast
<
	Association::backward,
	Association::deallocate,
	Association::link

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Direction

= list_cast
<
	Association::forward,
	Association::backward

>::rtn;


/************************************************************************************************************************
							interval
************************************************************************************************************************/


// alias from "enumerator" module ?


static constexpr size_type		Closing

= list_cast
<
	Association::closing

>::rtn;

static constexpr size_type		Closed

= list_cast
<
	Association::closed

>::rtn;

static constexpr size_type		Opening

= list_cast
<
	Association::opening

>::rtn;

static constexpr size_type		Open

= list_cast
<
	Association::open

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Interval

= list_cast
<
	Association::closing,
	Association::closed,
	Association::opening,
	Association::open

>::rtn;


/************************************************************************************************************************
							image
************************************************************************************************************************/


static constexpr size_type		Image

= list_cast
<
	Association::mutate,
	Association::allocate,
	Association::immutate,
	Association::deallocate

>::rtn;


/************************************************************************************************************************
							iterator
************************************************************************************************************************/


static constexpr size_type		Segment // mutate, immutate

= list_cast
<
	Association::segment

>::rtn;

static constexpr size_type		AllocateSegment

= list_cast
<
	Association::allocate,
	Association::segment

>::rtn;

static constexpr size_type		DeallocateSegment

= list_cast
<
	Association::deallocate,
	Association::segment

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Iterator

= list_cast
<
	Association::segment,
	Association::hook,
	Association::link

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename... params>
struct adjective;


template<size_type mask>
struct adjective<mask> { static constexpr size_type bitmask = mask; };


// "using" for polymorphic dispatching.


template<Association... params>
using Adjective = adjective<list_cast<params...>::rtn>;


template<typename T, Association... params>
using TAdjective = adjective<list_cast<params...>::rtn, T>;


template<size_type mask, typename... params>
struct modifier;


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<size_type mask>
struct adjective<mask, adjective<Segment> > : // mutate, immutate

		public adjective<Segment>
{
	static constexpr size_type bitmask = Segment;
	static constexpr size_type allocate_mask = apply< deduct<mask, Image>::rtn, AllocateSegment>::rtn;
	static constexpr size_type deallocate_mask = apply< deduct<mask, Image>::rtn, DeallocateSegment>::rtn;

	static modifier<allocate_mask> cast(size_type l, size_type o = 0)
	{
		return modifier<allocate_mask>(l, o);
	}

	template<typename T>
	static modifier<deallocate_mask, T> cast(T *o)
	{
		return modifier<deallocate_mask, T>(o);
	}
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


template<typename T>
struct adjective<DeallocateSegment, T> :

		public adjective<Segment>
{
	static constexpr size_type bitmask = DeallocateSegment;

	T *origin;

	adjective(T *o) : origin(o) { }
};


template<size_type mask>
struct adjective<mask, adjective<AllocateSegment> > :

		public adjective<Segment>
{
	static constexpr size_type bitmask = AllocateSegment;

	size_type length;
	size_type offset;

	adjective(size_type l, size_type o) : length(l), offset(o) { }
};


/************************************************************************************************************************
							3
************************************************************************************************************************/


/************************************************************************************************************************
							4
************************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


// not yet implemented.

template<size_type mask>
struct DispatchError
{
	DispatchError() { static_assert(true, "adjective dispatch: no match found."); }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using dispatch_direction = typename dispatch
<
	mask,

	adjective<ForwardAllocateHook>,
	adjective<ForwardAllocateLink>,

	adjective<ForwardDeallocateHook>,
	adjective<ForwardDeallocateLink>,

	adjective<Forward>,

	adjective<BackwardAllocateHook>,
	adjective<BackwardAllocateLink>,

	adjective<BackwardDeallocateHook>,
	adjective<BackwardDeallocateLink>,

	adjective<Backward>,

	DispatchError<mask>

>::rtn;


template<size_type mask>
using dispatch_interval = typename dispatch
<
	mask,

	adjective<Closing>,
	adjective<Closed>,
	adjective<Opening>,
	adjective<Open>,

	DispatchError<mask>

>::rtn;


template<size_type mask>
using dispatch_image = typename dispatch
<
	mask,

	adjective<Image>

>::rtn;


template<size_type mask>
using dispatch_iterator = typename dispatch
<
	mask,

	adjective<mask, adjective<AllocateSegment> >,
	adjective<mask, adjective<Segment> >,

	adjective<Iterator>

>::rtn;


template<size_type mask, typename T>
using dispatch_iterator_T = typename dispatch
<
	mask,

	adjective<DeallocateSegment, T>,

	adjective<Iterator>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


// partition implies no need for a default value.

template<size_type mask>
struct modifier<mask> :

		public dispatch_direction<mask>,
		public dispatch_interval<mask>,
		public dispatch_image<Image>,
		public dispatch_iterator<mask>

{
	modifier() : dispatch_iterator<mask>() { }
	modifier(size_type l, size_type o) : dispatch_iterator<mask>(l, o) { }
};

template<size_type mask, typename T>
struct modifier<mask, T> :

		public dispatch_direction<mask>,
		public dispatch_interval<mask>,
		public dispatch_image<Image>,
		public dispatch_iterator_T<mask, T>

{
	modifier(T *o) : dispatch_iterator_T<mask, T>(o) { }
};


