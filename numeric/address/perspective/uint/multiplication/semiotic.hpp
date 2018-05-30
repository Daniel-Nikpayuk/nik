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
	typename sub_adjective

> struct multiplication
<
	reg_length,
	Performance::specification,
	sub_adjective
>
{
	using reg_type					= typename byte_type<reg_length>::reg_type;

	using uint_map_scalar_multiply_assign		= map_scalar_multiply_assign<reg_length, sub_adjective>;

	//

	using generic					= typename Power::generic;

/*
*/

	template<typename sub_type>
	static void multiply(reg_type & c, sub_type sub, sub_type end, reg_type s)
	{
		uint_map_scalar_multiply_assign umsma(c, s);

		generic::map(umsma, sub, end);
	}
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective

> struct multiplication
<
	reg_length,
	Performance::optimization,
	sub_adjective
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
	typename ob_adjective

> struct multiplication
<
	reg_length,
	Performance::specification,
	sub_adjective,
	ob_adjective
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using uint_map_scalar_multiply		= map_scalar_multiply<reg_length, sub_adjective, ob_adjective>;

	//

	using generic				= typename Power::generic;

/*
*/

	template<typename sub_type, typename ob_type>
	static sub_type multiply(reg_type & c, sub_type sub, ob_type ob, ob_type end, reg_type s)
	{
		uint_map_scalar_multiply umsm(c, s);

		return generic::map(umsm, sub, ob, end);
	}
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct multiplication
<
	reg_length,
	Performance::optimization,
	sub_adjective,
	ob_adjective
>
{
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob2_adjective,
	typename ob1_adjective,
	typename ob_adjective

> struct multiplication
<
	reg_length,
	Performance::specification,
	sub_adjective,
	ob2_adjective,
	ob1_adjective,
	ob_adjective
>
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

					  template<typename ob2_type, typename ob1_type, typename sub_type>
	using uint_map_multiply		= map_multiply
					<
						reg_length,
						sub_adjective, ob2_adjective, ob1_adjective, ob_adjective,
						ob2_type, ob1_type, sub_type
					>;

	//

	using generic			= typename Power::generic;

/*
*/

	template<typename sub_type, typename ob2_type, typename ob1_type, typename ob_type>
	static sub_type
	multiply(reg_type & c, sub_type sub, ob2_type ob2, ob2_type end2, ob1_type ob1, ob1_type end1, ob_type ob, ob_type end)
	{
		uint_map_multiply<ob2_type, ob1_type, sub_type> umm(c, ob2, end2, end1, sub);

		return generic::map(umm, ob2, ob1, ob, end);
	}
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob2_adjective,
	typename ob1_adjective,
	typename ob_adjective

> struct multiplication
<
	reg_length,
	Performance::optimization,
	sub_adjective,
	ob2_adjective,
	ob1_adjective,
	ob_adjective
>
{
};

