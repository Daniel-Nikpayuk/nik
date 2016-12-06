/************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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


#define OMIT	LIST<Connotation::omit_functor, tracerEnum, optimizerEnum>
#define APPLY	LIST<Connotation::apply_functor, tracerEnum, optimizerEnum>


/***********************************************************************************************************************/


template
<
	size_type tracerEnum,
	size_type optimizerEnum,

	typename sub_pointer,
	typename ob_pointer
>
static inline void functor_action(const _adverb<OMIT> & ad, sub_pointer out, ob_pointer in)
{
	*out = *in;
}


/***********************************************************************************************************************/


template
<
	size_type tracerEnum,
	size_type optimizerEnum,
	typename F,

	typename sub_pointer,
	typename ob_pointer
>
static void functor_action(const _adverb<APPLY, F> & ad, sub_pointer out, ob_pointer in)
{
	ad.functor(out, in);
}


/***********************************************************************************************************************/


template
<
	size_type tracerEnum,
	size_type optimizerEnum,
	typename F,

	typename sub_pointer,
	typename ob_pointer
>
static void functor_action(const _adverb<APPLY, F> & ad, sub_pointer out, ob_pointer in, ob_pointer in1)
{
	ad.functor(out, in, in1);
}


/***********************************************************************************************************************/


#undef APPLY
#undef OMIT


