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

	Performance performance = Performance::specification

> struct printer;

/*
*/

template
<
	size_type length

> struct printer
<
	length,
	Performance::specification
>
{
	using reg_type		= typename byte_type<length>::rtn;

	using zero		= typename byte_type<length>::zero;

	using ob_policy		= object
				<
					Interval::opening,
					Direction::backward
				>;

	using sub_policy	= ob_policy;

	using generic		= typename Power::template generic<sub_policy>;
	using identity		= typename Power::template identity<sub_policy>;
	using functor		= typename Power::template identity<sub_policy, ob_policy>;

	using method		= half<length, sub_policy, ob_policy, Performance::specification>;

	struct pr_verb
	{
		template<typename sub_type>
		inline void main_action(sub_type sub)
		{
			builtin_printer::print(*sub);
			builtin_printer::print(' ');
		}

		template<typename sub_type>
		inline void last_action(sub_type sub)
		{
			builtin_printer::print(*sub);
			builtin_printer::print('\n');
		}
	};

		// print:

	template<typename sub_type>
	static void print(sub_type sub, sub_type end)
	{
		size_type N = end - sub;

		reg_type r;
		reg_type d = 10;
		reg_type tmp[N];

		pr_verb pr;

		method::repeat(pr, sub, end);

		while (!identity::zero(tmp, tmp + N))
		{
			method::divide(r, tmp, sub, end, d);

			builtin_printer::print(r);

			--sub;
		}
	}
};

/*
*/

template
<
	size_type length

> struct printer
<
	length,
	Performance::optimization
>
{
};

