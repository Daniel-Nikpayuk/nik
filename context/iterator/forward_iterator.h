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

#ifndef CONTEXT_FORWARD_ITERATOR_H
#define CONTEXT_FORWARD_ITERATOR_H

#include"iterator.h"

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).
*/

namespace nik
{
	namespace context
	{
/*
			forward_iterator:
				The minimal specification (axiomatic properties) of a forward_iterator are:
				typedefs:
				constructors:
				accessors:
*/
		struct forward_iterator : public iterator
		{
			#define overload1(method, op) \
			template<typename OutputIterator, typename InputIterator> \
			static OutputIterator method(OutputIterator out, InputIterator in, const InputIterator end) \
				{ while (in != end) *(out++)op(*(in++)); return out; }

			#define overload2(method, op) \
			template<typename OutputIterator, typename InputIterator1, typename InputIterator2> \
			static OutputIterator method(OutputIterator out, InputIterator1 in1, InputIterator2 in2, const InputIterator2 end2) \
				{ while (in2 != end2) *(out++)=(*(in1++))op(*(in2++)); return out; }
/*
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
/*
	+:
*/
			overload1(plus, =+)
			overload2(plus, +)
/*
	-:
*/
			overload1(minus, =-)
			overload2(minus, -)
/*
	*:
		changes type.
*/
			overload1(asterisk, =*)
			overload2(asterisk, *)
/*
	/:
*/
			overload2(slash, /)
/*
	%:
*/
			overload2(percent, %)
/*
	ˆ:
*/
			overload2(caret, ^)
/*
	&:
		changes type.
*/
			overload1(ampersand, =&)
			overload2(ampersand, &)
/*
	|:
*/
			overload2(bar, |)
/*
	~:
*/
			overload1(tilde, =~)
/*
	!:
*/
			overload1(exclamation, =!)
/*
	=:
		reference.
*/
			overload1(assign, =)
/*
	<:
		changes type.
*/
			overload2(less_than, <)
/*
	>:
		changes type.
*/
			overload2(greater_than, >)
/*
	+=:
		reference.
*/
			overload1(plus_assign, +=)
/*
	-=:
		reference.
*/
			overload1(minus_assign, -=)
/*
	*=:
		reference.
*/
			overload1(asterisk_assign, *=)
/*
	/=:
		reference.
*/
			overload1(slash_assign, /=)
/*
	%=:
		reference.
*/
			overload1(percent_assign, %=)
/*
	ˆ=:
		reference.
*/
			overload1(caret_assign, ^=)
/*
	&=:
		reference.
*/
			overload1(ampersand_assign, &=)
/*
	|=:
		reference.
*/
			overload1(bar_assign, |=)
/*
	<<:
*/
			overload2(left_shift, <<)
/*
	>>:
*/
			overload2(right_shift, >>)
/*
	>>=:
		reference.
*/
			overload1(right_shift_assign, >>=)
/*
	<<=:
		reference.
*/
			overload1(left_shift_assign, <<=)
/*
	==:
		changes type.
*/
			overload2(equals, ==)
/*
	!=:
		changes type.
*/
			overload2(not_equals, !=)
/*
	<=:
		changes type.
*/
			overload2(less_than_or_equal, <=)
/*
	>=:
		changes type.
*/
			overload2(greater_than_or_equal, >=)
/*
	&&:
*/
			overload2(logical_and, &&)
/*
	||:
*/
			overload2(logical_or, ||)
/*
	++:
		reference.
*/
			template<typename Iterator>
			static void left_increment(Iterator out, const Iterator end)
				{ while (out != end) ++(*(out++)); }

			template<typename Iterator>
			static void right_increment(Iterator out, const Iterator end)
				{ while (out != end) (*(out++))++; }
/*
	--:
		reference.
*/
			template<typename Iterator>
			static void left_decrement(Iterator out, const Iterator end)
				{ while (out != end) --(*(out++)); }

			template<typename Iterator>
			static void right_decrement(Iterator out, const Iterator end)
				{ while (out != end) (*(out++))--; }
/*
	,:
			template<typename OutputType, typename InputType1, typename InputType2>
			static OutputType comma(InputType1 x, InputType2 y) { return x,y; }
*/
/*
	->*:
		changes type.
*/
			overload2(point_asterisk, ->*)
/*
	->:
		changes type.
*/
			template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
			static OutputIterator point(OutputIterator out, InputIterator1 in1, InputIterator2 in2, const InputIterator2 end2)
				{ while (in2 != end2) *(out++)=(*(in1++))->*(in2++); return out; }
/*
	():
		changes type.
*/
			template<typename Iterator, typename ValueType>
			static void parentheses(Iterator out, const Iterator end)
				{ while (out != end) (*(out++))(); }

			template<typename OutputIterator, typename InputIterator>
			static OutputIterator parentheses(OutputIterator out, InputIterator in, const InputIterator end)
				{ while (in != end) *(out++)=(*(in++))(); return out; }

			template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
			static OutputIterator parentheses(OutputIterator out,
				InputIterator1 in1, InputIterator2 in2, const InputIterator2 end2)
					{ while (in2 != end2) *(out++)=(*(in1++))(*(in2++)); return out; }
/*
	[]:
		changes type.
*/
			template<typename OutputIterator, typename InputIterator1, typename InputIterator2>
			static OutputIterator brackets(OutputIterator out,
				InputIterator1 in1, InputIterator2 in2, const InputIterator2 end2)
					{ while (in2 != end2) *(out++)=(*(in1++))[*(in2++)]; return out; }

/*
	size:
*/
			template<typename SizeType, typename Iterator>
			static SizeType size(Iterator out, const Iterator end)
			{
				SizeType length=0;
				while (out++ != end) ++length;
				return length;
			}
/*
	repeat:
		Assumes out memory already allocated and is simply being overwritten instead of constructed and assigned.
*/
			template<typename Iterator, typename ValueType>
			static void repeat(Iterator out, const Iterator end, const ValueType & value)
				{ while (out != end) *(out++)=value; }
		};
	}
}

#endif
