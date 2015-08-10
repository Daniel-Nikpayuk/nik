/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef CONTEXT_ITERATOR_H
#define CONTEXT_ITERATOR_H

#include"iterator_macro.h"

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	overload:
		38 operators referenced from: http://en.cppreference.com/w/cpp/language/operators

		Componentwise operators are similar enough to factorize and pass the specific operator
		as a method, but it is more cpu efficient to NOT---especially given there are few practical
		contexts in which many different such operators will all be used together.

		Side effects at the general coder level is bad policy, but at this intended low level where
		safety is minimal it is more memory efficient given the dynamic size of arrays.
		No assumption is made toward the referenced output vector to being empty. The method mapped
		values from the input vector(s) are appended to the output vector.

		The other reason for passing the output vector as a reference is that it allows for type deduction.
*/

namespace nik
{
	namespace context
	{
/*
			iterator:
				The minimal specification (axiomatic properties) of an iterator are:
				typedefs:
				constructors:
				accessors:

			For iterators in general, references are a derived type,
			but for compatibility with pointers no such derivation is assumed.

			Methods that have more than one template typename (eg. Iterator1, Iterator2) have so for higher
			entropy, but in practice you may need to optimize (eg. Iterator2=const Iterator1 &).
*/
		template<typename size_type>
		struct iterator
		{
		};

/************************************************************************************************************************/

/*
		Strictly speaking, there are infinitely many different "plus" methods based on side effects.
*/
		template<typename size_type>
		struct forward_iterator : public iterator<size_type>
		{
/////////////////////////////////////////////////////////////
//	Iterator modifiers
/////////////////////////////////////////////////////////////
/*
	size:
*/
			template<typename InputIterator, typename TerminalIterator>
			static size_type size(InputIterator in, TerminalIterator end)
			{
				size_type length(0);
				while (in++ != end) ++length;
				return length;
			}
/*
	Breaks for n < 0.

	In practice, when specifying the template typename Iterator, you need to specify if it's a reference or not.
	Admittedly the most natural application is as reference by default, but as the (++) method could be user defined
	for side effects of some shared internal state, it's problematic to constrain this generic method unnecessarily.
*/
			template<typename Iterator>
			static void left_increment(Iterator out, size_type n)
				{ while (n--) ++out; }
/*
	Breaks for n < 0.

	Alternative is to code as "while (--n) ++out; return ++out;" which optimizes better but breaks for n <= 0.

	In practice, when specifying the template typename Iterator, you need to specify if it's a reference or not.
*/
			template<typename Iterator>
			static Iterator left_increment(Iterator out, size_type n)
			{
				while (n--) ++out;
				return out;
			}
/*
	Breaks for n < 0.

	In practice, when specifying the template typename Iterator, you need to specify if it's a reference or not.
*/
			template<typename Iterator>
			static Iterator right_increment(Iterator out, size_type n)
			{
				Iterator rtn(out);
				while (n--) ++out;
				return rtn;
			}
/////////////////////////////////////////////////////////////
//	Iterator value (dereference) modifiers
/////////////////////////////////////////////////////////////
/*
	+:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			void_overload1(++, plus, =+)
			return_overload1(++, plus, =+)

			void_overload2(++, plus, +)
			return_overload2(++, plus, +)
/*
	-:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			void_overload1(++, minus, =-)
			return_overload1(++, minus, =-)

			void_overload2(++, minus, -)
			return_overload2(++, minus, -)
/*
	*:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			void_overload1(++, asterisk, =*)
			return_overload1(++, asterisk, =*)

			void_overload2(++, asterisk, *)
			return_overload2(++, asterisk, *)
/*
	/:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, slash, /)
			return_overload2(++, slash, /)
/*
	%:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, percent, %)
			return_overload2(++, percent, %)
/*
	ˆ:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, caret, ^)
			return_overload2(++, caret, ^)
/*
	&:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			void_overload1(++, ampersand, =&)
			return_overload1(++, ampersand, =&)

			void_overload2(++, ampersand, &)
			return_overload2(++, ampersand, &)
/*
	|:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, bar, |)
			return_overload2(++, bar, |)
/*
	~:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			void_overload1(++, tilde, =~)
			return_overload1(++, tilde, =~)
/*
	!:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			void_overload1(++, exclamation, =!)
			return_overload1(++, exclamation, =!)
/*
	=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.

	There's no need for a "return" version of "constant value" assign as the out iterator equals the end iterator upon halting.
*/
			void_overload1(++, assign, =)
			const_overload1(++, repeat, =)
			return_overload1(++, assign, =)
/*
	<:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, less_than, <)
			return_overload2(++, less_than, <)
/*
	>:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, greater_than, >)
			return_overload2(++, greater_than, >)
/*
	+=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.

	There's no need for a "return" version of "constant value" plus_assign as the out iterator equals the end iterator upon halting.
*/
			void_overload1(++, plus_assign, +=)
			const_overload1(++, plus_repeat, +=)
			return_overload1(++, plus_assign, +=)
/*
	-=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, minus_assign, -=)
			const_overload1(++, minus_repeat, -=)
			return_overload1(++, minus_assign, -=)
/*
	*=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, asterisk_assign, *=)
			const_overload1(++, asterisk_repeat, *=)
			return_overload1(++, asterisk_assign, *=)
/*
	/=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, slash_assign, /=)
			const_overload1(++, slash_repeat, /=)
			return_overload1(++, slash_assign, /=)
/*
	%=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, percent_assign, %=)
			const_overload1(++, percent_repeat, %=)
			return_overload1(++, percent_assign, %=)
/*
	ˆ=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, caret_assign, ^=)
			const_overload1(++, caret_repeat, ^=)
			return_overload1(++, caret_assign, ^=)
/*
	&=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, ampersand_assign, &=)
			const_overload1(++, ampersand_repeat, &=)
			return_overload1(++, ampersand_assign, &=)
/*
	|=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, bar_assign, |=)
			const_overload1(++, bar_repeat, |=)
			return_overload1(++, bar_assign, |=)
/*
	<<:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, left_shift, <<)
			return_overload2(++, left_shift, <<)
/*
	>>:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, right_shift, >>)
			return_overload2(++, right_shift, >>)
/*
	>>=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, right_shift_assign, >>=)
			const_overload1(++, right_shift_repeat, >>=)
			return_overload1(++, right_shift_assign, >>=)
/*
	<<=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(++, left_shift_assign, <<=)
			const_overload1(++, left_shift_repeat, <<=)
			return_overload1(++, left_shift_assign, <<=)
/*
	==:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, equals, ==)
			return_overload2(++, equals, ==)
/*
	!=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, not_equals, !=)
			return_overload2(++, not_equals, !=)
/*
	<=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, less_than_or_equal, <=)
			return_overload2(++, less_than_or_equal, <=)
/*
	>=:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, greater_than_or_equal, >=)
			return_overload2(++, greater_than_or_equal, >=)
/*
	&&:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, logical_and, &&)
			return_overload2(++, logical_and, &&)
/*
	||:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, logical_or, ||)
			return_overload2(++, logical_or, ||)
/*
	++:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			left_overload0(++, left_increment, ++)
			right_overload0(++, right_increment, ++)
/*
	--:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			left_overload0(++, left_decrement, --)
			right_overload0(++, right_decrement, --)
/*
	,:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType comma(InputType1 x, InputType2 y) { return x,y; }
*/
/*
	->*:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload2(++, point_asterisk, ->*)
			return_overload2(++, point_asterisk, ->*)
/*
	->:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			return_overload2(++, point, .operator->)
/*
	():

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
/*
	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/
			right_overload0(++, parentheses, ())

			right_void_overload1(++, parentheses, =, ())
			right_return_overload1(++, parentheses, =, ())

			void_overload2(++, parentheses, )
			return_overload2(++, parentheses, )
/*
	[]:

	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			bracket_void_overload2(++, brackets, )
			bracket_return_overload2(++, brackets, )
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
			struct unroll
			{
/*
	Assumes ascending order.
*/
				template<typename Iterator>
				static bool equal(Iterator in1, Iterator in2)
					{ return (*in1 == *in2) && unroll<N-1>::equal(++in1, ++in2); }
/*
	Assumes ascending order.
*/
				template<typename Iterator>
				static bool not_equal(Iterator in1, Iterator in2)
					{ return (*in1 != *in2) || unroll<N-1>::not_equal(++in1, ++in2); }
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool less_than(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					else return unroll<N-1>::less_than(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool less_than_or_equal(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					else return unroll<N-1>::less_than_or_equal(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool greater_than(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					else return unroll<N-1>::greater_than(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool greater_than_or_equal(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					else return unroll<N-1>::greater_than_or_equal(--in1, --in2);
				}
/*
	Assumes ascending order.
*/
				template<typename OutputIterator, typename InputIterator>
				static void copy(OutputIterator out, InputIterator in)
				{
					*out=*in;
					unroll<N-1>::copy(++out, ++in);
				}
/*
	Assumes ascending order.
*/
				template<typename Iterator, typename ValueType>
				static void assign(Iterator out, ValueType in)
				{
					*out=in;
					unroll<N-1>::assign(++out, in);
				}
/*
	Assumes ascending order.
*/
				template<typename Iterator, typename ValueType>
				static Iterator rep(Iterator out, ValueType in)
				{
					*out=in;
					return unroll<N-1>::rep(++out, in);
				}
/*
	Assumes ascending order.

	Choice of (*out < *in2) is intentional as it provides higher entropy---it allows in1 == out (but in2 != out).
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
				{
					*out=*in1 + *in2 + carry;
					unroll<N-1>::plus(++out, ++in1, ++in2, (*out < *in2));
				}

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void plus_assign(OutputIterator out, InputIterator in, ValueType carry)
				{
					*out+=*in + carry;
					unroll<N-1>::plus_assign(++out, ++in, (*out < *in));
				}
/*
	Assumes ascending order.

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void minus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
				{
					*out=*in1 - *in2 - carry;
					unroll<N-1>::minus(++out, ++in1, ++in2, (*out > *in2));
				} out+in2+carry=in1	in1 < out, in1 < in2
*/
/*
	Assumes ascending order.

	Obfuscated code ?
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void scale(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ unroll<N-1>::scale(++out, ++in1, in2, times(*out=carry, *in1, in2)); }

				template<size_type M, typename SubFiller=void>
				struct subunroll
				{
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.
*/
					template<typename OutputIterator, typename ValueType>
					static void left_shift_assign(OutputIterator out)
					{
						unroll<N-M>::backcopy(out+(N-1), out+(M-1));
						unroll<M>::assign(out, 0);
					}
/*
	Does not assume anything about the existing value of out1.
*/
					template<typename OutputIterator, typename InputIterator>
					static void asterisk(OutputIterator out1, OutputIterator out2, InputIterator in1, InputIterator in2)
					{
						unroll<M>::scale(unroll<N-M>::rep(out2, 0), in1, *in2, (size_type) 0);
						plus_assign(out1, out2, 0);
						subunroll<M-1>::asterisk(out1, out2, in1, ++in2);
					}
				};

				template<typename SubFiller>
				struct subunroll<1, SubFiller>
				{
					template<typename OutputIterator, typename ValueType>
					static void left_shift_assign(OutputIterator out)
					{
						unroll<N-1>::backcopy(out+(N-1), out);
						unroll<1>::assign(out, 0);
					}

					template<typename OutputIterator, typename InputIterator>
					static void asterisk(OutputIterator out1, OutputIterator out2, InputIterator in1, InputIterator in2)
					{
						unroll<1>::scale(unroll<N-1>::rep(out2, 0), in1, *in2, (size_type) 0);
						plus_assign(out1, out2, 0);
					}
				};
			};

			template<typename Filler>
			struct unroll<1, Filler>
			{
				template<typename Iterator>
				static bool equal(Iterator in1, Iterator in2) { return (*in1 == *in2); }
				template<typename Iterator>
				static bool not_equal(Iterator in1, Iterator in2) { return (*in1 != *in2); }

				template<typename Iterator>
				static bool less_than(Iterator in1, Iterator in2) { return (*in1 < *in2); }
				template<typename Iterator>
				static bool less_than_or_equal(Iterator in1, Iterator in2) { return (*in1 <= *in2); }
				template<typename Iterator>
				static bool greater_than(Iterator in1, Iterator in2) { return (*in1 > *in2); }
				template<typename Iterator>
				static bool greater_than_or_equal(Iterator in1, Iterator in2) { return (*in1 >= *in2); }

				template<typename OutputIterator, typename InputIterator>
				static void copy(OutputIterator out, InputIterator in) { *out=*in; }
				template<typename Iterator, typename ValueType>
				static void assign(Iterator out, ValueType in) { *out=in; }
				template<typename Iterator, typename ValueType>
				static Iterator rep(Iterator out, ValueType in) { *out=in; return ++out; }

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
					{ *out=*in1 + *in2 + carry; }

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void plus_assign(OutputIterator out, InputIterator in, ValueType carry)
					{ *out+=*in + carry; }
/*
	Obfuscated code ?
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void scale(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ times(*out=carry, *in1, in2); }
			};

			template<typename Filler>
			struct unroll<0, Filler>
			{
				template<typename Iterator, typename ValueType>
				static Iterator rep(Iterator out, ValueType in) { return out; }
			};
		};

/************************************************************************************************************************/

		template<typename size_type>
		struct bidirectional_iterator : public forward_iterator<size_type>
		{
/*
	Breaks for n < 0.

	Alternative is to code as "while (--n) --out; return --out;" which optimizes better but breaks for n <= 0.
*/
			template<typename Iterator>
			static Iterator left_decrement(Iterator & out, size_type n)
			{
				while (n--) --out;
				return out;
			}
/*
	Breaks for n < 0.
*/
			template<typename Iterator>
			static Iterator right_decrement(Iterator & out, size_type n)
			{
				Iterator rtn(out);
				while (n--) --out;
				return rtn;
			}
/*
	Breaks for n < 0.
*/
			template<typename Iterator>
			static void backward(Iterator & out, size_type n)
				{ while (n--) --out; }
/*
	Breaks for n < 0.
*/
			template<typename Iterator>
			static Iterator backward(Iterator out, size_type n)
				{ while (n--) --out; return out; }
/*
	In practice, when specifying the template typename OutputIterator, you need to specify if it's a reference or not.
*/
			void_overload1(--, assign, =)
			const_overload1(--, repeat, =)
			return_overload1(--, assign, =)
		};

/************************************************************************************************************************/

		template<typename size_type>
		struct random_access_iterator : public bidirectional_iterator<size_type>
		{
			template<typename InputIterator, typename TerminalIterator>
			static size_type size(InputIterator in, TerminalIterator end)
				{ return end-in; }
		};
	}
}

#endif
