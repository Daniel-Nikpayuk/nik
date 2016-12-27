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
	UIntAdjective<LIST<ob_directionEnum, ob_intervalEnum>>


#define OB_ADJ_INTERVAL(interval)											\
															\
	UIntAdjective<LIST<ob_directionEnum, UIntAssociation::interval>>


/************************************************************************************************************************/
/************************************************************************************************************************/


template<FULL_PARAMETERS>
static sub_pointer morph(ADV_TYPE(specialize) & ad,

			sub_pointer out, const SUB_ADJ_FULL & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_FULL & ob);


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

struct Morph
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

	[in, end) --> [out, out + end-in)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	Morph::functor_action(ad, out, in);
	Morph::count_action(ad);

	Morph::iterate_action(out, sub);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_INTERVAL(opening) & ob)
{
	while (in != end)
	{
		Morph::iterate_action(in, ob);

		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closing) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	Morph::iterate_action(in, ob);

	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
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
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	while (in < end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	Morph::functor_action(ad, out, in);
	Morph::count_action(ad);

	Morph::iterate_action(in, ob);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	Morph::functor_action(ad, out, in);
	Morph::count_action(ad);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(opening) & ob)
{
	Morph::iterate_action(in, ob);

	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	Morph::functor_action(ad, out, in);
	Morph::count_action(ad);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(closed) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	Morph::iterate_action(in, ob);

	while (in < end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	Morph::functor_action(ad, out, in);
	Morph::count_action(ad);

	Morph::iterate_action(in, ob);

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
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	while (in != end)
	{
		Morph::iterate_action(out, sub);

		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	Morph::iterate_action(out, sub);

	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	Morph::functor_action(ad, out, in);
	Morph::count_action(ad);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_INTERVAL(opening) & ob)
{
	while (in != end)
	{
		Morph::iterate_action(in, ob);
		Morph::iterate_action(out, sub);

		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(opening) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	Morph::iterate_action(in, ob);

	while (in != end)
	{
		Morph::iterate_action(out, sub);

		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(in, ob);
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
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closing) & ob)
{
	Morph::iterate_action(out, sub);

	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(closed) & ob)
{
	Morph::iterate_action(out, sub);

	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	Morph::functor_action(ad, out, in);
	Morph::count_action(ad);

	Morph::iterate_action(out, sub);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, OB_ADJ_INTERVAL(opening) & ob)
{
	while (in != end)
	{
		Morph::iterate_action(in, ob);
		Morph::iterate_action(out, sub);

		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);
	}

	Morph::iterate_action(out, sub);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer morph(ADV_TYPE(prototype) & ad,

			sub_pointer out, const SUB_ADJ_INTERVAL(open) & sub,

			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(open) & ob)
{
	Morph::iterate_action(in, ob);
	Morph::iterate_action(out, sub);

	while (in != end)
	{
		Morph::functor_action(ad, out, in);
		Morph::count_action(ad);

		Morph::iterate_action(out, sub);
		Morph::iterate_action(in, ob);
	}

	return out;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ALLOCATE_SEGMENT_MORPH(sub_interval, ob_interval)								\
															\
template<DIRECTION_ONLY_PARAMETERS>											\
static sub_pointer morph(ADV_TYPE(prototype) & ad,									\
															\
			sub_pointer & origin, const SUB_ADJ_IMAGE(sub_interval, allocate) & sub,			\
															\
			ob_int_type in, ob_int_type end, const OB_ADJ_INTERVAL(ob_interval) & ob)			\
															\
	{ return morph(ad, Morph::memory_action(origin, sub), SUB_ADJ_IMAGE(sub_interval, mutate)(), in, end, ob); }


/***********************************************************************************************************************/


ALLOCATE_SEGMENT_MORPH(closing, closing)
ALLOCATE_SEGMENT_MORPH(closing, closed)
ALLOCATE_SEGMENT_MORPH(closing, opening)
ALLOCATE_SEGMENT_MORPH(closing, open)

ALLOCATE_SEGMENT_MORPH(closed, closing)
ALLOCATE_SEGMENT_MORPH(closed, closed)
ALLOCATE_SEGMENT_MORPH(closed, opening)
ALLOCATE_SEGMENT_MORPH(closed, open)

ALLOCATE_SEGMENT_MORPH(opening, closing)
ALLOCATE_SEGMENT_MORPH(opening, closed)
ALLOCATE_SEGMENT_MORPH(opening, opening)
ALLOCATE_SEGMENT_MORPH(opening, open)

ALLOCATE_SEGMENT_MORPH(open, closing)
ALLOCATE_SEGMENT_MORPH(open, closed)
ALLOCATE_SEGMENT_MORPH(open, opening)
ALLOCATE_SEGMENT_MORPH(open, open)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef ADV_PARAMETERS_OPTIMIZER_REDUCED
#undef SUB_ADJ_PARAMETERS_FULL
#undef SUB_ADJ_PARAMETERS_INTERVAL_REDUCED
#undef SUB_ADJ_PARAMETERS_DIRECTION_ONLY
#undef OB_ADJ_PARAMETERS_FULL
#undef OB_ADJ_PARAMETERS_INTERVAL_REDUCED
#undef FULL_PARAMETERS
#undef INTERVAL_REDUCED_PARAMETERS
#undef DIRECTION_ONLY_PARAMETERS
#undef ADV_TYPE
#undef SUB_ADJ_FULL
#undef SUB_ADJ_INTERVAL
#undef SUB_ADJ_IMAGE
#undef OB_ADJ_FULL
#undef OB_ADJ_INTERVAL
#undef ALLOCATE_SEGMENT_MORPH


