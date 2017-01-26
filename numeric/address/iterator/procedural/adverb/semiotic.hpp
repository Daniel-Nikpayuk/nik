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


enum struct Manner : size_type
{
	functor,
	tracer,
	fixer,
	optimizer,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


using bitmask = typename bit::template bitmask<Connotation>;

template<Connotation... params>
using list_cast = typename bitmask::template list_cast<params...>;

template<size_type mask>
using pattern = typename bitmask::template pattern<mask>;

template<size_type mask, size_type... params>
using match = typename pattern<mask>::template match<params...>;

template<size_type mask, typename... params>
using dispatch = typename pattern<mask>::template dispatch<params...>;

template<size_type base, size_type mask>
using apply = typename pattern<base>::template apply<mask>;

template<size_type mask, size_type base>
using deduct = typename pattern<mask>::template deduct<base>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							functor
************************************************************************************************************************/


static constexpr size_type		OmitFunctor

= list_cast
<
	Connotation::omit_functor

>::rtn;

static constexpr size_type		ApplyFunctor

= list_cast
<
	Connotation::apply_functor

>::rtn;

static constexpr size_type		OmitOmit

= list_cast
<
	Connotation::omit_functor,
	Connotation::omit_count

>::rtn;

static constexpr size_type		OmitApply

= list_cast
<
	Connotation::omit_functor,
	Connotation::apply_count

>::rtn;

static constexpr size_type		ApplyOmit

= list_cast
<
	Connotation::apply_functor,
	Connotation::omit_count

>::rtn;

static constexpr size_type		ApplyApply

= list_cast
<
	Connotation::apply_functor,
	Connotation::apply_count

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Functor

= list_cast
<
	Connotation::omit_functor,
	Connotation::apply_functor

>::rtn;


/************************************************************************************************************************
							tracer
************************************************************************************************************************/


static constexpr size_type		OmitCount

= list_cast
<
	Connotation::omit_count

>::rtn;

static constexpr size_type		ApplyCount

= list_cast
<
	Connotation::apply_count

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Tracer

= list_cast
<
	Connotation::omit_count,
	Connotation::apply_count

>::rtn;


/************************************************************************************************************************
							fixer
************************************************************************************************************************/


static constexpr size_type		Fixer

= list_cast
<
	Connotation::after,
	Connotation::before,
	Connotation::between

>::rtn;


/************************************************************************************************************************
							optimizer
************************************************************************************************************************/


static constexpr size_type		Prototype

= list_cast
<
	Connotation::prototype

>::rtn;

static constexpr size_type		Specialize

= list_cast
<
	Connotation::specialize

>::rtn;

/***********************************************************************************************************************/

static constexpr size_type		Optimizer

= list_cast
<
	Connotation::prototype,
	Connotation::specialize

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename... params>
struct adverb;


template<size_type mask>
struct adverb<mask> { static constexpr size_type bitmask = mask; };


// "using" for polymorphic dispatching.


template<Connotation... params>
using Adverb = adverb<list_cast<params...>::rtn>;


template<typename F, Connotation... params>
using FAdverb = adverb<list_cast<params...>::rtn, F>;


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<size_type mask>
struct adverb<mask, adverb<OmitFunctor> >
{
	static constexpr size_type bitmask = OmitFunctor;
	static constexpr size_type functor_mask = apply< deduct<mask, Functor>::rtn, ApplyFunctor>::rtn;
	static constexpr size_type Optimizer = match<mask, Prototype, Specialize>::rtn;

	template<typename F>
	static adverb<functor_mask, adverb<Optimizer>, F> cast(const F & f)
	{
		return adverb<functor_mask, adverb<Optimizer>, F>(f);
	}
};


template<typename F>
struct adverb<ApplyFunctor, F>
{
	static constexpr size_type bitmask = ApplyFunctor;

	F functor;

	adverb(const F & f) : functor(f) { }
};


template<size_type mask>
struct adverb<mask, adverb<OmitCount> >
{
	static constexpr size_type bitmask = OmitCount;
	static constexpr size_type tracer_mask = apply< deduct<mask, Tracer>::rtn, ApplyCount>::rtn;
	static constexpr size_type Optimizer = match<mask, Prototype, Specialize>::rtn;

	static adverb<tracer_mask, adverb<Optimizer> > cast(const size_type & c)
	{
		return adverb<tracer_mask, adverb<Optimizer> >(c);
	}
};


template<size_type mask>
struct adverb<mask, adverb<ApplyCount> >
{
	static constexpr size_type bitmask = ApplyCount;

	size_type count;

	adverb(const size_type & c) : count(c) { }
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


/************************************************************************************************************************
							3
************************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using DispatchError = typename structural<Interface::semiotic>::template DispatchError<mask>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using dispatch_fixer = typename dispatch
<
	mask,

	adverb<Fixer>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using dispatch_functor = typename dispatch
<
	mask,

	adverb<mask, adverb<OmitFunctor> >,

	DispatchError<mask>

>::rtn;


template<size_type mask, typename F>
using dispatch_functor_F = typename dispatch
<
	mask,

	adverb<ApplyFunctor, F>,

	DispatchError<mask>

>::rtn;


template<size_type mask>
using dispatch_tracer = typename dispatch
<
	mask,

	adverb<OmitCount>,
	adverb<mask, adverb<ApplyCount> >,

	DispatchError<mask>

>::rtn;


// partition implies no need for a default value.

template<size_type mask>
struct adverb<mask, adverb<Prototype> > :

		public dispatch_functor<mask>,
		public dispatch_tracer<mask>

{
	static constexpr size_type bitmask = Prototype;
};


template<size_type mask, typename F>
struct adverb<mask, adverb<Prototype>, F> :

		public dispatch_functor_F<mask, F>,
		public dispatch_tracer<mask>

{
	static constexpr size_type bitmask = Prototype;

	adverb(const F & f) : dispatch_functor_F<mask, F>(f) { }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename... params>
struct optimizer;


// partition implies no need for a default value.


template<size_type mask>
struct optimizer<mask> : public dispatch
<
	mask,

	adverb<mask, adverb<Prototype> >//,
//	adverb<mask, adverb<Specialize> >,

//	DispatchError<mask>

>::rtn { };


template<size_type mask, typename F>
struct optimizer<mask, F> : public dispatch
<
	mask,

	adverb<mask, adverb<Prototype>, F>,
	adverb<mask, adverb<Specialize>, F>,

	DispatchError<mask>

>::rtn
{
	optimizer(const F & f) : dispatch_functor_F<mask, F>(f) { }
};


