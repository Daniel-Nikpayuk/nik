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
	size_type N,
	typename...

> struct generic;

#include"unary/semiotic.hpp"

#include"binary/semiotic.hpp"

