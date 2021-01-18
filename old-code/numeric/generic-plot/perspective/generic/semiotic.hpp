/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	We tether the interval decomposition to the while loop,
	meaning [) is most natural, so then our decomposition is as follows:

	closing	|a <= b|:	[a, b)		= [a, b)
	closed	|a <= b|:	[a, b]		= [a, b)	-> [b]
	open	|a <  b|:	(a, b)		= (a)		-> [a+1, b)
	opening	|a <  b|:	(a, b]		= (a)		-> [a+1, b)	-> [b]

	Here (a) implies iterate, while [b] implies act.
*/

enum struct Interval : size_type
{
	closed,
	closing,
	opening,
	open,

	dimension // filler
};

enum struct Direction : size_type
{
	forward,
	backward,

	dimension // filler
};

template<Interval ob_interval, Direction ob_direction>
struct object
{
	static constexpr Interval interval	= ob_interval;
	static constexpr Direction direction	= ob_direction;
};

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
	Interval sub_interval, Direction sub_direction,
	template<Interval, Direction> typename Object

> struct generic
<
	Object<sub_interval, sub_direction>
>
{
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

/*
	There are methods meant specifically for use with copowers<multi>.

	initial case:

	template<typename vb_type, typename Type, size_type length, Access access>
	static void repeat
	(
		vb_type & vb,
		mobile_copower<power<Type, length, One::value>, access> sub,
		mobile_copower<power<Type, length, One::value>, access> end
	)
	{
		// ideally:

		while (sub != end)
		{
			repeat(vb, sub[k], (*end).value);
		}
	}
*/

/*
	recursive case:

	template<typename vb_type, typename Type, size_type length, size_type N, Access access>
	static void repeat
	(
		vb_type & vb,
		mobile_copower<power<Type, length, N>, access> sub,
		mobile_copower<power<Type, length, N>, access> end
	)
	{
		// ideally:

		while (sub != end)
		{
			repeat(vb, *sub, *end);

			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}
	}
*/
};

/*
	binary:
*/

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction,
	template<Interval, Direction> typename Object

> struct generic
<
	Object<sub_interval, sub_direction>,
	Object<ob_interval, ob_direction>
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
			vb.main_action(sub, ob);

			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;

			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}

		if (ob_interval == Interval::closed || ob_interval == Interval::opening)
		{
			vb.last_action(sub, ob);
		}

		return sub;
	}
};

