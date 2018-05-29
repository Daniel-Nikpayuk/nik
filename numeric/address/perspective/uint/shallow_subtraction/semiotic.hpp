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

template
<
	size_type reg_length,
	typename sub_policy,
	typename ob_policy,

	Performance performance = Performance::specification

> struct shallow_subtraction;

/*
*/

template
<
	size_type reg_length,
	typename sub_policy,
	typename ob_policy

> struct shallow_subtraction
<
	reg_length,
	sub_policy,
	ob_policy,
	Performance::specification
>
{
	using reg_type					= typename byte_type<reg_length>::reg_type;

	using uint_map_shallow_subtraction		= map_shallow_subtraction<reg_length, sub_policy, ob_policy>;

	//

	using generic					= typename Power::generic;

/*
*/

	template<typename sub_type, typename ob_type>
	static sub_type subtract(reg_type & c, sub_type sub, ob_type ob, ob_type end)
	{
		uint_map_shallow_subtraction umss(c);

		return generic::map(umss, sub, ob, end);
	}
};

/*
*/

template
<
	size_type reg_length,
	typename sub_policy,
	typename ob_policy

> struct shallow_subtraction
<
	reg_length,
	sub_policy,
	ob_policy,
	Performance::optimization
>
{
};

