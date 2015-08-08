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

#ifndef CONTEXT_ITERATOR_VALUE_H
#define CONTEXT_ITERATOR_VALUE_H

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
			iterator_value:
				The minimal specification (axiomatic properties) of a iterator_value are:
				typedefs:
				constructors:
				accessors:
*/
		struct iterator_value
		{
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
	repeat:
		Assumes out memory already allocated and is simply being overwritten instead of constructed and assigned.
*/
			template<typename Iterator, typename ValueType>
			static void assign(Iterator out, const Iterator end, const ValueType & value)
				{ while (out != end) *(out++)=value; }

			template<typename OutputIterator, typename InputIterator>
			static OutputIterator decrement_assign(OutputIterator out, InputIterator in, const InputIterator end)
				{ while (in != end) *(out--)=*(in--); return out; }
/*
	recursive:
			Most contextual structs aren't templated, while their methods are.
			The few structs that are pass instances of types (eg. digit: "size_type base")
			within their template parameters, and so it makes sense to factor out the typename as part of the struct.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The recursive struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
			template<size_type N, typename Filler=void>
			struct recursive
			{
/*
	Assumes ascending order.
*/
				template<typename Iterator>
				static bool equal(Iterator in1, Iterator in2)
					{ return (*in1 == *in2) && recursive<N-1>::equal(++in1, ++in2); }
/*
	Assumes ascending order.
*/
				template<typename Iterator>
				static bool not_equal(Iterator in1, Iterator in2)
					{ return (*in1 != *in2) || recursive<N-1>::not_equal(++in1, ++in2); }
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool less_than(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					else return recursive<N-1>::less_than(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool less_than_or_equal(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 < *in2);
					else return recursive<N-1>::less_than_or_equal(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool greater_than(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					else return recursive<N-1>::greater_than(--in1, --in2);
				}
/*
	Assumes descending order.
*/
				template<typename Iterator>
				static bool greater_than_or_equal(Iterator in1, Iterator in2)
				{
					if (*in1 != *in2) return (*in1 > *in2);
					else return recursive<N-1>::greater_than_or_equal(--in1, --in2);
				}
/*
	Assumes ascending order.
*/
				template<typename OutputIterator, typename InputIterator>
				static void copy(OutputIterator out, InputIterator in)
				{
					*out=*in;
					recursive<N-1>::copy(++out, ++in);
				}
/*
	Assumes ascending order.
*/
				template<typename Iterator, typename ValueType>
				static void assign(Iterator out, ValueType in)
				{
					*out=in;
					recursive<N-1>::assign(++out, in);
				}
/*
	Assumes ascending order.
*/
				template<typename Iterator, typename ValueType>
				static Iterator rep(Iterator out, ValueType in)
				{
					*out=in;
					return recursive<N-1>::rep(++out, in);
				}
/*
	Assumes ascending order.

	Choice of (*out < *in2) is intentional as it provides higher entropy---it allows in1 == out (but in2 != out).
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void plus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
				{
					*out=*in1 + *in2 + carry;
					recursive<N-1>::plus(++out, ++in1, ++in2, (*out < *in2));
				}

				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void plus_assign(OutputIterator out, InputIterator in, ValueType carry)
				{
					*out+=*in + carry;
					recursive<N-1>::plus_assign(++out, ++in, (*out < *in));
				}
/*
	Assumes ascending order.
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void minus(OutputIterator out, InputIterator in1, InputIterator in2, ValueType carry)
				{
					*out=*in1 - *in2 - carry;
					recursive<N-1>::minus(++out, ++in1, ++in2, (*out > *in2));
				} out+in2+carry=in1	in1 < out, in1 < in2

/*
	Assumes ascending order.

	Obfuscated code ?
*/
				template<typename OutputIterator, typename InputIterator, typename ValueType>
				static void scale(OutputIterator out, InputIterator in1, ValueType in2, ValueType carry)
					{ recursive<N-1>::scale(++out, ++in1, in2, times(*out=carry, *in1, in2)); }

				template<size_type M, typename SubFiller=void>
				struct subrecursive
				{
/*
	There's no point in having a shift which takes block input as shift quantity,
	as shift quantity itself can only be as big as the size of an array.
*/
					template<typename OutputIterator, typename ValueType>
					static void left_shift_assign(OutputIterator out)
					{
						recursive<N-M>::backcopy(out+(N-1), out+(M-1));
						recursive<M>::assign(out, 0);
					}
/*
	Does not assume anything about the existing value of out1.
*/
					template<typename OutputIterator, typename InputIterator>
					static void asterisk(OutputIterator out1, OutputIterator out2, InputIterator in1, InputIterator in2)
					{
						recursive<M>::scale(recursive<N-M>::rep(out2, 0), in1, *in2, (size_type) 0);
						plus_assign(out1, out2, 0);
						subrecursive<M-1>::asterisk(out1, out2, in1, ++in2);
					}
				};

				template<typename SubFiller>
				struct subrecursive<1, SubFiller>
				{
					template<typename OutputIterator, typename ValueType>
					static void left_shift_assign(OutputIterator out)
					{
						recursive<N-1>::backcopy(out+(N-1), out);
						recursive<1>::assign(out, 0);
					}

					template<typename OutputIterator, typename InputIterator>
					static void asterisk(OutputIterator out1, OutputIterator out2, InputIterator in1, InputIterator in2)
					{
						recursive<1>::scale(recursive<N-1>::rep(out2, 0), in1, *in2, (size_type) 0);
						plus_assign(out1, out2, 0);
					}
				};
			};

			template<typename Filler>
			struct recursive<1, Filler>
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
			struct recursive<0, Filler>
			{
				template<typename Iterator, typename ValueType>
				static Iterator rep(Iterator out, ValueType in) { return out; }
			};
		};
	}
}

#endif
