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

template<size_type mask>
struct DispatchError
{
	DispatchError() { static_assert(true, "adjective dispatch: no match found."); }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
template<size_type... params>
using list = typename parameter<size_type>::template list<params...>;
*/

template<typename... params>
using tuple = typename variadic<Orientation::structural, Interface::semiotic>::template tuple<params...>;

/*
template<size_type i, typename... params>
using cases = typename variadic<Orientation::functional, Interface::media>::template cases<i, params...>;
*/

template<typename Field, typename Relation, Relation... params>
using sortFill = typename variadic<Orientation::functional, Interface::media>::template sortFill<Field, Relation, params...>;


/***********************************************************************************************************************/


template<typename mask>
using pattern = typename bit::mask::template pattern<mask>;

template<size_type mask, size_type... params>
using match = typename pattern<mask>::template match<params...>;

template<size_type mask, typename... params>
using dispatch = typename pattern<mask>::template dispatch<params...>;

template<size_type base, size_type mask>
using apply = typename pattern<base>::template apply<mask>;

template<size_type mask, size_type base>
using deduct = typename pattern<mask>::template deduct<base>;

template<typename Ordering, typename Relation, Relation... params>
using mask = typename bit::mask::template cast
<
	typename sortFill<Ordering, Relation, params...>::rtn
>;


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


template<typename L>
using functor_cast = apply< deduct<L, Functor>::rtn, ApplyFunctor>;

template<typename L>
using tracer_cast = apply< deduct<L, Tracer>::rtn, ApplyCount>;


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


static constexpr size_type		Forward

= adj_cast
<
	Association::forward

>::rtn;

static constexpr size_type		ForwardAllocateHook

= adj_cast
<
	Association::forward,
	Association::allocate,
	Association::hook

>::rtn;

static constexpr size_type		ForwardAllocateLink

= adj_cast
<
	Association::forward,
	Association::allocate,
	Association::link

>::rtn;

static constexpr size_type		ForwardDeallocateHook

= adj_cast
<
	Association::forward,
	Association::deallocate,
	Association::hook

>::rtn;

static constexpr size_type		ForwardDeallocateLink

= adj_cast
<
	Association::forward,
	Association::deallocate,
	Association::link

>::rtn;

static constexpr size_type		Backward

= adj_cast
<
	Association::backward

>::rtn;

static constexpr size_type		BackwardAllocateHook

= adj_cast
<
	Association::backward,
	Association::allocate,
	Association::hook

>::rtn;

static constexpr size_type		BackwardAllocateLink

= adj_cast
<
	Association::backward,
	Association::allocate,
	Association::link

>::rtn;

static constexpr size_type		BackwardDeallocateHook

= adj_cast
<
	Association::backward,
	Association::deallocate,
	Association::hook

>::rtn;

static constexpr size_type		BackwardDeallocateLink

= adj_cast
<
	Association::backward,
	Association::deallocate,
	Association::link

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Direction

= adj_cast
<
	Association::forward,
	Association::backward

>::rtn;


/************************************************************************************************************************
							interval
************************************************************************************************************************/


// alias from "enumerator" module ?


static constexpr size_type		Closing

= adj_cast
<
	Association::closing

>::rtn;

static constexpr size_type		Closed

= adj_cast
<
	Association::closed

>::rtn;

static constexpr size_type		Opening

= adj_cast
<
	Association::opening

>::rtn;

static constexpr size_type		Open

= adj_cast
<
	Association::open

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Interval

= adj_cast
<
	Association::closing,
	Association::closed,
	Association::opening,
	Association::open

>::rtn;


/************************************************************************************************************************
							image
************************************************************************************************************************/


static constexpr size_type		Allocate

= adj_cast
<
	Association::allocate

>::rtn;

static constexpr size_type		Deallocate // hook, link

= adj_cast
<
	Association::deallocate

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Image

= adj_cast
<
	Association::mutate,
	Association::allocate,
	Association::immutate,
	Association::deallocate

>::rtn;


/************************************************************************************************************************
							iterator
************************************************************************************************************************/


static constexpr size_type		Mutate // mutate, immutate

= adj_cast
<
	Association::mutate

>::rtn;

static constexpr size_type		Segment // mutate, immutate

= adj_cast
<
	Association::segment

>::rtn;

static constexpr size_type		AllocateSegment

= adj_cast
<
	Association::allocate,
	Association::segment

>::rtn;

static constexpr size_type		DeallocateSegment

= adj_cast
<
	Association::deallocate,
	Association::segment

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Iterator

= adj_cast
<
	Association::segment,
	Association::hook,
	Association::link

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using mutate_cast = apply< deduct<mask, Image>::rtn, Mutate>;

template<size_type mask>
using allocate_cast = apply< deduct<mask, Image>::rtn, AllocateSegment>;

template<size_type mask>
using deallocate_cast = apply< deduct<mask, Image>::rtn, DeallocateSegment>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


using EnumAssociation = typename enumerator::Association;

template<EnumAssociation... params>
using enum_list = typename enumerator::template adj_list<params...>;

using null_enum = typename enumerator::null_adj;


template<size_type mask, typename... params>
using enum_adjective = typename enumerator::template adjective<mask, params...>;

template<EnumAssociation... params>
using enum_cast = typename enumerator::template adj_cast<params...>;

template<EnumAssociation... params>
using EnumAdjective = typename enumerator::template Adjective<params...>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							enum_adjective
************************************************************************************************************************/


/************************************************************************************************************************
							increment
************************************************************************************************************************/


static constexpr size_type		EnumSucceed

= enum_cast
<
	EnumAssociation::succeed

>::rtn;

static constexpr size_type		EnumAccede

= enum_cast
<
	EnumAssociation::accede

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		EnumIncrement

= enum_cast
<
	EnumAssociation::succeed,
	EnumAssociation::accede

>::rtn;


/************************************************************************************************************************
							direction
************************************************************************************************************************/


static constexpr size_type		EnumForward

= enum_cast
<
	EnumAssociation::forward

>::rtn;

static constexpr size_type		EnumBackward

= enum_cast
<
	EnumAssociation::backward

>::rtn;


/************************************************************************************************************************
							interval
************************************************************************************************************************/


static constexpr size_type		EnumClosing

= enum_cast
<
	EnumAssociation::closing

>::rtn;

static constexpr size_type		EnumClosed

= enum_cast
<
	EnumAssociation::closed

>::rtn;

static constexpr size_type		EnumOpening

= enum_cast
<
	EnumAssociation::opening

>::rtn;

static constexpr size_type		EnumOpen

= enum_cast
<
	EnumAssociation::open

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using accede_cast = apply< deduct<mask, EnumIncrement>::rtn, EnumAccede>;


