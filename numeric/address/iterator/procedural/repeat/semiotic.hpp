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
	The adverb as well as object-adjective arguments are strictly non-const reference values, meaning one cannot
	pass non-reference arguments to them. Although this code is meant to provide a clean narrative interface,
	given its low-level, I have decided against adding any wrappers for user-friendly dispatch cases.

	Though not the intention, this also forces the low-level coder to create a single type-info object to pass
	which is actually good for memory/space efficiency.

	Note:	This collection does not interpret the combination [sub,ob]_adj<backward, [mutate,deallocate], hook>
		and leaves it undefined.
*/


/***********************************************************************************************************************/


#define ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	size_type functorEnum,												\
	size_type tracerEnum,												\
	typename F,


/***********************************************************************************************************************/


#define SUB_ADJ_PARAMETERS_FULL												\
															\
	typename sub_pointer,												\
															\
	size_type sub_directionEnum,											\
	size_type sub_intervalEnum,											\
	size_type sub_imageEnum,											\
	size_type sub_iteratorEnum,


#define SUB_ADJ_PARAMETERS_INTERVAL_REDUCED										\
															\
	typename sub_pointer,												\
															\
	size_type sub_directionEnum,											\
	size_type sub_imageEnum,											\
	size_type sub_iteratorEnum,


#define SUB_ADJ_PARAMETERS_DIRECTION_ONLY										\
															\
	typename sub_pointer,												\
															\
	size_type sub_directionEnum,


/***********************************************************************************************************************/


#define OB_ADJ_PARAMETERS_FULL												\
															\
	typename ob_int_type,												\
															\
	size_type ob_directionEnum,											\
	size_type ob_intervalEnum											\


#define OB_ADJ_PARAMETERS_INTERVAL_REDUCED										\
															\
	typename ob_int_type,												\
															\
	size_type ob_directionEnum											\


/***********************************************************************************************************************/


#define FULL_PARAMETERS													\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	SUB_ADJ_PARAMETERS_FULL												\
															\
	OB_ADJ_PARAMETERS_FULL


/***********************************************************************************************************************/


#define INTERVAL_REDUCED_PARAMETERS											\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	SUB_ADJ_PARAMETERS_INTERVAL_REDUCED										\
															\
	OB_ADJ_PARAMETERS_INTERVAL_REDUCED


/***********************************************************************************************************************/


#define DIRECTION_ONLY_PARAMETERS											\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	SUB_ADJ_PARAMETERS_DIRECTION_ONLY										\
															\
	OB_ADJ_PARAMETERS_INTERVAL_REDUCED


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ADV_TYPE(optimizer)												\
															\
	Adverb<LIST<functorEnum, tracerEnum, Connotation::optimizer>, F>


/***********************************************************************************************************************/


#define SUB_ADJ_FULL													\
															\
	SubjectAdjective<LIST<sub_directionEnum, sub_intervalEnum, sub_imageEnum, sub_iteratorEnum>>


#define SUB_ADJ_INTERVAL(interval)											\
															\
	SubjectAdjective<LIST<sub_directionEnum, Association::interval, sub_imageEnum, sub_iteratorEnum>>


#define SUB_ADJ_IMAGE(interval, image)											\
															\
	SubjectAdjective<LIST<sub_directionEnum, Association::interval, Association::image, Association::segment>>


/***********************************************************************************************************************/


#define OB_ADJ_FULL													\
															\
	ObjectAdjective<LIST<ob_directionEnum, ob_intervalEnum>>


#define OB_ADJ_INTERVAL(interval)											\
															\
	ObjectAdjective<LIST<ob_directionEnum, Association::interval>>


/************************************************************************************************************************/
/************************************************************************************************************************/


template<FULL_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(specialize) & ad,

			sub_pointer out, const SUB_ADJ_FULL & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_FULL & ob);


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#include"body/peek_action.hpp"
#include"body/functor_action.hpp"
#include"body/count_action.hpp"
#include"body/iterate_action.hpp"
#include"body/memory_action.hpp"


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(out, sub);
	memory_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_IMAGE(opening, immutate) & ob)
{
	while (in != end)
	{
		iterate_action(in, ob);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_IMAGE(opening, deallocate) & ob)
{
	iterate_action(in, OB_ADJ_IMAGE(opening, immutate)());

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(out, sub);
	memory_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	iterate_action(in, ob);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	while (peek_action(in, end, ob))
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	memory_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(opening) & ob)
{
	iterate_action(in, OB_ADJ_IMAGE(opening, immutate)());

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	memory_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	iterate_action(in, OB_ADJ_IMAGE(open, immutate)());

	while (peek_action(in, end, ob))
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(in, ob);

	return out;
}


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	memory_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_IMAGE(opening, immutate) & ob)
{
	while (in != end)
	{
		iterate_action(in, ob);
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);
	}

	return out;
}


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_IMAGE(opening, deallocate) & ob)
{
	iterate_action(in, OB_ADJ_IMAGE(opening, immutate)());
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	memory_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	iterate_action(in, OB_ADJ_IMAGE(open, immutate)());

	while (in != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(in, ob);
	}

	return out;
}


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(out, sub);
	memory_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_IMAGE(opening, immutate) & ob)
{
	while (in != end)
	{
		iterate_action(in, ob);
		iterate_action(out, sub);

		functor_action(ad, out, in);
		count_action(ad);
	}

	iterate_action(out, sub);

	return out;
}


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_IMAGE(opening, deallocate) & ob)
{
	iterate_action(in, OB_ADJ_IMAGE(opening, immutate)());
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	functor_action(ad, out, in);
	count_action(ad);

	iterate_action(out, sub);
	memory_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	iterate_action(in, OB_ADJ_IMAGE(open, immutate)());
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ALLOCATE_SEGMENT_REPEAT(sub_interval, ob_interval)								\
															\
template<DIRECTION_ONLY_PARAMETERS>											\
static sub_pointer repeat(ADV_TYPE(prototype) & ad,									\
															\
			sub_pointer & origin, const SUB_ADJ_IMAGE(sub_interval, allocate) & sub,			\
															\
			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(ob_interval) & ob)				\
															\
	{ return repeat(ad, memory_action(origin, sub), SUB_ADJ_IMAGE(sub_interval, mutate)(), in, end, ob); }


/***********************************************************************************************************************/


ALLOCATE_SEGMENT_REPEAT(closing, closing)
ALLOCATE_SEGMENT_REPEAT(closing, closed)
ALLOCATE_SEGMENT_REPEAT(closing, opening)
ALLOCATE_SEGMENT_REPEAT(closing, open)

ALLOCATE_SEGMENT_REPEAT(closed, closing)
ALLOCATE_SEGMENT_REPEAT(closed, closed)
ALLOCATE_SEGMENT_REPEAT(closed, opening)
ALLOCATE_SEGMENT_REPEAT(closed, open)

ALLOCATE_SEGMENT_REPEAT(opening, closing)
ALLOCATE_SEGMENT_REPEAT(opening, closed)
ALLOCATE_SEGMENT_REPEAT(opening, opening)
ALLOCATE_SEGMENT_REPEAT(opening, open)

ALLOCATE_SEGMENT_REPEAT(open, closing)
ALLOCATE_SEGMENT_REPEAT(open, closed)
ALLOCATE_SEGMENT_REPEAT(open, opening)
ALLOCATE_SEGMENT_REPEAT(open, open)


