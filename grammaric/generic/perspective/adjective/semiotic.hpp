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

/*
	Object is a type placeholder used to modify adverbs.
	It is equipped with convenience functions which otherwise
	frequently show up in use of the grammar.
*/

template<Interval ob_interval, Direction ob_direction>
struct object
{
	using type				= object;

	using interval				= constant<Interval, ob_interval>;

	using is_closed				= boolean<ob_interval == Interval::closed>;
	using is_closing			= boolean<ob_interval == Interval::closing>;
	using is_opening			= boolean<ob_interval == Interval::opening>;
	using is_open				= boolean<ob_interval == Interval::open>;

	using is_initial_open			= boolean
						<
							ob_interval == Interval::opening	||
							ob_interval == Interval::open
						>;

	using is_terminal_closed		= boolean
						<
							ob_interval == Interval::closed		||
							ob_interval == Interval::opening
						>;

	using close_initial			= typename conditional
						<
							is_terminal_closed,
							constant<Interval, Interval::closed>,
							constant<Interval, Interval::closing>

						>::rtn;

	using open_terminal			= typename conditional
						<
							is_initial_open,
							constant<Interval, Interval::open>,
							constant<Interval, Interval::closing>

						>::rtn;

	using invert_interval			= typename block
						<
							if_then
							<
								is_closed,
								constant<Interval, Interval::closed>

							>, else_then
							<
								is_closing,
								constant<Interval, Interval::opening>

							>, else_then
							<
								is_opening,
								constant<Interval, Interval::closing>

							>, then
							<
								constant<Interval, Interval::open>
							>

						>::rtn;

	//

	using direction				= constant<Direction, ob_direction>;

	using is_forward			= boolean<ob_direction == Direction::forward>;
	using is_backward			= boolean<ob_direction == Direction::backward>;

	using invert_direction			= typename conditional
						<
							is_forward,
							constant<Direction, Direction::backward>,
							constant<Direction, Direction::forward>

						>::rtn;

	//

	using initial_closed_type		= object<close_initial::value, ob_direction>;
	using terminal_open_type		= object<open_terminal::value, ob_direction>;
	using inverse_type			= object<invert_interval::value, invert_direction::value>;

	//

	template<typename ob_type>
	inline static size_type distance(ob_type ob, ob_type end)
	{
		if	(is_forward::value)	return end - ob;
		else				return ob - end;
	}

	template<typename ob_type>
	inline static ob_type shift(ob_type ob, size_type distance)
	{
		if	(is_forward::value)	return ob + distance;
		else				return ob - distance;
	}

	//

	template<typename ob_type>
	inline static void first_iteration(ob_type & ob)
	{
		if (is_initial_open::value)
		{
			if	(is_forward::value)	++ob;
			else				--ob;
		}
	}

	template<typename ob_type>
	inline static void main_iteration(ob_type & ob)
	{
		if	(is_forward::value)	++ob;
		else				--ob;
	}
};

