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

	This is a very delicate setup---not at all robust---and must follow very strict design rules.

	1) no cross conversion.
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

template<Connotation... params>
using list_cast = typename bit::template list_cast<params...>;

template<size_type mask>
using pattern = typename bit::template pattern<mask>;

template<size_type mask, typename... params>
using match = typename pattern<mask>::template match<params...>;

template<size_type mask, typename S>
using tail = typename pattern<mask>::template tail<S::bitmask>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


struct Prototype
{
	static constexpr size_type bitmask = list_cast
	<
		Connotation::prototype

	>::rtn;
};

struct Specialize
{
	static constexpr size_type bitmask = list_cast
	<
		Connotation::specialize

	>::rtn;
};


struct ApplyFunctor { };
struct ApplyCount { };


struct ApplyApply
{
	static constexpr size_type bitmask = list_cast
	<
		Connotation::apply_functor,
		Connotation::apply_count

	>::rtn;
};

struct ApplyOmit
{
	static constexpr size_type bitmask = list_cast
	<
		Connotation::apply_functor,
		Connotation::omit_count

	>::rtn;
};


struct OmitApply
{
	static constexpr size_type bitmask = list_cast
	<
		Connotation::omit_functor,
		Connotation::apply_count

	>::rtn;
};

struct OmitOmit
{
	static constexpr size_type bitmask = list_cast
	<
		Connotation::omit_functor,
		Connotation::omit_count

	>::rtn;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename... params> struct Adverb;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


struct Adverb_OmitFunctor { };
struct Adverb_OmitCount { };


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<size_type mask, typename F>
struct Adverb<mask, ApplyFunctor, F>
{
	F functor;

	Adverb(const F & f) : functor(f) { }
};

template<size_type mask>
struct Adverb<mask, ApplyCount>
{
	size_type count;

	Adverb(const size_type & c) : count(c) { }
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


template<size_type mask, typename F>
struct Adverb<mask, ApplyApply, F> :

		public Adverb<mask, ApplyFunctor, F>,
		public Adverb<mask, ApplyCount>
{
	static constexpr size_type bitmask = ApplyApply::bitmask;

	Adverb(const F & f, size_type c) :

			Adverb<mask, ApplyFunctor, F>(f),
			Adverb<mask, ApplyCount>(c)

		{ }
};


template<size_type mask, typename F>
struct Adverb<mask, ApplyOmit, F> :

		public Adverb<mask, ApplyFunctor, F>,
		public Adverb_OmitCount
{
	static constexpr size_type bitmask = ApplyOmit::bitmask;

	Adverb(const F & f) :

			Adverb<mask, ApplyFunctor, F>(f)

		{ }
};


template<size_type mask>
struct Adverb<mask, OmitApply> :

		public Adverb<mask, ApplyCount>,
		public Adverb_OmitFunctor
{
	static constexpr size_type bitmask = OmitApply::bitmask;

	static constexpr size_type functor_mask = mask | ApplyOmit::bitmask;

	using Optimizer = typename match<mask, Prototype, Specialize>::rtn;

	template<typename F>
	static Adverb<functor_mask, Optimizer, F> cast(const F & f)
	{
		return Adverb<functor_mask, Optimizer, F>(f);
	}

};


template<size_type mask>
struct Adverb<mask, OmitOmit> :

		public Adverb_OmitFunctor,
		public Adverb_OmitCount
{
	static constexpr size_type bitmask = OmitOmit::bitmask;

	static constexpr size_type functor_mask = mask | ApplyOmit::bitmask;

	using Optimizer = typename match<mask, Prototype, Specialize>::rtn;

	template<typename F>
	static Adverb<functor_mask, Optimizer, F> cast(const F & f)
	{
		return Adverb<functor_mask, Optimizer, F>(f);
	}
};


/************************************************************************************************************************
							3
************************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename S>
using Adverb_Tail = Adverb< tail<mask, S>::rtn, S>;

template<size_type mask, typename S, typename F>
using Adverb_Tail_F = Adverb< tail<mask, S>::rtn, S, F>;

template<size_type mask>
using match_count = typename match
<
	mask,

	Adverb_Tail<mask, OmitOmit>,
	Adverb_Tail<mask, OmitApply>

>::rtn;

template<size_type mask, typename F>
using match_functor = typename match
<
	mask,

	Adverb_Tail_F<mask, ApplyOmit, F>,
	Adverb_Tail_F<mask, ApplyApply, F>

>::rtn;

template<size_type mask>
using match_optimizer = typename match
<
	mask,

	Adverb<mask, Prototype>,
	Adverb<mask, Specialize>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename Optimizer>
struct Adverb<mask, Optimizer> : public match_count<mask>
{
	static constexpr size_type bitmask = Optimizer::bitmask;
};


template<size_type mask, typename Optimizer, typename F>
struct Adverb<mask, Optimizer, F> : public match_functor<mask, F>
{
	static constexpr size_type bitmask = Optimizer::bitmask;

	Adverb(const F & f) : match_functor<mask, F>(f) { }
};


/***********************************************************************************************************************/


template<size_type mask>
struct Adverb<mask> : public match_optimizer<mask> { };


