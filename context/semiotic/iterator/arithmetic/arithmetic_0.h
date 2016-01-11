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

// Clean up the typedefs/usings namespace stuff.

// overhead dependencies:
#include"../../../context/constant.h"

/*
	The main difference between "componentwise" and "arithmetic" from an algorithmic lens is that with componentwise is
	each location is conditionally independent, whereas arithmetic is similar but also dependent on the previous value
	(recursive; maybe the simplest variety of recursive?).

	Incrementing and decrementing pointers which should otherwise maintain a constant location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using these such unrolling in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.
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
	template<typename size_type>
	struct arithmetic_0
	{
		typedef meta::constant<size_type> constant;
/*
			template<typename Topos>
			static bool equal(const Topos *in1, const Topos *in2, const Topos *end2)
			{
				while (in2 != end2)
					if (in1->value != in2->value) return false;
					else { in1=in1->edge0; in2=in2->edge0; }
				return true;
			}
*/
/*
	Tests for inequality over the range in2--end2.
	Assumes <--in1 exists.
*/
/*
			template<typename Topos>
			static bool not_equal(const Topos *in1, const Topos *in2, const Topos *end2)
			{
				while (in2 != end2)
					if (in1->value != in2->value) return true;
					else { in1=in1->edge0; in2=in2->edge0; }
				return false;
			}
*/
/*
	Compares for "less than" over the range in2--end2.  Assumes <--in1 exists.
	Optimized to shortcut on the probability that it's more likely in1->value != in2->value for random assignments.
*/
/*
			template<typename Topos>
			static bool less_than(const Topos *in1, const Topos *in2, const Topos *end2)
			{
				bool rtn=(in1->value < in2->value);
				while ((in2=in2->edge0) != end2)
				{
					in1=in1->edge0;
					if (in1->value < in2->value) rtn=true;
					else if (in1->value > in2->value) rtn=false;
				}
				return rtn;
			}
*/
/*
	Compares for "less than or equal" over the range in2--end2.
	Assumes <--in1 exists.
*/
/*
			template<typename Topos>
			static bool less_than_or_equal(const Topos *in1, const Topos *in2, const Topos *end2)
			{
				bool rtn=(in1->value <= in2->value);
				while ((in2=in2->edge0) != end2)
				{
					in1=in1->edge0;
					if (in1->value < in2->value) rtn=true;
					else if (in1->value > in2->value) rtn=false;
				}
				return rtn;
			}
*/
/*
	Compares for "greater than" over the range in2--end2.
	Assumes <--in1 exists.
*/
/*
			template<typename Topos>
			static bool greater_than(const Topos *in1, const Topos *in2, const Topos *end2)
			{
				bool rtn=(in1->value > in2->value);
				while ((in2=in2->edge0) != end2)
				{
					in1=in1->edge0;
					if (in1->value > in2->value) rtn=true;
					else if (in1->value < in2->value) rtn=false;
				}
				return rtn;
			}
*/
/*
	Compares for "greater than or equal" over the range in2--end2.
	Assumes <--in1 exists.
*/
/*
			template<typename Topos>
			static bool greater_than_or_equal(const Topos *in1, const Topos *in2, const Topos *end2)
			{
				bool rtn=(in1->value >= in2->value);
				while ((in2=in2->edge0) != end2)
				{
					in1=in1->edge0;
					if (in1->value > in2->value) rtn=true;
					else if (in1->value < in2->value) rtn=false;
				}
				return rtn;
			}
*/
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
		template<size_type N, typename Filler=void>
		struct unroll_0
		{

/****************************** Need to reimplement all loop unrolling under the new design constraints!!! ********************/

/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	
	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
				{
					carry&&=(*in1 == *in2);
					return unroll_0<N-1>::equal::no_break(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return false;
					else return unroll_0<N-1>::equal::with_break(++in1, ++in2);
				}
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
				{
					carry||=(*in1 != *in2);
					return unroll_0<N-1>::not_equal::no_break(carry, ++in1, ++in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return true;
					else return unroll_0<N-1>::not_equal::with_break(++in1, ++in2);
				}
			};
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to false for the "normal" interpretation. 
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than(bool carry, Iterator1 in1, Iterator2 in2)
			{
				if (*in1 < *in2) carry=true;
				else if (*in1 > *in2) carry=false;

				return unroll_0<N-1>::less_than::no_break(carry, ++in1, ++in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to true for the "normal" interpretation. 
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(bool carry, Iterator1 in1, Iterator2 in2)
			{
				if (*in1 < *in2) carry=true;
				else if (*in1 > *in2) carry=false;

				return unroll_0<N-1>::less_than::no_break(carry, ++in1, ++in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to false for the "normal" interpretation. 
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than(bool carry, Iterator1 in1, Iterator2 in2)
			{
				if (*in1 > *in2) carry=true;
				else if (*in1 < *in2) carry=false;

				return unroll_0<N-1>::less_than::no_break(carry, ++in1, ++in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
	carry is the overhead value. Set this to true for the "normal" interpretation. 
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(bool carry, Iterator1 in1, Iterator2 in2)
			{
				if (*in1 > *in2) carry=true;
				else if (*in1 < *in2) carry=false;

				return unroll_0<N-1>::less_than::no_break(carry, ++in1, ++in2);
			}
/*
			Intuitively, "right_shift" would be defined here,
			but given its implementation it is actually part of componentwise.h
*/
/*
	Choice of (*out < *in2) is intentional as it provides higher entropy---it allows in1 == out (but in2 != out).
*/
			struct plus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					*out=*in1 + *in2 + carry;
					unroll_0<N-1>::plus::no_return(++out, ++in1, ++in2, (*out < *in2));
				}

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					*out=*in1 + *in2 + carry;
					return unroll_0<N-1>::plus::with_return(++out, ++in1, ++in2, (*out < *in2));
				}
			};
/*
	In this case, *out+(*in2+carry)=*in1 implies a new carry if: *in1 < *out or *in1 < (*in2+carry)
	but there's the special case that (*in2+carry) already wraps around [(*in2+carry) < *in2, carry].
	In which case---given 0 <= carry <= 1---it's automatic that there's a new carry (but no need
	of worry about a "double carry" because (*in2+carry) if wrapped around would equal zero.

	Because use of *in1 can't be avoided in the new carry test, it requires out and in1 cannot be shallow copies.

	The assumption is addition is no less optimal than subtraction as the algorithm
	should require fewer tests, hence: *out=*in1-(*in2+carry) instead of *out=*in1-*in2-carry.
*/
			struct minus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					carry+=*in2;
					*out=*in1 - carry;
					unroll_0<N-1>::minus::no_return(++out, ++in1, ++in2, (carry < *in2 || *in1 < *out));
				}

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					carry+=*in2;
					*out=*in1 - carry;
					return unroll_0<N-1>::minus::with_return(++out, ++in1, ++in2, (carry < *in2 || *in1 < *out));
				}
			};

			struct assign
			{
				struct plus
				{
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void no_return(OutputIterator out, InputIterator in, ValueType carry)
					{
						*out+=*in + carry;
						unroll_0<N-1>::assign::plus::no_return(++out, ++in, (*out < *in));
					}

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static OutputIterator with_return(OutputIterator out, InputIterator in, ValueType carry)
					{
						*out+=*in + carry;
						return unroll_0<N-1>::assign::plus::with_return(++out, ++in, (*out < *in));
					}
				};
			};

			template<size_type M, typename SubFiller=void>
			struct subroll_0
			{
			};

			template<typename SubFiller>
			struct subroll_0<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_0<0, Filler>
		{
			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }
				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
					{ return true; }
			};

			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
					{ return carry; }

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
					{ return false; }
			};

			template<typename Iterator1, typename Iterator2>
			static bool less_than(bool carry, Iterator1 in1, Iterator2 in2)
				{ return carry; }

			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(bool carry, Iterator1 in1, Iterator2 in2)
				{ return carry; }

			template<typename Iterator1, typename Iterator2>
			static bool greater_than(bool carry, Iterator1 in1, Iterator2 in2)
				{ return carry; }

			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(bool carry, Iterator1 in1, Iterator2 in2)
				{ return carry; }

			struct plus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ }

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ return out; }
			};

			struct minus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ }

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ return out; }
			};

			struct assign
			{
				struct plus
				{
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void no_return(OutputIterator out, InputIterator in, ValueType carry)
						{ }

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static OutputIterator with_return(OutputIterator out, InputIterator in, ValueType carry)
						{ return out; }
				};
			};
		};
	};
    }

    namespace backward
    {
	template<typename size_type>
	struct arithmetic_0
	{
		typedef meta::constant<size_type> constant;
/*
	unroll:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
		template<size_type N, typename Filler=void>
		struct unroll_0
		{
/*
	carry is the overhead value. Set this to true for the "normal" interpretation. 
	
	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
				{
					carry&&=(*in1 == *in2);
					return unroll_0<N-1>::equal::no_break(carry, --in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return false;
					else return unroll_0<N-1>::equal::with_break(--in1, --in2);
				}
			};
/*
	carry is the overhead value. Set this to false for the "normal" interpretation. 

	Short-circuiting would seem the more efficient approach, but such conditional jumps are themselves expensive.
	Only when N becomes sufficiently large might it be faster to short-circuit.
*/
			struct not_equal
			{
				template<typename Iterator1, typename Iterator2>
				static bool no_break(bool carry, Iterator1 in1, Iterator2 in2)
				{
					carry||=(*in1 != *in2);
					return unroll_0<N-1>::not_equal::no_break(carry, --in1, --in2);
				}

				template<typename Iterator1, typename Iterator2>
				static bool with_break(Iterator1 in1, Iterator2 in2)
				{
					if (*in1 != *in2) return true;
					else return unroll_0<N-1>::not_equal::with_break(--in1, --in2);
				}
			};
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 < *in2);
				else return unroll_0<N-1>::less_than(--in1, --in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 < *in2);
				else return unroll_0<N-1>::less_than_or_equal(--in1, --in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 > *in2);
				else return unroll_0<N-1>::greater_than(--in1, --in2);
			}
/*
	in1 is the initial location of the left operand.
	in2 is the initial location of the right operand.
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 > *in2);
				else return unroll_0<N-1>::greater_than_or_equal(--in1, --in2);
			}
/*
			Intuitively, "right_shift" would be defined here,
			but given its implementation it is actually part of componentwise.h
*/
/*
	Finds the first occurrence along the iterator path of a non-zero value, returns the iterator position.
*/
			template<typename Iterator>
			static Iterator order(Iterator in)
			{
				if (*in) return in;
				else return unroll_0<N-1>::order(--in);
			}

			struct assign
			{
			};

			template<size_type M, typename SubFiller=void>
			struct subroll_0
			{
			};

			template<typename SubFiller>
			struct subroll_0<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_0<0, Filler>
		{
			template<typename Iterator1, typename Iterator2>
			static bool less_than(Iterator1 in1, Iterator2 in2)
				{ return false; }
			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(Iterator1 in1, Iterator2 in2)
				{ return true; }
			template<typename Iterator1, typename Iterator2>
			static bool greater_than(Iterator1 in1, Iterator2 in2)
				{ return false; }
			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(Iterator1 in1, Iterator2 in2)
				{ return true; }

/*
	Does not perform what is otherwise the standard final decrement.
*/
			template<typename Iterator>
			static Iterator order(Iterator in)
				{ return in; }

			struct assign
			{
			};
		};
	};
    }

    namespace bidirectional
    {
	template<typename size_type>
	struct arithmetic_0
	{
		template<size_type N, typename Filler=void>
		struct unroll_0
		{
			template<size_type M, typename SubFiller=void>
			struct subroll_0
			{
			};

			template<typename SubFiller>
			struct subroll_0<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_0<0, Filler>
		{
		};
	};
    }
    
    namespace random_access
    {
	template<typename size_type>
	struct arithmetic_0
	{
		template<size_type N, typename Filler=void>
		struct unroll_0
		{
			template<size_type M, typename SubFiller=void>
			struct subroll_0
			{
			};

			template<typename SubFiller>
			struct subroll_0<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll_0<0, Filler>
		{
		};
	};
    }
   }
  }
 }
}

#endif
