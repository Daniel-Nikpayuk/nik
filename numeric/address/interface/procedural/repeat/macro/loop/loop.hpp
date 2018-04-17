/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	size_type tracerEnum,
	size_type optimizerEnum,

	typename sub_pointer,
	typename ob_pointer
>
static void main_action(const _adverb<LIST<Connotation::omit_functor, tracerEnum, optimizerEnum>> & ad, sub_pointer out, ob_pointer in)
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
static void main_action(const _adverb<LIST<Connotation::apply_functor, tracerEnum, optimizerEnum>, F> & ad, sub_pointer out, ob_pointer in)
{
	ad.functor(out, in);
}


void loop()
{
}

/***********************************************************************************************************************/

	while (omit_peek())												\
	{														\
		iterate_out(out_direction, out_memory, out_pointer)							\
															\
		functor_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\

/***********************************************************************************************************************/

	while (omit_peek())												\
	{														\
		iterate_in(in_direction, mutate, in_pointer, arity_policy)						\
															\
		functor_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
	}														\

/***********************************************************************************************************************/

	while (omit_peek())												\
	{														\
		iterate_in(in_direction, mutate, in_pointer, arity_policy)						\
		iterate_out(out_direction, out_memory, out_pointer)							\
															\
		functor_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
	}														\

/***********************************************************************************************************************/

	while (apply_peek(in_direction, in_pointer))									\
	{														\
		functor_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\

