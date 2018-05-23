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
	typename sub_policy,
	typename ob1_policy,
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
	typename sub_policy,
	typename ob1_policy,
	typename ob_policy

> struct half
<
	sub_policy,
	ob1_policy,
	ob_policy,
	Performance::specification
>
{
	using method = typename Power::template generic<sub_policy, ob1_policy, ob_policy>;

	template<typename reg_type>
	struct div_verb
	{
		reg_type divisor;

		div_verb(reg_type d) : divisor(d) { }

		template<typename sub_type, typename ob1_type, typename ob_type>
		inline void main_action(sub_type sub, ob1_type ob1, ob_type ob)
		{
		}

		template<typename sub_type, typename ob1_type, typename ob_type>
		inline void last_action(sub_type sub, ob1_type ob1, ob_type ob)
		{
		}
	};


	template<typename sub_type, typename ob_type, typename reg_type>
	static sub_type divide(sub_type sub, ob_type ob, ob_type end, reg_type d)
	{
		div_verb<reg_type> div(d);

		return method::map(div, sub, ob, ob+1, end);
	}
};

/*
*/

template
<
	typename sub_policy,
	typename ob1_policy,
	typename ob_policy

> struct half
<
	sub_policy,
	ob1_policy,
	ob_policy,
	Performance::optimization
>
{
};

