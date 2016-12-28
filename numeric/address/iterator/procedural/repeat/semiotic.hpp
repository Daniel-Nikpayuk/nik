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

/*
	Note:	This collection does not interpret the combination sub_adj<backward, mutate, hook>
		and leaves it undefined.

		the repeat variable 'n' is of size_type which breaks semantically for negative numbers (signed types).
*/


/***********************************************************************************************************************/


#define ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	size_type functorEnum,												\
	size_type tracerEnum,												\
	typename F,


/***********************************************************************************************************************/


#define ESUB_ADJ_PARAMETERS_FULL											\
															\
	typename esub_pointer,												\
															\
	size_type esub_directionEnum,											\
	size_type esub_intervalEnum,											\
	size_type esub_imageEnum,											\
	size_type esub_iteratorEnum


#define ESUB_ADJ_PARAMETERS_INTERVAL_REDUCED										\
															\
	typename esub_pointer,												\
															\
	size_type esub_directionEnum,											\
	size_type esub_imageEnum,											\
	size_type esub_iteratorEnum


#define ESUB_ADJ_PARAMETERS_DIRECTION_ONLY										\
															\
	typename esub_pointer,												\
															\
	size_type esub_directionEnum


/***********************************************************************************************************************/


#define FULL_PARAMETERS													\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	ESUB_ADJ_PARAMETERS_FULL


/***********************************************************************************************************************/


#define INTERVAL_REDUCED_PARAMETERS											\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	ESUB_ADJ_PARAMETERS_INTERVAL_REDUCED


/***********************************************************************************************************************/


#define DIRECTION_ONLY_PARAMETERS											\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	ESUB_ADJ_PARAMETERS_DIRECTION_ONLY


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ADV_TYPE(optimizer)												\
															\
	Adverb<LIST<functorEnum, tracerEnum, Connotation::optimizer>, F>


/***********************************************************************************************************************/


#define ESUB_ADJ_FULL													\
															\
	ESubjectAdjective<LIST<esub_directionEnum, esub_intervalEnum, esub_imageEnum, esub_iteratorEnum>>


#define ESUB_ADJ_INTERVAL(interval)											\
															\
	ESubjectAdjective<LIST<esub_directionEnum, Association::interval, esub_imageEnum, esub_iteratorEnum>>


#define ESUB_ADJ_IMAGE(interval, image)											\
															\
	ESubjectAdjective<LIST<esub_directionEnum, Association::interval, Association::image, Association::segment>>


/************************************************************************************************************************/
/************************************************************************************************************************/


template<FULL_PARAMETERS>
static esub_pointer repeat(ADV_TYPE(specialize) & ad,

			esub_pointer out, ESUB_ADJ_FULL & sub,

			size_type n);


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


struct Repeat
{
	#include"body/functor_action.hpp"
	#include"body/count_action.hpp"
	#include"body/iterate_action.hpp"
	#include"body/memory_action.hpp"
};


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[out, out + n)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static esub_pointer repeat(ADV_TYPE(prototype) & ad,

			esub_pointer out, ESUB_ADJ_INTERVAL(closing) & esub,

			size_type n)
{
	while (n)
	{
		Repeat::functor_action(ad, out);
		Repeat::count_action(ad);

		Repeat::iterate_action(out, esub);
		--n;
	}

	Repeat::memory_action(esub);

	return out;
}


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[out, out + n]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static esub_pointer repeat(ADV_TYPE(prototype) & ad,

			esub_pointer out, ESUB_ADJ_INTERVAL(closed) & esub,

			size_type n)
{
	while (n)
	{
		Repeat::functor_action(ad, out);
		Repeat::count_action(ad);

		Repeat::iterate_action(out, esub);
		--n;
	}

	Repeat::functor_action(ad, out);
	Repeat::count_action(ad);

	Repeat::memory_action(esub);

	return out;
}


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	(out, out + n]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static esub_pointer repeat(ADV_TYPE(prototype) & ad,

			esub_pointer out, ESUB_ADJ_INTERVAL(opening) & esub,

			size_type n)
{
	while (n)
	{
		Repeat::iterate_action(out, esub);

		Repeat::functor_action(ad, out);
		Repeat::count_action(ad);

		--n;
	}

	Repeat::memory_action(esub);

	return out;
}


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	(out, out + n+1)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static esub_pointer repeat(ADV_TYPE(prototype) & ad,

			esub_pointer out, ESUB_ADJ_INTERVAL(open) & esub,

			size_type n)
{
	Repeat::iterate_action(out, esub);

	while (n)
	{
		Repeat::functor_action(ad, out);
		Repeat::count_action(ad);

		Repeat::iterate_action(out, esub);
		--n;
	}

	Repeat::memory_action(esub);

	return out;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Notice in this case the esub_adjective can be const because we know enough about it to optimize as such.
*/

#define ALLOCATE_SEGMENT_REPEAT(esub_interval)										\
															\
template<DIRECTION_ONLY_PARAMETERS>											\
static esub_pointer repeat(ADV_TYPE(prototype) & ad,									\
															\
			esub_pointer & origin, const ESUB_ADJ_IMAGE(esub_interval, allocate) & esub,			\
															\
			size_type n)											\
															\
{															\
	ESUB_ADJ_IMAGE(esub_interval, mutate) esub_mutate;								\
															\
	return repeat(ad, Repeat::memory_action(origin, esub), esub_mutate, n);						\
}


/***********************************************************************************************************************/


ALLOCATE_SEGMENT_REPEAT(closing)
ALLOCATE_SEGMENT_REPEAT(closed)
ALLOCATE_SEGMENT_REPEAT(opening)
ALLOCATE_SEGMENT_REPEAT(open)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef ADV_PARAMETERS_OPTIMIZER_REDUCED
#undef ESUB_ADJ_PARAMETERS_FULL
#undef ESUB_ADJ_PARAMETERS_INTERVAL_REDUCED
#undef ESUB_ADJ_PARAMETERS_DIRECTION_ONLY
#undef FULL_PARAMETERS
#undef INTERVAL_REDUCED_PARAMETERS
#undef DIRECTION_ONLY_PARAMETERS
#undef ADV_TYPE
#undef ESUB_ADJ_FULL
#undef ESUB_ADJ_INTERVAL
#undef ESUB_ADJ_IMAGE
#undef ALLOCATE_SEGMENT_REPEAT


