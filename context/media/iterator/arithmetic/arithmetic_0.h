/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

#ifndef CONTEXT_MEDIA_ITERATOR_ARITHMETIC_0_H
#define CONTEXT_MEDIA_ITERATOR_ARITHMETIC_0_H

#include<stddef.h>

// overhead dependencies:

#include"../../../context/policy/policy.h"
#include"../../../semiotic/iterator/policy/policy.h"

// Clean up the typedefs/usings namespace stuff.

/*
	The main difference between "componentwise" and "arithmetic" from an algorithmic lens is that with componentwise is
	each location is conditionally independent, whereas arithmetic is similar but also dependent on the previous value
	(recursive; maybe the simplest variety of recursive?).

	Incrementing and decrementing pointers which should otherwise maintain a c_policy::unit location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using such unrolling in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.

	The policy for the location of the "carry" arguement is for it to always be at the front (the first arguement).
	As with componentwise, these generic clean recursive functions are most useful to combine and recombine by returning
	iterators (when such a return exists). They are designed to privilege iteration after all, these functions are
	primarily iterator oriented. Any other semantics are an afterthought. In the case of arithmetic functions,
	the final carry might need to be returned as part of such semantics, and the most convenient modification
	to calling such functions is to specify the template parameter of the carry type as a reference,
	and having the carry as the first arguement is most convenient to that end.

	Most of the time the carry is nothing more than overhead, but a few functions have the carry as semantically meaningful
	all on its own. In such cases, having the carry as the first arguement changes nothing regarding the above policy:
	There are no additional reasons to change the policy or make exception that I can think of.

	The basic comparison operators are special enough to implement additional optimized versions. This breaks with the
	general design of minimizing memory footprint for the sake of cycle efficiency. Keep in mind these are in addition
	to the standard implementations.
*/

namespace nik
{
 namespace context
 {
  namespace media
  {
   namespace iterator
   {
    namespace forward
    {
	template<typename SizeType>
	struct arithmetic_0
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::policy<size_type> s_policy;

		struct zero
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename RIterator, typename EIterator>
			static void no_break(RIterator in, EIterator end, bool & carry)
			{
				carry=true;
				s_policy::fwd_arit::zero::no_break(carry, in, end);
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator, typename EIterator>
				static bool no_break(RIterator in, EIterator end)
					{ return s_policy::fwd_arit::zero::fast::no_break(true, in, end); }
			};
		};

		struct equal
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static void no_break(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=true;
				s_policy::fwd_arit::equal::no_break(carry, in1, in2, end2);
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool no_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
					{ return s_policy::fwd_arit::equal::fast::no_break(true, in1, in2, end2); }
			};
		};

		struct not_equal
		{
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static void no_break(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=false;
				s_policy::fwd_arit::not_equal::no_break(carry, in1, in2, end2);
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool no_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
					{ return s_policy::fwd_arit::not_equal::fast::no_break(false, in1, in2, end2); }
			};
		};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	end2 is the terminal location of the right operand.
*/
		struct less_than
		{
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static void no_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=false;
				s_policy::fwd_arit::less_than::no_return(carry, in1, in2, end2);
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator1 with_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=false;
				return s_policy::fwd_arit::less_than::with_return(carry, in1, in2, end2);
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{ return s_policy::fwd_arit::less_than::fast_return(false, in1, in2, end2); }

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, size_type order1, size_type order2)
				{ return s_policy::fwd_arit::less_than::fast_return(false, in1, in2, end2, order1, order2); }
		};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	end2 is the terminal location of the right operand.
*/
		struct less_than_or_equal
		{
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static void no_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=true;
				s_policy::fwd_arit::less_than_or_equal::no_return(carry, in1, in2, end2);
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator1 with_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=true;
				return s_policy::fwd_arit::less_than_or_equal::with_return(carry, in1, in2, end2);
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{ return s_policy::fwd_arit::less_than_or_equal::fast_return(true, in1, in2, end2); }

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, size_type order1, size_type order2)
				{ return s_policy::fwd_arit::less_than_or_equal::fast_return(true, in1, in2, end2, order1, order2); }
					
		};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	end2 is the terminal location of the right operand.
*/
		struct greater_than
		{
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static void no_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=false;
				s_policy::fwd_arit::greater_than::no_return(carry, in1, in2, end2);
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator1 with_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=false;
				return s_policy::fwd_arit::greater_than::with_return(carry, in1, in2, end2);
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{ return s_policy::fwd_arit::greater_than::fast_return(false, in1, in2, end2); }

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, size_type order1, size_type order2)
				{ return s_policy::fwd_arit::greater_than::fast_return(false, in1, in2, end2, order1, order2); }
					
		};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	end2 is the terminal location of the right operand.
*/
		struct greater_than_or_equal
		{
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static void no_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=true;
				s_policy::fwd_arit::greater_than_or_equal::no_return(carry, in1, in2, end2);
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator1 with_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=true;
				return s_policy::fwd_arit::greater_than_or_equal::with_return(carry, in1, in2, end2);
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{ return s_policy::fwd_arit::greater_than_or_equal::fast_return(true, in1, in2, end2); }

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(RIterator1 in1, RIterator2 in2, EIterator2 end2, size_type order1, size_type order2)
				{ return s_policy::fwd_arit::greater_than_or_equal::fast_return(true, in1, in2, end2, order1, order2); }
					
		};
/*
	carry needs to be set to 0 for the "normal" interpretation.

	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 < *in1, *in2.
	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 + 1 will not cause a second such overflow.
*/
		struct plus
		{
			template<typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2, typename ValueType>
			static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2, ValueType & carry)
			{
				carry=0;
				s_policy::fwd_arit::plus::no_return(carry, out, in1, in2, end2);
			}

			template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
			static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
				{ s_policy::fwd_arit::plus::no_return((ValueType) 0, out, in1, in2, end2); }

			template<typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2, typename ValueType>
			static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2, ValueType & carry)
			{
				carry=0;
				return s_policy::fwd_arit::plus::with_return(carry, out, in1, in2, end2);
			}

			template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
			static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
				{ return s_policy::fwd_arit::plus::with_return((ValueType) 0, out, in1, in2, end2); }
/*
	If an arithmetic overflow occurs beyond the half, it will only effect the first digit above.
*/
			struct half
			{
				template<typename WIterator, typename RIterator1,
					typename RIterator2, typename ERIterator2, typename ValueType>
				static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2, ValueType & carry)
				{
					carry=0;
					s_policy::fwd_arit::plus::half::no_return(carry, out, in1, in2, end2);
				}

				template<typename ValueType, typename WIterator,
					typename RIterator1, typename RIterator2, typename ERIterator2>
				static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
					{ s_policy::fwd_arit::plus::half::no_return((ValueType) 0, out, in1, in2, end2); }

				template<typename WIterator, typename RIterator1,
					typename RIterator2, typename ERIterator2, typename ValueType>
				static WIterator with_return(WIterator out,
					RIterator1 in1, RIterator2 in2, ERIterator2 end2, ValueType & carry)
				{
					carry=0;
					return s_policy::fwd_arit::plus::half::with_return(carry, out, in1, in2, end2);
				}

				template<typename ValueType, typename WIterator,
					typename RIterator1, typename RIterator2, typename ERIterator2>
				static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
					{ return s_policy::fwd_arit::plus::half::with_return((ValueType) 0, out, in1, in2, end2); }
			};
		};
/*
	carry needs to be set to 0 for the "normal" interpretation.

	Regarding arithmetic overflow, there are a few considerations:
	*out = *in1 - (carry + *in2) ==> *out + (carry + *in2) = *in1 
	It's possible (carry + *in2) is an overflow, but this implies carry == 1 and *in2 == b-1.
	As such, with an assumed overflow, the new carry would be true, and we need not worry about a "double carry"
	as (carry + *in2) would equal zero, and so *out == *in1 - (carry + *in2) == *in1.
	Otherwise, if (*in2+carry) has no overflow, then *in1 == carry + *out,
	and so we check for an overflow there by means of the test (*in1 < *out).
*/
		struct minus
		{
			template<typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2, typename ValueType>
			static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2, ValueType & carry)
			{
				carry=0;
				s_policy::fwd_arit::minus::no_return(carry, out, in1, in2, end2);
			}

			template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
			static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
				{ s_policy::fwd_arit::minus::no_return((ValueType) 0, out, in1, in2, end2); }

			template<typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2, typename ValueType>
			static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2, ValueType & carry)
			{
				carry=0;
				return s_policy::fwd_arit::minus::with_return(carry, out, in1, in2, end2);
			}

			template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
			static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
				{ return s_policy::fwd_arit::minus::with_return((ValueType) 0, out, in1, in2, end2); }

			struct half
			{
				template<typename WIterator, typename RIterator1,
					typename RIterator2, typename ERIterator2, typename ValueType>
				static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2, ValueType & carry)
				{
					carry=0;
					s_policy::fwd_arit::minus::half::no_return(carry, out, in1, in2, end2);
				}

				template<typename ValueType, typename WIterator,
					typename RIterator1, typename RIterator2, typename ERIterator2>
				static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
					{ s_policy::fwd_arit::minus::half::no_return((ValueType) 0, out, in1, in2, end2); }

				template<typename WIterator, typename RIterator1,
					typename RIterator2, typename ERIterator2, typename ValueType>
				static WIterator with_return(WIterator out,
					RIterator1 in1, RIterator2 in2, ERIterator2 end2, ValueType & carry)
				{
					carry=0;
					return s_policy::fwd_arit::minus::half::with_return(carry, out, in1, in2, end2);
				}

				template<typename ValueType, typename WIterator,
					typename RIterator1, typename RIterator2, typename ERIterator2>
				static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
					{ return s_policy::fwd_arit::minus::half::with_return((ValueType) 0, out, in1, in2, end2); }
			};
		};
/*
	scale:
		This is the half-register version (each dereferenced ValueType is assumed <= half-register size).
		As such, it requires no additional dependencies.

		carry is the overhead value. Set this to zero for the "normal" interpretation.
		out is the resultant containing structure.
		in1 is the initial containing structure.
		end1 is the end location of the input containing structure.
		in2 is the c_policy::unit scalar value.

		All ValueTypes are under the constraint of being less than the half register size.
*/
		struct scale
		{
			struct half
			{
				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static void no_return(WIterator out, RIterator in, ERIterator end, ValueType value, ValueType & carry)
				{
					carry=0;
					s_policy::fwd_arit::scale::half::no_return(carry, out, in, end, value);
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static void no_return(WIterator out, RIterator in, ERIterator end, ValueType value)
					{ s_policy::fwd_arit::scale::half::no_return((ValueType) 0, out, in, end, value); }

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static WIterator with_return(WIterator out, RIterator in, ERIterator end, ValueType value, ValueType & carry)
				{
					carry=0;
					return s_policy::fwd_arit::scale::half::with_return(carry, out, in, end, value);
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static WIterator with_return(WIterator out, RIterator in, ERIterator end, ValueType value)
					{ return s_policy::fwd_arit::scale::half::with_return((ValueType) 0, out, in, end, value); }
			};
		};

		struct right_shift
		{
/*
	For the "natural" right_shift,
	define in2 = ++RIterator(in1),
	as well as n = c_policy::unit::length-m,
	finally, *out=(*in1>>m) needs appending.
*/
			template<typename ValueType, typename WIterator, typename EWIterator, typename RIterator1, typename ERIterator1>
			static void no_return(WIterator out, EWIterator end, RIterator1 in1, ERIterator1 end1, size_type n)
			{
				s_policy::fwd_comp::right_shift::template no_return
					<WIterator&, RIterator1&>(out, in1, ++RIterator1(in1), end1, n, c_policy::unit::length-n);
				*out=(*in1>>n);

				s_policy::fwd_comp::repeat::no_return(++out, end, (ValueType) 0);
			}
/*
	For the "natural" right_shift,
	define in2 = ++RIterator(in1),
	as well as n = c_policy::unit::length-m,
	finally, *out=(*in1>>m) needs appending.
*/
			template<typename ValueType, typename WIterator, typename EWIterator, typename RIterator1, typename ERIterator1>
			static WIterator with_return(WIterator out, EWIterator end, RIterator1 in1, ERIterator1 end1, size_type n)
			{
				s_policy::fwd_comp::right_shift::template no_return
					<WIterator&, RIterator1&>(out, in1, ++RIterator1(in1), end1, n, c_policy::unit::length-n);
				*out=(*in1>>n);

				return s_policy::fwd_comp::repeat::with_return(++out, end, (ValueType) 0);
			}
		};

		struct assign
		{
/*
	carry needs to be set to 0 for the "normal" interpretation.

	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 < *in1, *in2.
	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 + 1 will not cause a second such overflow.
*/
			struct plus
			{
				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static void no_return(WIterator out, RIterator in, ERIterator end, ValueType & carry)
				{
					carry=0;
					s_policy::fwd_arit::assign::plus::no_return(carry, out, in, end);
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static void no_return(WIterator out, RIterator in, ERIterator end)
					{ s_policy::fwd_arit::assign::plus::no_return((ValueType) 0, out, in, end); }

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static WIterator with_return(WIterator out, RIterator in, ERIterator end, ValueType & carry)
				{
					carry=0;
					return s_policy::fwd_arit::assign::plus::with_return(carry, out, in, end);
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static WIterator with_return(WIterator out, RIterator in, ERIterator end)
					{ return s_policy::fwd_arit::assign::plus::with_return((ValueType) 0, out, in, end); }
/*
	If an arithmetic overflow occurs beyond the half, it will only effect the first digit above.
*/
				struct half
				{
					template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
					static void no_return(WIterator out, RIterator in, ERIterator end, ValueType & carry)
					{
						carry=0;
						s_policy::fwd_arit::assign::plus::half::no_return(carry, out, in, end);
					}

					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static void no_return(WIterator out, RIterator in, ERIterator end)
						{ s_policy::fwd_arit::assign::plus::half::no_return((ValueType) 0, out, in, end); }

					template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
					static WIterator with_return(WIterator out, RIterator in, ERIterator end, ValueType & carry)
					{
						carry=0;
						return s_policy::fwd_arit::assign::plus::half::with_return(carry, out, in, end);
					}

					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static WIterator with_return(WIterator out, RIterator in, ERIterator end)
						{ return s_policy::fwd_arit::assign::plus::half::with_return((ValueType) 0, out, in, end); }
				};
			};
/*
	carry needs to be set to 0 for the "normal" interpretation.

	Regarding arithmetic overflow, there are a few considerations:
	*out = *in1 - (carry + *in2) ==> *out + (carry + *in2) = *in1 
	It's possible (carry + *in2) is an overflow, but this implies carry == 1 and *in2 == b-1.
	As such, with an assumed overflow, the new carry would be true, and we need not worry about a "double carry"
	as (carry + *in2) would equal zero, and so *out == *in1 - (carry + *in2) == *in1.
	Otherwise, if (*in2+carry) has no overflow, then *in1 == carry + *out,
	and so we check for an overflow there by means of the test (*in1 < *out).
*/
			struct minus
			{
				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static void no_return(WIterator out, RIterator in, ERIterator end, ValueType & carry)
				{
					carry=0;
					s_policy::fwd_arit::assign::minus::no_return(carry, out, in, end);
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static void no_return(WIterator out, RIterator in, ERIterator end)
					{ s_policy::fwd_arit::assign::minus::no_return((ValueType) 0, out, in, end); }

				template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
				static WIterator with_return(WIterator out, RIterator in, ERIterator end, ValueType & carry)
				{
					carry=0;
					return s_policy::fwd_arit::assign::minus::with_return(carry, out, in, end);
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static WIterator with_return(WIterator out, RIterator in, ERIterator end)
					{ return s_policy::fwd_arit::assign::minus::with_return((ValueType) 0, out, in, end); }

				struct half
				{
					template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
					static void no_return(WIterator out, RIterator in, ERIterator end, ValueType & carry)
					{
						carry=0;
						s_policy::fwd_arit::assign::minus::half::no_return(carry, out, in, end);
					}

					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static void no_return(WIterator out, RIterator in, ERIterator end)
						{ s_policy::fwd_arit::assign::minus::half::no_return((ValueType) 0, out, in, end); }

					template<typename WIterator, typename RIterator, typename ERIterator, typename ValueType>
					static WIterator with_return(WIterator out, RIterator in, ERIterator end, ValueType & carry)
					{
						carry=0;
						return s_policy::fwd_arit::assign::minus::half::with_return(carry, out, in, end);
					}

					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static WIterator with_return(WIterator out, RIterator in, ERIterator end)
						{ return s_policy::fwd_arit::assign::minus::half::with_return((ValueType) 0, out, in, end); }
				};
			};
/*
	scale:
		This is the half-register version (each dereferenced ValueType is assumed <= half-register size).
		As such, it requires no additional dependencies.

		carry is the overhead value. Set this to zero for the "normal" interpretation.
		out is the resultant containing structure.
		in1 is the initial containing structure.
		end1 is the end location of the input containing structure.
		in2 is the c_policy::unit scalar value.

		All ValueTypes are under the constraint of being less than the half register size.
*/
			struct scale
			{
				struct half
				{
					template<typename WIterator, typename EIterator, typename ValueType>
					static void no_return(WIterator out, EIterator end, ValueType value, ValueType & carry)
					{
						carry=0;
						s_policy::fwd_arit::assign::scale::half::no_return(carry, out, end);
					}

					template<typename ValueType, typename WIterator, typename EIterator>
					static void no_return(WIterator out, EIterator end, ValueType value)
						{ s_policy::fwd_arit::assign::scale::half::no_return((ValueType) 0, out, end); }

					template<typename WIterator, typename EIterator, typename ValueType>
					static WIterator with_return(WIterator out, EIterator end, ValueType value, ValueType & carry)
					{
						carry=0;
						return s_policy::fwd_arit::assign::scale::half::with_return(carry, out, end);
					}

					template<typename ValueType, typename WIterator, typename EIterator>
					static WIterator with_return(WIterator out, EIterator end, ValueType value)
						{ return s_policy::fwd_arit::assign::scale::half::with_return((ValueType) 0, out, end); }
				};
			};

			struct right_shift
			{
/*
	For the "natural" right_shift,
	define in = ++out,
	as well as n = c_policy::unit::length-m,
	finally, *out>>=m needs appending.
*/
				template<typename ValueType, typename WIterator, typename EWIterator>
				static void no_return(WIterator out, EWIterator end, size_type n)
				{
					s_policy::fwd_comp::assign::right_shift::template no_return
						<WIterator&>(out, ++WIterator(out), end, n, c_policy::unit::length-n);
					*out>>=n;

					s_policy::fwd_comp::repeat::no_return(++out, end, (ValueType) 0);
				}
/*
	For the "natural" right_shift,
	define in = ++out,
	as well as n = c_policy::unit::length-m,
	finally, *out>>=m needs appending.
*/
				template<typename ValueType, typename WIterator, typename EWIterator>
				static WIterator with_return(WIterator out, EWIterator end, size_type n)
				{
					s_policy::fwd_comp::assign::right_shift::template no_return
						<WIterator&>(out, ++WIterator(out), end, n, c_policy::unit::length-n);
					*out>>=n;

					return s_policy::fwd_comp::repeat::with_return(++out, end, (ValueType) 0);
				}
			};
		};
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Explicit specialization isn't allowed. Template parameters are of an arbitrary but fixed type.
			As such one factoring all such parameters into a single template is effective.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_0
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct zero
			{
				template<typename Iterator>
				static void no_break(Iterator in, bool & carry)
				{
					carry=true;
					s_policy::template fwd_arit_unroll<N, M, L>::zero::no_break(carry, in);
				}

				struct fast
				{
					template<typename Iterator>
					static bool no_break(Iterator in)
						{ return s_policy::template fwd_arit_unroll<N, M, L>::zero::fast::no_break(true, in); }
				};
			};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_break(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=true;
					s_policy::template fwd_arit_unroll<N, M, L>::equal::no_break(carry, in1, in2);
				}

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(Iterator1 in1, Iterator2 in2)
						{ return s_policy::template fwd_arit_unroll<N, M, L>::equal::fast::no_break(true, in1, in2); }
				};
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_break(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=false;
					s_policy::template fwd_arit_unroll<N, M, L>::not_equal::no_break(carry, in1, in2);
				}

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(Iterator1 in1, Iterator2 in2)
						{ return s_policy::template fwd_arit_unroll<N, M, L>::not_equal::fast::no_break(false, in1, in2); }
				};
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct less_than
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=false;
					s_policy::template fwd_arit_unroll<N, M, L>::less_than::no_return(carry, in1, in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=false;
					return s_policy::template fwd_arit_unroll<N, M, L>::less_than::with_return(carry, in1, in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(Iterator1 in1, Iterator2 in2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::less_than::fast_return(false, in1, in2); }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::less_than::fast_return(false, in1, in2, order1, order2); }
			};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct less_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=true;
					s_policy::template fwd_arit_unroll<N, M, L>::less_than_or_equal::no_return(carry, in1, in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=true;
					return s_policy::template fwd_arit_unroll<N, M, L>::less_than_or_equal::with_return(carry, in1, in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(Iterator1 in1, Iterator2 in2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::less_than_or_equal::fast_return(true, in1, in2); }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::
						less_than_or_equal::fast_return(true, in1, in2, order1, order2); }
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct greater_than
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=false;
					s_policy::template fwd_arit_unroll<N, M, L>::greater_than::no_return(carry, in1, in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=false;
					return s_policy::template fwd_arit_unroll<N, M, L>::greater_than::with_return(carry, in1, in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(Iterator1 in1, Iterator2 in2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::greater_than::fast_return(false, in1, in2); }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::greater_than::fast_return(false, in1, in2, order1, order2); }
			};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct greater_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=true;
					s_policy::template fwd_arit_unroll<N, M, L>::greater_than_or_equal::no_return(carry, in1, in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=true;
					return s_policy::template fwd_arit_unroll<N, M, L>::greater_than_or_equal::with_return(carry, in1, in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(Iterator1 in1, Iterator2 in2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::greater_than_or_equal::fast_return(true, in1, in2); }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::
						greater_than_or_equal::fast_return(true, in1, in2, order1, order2); }
			};
/*
	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 < *in1, *in2.
	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 + 1 will not cause a second such overflow.
*/
			struct plus
			{
				template<typename WIterator, typename RIterator1, typename RIterator2, typename ValueType>
				static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ValueType & carry)
				{
					carry=0;
					s_policy::template fwd_arit_unroll<N, M, L>::plus::no_return(carry, out, in1, in2);
				}

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static void no_return(WIterator out, RIterator1 in1, RIterator2 in2)
					{ s_policy::template fwd_arit_unroll<N, M, L>::plus::no_return((ValueType) 0, out, in1, in2); }

				template<typename WIterator, typename RIterator1, typename RIterator2, typename ValueType>
				static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ValueType & carry)
				{
					carry=0;
					return s_policy::template fwd_arit_unroll<N, M, L>::plus::with_return(carry, out, in1, in2);
				}

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::plus::with_return((ValueType) 0, out, in1, in2); }
/*
	If an arithmetic overflow occurs beyond the half, it will only effect the first digit above.
*/
				struct half
				{
					template<typename WIterator, typename RIterator1, typename RIterator2, typename ValueType>
					static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ValueType & carry)
					{
						carry=0;
						s_policy::template fwd_arit_unroll<N, M, L>::plus::half::no_return(carry, out, in1, in2);
					}

					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static void no_return(WIterator out, RIterator1 in1, RIterator2 in2)
						{ s_policy::template fwd_arit_unroll<N, M, L>::plus::half::no_return((ValueType) 0, out, in1, in2); }

					template<typename WIterator, typename RIterator1, typename RIterator2, typename ValueType>
					static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ValueType & carry)
					{
						carry=0;
						return s_policy::template fwd_arit_unroll<N, M, L>::plus::half::with_return(carry, out, in1, in2);
					}

					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2)
						{ return s_policy::template fwd_arit_unroll<N, M, L>::plus::half::with_return((ValueType) 0, out, in1, in2); }
				};
			};
/*
	carry needs to be set to 0 for the "normal" interpretation.

	Regarding arithmetic overflow, there are a few considerations:
	*out = *in1 - (carry + *in2) ==> *out + (carry + *in2) = *in1 
	It's possible (carry + *in2) is an overflow, but this implies carry == 1 and *in2 == b-1.
	As such, with an assumed overflow, the new carry would be true, and we need not worry about a "double carry"
	as (carry + *in2) would equal zero, and so *out == *in1 - (carry + *in2) == *in1.
	Otherwise, if (*in2+carry) has no overflow, then *in1 == carry + *out,
	and so we check for an overflow there by means of the test (*in1 < *out).
*/
			struct minus
			{
				template<typename WIterator, typename RIterator1, typename RIterator2, typename ValueType>
				static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ValueType & carry)
				{
					carry=0;
					s_policy::template fwd_arit_unroll<N, M, L>::minus::no_return(carry, out, in1, in2);
				}

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static void no_return(WIterator out, RIterator1 in1, RIterator2 in2)
					{ s_policy::template fwd_arit_unroll<N, M, L>::minus::no_return((ValueType) 0, out, in1, in2); }

				template<typename WIterator, typename RIterator1, typename RIterator2, typename ValueType>
				static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ValueType & carry)
				{
					carry=0;
					return s_policy::template fwd_arit_unroll<N, M, L>::minus::with_return(carry, out, in1, in2);
				}

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2)
					{ return s_policy::template fwd_arit_unroll<N, M, L>::minus::with_return((ValueType) 0, out, in1, in2); }

				struct half
				{
					template<typename WIterator, typename RIterator1, typename RIterator2, typename ValueType>
					static void no_return(WIterator out, RIterator1 in1, RIterator2 in2, ValueType & carry)
					{
						carry=0;
						s_policy::template fwd_arit_unroll<N, M, L>::minus::half::no_return(carry, out, in1, in2);
					}

					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static void no_return(WIterator out, RIterator1 in1, RIterator2 in2)
						{ s_policy::template fwd_arit_unroll<N, M, L>::minus::half::no_return((ValueType) 0, out, in1, in2); }

					template<typename WIterator, typename RIterator1, typename RIterator2, typename ValueType>
					static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2, ValueType & carry)
					{
						carry=0;
						return s_policy::template fwd_arit_unroll<N, M, L>::minus::half::with_return(carry, out, in1, in2);
					}

					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static WIterator with_return(WIterator out, RIterator1 in1, RIterator2 in2)
						{ return s_policy::template fwd_arit_unroll<N, M, L>::minus::half::with_return((ValueType) 0, out, in1, in2); }
				};
			};

			struct scale
			{
				struct half
				{
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.

	All ValueTypes are under the constraint of being less than the half register size.
*/
					template<typename WIterator, typename RIterator, typename ValueType>
					static void no_return(WIterator out, RIterator in1, ValueType in2, ValueType & carry)
					{
						carry=0;
						s_policy::template fwd_arit_unroll<N, M, L>::scale::half::no_return(carry, out, in1, in2);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(WIterator out, RIterator in1, ValueType in2)
					{ s_policy::template fwd_arit_unroll<N, M, L>::
						scale::half::no_return((ValueType) 0, out, in1, in2);
					}
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.

	All ValueTypes are under the constraint of being less than the half register size.
*/
					template<typename WIterator, typename RIterator, typename ValueType>
					static WIterator with_return(WIterator out, RIterator in1, ValueType in2, ValueType & carry)
					{
						carry=0;
						return s_policy::template fwd_arit_unroll<N, M, L>::
							scale::half::with_return(carry, out, in1, in2);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(WIterator out, RIterator in1, ValueType in2)
					{
						return s_policy::template fwd_arit_unroll<N, M, L>::
							scale::half::with_return((ValueType) 0, out, in1, in2);
					}
				};
			};

			struct right_shift
			{
/*
	For the "natural" right_shift,
	define in2 = ++RIterator(in1),
	as well as n = c_policy::unit::length-m,
	finally, *out=(*in1>>m) needs appending.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1>>m); }.
	Do not add (*in2<<n) as in this specialization, in2 may be past the boundary.
*/
				template<typename ValueType, typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in, size_type n)
				{
					s_policy::template fwd_comp_unroll<M-1>::right_shift::template no_return
						<WIterator&, RIterator&>(out, in, ++RIterator(in), n, c_policy::unit::length-n);
					*out=(*in>>n);

					s_policy::template fwd_comp_unroll<N-M>::repeat::no_return(++out, (ValueType) 0);
				}
/*
	For the "natural" right_shift,
	define in2 = ++RIterator(in1),
	as well as n = c_policy::unit::length-m,
	finally, *out=(*in1>>m) needs appending.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1>>m); }.
	Do not add (*in2<<n) as in this specialization, in2 may be past the boundary.
*/
				template<typename ValueType, typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in, size_type n)
				{
					s_policy::template fwd_comp_unroll<M-1>::right_shift::template no_return
						<WIterator&, RIterator&>(out, in, ++RIterator(in), n, c_policy::unit::length-n);
					*out=(*in>>n);

					return s_policy::template fwd_comp_unroll<N-M>::repeat::with_return(++out, (ValueType) 0);
				}
			};

			struct assign
			{
				struct plus
				{
					template<typename WIterator, typename RIterator, typename ValueType>
					static void no_return(WIterator out, RIterator in, ValueType & carry)
					{
						carry=0;
						s_policy::template fwd_arit_unroll<N, M, L>::assign::plus::no_return(carry, out, in);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(WIterator out, RIterator in)
						{ s_policy::template fwd_arit_unroll<N, M, L>::assign::plus::no_return((ValueType) 0, out, in); }

					template<typename WIterator, typename RIterator, typename ValueType>
					static WIterator with_return(WIterator out, RIterator in, ValueType & carry)
					{
						carry=0;
						return s_policy::template fwd_arit_unroll<N, M, L>::assign::plus::with_return(carry, out, in);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(WIterator out, RIterator in)
						{ return s_policy::template fwd_arit_unroll<N, M, L>::assign::plus::with_return((ValueType) 0, out, in); }
/*
	If an arithmetic overflow occurs beyond the half, it will only effect the first digit above.
*/
					struct half
					{
						template<typename WIterator, typename RIterator, typename ValueType>
						static void no_return(WIterator out, RIterator in, ValueType & carry)
						{
							carry=0;
							s_policy::template fwd_arit_unroll<N, M, L>::assign::plus::half::no_return(carry, out, in);
						}

						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(WIterator out, RIterator in)
							{ s_policy::template fwd_arit_unroll<N, M, L>::assign::plus::half::no_return((ValueType) 0, out, in); }

						template<typename WIterator, typename RIterator, typename ValueType>
						static WIterator with_return(WIterator out, RIterator in, ValueType & carry)
						{
							carry=0;
							return s_policy::template fwd_arit_unroll<N, M, L>::assign::plus::half::with_return(carry, out, in);
						}

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(WIterator out, RIterator in)
							{ return s_policy::template fwd_arit_unroll<N, M, L>::assign::
								plus::half::with_return((ValueType) 0, out, in); }
					};
				};
/*
	Two ValueTypes are relevant as one might be a reference while the other is not.

	carry needs to be set to 0 for the "normal" interpretation.
*/
				struct minus
				{
					template<typename WIterator, typename RIterator, typename ValueType>
					static void no_return(WIterator out, RIterator in, ValueType & carry)
					{
						carry=0;
						s_policy::template fwd_arit_unroll<N, M, L>::assign::minus::no_return(carry, out, in);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(WIterator out, RIterator in)
						{ s_policy::template fwd_arit_unroll<N, M, L>::assign::minus::no_return((ValueType) 0, out, in); }

					template<typename WIterator, typename RIterator, typename ValueType>
					static WIterator with_return(WIterator out, RIterator in, ValueType & carry)
					{
						carry=0;
						return s_policy::template fwd_arit_unroll<N, M, L>::assign::minus::with_return(carry, out, in);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(WIterator out, RIterator in)
						{ return s_policy::template fwd_arit_unroll<N, M, L>::assign::minus::with_return((ValueType) 0, out, in); }

					struct half
					{
						template<typename WIterator, typename RIterator, typename ValueType>
						static void no_return(WIterator out, RIterator in, ValueType & carry)
						{
							carry=0;
							s_policy::template fwd_arit_unroll<N, M, L>::assign::minus::half::no_return(carry, out, in);
						}

						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(WIterator out, RIterator in)
							{ s_policy::template fwd_arit_unroll<N, M, L>::assign::minus::half::no_return((ValueType) 0, out, in); }

						template<typename WIterator, typename RIterator, typename ValueType>
						static WIterator with_return(WIterator out, RIterator in, ValueType & carry)
						{
							carry=0;
							return s_policy::template fwd_arit_unroll<N, M, L>::assign::minus::half::with_return(carry, out, in);
						}

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(WIterator out, RIterator in)
							{ return s_policy::template fwd_arit_unroll<N, M, L>::assign::
								minus::half::with_return((ValueType) 0, out, in); }
					};
				};

				struct scale
				{
					struct half
					{
						template<typename WIterator, typename ValueType>
						static void no_return(WIterator out, ValueType value, ValueType & carry)
						{
							carry=0;
							s_policy::template fwd_arit_unroll<N, M, L>::assign::scale::half::no_return(carry, out, value);
						}

						template<typename ValueType, typename WIterator>
						static void no_return(WIterator out, ValueType value)
							{ s_policy::template fwd_arit_unroll<N, M, L>::assign::
								scale::half::no_return((ValueType) 0, out, value); }

						template<typename WIterator, typename ValueType>
						static WIterator with_return(WIterator out, ValueType value, ValueType & carry)
						{
							carry=0;
							return s_policy::template fwd_arit_unroll<N, M, L>::assign::scale::half::with_return(carry, out, value);
						}

						template<typename ValueType, typename WIterator>
						static WIterator with_return(WIterator out, ValueType value)
							{ return s_policy::template fwd_arit_unroll<N, M, L>::assign::
								scale::half::with_return((ValueType) 0, out, value); }
					};
				};

				struct right_shift
				{
/*
	For the "natural" right_shift,
	define in = ++out,
	as well as n = c_policy::unit::length-m,
	finally, *out>>=m needs appending.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1>>m); }.
	Do not add (*in2<<n) as in this specialization, in2 may be past the boundary.
*/
					template<typename ValueType, typename WIterator>
					static void no_return(WIterator out, size_type n)
					{
						s_policy::template fwd_comp_unroll<M-1>::assign::right_shift::template no_return
							<WIterator&>(out, ++WIterator(out), n, c_policy::unit::length-n);
						*out>>=n;

						s_policy::template fwd_comp_unroll<N-M>::repeat::no_return(++out, (ValueType) 0);
					}
/*
	For the "natural" right_shift,
	define in = ++out,
	as well as n = c_policy::unit::length-m,
	finally, *out>>=m needs appending.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1>>m); }.
	Do not add (*in2<<n) as in this specialization, in2 may be past the boundary.
*/
					template<typename ValueType, typename WIterator>
					static WIterator with_return(WIterator out, size_type n)
					{
						s_policy::template fwd_comp_unroll<M-1>::assign::right_shift::template no_return
							<WIterator&>(out, ++WIterator(out), n, c_policy::unit::length-n);
						*out>>=n;

						return s_policy::template fwd_comp_unroll<N-M>::repeat::with_return(++out, (ValueType) 0);
					}
				};
			};
		};
	};
    }

    namespace backward
    {
	template<typename SizeType>
	struct arithmetic_0
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::policy<size_type> s_policy;

		struct zero
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename RIterator, typename EIterator>
			static void no_break(RIterator in, EIterator end, bool & carry)
			{
				carry=true;
				s_policy::bwd_arit::zero::no_break(carry, in, end);
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator, typename EIterator>
				static bool no_break(RIterator in, EIterator end)
					{ return s_policy::bwd_arit::zero::fast::no_break(true, in, end); }
			};
		};

		struct equal
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static void no_break(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=true;
				s_policy::bwd_arit::equal::no_break(carry, in1, in2, end2);
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool no_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
					{ return s_policy::bwd_arit::equal::fast::no_break(true, in1, in2, end2); }
			};
		};

		struct not_equal
		{
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static void no_break(RIterator1 in1, RIterator2 in2, EIterator2 end2, bool & carry)
			{
				carry=false;
				s_policy::bwd_arit::not_equal::no_break(carry, in1, in2, end2);
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool no_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
					{ return s_policy::bwd_arit::not_equal::fast::no_break(false, in1, in2, end2); }
			};
		};

		struct left_shift
		{
/*
	For the "natural" left_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = --RIterator(in1),
	as well as n = c_policy::unit::length-m.
*/
			template<typename ValueType, typename WIterator, typename EWIterator, typename RIterator1, typename ERIterator1>
			static void no_return(WIterator out, EWIterator end, RIterator1 in1, ERIterator1 end1, size_type n)
			{
				s_policy::bwd_comp::left_shift::template no_return
					<WIterator&, RIterator1&>(out, in1, --RIterator1(in1), end1, n, c_policy::unit::length-n);
				*out=(*in1<<n);

				s_policy::bwd_comp::repeat::no_return(--out, end, (ValueType) 0);
			}

			template<typename ValueType, typename WIterator, typename EWIterator, typename RIterator1, typename ERIterator1>
			static WIterator with_return(WIterator out, EWIterator end, RIterator1 in1, ERIterator1 end1, size_type n)
			{
				s_policy::bwd_comp::left_shift::template no_return
					<WIterator&, RIterator1&>(out, in1, --RIterator1(in1), end1, n, c_policy::unit::length-n);
				*out=(*in1<<n);

				return s_policy::bwd_comp::repeat::with_return(--out, end, (ValueType) 0);
			}
		};

		struct assign
		{
			struct left_shift
			{
/*
	For the "natural" left_shift,
	define in = --out,
	as well as n = c_policy::unit::length-m,
	finally, *out<<=m needs appending.
*/
				template<typename ValueType, typename WIterator, typename EWIterator>
				static void no_return(WIterator out, EWIterator end, size_type n)
				{
					s_policy::bwd_comp::assign::left_shift::template no_return
						<WIterator&>(out, --WIterator(out), end, n, c_policy::unit::length-n);
					*out<<=n;

					s_policy::bwd_comp::repeat::no_return(--out, end, (ValueType) 0);
				}

				template<typename ValueType, typename WIterator, typename EWIterator>
				static WIterator with_return(WIterator out, EWIterator end, size_type n)
				{
					s_policy::bwd_comp::assign::left_shift::template no_return
						<WIterator&>(out, --WIterator(out), end, n, c_policy::unit::length-n);
					*out<<=n;

					return s_policy::bwd_comp::repeat::with_return(--out, end, (ValueType) 0);
				}
			};
		};
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Explicit specialization isn't allowed. Template parameters are of an arbitrary but fixed type.
			As such one factoring all such parameters into a single template is effective.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_0
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct zero
			{
				template<typename Iterator>
				static void no_break(Iterator in, bool & carry)
				{
					carry=true;
					s_policy::template bwd_arit_unroll_0<N, M, L>::zero::no_break(carry, in);
				}

				struct fast
				{
					template<typename Iterator>
					static bool no_break(Iterator in)
						{ return s_policy::template bwd_arit_unroll_0<N, M, L>::zero::fast::no_break(true, in); }
				};
			};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_break(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=true;
					s_policy::template bwd_arit_unroll_0<N, M, L>::equal::no_break(carry, in1, in2);
				}

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(Iterator1 in1, Iterator2 in2)
						{ return s_policy::template bwd_arit_unroll_0<N, M, L>::equal::fast::no_break(true, in1, in2); }
				};
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_break(Iterator1 in1, Iterator2 in2, bool & carry)
				{
					carry=false;
					s_policy::template bwd_arit_unroll_0<N, M, L>::not_equal::no_break(carry, in1, in2);
				}

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(Iterator1 in1, Iterator2 in2)
					{
						return s_policy::template bwd_arit_unroll_0<N, M, L>::
							not_equal::fast::no_break(false, in1, in2);
					}
				};
			};

			struct left_shift
			{
/*
	For the "natural" left_shift,
	N is interpreted here as (array length - # of array positional shifts).
	define in2 = --RIterator(in1),
	as well as n = c_policy::unit::length-m.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1<<m); }.
	Do not add (*in2>>n) as in this specialization, in2 may be past the boundary.
*/
				template<typename ValueType, typename WIterator, typename RIterator>
				static void no_return(WIterator out, RIterator in, size_type n)
				{
					s_policy::template bwd_comp_unroll<M-1>::left_shift::template no_return
						<WIterator&, RIterator&>(out, in, --RIterator(in), n, c_policy::unit::length-n);
					*out=(*in<<n);

					s_policy::template bwd_comp_unroll<N-M>::repeat::no_return(--out, (ValueType) 0);
				}

				template<typename ValueType, typename WIterator, typename RIterator>
				static WIterator with_return(WIterator out, RIterator in, size_type n)
				{
					s_policy::template bwd_comp_unroll<M-1>::left_shift::template no_return
						<WIterator&, RIterator&>(out, in, --RIterator(in), n, c_policy::unit::length-n);
					*out=(*in<<n);

					return s_policy::template bwd_comp_unroll<N-M>::repeat::with_return(--out, (ValueType) 0);
				}
			};

			struct assign
			{
				struct left_shift
				{
/*
	For the "natural" left_shift,
	define in = --out,
	as well as n = c_policy::unit::length-m,
	finally, *out<<=m needs appending.

	Within the safe version, unroll <N-1> instead of <N>, and append { *out=(*in1<<m); }.
	Do not add (*in2>>n) as in this specialization, in2 may be past the boundary.
*/
					template<typename ValueType, typename WIterator>
					static void no_return(WIterator out, size_type n)
					{
						s_policy::template bwd_comp_unroll<M-1>::assign::left_shift::template no_return
							<WIterator&>(out, --WIterator(out), n, c_policy::unit::length-n);
						*out<<=n;

						s_policy::template bwd_comp_unroll<N-M>::repeat::no_return(--out, (ValueType) 0);
					}

					template<typename ValueType, typename WIterator>
					static WIterator with_return(WIterator out, size_type n)
					{
						s_policy::template bwd_comp_unroll<M-1>::assign::left_shift::template no_return
							<WIterator&>(out, --WIterator(out), n, c_policy::unit::length-n);
						*out<<=n;

						return s_policy::template bwd_comp_unroll<N-M>::repeat::with_return(--out, (ValueType) 0);
					}
				};
			};
		};
	};
    }

    namespace bidirectional
    {
	template<typename SizeType>
	struct arithmetic_0
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::policy<size_type> s_policy;

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_0
		{
		};
	};
    }

    namespace random_access
    {
	template<typename SizeType>
	struct arithmetic_0
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::policy<size_type> s_policy;

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_0
		{
		};
	};
    }
   }
  }
 }
}

#endif
