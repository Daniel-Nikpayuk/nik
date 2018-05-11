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


enum struct Operator : size_type
{
	equals,
	not_equals,
	less_than,
	less_than_or_equal,
	greater_than,
	greater_than_or_equal

	dimension
};

enum struct Interval : size_type
{
	closed,
	closing,
	opening,
	open,

	dimension
};

enum struct Direction : size_type
{
	forward,
	backward,

	dimension
};

/***********************************************************************************************************************/

	// forward:

template<Direction direction, typename Filler = void>
struct iterate
{
	template<typename type_ptr>
	static void apply(type_ptr & p)
	{
		++p;
	}
};

	// backward:

template<typename Filler>
struct iterate<Direction::backward, Filler>
{
	template<typename type_ptr>
	static void apply(type_ptr & p)
	{
		--p;
	}
};

/***********************************************************************************************************************/

	// closed, closing:

template<Interval interval, Direction direction>
struct initialize
{
	template<typename type_ptr>
	static void apply(type_ptr & p)
	{
		// do nothing.
	}
};

	// (m, n], assumes m < n:

template<Direction direction>
struct initialize<Interval::opening, direction>
{
	template<typename type_ptr>
	static void apply(type_ptr & p)
	{
		iterate<direction>::apply(p);
	}
};

	// (m, n), assumes m < n:

template<Direction direction>
struct initialize<Interval::open, direction>
{
	template<typename type_ptr>
	static void apply(type_ptr & p)
	{
		iterate<direction>::apply(p);
	}
};

/***********************************************************************************************************************/

	// opening, open:

template<Interval interval, Direction direction>
struct terminalize
{
	template<typename type_ptr>
	static void apply(type_ptr & p)
	{
		// do nothing.
	}
};

	// [m, n], assumes m < n:

template<Direction direction>
struct terminalize<Interval::closed, direction>
{
	template<typename type_ptr>
	static void apply(type_ptr & p)
	{
		iterate<direction>::apply(p);
	}
};

/*
	We tether the interval decomposition to the the while loop, meaning [) is most natural,
	so then our decomposition is as follows:

	[a, b) = [a, b)
	[a, b] = [a, b)	-> [b]
	(a, b) = (a)	-> [a+1, b)			=> a < b
	(a, b] = (a)	-> [a+1, b)	-> [b]		=> a < b

	Here (a) implies iterate, while [b] implies act.
*/

