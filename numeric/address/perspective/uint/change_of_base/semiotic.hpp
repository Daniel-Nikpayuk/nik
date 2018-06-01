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

/*
	Concept:

	The number of digits required for the numeral character array.

	log(2^64N) == 64N*lg(2)/lg(10) == 64N/(1+lg(5)) < 20N
*/

/***********************************************************************************************************************/

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct change_of_base
<
	reg_length,
	Performance::specification,
	sub_adjective,
	ob_adjective
>
{
	using reg_type					= typename byte_type<reg_length>::reg_type;

	//

							  template<typename ob_type>
	using uint_map_half_change_base			= map_half_change_base
							<
								reg_length,
								sub_adjective, ob_adjective,
								ob_type
							>;

	//

	using generic					= typename Power::generic;

		// change base:

/*
	ob1_type, ob_type are assumed to be temporary memory.

	Specification requires ob to have a right closed interval to work properly.
*/
	struct half_type
	{
		template<typename sub_type, typename ob_type>
		static sub_type change_base(sub_type sub, ob_type ob, ob_type end, reg_type d = 10)
		{
			uint_map_half_change_base<ob_type> umhcb(end, d);
		
			return generic::map(umhcb, sub, ob, end);
		}
	};
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct change_of_base
<
	reg_length,
	Performance::optimization,
	sub_adjective,
	ob_adjective
>
{
};

