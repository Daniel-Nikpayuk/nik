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
	typename verb_mask,												\
	typename... F,													\
															\
	typename sub_pointer,												\
															\
	typename sub_mask,												\
	typename... T


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	tuple/list data structures are appropriate here because resolution
	occurs during compile-time and the size is expected to be small.

	When dispatches are properly partitioned, there is no need for a match error.
*/


struct Repeat
{
	using Selection = tuple
	<
		tone<Connotation::omit_functor, Connotation::apply_functor>,		// functor
		tone<Connotation::omit_count, Connotation::apply_count>,		// tracer
		tone<Connotation::prototype, Connotation::specialize>			// optimizer
	>;

/***********************************************************************************************************************/

	template<typename mask, typename... params>
	struct adverb;

	template<typename mask, typename F>
	struct adverb<mask, F> :

			public monovalent_functor_F<mask, F>,
			public count<mask>

	{
		adverb(const F & f) : monovalent_functor_F<mask, F>(f) { }
	};

	template<typename mask>
	struct adverb<mask> :

			public monovalent_functor<mask>,
			public count<mask>

		{ };

/***********************************************************************************************************************/

	template<typename mask, typename F>
	using functor_adverb = adverb<functor_cast<mask>, F>;

	template<typename mask, typename F>
	static functor_adverb<mask, F> apply_functor(const adverb<mask> &, const F & f)
	{
		return functor_adverb<mask, F>(f);
	}

	template<typename mask>
	using tracer_adverb = adverb<tracer_cast<mask>>;

	template<typename mask>
	static tracer_adverb<mask> apply_count(const adverb<mask> &, const size_type & c)
	{
		return tracer_adverb<mask>(c);
	}

/***********************************************************************************************************************/

	template<Connotation... params>
	using verb = adverb
	<
		typename parameter<Connotation>::
		template list<params...>::modified::type::
		template fill<Selection>::type
	>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	using Arrangement = tuple
	<
		echo<Association::forward, Association::backward>,						// direction
		echo<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
		echo<Association::mutate, Association::allocate, Association::deallocate>,			// image
		echo<Association::segment, Association::hook, Association::link>				// iterator
	>;

/***********************************************************************************************************************/

	template<typename mask, typename... params>
	struct adjective;

	template<typename mask, typename T>
	struct adjective<mask, T> :

			public iterate<mask>,
			public valent_memory_T<mask, T>

	{
		adjective(T *o) : valent_memory_T<mask, T>(o) { }
	};

	template<typename mask>
	struct adjective<mask> :

			public iterate<mask>,
			public valent_memory<mask>,
			public allo_monovalent_memory<mask>,
			public deallo_monovalent_memory<mask>

	{
		adjective() : valent_memory<mask>(), allo_monovalent_memory<mask>(), deallo_monovalent_memory<mask>() { }
		adjective(size_type l, size_type o) : allo_monovalent_memory<mask>(l, o) { }
	};

/***********************************************************************************************************************/

	template<typename mask>
	using mutate_adjective = adjective<mutate_cast<mask>>;

	template<typename mask>
	static mutate_adjective<mask> mutate(const adjective<mask> &)
	{
		return mutate_adjective<mask>();
	}

/***********************************************************************************************************************/

	template<typename mask>
	using allocate_adjective = adjective<allocate_cast<mask>>;

	template<typename mask>
	static allocate_adjective<mask> allocate_segment(const adjective<mask> &, size_type l, size_type o = 0)
	{
		return allocate_adjective<mask>(l, o);
	}

/***********************************************************************************************************************/

	template<typename mask, typename T>
	using deallocate_adjective = adjective<deallocate_cast<mask>, T>;

	template<typename mask, typename T>
	static deallocate_adjective<mask, T> deallocate_segment(const adjective<mask> &, T *o)
	{
		return deallocate_adjective<mask, T>(o);
	}

/***********************************************************************************************************************/

/*
	template<Association... params>
	using subject = adjective
	<
		typename echo<params...>::template sortFill<Arrangement>::type,
	>;
*/
};


/*
template<size_type mask, size_type base, typename... params>
using RepeatVerb = typename Repeat::template adverb<mask, base, params...>;

template<size_type mask, size_type base, typename... params>
using RepeatSubject = typename Repeat::template adjective<mask, base, params...>;
*/


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


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[out, end)
*/


/*
template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, Closing, T...> & sub)
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


/*
	Constraints:

	[out, out + n)
*/


/*
template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, RepeatSubject<sub_mask, Closing, T...> & sub,

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
template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, Closed, T...> & sub)
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
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, RepeatSubject<sub_mask, Closed, T...> & sub,

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
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, Opening, T...> & sub)
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
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, RepeatSubject<sub_mask, Opening, T...> & sub,

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
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, Open, T...> & sub)
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
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, RepeatSubject<sub_mask, Open, T...> & sub,

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
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer & origin, sub_pointer end, const RepeatSubject<sub_mask, AllocateSegment, T...> & sub)
{
	auto sub_mutate = Repeat::mutate(sub);

	return repeat(ad, memory_action(origin, sub), end, sub_mutate);
}


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer & origin, const RepeatSubject<sub_mask, AllocateSegment, T...> & sub,

			size_type n)
{
	auto sub_mutate = Repeat::mutate(sub);

	return repeat(ad, memory_action(origin, sub), sub_mutate, n);
}


template<PARAMETERS>
static sub_pointer repeat(RepeatVerb<verb_mask, Prototype, F...> & ad,

			sub_pointer out, sub_pointer end, RepeatSubject<sub_mask, DeallocateSegment, T...> & sub)

	{ memory_action(sub); }
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef PARAMETERS
#undef STATIC_ASSERT


