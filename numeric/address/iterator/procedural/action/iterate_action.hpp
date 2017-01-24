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


using Adjective_ForwardAllocateHook = typename structural<Interface::semiotic>::Adjective_ForwardAllocateHook;

/*
static constexpr size_type ForwardAllocateHook	= adj_bit::template list_cast
<
	Association::forward,
	Association::allocate,
	Association::hook

>::rtn;
*/


#define DIRECTION(direction)												\
															\
	adj_list<Association::direction>


#define DIR_IMG_ITER(direction, image, iterator)									\
															\
	adj_list<Association::direction, Association::image, Association::iterator>


/***********************************************************************************************************************/


#define ACCEDE														\
															\
	enum_list<EnumAssociation::accede>


#define ENUM_DIRECTION(direction)											\
															\
	enum_list<EnumAssociation::succeed, EnumAssociation::direction>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define NODE_TYPE	typename structural<Interface::semiotic>::template trim<pointer>::node


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template
<
	typename pointer
>
static inline void iterate_action(pointer & p, const Adjective<DIRECTION(forward)> & adj)
	{ ++p; }
*/


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective_ForwardAllocateHook & adj)

	{ out = +out = new NODE_TYPE; }


/***********************************************************************************************************************/


/*
template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(forward, allocate, link)> & adj)
{
	+out = new NODE_TYPE;
	-+out = out;
	++out;
}
*/


/***********************************************************************************************************************/


/*
template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(forward, deallocate, hook)> & adj)
	{ delete out++; }
*/


/***********************************************************************************************************************/


/*
template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(forward, deallocate, link)> & adj)
	{ delete -++out; }
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIRECTION(backward)> & adj)
	{ --out; }
*/


/***********************************************************************************************************************/


/*
template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(backward, allocate, hook)> & adj)
{
	pointer tmp = out;
	out = new NODE_TYPE;
	+out = tmp;
}
*/


/***********************************************************************************************************************/


/*
template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(backward, allocate, link)> & adj)
{
	-out = new NODE_TYPE;
	+-out = out;
	--out;
}
*/


/***********************************************************************************************************************/


/*
template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(backward, deallocate, link)> & adj)
	{ delete +--out; }
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
template
<
	typename value_type,
	typename A
>
static inline void iterate_action(value_type & in, const EnumAdjective<ACCEDE, A> & ob)
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


#undef DIRECTION
#undef DIR_IMG_ITER
#undef ACCEDE
#undef ENUM_DIRECTION


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef NODE_TYPE


