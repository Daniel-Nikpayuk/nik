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

#include"body/declare_variables.hpp"

template
<
	typename sAdjective,
	typename oAdjective,
	typename AdAdverb,
	size_type sInterval = sAdjective::traits::interval_enum,
	size_type oInterval = oAdjective::traits::interval_enum
>
struct prototype { };


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<typename sAdjective, typename oAdjective, typename Adverb>
struct prototype<sAdjective, oAdjective, Adverb, ModIterator::closing, ModIterator::closing>
{
	typedef typename sAdjective::traits s_traits;
	typedef typename oAdjective::traits o_traits;
	typedef typename Adverb::policy policy;

	typedef typename s_traits::return_type return_type;

	static return_type map(const sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		return_type subject;

		declare_variables<s_traits>(subject, const_subject);

/*
		while (omit_peek(object))
		{
			main_action<template_policy, arity_policy>(subject, object);
			count_action<count_policy>(verb);

			iterate_out<out_direction, out_memory, out_pointer>(subject);
			iterate_in<in_direction, in_memory, in_pointer, arity_policy>(object);
		}

		undeclare_variables<in_memory, in_pointer, arity_policy>(object);
*/

		return subject;
	}
};


