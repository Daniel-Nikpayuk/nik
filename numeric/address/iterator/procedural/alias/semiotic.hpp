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

// not yet implemented.

template<typename L>
struct DispatchError
{
	DispatchError() { static_assert(true, "adjective dispatch: no match found."); }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... params>
using tuple = typename variadic::template tuple<params...>;

template<typename enum_type>
using parameter = typename enumerative::template parameter<enum_type>;


/***********************************************************************************************************************/


enum struct Connotation : size_type;

template<Connotation... params>
using tone = typename parameter<Connotation>::template modifier<params...>;

using null_tone = tone<>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							adverb
************************************************************************************************************************/


/************************************************************************************************************************
							functor
************************************************************************************************************************/


using					OmitFunctor

= tone
<
	Connotation::omit_functor
>;

using					ApplyFunctor

= tone
<
	Connotation::apply_functor
>;

using					OmitOmit

= tone
<
	Connotation::omit_functor,
	Connotation::omit_count
>;

using					OmitApply

= tone
<
	Connotation::omit_functor,
	Connotation::apply_count
>;

using					ApplyOmit

= tone
<
	Connotation::apply_functor,
	Connotation::omit_count
>;

using					ApplyApply

= tone
<
	Connotation::apply_functor,
	Connotation::apply_count
>;

/***********************************************************************************************************************/

using					Functor

= tone
<
	Connotation::omit_functor,
	Connotation::apply_functor
>;


/************************************************************************************************************************
							tracer
************************************************************************************************************************/


using					OmitCount

= tone
<
	Connotation::omit_count
>;

using					ApplyCount

= tone
<
	Connotation::apply_count
>;

/***********************************************************************************************************************/

using					Tracer

= tone
<
	Connotation::omit_count,
	Connotation::apply_count
>;


/************************************************************************************************************************
							fixer
************************************************************************************************************************/


using					Fixer

= tone
<
	Connotation::after,
	Connotation::before,
	Connotation::between
>;


/************************************************************************************************************************
							optimizer
************************************************************************************************************************/


using					Prototype

= tone
<
	Connotation::prototype
>;

using					Specialize

= tone
<
	Connotation::specialize
>;

/***********************************************************************************************************************/

using					Optimizer

= tone
<
	Connotation::prototype,
	Connotation::specialize
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename mask>
using functor_cast = typename mask::template cast<Functor, ApplyFunctor>::type;

template<typename mask>
using tracer_cast = typename mask::template cast<Tracer, ApplyCount>::type;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


using Association = typename structural::Association;

template<Association... params>
using echo = typename structural::template echo<params...>;

using null_echo = typename structural::null_echo;

template<typename... params>
using adjective = typename structural::template adjective<params...>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							adjective
************************************************************************************************************************/


/************************************************************************************************************************
							direction
************************************************************************************************************************/


using					Forward

= echo
<
	Association::forward
>;

using					ForwardAllocateHook

= echo
<
	Association::forward,
	Association::allocate,
	Association::hook
>;

using					ForwardAllocateLink

= echo
<
	Association::forward,
	Association::allocate,
	Association::link
>;

using					ForwardDeallocateHook

= echo
<
	Association::forward,
	Association::deallocate,
	Association::hook
>;

using					ForwardDeallocateLink

= echo
<
	Association::forward,
	Association::deallocate,
	Association::link
>;

using					Backward

= echo
<
	Association::backward
>;

using					BackwardAllocateHook

= echo
<
	Association::backward,
	Association::allocate,
	Association::hook
>;

using					BackwardAllocateLink

= echo
<
	Association::backward,
	Association::allocate,
	Association::link
>;

using					BackwardDeallocateHook

= echo
<
	Association::backward,
	Association::deallocate,
	Association::hook
>;

using					BackwardDeallocateLink

= echo
<
	Association::backward,
	Association::deallocate,
	Association::link
>;

/***********************************************************************************************************************/

using					Direction

= echo
<
	Association::forward,
	Association::backward
>;


/************************************************************************************************************************
							interval
************************************************************************************************************************/


// alias from "enumerator" module ?


using					Closing

= echo
<
	Association::closing
>;

using					Closed

= echo
<
	Association::closed
>;

using					Opening

= echo
<
	Association::opening
>;

using					Open

= echo
<
	Association::open
>;

/***********************************************************************************************************************/

using					Interval

= echo
<
	Association::closing,
	Association::closed,
	Association::opening,
	Association::open
>;


/************************************************************************************************************************
							image
************************************************************************************************************************/


using					Mutate // mutate, immutate

= echo
<
	Association::mutate
>;

using					Allocate

= echo
<
	Association::allocate
>;

using					Deallocate // hook, link

= echo
<
	Association::deallocate
>;

using					AllocateSegment

= echo
<
	Association::allocate,
	Association::segment
>;

using					DeallocateSegment

= echo
<
	Association::deallocate,
	Association::segment
>;

/***********************************************************************************************************************/

using					Image

= echo
<
	Association::mutate,
	Association::allocate,
	Association::immutate,
	Association::deallocate
>;


/************************************************************************************************************************
							iterator
************************************************************************************************************************/


using					Segment // mutate, immutate

= echo
<
	Association::segment
>;

/***********************************************************************************************************************/

using					Iterator

= echo
<
	Association::segment,
	Association::hook,
	Association::link
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename mask>
using mutate_cast = typename mask::template cast<Image, Mutate>::type;

template<typename mask>
using allocate_cast = typename mask::template cast<Image, AllocateSegment>::type;

template<typename mask>
using deallocate_cast = typename mask::template cast<Image, DeallocateSegment>::type;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


using RangeAssociation = typename range::Association;

template<RangeAssociation... params>
using range_echo = typename range::template echo<params...>;

using null_range_echo = typename range::null_echo;


template<typename... params>
using range_adjective = typename range::template adjective<params...>;

/*
template<RangeAssociation... params>
using RangeAdjective = typename enumerator::template Adjective<params...>;
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							range_adjective
************************************************************************************************************************/


/************************************************************************************************************************
							increment
************************************************************************************************************************/


using					RangeSucceed

= range_echo
<
	RangeAssociation::succeed
>;

using					RangeAccede

= range_echo
<
	RangeAssociation::accede
>;

/***********************************************************************************************************************/

using					RangeIncrement

= range_echo
<
	RangeAssociation::succeed,
	RangeAssociation::accede
>;


/************************************************************************************************************************
							direction
************************************************************************************************************************/


using					RangeForward

= range_echo
<
	RangeAssociation::forward
>;

using					RangeBackward

= range_echo
<
	RangeAssociation::backward
>;


/************************************************************************************************************************
							interval
************************************************************************************************************************/


using					RangeClosing

= range_echo
<
	RangeAssociation::closing
>;

using					RangeClosed

= range_echo
<
	RangeAssociation::closed
>;

using					RangeOpening

= range_echo
<
	RangeAssociation::opening
>;

using					RangeOpen

= range_echo
<
	RangeAssociation::open
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename mask>
using accede_cast = typename mask::template cast<RangeIncrement, RangeAccede>::type;


