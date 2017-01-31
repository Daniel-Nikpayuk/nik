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


template
<
	typename sub_pointer
>
static inline void functor_action(const adverb<OmitFunctor> & ad, sub_pointer p)
	{ }


/***********************************************************************************************************************/


template
<
	typename sub_pointer,
	typename ob_value_type
>
static inline void enum_functor_action(const adverb<OmitFunctor> & ad, sub_pointer out, ob_value_type in)
{
	*out = in;
}


template
<
	typename sub_pointer,
	typename ob_pointer,

	size_type mask
>
static inline void functor_action(const adverb<OmitFunctor> & ad, sub_pointer out, ob_pointer in)
{
	*out = *in;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template
<
	typename sub_pointer,
	typename F
>
static inline void functor_action(const adverb<ApplyFunctor, F> & ad, sub_pointer p)
{
	ad.functor(p);
}


/***********************************************************************************************************************/


template
<
	typename F,
	typename sub_pointer,
	typename ob_pointer
>
static inline void enum_functor_action(const adverb<ApplyFunctor, F> & ad, sub_pointer out, ob_pointer in)
{
	ad.functor(out, in);
}


template
<
	typename F,
	typename sub_pointer,
	typename ob_pointer
>
static inline void functor_action(const adverb<ApplyFunctor, F> & ad, sub_pointer out, ob_pointer in)
{
	ad.functor(out, in);
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask>
using functor = typename dispatch
<
	mask,

	adverb<OmitFunctor>

>::rtn;

template<size_type mask, typename F>
using functor_F = typename dispatch
<
	mask,

	adverb<ApplyFunctor, F>

>::rtn;


