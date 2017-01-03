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


	while (omit_peek())												\
	{														\
		functor_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\


/***********************************************************************************************************************/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	size_type optimizerEnum,

	typename sub_pointer,
	typename ob_pointer,
	typename F
>
static void fcoi_loop(const _adverb<LIST<Connotation::omit_functor, Connotation::omit_count, optimizerEnum>, F> & ad, sub_pointer out, ob_pointer in)
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
static void functor_action(const _adverb<LIST<Connotation::apply_functor, tracerEnum, optimizerEnum>, F> & ad, sub_pointer out, ob_pointer in)
static void count_action(_adverb<LIST<functorEnum, Connotation::apply_count, optimizerEnum>, F> & ad)
{
	ad.functor(out, in);
	++ad.count;
}



/***********************************************************************************************************************/




