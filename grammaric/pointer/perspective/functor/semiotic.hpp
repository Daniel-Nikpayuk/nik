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
	Although the template parameter allows for arbitrary types, product is meant specifically for register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	8 << 3, void*

	In the context of this library, products are the disjoint union of concurrent instances of the same type.
	This generic code is only intended for a fixed number of similar types, but the length parameter generates
        further possibilities. As such, the basic methods for the objects of this class are called as external
        static functions allowing for identity, proximity, and shape methods between various lengths.
*/

template
<
	Interval in_interval, Direction in_direction,
	Interval out_interval, Direction out_direction
>
struct shape
{
		// repeat:

		// morph:

		// map:

			// closed:

	template<typename in_iterator, typename out_iterator>
	static in_iterator map(in_iterator in, out_iterator out, out_iterator end)
	{
		while (out != end)
		{
			if (*in != *out_b) return false;
			++in_b, ++out_b;
		}

		return true;
	}

	template<typename Type, Access in_access, Access out_access>
	static in_iterator map(coproduct<Type*, in_access> in, coproduct<Type*, out_access> out, coproduct<Type*, out_access> end)
	{
		in.focus;
		out.focus;
		end.focus;

		while (out != end)
		{
			if (*in != *out_b) return false;
			++in_b, ++out_b;
		}

		return true;
	}

		// assign:
};

/*
	We tether the interval decomposition to the while loop,
	meaning [) is most natural, so then our decomposition is as follows:

	closing	|a <= b|:	[a, b)		= [a, b)
	closed	|a <= b|:	[a, b]		= [a, b)	-> [b]
	open	|a <  b|:	(a, b)		= (a)		-> [a+1, b)
	opening	|a <  b|:	(a, b]		= (a)		-> [a+1, b)	-> [b]

	Here (a) implies iterate, while [b] implies act.
*/

template<Interval sub_interval, Direction sub_direction>
struct subject														{

template<Interval ob_interval, Direction ob_direction>
struct object														{

	// False conditionals are expected to be optimized out at compile time.

template<typename verb_type, typename type_ptr, typename const_type_ptr>
static type_ptr compare(verb_type & verb, type_ptr sub, const_type_ptr ob, const_type_ptr end)
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
		if (verb.is_pattern(sub, ob)) return sub;

		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	if (sub_interval == Interval::closed || sub_interval == Interval::opening)
	{
		verb.is_pattern(sub, ob);
	}

	return sub;
}

template<typename verb_type, typename type_ptr, typename const_type_ptr>
static type_ptr map(const verb_type & verb, type_ptr sub, const_type_ptr ob, const_type_ptr end)
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
		verb.functor(sub, ob);

		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	if (sub_interval == Interval::closed || sub_interval == Interval::opening)
	{
		verb.functor(sub, ob);
	}

	return sub;
}

};};

