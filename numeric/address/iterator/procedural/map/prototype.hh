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
#include"body/peek_action.hpp"
#include"body/main_action.hpp"
#include"body/count_action.hpp"
#include"body/iterate_out.hpp"
#include"body/iterate_in.hpp"
#include"body/undeclare_variables.hpp"

template
<
	typename const_sAdjective,
	typename oAdjective,
	typename AdAdverb,

	size_type sInterval = const_sAdjective::traits::interval_enum,
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


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closing, ModIterator::closing>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


