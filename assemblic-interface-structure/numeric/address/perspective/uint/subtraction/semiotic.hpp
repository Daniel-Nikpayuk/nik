/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

> struct subtraction
<
	reg_length,
	Performance::specification,
	sub_adjective,
	ob_adjective
>
{
	using reg_type					= typename byte_type<reg_length>::reg_type;

	using uint_map_subtract_assign			= map_subtract_assign<reg_length, sub_adjective, ob_adjective>;

	//

	using generic					= typename Power::generic;

/*
*/

	template<typename sub_type, typename ob_type>
	static sub_type subtract(reg_type & c, sub_type sub, ob_type ob, ob_type end)
	{
		uint_map_subtract_assign umsa(c);

		return generic::map(umsa, sub, ob, end);
	}
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct subtraction
<
	reg_length,
	Performance::optimization,
	sub_adjective,
	ob_adjective
>
{
};

/***********************************************************************************************************************/

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob1_adjective,
	typename ob_adjective

> struct subtraction
<
	reg_length,
	Performance::specification,
	sub_adjective,
	ob1_adjective,
	ob_adjective
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using uint_map_subtract			= map_subtract<reg_length, sub_adjective, ob1_adjective, ob_adjective>;

	//

	using generic				= typename Power::generic;

/*
*/

	template<typename sub_type, typename ob1_type, typename ob_type>
	static sub_type subtract(reg_type & c, sub_type sub, ob1_type ob1, ob_type ob, ob_type end)
	{
		uint_map_subtract ums(c);

		return generic::map(ums, sub, ob1, ob, end);
	}
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob1_adjective,
	typename ob_adjective

> struct subtraction
<
	reg_length,
	Performance::optimization,
	sub_adjective,
	ob1_adjective,
	ob_adjective
>
{
};

