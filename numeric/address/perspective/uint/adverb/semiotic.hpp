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


/***********************************************************************************************************************/


struct uint_half_division
{
	reg_type & remainder;
	reg_type divisor;

	div_verb(reg_type & r, reg_type d) : remainder(r), divisor(d) { }

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		*sub = three_halves::divide(remainder, remainder, *ob, divisor);
	}

	template<typename sub_type, typename ob_type>
	inline void last_action(sub_type sub, ob_type ob)
	{
		*sub = three_halves::divide(remainder, remainder, *ob, divisor);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob1_interval, Direction ob1_direction,
	Interval ob_interval, Direction ob_direction,

	typename ob1_type, typename ob_type

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

	using identity_zero_first	= typename Power::template identity_zero<object<ob_interval, ob_direction>>;
	using identity_zero_main	= typename Power::template identity_zero<object<Interval::closed, ob_direction>>;

	//

	using generic			= typename Power::template generic;

	using functor_first		= typename Power::template functor<object<ob1_interval, ob1_direction>>;
	using functor_main		= typename Power::template functor<object<Interval::closed, ob1_direction>>;
	using binary_main		= typename Power::template functor
					<
						object<Interval::closed, ob_direction>
						object<Interval::closed, ob1_direction>,
					>;

	using division_main		= half_division
					<
						length,
						object<Interval::closed, ob1_direction>,
						object<Interval::closed, ob_direction>
					>;

	//

	ob1_type end1;
	ob_type end;

	reg_type r;
	reg_type d;

	identity_zero_first izf;
	identity_zero_main izm;

	dgt_verb(ob1_type e1, ob_type e, reg_type od) : end1(e1), end(e), d(od) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		ob_type	o	= generic::compare(izf, ob, end);
		ob_type o1	= ob1 - (ob - o); // ? will it make a difference with unsigned or not?

		functor_first::set(ob1, o1, zero::value);

		ob1 = o1;
		ob = o;
	}

/*
	By the time main_action is called, end1, end are now closed intervals.
*/

	template<typename sub_type>
	inline void main_action(sub_type sub, ob1_type & ob1, ob_type & ob)
	{
		r = zero::value;
		division_main::divide(r, ob1, ob, end, d);
		*sub = r;

		binary_main::assign(ob, ob1, end1);
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		ob_type	o	= generic::compare(izm, ob, end);
		ob_type o1	= ob1 - (ob - o); // ? will it make a difference with unsigned or not?

		functor_main::set(ob1, o1, zero::value);

		ob1 = o1;
		ob = o;
	}

	template<typename sub_type>
	inline void last_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
	}
};

