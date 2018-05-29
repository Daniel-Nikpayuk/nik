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

template
<
	size_type reg_length,
	typename sub_policy,
	typename ob1_policy,
	typename ob_policy,

	Performance performance = Performance::specification

> struct printer;

/*
*/

template
<
	size_type reg_length,
	Interval sub_interval, Direction sub_direction,
	Interval ob1_interval, Direction ob1_direction,
	Interval ob_interval, Direction ob_direction

> struct printer
<
	reg_length,
	object<sub_interval, sub_direction>,
	object<ob1_interval, ob1_direction>,
	object<ob_interval, ob_direction>,
	Performance::specification
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	//

	using reverse_sub_interval		= typename block
						<
							if_then
							<
								boolean<sub_interval == Interval::closing>,
								constant<Interval, Interval::opening>

							>, else_then
							<
								boolean<sub_interval == Interval::opening>,
								constant<Interval, Interval::closing>

							>, then
							<
								constant<Interval, sub_interval>
							>

						>::rtn;

	using reverse_sub_direction		= typename block
						<
							if_then
							<
								boolean<sub_direction == Direction::forward>,
								constant<Direction, Direction::backward>
							>, then
							<
								constant<Direction, Direction::forward>
							>

						>::rtn;

	//

	using printer_digit			= typename Power::template repeat_digit
						<
							object<reverse_sub_interval::value, reverse_sub_direction::value>
						>;

	using word_map_change_of_base		= typename Word::uint::template map_change_of_base
						<
							reg_length,
							object<sub_interval, sub_direction>
						>;

						  template<typename ob1_type, typename ob_type>
	using uint_map_change_of_base		= map_change_of_base
						<
							reg_length,
							object<sub_interval, sub_direction>,
							object<ob1_interval, ob1_direction>,
							object<ob_interval, ob_direction>,
							ob1_type,
							ob_type
						>;

	//

	using generic				= typename Power::generic;

		// print:

/*
	ob1_type, ob_type are assumed to be temporary memory.

	Specification requires ob to have a right closed interval to work properly.
*/

	template<typename sub_type, typename ob1_type, typename ob_type>
	static void print(sub_type sub, ob1_type ob1, ob_type ob, ob_type end, reg_type d = 10)
	{
		size_type l	= (ob_direction == Direction::forward) ? (end - ob) : (ob - end);
		ob_type end1	= (ob1_direction == Direction::forward) ? ob1 + l : ob1 - l;

		uint_map_change_of_base<ob1_type, ob_type> uint_mcob(end1, end, d);

		sub_type sub_end = generic::map(uint_mcob, sub, ob1, ob, end);

			//

		printer_digit pd;

		generic::repeat(pd, sub_end, sub);
	}
};

/***********************************************************************************************************************/

/*
*/

template
<
	size_type reg_length,
	Interval sub_interval, Direction sub_direction,
	Interval ob1_interval, Direction ob1_direction,
	Interval ob_interval, Direction ob_direction

> struct printer
<
	reg_length,
	object<sub_interval, sub_direction>,
	object<ob1_interval, ob1_direction>,
	object<ob_interval, ob_direction>,
	Performance::optimization
>
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	//

	using reverse_sub_interval		= typename block
						<
							if_then
							<
								boolean<sub_interval == Interval::closing>,
								constant<Interval, Interval::opening>

							>, else_then
							<
								boolean<sub_interval == Interval::opening>,
								constant<Interval, Interval::closing>

							>, then
							<
								constant<Interval, sub_interval>
							>

						>::rtn;

	using reverse_sub_direction		= typename block
						<
							if_then
							<
								boolean<sub_direction == Direction::forward>,
								constant<Direction, Direction::backward>
							>, then
							<
								constant<Direction, Direction::forward>
							>

						>::rtn;

	//

	using printer_digit			= typename Power::template repeat_digit
						<
							object<reverse_sub_interval::value, reverse_sub_direction::value>
						>;

	using word_map_change_of_base		= typename Word::uint::template map_change_of_base
						<
							reg_length,
							object<sub_interval, sub_direction>
						>;

						  template<typename ob1_type, typename ob_type>
	using uint_map_change_of_base		= map_change_of_base
						<
							reg_length,
							object<sub_interval, sub_direction>,
							object<ob1_interval, ob1_direction>,
							object<ob_interval, ob_direction>,
							ob1_type,
							ob_type
						>;

	//

	using generic				= typename Power::generic;

		// print:

/*
	ob1_type, ob_type are assumed to be temporary memory.

	Optimization requires ob to have a right open interval to work properly.
*/

	template<typename sub_type, typename ob1_type, typename ob_type>
	static void print(sub_type sub, ob1_type ob1, ob_type ob, ob_type end, reg_type d = 10)
	{
		size_type l	= (ob_direction == Direction::forward) ? (end - ob) : (ob - end);
		ob_type end1	= (ob1_direction == Direction::forward) ? ob1 + l : ob1 - l;

		uint_map_change_of_base<ob1_type, ob_type> uint_mcob(end1, end, d);

		sub_type sub_end = generic::map(uint_mcob, sub, ob1, ob, end);

			//

		printer_digit pd;

		builtin_printer::print(*end);

		generic::repeat(pd, sub_end, sub);
	}
};

