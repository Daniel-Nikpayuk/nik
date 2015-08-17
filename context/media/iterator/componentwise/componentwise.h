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

#ifndef CONTEXT_ITERATOR_COMPONENTWISE_H
#define CONTEXT_ITERATOR_COMPONENTWISE_H

#include"overload_macro.h"

/*
	overload: 38 operators referenced from: http://en.cppreference.com/w/cpp/language/operators

	Componentwise operators are similar enough to factorize and pass the specific operator
	as a method, but it is more cpu efficient to NOT---especially given there are few practical
	contexts in which many different such operators will all be used together.

	Side effects at the general coder level is bad policy, but at this intended low level where
	safety is minimal it is more memory efficient given the dynamic size of arrays.

	iterator:
		The minimal specification (axiomatic properties) of an iterator are:
		typedefs:
		constructors:
		accessors:

	For iterators in general, references are a derived type,
	but for compatibility with pointers no specific instance of a derived type is assumed.

	Methods that have more than one template typename (eg. Iterator1, Iterator2) have so for higher
	entropy, but in practice you may need to optimize (eg. Iterator2=const Iterator1 &).
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).
	As far as debugging goes, keep in mind the location of an array (as pointer) is constant and thus not
	allowed as a reference, so for example if you declare "int array[100]" you can't pass "array" directly
	if you're template parameter is specified as a variable. Instead you need to make a copy of array:
		"int *a=array", so then you can pass "a" instead.

	Strictly speaking, there are infinitely many different methods of each overload type based on side effects.
*/

namespace nik
{
	namespace context
	{
		namespace iterator
		{

/************************************************************************************************************************/
//	forward iterator

			namespace forward
			{

				struct componentwise
				{
/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(++, plus, =+)
					return_overload1(++, plus, =+)

					void_overload2(++, plus, +)
					return_overload2(++, plus, +)
/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(++, minus, =-)
					return_overload1(++, minus, =-)

					void_overload2(++, minus, -)
					return_overload2(++, minus, -)
/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(++, asterisk, =*)
					return_overload1(++, asterisk, =*)

					void_overload2(++, asterisk, *)
					return_overload2(++, asterisk, *)
/*
	/:
*/
					void_overload2(++, slash, /)
					return_overload2(++, slash, /)
/*
	%:
*/
					void_overload2(++, percent, %)
					return_overload2(++, percent, %)
/*
	ˆ:
*/
					void_overload2(++, caret, ^)
					return_overload2(++, caret, ^)
/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(++, ampersand, =&)
					return_overload1(++, ampersand, =&)

					void_overload2(++, ampersand, &)
					return_overload2(++, ampersand, &)
/*
	|:
*/
					void_overload2(++, bar, |)
					return_overload2(++, bar, |)
/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(++, tilde, =~)
					return_overload1(++, tilde, =~)
/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(++, exclamation, =!)
					return_overload1(++, exclamation, =!)
/*
	=:

	There's no need for a "return" version of "constant value" assign as the out iterator equals the end iterator upon halting.
*/
					const_overload1(++, repeat, =)
					void_overload1(++, assign, =)
					return_overload1(++, assign_return, =)
/*
	<:
*/
					void_overload2(++, less_than, <)
					return_overload2(++, less_than, <)
/*
	>:
*/
					void_overload2(++, greater_than, >)
					return_overload2(++, greater_than, >)
/*
	+=:

	There's no need for a "return" version of "constant value" plus_assign as the out iterator equals the end iterator upon halting.
*/
					const_overload1(++, plus_repeat, +=)
					void_overload1(++, plus_assign, +=)
					return_overload1(++, plus_assign_return, +=)
/*
	-=:
*/
					const_overload1(++, minus_repeat, -=)
					void_overload1(++, minus_assign, -=)
					return_overload1(++, minus_assign_return, -=)
/*
	*=:
*/
					const_overload1(++, asterisk_repeat, *=)
					void_overload1(++, asterisk_assign, *=)
					return_overload1(++, asterisk_assign_return, *=)
/*
	/=:
*/
					const_overload1(++, slash_repeat, /=)
					void_overload1(++, slash_assign, /=)
					return_overload1(++, slash_assign_return, /=)
/*
	%=:
*/
					const_overload1(++, percent_repeat, %=)
					void_overload1(++, percent_assign, %=)
					return_overload1(++, percent_assign_return, %=)
/*
	ˆ=:
*/
					const_overload1(++, caret_repeat, ^=)
					void_overload1(++, caret_assign, ^=)
					return_overload1(++, caret_assign_return, ^=)
/*
	&=:
*/
					const_overload1(++, ampersand_repeat, &=)
					void_overload1(++, ampersand_assign, &=)
					return_overload1(++, ampersand_assign_return, &=)
/*
	|=:
*/
					const_overload1(++, bar_repeat, |=)
					void_overload1(++, bar_assign, |=)
					return_overload1(++, bar_assign_return, |=)
/*
	<<:
*/
					void_overload2(++, left_shift, <<)
					return_overload2(++, left_shift, <<)
/*
	>>:
*/
					void_overload2(++, right_shift, >>)
					return_overload2(++, right_shift, >>)
/*
	>>=:
*/
					const_overload1(++, right_shift_repeat, >>=)
					void_overload1(++, right_assign, >>=)
					return_overload1(++, right_shift_assign_return, >>=)
/*
	<<=:
*/
					const_overload1(++, left_shift_repeat, <<=)
					void_overload1(++, left_assign, <<=)
					return_overload1(++, left_shift_assign_return, <<=)
/*
	==:
*/
					void_overload2(++, equals, ==)
					return_overload2(++, equals, ==)
/*
	!=:
*/
					void_overload2(++, not_equals, !=)
					return_overload2(++, not_equals, !=)
/*
	<=:
*/
					void_overload2(++, less_than_or_equal, <=)
					return_overload2(++, less_than_or_equal, <=)
/*
	>=:
*/
					void_overload2(++, greater_than_or_equal, >=)
					return_overload2(++, greater_than_or_equal, >=)
/*
	&&:
*/
					void_overload2(++, logical_and, &&)
					return_overload2(++, logical_and, &&)
/*
	||:
*/
					void_overload2(++, logical_or, ||)
					return_overload2(++, logical_or, ||)
/*
	++:
*/
					left_overload0(++, left_increment, ++)
					right_overload0(++, right_increment, ++)
/*
	--:
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
*/
					void_overload2(++, point_asterisk, ->*)
					return_overload2(++, point_asterisk, ->*)
/*
	->:
*/
					return_overload2(++, point, .operator->)
/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/
					right_overload0(++, parentheses, ())

					right_void_overload1(++, parentheses, =, ())
					right_return_overload1(++, parentheses, =, ())

					void_overload2(++, parentheses, )
					return_overload2(++, parentheses, )
/*
	[]:
*/
					bracket_void_overload2(++, brackets, )
					bracket_return_overload2(++, brackets, )
				};
/*
	unroll:
			Compiler constraints require factoring out the size_type parameter, for the partial specializations of unroll.
			I have therefore factored it out as the templated "recursive" struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
				template<typename size_type>
				struct recursive
				{
					template<size_type N, typename Filler=void>
					struct unroll
					{
/*
*/
						template<typename Iterator, typename ValueType>
						static void repeat(Iterator out, ValueType in)
						{
							*out=in;
							unroll<N-1>::repeat(++out, in);
						}
/*
*/
						template<typename Iterator, typename ValueType>
						static Iterator repeat_return(Iterator out, ValueType in)
						{
							*out=in;
							return unroll<N-1>::rep(++out, in);
						}
/*
*/
						template<typename OutputIterator, typename InputIterator>
						static void assign(OutputIterator out, InputIterator in)
						{
							*out=*in;
							unroll<N-1>::copy(++out, ++in);
						}
/*
*/
						template<typename OutputIterator, typename InputIterator>
						static OutputIterator assign_return(OutputIterator out, InputIterator in)
						{
							*out=*in;
							return unroll<N-1>::assign(++out, ++in);
						}
					};

					template<typename Filler>
					struct unroll<1, Filler>
					{
						template<typename Iterator, typename ValueType>
						static void repeat(Iterator out, ValueType in) { *out=in; }
						template<typename Iterator, typename ValueType>
						static Iterator repeat_return(Iterator out, ValueType in) { *out=in; return ++out; }
						template<typename OutputIterator, typename InputIterator>
						static void assign(OutputIterator out, InputIterator in) { *out=*in; }
						template<typename OutputIterator, typename InputIterator>
						static OutputIterator assign_return(OutputIterator out, InputIterator in)
							{ *out=*in; return ++out; }
					};

					template<typename Filler>
					struct unroll<0, Filler>
					{
						template<typename Iterator, typename ValueType>
						static Iterator repeat_return(Iterator out, ValueType in) { return out; }
					};
				};
			}

/************************************************************************************************************************/
//	backward iterator

			namespace backward
			{
				struct componentwise
				{
/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(--, plus, =+)
					return_overload1(--, plus, =+)

					void_overload2(--, plus, +)
					return_overload2(--, plus, +)
/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(--, minus, =-)
					return_overload1(--, minus, =-)

					void_overload2(--, minus, -)
					return_overload2(--, minus, -)
/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(--, asterisk, =*)
					return_overload1(--, asterisk, =*)

					void_overload2(--, asterisk, *)
					return_overload2(--, asterisk, *)
/*
	/:
*/
					void_overload2(--, slash, /)
					return_overload2(--, slash, /)
/*
	%:
*/
					void_overload2(--, percent, %)
					return_overload2(--, percent, %)
/*
	ˆ:
*/
					void_overload2(--, caret, ^)
					return_overload2(--, caret, ^)
/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(--, ampersand, =&)
					return_overload1(--, ampersand, =&)

					void_overload2(--, ampersand, &)
					return_overload2(--, ampersand, &)
/*
	|:
*/
					void_overload2(--, bar, |)
					return_overload2(--, bar, |)
/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(--, tilde, =~)
					return_overload1(--, tilde, =~)
/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
					void_overload1(--, exclamation, =!)
					return_overload1(--, exclamation, =!)
/*
	=:

	There's no need for a "return" version of "constant value" assign as the out iterator equals the end iterator upon halting.

	There is the concern where TerminalIterator "end" needs to be beyond the initial iterator address of the structure.
	In the case of a user-defined iterator class, the details of implementation informs such a discussion.
	In the case of a C++ array, I assume modular arithmetic applies to the iterator (pointer). In this case,
	as far as I've read nothing states that the array address can't start with the zero address, but even in that case (0-1 == -1)
	the algorithm will still halt accordingly. The only issue then is if the OutputIterator is a reference type, as the iterator
	then might halt in an unexpected position. Of course if one was expecting address array-1, they would know in advance not to
	dereference there, and would still need to increment to access valid data. As such there still should be no issue.
*/
					const_overload1(--, repeat, =)
					void_overload1(--, assign, =)
					return_overload1(--, assign_return, =)
/*
	<:
*/
					void_overload2(--, less_than, <)
					return_overload2(--, less_than, <)
/*
	>:
*/
					void_overload2(--, greater_than, >)
					return_overload2(--, greater_than, >)
/*
	+=:

	There's no need for a "return" version of "constant value" plus_assign as the out iterator equals the end iterator upon halting.
*/
					const_overload1(--, plus_repeat, +=)
					void_overload1(--, plus_assign, +=)
					return_overload1(--, plus_assign_return, +=)
/*
	-=:
*/
					const_overload1(--, minus_repeat, -=)
					void_overload1(--, minus_assign, -=)
					return_overload1(--, minus_assign_return, -=)
/*
	*=:
*/
					const_overload1(--, asterisk_repeat, *=)
					void_overload1(--, asterisk_assign, *=)
					return_overload1(--, asterisk_assign_return, *=)
/*
	/=:
*/
					const_overload1(--, slash_repeat, /=)
					void_overload1(--, slash_assign, /=)
					return_overload1(--, slash_assign_return, /=)
/*
	%=:
*/
					const_overload1(--, percent_repeat, %=)
					void_overload1(--, percent_assign, %=)
					return_overload1(--, percent_assign_return, %=)
/*
	ˆ=:
*/
					const_overload1(--, caret_repeat, ^=)
					void_overload1(--, caret_assign, ^=)
					return_overload1(--, caret_assign_return, ^=)
/*
	&=:
*/
					const_overload1(--, ampersand_repeat, &=)
					void_overload1(--, ampersand_assign, &=)
					return_overload1(--, ampersand_assign_return, &=)
/*
	|=:
*/
					const_overload1(--, bar_repeat, |=)
					void_overload1(--, bar_assign, |=)
					return_overload1(--, bar_assign_return, |=)
/*
	<<:
*/
					void_overload2(--, left_shift, <<)
					return_overload2(--, left_shift, <<)
/*
	>>:
*/
					void_overload2(--, right_shift, >>)
					return_overload2(--, right_shift, >>)
/*
	>>=:
*/
					const_overload1(--, right_shift_repeat, >>=)
					void_overload1(--, right_assign, >>=)
					return_overload1(--, right_shift_assign_return, >>=)
/*
	<<=:
*/
					const_overload1(--, left_shift_repeat, <<=)
					void_overload1(--, left_assign, <<=)
					return_overload1(--, left_shift_assign_return, <<=)
/*
	==:
*/
					void_overload2(--, equals, ==)
					return_overload2(--, equals, ==)
/*
	!=:
*/
					void_overload2(--, not_equals, !=)
					return_overload2(--, not_equals, !=)
/*
	<=:
*/
					void_overload2(--, less_than_or_equal, <=)
					return_overload2(--, less_than_or_equal, <=)
/*
	>=:
*/
					void_overload2(--, greater_than_or_equal, >=)
					return_overload2(--, greater_than_or_equal, >=)
/*
	&&:
*/
					void_overload2(--, logical_and, &&)
					return_overload2(--, logical_and, &&)
/*
	||:
*/
					void_overload2(--, logical_or, ||)
					return_overload2(--, logical_or, ||)
/*
	++:
*/
					left_overload0(--, left_increment, ++)
					right_overload0(--, right_increment, ++)
/*
	--:
*/
					left_overload0(--, left_decrement, --)
					right_overload0(--, right_decrement, --)
/*
	,:
				template<typename OutputType, typename InputType1, typename InputType2>
				static OutputType comma(InputType1 x, InputType2 y) { return x,y; }
*/
/*
	->*:
*/
					void_overload2(--, point_asterisk, ->*)
					return_overload2(--, point_asterisk, ->*)
/*
	->:
*/
				return_overload2(--, point, .operator->)
/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/
					right_overload0(--, parentheses, ())

					right_void_overload1(--, parentheses, =, ())
					right_return_overload1(--, parentheses, =, ())

					void_overload2(--, parentheses, )
					return_overload2(--, parentheses, )
/*
	[]:
*/
					bracket_void_overload2(--, brackets, )
					bracket_return_overload2(--, brackets, )
				};
/*
	unroll:
			Compiler constraints require factoring out the size_type parameter, for the partial specializations of unroll.
			I have therefore factored it out as the templated "recursive" struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
				template<typename size_type>
				struct recursive
				{
					template<size_type N, typename Filler=void>
					struct unroll
					{
/*
*/
						template<typename Iterator, typename ValueType>
						static void repeat(Iterator out, ValueType in)
						{
							*out=in;
							unroll<N-1>::repeat(--out, in);
						}
/*
*/
						template<typename Iterator, typename ValueType>
						static Iterator repeat_return(Iterator out, ValueType in)
						{
							*out=in;
							return unroll<N-1>::rep(--out, in);
						}
/*
*/
						template<typename OutputIterator, typename InputIterator>
						static void assign(OutputIterator out, InputIterator in)
						{
							*out=*in;
							unroll<N-1>::copy(--out, --in);
						}
/*
*/
						template<typename OutputIterator, typename InputIterator>
						static OutputIterator assign_return(OutputIterator out, InputIterator in)
						{
							*out=*in;
							return unroll<N-1>::assign(--out, --in);
						}
					};

					template<typename Filler>
					struct unroll<1, Filler>
					{
						template<typename Iterator, typename ValueType>
						static void repeat(Iterator out, ValueType in) { *out=in; }
						template<typename Iterator, typename ValueType>
						static Iterator repeat_return(Iterator out, ValueType in) { *out=in; return --out; }
						template<typename OutputIterator, typename InputIterator>
						static void assign(OutputIterator out, InputIterator in) { *out=*in; }
						template<typename OutputIterator, typename InputIterator>
						static OutputIterator assign_return(OutputIterator out, InputIterator in)
							{ *out=*in; return --out; }
					};

					template<typename Filler>
					struct unroll<0, Filler>
					{
						template<typename Iterator, typename ValueType>
						static Iterator repeat_return(Iterator out, ValueType in) { return out; }
					};
				};
			}

/************************************************************************************************************************/
//	bidirectional iterator

			namespace bidirectional
			{
				struct componentwise
				{
				};
			}

/************************************************************************************************************************/
//	random access iterator

			namespace random_access
			{
				struct componentwise
				{
				};
			}
		}
	}
}

#endif
