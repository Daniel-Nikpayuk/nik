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
							open
************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
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
	iterate_action(in, ob<mutate>);
	iterate_action(out, sub);

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}
*/


