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


#define ESUB_ADJ_PARAMETERS_DIRECTION_REDUCED										\
															\
	typename esub_pointer,												\
															\
	size_type esub_intervalEnum,											\
	size_type esub_imageEnum,											\
	size_type esub_iteratorEnum


#define ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY									\
															\
	typename esub_pointer,												\
															\
	size_type esub_intervalEnum,											\
	size_type esub_iteratorEnum


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ESUB_ADJ_DIR(direction)												\
															\
	ESubjectAdjective<LIST<Association::direction, esub_intervalEnum, esub_imageEnum, esub_iteratorEnum>>


#define ESUB_ADJ_DIR_IMG_ITER(direction, image, iterator)								\
															\
	ESubjectAdjective<LIST<Association::direction, esub_intervalEnum, Association::image, Association::iterator>>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ESUB_POINTER_TYPE	typename structural<nik::semiotic>::template trim<esub_pointer>::pointer::pointer


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<ESUB_ADJ_PARAMETERS_DIRECTION_REDUCED>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR(forward) & esub)
	{ ++out; }


/***********************************************************************************************************************/


template<ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR_IMG_ITER(forward, allocate, hook) & esub)
	{ out = +out = new ESUB_POINTER_TYPE; }


/***********************************************************************************************************************/


template<ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR_IMG_ITER(forward, allocate, link) & esub)
{
	+out = new ESUB_POINTER_TYPE;
	-+out = out;
	++out;
}


/***********************************************************************************************************************/


template<ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR_IMG_ITER(forward, deallocate, hook) & esub)
	{ delete out++; }


/***********************************************************************************************************************/


template<ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR_IMG_ITER(forward, deallocate, link) & esub)
	{ delete -++out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Note:	This collection is undefined for ESubjectAdjective<backward, [mutate/deallocate], hook>.
*/

template<ESUB_ADJ_PARAMETERS_DIRECTION_REDUCED>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR(backward) & esub)
{
	static_assert
	(
		(
			esub_imageEnum != Association::mutate				&&
			esub_imageEnum != Association::deallocate
		)									||
		esub_iteratorEnum != Association::hook					,

		"\n\nmap is undefined for ESubjectAdjective<backward, mutate, hook>.\n"
	);

	--out;
}


/***********************************************************************************************************************/


template<ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR_IMG_ITER(backward, allocate, hook) & esub)
{
	esub_pointer tmp = out;
	out = new ESUB_POINTER_TYPE;
	+out = tmp;
}


/***********************************************************************************************************************/


template<ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR_IMG_ITER(backward, allocate, link) & esub)
{
	-out = new ESUB_POINTER_TYPE;
	+-out = out;
	--out;
}


/***********************************************************************************************************************/


template<ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY>
static inline void iterate_action(esub_pointer & out, const ESUB_ADJ_DIR_IMG_ITER(backward, deallocate, link) & esub)
	{ delete +--out; }


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef ESUB_ADJ_PARAMETERS_DIRECTION_REDUCED
#undef ESUB_ADJ_PARAMETERS_INTERVAL_ITERATOR_ONLY
#undef ESUB_ADJ_DIR
#undef ESUB_ADJ_DIR_IMG_ITER


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef ESUB_POINTER_TYPE


