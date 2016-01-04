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
	For the "natural" right_shift,
	define in2 = ++InputIterator(in1),
	as well as n = constant::register_length-m,
	finally, *out=(*in1>>m) needs appending.
*/
		struct right_shift
		{
			template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator>
			static void no_return(OutputIterator out, InputIterator1 in1,
				InputIterator2 in2, TerminalIterator end, size_type m, size_type n)
			{
				while (in2 != end)
				{
					*out=(*in1>>m)+(*in2<<n);
					++out; ++in1; ++in2;
				}
			}

			template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator>
			static OutputIterator with_return(OutputIterator out, InputIterator1 in1,
				InputIterator2 in2, TerminalIterator end, size_type m, size_type n)
			{
				while (in2 != end)
				{
					*out=(*in1>>m)+(*in2<<n);
					++out; ++in1; ++in2;
				}

				return out;
			}
		};
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
*/
			template<typename Iterator1, typename Iterator2>
			static bool equal(Iterator1 in1, Iterator2 in2)
				{ return (*in1 == *in2) && unroll_0<N-1>::equal(++in1, ++in2); }
/*
*/
			template<typename Iterator1, typename Iterator2>
			static bool not_equal(Iterator1 in1, Iterator2 in2)
				{ return (*in1 != *in2) || unroll_0<N-1>::not_equal(++in1, ++in2); }
/*
	N is interpreted here as (array length - # of array positional shifts).

	For the "natural" right_shift,
	define in2 = ++InputIterator(in1),
	as well as n = constant::register_length-m.
*/
			struct right_shift
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, size_type m, size_type n)
				{
					*out=(*in1>>m)+(*in2<<n);
					unroll_0<N-1>::right_shift::no_return(++out, ++in1, ++in2, m, n);
				}

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
				static OutputIterator with_return(OutputIterator out,
					InputIterator1 in1, InputIterator2 in2, size_type m, size_type n)
				{
					*out=(*in1>>m)+(*in2<<n);
					return unroll_0<N-1>::right_shift::with_return(++out, ++in1, ++in2, m, n);
				}
			};
/*
	Need for separate no_return, with_return versions as one cannot assume choice of N.

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
					ValueType tmp(*in2+carry);
					*out=*in1 - tmp;
					unroll_0<N-1>::minus::no_return(++out, ++in1, ++in2, (tmp < *in2 || *in1 < *out));
				}

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
				{
					ValueType tmp(*in2+carry);
					*out=*in1 - tmp;
					return unroll_0<N-1>::minus::with_return(++out, ++in1, ++in2, (tmp < *in2 || *in1 < *out));
				}
			};

			struct assign
			{
				struct right_shift
				{
					template<typename OutputIterator, typename InputIterator>
					static void no_return(OutputIterator out, InputIterator in, size_type m, size_type n)
					{
						(*out>>=m)+=(*in<<n);
						unroll_0<N-1>::assign::right_shift::no_return(++out, ++in, m, n);
					}

					template<typename OutputIterator, typename InputIterator>
					static OutputIterator with_return(OutputIterator out, InputIterator in, size_type m, size_type n)
					{
						(*out>>=m)+=(*in<<n);
						return unroll_0<N-1>::assign::left_shift::with_return(++out, ++in, m, n);
					}
				};

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
		};

		template<typename Filler>
		struct unroll_0<1, Filler>
		{
			template<typename Iterator1, typename Iterator2>
			static bool equal(Iterator1 in1, Iterator2 in2) { return (*in1 == *in2); }
			template<typename Iterator1, typename Iterator2>
			static bool not_equal(Iterator1 in1, Iterator2 in2) { return (*in1 != *in2); }

/*
	Does not perform adding (*in2<<n) as in2 may be past the boundary.
*/
			struct right_shift
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, size_type m, size_type n)
					{ *out=(*in1>>m); }

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
				static OutputIterator with_return(OutputIterator out,
					InputIterator1 in1, InputIterator2 in2, size_type m, size_type n)
						{ *out=(*in1>>m); return ++out; }
			};

			struct plus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ *out=*in1 + *in2 + carry; }

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ *out=*in1 + *in2 + carry; return ++out; }
			};

			struct minus
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ *out=*in1 - (*in2 + carry); }

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename ValueType>
				static OutputIterator with_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, ValueType carry)
					{ *out=*in1 - (*in2 + carry); return ++out; }
			};

			struct assign
			{
/*
	Does not perform adding (*in<<n) as in2 may be past the boundary.
*/
				struct right_shift
				{
					template<typename OutputIterator, typename InputIterator>
					static void no_return(OutputIterator out, InputIterator in, size_type m, size_type n)
						{ *out>>=m; }

					template<typename OutputIterator, typename InputIterator>
					static OutputIterator with_return(OutputIterator out, InputIterator in, size_type m, size_type n)
						{ *out>>=m; return ++out; }
				};

				struct plus
				{
					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static void no_return(OutputIterator out, InputIterator in, ValueType carry)
						{ *out+=*in + carry; }

					template<typename OutputIterator, typename InputIterator, typename ValueType>
					static OutputIterator with_return(OutputIterator out, InputIterator in, ValueType carry)
						{ *out+=*in + carry; return ++out; }
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
	For the "natural" left_shift,
	define in2 = --InputIterator(in1),
	as well as n = constant::register_length-m.
	finally, *out=(*in1<<m) needs appending.
*/
		struct left_shift
		{
			template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator>
			static void no_return(OutputIterator out, InputIterator1 in1,
				InputIterator2 in2, TerminalIterator end, size_type m, size_type n)
			{
				while (in2 != end)
				{
					*out=(*in1<<m)+(*in2>>n);
					--out; --in1; --in2;
				}
			}

			template<typename OutputIterator, typename InputIterator1, typename InputIterator2, typename TerminalIterator>
			static OutputIterator with_return(OutputIterator out, InputIterator1 in1,
				InputIterator2 in2, TerminalIterator end, size_type m, size_type n)
			{
				while (in2 != end)
				{
					*out=(*in1<<m)+(*in2>>n);
					--out; --in1; --in2;
				}

				return out;
			}
		};
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
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 < *in2);
				else return unroll_0<N-1>::less_than(--in1, --in2);
			}
/*
*/
			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 < *in2);
				else return unroll_0<N-1>::less_than_or_equal(--in1, --in2);
			}
/*
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 > *in2);
				else return unroll_0<N-1>::greater_than(--in1, --in2);
			}
/*
*/
			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(Iterator1 in1, Iterator2 in2)
			{
				if (*in1 != *in2) return (*in1 > *in2);
				else return unroll_0<N-1>::greater_than_or_equal(--in1, --in2);
			}

/*
	Finds the first occurrence along the iterator path of a non-zero value, returns the iterator position.
*/
			template<typename Iterator>
			static Iterator order(Iterator in)
			{
				if (*in) return in;
				else return unroll_0<N-1>::order(--in);
			}
/*
	N is interpreted here as (array length - # of array positional shifts).

	For the "natural" left_shift,
	define in2 = --InputIterator(in1),
	as well as n = constant::register_length-m,
*/
			struct left_shift
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
				static void no_return(OutputIterator out,
					InputIterator1 in1, InputIterator2 in2, size_type m, size_type n)
				{
					*out=(*in1<<m)+(*in2>>n);
					unroll_0<N-1>::left_shift::no_return(--out, --in1, --in2, m, n);
				}

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
				static OutputIterator with_return(OutputIterator out,
					InputIterator1 in1, InputIterator2 in2, size_type m, size_type n)
				{
					*out=(*in1<<m)+(*in2>>n);
					return unroll_0<N-1>::left_shift::with_return(--out, --in1, --in2, m, n);
				}
			};

			struct assign
			{
				struct left_shift
				{
					template<typename OutputIterator, typename InputIterator>
					static void no_return(OutputIterator out, InputIterator in, size_type m, size_type n)
					{
						(*out<<=m)+=(*in>>n);
						unroll_0<N-1>::assign::left_shift::no_return(--out, --in, m, n);
					}

					template<typename OutputIterator, typename InputIterator>
					static OutputIterator with_return(OutputIterator out, InputIterator in, size_type m, size_type n)
					{
						(*out<<=m)+=(*in>>n);
						return unroll_0<N-1>::assign::left_shift::with_return(--out, --in, m, n);
					}
				};
			};
		};

		template<typename Filler>
		struct unroll_0<1, Filler>
		{
			template<typename Iterator1, typename Iterator2>
			static bool less_than(Iterator1 in1, Iterator2 in2) { return (*in1 < *in2); }
			template<typename Iterator1, typename Iterator2>
			static bool less_than_or_equal(Iterator1 in1, Iterator2 in2) { return (*in1 <= *in2); }
			template<typename Iterator1, typename Iterator2>
			static bool greater_than(Iterator1 in1, Iterator2 in2) { return (*in1 > *in2); }
			template<typename Iterator1, typename Iterator2>
			static bool greater_than_or_equal(Iterator1 in1, Iterator2 in2) { return (*in1 >= *in2); }

/*
	Does not perform what is otherwise the standard final decrement.
*/
			template<typename Iterator>
			static Iterator order(Iterator in) { if (*in) return in; else return --in; }

/*
	Does not perform adding (*in2>>n) as in2 may be past the boundary.
*/
			struct left_shift
			{
				template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
				static void no_return(OutputIterator out, InputIterator1 in1, InputIterator2 in2, size_type m, size_type n)
					{ *out=(*in1<<m); }

				template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
				static OutputIterator with_return(OutputIterator out,
					InputIterator1 in1, InputIterator2 in2, size_type m, size_type n)
						{ *out=(*in1<<m); return --out; }
			};

			struct assign
			{
/*
	Does not perform adding (*in>>n) as in2 may be past the boundary.
*/
				struct left_shift
				{
					template<typename OutputIterator, typename InputIterator>
					static void no_return(OutputIterator out, InputIterator in, size_type m, size_type n)
						{ *out<<=m; }

					template<typename OutputIterator, typename InputIterator>
					static OutputIterator with_return(OutputIterator out, InputIterator in, size_type m, size_type n)
						{ *out<<=m; return --out; }
				};
			};
		};
	};
    }

    namespace bidirectional
    {
	template<typename size_type>
	struct arithmetic_0
	{
	};
    }
    
    namespace random_access
    {
	template<typename size_type>
	struct arithmetic_0
	{
	};
    }
   }
  }
 }
}

#endif
