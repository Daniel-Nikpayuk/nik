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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_BACKWARD_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_OVERLOAD_BACKWARD_H

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
    namespace extensionwise
    {
     namespace backward
     {
	template<typename SizeType>
	struct overload
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct plus
		{
			no_return_1(-, =+)
			with_return_1(-, =+)

			no_return_2(-, +)
			with_return_2(-, +)
		};
/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct minus
		{
			no_return_1(-, =-)
			with_return_1(-, =-)

			no_return_2(-, -)
			with_return_2(-, -)
		};
/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct asterisk
		{
			no_return_1(-, =*)
			with_return_1(-, =*)

			no_return_2(-, *)
			with_return_2(-, *)
		};
/*
	/:
*/
		struct slash
		{
			no_return_2(-, /)
			with_return_2(-, /)
		};
/*
	%:
*/
		struct percent
		{
			no_return_2(-, %)
			with_return_2(-, %)
		};
/*
	ˆ:
*/
		struct caret
		{
			no_return_2(-, ^)
			with_return_2(-, ^)
		};
/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct ampersand
		{
			no_return_1(-, =&)
			with_return_1(-, =&)

			no_return_2(-, &)
			with_return_2(-, &)
		};
/*
	|:
*/
		struct bar
		{
			no_return_2(-, |)
			with_return_2(-, |)
		};
/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct tilde
		{
			no_return_1(-, =~)
			with_return_1(-, =~)
		};
/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
		struct exclamation
		{
			no_return_1(-, =!)
			with_return_1(-, =!)
		};
/*
	<:
*/
		struct less_than
		{
			no_return_2(-, <)
			with_return_2(-, <)
		};
/*
	>:
*/
		struct greater_than
		{
			no_return_2(-, >)
			with_return_2(-, >)
		};
/*
	<<:
*/
		struct left_shift
		{
			no_return_2(-, <<)
			with_return_2(-, <<)
		};
/*
	>>:
*/
		struct right_shift
		{
			no_return_2(-, >>)
			with_return_2(-, >>)
		};
/*
	==:
*/
		struct equals
		{
			no_return_2(-, ==)
			with_return_2(-, ==)
		};
/*
	!=:
*/
		struct not_equals
		{
			no_return_2(-, !=)
			with_return_2(-, !=)
		};
/*
	<=:
*/
		struct less_than_or_equal
		{
			no_return_2(-, <=)
			with_return_2(-, <=)
		};
/*
	>=:
*/
		struct greater_than_or_equal
		{
			no_return_2(-, >=)
			with_return_2(-, >=)
		};
/*
	&&:
*/
		struct logical_and
		{
			no_return_2(-, &&)
			with_return_2(-, &&)
		};
/*
	||:
*/
		struct logical_or
		{
			no_return_2(-, ||)
			with_return_2(-, ||)
		};
/*
	++:
*/
		struct left_increment
		{
			no_return_left_0(-, ++)
		};

		struct right_increment
		{
			no_return_right_0(-, ++)
		};
/*
	--:
*/
		struct left_decrement
		{
			no_return_left_0(-, --)
		};

		struct right_decrement
		{
			no_return_right_0(-, --)
		};
/*
	,:
*/
		struct comma
		{
		};

/*
	->*:
*/
		struct point_asterisk
		{
			no_return_2(-, ->*)
			with_return_2(-, ->*)
		};
/*
	->:
*/
		struct point
		{
			with_return_2(-, .operator->)
		};
/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/
		struct parentheses
		{
			no_return_right_0(-, ())

			no_return_right_1(-, =, ())
			with_return_right_1(-, =, ())

			no_return_2(-, )
			with_return_2(-, )
		};
/*
	[]:
*/
		struct brackets
		{
			no_return_bracket_2(-, )
			with_return_bracket_2(-, )
		};
/*
	There's no need for a "return" version of "c_policy::unit value" assign as the out iterator equals the end iterator upon halting.

	There is the concern where EIterator "end" needs to be beyond the initial iterator address of the structure.
	In the case of a user-defined iterator class, the details of implementation informs such a discussion.
	In the case of a C++ array, I assume modular arithmetic applies to the iterator (pointer). In this case,
	as far as I've read nothing states that the array address can't start with the zero address, but even in that case (0-1 == -1)
	the algorithm will still halt accordingly. The only issue then is if the WIterator is a reference type, as the iterator
	then might halt in an unexpected position. Of course if one was expecting address array-1, they would know in advance not to
	dereference there, and would still need to increment to access valid data. As such there still should be no issue.
*/
		struct repeat
		{
/*
		=:
*/
			no_return_0(-, =)
/*
		+=:
*/
			struct plus
			{
				no_return_0(-, +=)
			};
/*
		-=:
*/
			struct minus
			{
				no_return_0(-, -=)
			};
/*
		*=:
*/
			struct asterisk
			{
				no_return_0(-, *=)
			};
/*
		/=:
*/
			struct slash
			{
				no_return_0(-, /=)
			};
/*
		%=:
*/
			struct percent
			{
				no_return_0(-, %=)
			};
/*
		ˆ=:
*/
			struct caret
			{
				no_return_0(-, ^=)
			};
/*
		&=:
*/
			struct ampersand
			{
				no_return_0(-, &=)
			};
/*
		|=:
*/
			struct bar
			{
				no_return_0(-, |=)
			};
/*
		>>=:
*/
			struct right_shift
			{
				no_return_0(-, >>=)
			};
/*
		<<=:
*/
			struct left_shift
			{
				no_return_0(-, <<=)
			};
		};

		struct assign
		{
/*
		=:
*/
			no_return_1(-, =)
			with_return_1(-, =)
/*
		+=:
*/
			struct plus
			{
				no_return_1(-, +=)
				with_return_1(-, +=)
			};
/*
		-=:
*/
			struct minus
			{
				no_return_1(-, -=)
				with_return_1(-, -=)
			};
/*
		*=:
*/
			struct asterisk
			{
				no_return_1(-, *=)
				with_return_1(-, *=)
			};
/*
		/=:
*/
			struct slash
			{
				no_return_1(-, /=)
				with_return_1(-, /=)
			};
/*
		%=:
*/
			struct percent
			{
				no_return_1(-, %=)
				with_return_1(-, %=)
			};
/*
		ˆ=:
*/
			struct caret
			{
				no_return_1(-, ^=)
				with_return_1(-, ^=)
			};
/*
		&=:
*/
			struct ampersand
			{
				no_return_1(-, &=)
				with_return_1(-, &=)
			};
/*
		|=:
*/
			struct bar
			{
				no_return_1(-, |=)
				with_return_1(-, |=)
			};
/*
		>>=:
*/
			struct right_shift
			{
				no_return_1(-, >>=)
				with_return_1(-, >>=)
			};
/*
		<<=:
*/
			struct left_shift
			{
				no_return_1(-, <<=)
				with_return_1(-, <<=)
			};
		};
/*
	unroll:
			Compiler constraints require factoring out the size_type parameter, for the partial specializations of unroll.
			I have therefore factored it out as the templated "extend" struct. Notice the semantics of the word "extend"
			itself are a signifier of the overhead word space, which is to say it's a metaname.

			Generally having a template parameter which isn't directly used implies lower generic entropy if it
			isn't used directly in any of the methods (for example its subtypes are used instead). The unroll struct
			below is an exception to the exising design for no other reason than the need for partial template
			specialization: Explicit specialization isn't allowed. Otherwise, the Filler typename isn't even used.
*/
		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct plus
			{
				unroll_no_return_1(plus, -, =+)
				unroll_with_return_1(plus, -, =+)

				unroll_no_return_2(plus, -, +)
				unroll_with_return_2(plus, -, +)
			};
/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct minus
			{
				unroll_no_return_1(minus, -, =-)
				unroll_with_return_1(minus, -, =-)

				unroll_no_return_2(minus, -, -)
				unroll_with_return_2(minus, -, -)
			};
/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct asterisk
			{
				unroll_no_return_1(asterisk, -, =*)
				unroll_with_return_1(asterisk, -, =*)

				unroll_no_return_2(asterisk, -, *)
				unroll_with_return_2(asterisk, -, *)
			};
/*
	/:
*/
			struct slash
			{
				unroll_no_return_2(slash, -, /)
				unroll_with_return_2(slash, -, /)
			};
/*
	%:
*/
			struct percent
			{
				unroll_no_return_2(percent, -, %)
				unroll_with_return_2(percent, -, %)
			};
/*
	ˆ:
*/
			struct caret
			{
				unroll_no_return_2(caret, -, ^)
				unroll_with_return_2(caret, -, ^)
			};
/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct ampersand
			{
				unroll_no_return_1(ampersand, -, =&)
				unroll_with_return_1(ampersand, -, =&)

				unroll_no_return_2(ampersand, -, &)
				unroll_with_return_2(ampersand, -, &)
			};
/*
	|:
*/
			struct bar
			{
				unroll_no_return_2(bar, -, |)
				unroll_with_return_2(bar, -, |)
			};
/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct tilde
			{
				unroll_no_return_1(tilde, -, =~)
				unroll_with_return_1(tilde, -, =~)
			};
/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct exclamation
			{
				unroll_no_return_1(exclamation, -, =!)
				unroll_with_return_1(exclamation, -, =!)
			};
/*
	<:
*/
			struct less_than
			{
				unroll_no_return_2(less_than, -, <)
				unroll_with_return_2(less_than, -, <)
			};
/*
	>:
*/
			struct greater_than
			{
				unroll_no_return_2(greater_than, -, >)
				unroll_with_return_2(greater_than, -, >)
			};
/*
	<<:
*/
			struct left_shift
			{
				unroll_no_return_2(left_shift, -, <<)
				unroll_with_return_2(left_shift, -, <<)
			};
/*
	>>:
*/
			struct right_shift
			{
				unroll_no_return_2(right_shift, -, >>)
				unroll_with_return_2(right_shift, -, >>)
			};
/*
	==:
*/
			struct equals
			{
				unroll_no_return_2(equals, -, ==)
				unroll_with_return_2(equals, -, ==)
			};
/*
	!=:
*/
			struct not_equals
			{
				unroll_no_return_2(not_equals, -, !=)
				unroll_with_return_2(not_equals, -, !=)
			};
/*
	<=:
*/
			struct less_than_or_equal
			{
				unroll_no_return_2(less_than_or_equal, -, <=)
				unroll_with_return_2(less_than_or_equal, -, <=)
			};
/*
	>=:
*/
			struct greater_than_or_equal
			{
				unroll_no_return_2(greater_than_or_equal, -, >=)
				unroll_with_return_2(greater_than_or_equal, -, >=)
			};
/*
	&&:
*/
			struct logical_and
			{
				unroll_no_return_2(logical_and, -, &&)
				unroll_with_return_2(logical_and, -, &&)
			};
/*
	||:
*/
			struct logical_or
			{
				unroll_no_return_2(logical_or, -, ||)
				unroll_with_return_2(logical_or, -, ||)
			};
/*
	++:
*/
			struct left_increment
			{
				unroll_no_return_left_0(left_increment, -, ++)
			};

			struct right_increment
			{
				unroll_no_return_right_0(right_increment, -, ++)
			};
/*
	--:
*/
			struct left_decrement
			{
				unroll_no_return_left_0(left_decrement, -, --)
			};

			struct right_decrement
			{
				unroll_no_return_right_0(right_decrement, -, --)
			};
/*
	,:
*/
			struct comma
			{
			};
/*
	->*:
*/
			struct point_asterisk
			{
				unroll_no_return_2(point_asterisk, -, ->*)
				unroll_with_return_2(point_asterisk, -, ->*)
			};
/*
	->:
*/
			struct point
			{
				unroll_with_return_2(point, -, .operator->)
			};
/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/
			struct parentheses
			{
				unroll_no_return_right_0(parentheses, -, ())

				unroll_no_return_right_1(parentheses, -, =, ())
				unroll_with_return_right_1(parentheses, -, =, ())

				unroll_no_return_2(parentheses, -, )
				unroll_with_return_2(parentheses, -, )
			};
/*
	[]:
*/
			struct brackets
			{
				unroll_no_return_bracket_2(brackets, -, )
				unroll_with_return_bracket_2(brackets, -, )
			};
/*
	There's no need for a "return" version of "c_policy::unit value" assign as the out iterator equals the end iterator upon halting.
*/
			struct repeat
			{
/*
		=:
*/
				unroll_no_return_0(repeat, -, =)
/*
		+=:
*/
				struct plus
				{
					unroll_no_return_0(plus, -, +=)
				};
/*
		-=:
*/
				struct minus
				{
					unroll_no_return_0(minus, -, -=)
				};
/*
		*=:
*/
				struct asterisk
				{
					unroll_no_return_0(asterisk, -, *=)
				};
/*
		/=:
*/
				struct slash
				{
					unroll_no_return_0(slash, -, /=)
				};
/*
		%=:
*/
				struct percent
				{
					unroll_no_return_0(percent, -, %=)
				};
/*
		ˆ=:
*/
				struct caret
				{
					unroll_no_return_0(caret, -, ^=)
				};
/*
		&=:
*/
				struct ampersand
				{
					unroll_no_return_0(ampersand, -, &=)
				};
/*
		|=:
*/
				struct bar
				{
					unroll_no_return_0(bar, -, |=)
				};
/*
		>>=:
*/
				struct right_shift
				{
					unroll_no_return_0(right_shift, -, >>=)
				};
/*
		<<=:
*/
				struct left_shift
				{
					unroll_no_return_0(left_shift, -, <<=)
				};
			};

			struct assign
			{
/*
		=:
*/
				unroll_no_return_1(assign, -, =)
				unroll_with_return_1(assign, -, =)
/*
		+=:
*/
				struct plus
				{
					unroll_no_return_1(plus, -, +=)
					unroll_with_return_1(plus, -, +=)
				};
/*
		-=:
*/
				struct minus
				{
					unroll_no_return_1(minus, -, -=)
					unroll_with_return_1(minus, -, -=)
				};
/*
		*=:
*/
				struct asterisk
				{
					unroll_no_return_1(asterisk, -, *=)
					unroll_with_return_1(asterisk, -, *=)
				};
/*
		/=:
*/
				struct slash
				{
					unroll_no_return_1(slash, -, /=)
					unroll_with_return_1(slash, -, /=)
				};
/*
		%=:
*/
				struct percent
				{
					unroll_no_return_1(percent, -, %=)
					unroll_with_return_1(percent, -, %=)
				};
/*
		ˆ=:
*/
				struct caret
				{
					unroll_no_return_1(caret, -, ^=)
					unroll_with_return_1(caret, -, ^=)
				};
/*
		&=:
*/
				struct ampersand
				{
					unroll_no_return_1(ampersand, -, &=)
					unroll_with_return_1(ampersand, -, &=)
				};
/*
		|=:
*/
				struct bar
				{
					unroll_no_return_1(bar, -, |=)
					unroll_with_return_1(bar, -, |=)
				};
/*
		>>=:
*/
				struct right_shift
				{
					unroll_no_return_1(right_shift, -, >>=)
					unroll_with_return_1(right_shift, -, >>=)
				};
/*
		<<=:
*/
				struct left_shift
				{
					unroll_no_return_1(left_shift, -, <<=)
					unroll_with_return_1(left_shift, -, <<=)
				};
			};
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct plus
			{
				initial_unroll_no_return_1(plus, -, =+)
				initial_unroll_with_return_1(plus, -, =+)

				initial_unroll_no_return_2(plus, -, +)
				initial_unroll_with_return_2(plus, -, +)
			};
/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct minus
			{
				initial_unroll_no_return_1(minus, -, =-)
				initial_unroll_with_return_1(minus, -, =-)

				initial_unroll_no_return_2(minus, -, -)
				initial_unroll_with_return_2(minus, -, -)
			};
/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct asterisk
			{
				initial_unroll_no_return_1(asterisk, -, =*)
				initial_unroll_with_return_1(asterisk, -, =*)

				initial_unroll_no_return_2(asterisk, -, *)
				initial_unroll_with_return_2(asterisk, -, *)
			};
/*
	/:
*/
			struct slash
			{
				initial_unroll_no_return_2(slash, -, /)
				initial_unroll_with_return_2(slash, -, /)
			};
/*
	%:
*/
			struct percent
			{
				initial_unroll_no_return_2(percent, -, %)
				initial_unroll_with_return_2(percent, -, %)
			};
/*
	ˆ:
*/
			struct caret
			{
				initial_unroll_no_return_2(caret, -, ^)
				initial_unroll_with_return_2(caret, -, ^)
			};
/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct ampersand
			{
				initial_unroll_no_return_1(ampersand, -, =&)
				initial_unroll_with_return_1(ampersand, -, =&)

				initial_unroll_no_return_2(ampersand, -, &)
				initial_unroll_with_return_2(ampersand, -, &)
			};
/*
	|:
*/
			struct bar
			{
				initial_unroll_no_return_2(bar, -, |)
				initial_unroll_with_return_2(bar, -, |)
			};
/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct tilde
			{
				initial_unroll_no_return_1(tilde, -, =~)
				initial_unroll_with_return_1(tilde, -, =~)
			};
/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/
			struct exclamation
			{
				initial_unroll_no_return_1(exclamation, -, =!)
				initial_unroll_with_return_1(exclamation, -, =!)
			};
/*
	<:
*/
			struct less_than
			{
				initial_unroll_no_return_2(less_than, -, <)
				initial_unroll_with_return_2(less_than, -, <)
			};
/*
	>:
*/
			struct greater_than
			{
				initial_unroll_no_return_2(greater_than, -, >)
				initial_unroll_with_return_2(greater_than, -, >)
			};
/*
	<<:
*/
			struct left_shift
			{
				initial_unroll_no_return_2(left_shift, -, <<)
				initial_unroll_with_return_2(left_shift, -, <<)
			};
/*
	>>:
*/
			struct right_shift
			{
				initial_unroll_no_return_2(right_shift, -, >>)
				initial_unroll_with_return_2(right_shift, -, >>)
			};
/*
	==:
*/
			struct equals
			{
				initial_unroll_no_return_2(equals, -, ==)
				initial_unroll_with_return_2(equals, -, ==)
			};
/*
	!=:
*/
			struct not_equals
			{
				initial_unroll_no_return_2(not_equals, -, !=)
				initial_unroll_with_return_2(not_equals, -, !=)
			};
/*
	<=:
*/
			struct less_than_or_equal
			{
				initial_unroll_no_return_2(less_than_or_equal, -, <=)
				initial_unroll_with_return_2(less_than_or_equal, -, <=)
			};
/*
	>=:
*/
			struct greater_than_or_equal
			{
				initial_unroll_no_return_2(greater_than_or_equal, -, >=)
				initial_unroll_with_return_2(greater_than_or_equal, -, >=)
			};
/*
	&&:
*/
			struct logical_and
			{
				initial_unroll_no_return_2(logical_and, -, &&)
				initial_unroll_with_return_2(logical_and, -, &&)
			};
/*
	||:
*/
			struct logical_or
			{
				initial_unroll_no_return_2(logical_or, -, ||)
				initial_unroll_with_return_2(logical_or, -, ||)
			};
/*
	++:
*/
			struct left_increment
			{
				initial_unroll_no_return_left_0(left_increment, -, ++)
			};

			struct right_increment
			{
				initial_unroll_no_return_right_0(right_increment, -, ++)
			};
/*
	--:
*/
			struct left_decrement
			{
				initial_unroll_no_return_left_0(left_decrement, -, --)
			};

			struct right_decrement
			{
				initial_unroll_no_return_right_0(right_decrement, -, --)
			};
/*
	,:
*/
			struct comma
			{
			};
/*
	->*:
*/
			struct point_asterisk
			{
				initial_unroll_no_return_2(point_asterisk, -, ->*)
				initial_unroll_with_return_2(point_asterisk, -, ->*)
			};
/*
	->:
*/
			struct point
			{
				initial_unroll_with_return_2(point, -, .operator->)
			};
/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/
			struct parentheses
			{
				initial_unroll_no_return_right_0(parentheses, -, ())

				initial_unroll_no_return_right_1(parentheses, -, =, ())
				initial_unroll_with_return_right_1(parentheses, -, =, ())

				initial_unroll_no_return_2(parentheses, -, )
				initial_unroll_with_return_2(parentheses, -, )
			};
/*
	[]:
*/
			struct brackets
			{
				initial_unroll_no_return_bracket_2(brackets, -, )
				initial_unroll_with_return_bracket_2(brackets, -, )
			};
/*
	There's no need for a "return" version of "c_policy::unit value" assign as the out iterator equals the end iterator upon halting.
*/
			struct repeat
			{
/*
		=:
*/
				initial_unroll_no_return_0(repeat, -, =)
/*
		+=:
*/
				struct plus
				{
					initial_unroll_no_return_0(plus, -, +=)
				};
/*
		-=:
*/
				struct minus
				{
					initial_unroll_no_return_0(minus, -, -=)
				};
/*
		*=:
*/
				struct asterisk
				{
					initial_unroll_no_return_0(asterisk, -, *=)
				};
/*
		/=:
*/
				struct slash
				{
					initial_unroll_no_return_0(slash, -, /=)
				};
/*
		%=:
*/
				struct percent
				{
					initial_unroll_no_return_0(percent, -, %=)
				};
/*
		ˆ=:
*/
				struct caret
				{
					initial_unroll_no_return_0(caret, -, ^=)
				};
/*
		&=:
*/
				struct ampersand
				{
					initial_unroll_no_return_0(ampersand, -, &=)
				};
/*
		|=:
*/
				struct bar
				{
					initial_unroll_no_return_0(bar, -, |=)
				};
/*
		>>=:
*/
				struct right_shift
				{
					initial_unroll_no_return_0(right_shift, -, >>=)
				};
/*
		<<=:
*/
				struct left_shift
				{
					initial_unroll_no_return_0(left_shift, -, <<=)
				};
			};

			struct assign
			{
/*
		=:
*/
				initial_unroll_no_return_1(assign, -, =)
				initial_unroll_with_return_1(assign, -, =)
/*
		+=:
*/
				struct plus
				{
					initial_unroll_no_return_1(plus, -, +=)
					initial_unroll_with_return_1(plus, -, +=)
				};
/*
		-=:
*/
				struct minus
				{
					initial_unroll_no_return_1(minus, -, -=)
					initial_unroll_with_return_1(minus, -, -=)
				};
/*
		*=:
*/
				struct asterisk
				{
					initial_unroll_no_return_1(asterisk, -, *=)
					initial_unroll_with_return_1(asterisk, -, *=)
				};
/*
		/=:
*/
				struct slash
				{
					initial_unroll_no_return_1(slash, -, /=)
					initial_unroll_with_return_1(slash, -, /=)
				};
/*
		%=:
*/
				struct percent
				{
					initial_unroll_no_return_1(percent, -, %=)
					initial_unroll_with_return_1(percent, -, %=)
				};
/*
		ˆ=:
*/
				struct caret
				{
					initial_unroll_no_return_1(caret, -, ^=)
					initial_unroll_with_return_1(caret, -, ^=)
				};
/*
		&=:
*/
				struct ampersand
				{
					initial_unroll_no_return_1(ampersand, -, &=)
					initial_unroll_with_return_1(ampersand, -, &=)
				};
/*
		|=:
*/
				struct bar
				{
					initial_unroll_no_return_1(bar, -, |=)
					initial_unroll_with_return_1(bar, -, |=)
				};
/*
		>>=:
*/
				struct right_shift
				{
					initial_unroll_no_return_1(right_shift, -, >>=)
					initial_unroll_with_return_1(right_shift, -, >>=)
				};
/*
		<<=:
*/
				struct left_shift
				{
					initial_unroll_no_return_1(left_shift, -, <<=)
					initial_unroll_with_return_1(left_shift, -, <<=)
				};
			};
		};
	};
     }
    }
   }
  }
 }
}

#endif
