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
	typename ob2_policy,
	typename ob1_policy,
	typename ob_policy,

	Performance performance = Performance::specification

> struct multiplication;

/*
*/

template
<
	size_type reg_length,
	Interval sub_interval, Direction sub_direction,
	Interval ob2_interval, Direction ob2_direction,
	Interval ob1_interval, Direction ob1_direction,
	Interval ob_interval, Direction ob_direction

> struct multiplication
<
	reg_length,
	object<sub_interval, sub_direction>,
	object<ob2_interval, ob2_direction>,
	object<ob1_interval, ob1_direction>,
	object<ob_interval, ob_direction>,
	Performance::specification
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

						  template<typename ob2_type, typename ob1_type, typename sub_type>
	using uint_map_multiplication		= map_multiplication
						<
							reg_length,
							object<sub_interval, sub_direction>,
							object<ob2_interval, ob2_direction>,
							object<ob1_interval, ob1_direction>,
							object<ob_interval, ob_direction>,
							ob2_type,
							ob1_type,
							sub_type
						>;

	//

	using generic				= typename Power::generic;

/*
*/

	template<typename sub_type, typename ob2_type, typename ob1_type, typename ob_type>
	static sub_type multiply(reg_type & c, sub_type sub, ob2_type ob2, ob1_type ob1, ob_type ob, ob_type end)
	{
		size_type l	= (ob_direction == Direction::forward) ? (end - ob) : (ob - end);
		ob2_type end2	= (ob2_direction == Direction::forward) ? ob2 + l : ob2 - l;
		ob1_type end1	= (ob1_direction == Direction::forward) ? ob1 + l : ob1 - l;

		uint_map_multiplication<ob2_type, ob1_type, sub_type> umm(c, ob2, end2, end1, sub);

		return generic::map(umm, ob2, ob1, ob, end);
	}
};

/*
*/

template
<
	size_type reg_length,
	Interval sub_interval, Direction sub_direction,
	Interval ob2_interval, Direction ob2_direction,
	Interval ob1_interval, Direction ob1_direction,
	Interval ob_interval, Direction ob_direction

> struct multiplication
<
	reg_length,
	object<sub_interval, sub_direction>,
	object<ob2_interval, ob2_direction>,
	object<ob1_interval, ob1_direction>,
	object<ob_interval, ob_direction>,
	Performance::optimization
>
{
};

