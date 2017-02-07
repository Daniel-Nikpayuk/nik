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
using adv_list = typename parameter<Connotation>::template list<params...>;

using null_adv = adv_list<>;


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

= adv_list
<
	Connotation::omit_functor
>;

using					OmitOmit

= adv_list
<
	Connotation::omit_functor,
	Connotation::omit_count
>;

using					OmitApply

= adv_list
<
	Connotation::omit_functor,
	Connotation::apply_count
>;

using					ApplyOmit

= adv_list
<
	Connotation::apply_functor,
	Connotation::omit_count
>;

using					ApplyApply

= adv_list
<
	Connotation::apply_functor,
	Connotation::apply_count
>;

/***********************************************************************************************************************/

using					Functor

= adv_list
<
	Connotation::omit_functor,
	Connotation::apply_functor
>;


/************************************************************************************************************************
							tracer
************************************************************************************************************************/


using					OmitCount

= adv_list
<
	Connotation::omit_count
>;


/***********************************************************************************************************************/

using					Tracer

= adv_list
<
	Connotation::omit_count,
	Connotation::apply_count
>;


/************************************************************************************************************************
							fixer
************************************************************************************************************************/


using					Fixer

= adv_list
<
	Connotation::after,
	Connotation::before,
	Connotation::between
>;


/************************************************************************************************************************
							optimizer
************************************************************************************************************************/


using					Prototype

= adv_list
<
	Connotation::prototype
>;

using					Specialize

= adv_list
<
	Connotation::specialize
>;

/***********************************************************************************************************************/

using					Optimizer

= adv_list
<
	Connotation::prototype,
	Connotation::specialize
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template<typename L>
using functor_cast = apply< deduct<L, Functor>::rtn, ApplyFunctor>;

template<typename L>
using tracer_cast = apply< deduct<L, Tracer>::rtn, ApplyCount>;
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


using Association = typename structural::Association;

template<Association... params>
using adj_list = typename structural::template adj_list<params...>;

using null_adj = typename structural::null_adj;

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

= adj_list
<
	Association::forward
>;

using					ForwardAllocateHook

= adj_list
<
	Association::forward,
	Association::allocate,
	Association::hook
>;

using					ForwardAllocateLink

= adj_list
<
	Association::forward,
	Association::allocate,
	Association::link
>;

using					ForwardDeallocateHook

= adj_list
<
	Association::forward,
	Association::deallocate,
	Association::hook
>;

using					ForwardDeallocateLink

= adj_list
<
	Association::forward,
	Association::deallocate,
	Association::link
>;

using					Backward

= adj_list
<
	Association::backward
>;

using					BackwardAllocateHook

= adj_list
<
	Association::backward,
	Association::allocate,
	Association::hook
>;

using					BackwardAllocateLink

= adj_list
<
	Association::backward,
	Association::allocate,
	Association::link
>;

using					BackwardDeallocateHook

= adj_list
<
	Association::backward,
	Association::deallocate,
	Association::hook
>;

using					BackwardDeallocateLink

= adj_list
<
	Association::backward,
	Association::deallocate,
	Association::link
>;

/***********************************************************************************************************************/

using					Direction

= adj_list
<
	Association::forward,
	Association::backward
>;


/************************************************************************************************************************
							interval
************************************************************************************************************************/


// alias from "enumerator" module ?


using					Closing

= adj_list
<
	Association::closing
>;

using					Closed

= adj_list
<
	Association::closed
>;

using					Opening

= adj_list
<
	Association::opening
>;

using					Open

= adj_list
<
	Association::open
>;

/***********************************************************************************************************************/

using					Interval

= adj_list
<
	Association::closing,
	Association::closed,
	Association::opening,
	Association::open
>;


/************************************************************************************************************************
							image
************************************************************************************************************************/


using					Allocate

= adj_list
<
	Association::allocate
>;

using					Deallocate // hook, link

= adj_list
<
	Association::deallocate
>;

/***********************************************************************************************************************/

using					Image

= adj_list
<
	Association::mutate,
	Association::allocate,
	Association::immutate,
	Association::deallocate
>;


/************************************************************************************************************************
							iterator
************************************************************************************************************************/


using					Mutate // mutate, immutate

= adj_list
<
	Association::mutate
>;

using					Segment // mutate, immutate

= adj_list
<
	Association::segment
>;

using					AllocateSegment

= adj_list
<
	Association::allocate,
	Association::segment
>;

using					DeallocateSegment

= adj_list
<
	Association::deallocate,
	Association::segment
>;

/***********************************************************************************************************************/

using					Iterator

= adj_list
<
	Association::segment,
	Association::hook,
	Association::link
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template<size_type mask>
using mutate_cast = apply< deduct<mask, Image>::rtn, Mutate>;

template<size_type mask>
using allocate_cast = apply< deduct<mask, Image>::rtn, AllocateSegment>;

template<size_type mask>
using deallocate_cast = apply< deduct<mask, Image>::rtn, DeallocateSegment>;
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


using EnumAssociation = typename range::Association;

template<EnumAssociation... params>
using enum_list = typename range::template adj_list<params...>;

using null_enum = typename range::null_adj;


template<typename... params>
using enum_adjective = typename range::template adjective<params...>;

/*
template<EnumAssociation... params>
using EnumAdjective = typename enumerator::template Adjective<params...>;
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							enum_adjective
************************************************************************************************************************/


/************************************************************************************************************************
							increment
************************************************************************************************************************/


using					EnumSucceed

= enum_list
<
	EnumAssociation::succeed
>;

using					EnumAccede

= enum_list
<
	EnumAssociation::accede
>;

/***********************************************************************************************************************/

using					EnumIncrement

= enum_list
<
	EnumAssociation::succeed,
	EnumAssociation::accede
>;


/************************************************************************************************************************
							direction
************************************************************************************************************************/


using					EnumForward

= enum_list
<
	EnumAssociation::forward
>;

using					EnumBackward

= enum_list
<
	EnumAssociation::backward
>;


/************************************************************************************************************************
							interval
************************************************************************************************************************/


using					EnumClosing

= enum_list
<
	EnumAssociation::closing
>;

using					EnumClosed

= enum_list
<
	EnumAssociation::closed
>;

using					EnumOpening

= enum_list
<
	EnumAssociation::opening
>;

using					EnumOpen

= enum_list
<
	EnumAssociation::open
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template<size_type mask>
using accede_cast = apply< deduct<mask, EnumIncrement>::rtn, EnumAccede>;
*/


