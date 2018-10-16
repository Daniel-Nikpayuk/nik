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

	|wn|...|w0| / |y1|y0|, where y1 == 0.

	Don't assume sub_type == ob_type. Their dereferenced reg_types need to match,
	but otherwise higher entropy is maintained by allowing their containers to differ.
*/

/*
	We tether the interval decomposition to the while loop,
	meaning [) is most natural, so then our decomposition is as follows:

	closing	|a <= b|:	[a, b)		= [a, b)
	closed	|a <= b|:	[a, b]		= [a, b)	-> [b]
	open	|a <  b|:	(a, b)		= (a)		-> [a+1, b)
	opening	|a <  b|:	(a, b]		= (a)		-> [a+1, b)	-> [b]

	Here (a) implies iterate, while [b] implies act.
*/

/***********************************************************************************************************************/

template
<
	size_type reg_length,
	typename sub_adjective

> struct division
<
	reg_length,
	Performance::specification,
	sub_adjective
>
{
	using reg_type					= typename byte_type<reg_length>::reg_type;

	using uint_map_root_divide_assign		= map_root_divide_assign
							<
								reg_length,
								sub_adjective
							>;

	//

	using generic					= typename Power::generic;

/*
	With the exception of the very first digit, all successor first digits are the remainder
	of the componentwise division, meaning each following first digit is necessarily less than the divisor.
	As such, by adding a "lead" initialized as 0---which also carries the remainder forward,
	we can guarantee the leading digit is always less than the divisor.
*/

	struct root_type
	{
		template<typename sub_type>
		static void divide(reg_type & r, sub_type sub, sub_type end, reg_type d)
		{
			uint_map_root_divide_assign umhda(r, d);

			generic::map(umhda, sub, end);
		}
	};
};

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective

> struct division
<
	reg_length,
	Performance::optimization,
	sub_adjective
>
{
};

/***********************************************************************************************************************/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct division
<
	reg_length,
	Performance::specification,
	sub_adjective,
	ob_adjective
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using uint_map_root_divide		= map_root_divide<reg_length, sub_adjective, ob_adjective>;

	//

	using generic				= typename Power::generic;

/*
	With the exception of the very first digit, all successor first digits are the remainder
	of the componentwise division, meaning each following first digit is necessarily less than the divisor.
	As such, by adding a "lead" initialized as 0---which also carries the remainder forward,
	we can guarantee the leading digit is always less than the divisor.
*/

	struct root_type
	{
		template<typename sub_type, typename ob_type>
		static sub_type divide(reg_type & r, sub_type sub, ob_type ob, ob_type end, reg_type d)
		{
			uint_map_root_divide umhd(r, d);

			return generic::map(umhd, sub, ob, end);
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

> struct division
<
	reg_length,
	Performance::optimization,
	sub_adjective,
	ob_adjective
>
{
};

