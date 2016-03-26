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
	initial_no_return_1(DIRECTION, =+)
	initial_with_return_1(DIRECTION, =+)

	initial_no_return_2(DIRECTION, +)
	initial_with_return_2(DIRECTION, +)
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	initial_no_return_1(DIRECTION, =-)
	initial_with_return_1(DIRECTION, =-)

	initial_no_return_2(DIRECTION, -)
	initial_with_return_2(DIRECTION, -)
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	initial_no_return_1(DIRECTION, =*)
	initial_with_return_1(DIRECTION, =*)

	initial_no_return_2(DIRECTION, *)
	initial_with_return_2(DIRECTION, *)
};

/*
	/:
*/

struct slash
{
	initial_no_return_2(DIRECTION, /)
	initial_with_return_2(DIRECTION, /)
};

/*
	%:
*/

struct percent
{
	initial_no_return_2(DIRECTION, %)
	initial_with_return_2(DIRECTION, %)
};

/*
	ˆ:
*/

struct caret
{
	initial_no_return_2(DIRECTION, ^)
	initial_with_return_2(DIRECTION, ^)
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	initial_no_return_1(DIRECTION, =&)
	initial_with_return_1(DIRECTION, =&)

	initial_no_return_2(DIRECTION, &)
	initial_with_return_2(DIRECTION, &)
};

/*
	|:
*/

struct bar
{
	initial_no_return_2(DIRECTION, |)
	initial_with_return_2(DIRECTION, |)
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	initial_no_return_1(DIRECTION, =~)
	initial_with_return_1(DIRECTION, =~)
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	initial_no_return_1(DIRECTION, =!)
	initial_with_return_1(DIRECTION, =!)
};

/*
	<:
*/

struct less_than
{
	initial_no_return_2(DIRECTION, <)
	initial_with_return_2(DIRECTION, <)
};

/*
	>:
*/

struct greater_than
{
	initial_no_return_2(DIRECTION, >)
	initial_with_return_2(DIRECTION, >)
};

/*
	<<:
*/

struct left_shift
{
	initial_no_return_2(DIRECTION, <<)
	initial_with_return_2(DIRECTION, <<)
};

/*
	>>:
*/

struct right_shift
{
	initial_no_return_2(DIRECTION, >>)
	initial_with_return_2(DIRECTION, >>)
};

/*
	==:
*/

struct equals
{
	initial_no_return_2(DIRECTION, ==)
	initial_with_return_2(DIRECTION, ==)
};

/*
	!=:
*/

struct not_equals
{
	initial_no_return_2(DIRECTION, !=)
	initial_with_return_2(DIRECTION, !=)
};

/*
	<=:
*/

struct less_than_or_equal
{
	initial_no_return_2(DIRECTION, <=)
	initial_with_return_2(DIRECTION, <=)
};

/*
	>=:
*/

struct greater_than_or_equal
{
	initial_no_return_2(DIRECTION, >=)
	initial_with_return_2(DIRECTION, >=)
};

/*
	&&:
*/

struct logical_and
{
	initial_no_return_2(DIRECTION, &&)
	initial_with_return_2(DIRECTION, &&)
};

/*
	||:
*/

struct logical_or
{
	initial_no_return_2(DIRECTION, ||)
	initial_with_return_2(DIRECTION, ||)
};

/*
	++:
*/

struct left_increment
{
	initial_no_return_left_0(DIRECTION, ++)
};

struct right_increment
{
	initial_no_return_right_0(DIRECTION, ++)
};

/*
	--:
*/

struct left_decrement
{
	initial_no_return_left_0(DIRECTION, --)
};

struct right_decrement
{
	initial_no_return_right_0(DIRECTION, --)
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
	initial_no_return_2(DIRECTION, ->*)
	initial_with_return_2(DIRECTION, ->*)
};

/*
	->:
*/

struct point
{
	initial_with_return_2(DIRECTION, .operator->)
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	initial_no_return_right_0(DIRECTION, ())

	initial_no_return_right_1(DIRECTION, =, ())
	initial_with_return_right_1(DIRECTION, =, ())

	initial_no_return_2(DIRECTION, )
	initial_with_return_2(DIRECTION, )
};

/*
	[]:
*/

struct brackets
{
	initial_no_return_bracket_2(DIRECTION, )
	initial_with_return_bracket_2(DIRECTION, )
};

/*
	=:
*/

struct repeat
{
	initial_no_return_0(DIRECTION, =)
	// There's no need for a "return" version as the out iterator equals the end iterator upon halting.
/*
	+=:
*/
	struct plus
	{
		initial_no_return_0(DIRECTION, +=)
	};
/*
	-=:
*/
	struct minus
	{
		initial_no_return_0(DIRECTION, -=)
	};
/*
	*=:
*/
	struct asterisk
	{
		initial_no_return_0(DIRECTION, *=)
	};
/*
	/=:
*/
	struct slash
	{
		initial_no_return_0(DIRECTION, /=)
	};
/*
	%=:
*/
	struct percent
	{
		initial_no_return_0(DIRECTION, %=)
	};
/*
	ˆ=:
*/
	struct caret
	{
		initial_no_return_0(DIRECTION, ^=)
	};
/*
	&=:
*/
	struct ampersand
	{
		initial_no_return_0(DIRECTION, &=)
	};
/*
	|=:
*/
	struct bar
	{
		initial_no_return_0(DIRECTION, |=)
	};
/*
	>>=:
*/
	struct right_shift
	{
		initial_no_return_0(DIRECTION, >>=)
	};
/*
	<<=:
*/
	struct left_shift
	{
		initial_no_return_0(DIRECTION, <<=)
	};
};

/*
	=:
*/

struct assign
{
	initial_no_return_1(DIRECTION, =)
	initial_with_return_1(DIRECTION, =)
/*
	+=:
*/
	struct plus
	{
		initial_no_return_1(DIRECTION, +=)
		initial_with_return_1(DIRECTION, +=)
	};
/*
	-=:
*/
	struct minus
	{
		initial_no_return_1(DIRECTION, -=)
		initial_with_return_1(DIRECTION, -=)
	};
/*
	*=:
*/
	struct asterisk
	{
		initial_no_return_1(DIRECTION, *=)
		initial_with_return_1(DIRECTION, *=)
	};
/*
	/=:
*/
	struct slash
	{
		initial_no_return_1(DIRECTION, /=)
		initial_with_return_1(DIRECTION, /=)
	};
/*
	%=:
*/
	struct percent
	{
		initial_no_return_1(DIRECTION, %=)
		initial_with_return_1(DIRECTION, %=)
	};
/*
	ˆ=:
*/
	struct caret
	{
		initial_no_return_1(DIRECTION, ^=)
		initial_with_return_1(DIRECTION, ^=)
	};
/*
	&=:
*/
	struct ampersand
	{
		initial_no_return_1(DIRECTION, &=)
		initial_with_return_1(DIRECTION, &=)
	};
/*
	|=:
*/
	struct bar
	{
		initial_no_return_1(DIRECTION, |=)
		initial_with_return_1(DIRECTION, |=)
	};
/*
	>>=:
*/
	struct right_shift
	{
		initial_no_return_1(DIRECTION, >>=)
		initial_with_return_1(DIRECTION, >>=)
	};
/*
	<<=:
*/
	struct left_shift
	{
		initial_no_return_1(DIRECTION, <<=)
		initial_with_return_1(DIRECTION, <<=)
	};
};

