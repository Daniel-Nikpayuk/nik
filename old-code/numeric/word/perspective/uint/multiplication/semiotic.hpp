/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	if 1 < base, then 0 < base-1.
	Since -1 < 1, then base-1 < base+1.
	Hence (base-1)^2 < base^2-1.
	Thus carry < base^2.

*/

/***********************************************************************************************************************/

/*
	Let	m1=|w3|w2|
	and	m0=|w1|w0|
*/

template<size_type reg_length, Performance performance = Performance::specification> /* typename WordType,*/
struct multiplication
{
	using reg_type		= typename byte_type<reg_length>::reg_type;
	using root_length	= typename byte_type<reg_length>::half_type::length;
	using low_pass		= typename byte_type<reg_length>::low_pass;

/*
		? Adds to the existing out regardless of its initial value.
		The return value is the lower digit.
		p is the lower (product) digit.
		This is intuitively opposite of what it should be,
		but implements recursively/iteratively better under composition.
*/

	static reg_type multiply(reg_type & upper, reg_type m1, reg_type m0)
	{
		reg_type	upper_m1		= (m1 >> root_length::value),
				lower_m1		= (low_pass::value & m1),

				upper_m0		= (m0 >> root_length::value),
				lower_m0		= (low_pass::value & m0),

				product_ll		= lower_m1 * lower_m0,
				product_ul		= upper_m1 * lower_m0,
				product_lu		= lower_m1 * upper_m0,
				product_uu		= upper_m1 * upper_m0,

				lower0			= (product_ul << root_length::value) + product_ll,
				upper0			= (lower0 < product_ll),

				lower1			= (product_lu << root_length::value) + lower0,
				upper1			= (lower1 < lower0) + upper0,

				lower			= lower1;

				upper			= (product_ul >> root_length::value)
							+ (product_lu >> root_length::value)
							+ product_uu
							+ upper1;

		return lower;
	}
};

/***********************************************************************************************************************/

/*
	Let	n1=|w3|w2|
	and	n0=|w1|w0|
	with	 d=|y1|y0|

	r	is the remainder and is offered for runtime optimization.

	A variable is {n,u,l,b}-free (neither, upper, lower, both) based on its root_type,
	and whether or not that information is not yet redundant.

	Note: This is a source code optimization, as far as I can tell,
	there's no difference in reducing memory or processor cycles.
*/

template<size_type reg_length> /* typename WordType */
struct multiplication<reg_length, Performance::optimization>
{
	using reg_type		= typename byte_type<reg_length>::reg_type;
	using root_length	= typename byte_type<reg_length>::half_type::length;
	using low_pass		= typename byte_type<reg_length>::low_pass;

};

