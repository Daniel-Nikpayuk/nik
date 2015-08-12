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

#ifndef CONTEXT_ITERATOR_FUNCTIONAL_H
#define CONTEXT_ITERATOR_FUNCTIONAL_H

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

namespace nik
{
	namespace context
	{
		namespace forward
		{
/*
		Strictly speaking, there are infinitely many different "plus" methods based on side effects.
*/
			template<typename size_type>
			struct functional
			{

/************************************************************************************************************************/
//	forward iterator

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
			};
		}

/************************************************************************************************************************/
//	bidirectional iterator

		namespace bidirectional
		{
			template<typename size_type>
			struct functional
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
		}

/************************************************************************************************************************/
//	random access iterator

		namespace random_access
		{
			template<typename size_type>
			struct functional
			{
				template<typename InputIterator, typename TerminalIterator>
				static size_type size(InputIterator in, TerminalIterator end)
					{ return end-in; }
			};
		}
	}
}

#endif
