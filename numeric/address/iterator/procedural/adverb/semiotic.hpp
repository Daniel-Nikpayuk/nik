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


template<size_type mask, typename... params>
struct adverb;


template<size_type mask>
struct adverb<mask> { static constexpr size_type bitmask = mask; };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<Connotation... params>
using adv_list = typename parameter<Connotation>::template list<params...>;

using null_adv = adv_list<>;


template<Connotation... params>
using adv_cast = typename bit::mask::template cast<adv_list<params...>>;

// "using" for polymorphic dispatching.

template<Connotation... params>
using Adverb = adverb<adv_cast<params...>::rtn>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


static constexpr size_type ApplyFunctor = adv_cast<Connotation::apply_functor>::rtn;


static constexpr size_type ApplyCount = adv_cast<Connotation::apply_count>::rtn;


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<typename F>
struct adverb<ApplyFunctor, F>
{
	static constexpr size_type bitmask = ApplyFunctor;

	F functor;

	adverb(const F & f) : functor(f) { }
};


template<typename Filler>
struct adverb<ApplyCount, Filler>
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


