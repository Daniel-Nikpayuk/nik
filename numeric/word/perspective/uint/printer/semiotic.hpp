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
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	Performance performance = Performance::specification

> struct printer;

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective

> struct printer
<
	reg_length,
	sub_adjective,
	Performance::specification
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	using uint_map_change_of_base		= map_change_of_base<reg_length, sub_adjective>;

	//

	using generic				= typename Power::generic;

	using printer				= typename Power::printer<sub_adjective::inverse_type>;

		// print:

/*
		sub_type is forward closing for the normal interpretation.
*/

	template<typename sub_type>
	static void print(sub_type sub, reg_type ob, reg_type d = 10)
	{
		uint_map_change_of_base umcob(d);

		sub_type end = generic::map(umcob, sub, ob, zero::value);

		printer::print(end, sub);
	}
};

/***********************************************************************************************************************/

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective

> struct printer
<
	reg_length,
	sub_adjective,
	Performance::optimization
>
{
};

