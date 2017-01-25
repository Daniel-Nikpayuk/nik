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


/***********************************************************************************************************************/


template
<
	typename sub_pointer
>
static inline void functor_action(const Adverb_OmitFunctor & ad, sub_pointer p)
	{ }


/***********************************************************************************************************************/


template
<
	typename sub_pointer,
	typename ob_value_type,

	size_type mask,
	typename... A
>
static inline void functor_action(const Adverb_OmitFunctor & ad, sub_pointer out, ob_value_type in, const EnumAdjective<mask, A...> & ob)
{
	*out = in;
}


/***********************************************************************************************************************/


template
<
	typename sub_pointer,
	typename ob_pointer,

	size_type mask,
	typename... T
>
static inline void functor_action(const Adverb_OmitFunctor & ad, sub_pointer out, ob_pointer in, const Adjective<mask, T...> & ob)
{
	*out = *in;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	size_type mask,
	typename F,

	typename sub_pointer
>
static inline void functor_action(const Adverb<mask, ApplyFunctor, F> & ad, sub_pointer p)
{
	ad.functor(p);
}


/***********************************************************************************************************************/


/*
	Adjective == EnumAdjective<L> || Adjective<L, T>
*/


template
<
	size_type mask,
	typename F,
	typename sub_pointer,
	typename ob_pointer,
	typename Adjective
>
static inline void functor_action(const Adverb<mask, ApplyFunctor, F> & ad, sub_pointer out, ob_pointer in, const Adjective & ob)
{
	ad.functor(out, in);
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


