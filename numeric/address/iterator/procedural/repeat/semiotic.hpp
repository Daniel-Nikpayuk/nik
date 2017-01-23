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


#define ADV_TYPE(optimizer)												\
															\
	Adverb<Connotation::optimizer, F>


/***********************************************************************************************************************/


#define SUB_ADJ_FULL													\
															\
	Adjective<adj_list<sub_directionEnum, sub_intervalEnum, sub_imageEnum, sub_iteratorEnum>, T>


#define SUB_ADJ_INTERVAL(interval)											\
															\
	Adjective<adj_list<sub_directionEnum, Association::interval, sub_imageEnum, sub_iteratorEnum>, T>


#define SUB_ADJ_IMAGE(interval, image)											\
															\
	Adjective<adj_list<sub_directionEnum, Association::interval, Association::image, Association::segment>, T>


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


/*
template<FULL_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(specialize) & ad,

			sub_pointer out, sub_pointer end, SUB_ADJ_FULL & sub);


template<FULL_PARAMETERS>
static sub_pointer repeat(ADV_TYPE(specialize) & ad,

			sub_pointer out, SUB_ADJ_FULL & sub,

			size_type n);
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	tuple/list data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.
*/


struct Repeat
{
	enum struct Manner : size_type
	{
		functor,
		tracer,
		optimizer,

		dimension
	};

	using Selection = tuple
	<
		adv_list<Connotation::omit_functor, Connotation::apply_functor>,	// functor
		adv_list<Connotation::omit_count, Connotation::apply_count>,		// tracer
		adv_list<Connotation::prototype, Connotation::specialize>		// optimizer
	>;

	template<Connotation... params>
	using verb = Adverb
	<
		bit::template cast
		<
			typename sortFill<Selection, Connotation, params...>::rtn

		>::rtn
	>;


/***********************************************************************************************************************/


	enum struct Attribute : size_type
	{
		direction,
		interval,
		image,
		iterator,

		dimension
	};

	using Arrangement = tuple
	<
		adj_list<Association::forward, Association::backward>,						// direction
		adj_list<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
		adj_list<Association::mutate, Association::allocate, Association::deallocate>,			// image
		adj_list<Association::segment, Association::hook, Association::link>				// iterator
	>;

	template<Association... params>
	using subject = Adjective
	<
		adj_bit::template cast
		<
			typename sortFill<Arrangement, Association, params...>::rtn

		>::rtn
	>;


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[out, end)
*/


	template<size_type verb_mask, size_type sub_mask>
	struct closing
	{
		template
		<
			typename F,
			typename sub_pointer,
			typename T
		>
		static sub_pointer repeat(Adverb<verb_mask, F> & ad, sub_pointer out, sub_pointer end, Adjective<sub_mask, T> & sub)
		{
//			STATIC_ASSERT

			while (out != end)
			{
				functor_action(ad, out);
//				count_action(ad);

				iterate_action(out, sub);
			}

			return out;
		}

		template
		<
			typename F,
			typename sub_pointer,
			typename T
		>
		static sub_pointer repeat(Adverb<verb_mask, F> & ad, sub_pointer out, Adjective<sub_mask, T> & sub, size_type n)
		{
//			STATIC_ASSERT

			while (n)
			{
				functor_action(ad, out);
//				count_action(ad);

				iterate_action(out, sub);
				--n;
			}

			return out;
		}
	};

	template<size_type verb_mask, size_type sub_mask>
	struct closed
	{
		template
		<
			typename F,
			typename sub_pointer,
			typename T
		>
		static sub_pointer repeat(Adverb<verb_mask, F> & ad, sub_pointer out, sub_pointer end, Adjective<sub_mask, T> & sub)
		{
//			STATIC_ASSERT

			while (out != end)
			{
				functor_action(ad, out);
//				count_action(ad);

				iterate_action(out, sub);
			}

			functor_action(ad, out);
//			count_action(ad);

			return out;
		}
	};

	using VerbDispatch = typename parameter<size_type>::template list
	<
		bit::template list_cast<Connotation::	prototype	>::rtn,
		bit::template list_cast<Connotation::	specialize	>::rtn
	>;

	using SubjectDispatch = typename parameter<size_type>::template list
	<
		adj_bit::template list_cast<Association::	closing	>::rtn,
		adj_bit::template list_cast<Association::	closed	>::rtn,
		adj_bit::template list_cast<Association::	opening	>::rtn,
		adj_bit::template list_cast<Association::	open	>::rtn
	>;

	template<size_type bitmask>
	using verb_dispatch = typename bit::template pattern<bitmask>::template dispatch<VerbDispatch>;

	template<size_type bitmask>
	using sub_dispatch = typename adj_bit::template pattern<bitmask>::template dispatch<SubjectDispatch>;

	template<size_type verb_mask, size_type sub_mask>
	struct dispatch
	{
		static constexpr size_type rtn =	length<VerbDispatch>::rtn	*
							verb_dispatch<verb_mask>::rtn	+
							sub_dispatch<sub_mask>::rtn	;
	};
};


template<size_type verb_mask, size_type sub_mask>
using RepeatDispatcher = typename cases
<
	0,//Repeat::template dispatch<verb_mask, sub_mask>::rtn,

	typename Repeat::template closing<verb_mask, sub_mask>,
	typename Repeat::template closed<verb_mask, sub_mask>//,
/*
	Repeat::opening<verb_mask, sub_mask>,
	Repeat::open<verb_mask, sub_mask>,
*/

>::rtn;


template
<
	size_type verb_mask,
	typename F,

	typename sub_pointer,

	size_type sub_mask,
	typename T
>
static sub_pointer repeat(Adverb<verb_mask, F> & ad, sub_pointer out, sub_pointer end, Adjective<sub_mask, T> & sub)
{
	return RepeatDispatcher<verb_mask, sub_mask>::repeat(ad, out, end, sub);
};


template
<
	size_type verb_mask,
	typename F,

	typename sub_pointer,

	size_type sub_mask,
	typename T
>
static sub_pointer repeat(Adverb<verb_mask, F> & ad, sub_pointer out, Adjective<sub_mask, T> & sub, size_type n)
{
	return RepeatDispatcher<verb_mask, sub_mask>::repeat(ad, out, sub, n);
};


/*
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
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[out, out + n)
*/


/*
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
*/


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[out, end]
*/


/*
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
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[out, out + n]
*/


/*
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
*/


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	(out, end]
*/


/*
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
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(out, out + n]
*/


/*
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
*/


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	(out, end), out != end
*/


/*
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
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(out, out + n+1)
*/


/*
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
*/


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


/*
ALLOCATE_SEGMENT_REPEAT(closing)
ALLOCATE_SEGMENT_REPEAT(closed)
ALLOCATE_SEGMENT_REPEAT(opening)
ALLOCATE_SEGMENT_REPEAT(open)
*/


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


