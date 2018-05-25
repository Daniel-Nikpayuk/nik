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

	The number of digits required for the numeral character array.

	log(2^64N) == 64N*lg(2)/lg(10) == 64N/(1+lg(5)) < 20N
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

	using iz_verb			= typename Power::identity_zero_verb;

	using word_uint_printer		= typename Word::uint::template printer<length, Performance::specification>;

	//

	using sub_policy		= object
					<
						Interval::closing,
						Direction::forward
					>;

	using ob_policy			= object
					<
						Interval::opening,
						Direction::backward
					>;

	using trinary_generic		= typename Power::template generic<sub_policy, ob_policy, ob_policy>;
	using digit_printer		= typename Power::template printer<ob_policy>;

	//

	using loop_policy		= object
					<
						Interval::closed,
						Direction::backward
					>;

	using loop_unary_generic	= typename Power::template generic<loop_policy>;

	using loop_unary_functor	= typename Power::template functor<loop_policy>;
	using loop_binary_functor	= typename Power::template functor<loop_policy, loop_policy>;

	using loop_division		= half<length, loop_policy, loop_policy>;

	using ob_printer		= typename Power::template printer<ob_policy>; // debugging
	using loop_printer		= typename Power::template printer<loop_policy>; // debugging

	template<typename ob_type>
	struct dgt_verb
	{
		ob_type ob1;
		ob_type ob;

		reg_type r;
		reg_type d;

		iz_verb iz;

		dgt_verb(ob_type o1, ob_type o, reg_type div) : ob1(o1), ob(o), d(div) { }

/*
	By the time main_action is called, end1, end are now closed intervals.
*/

		template<typename sub_type>
		inline void main_action(sub_type sub, ob_type & end1, ob_type & end)
		{
			nik::display << "end-ob: ";		// debugging
			loop_printer::space_print(end, ob);	// debugging
			nik::display << "end1-ob1: ";		// debugging
			loop_printer::space_print(end1, ob1);	// debugging
			nik::display << nik::endl;		// debugging

			ob_type	e	= loop_unary_generic::compare(iz, end, ob);
			ob_type e1	= end1 - (end - e); // ? will it make a difference with unsigned or not?

			loop_unary_functor::set(end1, e1, zero::value);

			end1 = e1;
			end = e;

			r = zero::value;
			loop_division::divide(r, end1, end, ob, d);
			*sub = r;

			loop_binary_functor::assign(end, end1, ob1);

			nik::display << "end-ob: ";		// debugging
			loop_printer::space_print(end, ob);	// debugging
			nik::display << "end1-ob1: ";		// debugging
			loop_printer::space_print(end1, ob1);	// debugging
			nik::display << nik::endl;		// debugging
		}

		template<typename sub_type>
		inline void last_action(sub_type sub, ob_type end1, ob_type end)
		{
		}
	};

		// print:

		// sub_type	is restricted to forward closing.
		// ob_type	is restricted to backward opening.
		//		is assumed as temporary memory.

	template<typename sub_type, typename ob_type>
	static void print(sub_type sub, ob_type end1, ob_type end, ob_type ob, reg_type d = 10)
	{
		ob_type ob1 = end1 - (end-ob);

		dgt_verb<ob_type> dgt(ob1, ob, d);

//		sub_type end0 = trinary_generic::map(dgt, sub, end1, end, ob);

		sub_type end0 = sub;

		--end1; --end;
		while (end != ob)
		{
			dgt.main_action(end0, end1, end);

			++end0;
		}

		word_uint_printer::print(end0, *end, d);

		digit_printer::digit_print(end0, sub);
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

