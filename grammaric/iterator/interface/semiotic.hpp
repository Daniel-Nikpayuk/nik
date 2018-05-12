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
	Semantic note:

	The operators in this module act on abstract iterator types.

	On the one hand, iterators only exist to navigate specific data structures, which means by extension
	the operators in this module are effectively acting on data structures instead of iterators.
	This raises the question: Where do we categorize these operators, with structures or their navigators?

	The specification I have taken is that we categorize such operators with the navigators of structures.
	The idea is these operators are acting on iterators: It just so happens that these iterators maintain
	relationships with each other that coincide with particular data structures.
*/

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

template<Interval ob_interval, Direction ob_direction>
struct object
{
	static constexpr Interval interval	= ob_interval;
	static constexpr Direction direction	= ob_direction;
};

	// generic:

enum struct Operator : size_type
{
	compare,
	map,

	dimension
};

