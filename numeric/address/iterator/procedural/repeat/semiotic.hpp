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
	Note:	This collection does not interpret the combination sub_adj<backward, mutate, hook>
		and leaves it undefined.

		the repeat variable 'n' is of size_type which breaks semantically for negative numbers (signed types).

		No need for "memory_action(sub)" at body's end, as it would only be called for a segment deallocate,
		in which case there's no need for such an expensive loop to begin with. This special case is branched.
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	TUPLE/LIST data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Repeat
{
	struct Manner
	{
		enum : size_type
		{
			functor,
			tracer,
			optimizer,

			dimension
		};

		using Relation = TUPLE
		<
			LIST<Connotation::omit_functor, Connotation::apply_functor>,	// functor
			LIST<Connotation::omit_count, Connotation::apply_count>,	// tracer
			LIST<Connotation::prototype, Connotation::specialize>		// optimizer
		>;
	};

	template<size_type... params>
	using verb = Adverb<SORTFILL<Manner, params...>::rtn, void>;

	struct Attribute
	{
		enum : size_type
		{
			direction,
			interval,
			image,
			iterator,

			dimension
		};

		using Relation = TUPLE
		<
			LIST<Association::forward, Association::backward>,						// direction
			LIST<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
			LIST<Association::mutate, Association::allocate, Association::deallocate>,			// image
			LIST<Association::segment, Association::hook, Association::link>				// iterator
		>;
	};

	template<size_type... params>
	using subject = Adjective<SORTFILL<Attribute, params...>::rtn>;
};


/***********************************************************************************************************************/
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
	size_type sub_iteratorEnum


#define SUB_ADJ_PARAMETERS_INTERVAL_REDUCED										\
															\
	typename sub_pointer,												\
															\
	size_type sub_directionEnum,											\
	size_type sub_imageEnum,											\
	size_type sub_iteratorEnum


#define SUB_ADJ_PARAMETERS_DIRECTION_ONLY										\
															\
	typename sub_pointer,												\
															\
	size_type sub_directionEnum


/***********************************************************************************************************************/


#define FULL_PARAMETERS													\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	SUB_ADJ_PARAMETERS_FULL


/***********************************************************************************************************************/


#define INTERVAL_REDUCED_PARAMETERS											\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	SUB_ADJ_PARAMETERS_INTERVAL_REDUCED


/***********************************************************************************************************************/


#define DIRECTION_ONLY_PARAMETERS											\
															\
	ADV_PARAMETERS_OPTIMIZER_REDUCED										\
															\
	SUB_ADJ_PARAMETERS_DIRECTION_ONLY


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define ADV_TYPE(optimizer)												\
															\
	Adverb<LIST<functorEnum, tracerEnum, Connotation::optimizer>, F>


/***********************************************************************************************************************/


#define SUB_ADJ_FULL													\
															\
	Adjective<LIST<sub_directionEnum, sub_intervalEnum, sub_imageEnum, sub_iteratorEnum>>


#define SUB_ADJ_INTERVAL(interval)											\
															\
	Adjective<LIST<sub_directionEnum, Association::interval, sub_imageEnum, sub_iteratorEnum>>


#define SUB_ADJ_IMAGE(interval, image)											\
															\
	Adjective<LIST<sub_directionEnum, Association::interval, Association::image, Association::segment>>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define STATIC_ASSERT													\
															\
	static_assert													\
	(														\
		sub_directionEnum != Association::backward				||				\
		(													\
			sub_imageEnum != Association::mutate				&&				\
			sub_imageEnum != Association::deallocate							\
		)									||				\
		sub_iteratorEnum != Association::hook					,				\
															\
		"\n\nmap is undefined for Subject<backward, hook>.\n"							\
	);


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<FULL_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(specialize) & ad,

			sub_pointer out, sub_pointer end, SUB_ADJ_FULL & sub);


template<FULL_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(specialize) & ad,

			sub_pointer out, SUB_ADJ_FULL & sub,

			size_type n);


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[out, end)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, sub_pointer end, SUB_ADJ_INTERVAL(closing) & sub)
{
	STATIC_ASSERT

	while (out != end)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[out, out + n)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, SUB_ADJ_INTERVAL(closing) & sub,

			size_type n)
{
	STATIC_ASSERT

	while (n)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
		--n;
	}

	return out;
}


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[out, end]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, sub_pointer end, SUB_ADJ_INTERVAL(closed) & sub)
{
	STATIC_ASSERT

	while (out != end)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
	}

	functor_action(ad, out);
	count_action(ad);

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	[out, out + n]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, SUB_ADJ_INTERVAL(closed) & sub,

			size_type n)
{
	STATIC_ASSERT

	while (n)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
		--n;
	}

	functor_action(ad, out);
	count_action(ad);

	return out;
}


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	(out, end]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, sub_pointer end, SUB_ADJ_INTERVAL(opening) & sub)
{
	STATIC_ASSERT

	while (out != end)
	{
		iterate_action(out, sub);

		functor_action(ad, out);
		count_action(ad);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(out, out + n]
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, SUB_ADJ_INTERVAL(opening) & sub,

			size_type n)
{
	STATIC_ASSERT

	while (n)
	{
		iterate_action(out, sub);

		functor_action(ad, out);
		count_action(ad);

		--n;
	}

	return out;
}


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	(out, end), out != end
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, sub_pointer end, SUB_ADJ_INTERVAL(open) & sub)
{
	STATIC_ASSERT

	iterate_action(out, sub);

	while (out != end)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}


/***********************************************************************************************************************/


/*
	Constraints:

	(out, out + n+1)
*/


template<INTERVAL_REDUCED_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(prototype) & ad,

			sub_pointer out, SUB_ADJ_INTERVAL(open) & sub,

			size_type n)
{
	STATIC_ASSERT

	iterate_action(out, sub);

	while (n)
	{
		functor_action(ad, out);
		count_action(ad);

		iterate_action(out, sub);
		--n;
	}

	return out;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Notice in this case the sub_adjective can be const because we know enough about it to optimize as such.
*/

#define ALLOCATE_SEGMENT_REPEAT(sub_interval)										\
															\
template<DIRECTION_ONLY_PARAMETERS>											\
static void repeat(ADV_TYPE(prototype) & ad,										\
															\
			sub_pointer out, sub_pointer end, SUB_ADJ_IMAGE(sub_interval, deallocate) & sub)		\
															\
	{ memory_action(sub); }												\
															\
template<DIRECTION_ONLY_PARAMETERS>											\
static sub_pointer repeat(ADV_TYPE(prototype) & ad,									\
															\
			sub_pointer & origin, sub_pointer end, const SUB_ADJ_IMAGE(sub_interval, allocate) & sub)	\
{															\
	SUB_ADJ_IMAGE(sub_interval, mutate) sub_mutate;									\
															\
	return repeat(ad, memory_action(origin, sub), end, sub_mutate);							\
}															\
															\
template<DIRECTION_ONLY_PARAMETERS>											\
static sub_pointer repeat(ADV_TYPE(prototype) & ad,									\
															\
			sub_pointer & origin, const SUB_ADJ_IMAGE(sub_interval, allocate) & sub,			\
															\
			size_type n)											\
{															\
	SUB_ADJ_IMAGE(sub_interval, mutate) sub_mutate;									\
															\
	return repeat(ad, memory_action(origin, sub), sub_mutate, n);							\
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
#undef SUB_ADJ_PARAMETERS_FULL
#undef SUB_ADJ_PARAMETERS_INTERVAL_REDUCED
#undef SUB_ADJ_PARAMETERS_DIRECTION_ONLY
#undef FULL_PARAMETERS
#undef INTERVAL_REDUCED_PARAMETERS
#undef DIRECTION_ONLY_PARAMETERS
#undef ADV_TYPE
#undef SUB_ADJ_FULL
#undef SUB_ADJ_INTERVAL
#undef SUB_ADJ_IMAGE
#undef STATIC_ASSERT
#undef ALLOCATE_SEGMENT_REPEAT


