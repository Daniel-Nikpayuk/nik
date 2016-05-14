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

	overload: 40 operators referenced from: http://en.cppreference.com/w/cpp/language/operators

	Notice "closing" is the assumed default policy.
*/

/*
	+:

	"=+" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct plus
{
	closing_unroll_no_return_1(plus, SGN, INV, =+)
	closing_unroll_with_return_1(plus, SGN, INV, =+)

	closing_unroll_no_return_2(plus, SGN, INV, +)
	closing_unroll_with_return_2(plus, SGN, INV, +)

	struct closed
	{
		closed_unroll_no_return_1(plus, SGN, INV, =+)
		closed_unroll_with_return_1(plus, SGN, INV, =+)

		closed_unroll_no_return_2(plus, SGN, INV, +)
		closed_unroll_with_return_2(plus, SGN, INV, +)
	};

	struct opening
	{
		opening_unroll_no_return_1(plus, SGN, INV, =+)
		opening_unroll_with_return_1(plus, SGN, INV, =+)

		opening_unroll_no_return_2(plus, SGN, INV, +)
		opening_unroll_with_return_2(plus, SGN, INV, +)
	};

	struct open
	{
		open_unroll_no_return_1(plus, SGN, INV, =+)
		open_unroll_with_return_1(plus, SGN, INV, =+)

		open_unroll_no_return_2(plus, SGN, INV, +)
		open_unroll_with_return_2(plus, SGN, INV, +)
	};
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	closing_unroll_no_return_1(minus, SGN, INV, =-)
	closing_unroll_with_return_1(minus, SGN, INV, =-)

	closing_unroll_no_return_2(minus, SGN, INV, -)
	closing_unroll_with_return_2(minus, SGN, INV, -)

	struct closed
	{
		closed_unroll_no_return_1(minus, SGN, INV, =-)
		closed_unroll_with_return_1(minus, SGN, INV, =-)

		closed_unroll_no_return_2(minus, SGN, INV, -)
		closed_unroll_with_return_2(minus, SGN, INV, -)
	};

	struct opening
	{
		opening_unroll_no_return_1(minus, SGN, INV, =-)
		opening_unroll_with_return_1(minus, SGN, INV, =-)

		opening_unroll_no_return_2(minus, SGN, INV, -)
		opening_unroll_with_return_2(minus, SGN, INV, -)
	};

	struct open
	{
		open_unroll_no_return_1(minus, SGN, INV, =-)
		open_unroll_with_return_1(minus, SGN, INV, =-)

		open_unroll_no_return_2(minus, SGN, INV, -)
		open_unroll_with_return_2(minus, SGN, INV, -)
	};
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	closing_unroll_no_return_1(asterisk, SGN, INV, =*)
	closing_unroll_with_return_1(asterisk, SGN, INV, =*)

	closing_unroll_no_return_2(asterisk, SGN, INV, *)
	closing_unroll_with_return_2(asterisk, SGN, INV, *)

	struct closed
	{
		closed_unroll_no_return_1(asterisk, SGN, INV, =*)
		closed_unroll_with_return_1(asterisk, SGN, INV, =*)

		closed_unroll_no_return_2(asterisk, SGN, INV, *)
		closed_unroll_with_return_2(asterisk, SGN, INV, *)
	};

	struct opening
	{
		opening_unroll_no_return_1(asterisk, SGN, INV, =*)
		opening_unroll_with_return_1(asterisk, SGN, INV, =*)

		opening_unroll_no_return_2(asterisk, SGN, INV, *)
		opening_unroll_with_return_2(asterisk, SGN, INV, *)
	};

	struct open
	{
		open_unroll_no_return_1(asterisk, SGN, INV, =*)
		open_unroll_with_return_1(asterisk, SGN, INV, =*)

		open_unroll_no_return_2(asterisk, SGN, INV, *)
		open_unroll_with_return_2(asterisk, SGN, INV, *)
	};
};

/*
	/:
*/

struct slash
{
	closing_unroll_no_return_2(slash, SGN, INV, /)
	closing_unroll_with_return_2(slash, SGN, INV, /)

	struct closed
	{
		closed_unroll_no_return_2(slash, SGN, INV, /)
		closed_unroll_with_return_2(slash, SGN, INV, /)
	};

	struct opening
	{
		opening_unroll_no_return_2(slash, SGN, INV, /)
		opening_unroll_with_return_2(slash, SGN, INV, /)
	};

	struct open
	{
		open_unroll_no_return_2(slash, SGN, INV, /)
		open_unroll_with_return_2(slash, SGN, INV, /)
	};
};

/*
	%:
*/

struct percent
{
	closing_unroll_no_return_2(percent, SGN, INV, %)
	closing_unroll_with_return_2(percent, SGN, INV, %)

	struct closed
	{
		closed_unroll_no_return_2(percent, SGN, INV, %)
		closed_unroll_with_return_2(percent, SGN, INV, %)
	};

	struct opening
	{
		opening_unroll_no_return_2(percent, SGN, INV, %)
		opening_unroll_with_return_2(percent, SGN, INV, %)
	};

	struct open
	{
		open_unroll_no_return_2(percent, SGN, INV, %)
		open_unroll_with_return_2(percent, SGN, INV, %)
	};
};

/*
	ˆ:
*/

struct caret
{
	closing_unroll_no_return_2(caret, SGN, INV, ^)
	closing_unroll_with_return_2(caret, SGN, INV, ^)

	struct closed
	{
		closed_unroll_no_return_2(caret, SGN, INV, ^)
		closed_unroll_with_return_2(caret, SGN, INV, ^)
	};

	struct opening
	{
		opening_unroll_no_return_2(caret, SGN, INV, ^)
		opening_unroll_with_return_2(caret, SGN, INV, ^)
	};

	struct open
	{
		open_unroll_no_return_2(caret, SGN, INV, ^)
		open_unroll_with_return_2(caret, SGN, INV, ^)
	};
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	closing_unroll_no_return_1(ampersand, SGN, INV, =&)
	closing_unroll_with_return_1(ampersand, SGN, INV, =&)

	closing_unroll_no_return_2(ampersand, SGN, INV, &)
	closing_unroll_with_return_2(ampersand, SGN, INV, &)

	struct closed
	{
		closed_unroll_no_return_1(ampersand, SGN, INV, =&)
		closed_unroll_with_return_1(ampersand, SGN, INV, =&)

		closed_unroll_no_return_2(ampersand, SGN, INV, &)
		closed_unroll_with_return_2(ampersand, SGN, INV, &)
	};

	struct opening
	{
		opening_unroll_no_return_1(ampersand, SGN, INV, =&)
		opening_unroll_with_return_1(ampersand, SGN, INV, =&)

		opening_unroll_no_return_2(ampersand, SGN, INV, &)
		opening_unroll_with_return_2(ampersand, SGN, INV, &)
	};

	struct open
	{
		open_unroll_no_return_1(ampersand, SGN, INV, =&)
		open_unroll_with_return_1(ampersand, SGN, INV, =&)

		open_unroll_no_return_2(ampersand, SGN, INV, &)
		open_unroll_with_return_2(ampersand, SGN, INV, &)
	};
};

/*
	|:
*/

struct bar
{
	closing_unroll_no_return_2(bar, SGN, INV, |)
	closing_unroll_with_return_2(bar, SGN, INV, |)

	struct closed
	{
		closed_unroll_no_return_2(bar, SGN, INV, |)
		closed_unroll_with_return_2(bar, SGN, INV, |)
	};

	struct opening
	{
		opening_unroll_no_return_2(bar, SGN, INV, |)
		opening_unroll_with_return_2(bar, SGN, INV, |)
	};

	struct open
	{
		open_unroll_no_return_2(bar, SGN, INV, |)
		open_unroll_with_return_2(bar, SGN, INV, |)
	};
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	closing_unroll_no_return_1(tilde, SGN, INV, =~)
	closing_unroll_with_return_1(tilde, SGN, INV, =~)

	struct closed
	{
		closed_unroll_no_return_1(tilde, SGN, INV, =~)
		closed_unroll_with_return_1(tilde, SGN, INV, =~)
	};

	struct opening
	{
		opening_unroll_no_return_1(tilde, SGN, INV, =~)
		opening_unroll_with_return_1(tilde, SGN, INV, =~)
	};

	struct open
	{
		open_unroll_no_return_1(tilde, SGN, INV, =~)
		open_unroll_with_return_1(tilde, SGN, INV, =~)
	};
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	closing_unroll_no_return_1(exclamation, SGN, INV, =!)
	closing_unroll_with_return_1(exclamation, SGN, INV, =!)

	struct closed
	{
		closed_unroll_no_return_1(exclamation, SGN, INV, =!)
		closed_unroll_with_return_1(exclamation, SGN, INV, =!)
	};

	struct opening
	{
		opening_unroll_no_return_1(exclamation, SGN, INV, =!)
		opening_unroll_with_return_1(exclamation, SGN, INV, =!)
	};

	struct open
	{
		open_unroll_no_return_1(exclamation, SGN, INV, =!)
		open_unroll_with_return_1(exclamation, SGN, INV, =!)
	};
};

/*
	<:
*/

struct less_than
{
	closing_unroll_no_return_2(less_than, SGN, INV, <)
	closing_unroll_with_return_2(less_than, SGN, INV, <)

	struct closed
	{
		closed_unroll_no_return_2(less_than, SGN, INV, <)
		closed_unroll_with_return_2(less_than, SGN, INV, <)
	};

	struct opening
	{
		opening_unroll_no_return_2(less_than, SGN, INV, <)
		opening_unroll_with_return_2(less_than, SGN, INV, <)
	};

	struct open
	{
		open_unroll_no_return_2(less_than, SGN, INV, <)
		open_unroll_with_return_2(less_than, SGN, INV, <)
	};
};

/*
	>:
*/

struct greater_than
{
	closing_unroll_no_return_2(greater_than, SGN, INV, >)
	closing_unroll_with_return_2(greater_than, SGN, INV, >)

	struct closed
	{
		closed_unroll_no_return_2(greater_than, SGN, INV, >)
		closed_unroll_with_return_2(greater_than, SGN, INV, >)
	};

	struct opening
	{
		opening_unroll_no_return_2(greater_than, SGN, INV, >)
		opening_unroll_with_return_2(greater_than, SGN, INV, >)
	};

	struct open
	{
		open_unroll_no_return_2(greater_than, SGN, INV, >)
		open_unroll_with_return_2(greater_than, SGN, INV, >)
	};
};

/*
	<<:
*/

struct left_shift
{
	closing_unroll_no_return_2(left_shift, SGN, INV, <<)
	closing_unroll_with_return_2(left_shift, SGN, INV, <<)

	struct closed
	{
		closed_unroll_no_return_2(left_shift, SGN, INV, <<)
		closed_unroll_with_return_2(left_shift, SGN, INV, <<)
	};

	struct opening
	{
		opening_unroll_no_return_2(left_shift, SGN, INV, <<)
		opening_unroll_with_return_2(left_shift, SGN, INV, <<)
	};

	struct open
	{
		open_unroll_no_return_2(left_shift, SGN, INV, <<)
		open_unroll_with_return_2(left_shift, SGN, INV, <<)
	};
};

/*
	>>:
*/

struct right_shift
{
	closing_unroll_no_return_2(right_shift, SGN, INV, >>)
	closing_unroll_with_return_2(right_shift, SGN, INV, >>)

	struct closed
	{
		closed_unroll_no_return_2(right_shift, SGN, INV, >>)
		closed_unroll_with_return_2(right_shift, SGN, INV, >>)
	};

	struct opening
	{
		opening_unroll_no_return_2(right_shift, SGN, INV, >>)
		opening_unroll_with_return_2(right_shift, SGN, INV, >>)
	};

	struct open
	{
		open_unroll_no_return_2(right_shift, SGN, INV, >>)
		open_unroll_with_return_2(right_shift, SGN, INV, >>)
	};
};

/*
	==:
*/

struct equals
{
	closing_unroll_no_return_2(equals, SGN, INV, ==)
	closing_unroll_with_return_2(equals, SGN, INV, ==)

	struct closed
	{
		closed_unroll_no_return_2(equals, SGN, INV, ==)
		closed_unroll_with_return_2(equals, SGN, INV, ==)
	};

	struct opening
	{
		opening_unroll_no_return_2(equals, SGN, INV, ==)
		opening_unroll_with_return_2(equals, SGN, INV, ==)
	};

	struct open
	{
		open_unroll_no_return_2(equals, SGN, INV, ==)
		open_unroll_with_return_2(equals, SGN, INV, ==)
	};
};

/*
	!=:
*/

struct not_equals
{
	closing_unroll_no_return_2(not_equals, SGN, INV, !=)
	closing_unroll_with_return_2(not_equals, SGN, INV, !=)

	struct closed
	{
		closed_unroll_no_return_2(not_equals, SGN, INV, !=)
		closed_unroll_with_return_2(not_equals, SGN, INV, !=)
	};

	struct opening
	{
		opening_unroll_no_return_2(not_equals, SGN, INV, !=)
		opening_unroll_with_return_2(not_equals, SGN, INV, !=)
	};

	struct open
	{
		open_unroll_no_return_2(not_equals, SGN, INV, !=)
		open_unroll_with_return_2(not_equals, SGN, INV, !=)
	};
};

/*
	<=:
*/

struct less_than_or_equal
{
	closing_unroll_no_return_2(less_than_or_equal, SGN, INV, <=)
	closing_unroll_with_return_2(less_than_or_equal, SGN, INV, <=)

	struct closed
	{
		closed_unroll_no_return_2(less_than_or_equal, SGN, INV, <=)
		closed_unroll_with_return_2(less_than_or_equal, SGN, INV, <=)
	};

	struct opening
	{
		opening_unroll_no_return_2(less_than_or_equal, SGN, INV, <=)
		opening_unroll_with_return_2(less_than_or_equal, SGN, INV, <=)
	};

	struct open
	{
		open_unroll_no_return_2(less_than_or_equal, SGN, INV, <=)
		open_unroll_with_return_2(less_than_or_equal, SGN, INV, <=)
	};
};

/*
	>=:
*/

struct greater_than_or_equal
{
	closing_unroll_no_return_2(greater_than_or_equal, SGN, INV, >=)
	closing_unroll_with_return_2(greater_than_or_equal, SGN, INV, >=)

	struct closed
	{
		closed_unroll_no_return_2(greater_than_or_equal, SGN, INV, >=)
		closed_unroll_with_return_2(greater_than_or_equal, SGN, INV, >=)
	};

	struct opening
	{
		opening_unroll_no_return_2(greater_than_or_equal, SGN, INV, >=)
		opening_unroll_with_return_2(greater_than_or_equal, SGN, INV, >=)
	};

	struct open
	{
		open_unroll_no_return_2(greater_than_or_equal, SGN, INV, >=)
		open_unroll_with_return_2(greater_than_or_equal, SGN, INV, >=)
	};
};

/*
	&&:
*/

struct logical_and
{
	closing_unroll_no_return_2(logical_and, SGN, INV, &&)
	closing_unroll_with_return_2(logical_and, SGN, INV, &&)

	struct closed
	{
		closed_unroll_no_return_2(logical_and, SGN, INV, &&)
		closed_unroll_with_return_2(logical_and, SGN, INV, &&)
	};

	struct opening
	{
		opening_unroll_no_return_2(logical_and, SGN, INV, &&)
		opening_unroll_with_return_2(logical_and, SGN, INV, &&)
	};

	struct open
	{
		open_unroll_no_return_2(logical_and, SGN, INV, &&)
		open_unroll_with_return_2(logical_and, SGN, INV, &&)
	};
};

/*
	||:
*/

struct logical_or
{
	closing_unroll_no_return_2(logical_or, SGN, INV, ||)
	closing_unroll_with_return_2(logical_or, SGN, INV, ||)

	struct closed
	{
		closed_unroll_no_return_2(logical_or, SGN, INV, ||)
		closed_unroll_with_return_2(logical_or, SGN, INV, ||)
	};

	struct opening
	{
		opening_unroll_no_return_2(logical_or, SGN, INV, ||)
		opening_unroll_with_return_2(logical_or, SGN, INV, ||)
	};

	struct open
	{
		open_unroll_no_return_2(logical_or, SGN, INV, ||)
		open_unroll_with_return_2(logical_or, SGN, INV, ||)
	};
};

/*
	++:
*/

struct left_increment
{
	closing_unroll_no_return_left_0(left_increment, SGN, INV, ++)

	struct closed
	{
		closed_unroll_no_return_left_0(left_increment, SGN, INV, ++)
	};

	struct opening
	{
		opening_unroll_no_return_left_0(left_increment, SGN, INV, ++)
	};

	struct open
	{
		open_unroll_no_return_left_0(left_increment, SGN, INV, ++)
	};
};

struct right_increment
{
	closing_unroll_no_return_right_0(right_increment, SGN, INV, ++)

	struct closed
	{
		closed_unroll_no_return_right_0(right_increment, SGN, INV, ++)
	};

	struct opening
	{
		opening_unroll_no_return_right_0(right_increment, SGN, INV, ++)
	};

	struct open
	{
		open_unroll_no_return_right_0(right_increment, SGN, INV, ++)
	};
};

/*
	--:
*/

struct left_decrement
{
	closing_unroll_no_return_left_0(left_decrement, SGN, INV, --)

	struct closed
	{
		closed_unroll_no_return_left_0(left_decrement, SGN, INV, --)
	};

	struct opening
	{
		opening_unroll_no_return_left_0(left_decrement, SGN, INV, --)
	};

	struct open
	{
		open_unroll_no_return_left_0(left_decrement, SGN, INV, --)
	};
};

struct right_decrement
{
	closing_unroll_no_return_right_0(right_decrement, SGN, INV, --)

	struct closed
	{
		closed_unroll_no_return_right_0(right_decrement, SGN, INV, --)
	};

	struct opening
	{
		opening_unroll_no_return_right_0(right_decrement, SGN, INV, --)
	};

	struct open
	{
		open_unroll_no_return_right_0(right_decrement, SGN, INV, --)
	};
};

/*
	,:
*/

struct comma
{
	struct closed
	{
	};

	struct opening
	{
	};

	struct open
	{
	};
};

/*
	->*:
*/

struct point_asterisk
{
	closing_unroll_no_return_2(point_asterisk, SGN, INV, ->*)
	closing_unroll_with_return_2(point_asterisk, SGN, INV, ->*)

	struct closed
	{
		closed_unroll_no_return_2(point_asterisk, SGN, INV, ->*)
		closed_unroll_with_return_2(point_asterisk, SGN, INV, ->*)
	};

	struct opening
	{
		opening_unroll_no_return_2(point_asterisk, SGN, INV, ->*)
		opening_unroll_with_return_2(point_asterisk, SGN, INV, ->*)
	};

	struct open
	{
		open_unroll_no_return_2(point_asterisk, SGN, INV, ->*)
		open_unroll_with_return_2(point_asterisk, SGN, INV, ->*)
	};
};

/*
	->:
*/

struct point
{
	closing_unroll_with_return_2(point, SGN, INV, .operator->)

	struct closed
	{
		closed_unroll_with_return_2(point, SGN, INV, .operator->)
	};

	struct opening
	{
		opening_unroll_with_return_2(point, SGN, INV, .operator->)
	};

	struct open
	{
		open_unroll_with_return_2(point, SGN, INV, .operator->)
	};
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	closing_unroll_no_return_right_0(parentheses, SGN, INV, ())

	closing_unroll_no_return_right_1(parentheses, SGN, INV, =, ())
	closing_unroll_with_return_right_1(parentheses, SGN, INV, =, ())

	closing_unroll_no_return_2(parentheses, SGN, INV, )
	closing_unroll_with_return_2(parentheses, SGN, INV, )

	struct closed
	{
		closed_unroll_no_return_right_0(parentheses, SGN, INV, ())

		closed_unroll_no_return_right_1(parentheses, SGN, INV, =, ())
		closed_unroll_with_return_right_1(parentheses, SGN, INV, =, ())

		closed_unroll_no_return_2(parentheses, SGN, INV, )
		closed_unroll_with_return_2(parentheses, SGN, INV, )
	};

	struct opening
	{
		opening_unroll_no_return_right_0(parentheses, SGN, INV, ())

		opening_unroll_no_return_right_1(parentheses, SGN, INV, =, ())
		opening_unroll_with_return_right_1(parentheses, SGN, INV, =, ())

		opening_unroll_no_return_2(parentheses, SGN, INV, )
		opening_unroll_with_return_2(parentheses, SGN, INV, )
	};

	struct open
	{
		open_unroll_no_return_right_0(parentheses, SGN, INV, ())

		open_unroll_no_return_right_1(parentheses, SGN, INV, =, ())
		open_unroll_with_return_right_1(parentheses, SGN, INV, =, ())

		open_unroll_no_return_2(parentheses, SGN, INV, )
		open_unroll_with_return_2(parentheses, SGN, INV, )
	};
};

/*
	[]:
*/

struct brackets
{
	closing_unroll_no_return_brackets_2(brackets, SGN, INV, )
	closing_unroll_with_return_brackets_2(brackets, SGN, INV, )

	struct closed
	{
		closed_unroll_no_return_brackets_2(brackets, SGN, INV, )
		closed_unroll_with_return_brackets_2(brackets, SGN, INV, )
	};

	struct opening
	{
		opening_unroll_no_return_brackets_2(brackets, SGN, INV, )
		opening_unroll_with_return_brackets_2(brackets, SGN, INV, )
	};

	struct open
	{
		open_unroll_no_return_brackets_2(brackets, SGN, INV, )
		open_unroll_with_return_brackets_2(brackets, SGN, INV, )
	};
};

/*
	=:
*/

struct repeat
{
	closing_unroll_no_return_0(repeat, SGN, INV, =)
	closing_unroll_with_return_0(repeat, SGN, INV, =)

	struct closed
	{
		closed_unroll_no_return_0(repeat, SGN, INV, =)
		closed_unroll_with_return_0(repeat, SGN, INV, =)
	};

	struct opening
	{
		opening_unroll_no_return_0(repeat, SGN, INV, =)
		opening_unroll_with_return_0(repeat, SGN, INV, =)
	};

	struct open
	{
		open_unroll_no_return_0(repeat, SGN, INV, =)
		open_unroll_with_return_0(repeat, SGN, INV, =)
	};
/*
	+=:
*/
	struct plus
	{
		closing_unroll_no_return_0(plus, SGN, INV, +=)

		struct closed
		{
			closed_unroll_no_return_0(plus, SGN, INV, +=)
		};

		struct opening
		{
			opening_unroll_no_return_0(plus, SGN, INV, +=)
		};

		struct open
		{
			open_unroll_no_return_0(plus, SGN, INV, +=)
		};
	};
/*
	-=:
*/
	struct minus
	{
		closing_unroll_no_return_0(minus, SGN, INV, -=)

		struct closed
		{
			closed_unroll_no_return_0(minus, SGN, INV, -=)
		};

		struct opening
		{
			opening_unroll_no_return_0(minus, SGN, INV, -=)
		};

		struct open
		{
			open_unroll_no_return_0(minus, SGN, INV, -=)
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		closing_unroll_no_return_0(asterisk, SGN, INV, *=)

		struct closed
		{
			closed_unroll_no_return_0(asterisk, SGN, INV, *=)
		};

		struct opening
		{
			opening_unroll_no_return_0(asterisk, SGN, INV, *=)
		};

		struct open
		{
			open_unroll_no_return_0(asterisk, SGN, INV, *=)
		};
	};
/*
	/=:
*/
	struct slash
	{
		closing_unroll_no_return_0(slash, SGN, INV, /=)

		struct closed
		{
			closed_unroll_no_return_0(slash, SGN, INV, /=)
		};

		struct opening
		{
			opening_unroll_no_return_0(slash, SGN, INV, /=)
		};

		struct open
		{
			open_unroll_no_return_0(slash, SGN, INV, /=)
		};
	};
/*
	%=:
*/
	struct percent
	{
		closing_unroll_no_return_0(percent, SGN, INV, %=)

		struct closed
		{
			closed_unroll_no_return_0(percent, SGN, INV, %=)
		};

		struct opening
		{
			opening_unroll_no_return_0(percent, SGN, INV, %=)
		};

		struct open
		{
			open_unroll_no_return_0(percent, SGN, INV, %=)
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		closing_unroll_no_return_0(caret, SGN, INV, ^=)

		struct closed
		{
			closed_unroll_no_return_0(caret, SGN, INV, ^=)
		};

		struct opening
		{
			opening_unroll_no_return_0(caret, SGN, INV, ^=)
		};

		struct open
		{
			open_unroll_no_return_0(caret, SGN, INV, ^=)
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		closing_unroll_no_return_0(ampersand, SGN, INV, &=)

		struct closed
		{
			closed_unroll_no_return_0(ampersand, SGN, INV, &=)
		};

		struct opening
		{
			opening_unroll_no_return_0(ampersand, SGN, INV, &=)
		};

		struct open
		{
			open_unroll_no_return_0(ampersand, SGN, INV, &=)
		};
	};
/*
	|=:
*/
	struct bar
	{
		closing_unroll_no_return_0(bar, SGN, INV, |=)

		struct closed
		{
			closed_unroll_no_return_0(bar, SGN, INV, |=)
		};

		struct opening
		{
			opening_unroll_no_return_0(bar, SGN, INV, |=)
		};

		struct open
		{
			open_unroll_no_return_0(bar, SGN, INV, |=)
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		closing_unroll_no_return_0(right_shift, SGN, INV, >>=)

		struct closed
		{
			closed_unroll_no_return_0(right_shift, SGN, INV, >>=)
		};

		struct opening
		{
			opening_unroll_no_return_0(right_shift, SGN, INV, >>=)
		};

		struct open
		{
			open_unroll_no_return_0(right_shift, SGN, INV, >>=)
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		closing_unroll_no_return_0(left_shift, SGN, INV, <<=)

		struct closed
		{
			closed_unroll_no_return_0(left_shift, SGN, INV, <<=)
		};

		struct opening
		{
			opening_unroll_no_return_0(left_shift, SGN, INV, <<=)
		};

		struct open
		{
			open_unroll_no_return_0(left_shift, SGN, INV, <<=)
		};
	};
};

/*
	=:
*/

struct assign
{
	closing_unroll_no_return_1(assign, SGN, INV, =)
	closing_unroll_with_return_1(assign, SGN, INV, =)

	struct closed
	{
		closed_unroll_no_return_1(assign, SGN, INV, =)
		closed_unroll_with_return_1(assign, SGN, INV, =)
	};

	struct opening
	{
		opening_unroll_no_return_1(assign, SGN, INV, =)
		opening_unroll_with_return_1(assign, SGN, INV, =)
	};

	struct open
	{
		open_unroll_no_return_1(assign, SGN, INV, =)
		open_unroll_with_return_1(assign, SGN, INV, =)
	};
/*
	+=:
*/
	struct plus
	{
		closing_unroll_no_return_1(plus, SGN, INV, +=)
		closing_unroll_with_return_1(plus, SGN, INV, +=)

		struct closed
		{
			closed_unroll_no_return_1(plus, SGN, INV, +=)
			closed_unroll_with_return_1(plus, SGN, INV, +=)
		};

		struct opening
		{
			opening_unroll_no_return_1(plus, SGN, INV, +=)
			opening_unroll_with_return_1(plus, SGN, INV, +=)
		};

		struct open
		{
			open_unroll_no_return_1(plus, SGN, INV, +=)
			open_unroll_with_return_1(plus, SGN, INV, +=)
		};
	};
/*
	-=:
*/
	struct minus
	{
		closing_unroll_no_return_1(minus, SGN, INV, -=)
		closing_unroll_with_return_1(minus, SGN, INV, -=)

		struct closed
		{
			closed_unroll_no_return_1(minus, SGN, INV, -=)
			closed_unroll_with_return_1(minus, SGN, INV, -=)
		};

		struct opening
		{
			opening_unroll_no_return_1(minus, SGN, INV, -=)
			opening_unroll_with_return_1(minus, SGN, INV, -=)
		};

		struct open
		{
			open_unroll_no_return_1(minus, SGN, INV, -=)
			open_unroll_with_return_1(minus, SGN, INV, -=)
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		closing_unroll_no_return_1(asterisk, SGN, INV, *=)
		closing_unroll_with_return_1(asterisk, SGN, INV, *=)

		struct closed
		{
			closed_unroll_no_return_1(asterisk, SGN, INV, *=)
			closed_unroll_with_return_1(asterisk, SGN, INV, *=)
		};

		struct opening
		{
			opening_unroll_no_return_1(asterisk, SGN, INV, *=)
			opening_unroll_with_return_1(asterisk, SGN, INV, *=)
		};

		struct open
		{
			open_unroll_no_return_1(asterisk, SGN, INV, *=)
			open_unroll_with_return_1(asterisk, SGN, INV, *=)
		};
	};
/*
	/=:
*/
	struct slash
	{
		closing_unroll_no_return_1(slash, SGN, INV, /=)
		closing_unroll_with_return_1(slash, SGN, INV, /=)

		struct closed
		{
			closed_unroll_no_return_1(slash, SGN, INV, /=)
			closed_unroll_with_return_1(slash, SGN, INV, /=)
		};

		struct opening
		{
			opening_unroll_no_return_1(slash, SGN, INV, /=)
			opening_unroll_with_return_1(slash, SGN, INV, /=)
		};

		struct open
		{
			open_unroll_no_return_1(slash, SGN, INV, /=)
			open_unroll_with_return_1(slash, SGN, INV, /=)
		};
	};
/*
	%=:
*/
	struct percent
	{
		closing_unroll_no_return_1(percent, SGN, INV, %=)
		closing_unroll_with_return_1(percent, SGN, INV, %=)

		struct closed
		{
			closed_unroll_no_return_1(percent, SGN, INV, %=)
			closed_unroll_with_return_1(percent, SGN, INV, %=)
		};

		struct opening
		{
			opening_unroll_no_return_1(percent, SGN, INV, %=)
			opening_unroll_with_return_1(percent, SGN, INV, %=)
		};

		struct open
		{
			open_unroll_no_return_1(percent, SGN, INV, %=)
			open_unroll_with_return_1(percent, SGN, INV, %=)
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		closing_unroll_no_return_1(caret, SGN, INV, ^=)
		closing_unroll_with_return_1(caret, SGN, INV, ^=)

		struct closed
		{
			closed_unroll_no_return_1(caret, SGN, INV, ^=)
			closed_unroll_with_return_1(caret, SGN, INV, ^=)
		};

		struct opening
		{
			opening_unroll_no_return_1(caret, SGN, INV, ^=)
			opening_unroll_with_return_1(caret, SGN, INV, ^=)
		};

		struct open
		{
			open_unroll_no_return_1(caret, SGN, INV, ^=)
			open_unroll_with_return_1(caret, SGN, INV, ^=)
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		closing_unroll_no_return_1(ampersand, SGN, INV, &=)
		closing_unroll_with_return_1(ampersand, SGN, INV, &=)

		struct closed
		{
			closed_unroll_no_return_1(ampersand, SGN, INV, &=)
			closed_unroll_with_return_1(ampersand, SGN, INV, &=)
		};

		struct opening
		{
			opening_unroll_no_return_1(ampersand, SGN, INV, &=)
			opening_unroll_with_return_1(ampersand, SGN, INV, &=)
		};

		struct open
		{
			open_unroll_no_return_1(ampersand, SGN, INV, &=)
			open_unroll_with_return_1(ampersand, SGN, INV, &=)
		};
	};
/*
	|=:
*/
	struct bar
	{
		closing_unroll_no_return_1(bar, SGN, INV, |=)
		closing_unroll_with_return_1(bar, SGN, INV, |=)

		struct closed
		{
			closed_unroll_no_return_1(bar, SGN, INV, |=)
			closed_unroll_with_return_1(bar, SGN, INV, |=)
		};

		struct opening
		{
			opening_unroll_no_return_1(bar, SGN, INV, |=)
			opening_unroll_with_return_1(bar, SGN, INV, |=)
		};

		struct open
		{
			open_unroll_no_return_1(bar, SGN, INV, |=)
			open_unroll_with_return_1(bar, SGN, INV, |=)
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		closing_unroll_no_return_1(right_shift, SGN, INV, >>=)
		closing_unroll_with_return_1(right_shift, SGN, INV, >>=)

		struct closed
		{
			closed_unroll_no_return_1(right_shift, SGN, INV, >>=)
			closed_unroll_with_return_1(right_shift, SGN, INV, >>=)
		};

		struct opening
		{
			opening_unroll_no_return_1(right_shift, SGN, INV, >>=)
			opening_unroll_with_return_1(right_shift, SGN, INV, >>=)
		};

		struct open
		{
			open_unroll_no_return_1(right_shift, SGN, INV, >>=)
			open_unroll_with_return_1(right_shift, SGN, INV, >>=)
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		closing_unroll_no_return_1(left_shift, SGN, INV, <<=)
		closing_unroll_with_return_1(left_shift, SGN, INV, <<=)

		struct closed
		{
			closed_unroll_no_return_1(left_shift, SGN, INV, <<=)
			closed_unroll_with_return_1(left_shift, SGN, INV, <<=)
		};

		struct opening
		{
			opening_unroll_no_return_1(left_shift, SGN, INV, <<=)
			opening_unroll_with_return_1(left_shift, SGN, INV, <<=)
		};

		struct open
		{
			open_unroll_no_return_1(left_shift, SGN, INV, <<=)
			open_unroll_with_return_1(left_shift, SGN, INV, <<=)
		};
	};
};

struct allocate
{
	closing_unroll_no_return_new_0(allocate, SGN, INV)
	closing_unroll_with_return_new_0(allocate, SGN, INV)

	struct brackets
	{
		closing_unroll_no_return_new_brackets_0(allocate, SGN, INV)
		closing_unroll_with_return_new_brackets_0(allocate, SGN, INV)

		closing_unroll_no_return_new_brackets_1(allocate, SGN, INV)
		closing_unroll_with_return_new_brackets_1(allocate, SGN, INV)
	};

	struct closed
	{
		closed_unroll_no_return_new_0(allocate, SGN, INV)
		closed_unroll_with_return_new_0(allocate, SGN, INV)

		struct brackets
		{
			closed_unroll_no_return_new_brackets_0(allocate, SGN, INV)
			closed_unroll_with_return_new_brackets_0(allocate, SGN, INV)

			closed_unroll_no_return_new_brackets_1(allocate, SGN, INV)
			closed_unroll_with_return_new_brackets_1(allocate, SGN, INV)
		};
	};

	struct opening
	{
		opening_unroll_no_return_new_0(allocate, SGN, INV)
		opening_unroll_with_return_new_0(allocate, SGN, INV)

		struct brackets
		{
			opening_unroll_no_return_new_brackets_0(allocate, SGN, INV)
			opening_unroll_with_return_new_brackets_0(allocate, SGN, INV)

			opening_unroll_no_return_new_brackets_1(allocate, SGN, INV)
			opening_unroll_with_return_new_brackets_1(allocate, SGN, INV)
		};
	};

	struct open
	{
		open_unroll_no_return_new_0(allocate, SGN, INV)
		open_unroll_with_return_new_0(allocate, SGN, INV)

		struct brackets
		{
			open_unroll_no_return_new_brackets_0(allocate, SGN, INV)
			open_unroll_with_return_new_brackets_0(allocate, SGN, INV)

			open_unroll_no_return_new_brackets_1(allocate, SGN, INV)
			open_unroll_with_return_new_brackets_1(allocate, SGN, INV)
		};
	};
};

struct deallocate
{
	closing_unroll_no_return_delete_0(deallocate, SGN, INV)
	closing_unroll_with_return_delete_0(deallocate, SGN, INV)

	struct brackets
	{
		closing_unroll_no_return_delete_brackets_0(deallocate, SGN, INV)
		closing_unroll_with_return_delete_brackets_0(deallocate, SGN, INV)
	};

	struct closed
	{
		closed_unroll_no_return_delete_0(deallocate, SGN, INV)
		closed_unroll_with_return_delete_0(deallocate, SGN, INV)

		struct brackets
		{
			closed_unroll_no_return_delete_brackets_0(deallocate, SGN, INV)
			closed_unroll_with_return_delete_brackets_0(deallocate, SGN, INV)
		};
	};

	struct opening
	{
		opening_unroll_no_return_delete_0(deallocate, SGN, INV)
		opening_unroll_with_return_delete_0(deallocate, SGN, INV)

		struct brackets
		{
			opening_unroll_no_return_delete_brackets_0(deallocate, SGN, INV)
			opening_unroll_with_return_delete_brackets_0(deallocate, SGN, INV)
		};
	};

	struct open
	{
		open_unroll_no_return_delete_0(deallocate, SGN, INV)
		open_unroll_with_return_delete_0(deallocate, SGN, INV)

		struct brackets
		{
			open_unroll_no_return_delete_brackets_0(deallocate, SGN, INV)
			open_unroll_with_return_delete_brackets_0(deallocate, SGN, INV)
		};
	};
};

