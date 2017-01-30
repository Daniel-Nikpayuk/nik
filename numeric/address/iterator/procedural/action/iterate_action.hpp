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
	iterate_action can be called on both "out" as well as "in" pointers.
*/

/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define NODE_TYPE	typename structural::template trim<pointer>::node


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & p, const adjective<Forward> & adj)
	{ ++p; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const adjective<ForwardAllocateHook> & adj)

	{ out = +out = new NODE_TYPE; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const adjective<ForwardAllocateLink> & adj)
{
	+out = new NODE_TYPE;
	-+out = out;
	++out;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const adjective<ForwardDeallocateHook> & adj)
	{ delete out++; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const adjective<ForwardDeallocateLink> & adj)
	{ delete -++out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const adjective<Backward> & adj)
	{ --out; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const adjective<BackwardAllocateHook> & adj)
{
	pointer tmp = out;
	out = new NODE_TYPE;
	+out = tmp;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const adjective<BackwardAllocateLink> & adj)
{
	-out = new NODE_TYPE;
	+-out = out;
	--out;
}


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const adjective<BackwardDeallocateLink> & adj)
	{ delete +--out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template
<
	typename value_type,

	size_type mask,
	typename A
>
static inline void iterate_action(value_type & in, const enum_adjective<mask, Accede, A> & ob)
	{ ob.accessor(in); }
*/


/***********************************************************************************************************************/


/*
template
<
	typename value_type
>
static inline void iterate_action(value_type & in, const enum_adjective<ENUM_DIRECTION(forward)> & ob)
	{ ++in; }
*/


/***********************************************************************************************************************/


/*
template
<
	typename value_type
>
static inline void iterate_action(value_type & in, const enum_adjective<ENUM_DIRECTION(backward)> & ob)
	{ --in; }
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using iterate = typename dispatch
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

	adjective<Backward>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef NODE_TYPE


