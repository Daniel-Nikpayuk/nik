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
	typename subject,
	typename object,
	typename verb,
	size_type outInterval = subject::traits::interval_enum,
	size_type inInterval = object::traits::interval_enum
>
struct prototype { };



/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<typename subject, typename object, typename verb>
struct prototype<subject, object, verb, ModIterator::closing, ModIterator::closing>
{
	typedef typename subject::traits s_traits;
	typedef typename object::traits o_traits;
	typedef typename verb::policy v_policy;

	typedef typename s_traits::return_type return_type;

	static return_type map(const subject & const_s, object & o, verb & v)
	{
		return_type s;

		declare_variables<s_traits>(s, const_s);

/*
		while (omit_peek(o))
		{
			main_action<template_policy, arity_policy>(s, o);
			count_action<count_policy>(v);

			iterate_out<out_direction, out_memory, out_pointer>(s);
			iterate_in<in_direction, in_memory, in_pointer, arity_policy>(o);
		}

		undeclare_variables<in_memory, in_pointer, arity_policy>(o);
*/

		return s;
	}
};


