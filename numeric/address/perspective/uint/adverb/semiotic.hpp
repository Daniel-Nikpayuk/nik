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
	A design decision needs to be made regarding temporary containers and how much they should be optimized here.
	In the meantime they're not optimized at all.

	map_half_division
	map_change_of_base
	
	map_shallow_addition
	map_addition
	
	map_shallow_subtraction
	map_subtraction
	
	map_shallow_scalar_multiplication
	map_scalar_multiplication
	map_multiplication
*/


/***********************************************************************************************************************/


template<size_type reg_length, typename sub_adjective, typename ob_adjective>
struct map_half_division
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	//

	using word_half_division	= typename Word::uint::template half_division<reg_length, Performance::specification>;

	reg_type & remainder;
	reg_type divisor;

	map_half_division(reg_type & r, reg_type d) : remainder(r), divisor(d) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		*sub = word_half_division::divide(remainder, remainder, *ob, divisor);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_action(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_right_closed::value)
		{
			*sub = word_half_division::divide(remainder, remainder, *ob, divisor);
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep sub_type, ob_type independent for higher entropy: They allow for different containers.
	ob_tmp1 is a temporary container, the choice of which can be optimized based on how its used here.
	reg_type is what their dereference type.
*/


template
<
	size_type reg_length,
	typename sub_adjective, typename ob1_adjective, typename ob_adjective,
	typename ob1_type, typename ob_type

> struct map_change_of_base
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	using compare_zero_first		= typename Power::template compare_zero<object<ob_interval, ob_direction>>;
	using compare_zero_main			= typename Power::template compare_zero<object<Interval::closed, ob_direction>>;

	using word_map_change_of_base		= typename Word::uint::template map_change_of_base
						<
							reg_length,
							object<sub_interval, sub_direction>
						>;

	//

	using generic				= typename Power::generic;

	using functor_first			= typename Power::template functor<object<ob1_interval, ob1_direction>>;
	using functor_main			= typename Power::template functor<object<Interval::closed, ob1_direction>>;
	using binary_main			= typename Power::template functor
						<
							object<Interval::closed, ob_direction>,
							object<Interval::closed, ob1_direction>
						>;

	using division_main			= half_division
						<
							reg_length,
							object<Interval::closed, ob1_direction>,
							object<Interval::closed, ob_direction>
						>;

	//

	ob1_type end1;
	ob_type end;

	reg_type remainder;
	reg_type divisor;

	compare_zero_first czf;
	compare_zero_main czm;

	map_change_of_base(ob1_type e1, ob_type e, reg_type d) : end1(e1), end(e), divisor(d) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);

		ob_type	o	= generic::compare(czf, ob, end);

		size_type d	= (ob_direction == Direction::forward) ? (o - ob) : (ob - o);
		ob_type o1	= (ob1_direction == Direction::forward) ? ob1 + d : ob1 - d;

		functor_first::set(ob1, o1, zero::value);

		ob1 = o1;
		ob = o;
	}

/*
	By the time main_action is called, end1, end are now closed or closing intervals.
*/

	template<typename sub_type>
	inline void main_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		remainder = zero::value;
		division_main::divide(remainder, ob1, ob, end, divisor);
		*sub = remainder;

		binary_main::assign(ob, ob1, end1);
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);

		ob_type	o	= generic::compare(czm, ob, end);

		size_type d	= (ob_direction == Direction::forward) ? (o - ob) : (ob - o);
		ob_type o1	= (ob1_direction == Direction::forward) ? ob1 + d : ob1 - d;

		functor_main::set(ob1, o1, zero::value);

		ob1 = o1;
		ob = o;
	}

	template<typename sub_type>
	inline void last_action(sub_type & sub, ob1_type ob1, ob_type ob)
	{
		if (ob_adjective::is_right_closed::value)
		{
			word_map_change_of_base word_mcob(divisor);

			sub = generic::map(word_mcob, sub, *ob, zero::value);
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective, typename ob_adjective>
struct map_shallow_addition
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	//

	reg_type & carry;

	map_shallow_addition(reg_type & c) : carry(c) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

/*
	By the time main_action is called, end1, end are now closed intervals.

	If *ob1 + *ob causes an arithmetic overflow, then *ob1 + *ob < *ob1, *ob.
	If *ob1 + *ob causes an arithmetic overflow, then *ob1 + *ob + 1 will not cause a second such overflow.
*/

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		carry	+= *ob;
		*sub	+= carry;
		carry	 = (carry < *ob || *sub < carry);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_action(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_right_closed::value)
		{
			carry	+= *ob;
			*sub	+= carry;
			carry	 = (carry < *ob || *sub < carry);
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective, typename ob1_adjective, typename ob_adjective>
struct map_addition
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	//

	reg_type & carry;

	map_addition(reg_type & c) : carry(c) { }

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob1_adjective::first_iteration(ob1);
		ob_adjective::first_iteration(ob);
	}

/*
	By the time main_action is called, end1, end are now closed intervals.

	If *ob1 + *ob causes an arithmetic overflow, then *ob1 + *ob < *ob1, *ob.
	If *ob1 + *ob causes an arithmetic overflow, then *ob1 + *ob + 1 will not cause a second such overflow.
*/

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void main_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		carry	+= *ob1;
		*sub	 = carry + *ob;
		carry	 = (carry < *ob1 || *sub < *ob);
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob1_adjective::main_iteration(ob1);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void last_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		if (ob_adjective::is_right_closed::value)
		{
			carry	+= *ob1;
			*sub	 = carry + *ob;
			carry	 = (carry < *ob1 || *sub < *ob);
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective, typename ob_adjective>
struct map_shallow_subtraction
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	//

	reg_type & carry;
	reg_type sub_value;

	map_shallow_subtraction(reg_type & c) : carry(c) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

/*
	By the time main_action is called, end1, end are now closed intervals.

*/

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		sub_value	 = *sub;

		carry		+= *ob;
		*sub		-= carry;
		carry		 = (carry < *ob || sub_value < *sub);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_action(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_right_closed::value)
		{
			sub_value	 = *sub;

			carry		+= *ob;
			*sub		-= carry;
			carry		 = (carry < *ob || sub_value < *sub);
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective, typename ob1_adjective, typename ob_adjective>
struct map_subtraction
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	//

	reg_type & carry;

	map_subtraction(reg_type & c) : carry(c) { }

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob1_adjective::first_iteration(ob1);
		ob_adjective::first_iteration(ob);
	}

/*
	By the time main_action is called, end1, end are now closed intervals.

	Regarding arithmetic overflow, there are a few considerations:
	*sub = *ob1 - (carry + *ob) ==> *sub + (carry + *ob) = *ob1
	It's possible (carry + *ob) is an overflow, but this implies carry == 1 and *ob == b-1.
	As such, with an assumed overflow, the new carry would be true, and we need not worry about a "double carry"
	as (carry + *ob) would equal zero, and so *sub == *ob1 - (carry + *ob) == *ob1.
	Otherwise, if (*ob + carry) has no overflow, then *ob1 == carry + *sub,
	and so we check for an overflow there by means of the test (*ob1 < *sub).
*/

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void main_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		carry	+= *ob;
		*sub	 = *ob1 - carry;
		carry	 = (carry < *ob || *ob1 < *sub);
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob1_adjective::main_iteration(ob1);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void last_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		if (ob_adjective::is_right_closed::value)
		{
			carry	+= *ob;
			*sub	 = *ob1 - carry;
			carry	 = (carry < *ob || *ob1 < *sub);
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective>
struct map_shallow_scalar_multiplication
{
	using reg_type					= typename byte_type<reg_length>::reg_type;

	//

	using word_half_multiplication			= typename Word::uint::template half_multiplication<reg_length>;

	//

	reg_type & carry;
	reg_type scalar;
	reg_type upper;

	map_shallow_scalar_multiplication(reg_type & c, reg_type s) : carry(c), scalar(s) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		sub_adjective::first_iteration(sub);
	}

/*
	By the time main_action is called, end1, end are now closed intervals.
*/

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		*sub	= word_half_multiplication::multiply(upper, scalar, *sub) + carry;
		carry	= (*sub < carry) + upper;
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		sub_adjective::main_iteration(sub);
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		if (sub_adjective::is_right_closed::value)
		{
			*sub	= word_half_multiplication::multiply(upper, scalar, *sub) + carry;
			carry	= (*sub < carry) + upper;
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective, typename ob_adjective>
struct map_scalar_multiplication
{
	using reg_type					= typename byte_type<reg_length>::reg_type;

	//

	using word_half_multiplication			= typename Word::uint::template half_multiplication<reg_length>;

	//

	reg_type & carry;
	reg_type scalar;
	reg_type upper;

	map_scalar_multiplication(reg_type & c, reg_type s) : carry(c), scalar(s) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

/*
	By the time main_action is called, end1, end are now closed intervals.
*/

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		*sub	= word_half_multiplication::multiply(upper, scalar, *ob) + carry;
		carry	= (*sub < carry) + upper;
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_action(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_right_closed::value)
		{
			*sub	= word_half_multiplication::multiply(upper, scalar, *ob) + carry;
			carry	= (*sub < carry) + upper;
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template
<
	size_type reg_length,
	typename sub_adjective, typename ob2_adjective, typename ob1_adjective, typename ob_adjective,
	typename ob2_type, typename ob1_type, typename sub_type

> struct map_multiplication
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	//

	using functor_main			= typename Power::template functor<object<Interval::closed, ob2_direction>>;

	using shallow_addition_main		= shallow_addition
						<
							reg_length,
							object<Interval::closed, sub_direction>,
							object<Interval::closed, ob2_direction>
						>;

	using scalar_main			= scalar_multiplication
						<
							reg_length,
							object<Interval::closed, ob2_direction>,
							object<Interval::closed, ob1_direction>
						>;

	//

	ob2_type begin2;
	ob2_type end2;

	ob1_type end1;

	sub_type begin;

	reg_type & carry;

	map_multiplication(reg_type & c, ob2_type b2, ob2_type e2, ob1_type e1, sub_type b) :

		carry(c), begin2(b2), end2(e2), end1(e1), begin(b) { }

	template<typename ob_type>
	inline void first_iteration(ob2_type & ob2, ob1_type & ob1, ob_type & ob)
	{
		ob2_adjective::first_iteration(ob2);
		ob1_adjective::first_iteration(ob1);
		ob_adjective::first_iteration(ob);
	}

/*
	By the time main_action is called, end1, end are now closed intervals.

	Set	sub identically equal to zero for the normal interpretation.
		ob2 = ob3 for the normal interpretation.

	This still needs to be robust against overloading.
*/

	template<typename ob_type>
	inline void main_action(ob2_type ob2, ob1_type ob1, ob_type ob)
	{
		functor_main::set(begin2, ob2, zero::value);

		carry = 0;
		scalar_main::multiply(carry, ob2, ob1, end1, *ob);

		carry = 0;
		shallow_addition_main::add(carry, begin, begin2, end2);
	}

	template<typename ob_type>
	inline void main_iteration(ob2_type & ob2, ob1_type & ob1, ob_type & ob)
	{
		ob2_adjective::main_iteration(ob2);
		ob1_adjective::main_iteration(ob1);
		ob_adjective::main_iteration(ob);
	}

	template<typename ob_type>
	inline void last_action(ob2_type ob2, ob1_type ob1, ob_type ob)
	{
		if (ob_adjective::is_right_closed::value)
		{
			functor_main::set(begin2, ob2, zero::value);

			carry = 0;
			scalar_main::multiply(carry, ob2, ob1, end1, *ob);

			carry = 0;
			shallow_addition_main::add(carry, begin, begin2, end2);
		}
	}
};

