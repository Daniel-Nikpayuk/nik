/************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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


#define SUB_ADJ_PARAMETERS_DIRECTION_REDUCED										\
															\
	typename sub_pointer,												\
															\
	size_type sub_intervalEnum,											\
	size_type sub_imageEnum,											\
	size_type sub_iteratorEnum


#define SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY									\
															\
	typename sub_pointer,												\
															\
	size_type sub_intervalEnum,											\
	size_type sub_iteratorEnum


/***********************************************************************************************************************/


#define OB_ADJ_PARAMETERS_DIRECTION_REDUCED										\
															\
	typename ob_pointer,												\
															\
	size_type ob_intervalEnum,											\
	size_type ob_imageEnum,												\
	size_type ob_iteratorEnum,											\
	typename T


#define OB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY									\
															\
	typename ob_pointer,												\
															\
	size_type ob_intervalEnum,											\
	size_type ob_iteratorEnum,											\
	typename T


#define OB_ADJ_PARAMETERS_INTERVAL_ONLY											\
															\
	typename ob_int_type,												\
															\
	size_type ob_intervalEnum											\


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define SUB_ADJ_DIR(direction)												\
															\
	Adjective<LIST<Association::direction, sub_intervalEnum, sub_imageEnum, sub_iteratorEnum>>


#define SUB_ADJ_DIR_IMG_ITER(direction, image, iterator)								\
															\
	Adjective<LIST<Association::direction, sub_intervalEnum, Association::image, Association::iterator>>


/***********************************************************************************************************************/


#define OB_UINT_ADJ_DIR(direction)											\
															\
	UIntAdjective<LIST<UIntAssociation::direction, ob_intervalEnum>>


#define OB_ADJ_DIR(direction)												\
															\
	Adjective<LIST<Association::direction, ob_intervalEnum, ob_imageEnum, ob_iteratorEnum>, T>


#define OB_ADJ_DIR_IMG_ITER(direction, image, iterator)									\
															\
	Adjective<LIST<Association::direction, ob_intervalEnum, Association::image, Association::iterator>, T>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define SUB_POINTER_TYPE	typename structural<nik::semiotic>::template trim<sub_pointer>::pointer::pointer


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_DIRECTION_REDUCED>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR(forward) & sub)
	{ ++out; }


/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR_IMG_ITER(forward, allocate, hook) & sub)
	{ out = +out = new SUB_POINTER_TYPE; }


/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR_IMG_ITER(forward, allocate, link) & sub)
{
	+out = new SUB_POINTER_TYPE;
	-+out = out;
	++out;
}


/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR_IMG_ITER(forward, deallocate, hook) & sub)
	{ delete out++; }


/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR_IMG_ITER(forward, deallocate, link) & sub)
	{ delete -++out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_DIRECTION_REDUCED>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR(backward) & sub)
	{ --out; }


/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR_IMG_ITER(backward, allocate, hook) & sub)
{
	sub_pointer tmp = out;
	out = new SUB_POINTER_TYPE;
	+out = tmp;
}


/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR_IMG_ITER(backward, allocate, link) & sub)
{
	-out = new SUB_POINTER_TYPE;
	+-out = out;
	--out;
}


/***********************************************************************************************************************/


template<SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(sub_pointer & out, const SUB_ADJ_DIR_IMG_ITER(backward, deallocate, link) & sub)
	{ delete +--out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<OB_ADJ_PARAMETERS_INTERVAL_ONLY>
static inline void iterate_action(ob_int_type & in, const OB_UINT_ADJ_DIR(forward) & ob)
	{ ++in; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<OB_ADJ_PARAMETERS_DIRECTION_REDUCED>
static inline void iterate_action(ob_pointer & in, const OB_ADJ_DIR(forward) & ob)
	{ ++in; }


/***********************************************************************************************************************/


template<OB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(ob_pointer & in, const OB_ADJ_DIR_IMG_ITER(forward, deallocate, hook) & ob)
	{ delete in++; }


/***********************************************************************************************************************/


template<OB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(ob_pointer & in, const OB_ADJ_DIR_IMG_ITER(forward, deallocate, link) & ob)
	{ delete -++in; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<OB_ADJ_PARAMETERS_INTERVAL_ONLY>
static inline void iterate_action(ob_int_type & in, const OB_UINT_ADJ_DIR(backward) & ob)
	{ --in; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<OB_ADJ_PARAMETERS_DIRECTION_REDUCED>
static inline void iterate_action(ob_pointer & in, const OB_ADJ_DIR(backward) & ob)
	{ --in; }


/***********************************************************************************************************************/


template<OB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(ob_pointer & in, const OB_ADJ_DIR_IMG_ITER(backward, deallocate, link) & ob)
	{ delete +--in; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef SUB_ADJ_PARAMETERS_DIRECTION_REDUCED
#undef SUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY
#undef OB_ADJ_PARAMETERS_DIRECTION_REDUCED
#undef OB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY
#undef SUB_ADJ_DIR
#undef SUB_ADJ_DIR_IMG_ITER
#undef OB_UINT_ADJ_DIR
#undef OB_ADJ_DIR
#undef OB_ADJ_DIR_IMG_ITER


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef SUB_POINTER_TYPE


