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

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct printer
<
	reg_length,
	Performance::specification,
	sub_adjective,
	ob_adjective
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	//

	using power_printer			= typename Power::template printer
						<
							typename sub_adjective::inverse_type
						>;

	using uint_change_of_base		= change_of_base
						<
							reg_length,
							Performance::specification,
							sub_adjective, ob_adjective
						>;

	//

	using generic				= typename Power::generic;

		// print:

/*
	ob1_type, ob_type are assumed to be temporary memory.

	Specification requires ob_type to be terminal closed for the normal interpretation.
*/

	template<typename sub_type, typename ob_type>
	static void print(sub_type sub, ob_type ob, ob_type end, reg_type d = 10)
	{
		sub_type sub_end = uint_change_of_base::half_type::change_base(sub, ob, end, d);

			//

		if	(sub_adjective::distance(sub, sub_end))	power_printer::print(sub_end, sub);
		else						builtin_printer::print(zero::value);
	}
};

/***********************************************************************************************************************/

/*
*/

template
<
	size_type reg_length,
	typename sub_adjective,
	typename ob_adjective

> struct printer
<
	reg_length,
	Performance::optimization,
	sub_adjective,
	ob_adjective
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	//

	using power_printer			= typename Power::template printer
						<
							typename sub_adjective::inverse_type
						>;

	using uint_change_of_base		= change_of_base
						<
							reg_length,
							Performance::specification,
							sub_adjective,
							typename ob_adjective::terminal_open_type
						>;

	//

	using generic				= typename Power::generic;

		// print:

/*
	ob1_type, ob_type are assumed to be temporary memory.

	Optimization requires ob to have a right open interval to work properly.
*/

	template<typename sub_type, typename ob_type>
	static void print(sub_type sub, ob_type ob, ob_type end, reg_type d = 10)
	{
		sub_type sub_end = uint_change_of_base::change_base(sub, ob, end, d);

			//

		builtin_printer::print(*end);

		printer::print(sub_end, sub);
	}
};

