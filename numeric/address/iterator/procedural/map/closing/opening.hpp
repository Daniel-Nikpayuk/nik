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


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


/*
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
static sub_pointer map(ADV_PROTOTYPE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob)
{
	while (in != end)
	{
		iterate_action(in, ob);

		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
	}

	return out;
}
*/


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


/*
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closing, Association::opening, Association::deallocate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate<ob_adjective, Association::mutate>::apply(variables);

		while (in != end)
		{
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate<sub_adjective>::apply(out);
			iterate<ob_adjective, Association::deallocate>::apply(variables);
		}

		functor_action<sub_adjective, ob_adjective>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate<sub_adjective>::apply(out);
		memory_action_in<ob_adjective, Association::deallocate>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


