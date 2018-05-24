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
	Does not test sub, ob, for matching interior closed interval lengths or right ends.

	False conditionals are expected to be optimized out at compile time.
*/

template
<
	typename...

> struct generic;

/*
	unary:
*/

template
<
	Interval sub_interval, Direction sub_direction

> struct generic
<
	object<sub_interval, sub_direction>
>
{
		// compare:

	template<typename vb_type, typename sub_type>
	static sub_type compare(vb_type & vb, sub_type sub, sub_type end)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		while (sub != end)
		{
			if (vb.break_match(sub)) return sub;

			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (sub_interval == Interval::closed || sub_interval == Interval::opening)
		{
			vb.last_match(sub);
		}

		return sub;
	}

		// repeat:

	template<typename vb_type, typename sub_type>
	static void repeat(vb_type & vb, sub_type sub, sub_type end)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		while (sub != end)
		{
			vb.main_action(sub);

			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (sub_interval == Interval::closed || sub_interval == Interval::opening)
		{
			vb.last_action(sub);
		}
	}
};

/*
	binary:
*/

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct generic
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
		// compare:

	template<typename vb_type, typename sub_type, typename ob_type>
	static sub_type compare(vb_type & vb, sub_type sub, ob_type ob, ob_type end)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}

		while (ob != end)
		{
			if (vb.break_match(sub, ob)) return sub;

			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;

			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}

		if (ob_interval == Interval::closed || ob_interval == Interval::opening)
		{
			vb.last_match(sub, ob);
		}

		return sub;
	}

		// (morph,) map:

	template<typename vb_type, typename sub_type, typename ob_type>
	static sub_type map(vb_type & vb, sub_type sub, ob_type ob, ob_type end)
	{
/*
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}
*/

/*
		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
*/

/*
		while (ob != end)
		{
			vb.main_action(sub, ob);

			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;

			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
*/

/*
		if (ob_interval == Interval::closed || ob_interval == Interval::opening)
		{
			vb.last_action(sub, ob);
		}
*/

		return sub;
	}
};

/*
	trinary:
*/

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob1_interval, Direction ob1_direction,
	Interval ob_interval, Direction ob_direction

> struct generic
<
	object<sub_interval, sub_direction>,
	object<ob1_interval, ob1_direction>,
	object<ob_interval, ob_direction>
>
{
		// (morph,) map:

	template<typename vb_type, typename sub_type, typename ob1_type, typename ob_type>
	static sub_type map(vb_type & vb, sub_type sub, ob1_type ob1, ob_type ob, ob_type end)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob1_interval == Interval::opening || ob1_interval == Interval::open)
		{
			if	(ob1_direction == Direction::forward)	++ob1;
			else if	(ob1_direction == Direction::backward)	--ob1;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}

		while (ob != end)
		{
			vb.main_action(sub, ob1, ob);

			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;

			if	(ob1_direction == Direction::forward)	++ob1;
			else if	(ob1_direction == Direction::backward)	--ob1;

			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}

		if (ob_interval == Interval::closed || ob_interval == Interval::opening)
		{
			vb.last_action(sub, ob1, ob);
		}

		return sub;
	}
};

