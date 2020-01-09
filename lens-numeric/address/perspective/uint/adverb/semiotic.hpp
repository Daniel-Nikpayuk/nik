/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	
	map_add_assign
	map_add
	
	map_subtract_assign
	map_subtract
	
	map_scalar_multiply_assign
	map_scalar_multiply
	map_multiply

	map_root_divide_assign
	map_root_divide
	map_divide

	map_root_change_base
*/

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective, typename ob_adjective>
struct map_add_assign
{
	using reg_type = typename byte_type<reg_length>::reg_type;

	//

	reg_type & carry;

	map_add_assign(reg_type & c) : carry(c) { }

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
		if (ob_adjective::is_terminal_closed::value)
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
struct map_add
{
	using reg_type = typename byte_type<reg_length>::reg_type;

	//

	reg_type & carry;

	map_add(reg_type & c) : carry(c) { }

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
		if (ob_adjective::is_terminal_closed::value)
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
struct map_subtract_assign
{
	using reg_type = typename byte_type<reg_length>::reg_type;

	//

	reg_type & carry;
	reg_type sub_value;

	map_subtract_assign(reg_type & c) : carry(c) { }

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
		if (ob_adjective::is_terminal_closed::value)
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
struct map_subtract
{
	using reg_type = typename byte_type<reg_length>::reg_type;

	//

	reg_type & carry;

	map_subtract(reg_type & c) : carry(c) { }

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
		if (ob_adjective::is_terminal_closed::value)
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
struct map_scalar_multiply_assign
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	//

	using word_multiplication		= typename Word::uint::template multiplication
						<
							reg_length,
							Performance::specification
						>;

	//

	reg_type & carry;
	reg_type scalar;
	reg_type upper;

	map_scalar_multiply_assign(reg_type & c, reg_type s) : carry(c), scalar(s) { }

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
		*sub	= word_multiplication::multiply(upper, scalar, *sub) + carry;
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
		if (sub_adjective::is_terminal_closed::value)
		{
			*sub	= word_multiplication::multiply(upper, scalar, *sub) + carry;
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
struct map_scalar_multiply
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	//

	using word_multiplication		= typename Word::uint::template multiplication
						<
							reg_length,
							Performance::specification
						>;

	//

	reg_type & carry;
	reg_type scalar;
	reg_type upper;

	map_scalar_multiply(reg_type & c, reg_type s) : carry(c), scalar(s) { }

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
		*sub	= word_multiplication::multiply(upper, scalar, *ob) + carry;
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
		if (ob_adjective::is_terminal_closed::value)
		{
			*sub	= word_multiplication::multiply(upper, scalar, *ob) + carry;
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
	typename sub_type, typename ob2_type, typename ob1_type

> struct map_multiply
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	//

	using functor_main			= typename Power::template functor
						<
							typename ob2_adjective::initial_closed_type
						>;

	using addition_main			= addition
						<
							reg_length,
							Performance::specification,
							typename sub_adjective::initial_closed_type,
							typename ob2_adjective::initial_closed_type
						>;

	using scalar_main			= multiplication
						<
							reg_length,
							Performance::specification,
							typename ob2_adjective::initial_closed_type,
							object
							<
								ob1_adjective::close_initial::value,
								ob1_adjective::invert_direction::value
							>
						>;

	//

	sub_type begin;

	ob2_type begin2;
	ob2_type end2;

	ob1_type begin1;

	reg_type carry;

	map_multiply(sub_type b, ob2_type b2, ob2_type e2, ob1_type b1) :

		begin(b), begin2(b2), end2(e2), begin1(b1) { }

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
		scalar_main::multiply(carry, ob2, begin1, ob1, *ob);

		carry = 0;
		addition_main::add(carry, begin, begin2, end2);
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
		if (ob_adjective::is_terminal_closed::value)
		{
			functor_main::set(begin2, ob2, zero::value);

			carry = 0;
			scalar_main::multiply(carry, ob2, begin1, ob1, *ob);

			carry = 0;
			addition_main::add(carry, begin, begin2, end2);
		}
	}
};

/***********************************************************************************************************************/

template<size_type reg_length, typename sub_adjective>
struct map_root_divide_assign
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	//

	using word_division		= typename Word::uint::template division
					<
						reg_length,
						Performance::specification
					>;

	reg_type & remainder;
	reg_type divisor;

	map_root_divide_assign(reg_type & r, reg_type d) : remainder(r), divisor(d) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		sub_adjective::first_iteration(sub);
	}

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		*sub = word_division::root_type::divide(remainder, remainder, *sub, divisor);
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		sub_adjective::main_iteration(sub);
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		if (sub_adjective::is_terminal_closed::value)
		{
			*sub = word_division::root_type::divide(remainder, remainder, *sub, divisor);
		}
	}
};

/***********************************************************************************************************************/

template<size_type reg_length, typename sub_adjective, typename ob_adjective>
struct map_root_divide
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	//

	using word_division		= typename Word::uint::template division
					<
						reg_length,
						Performance::specification
					>;

	reg_type & remainder;
	reg_type divisor;

	map_root_divide(reg_type & r, reg_type d) : remainder(r), divisor(d) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		*sub = word_division::root_type::divide(remainder, remainder, *ob, divisor);
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
		if (ob_adjective::is_terminal_closed::value)
		{
			*sub = word_division::root_type::divide(remainder, remainder, *ob, divisor);
		}
	}
};

/***********************************************************************************************************************/

template<size_type reg_length, typename sub_adjective, typename ob_adjective>
struct map_divide
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	//

	using word_division		= typename Word::uint::template division
					<
						reg_length,
						Performance::specification
					>;

	reg_type & remainder;
	reg_type divisor;

	map_divide(reg_type & r, reg_type d) : remainder(r), divisor(d) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		*sub = word_division::divide(remainder, remainder, *ob, divisor);
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
		if (ob_adjective::is_terminal_closed::value)
		{
			*sub = word_division::divide(remainder, remainder, *ob, divisor);
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
	typename sub_adjective, typename ob_adjective,
	typename ob_type

> struct map_root_change_base
{
	using reg_type				= typename byte_type<reg_length>::reg_type;

	using zero				= typename Constant::template zero<reg_type>;

	using compare_zero_first		= typename Power::template compare_zero<ob_adjective>;
	using compare_zero_main			= typename Power::template compare_zero
						<
							typename ob_adjective::initial_closed_type
						>;

	//

	using generic				= typename Power::generic;

	using word_change_of_base		= typename Word::uint::template change_of_base
						<
							reg_length,
							Performance::specification,
							typename sub_adjective::initial_closed_type
						>;

	using division_main			= division
						<
							reg_length,
							Performance::specification,
							typename ob_adjective::initial_closed_type
						>;

	//

	ob_type end;

	reg_type remainder;
	reg_type divisor;

	compare_zero_first czf;
	compare_zero_main czm;

	map_root_change_base(ob_type e, reg_type d) : end(e), divisor(d) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);

		ob = generic::compare(czf, ob, end);
	}

/*
	By the time main_action is called, end1, end are now closed or closing intervals.
*/

	template<typename sub_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		remainder = zero::value;
		division_main::root_type::divide(remainder, ob, end, divisor);
		*sub = remainder;
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);

		ob = generic::compare(czm, ob, end);
	}

	template<typename sub_type>
	inline void last_action(sub_type & sub, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			sub = word_change_of_base::change_base(sub, *ob, divisor);
		}
	}
};

