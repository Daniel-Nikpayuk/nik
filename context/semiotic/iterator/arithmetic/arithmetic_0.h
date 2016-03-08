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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_0_H
#define CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_0_H

#include<stddef.h>

// overhead dependencies:

#include"../../../context/policy/policy.h"

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
  namespace semiotic
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

		struct zero
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename RIterator, typename EIterator>
			static void no_break(bool & carry, RIterator in, EIterator end)
			{
				while (in != end)
				{
					carry=carry && !*in;
					++in;
				}
			}
/*
	If return == end, then the iterated container property is true.
*/
			template<typename RIterator, typename EIterator>
			static RIterator with_break(RIterator in, EIterator end)
			{
				while (in != end)
				{
					if (*in) return in;
					++in;
				}

				return in;
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator, typename EIterator>
				static bool no_break(bool carry, RIterator in, EIterator end)
				{
					while (in != end)
					{
						carry=carry && !*in;
						++in;
					}

					return carry;
				}
/*
	If return == end, then the iterated container property is true.
*/
				template<typename RIterator, typename EIterator>
				static bool with_break(RIterator in, EIterator end)
				{
					while (in != end)
					{
						if (*in) return false;
						++in;
					}

					return true;
				}
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
			static void no_break(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry && (*in1 == *in2);
					++in1; ++in2;
				}
			}
/*
	If return == end, then the iterated container property is true.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator2 with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return in2;
					++in1; ++in2;
				}

				return in2;
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool no_break(bool carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						carry=carry && (*in1 == *in2);
						++in1; ++in2;
					}

					return carry;
				}
/*
	If return == end, then the iterated container property is true.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						if (*in1 != *in2) return false;
						++in1; ++in2;
					}

					return true;
				}
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
			static void no_break(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry || (*in1 != *in2);
					++in1; ++in2;
				}
			}
/*
	If return == end, then the iterated container property is false.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator2 with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return in2;
					++in1; ++in2;
				}

				return in2;
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool no_break(bool carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						carry=carry || (*in1 != *in2);
						++in1; ++in2;
					}

					return carry;
				}
/*
	If return == end, then the iterated container property is false.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						if (*in1 != *in2) return true;
						++in1; ++in2;
					}

					return false;
				}
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
			static void no_return(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					++in1; ++in2;
				}
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator1 with_return(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					++in1; ++in2;
				}

				return in1;
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(bool carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					++in1; ++in2;
				}

				return carry;
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(bool carry, RIterator1 in1,
				RIterator2 in2, EIterator2 end2, size_type order1, size_type order2)
					{ return (order1 < order2 || (order1 == order2 && fast_return(carry, in1, in2, end2))); }
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
			static void no_return(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					++in1; ++in2;
				}
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator1 with_return(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					++in1; ++in2;
				}

				return in1;
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(bool carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					++in1; ++in2;
				}

				return carry;
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(bool carry, RIterator1 in1,
				RIterator2 in2, EIterator2 end2, size_type order1, size_type order2)
					{ return (order1 < order2 || (order1 == order2 && fast_return(carry, in1, in2, end2))); }
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
			static void no_return(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					++in1; ++in2;
				}
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator1 with_return(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					++in1; ++in2;
				}

				return in1;
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(bool carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					++in1; ++in2;
				}

				return carry;
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(bool carry, RIterator1 in1,
				RIterator2 in2, EIterator2 end2, size_type order1, size_type order2)
					{ return (order1 > order2 || (order1 == order2 && fast_return(carry, in1, in2, end2))); }
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
			static void no_return(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					++in1; ++in2;
				}
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator1 with_return(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					++in1; ++in2;
				}

				return in1;
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(bool carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					++in1; ++in2;
				}

				return carry;
			}

			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_return(bool carry, RIterator1 in1,
				RIterator2 in2, EIterator2 end2, size_type order1, size_type order2)
					{ return (order1 > order2 || (order1 == order2 && fast_return(carry, in1, in2, end2))); }
		};
/*
	carry needs to be set to 0 for the "normal" interpretation.

	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 < *in1, *in2.
	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 + 1 will not cause a second such overflow.
*/
		struct plus
		{
			template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
			static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
			{
				while (in2 != end2)
				{
					carry+=*in1;
					*out=carry + *in2;
					carry=(carry < *in1 || *out < *in2);
					++out; ++in1; ++in2;
				}
			}

			template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
			static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
			{
				while (in2 != end2)
				{
					carry+=*in1;
					*out=carry + *in2;
					carry=(carry < *in1 || *out < *in2);
					++out; ++in1; ++in2;
				}

				return out;
			}
/*
	If an arithmetic overflow occurs beyond the half, it will only effect the first digit above.
*/
			struct half
			{
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
				static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
				{
					while (in2 != end2)
					{
						carry+=*in1 + *in2;
						*out=c_policy::unit::filter::low_pass & carry;
						carry=bool(c_policy::unit::half::size & carry);
						++out; ++in1; ++in2;
					}
				}

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
				static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
				{
					while (in2 != end2)
					{
						carry+=*in1 + *in2;
						*out=c_policy::unit::filter::low_pass & carry;
						carry=bool(c_policy::unit::half::size & carry);
						++out; ++in1; ++in2;
					}

					return out;
				}
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
			template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
			static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
			{
				while (in2 != end2)
				{
					carry+=*in2;
					*out=*in1 - carry;
					carry=(carry < *in2 || *in1 < *out);
					++out; ++in1; ++in2;
				}
			}

			template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
			static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
			{
				while (in2 != end2)
				{
					carry+=*in2;
					*out=*in1 - carry;
					carry=(carry < *in2 || *in1 < *out);
					++out; ++in1; ++in2;
				}

				return out;
			}

			struct half
			{
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
				static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
				{
					while (in2 != end2)
					{
						*out=carry + *in2;
						carry=(*in1 < *out);
						*out=(carry * c_policy::unit::half::size) + *in1 - *out;
						++out; ++in1; ++in2;
					}
				}

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2, typename ERIterator2>
				static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2, ERIterator2 end2)
				{
					while (in2 != end2)
					{
						*out=carry + *in2;
						carry=(*in1 < *out);
						*out=(carry * c_policy::unit::half::size) + *in1 - *out;
						++out; ++in1; ++in2;
					}

					return out;
				}
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
				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static void no_return(ValueType carry, WIterator out, RIterator in, ERIterator end, ValueType value)
				{
					while (in != end)
					{
						carry+=(*in) * value;
						*out=c_policy::unit::filter::low_pass & carry;
						carry>>=c_policy::unit::half::length;
						++out; ++in;
					}
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static WIterator with_return(ValueType carry, WIterator out, RIterator in, ERIterator end, ValueType value)
				{
					while (in != end)
					{
						carry+=(*in) * value;
						*out=c_policy::unit::filter::low_pass & carry;
						carry>>=c_policy::unit::half::length;
						++out; ++in;
					}

					return out;
				}
			};
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
				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static void no_return(ValueType carry, WIterator out, RIterator in, ERIterator end)
				{
					while (in != end)
					{
						carry+=*in;
						*out+=carry;
						carry=(carry < *in || *out < carry);
						++out; ++in;
					}
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static WIterator with_return(ValueType carry, WIterator out, RIterator in, ERIterator end)
				{
					while (in != end)
					{
						carry+=*in;
						*out+=carry;
						carry=(carry < *in || *out < carry);
						++out; ++in;
					}

					return out;
				}
/*
	If an arithmetic overflow occurs beyond the half, it will only effect the first digit above.
*/
				struct half
				{
					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static void no_return(ValueType carry, WIterator out, RIterator in, ERIterator end)
					{
						while (in != end)
						{
							carry+=*out + *in;
							*out=c_policy::unit::filter::low_pass & carry;
							carry=bool(c_policy::unit::half::size & carry);
							++out; ++in;
						}
					}

					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static WIterator with_return(ValueType carry, WIterator out, RIterator in, ERIterator end)
					{
						while (in != end)
						{
							carry+=*out + *in;
							*out=c_policy::unit::filter::low_pass & carry;
							carry=bool(c_policy::unit::half::size & carry);
							++out; ++in;
						}

						return out;
					}
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
				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static void no_return(ValueType carry, WIterator out, RIterator in, ERIterator end)
				{
					ValueType before;
					while (in != end)
					{
						before=*out;
						carry+=*in;
						*out-=carry;
						carry=(carry < *in || before < *out);
						++out; ++in;
					}
				}

				template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
				static WIterator with_return(ValueType carry, WIterator out, RIterator in, ERIterator end)
				{
					ValueType before;
					while (in != end)
					{
						before=*out;
						carry+=*in;
						*out-=carry;
						carry=(carry < *in || before < *out);
						++out; ++in;
					}

					return out;
				}

				struct half
				{
					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static void no_return(ValueType carry, WIterator out, RIterator in, ERIterator end)
					{
						ValueType before;
						while (in != end)
						{
							before=*out;
							*out=carry + *in;
							carry=(before < *out);
							*out=(carry * c_policy::unit::half::size) + before - *out;
							++out; ++in;
						}
					}

					template<typename ValueType, typename WIterator, typename RIterator, typename ERIterator>
					static WIterator with_return(ValueType carry, WIterator out, RIterator in, ERIterator end)
					{
						ValueType before;
						while (in != end)
						{
							before=*out;
							*out=carry + *in;
							carry=(before < *out);
							*out=(carry * c_policy::unit::half::size) + before - *out;
							++out; ++in;
						}

						return out;
					}
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
					template<typename ValueType, typename WIterator, typename EIterator>
					static void no_return(ValueType carry, WIterator out, EIterator end, ValueType value)
					{
						while (out != end)
						{
							carry+=(*out) * value;
							*out=c_policy::unit::filter::low_pass & carry;
							carry>>=c_policy::unit::half::length;
							++out;
						}
					}

					template<typename ValueType, typename WIterator, typename EIterator>
					static WIterator with_return(ValueType carry, WIterator out, EIterator end, ValueType value)
					{
						while (out != end)
						{
							carry+=(*out) * value;
							*out=c_policy::unit::filter::low_pass & carry;
							carry>>=c_policy::unit::half::length;
							++out;
						}

						return out;
					}
				};
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
				static void no_break(bool & carry, Iterator in)
				{
					carry=carry && !*in;
					unroll_0<N-1>::zero::no_break(carry, ++in);
				}
/*
	If return == end, then the iterated container property is true.
*/
				template<typename Iterator>
				static Iterator with_break(Iterator in)
				{
					if (*in) return in;
					else return unroll_0<N-1>::zero::with_break(++in);
				}

				struct fast
				{
					template<typename Iterator>
					static bool no_break(bool carry, Iterator in)
					{
						carry=carry && !*in;
						return unroll_0<N-1>::zero::fast::no_break(carry, ++in);
					}
/*
	If return == end, then the iterated container property is true.
*/
					template<typename Iterator>
					static bool with_break(Iterator in)
					{
						if (*in) return false;
						else return unroll_0<N-1>::zero::fast::with_break(++in);
					}
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
				static void no_break(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					carry=carry && (*in1 == *in2);
					unroll_0<N-1>::equal::no_break(carry, ++in1, ++in2);
				}
/*
	If return == end, then the iterated container property is true.
*/
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return in2;
					else return unroll_0<N-1>::equal::with_break(++in1, ++in2);
				}

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{
						carry=carry && (*in1 == *in2);
						return unroll_0<N-1>::equal::fast::no_break(carry, ++in1, ++in2);
					}
/*
	If return == end, then the iterated container property is true.
*/
					template<typename Iterator1, typename Iterator2>
					static bool with_break(Iterator1 in1, Iterator2 in2)
					{
						if (*in1 != *in2) return false;
						else return unroll_0<N-1>::equal::fast::with_break(++in1, ++in2);
					}
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
				static void no_break(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					carry=carry || (*in1 != *in2);
					unroll_0<N-1>::not_equal::no_break(carry, ++in1, ++in2);
				}
/*
	If return == end, then the iterated container property is false.
*/
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return in2;
					else return unroll_0<N-1>::not_equal::with_break(++in1, ++in2);
				}

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{
						carry=carry || (*in1 != *in2);
						return unroll_0<N-1>::not_equal::fast::no_break(carry, ++in1, ++in2);
					}
/*
	If return == end, then the iterated container property is false.
*/
					template<typename Iterator1, typename Iterator2>
					static bool with_break(Iterator1 in1, Iterator2 in2)
					{
						if (*in1 != *in2) return true;
						else return unroll_0<N-1>::not_equal::fast::with_break(++in1, ++in2);
					}
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
				static void no_return(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					unroll_0<N-1>::less_than::no_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					return unroll_0<N-1>::less_than::with_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					return unroll_0<N-1>::less_than::fast_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
				{
					return (order1 < order2 || (order1 == order2 &&
						unroll_0<N>::less_than::fast_return(carry, in1, in2)));
				}
			};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct less_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					unroll_0<N-1>::less_than_or_equal::no_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					return unroll_0<N-1>::less_than_or_equal::with_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 < *in2) carry=true;
					else if (*in1 > *in2) carry=false;

					return unroll_0<N-1>::less_than_or_equal::fast_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
				{
					return (order1 < order2 || (order1 == order2 &&
						unroll_0<N>::less_than_or_equal::fast_return(carry, in1, in2)));
				}
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct greater_than
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					unroll_0<N-1>::greater_than::no_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					return unroll_0<N-1>::greater_than::with_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					return unroll_0<N-1>::greater_than::fast_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
				{
					return (order1 > order2 || (order1 == order2 &&
						unroll_0<N>::greater_than::fast_return(carry, in1, in2)));
				}
			};
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct greater_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					unroll_0<N-1>::greater_than_or_equal::no_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					return unroll_0<N-1>::greater_than_or_equal::with_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2)
				{
					if (*in1 > *in2) carry=true;
					else if (*in1 < *in2) carry=false;

					return unroll_0<N-1>::greater_than_or_equal::fast_return(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
				{
					return (order1 > order2 || (order1 == order2 &&
						unroll_0<N>::greater_than_or_equal::fast_return(carry, in1, in2)));
				}
			};
/*
			Intuitively, "right_shift" would be defined here,
			but given its implementation it is actually part of componentwise.h
*/
/*
	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 < *in1, *in2.
	If *in1 + *in2 causes an arithmetic overflow, then *in1 + *in2 + 1 will not cause a second such overflow.
*/
			struct plus
			{
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
				{
					carry+=*in1;
					*out=carry + *in2;
					carry=(carry < *in1 || *out < *in2);
					unroll_0<N-1>::plus::no_return(carry, ++out, ++in1, ++in2);
				}

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
				{
					carry+=*in1;
					*out=carry + *in2;
					carry=(carry < *in1 || *out < *in2);
					return unroll_0<N-1>::plus::with_return(carry, ++out, ++in1, ++in2);
				}
/*
	If an arithmetic overflow occurs beyond the half, it will only effect the first digit above.
*/
				struct half
				{
					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
					{
						carry+=*in1 + *in2;
						*out=c_policy::unit::filter::low_pass & carry;
						carry=bool(c_policy::unit::half::size & carry);
						unroll_0<N-1>::plus::half::no_return(carry, ++out, ++in1, ++in2);
					}

					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
					{
						carry+=*in1 + *in2;
						*out=c_policy::unit::filter::low_pass & carry;
						carry=bool(c_policy::unit::half::size & carry);
						return unroll_0<N-1>::plus::half::with_return(carry, ++out, ++in1, ++in2);
					}
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
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
				{
					carry+=*in2;
					*out=*in1 - carry;
					carry=(carry < *in2 || *in1 < *out);
					unroll_0<N-1>::minus::no_return(carry, ++out, ++in1, ++in2);
				}

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
				{
					carry+=*in2;
					*out=*in1 - carry;
					carry=(carry < *in2 || *in1 < *out);
					return unroll_0<N-1>::minus::with_return(carry, ++out, ++in1, ++in2);
				}

				struct half
				{
					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
					{
						*out=carry + *in2;
						carry=(*in1 < *out);
						*out=(carry * c_policy::unit::half::size) + *in1 - *out;
						unroll_0<N-1>::minus::half::no_return(carry, ++out, ++in1, ++in2);
					}

					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
					{
						*out=carry + *in2;
						carry=(*in1 < *out);
						*out=(carry * c_policy::unit::half::size) + *in1 - *out;
						return unroll_0<N-1>::minus::half::with_return(carry, ++out, ++in1, ++in2);
					}
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
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType carry, WIterator out, RIterator in1, ValueType in2)
					{
						carry+=(*in1) * in2;
						*out=c_policy::unit::filter::low_pass & carry;
						carry>>=c_policy::unit::half::length;
						unroll_0<N-1>::scale::half::no_return(carry, ++out, ++in1, in2);
					}
/*
	carry is the overhead value. Set this to zero for the "normal" interpretation.
	out is the resultant containing structure.
	in1 is the initial containing structure.
	in2 is the c_policy::unit scalar value.

	All ValueTypes are under the constraint of being less than the half register size.
*/
					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType carry, WIterator out, RIterator in1, ValueType in2)
					{
						carry+=(*in1) * in2;
						*out=c_policy::unit::filter::low_pass & carry;
						carry>>=c_policy::unit::half::length;
						return unroll_0<N-1>::scale::half::with_return(carry, ++out, ++in1, in2);
					}
				};
			};

			struct assign
			{
				struct plus
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType carry, WIterator out, RIterator in)
					{
						carry+=*in;
						*out+=carry;
						carry=(carry < *in || *out < carry);
						unroll_0<N-1>::assign::plus::no_return(carry, ++out, ++in);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType carry, WIterator out, RIterator in)
					{
						carry+=*in;
						*out+=carry;
						carry=(carry < *in || *out < carry);
						return unroll_0<N-1>::assign::plus::with_return(carry, ++out, ++in);
					}
/*
	If an arithmetic overflow occurs beyond the half, it will only effect the first digit above.
*/
					struct half
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(ValueType carry, WIterator out, RIterator in)
						{
							carry+=*out + *in;
							*out=c_policy::unit::filter::low_pass & carry;
							carry=bool(c_policy::unit::half::size & carry);
							unroll_0<N-1>::assign::plus::half::no_return(carry, ++out, ++in);
						}

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(ValueType carry, WIterator out, RIterator in)
						{
							carry+=*out + *in;
							*out=c_policy::unit::filter::low_pass & carry;
							carry=bool(c_policy::unit::half::size & carry);
							return unroll_0<N-1>::assign::plus::half::with_return(carry, ++out, ++in);
						}
					};
				};
/*
	Two ValueTypes are relevant as one might be a reference while the other is not.

	carry needs to be set to 0 for the "normal" interpretation.
*/
				struct minus
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType carry, WIterator out, RIterator in)
					{
						ValueType before(*out);
						carry+=*in;
						*out-=carry;
						carry=(carry < *in || before < *out);
						unroll_0<N-1>::assign::minus::no_return(carry, ++out, ++in);
					}

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType carry, WIterator out, RIterator in)
					{
						ValueType before(*out);
						carry+=*in;
						*out-=carry;
						carry=(carry < *in || before < *out);
						return unroll_0<N-1>::assign::minus::with_return(carry, ++out, ++in);
					}

					struct half
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(ValueType carry, WIterator out, RIterator in)
						{
							ValueType before(*out);
							*out=carry + *in;
							carry=(before < *out);
							*out=(carry * c_policy::unit::half::size) + before - *out;
							unroll_0<N-1>::assign::minus::half::no_return(carry, ++out, ++in);
						}

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(ValueType carry, WIterator out, RIterator in)
						{
							ValueType before(*out);
							*out=carry + *in;
							carry=(before < *out);
							*out=(carry * c_policy::unit::half::size) + before - *out;
							return unroll_0<N-1>::assign::minus::half::with_return(carry, ++out, ++in);
						}
					};
				};

				struct scale
				{
					struct half
					{
						template<typename ValueType, typename WIterator>
						static void no_return(ValueType carry, WIterator out, ValueType value)
						{
							carry+=(*out) * value;
							*out=c_policy::unit::filter::low_pass & carry;
							carry>>=c_policy::unit::half::length;
							unroll_0<N-1>::assign::scale::half::no_return(carry, ++out, value);
						}

						template<typename ValueType, typename WIterator>
						static WIterator with_return(ValueType carry, WIterator out, ValueType value)
						{
							carry+=(*out) * value;
							*out=c_policy::unit::filter::low_pass & carry;
							carry>>=c_policy::unit::half::length;
							return unroll_0<N-1>::assign::scale::half::with_return(carry, ++out, value);
						}
					};
				};
			};
		};

		template<size_type M, size_type L>
		struct unroll_0<0, M, L>
		{
			struct zero
			{
				template<typename Iterator>
				static void no_break(bool & carry, Iterator in)
					{ }

				template<typename Iterator>
				static Iterator with_break(Iterator in)
					{ return in; }

				struct fast
				{
					template<typename Iterator>
					static bool no_break(bool carry, Iterator in)
						{ return carry; }

					template<typename Iterator>
					static bool with_break(Iterator in)
						{ return true; }
				};
			};

			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_break(bool & carry, Iterator1 in1, Iterator2 in2)
					{ }

				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
					{ return in2; }

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
						{ return carry; }

					template<typename Iterator1, typename Iterator2>
					static bool with_break(Iterator1 in1, Iterator2 in2)
						{ return true; }
				};
			};

			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_break(bool & carry, Iterator1 in1, Iterator2 in2)
					{ }

				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
					{ return in2; }

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
						{ return carry; }

					template<typename Iterator1, typename Iterator2>
					static bool with_break(Iterator1 in1, Iterator2 in2)
						{ return false; }
				};
			};

			struct less_than
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(bool & carry, Iterator1 in1, Iterator2 in2)
					{ }

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(bool & carry, Iterator1 in1, Iterator2 in2)
					{ return in1; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
					{ return carry; }
			};

			struct less_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(bool & carry, Iterator1 in1, Iterator2 in2)
					{ }

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(bool & carry, Iterator1 in1, Iterator2 in2)
					{ return in1; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
					{ return carry; }
			};

			struct greater_than
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(bool & carry, Iterator1 in1, Iterator2 in2)
					{ }

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(bool & carry, Iterator1 in1, Iterator2 in2)
					{ return in1; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
					{ return carry; }
			};

			struct greater_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_return(bool & carry, Iterator1 in1, Iterator2 in2)
					{ }

				template<typename Iterator1, typename Iterator2>
				static Iterator1 with_return(bool & carry, Iterator1 in1, Iterator2 in2)
					{ return in1; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_return(bool carry, Iterator1 in1, Iterator2 in2, size_type order1, size_type order2)
					{ return carry; }
			};

			struct plus
			{
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
					{ }

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
					{ return out; }

				struct half
				{
					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
						{ }

					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
						{ return out; }
				};
			};

			struct minus
			{
				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
					{ }

				template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
				static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
					{ return out; }

				struct half
				{
					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static void no_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
						{ }

					template<typename ValueType, typename WIterator, typename RIterator1, typename RIterator2>
					static WIterator with_return(ValueType carry, WIterator out, RIterator1 in1, RIterator2 in2)
						{ return out; }
				};
			};

			struct scale
			{
				struct half
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType carry, WIterator out, RIterator in1, ValueType in2)
						{ }

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType carry, WIterator out, RIterator in1, ValueType in2)
						{ return out; }
				};
			};

			struct assign
			{
				struct plus
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType carry, WIterator out, RIterator in)
						{ }

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType carry, WIterator out, RIterator in)
						{ return out; }

					struct half
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(ValueType carry, WIterator out, RIterator in)
							{ }

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(ValueType carry, WIterator out, RIterator in)
							{ return out; }
					};
				};

				struct minus
				{
					template<typename ValueType, typename WIterator, typename RIterator>
					static void no_return(ValueType carry, WIterator out, RIterator in)
						{ }

					template<typename ValueType, typename WIterator, typename RIterator>
					static WIterator with_return(ValueType carry, WIterator out, RIterator in)
						{ return out; }

					struct half
					{
						template<typename ValueType, typename WIterator, typename RIterator>
						static void no_return(ValueType carry, WIterator out, RIterator in)
							{ }

						template<typename ValueType, typename WIterator, typename RIterator>
						static WIterator with_return(ValueType carry, WIterator out, RIterator in)
							{ return out; }
					};
				};

				struct scale
				{
					struct half
					{
						template<typename ValueType, typename WIterator>
						static void no_return(ValueType carry, WIterator out, ValueType value)
							{ }

						template<typename ValueType, typename WIterator>
						static WIterator with_return(ValueType carry, WIterator out, ValueType value)
							{ return out; }
					};
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

		struct zero
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			template<typename RIterator, typename EIterator>
			static void no_break(bool & carry, RIterator in, EIterator end)
			{
				while (in != end)
				{
					carry=carry && !*in;
					--in;
				}
			}
/*
	If return == end, then the iterated container property is true.
*/
			template<typename RIterator, typename EIterator>
			static RIterator with_break(RIterator in, EIterator end)
			{
				while (in != end)
				{
					if (*in) return in;
					--in;
				}

				return in;
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator, typename EIterator>
				static bool no_break(bool carry, RIterator in, EIterator end)
				{
					while (in != end)
					{
						carry=carry && !*in;
						--in;
					}

					return carry;
				}
/*
	If return == end, then the iterated container property is true.
*/
				template<typename RIterator, typename EIterator>
				static bool with_break(RIterator in, EIterator end)
				{
					while (in != end)
					{
						if (*in) return false;
						--in;
					}

					return true;
				}
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
			static void no_break(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry && (*in1 == *in2);
					--in1; --in2;
				}
			}
/*
	If return == end, then the iterated container property is true.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator2 with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return in2;
					--in1; --in2;
				}

				return in2;
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool no_break(bool carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						carry=carry && (*in1 == *in2);
						--in1; --in2;
					}

					return carry;
				}
/*
	If return == end, then the iterated container property is true.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						if (*in1 != *in2) return false;
						--in1; --in2;
					}

					return true;
				}
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
			static void no_break(bool & carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					carry=carry || (*in1 != *in2);
					--in1; --in2;
				}
			}
/*
	If return == end, then the iterated container property is false.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator2 with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return in2;
					--in1; --in2;
				}

				return in2;
			}

			struct fast
			{
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool no_break(bool carry, RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						carry=carry || (*in1 != *in2);
						--in1; --in2;
					}

					return carry;
				}
/*
	If return == end, then the iterated container property is false.
*/
				template<typename RIterator1, typename RIterator2, typename EIterator2>
				static bool with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
				{
					while (in2 != end2)
					{
						if (*in1 != *in2) return true;
						--in1; --in2;
					}

					return false;
				}
			};
		};

		struct less_than
		{
/*
	If return == end, then the iterated container property is false.
	If return != end, then the iterated container property is (*in1 < *in2).

	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator2 with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return in2;
					--in1; --in2;
				}

				return in2;
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					--in1; --in2;
				}

				return false;
			}
		};

		struct less_than_or_equal
		{
/*
	If return == end, then the iterated container property is true.
	If return != end, then the iterated container property is (*in1 < *in2).

	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator2 with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return in2;
					--in1; --in2;
				}

				return in2;
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					--in1; --in2;
				}

				return true;
			}
		};

		struct greater_than
		{
/*
	If return == end, then the iterated container property is false.
	If return != end, then the iterated container property is (*in1 > *in2).

	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator2 with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return in2;
					--in1; --in2;
				}

				return in2;
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					--in1; --in2;
				}

				return false;
			}
		};

		struct greater_than_or_equal
		{
/*
	If return == end, then the iterated container property is true.
	If return != end, then the iterated container property is (*in1 > *in2).

	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static RIterator2 with_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return in2;
					--in1; --in2;
				}

				return in2;
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename RIterator1, typename RIterator2, typename EIterator2>
			static bool fast_break(RIterator1 in1, RIterator2 in2, EIterator2 end2)
			{
				while (in2 != end2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					--in1; --in2;
				}

				return true;
			}
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
				static void no_break(bool & carry, Iterator in)
				{
					carry=carry && !*in;
					unroll_0<N-1>::zero::no_break(carry, --in);
				}

				template<typename Iterator>
				static Iterator with_break(Iterator in)
				{
					if (*in) return in;
					else return unroll_0<N-1>::zero::with_break(--in);
				}

				struct fast
				{
					template<typename Iterator>
					static bool no_break(bool carry, Iterator in)
					{
						carry=carry && !*in;
						return unroll_0<N-1>::zero::fast::no_break(carry, --in);
					}

					template<typename Iterator>
					static bool with_break(Iterator in)
					{
						if (*in) return false;
						else return unroll_0<N-1>::zero::fast::with_break(--in);
					}
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
				static void no_break(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					carry=carry && (*in1 == *in2);
					unroll_0<N-1>::equal::no_break(carry, --in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return in2;
					else return unroll_0<N-1>::equal::with_break(--in1, --in2);
				}

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{
						carry=carry && (*in1 == *in2);
						return unroll_0<N-1>::equal::fast::no_break(carry, --in1, --in2);
					}

					template<typename Iterator1, typename Iterator2>
					static bool with_break(Iterator1 in1, Iterator2 in2)
					{
						if (*in1 != *in2) return false;
						else return unroll_0<N-1>::equal::fast::with_break(--in1, --in2);
					}
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
				static void no_break(bool & carry, Iterator1 in1, Iterator2 in2)
				{
					carry=carry || (*in1 != *in2);
					unroll_0<N-1>::not_equal::no_break(carry, --in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return in2;
					else return unroll_0<N-1>::not_equal::with_break(--in1, --in2);
				}

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{
						carry=carry || (*in1 != *in2);
						return unroll_0<N-1>::not_equal::fast::no_break(carry, --in1, --in2);
					}

					template<typename Iterator1, typename Iterator2>
					static bool with_break(Iterator1 in1, Iterator2 in2)
					{
						if (*in1 != *in2) return true;
						else return unroll_0<N-1>::not_equal::fast::with_break(--in1, --in2);
					}
				};
			};
/*
	If return == end, then the iterated container property is true.
	If return != end, then the iterated container property is (*in1 < *in2).

	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct less_than
			{
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return in2;
					else return unroll_0<N-1>::less_than::with_break(--in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					else return unroll_0<N-1>::less_than::fast_break(--in1, --in2);
				}
			};
/*
	If return == end, then the iterated container property is true.
	If return != end, then the iterated container property is (*in1 < *in2).

	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct less_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return in2;
					else return unroll_0<N-1>::less_than_or_equal::with_break(--in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					else return unroll_0<N-1>::less_than_or_equal::fast_break(--in1, --in2);
				}
			};
/*
	If return == end, then the iterated container property is true.
	If return != end, then the iterated container property is (*in1 > *in2).

	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct greater_than
			{
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return in2;
					else return unroll_0<N-1>::greater_than::with_break(--in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					else return unroll_0<N-1>::greater_than::fast_break(--in1, --in2);
				}
			};
/*
	If return == end, then the iterated container property is true.
	If return != end, then the iterated container property is (*in1 > *in2).

	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			struct greater_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return in2;
					else return unroll_0<N-1>::greater_than_or_equal::with_break(--in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool fast_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					else return unroll_0<N-1>::greater_than_or_equal::fast_break(--in1, --in2);
				}
			};
/*
			Intuitively, "right_shift" would be defined here,
			but given its implementation it is actually part of componentwise.h
*/
			struct assign
			{
			};
		};

		template<size_type M, size_type L>
		struct unroll_0<0, M, L>
		{
			struct zero
			{
				template<typename Iterator>
				static void no_break(bool & carry, Iterator in)
					{ }

				template<typename Iterator>
				static Iterator with_break(Iterator in)
					{ return in; }

				struct fast
				{
					template<typename Iterator>
					static bool no_break(bool carry, Iterator in)
						{ return carry; }

					template<typename Iterator>
					static bool with_break(Iterator in)
						{ return true; }
				};
			};

			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_break(bool & carry, Iterator1 in1, Iterator2 in2)
					{ }

				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
					{ return in2; }

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
						{ return carry; }

					template<typename Iterator1, typename Iterator2>
					static bool with_break(Iterator1 in1, Iterator2 in2)
						{ return true; }
				};
			};

			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static void no_break(bool & carry, Iterator1 in1, Iterator2 in2)
					{ }

				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
					{ return in2; }

				struct fast
				{
					template<typename Iterator1, typename Iterator2>
					static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
						{ return carry; }

					template<typename Iterator1, typename Iterator2>
					static bool with_break(Iterator1 in1, Iterator2 in2)
						{ return false; }
				};
			};

			struct less_than
			{
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
					{ return in2; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_break(Iterator1 in1, Iterator2 in2)
					{ return false; }
			};

			struct less_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
					{ return in2; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_break(Iterator1 in1, Iterator2 in2)
					{ return true; }
			};

			struct greater_than
			{
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
					{ return in2; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_break(Iterator1 in1, Iterator2 in2)
					{ return false; }
			};

			struct greater_than_or_equal
			{
				template<typename Iterator1, typename Iterator2>
				static Iterator2 with_break(Iterator1 in1, Iterator2 in2)
					{ return in2; }

				template<typename Iterator1, typename Iterator2>
				static bool fast_break(Iterator1 in1, Iterator2 in2)
					{ return true; }
			};

			struct assign
			{
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

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_0
		{
		};

		template<size_type M, size_type L>
		struct unroll_0<0, M, L>
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

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll_0
		{
		};

		template<size_type M, size_type L>
		struct unroll_0<0, M, L>
		{
		};
	};
    }
   }
  }
 }
}

#endif
