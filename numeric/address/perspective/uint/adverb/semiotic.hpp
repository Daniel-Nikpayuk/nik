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

template<typename...> struct uint_change_of_base;

/*
	Concept:

	The number of digits required for the numeral character array.

	log(2^64N) == 64N*lg(2)/lg(10) == 64N/(1+lg(5)) < 20N
*/

/*
*/

template<typename ob_type>
struct uint_change_of_base

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob1_interval, Direction ob1_direction,
	Interval ob_interval, Direction ob_direction,

	typename ob1_type,
	typename ob_type

> struct uint_change_of_base
<
	object<sub_interval, sub_direction>,
	object<ob1_interval, ob1_direction>,
	object<ob_interval, ob_direction>,
	ob1_type,
	ob_type
>

{
	using zero			= typename Constant::template zero<reg_type>;

	using iz_verb			= typename Power::identity_zero_verb;

	using word_uint_printer		= typename Word::uint::template printer<length, Performance::specification>;

	//

	using sub_policy		= object
					<
						Interval::closing,
						Direction::forward
					>;

	using ob_policy			= object
					<
						Interval::opening,
						Direction::backward
					>;

	using trinary_generic		= typename Power::template generic<sub_policy, ob_policy, ob_policy>;
	using digit_printer		= typename Power::template printer<ob_policy>;

	//

	using loop_policy		= object
					<
						Interval::closed,
						Direction::backward
					>;

	using loop_unary_generic	= typename Power::template generic<loop_policy>;

	using loop_unary_functor	= typename Power::template functor<loop_policy>;
	using loop_binary_functor	= typename Power::template functor<loop_policy, loop_policy>;

	using loop_division		= half<length, loop_policy, loop_policy>;

	using ob_printer		= typename Power::template printer<ob_policy>; // debugging
	using loop_printer		= typename Power::template printer<loop_policy>; // debugging

	//

	ob1_type end1;
	ob_type end;

	reg_type r;
	reg_type d;

	iz_verb iz;

	dgt_verb(ob1_type e1, ob_type e, reg_type od) : end1(e1), end(e), d(od) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		ob_type	e	= first_unary_generic::compare(iz, end, ob);
		ob_type e1	= end1 - (end - e); // ? will it make a difference with unsigned or not?

		loop_unary_functor::set(end1, e1, zero::value);

		end1 = e1;
		end = e;
	}

/*
	By the time main_action is called, end1, end are now closed intervals.
*/

	template<typename sub_type>
	inline void main_action(sub_type sub, ob1_type & ob1, ob_type & ob)
	{
		r = zero::value;
		loop_division::divide(r, end1, end, ob, d);
		*sub = r;

		loop_binary_functor::assign(end, end1, ob1);
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		ob_type	e	= loop_unary_generic::compare(iz, end, ob);
		ob_type e1	= end1 - (end - e); // ? will it make a difference with unsigned or not?

		loop_unary_functor::set(end1, e1, zero::value);

		end1 = e1;
		end = e;
	}

	template<typename sub_type>
	inline void last_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
	}
};

