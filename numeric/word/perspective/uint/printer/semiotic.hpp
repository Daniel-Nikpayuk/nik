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
	using reg_type			= typename byte_type<length>::reg_type;

	using zero			= typename Constant::template zero<reg_type>;

	using pd_verb			= typename Power::printer_digit_verb;

	//

					  template<Interval interval, Direction direction>
	using unary_generic		= typename Power::template generic<object<interval, direction>>;

	struct dgt_verb
	{
		reg_type ob;
		reg_type d;

		dgt_verb(reg_type o, reg_type div) : ob(o), d(div) { }

		template<typename sub_type>
		inline bool condition(sub_type sub)
		{
			return ob != zero::value;
		}

/*
	By the time main_action is called, end1, end are now closed intervals.
*/

		template<typename sub_type>
		inline void main_action(sub_type sub)
		{
			reg_type q	= ob / d;
			*sub		= ob % d;

			ob = q;
		}

		template<typename sub_type>
		inline void last_action(sub_type sub)
		{
		}
	};

		// print:

		// sub_type	is restricted to forward closing.
		// ob_type	is restricted to backward opening.
		//		is assumed as temporary memory.

	template<typename sub_type>
	static void print(sub_type sub, reg_type ob, reg_type d = 10)
	{
		dgt_verb dgt(ob, d);

		sub_type end	= unary_generic
				<
					Interval::closing,
					Direction::forward

				>::repeat(dgt, sub);

		pd_verb esp;

		unary_generic
		<
			Interval::opening,
			Direction::backward

		>::repeat(esp, end, sub);
	}
};

/***********************************************************************************************************************/

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

