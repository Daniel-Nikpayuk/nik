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


template<typename... params>
struct adverb;


template<typename L>
struct adverb<L> { using parameter_list = L; };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<Connotation... params>
using adv_list = typename parameter<Connotation>::template list<params...>;

using null_adv = adv_list<>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


using ApplyFunctor = adv_list<Connotation::apply_functor>;


using ApplyCount = adv_list<Connotation::apply_count>;


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<typename F>
struct adverb<ApplyFunctor, F>
{
	using parameter_list = ApplyFunctor;

	F functor;

	adverb(const F & f) : functor(f) { }
};


template<typename T>
struct adverb<ApplyCount, T>
{
	using parameter_list = ApplyCount;

	T count;

	adverb(const T & c) : count(c) { }
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


/************************************************************************************************************************
							3
************************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


