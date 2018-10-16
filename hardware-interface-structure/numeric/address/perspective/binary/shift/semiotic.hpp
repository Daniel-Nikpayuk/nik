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
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct shift
<
	reg_length,
	Performance::specification,
	sub_adjective,
	ob_adjective
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using one				= typename Constant::template one<reg_type>;

	//

	using binary_map_shift_left		= map_shift_left
						<
							reg_length,
							sub_adjective,
							sub_adjective,
							ob_adjective
						>;

	using binary_map_shift_right		= map_shift_right
						<
							reg_length,
							sub_adjective,
							sub_adjective,
							ob_adjective
						>;

	//

	using generic				= typename Power::generic;

	//

	template<typename sub_type, typename ob_type>
	static sub_type left(sub_type sub, ob_type ob, ob_type end, reg_type offset)
	{
		binary_map_shift_left bmsl(offset);

		return generic::map(bmsl, sub, ob, ob + one::value, end);
	}

	template<typename sub_type, typename ob_type>
	static sub_type right(sub_type sub, ob_type ob, ob_type end, reg_type offset)
	{
		binary_map_shift_right bmsr(offset);

		return generic::map(bmsr, sub, sub + one::value, ob, end);
	}
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct shift
<
	reg_length,
	Performance::optimization,
	sub_adjective,
	ob_adjective
>
{
};

