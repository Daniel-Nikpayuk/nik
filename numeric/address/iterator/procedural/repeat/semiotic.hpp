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


#define PARAMETERS													\
															\
	size_type verb_mask,												\
	typename... F,													\
															\
	typename sub_pointer,												\
															\
	size_type sub_mask,												\
	typename... T


/***********************************************************************************************************************/
/***********************************************************************************************************************/


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
	using verb = optimizer
	<
		bitmask::template cast
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
	using subject = adj_modifier
	<
		adj_bitmask::template cast
		<
			typename sortFill<Arrangement, Association, params...>::rtn

		>::rtn
	>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[out, end)
*/


/*
template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, Adjective<sub_mask, Closing, T...> & sub)
{
//	STATIC_ASSERT

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

static constexpr size_type Closing = structural<Interface::semiotic>::Closing;

/*
	Constraints:

	[out, out + n)
*/


template
<
	typename sub_pointer
>
static sub_pointer repeat(Adverb<Connotation::prototype> *ad,

			sub_pointer out, Adjective<Association::closing> & sub,

			size_type n)
{
//	STATIC_ASSERT

	while (n)
	{
		nik::display << (size_type) ad->bitmask << nik::endl;
//		functor_action(ad, out);
//		count_action(ad);

//		iterate_action(out, sub);
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


/*
template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, Adjective<sub_mask, Closed, T...> & sub)
{
//	STATIC_ASSERT

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
template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, Adjective<sub_mask, Closed, T...> & sub,

			size_type n)
{
//	STATIC_ASSERT

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
template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, Adjective<sub_mask, Opening, T...> & sub)
{
//	STATIC_ASSERT

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
template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, Adjective<sub_mask, Opening, T...> & sub,

			size_type n)
{
//	STATIC_ASSERT

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
template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, Adjective<sub_mask, Open, T...> & sub)
{
//	STATIC_ASSERT

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
template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, Adjective<sub_mask, Open, T...> & sub,

			size_type n)
{
//	STATIC_ASSERT

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


/*
template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, TAdjective<T, Association::deallocate, Association::Segment> & sub)

	{ memory_action(sub); }


template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer & origin, sub_pointer end, const Adjective<sub_mask, AllocateSegment, T...> & sub)
{
	Adjective<sub_mask, MutateSegment, T...> sub_mutate;

	return repeat(ad, memory_action(origin, sub), end, sub_mutate);
}


template<PARAMETERS>
static sub_pointer repeat(Adverb<verb_mask, Prototype, F...> & ad,

			sub_pointer & origin, const Adjective<sub_mask, AllocateSegment, T...> & sub,

			size_type n)
{
	Adjective<sub_mask, MutateSegment, T...> sub_mutate;

	return repeat(ad, memory_action(origin, sub), sub_mutate, n);
}
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef PARAMETERS
#undef STATIC_ASSERT


