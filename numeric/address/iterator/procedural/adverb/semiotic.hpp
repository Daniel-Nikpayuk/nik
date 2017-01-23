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
	Connotations and Manners of "{omit, apply} functor" are implicit in the build and it is tempting to minimize,
	but 1) This is bad design because I would be relying on an implementation feature to enforce specification design,
	2) Without explicitly specifying them, the compiler cannot distinguish the partial specializations below.
*/



enum struct Connotation : size_type
{
	omit_functor,
	apply_functor,

	omit_count,
	apply_count,

	after,
	before,
	between,

	prototype,
	specialize,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


using bit = typename bitmask::template bit<Connotation>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type bitmask, typename F> struct Adverb;
// { static_assert(true, "this variant is not implemented."); }; // should be false.


/************************************************************************************************************************
							1
***********************************************************************************************************************/


template<typename F> struct Adverb<0, F> { static constexpr size_type bitmask = 0; };


/***********************************************************************************************************************/

static constexpr size_type ApplyFunctor	= bit::template list_cast<Connotation::apply_functor>::rtn;
static constexpr size_type ApplyCount	= bit::template list_cast<Connotation::apply_count>::rtn;

template<typename F>
struct Adverb<ApplyFunctor, F>
{
	static constexpr size_type bitmask = ApplyFunctor;

	F functor;

	Adverb(const F & f) : functor(f) { }
};


template<typename Filler>
struct Adverb<ApplyCount, Filler>
{
	static constexpr size_type bitmask = ApplyCount;

	size_type count;

	Adverb(const size_type & c) : count(c) { }
};


/************************************************************************************************************************
							2
***********************************************************************************************************************/


static constexpr size_type ApplyApply	= bit::template list_cast<Connotation::apply_functor, Connotation::apply_count>::rtn;
static constexpr size_type ApplyOmit	= bit::template list_cast<Connotation::apply_functor, Connotation::omit_count>::rtn;

template<typename F>
struct Adverb<ApplyApply, F> :

		public Adverb<ApplyFunctor, F>,
		public Adverb<ApplyCount, void>
{
	static constexpr size_type bitmask = ApplyApply;

	Adverb(const F & f, size_type c) :

			Adverb<ApplyFunctor, F>(f),
			Adverb<ApplyCount, void>(c)

		{ }
};


template<typename F>
struct Adverb<ApplyOmit, F> :

		public Adverb<ApplyFunctor, F>
{
	static constexpr size_type bitmask = ApplyOmit;

	Adverb(const F & f) :

			Adverb<ApplyFunctor, F>(f)

		{ }
};


static constexpr size_type OmitApply	= bit::template list_cast<Connotation::omit_functor, Connotation::apply_count>::rtn;
static constexpr size_type OmitOmit	= bit::template list_cast<Connotation::omit_functor, Connotation::omit_count>::rtn;


template<typename Filler>
struct Adverb<OmitApply, Filler> :

		public Adverb<ApplyCount, void>
{
	static constexpr size_type bitmask = OmitApply;

	template<typename F>
	static Adverb<ApplyApply, F> as(const F & f)
	{
		return Adverb<ApplyApply, F> (f);
	}
};


template<typename Filler>
struct Adverb<OmitOmit, Filler>
{
	static constexpr size_type bitmask = OmitOmit;

	template<typename F>
	static Adverb<ApplyOmit, F> as(const F & f)
	{
		return Adverb<ApplyOmit, F> (f);
	}

	template<typename F>
	static Adverb<ApplyApply, F> as(const F & f, size_type c)
	{
		return Adverb<ApplyApply, F>(f, c);
	}
};


/************************************************************************************************************************
							3
***********************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type bitmask, typename... params>
using dispatch = typename bit::template pattern<bitmask>::template dispatch<params...>;

template<size_type bitmask, typename F = void>
struct Adverb : public dispatch
<
	bitmask,

	Adverb<OmitOmit, F>,
	Adverb<OmitApply, F>,

	Adverb<0, F>

>::rtn { };


