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
	Concept:

	|wn|...|w0| / |y1|y0|, where y1 == 0.
*/

template
<
	size_type length,
	typename sub_policy,
	typename ob_policy,

	Performance performance = Performance::specification

> struct half;

/*
	We tether the interval decomposition to the while loop,
	meaning [) is most natural, so then our decomposition is as follows:

	closing	|a <= b|:	[a, b)		= [a, b)
	closed	|a <= b|:	[a, b]		= [a, b)	-> [b]
	open	|a <  b|:	(a, b)		= (a)		-> [a+1, b)
	opening	|a <  b|:	(a, b]		= (a)		-> [a+1, b)	-> [b]

	Here (a) implies iterate, while [b] implies act.
*/

template
<
	size_type length,
	typename sub_policy,
	typename ob_policy

> struct half
<
	length,
	sub_policy,
	ob_policy,
	Performance::specification
>
{
	using reg_type		= typename byte_type<length>::rtn;

	using zero		= typename byte_type<length>::zero;

	using generic		= typename Power::template generic<sub_policy, ob_policy>;

	using three_halves	= typename Word::uint::template three_halves<length, Performance::specification>;

/*
	With the exception of the very first digit, all successor first digits are the remainder
	of the componentwise division, meaning each following first digit is necessarily less than the divisor.
	As such, by adding a "lead" initialized as 0---which also carries the remainder forward,
	we can guarantee the leading digit is always less than the divisor.
*/

	struct div_verb
	{
		reg_type & remainder;

		reg_type divisor;
		reg_type lead;

		div_verb(reg_type & r, reg_type d) :

			remainder(r), divisor(d), lead(zero::value) { }

		template<typename sub_type, typename ob_type>
		inline void main_action(sub_type sub, ob_type ob)
		{
//			*sub = three_halves::divide(lead, lead, *ob, divisor);
		}

		template<typename sub_type, typename ob_type>
		inline void last_action(sub_type sub, ob_type ob)
		{
//			*sub		= three_halves::divide(lead, lead, *ob, divisor);
//			remainder	= lead;
		}
	};

	template<typename sub_type, typename ob_type>
	static sub_type divide(reg_type & r, sub_type sub, ob_type ob, ob_type end, reg_type d)
	{
		div_verb div(r, d);

		return generic::map(div, sub, ob, end);
	}
};

/*
*/

template
<
	size_type length,
	typename sub_policy,
	typename ob_policy

> struct half
<
	length,
	sub_policy,
	ob_policy,
	Performance::optimization
>
{
};

