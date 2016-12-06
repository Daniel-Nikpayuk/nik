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


//#include"../body/peek_action.hpp"
#include"../body/main_action.hpp"
#include"../body/count_action.hpp"
#include"../body/iterate_action.hpp"
//#include"../body/memory_action_in.hpp"


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(_adverb<LIST<functorEnum, tracerEnum, Connotation::prototype>, F> & ad,

	sub_pointer out,

	const _adjective<LIST<sub_directionEnum, Association::closing, sub_imageEnum, sub_iteratorEnum>> & sub,

	ob_pointer in, ob_pointer end,

	const _adjective<LIST<ob_directionEnum, Association::closing, ob_imageEnum, ob_iteratorEnum>> & ob)
{
	while (in != end)
	{
		main_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}


/*
	allocate, segment:
*/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(_adverb<LIST<functorEnum, tracerEnum, Connotation::prototype>, F> & ad,

	sub_pointer & origin,

	const _adjective<LIST<sub_directionEnum, Association::closing, Association::allocate, Association::segment>> & sub,

	ob_pointer in, ob_pointer end,

	const _adjective<LIST<ob_directionEnum, Association::closing, ob_imageEnum, ob_iteratorEnum>> & ob)
{
	using value_type = typename structural<nik::semiotic>::template trim<sub_pointer>::pointer::value_type;
	origin = new value_type[sub.length];
	size_type offset = (sub_directionEnum == Association::forward) ? sub.offset : sub.length - 1 - sub.offset;
	sub_pointer out = origin + offset;

	while (in != end)
	{
		main_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}


