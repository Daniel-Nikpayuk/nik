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

/*
	This code is not intended to be used standalone.
	It needs to be equipped with a context to be interpreted by the compiler.
	It is meant to be bootstrapped with a given macro interpretation.

	overload: 38 operators referenced from: http://en.cppreference.com/w/cpp/language/operators
*/

/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct plus
{
	unroll_no_return_1(plus, DIRECTION, =+)
	unroll_with_return_1(plus, DIRECTION, =+)

	unroll_no_return_2(plus, DIRECTION, +)
	unroll_with_return_2(plus, DIRECTION, +)
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	unroll_no_return_1(minus, DIRECTION, =-)
	unroll_with_return_1(minus, DIRECTION, =-)

	unroll_no_return_2(minus, DIRECTION, -)
	unroll_with_return_2(minus, DIRECTION, -)
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	unroll_no_return_1(asterisk, DIRECTION, =*)
	unroll_with_return_1(asterisk, DIRECTION, =*)

	unroll_no_return_2(asterisk, DIRECTION, *)
	unroll_with_return_2(asterisk, DIRECTION, *)
};

/*
	/:
*/

struct slash
{
	unroll_no_return_2(slash, DIRECTION, /)
	unroll_with_return_2(slash, DIRECTION, /)
};

/*
	%:
*/

struct percent
{
	unroll_no_return_2(percent, DIRECTION, %)
	unroll_with_return_2(percent, DIRECTION, %)
};

/*
	ˆ:
*/

struct caret
{
	unroll_no_return_2(caret, DIRECTION, ^)
	unroll_with_return_2(caret, DIRECTION, ^)
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	unroll_no_return_1(ampersand, DIRECTION, =&)
	unroll_with_return_1(ampersand, DIRECTION, =&)

	unroll_no_return_2(ampersand, DIRECTION, &)
	unroll_with_return_2(ampersand, DIRECTION, &)
};

/*
	|:
*/

struct bar
{
	unroll_no_return_2(bar, DIRECTION, |)
	unroll_with_return_2(bar, DIRECTION, |)
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	unroll_no_return_1(tilde, DIRECTION, =~)
	unroll_with_return_1(tilde, DIRECTION, =~)
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	unroll_no_return_1(exclamation, DIRECTION, =!)
	unroll_with_return_1(exclamation, DIRECTION, =!)
};

/*
	<:
*/

struct less_than
{
	unroll_no_return_2(less_than, DIRECTION, <)
	unroll_with_return_2(less_than, DIRECTION, <)
};

/*
	>:
*/

struct greater_than
{
	unroll_no_return_2(greater_than, DIRECTION, >)
	unroll_with_return_2(greater_than, DIRECTION, >)
};

/*
	<<:
*/

struct left_shift
{
	unroll_no_return_2(left_shift, DIRECTION, <<)
	unroll_with_return_2(left_shift, DIRECTION, <<)
};

/*
	>>:
*/

struct right_shift
{
	unroll_no_return_2(right_shift, DIRECTION, >>)
	unroll_with_return_2(right_shift, DIRECTION, >>)
};

/*
	==:
*/

struct equals
{
	unroll_no_return_2(equals, DIRECTION, ==)
	unroll_with_return_2(equals, DIRECTION, ==)
};

/*
	!=:
*/

struct not_equals
{
	unroll_no_return_2(not_equals, DIRECTION, !=)
	unroll_with_return_2(not_equals, DIRECTION, !=)
};

/*
	<=:
*/

struct less_than_or_equal
{
	unroll_no_return_2(less_than_or_equal, DIRECTION, <=)
	unroll_with_return_2(less_than_or_equal, DIRECTION, <=)
};

/*
	>=:
*/

struct greater_than_or_equal
{
	unroll_no_return_2(greater_than_or_equal, DIRECTION, >=)
	unroll_with_return_2(greater_than_or_equal, DIRECTION, >=)
};

/*
	&&:
*/

struct logical_and
{
	unroll_no_return_2(logical_and, DIRECTION, &&)
	unroll_with_return_2(logical_and, DIRECTION, &&)
};

/*
	||:
*/

struct logical_or
{
	unroll_no_return_2(logical_or, DIRECTION, ||)
	unroll_with_return_2(logical_or, DIRECTION, ||)
};

/*
	++:
*/

struct left_increment
{
	unroll_no_return_left_0(left_increment, DIRECTION, ++)
};

struct right_increment
{
	unroll_no_return_right_0(right_increment, DIRECTION, ++)
};

/*
	--:
*/

struct left_decrement
{
	unroll_no_return_left_0(left_decrement, DIRECTION, --)
};

struct right_decrement
{
	unroll_no_return_right_0(right_decrement, DIRECTION, --)
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
	unroll_no_return_2(point_asterisk, DIRECTION, ->*)
	unroll_with_return_2(point_asterisk, DIRECTION, ->*)
};

/*
	->:
*/

struct point
{
	unroll_with_return_2(point, DIRECTION, .operator->)
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	unroll_no_return_right_0(parentheses, DIRECTION, ())

	unroll_no_return_right_1(parentheses, DIRECTION, =, ())
	unroll_with_return_right_1(parentheses, DIRECTION, =, ())

	unroll_no_return_2(parentheses, DIRECTION, )
	unroll_with_return_2(parentheses, DIRECTION, )
};

/*
	[]:
*/

struct brackets
{
	unroll_no_return_bracket_2(brackets, DIRECTION, )
	unroll_with_return_bracket_2(brackets, DIRECTION, )
};

/*
	=:
*/

struct repeat
{
	unroll_no_return_0(repeat, DIRECTION, =)
	// There's no need for a "return" version as the out iterator equals the end iterator upon halting.
/*
	+=:
*/
	struct plus
	{
		unroll_no_return_0(plus, DIRECTION, +=)
	};
/*
	-=:
*/
	struct minus
	{
		unroll_no_return_0(minus, DIRECTION, -=)
	};
/*
	*=:
*/
	struct asterisk
	{
		unroll_no_return_0(asterisk, DIRECTION, *=)
	};
/*
	/=:
*/
	struct slash
	{
		unroll_no_return_0(slash, DIRECTION, /=)
	};
/*
	%=:
*/
	struct percent
	{
		unroll_no_return_0(percent, DIRECTION, %=)
	};
/*
	ˆ=:
*/
	struct caret
	{
		unroll_no_return_0(caret, DIRECTION, ^=)
	};
/*
	&=:
*/
	struct ampersand
	{
		unroll_no_return_0(ampersand, DIRECTION, &=)
	};
/*
	|=:
*/
	struct bar
	{
		unroll_no_return_0(bar, DIRECTION, |=)
	};
/*
	>>=:
*/
	struct right_shift
	{
		unroll_no_return_0(right_shift, DIRECTION, >>=)
	};
/*
	<<=:
*/
	struct left_shift
	{
		unroll_no_return_0(left_shift, DIRECTION, <<=)
	};
};

/*
	=:
*/

struct assign
{
	unroll_no_return_1(assign, DIRECTION, =)
	unroll_with_return_1(assign, DIRECTION, =)
/*
	+=:
*/
	struct plus
	{
		unroll_no_return_1(plus, DIRECTION, +=)
		unroll_with_return_1(plus, DIRECTION, +=)
	};
/*
	-=:
*/
	struct minus
	{
		unroll_no_return_1(minus, DIRECTION, -=)
		unroll_with_return_1(minus, DIRECTION, -=)
	};
/*
	*=:
*/
	struct asterisk
	{
		unroll_no_return_1(asterisk, DIRECTION, *=)
		unroll_with_return_1(asterisk, DIRECTION, *=)
	};
/*
	/=:
*/
	struct slash
	{
		unroll_no_return_1(slash, DIRECTION, /=)
		unroll_with_return_1(slash, DIRECTION, /=)
	};
/*
	%=:
*/
	struct percent
	{
		unroll_no_return_1(percent, DIRECTION, %=)
		unroll_with_return_1(percent, DIRECTION, %=)
	};
/*
	ˆ=:
*/
	struct caret
	{
		unroll_no_return_1(caret, DIRECTION, ^=)
		unroll_with_return_1(caret, DIRECTION, ^=)
	};
/*
	&=:
*/
	struct ampersand
	{
		unroll_no_return_1(ampersand, DIRECTION, &=)
		unroll_with_return_1(ampersand, DIRECTION, &=)
	};
/*
	|=:
*/
	struct bar
	{
		unroll_no_return_1(bar, DIRECTION, |=)
		unroll_with_return_1(bar, DIRECTION, |=)
	};
/*
	>>=:
*/
	struct right_shift
	{
		unroll_no_return_1(right_shift, DIRECTION, >>=)
		unroll_with_return_1(right_shift, DIRECTION, >>=)
	};
/*
	<<=:
*/
	struct left_shift
	{
		unroll_no_return_1(left_shift, DIRECTION, <<=)
		unroll_with_return_1(left_shift, DIRECTION, <<=)
	};
};

