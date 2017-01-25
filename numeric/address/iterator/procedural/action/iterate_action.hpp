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


using Adjective_Forward = typename structural<Interface::semiotic>::Adjective_Forward;

using Adjective_ForwardAllocateHook = typename structural<Interface::semiotic>::Adjective_ForwardAllocateHook;
using Adjective_ForwardAllocateLink = typename structural<Interface::semiotic>::Adjective_ForwardAllocateLink;

using Adjective_ForwardDeallocateHook = typename structural<Interface::semiotic>::Adjective_ForwardDeallocateHook;
using Adjective_ForwardDeallocateLink = typename structural<Interface::semiotic>::Adjective_ForwardDeallocateLink;


using Adjective_Backward = typename structural<Interface::semiotic>::Adjective_Backward;

using Adjective_BackwardAllocateHook = typename structural<Interface::semiotic>::Adjective_BackwardAllocateHook;
using Adjective_BackwardAllocateLink = typename structural<Interface::semiotic>::Adjective_BackwardAllocateLink;

using Adjective_BackwardDeallocateHook = typename structural<Interface::semiotic>::Adjective_BackwardDeallocateHook;
using Adjective_BackwardDeallocateLink = typename structural<Interface::semiotic>::Adjective_BackwardDeallocateLink;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define NODE_TYPE	typename structural<Interface::semiotic>::template trim<pointer>::node


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & p, const Adjective_Forward & adj)
	{ ++p; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective_ForwardAllocateHook & adj)

	{ out = +out = new NODE_TYPE; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective_ForwardAllocateLink & adj)
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
static inline void iterate_action(pointer & out, const Adjective_ForwardDeallocateHook & adj)
	{ delete out++; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective_ForwardDeallocateLink & adj)
	{ delete -++out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective_Backward & adj)
	{ --out; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective_BackwardAllocateHook & adj)
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
static inline void iterate_action(pointer & out, const Adjective_BackwardAllocateLink & adj)
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
static inline void iterate_action(pointer & out, const Adjective_BackwardDeallocateLink & adj)
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
static inline void iterate_action(value_type & in, const EnumAdjective<mask, Accede, A> & ob)
	{ ob.accessor(in); }
*/


/***********************************************************************************************************************/


/*
template
<
	typename value_type
>
static inline void iterate_action(value_type & in, const EnumAdjective<ENUM_DIRECTION(forward)> & ob)
	{ ++in; }
*/


/***********************************************************************************************************************/


/*
template
<
	typename value_type
>
static inline void iterate_action(value_type & in, const EnumAdjective<ENUM_DIRECTION(backward)> & ob)
	{ --in; }
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef NODE_TYPE


