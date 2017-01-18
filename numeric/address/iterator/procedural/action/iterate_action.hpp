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


#define OB_UINT_ADJ_PARAMETERS_DIRECTION_REDUCED									\
															\
	typename ob_pointer,												\
															\
	UIntAssociation ob_intervalEnum											\


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define DIRECTION(direction)												\
															\
	adj_list<Association::direction>


#define DIR_IMG_ITER(direction, image, iterator)									\
															\
	adj_list<Association::direction, Association::image, Association::iterator>


/***********************************************************************************************************************/


#define OB_UINT_ADJ_DIR(direction)											\
															\
	UIntAdjective<uint_list<UIntAssociation::direction, ob_intervalEnum>>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define NODE_TYPE	typename structural<Interface::semiotic>::template trim<pointer>::node


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & p, const Adjective<DIRECTION(forward)> & adj)
	{ ++p; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(forward, allocate, hook)> & adj)
	{ out = +out = new NODE_TYPE; }


/***********************************************************************************************************************/


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


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(forward, deallocate, hook)> & adj)
	{ delete out++; }


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(forward, deallocate, link)> & adj)
	{ delete -++out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIRECTION(backward)> & adj)
	{ --out; }


/***********************************************************************************************************************/


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


/***********************************************************************************************************************/


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


/***********************************************************************************************************************/


template
<
	typename pointer
>
static inline void iterate_action(pointer & out, const Adjective<DIR_IMG_ITER(backward, deallocate, link)> & adj)
	{ delete +--out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<OB_UINT_ADJ_PARAMETERS_DIRECTION_REDUCED>
static inline void iterate_action(ob_pointer & in, const OB_UINT_ADJ_DIR(forward) & ob)
	{ ++in; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<OB_UINT_ADJ_PARAMETERS_DIRECTION_REDUCED>
static inline void iterate_action(ob_pointer & in, const OB_UINT_ADJ_DIR(backward) & ob)
	{ --in; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef OB_UINT_ADJ_PARAMETERS_DIRECTION_REDUCED
#undef DIRECTION
#undef DIR_IMG_ITER
#undef OB_UINT_ADJ_DIR


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef NODE_TYPE


