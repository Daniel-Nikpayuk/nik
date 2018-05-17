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
	size_type N,

	Interval sub_interval, Direction sub_direction

> struct nested_generic
<
	N,

	object<sub_interval, sub_direction>
>
{
	using sub_generic = nested_generic<N-1, object<sub_interval, sub_interval>>;

		// repeat:

	template<typename vb_type, typename sub_type>
	static void repeat(vb_type & vb, sub_type sub, sub_type end)
	{
		size_type length = end - sub;

		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		while (sub != end)
		{
			sub_generic::repeat(vb, *sub, *sub + length);

			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (sub_interval == Interval::closed || sub_interval == Interval::opening)
		{
			sub_generic::repeat(vb, *sub, *sub + length);
		}
	}
};

template
<
	Interval sub_interval, Direction sub_direction
>
struct nested_generic
<
	Zero::value,

	object<sub_interval, sub_direction>
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
};

/*
	The special case where N = 0 is used often in this library and gets its own alias:
*/

		template
		<
			Interval sub_interval, Direction sub_direction
		>
using generic = nested_generic
		<
			Zero::value,
			object<sub_interval, sub_direction>
		>;

