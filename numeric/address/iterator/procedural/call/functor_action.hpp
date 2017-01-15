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


#define OMIT	adv_list<Connotation::omit_functor>
#define APPLY	adv_list<Connotation::apply_functor>


/***********************************************************************************************************************/


template
<
	typename sub_pointer
>
static inline void functor_action(const Adverb<OMIT> & ad, sub_pointer p)
	{ }


/***********************************************************************************************************************/


template
<
	typename sub_pointer,
	typename ob_pointer,
	typename L
>
static inline void functor_action(const Adverb<OMIT> & ad, sub_pointer out, ob_pointer in, const UIntAdjective<L> & ob)
{
	*out = in;
}


/***********************************************************************************************************************/


template
<
	typename sub_pointer,
	typename ob_pointer,
	typename L,
	typename T
>
static inline void functor_action(const Adverb<OMIT> & ad, sub_pointer out, ob_pointer in, const Adjective<L, T> & ob)
{
	*out = *in;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename F,
	typename sub_pointer
>
static inline void functor_action(const Adverb<APPLY, F> & ad, sub_pointer p)
{
	ad.functor(p);
}


/***********************************************************************************************************************/


/*
	Adjective == UIntAdjective<L> || Adjective<L, T>
*/


template
<
	typename F,
	typename sub_pointer,
	typename ob_pointer,
	typename Adjective
>
static inline void functor_action(const Adverb<APPLY, F> & ad, sub_pointer out, ob_pointer in, const Adjective & ob)
{
	ad.functor(out, in);
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef APPLY
#undef OMIT


