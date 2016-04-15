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
*/

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

	struct post_test
	{
		post_test_unroll_no_return_1(plus, -, =+)
		post_test_unroll_with_return_1(plus, -, =+)

		post_test_unroll_no_return_2(plus, -, +)
		post_test_unroll_with_return_2(plus, -, +)
	};
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

	struct post_test
	{
		post_test_unroll_no_return_1(minus, -, =-)
		post_test_unroll_with_return_1(minus, -, =-)

		post_test_unroll_no_return_2(minus, -, -)
		post_test_unroll_with_return_2(minus, -, -)
	};
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

	struct post_test
	{
		post_test_unroll_no_return_1(asterisk, -, =*)
		post_test_unroll_with_return_1(asterisk, -, =*)

		post_test_unroll_no_return_2(asterisk, -, *)
		post_test_unroll_with_return_2(asterisk, -, *)
	};
};

/*
	/:
*/

struct slash
{
	unroll_no_return_2(slash, -, /)
	unroll_with_return_2(slash, -, /)

	struct post_test
	{
		post_test_unroll_no_return_2(slash, -, /)
		post_test_unroll_with_return_2(slash, -, /)
	};
};

/*
	%:
*/

struct percent
{
	unroll_no_return_2(percent, -, %)
	unroll_with_return_2(percent, -, %)

	struct post_test
	{
		post_test_unroll_no_return_2(percent, -, %)
		post_test_unroll_with_return_2(percent, -, %)
	};
};

/*
	ˆ:
*/

struct caret
{
	unroll_no_return_2(caret, -, ^)
	unroll_with_return_2(caret, -, ^)

	struct post_test
	{
		post_test_unroll_no_return_2(caret, -, ^)
		post_test_unroll_with_return_2(caret, -, ^)
	};
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

	struct post_test
	{
		post_test_unroll_no_return_1(ampersand, -, =&)
		post_test_unroll_with_return_1(ampersand, -, =&)

		post_test_unroll_no_return_2(ampersand, -, &)
		post_test_unroll_with_return_2(ampersand, -, &)
	};
};

/*
	|:
*/

struct bar
{
	unroll_no_return_2(bar, -, |)
	unroll_with_return_2(bar, -, |)

	struct post_test
	{
		post_test_unroll_no_return_2(bar, -, |)
		post_test_unroll_with_return_2(bar, -, |)
	};
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	unroll_no_return_1(tilde, -, =~)
	unroll_with_return_1(tilde, -, =~)

	struct post_test
	{
		post_test_unroll_no_return_1(tilde, -, =~)
		post_test_unroll_with_return_1(tilde, -, =~)
	};
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	unroll_no_return_1(exclamation, -, =!)
	unroll_with_return_1(exclamation, -, =!)

	struct post_test
	{
		post_test_unroll_no_return_1(exclamation, -, =!)
		post_test_unroll_with_return_1(exclamation, -, =!)
	};
};

/*
	<:
*/

struct less_than
{
	unroll_no_return_2(less_than, -, <)
	unroll_with_return_2(less_than, -, <)

	struct post_test
	{
		post_test_unroll_no_return_2(less_than, -, <)
		post_test_unroll_with_return_2(less_than, -, <)
	};
};

/*
	>:
*/

struct greater_than
{
	unroll_no_return_2(greater_than, -, >)
	unroll_with_return_2(greater_than, -, >)

	struct post_test
	{
		post_test_unroll_no_return_2(greater_than, -, >)
		post_test_unroll_with_return_2(greater_than, -, >)
	};
};

/*
	<<:
*/

struct left_shift
{
	unroll_no_return_2(left_shift, -, <<)
	unroll_with_return_2(left_shift, -, <<)

	struct post_test
	{
		post_test_unroll_no_return_2(left_shift, -, <<)
		post_test_unroll_with_return_2(left_shift, -, <<)
	};
};

/*
	>>:
*/

struct right_shift
{
	unroll_no_return_2(right_shift, -, >>)
	unroll_with_return_2(right_shift, -, >>)

	struct post_test
	{
		post_test_unroll_no_return_2(right_shift, -, >>)
		post_test_unroll_with_return_2(right_shift, -, >>)
	};
};

/*
	==:
*/

struct equals
{
	unroll_no_return_2(equals, -, ==)
	unroll_with_return_2(equals, -, ==)

	struct post_test
	{
		post_test_unroll_no_return_2(equals, -, ==)
		post_test_unroll_with_return_2(equals, -, ==)
	};
};

/*
	!=:
*/

struct not_equals
{
	unroll_no_return_2(not_equals, -, !=)
	unroll_with_return_2(not_equals, -, !=)

	struct post_test
	{
		post_test_unroll_no_return_2(not_equals, -, !=)
		post_test_unroll_with_return_2(not_equals, -, !=)
	};
};

/*
	<=:
*/

struct less_than_or_equal
{
	unroll_no_return_2(less_than_or_equal, -, <=)
	unroll_with_return_2(less_than_or_equal, -, <=)

	struct post_test
	{
		post_test_unroll_no_return_2(less_than_or_equal, -, <=)
		post_test_unroll_with_return_2(less_than_or_equal, -, <=)
	};
};

/*
	>=:
*/

struct greater_than_or_equal
{
	unroll_no_return_2(greater_than_or_equal, -, >=)
	unroll_with_return_2(greater_than_or_equal, -, >=)

	struct post_test
	{
		post_test_unroll_no_return_2(greater_than_or_equal, -, >=)
		post_test_unroll_with_return_2(greater_than_or_equal, -, >=)
	};
};

/*
	&&:
*/

struct logical_and
{
	unroll_no_return_2(logical_and, -, &&)
	unroll_with_return_2(logical_and, -, &&)

	struct post_test
	{
		post_test_unroll_no_return_2(logical_and, -, &&)
		post_test_unroll_with_return_2(logical_and, -, &&)
	};
};

/*
	||:
*/

struct logical_or
{
	unroll_no_return_2(logical_or, -, ||)
	unroll_with_return_2(logical_or, -, ||)

	struct post_test
	{
		post_test_unroll_no_return_2(logical_or, -, ||)
		post_test_unroll_with_return_2(logical_or, -, ||)
	};
};

/*
	++:
*/

struct left_increment
{
	unroll_no_return_left_0(left_increment, -, ++)

	struct post_test
	{
		post_test_unroll_no_return_left_0(left_increment, -, ++)
	};
};

struct right_increment
{
	unroll_no_return_right_0(right_increment, -, ++)

	struct post_test
	{
		post_test_unroll_no_return_right_0(right_increment, -, ++)
	};
};

/*
	--:
*/

struct left_decrement
{
	unroll_no_return_left_0(left_decrement, -, --)

	struct post_test
	{
		post_test_unroll_no_return_left_0(left_decrement, -, --)
	};
};

struct right_decrement
{
	unroll_no_return_right_0(right_decrement, -, --)

	struct post_test
	{
		post_test_unroll_no_return_right_0(right_decrement, -, --)
	};
};

/*
	,:
*/

struct comma
{
	struct post_test
	{
	};
};

/*
	->*:
*/

struct point_asterisk
{
	unroll_no_return_2(point_asterisk, -, ->*)
	unroll_with_return_2(point_asterisk, -, ->*)

	struct post_test
	{
		post_test_unroll_no_return_2(point_asterisk, -, ->*)
		post_test_unroll_with_return_2(point_asterisk, -, ->*)
	};
};

/*
	->:
*/

struct point
{
	unroll_with_return_2(point, -, .operator->)

	struct post_test
	{
		post_test_unroll_with_return_2(point, -, .operator->)
	};
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

	struct post_test
	{
		post_test_unroll_no_return_right_0(parentheses, -, ())

		post_test_unroll_no_return_right_1(parentheses, -, =, ())
		post_test_unroll_with_return_right_1(parentheses, -, =, ())

		post_test_unroll_no_return_2(parentheses, -, )
		post_test_unroll_with_return_2(parentheses, -, )
	};
};

/*
	[]:
*/

struct brackets
{
	unroll_no_return_brackets_2(brackets, -, )
	unroll_with_return_brackets_2(brackets, -, )

	struct post_test
	{
		post_test_unroll_no_return_brackets_2(brackets, -, )
		post_test_unroll_with_return_brackets_2(brackets, -, )
	};
};

/*
	=:
*/

struct repeat
{
	unroll_no_return_0(repeat, -, =)
	unroll_with_return_0(repeat, -, =)

	struct post_test
	{
		post_test_unroll_no_return_0(repeat, -, =)
		post_test_unroll_with_return_0(repeat, -, =)
	};
/*
	+=:
*/
	struct plus
	{
		unroll_no_return_0(plus, -, +=)

		struct post_test
		{
			post_test_unroll_no_return_0(plus, -, +=)
		};
	};
/*
	-=:
*/
	struct minus
	{
		unroll_no_return_0(minus, -, -=)

		struct post_test
		{
			post_test_unroll_no_return_0(minus, -, -=)
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		unroll_no_return_0(asterisk, -, *=)

		struct post_test
		{
			post_test_unroll_no_return_0(asterisk, -, *=)
		};
	};
/*
	/=:
*/
	struct slash
	{
		unroll_no_return_0(slash, -, /=)

		struct post_test
		{
			post_test_unroll_no_return_0(slash, -, /=)
		};
	};
/*
	%=:
*/
	struct percent
	{
		unroll_no_return_0(percent, -, %=)

		struct post_test
		{
			post_test_unroll_no_return_0(percent, -, %=)
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		unroll_no_return_0(caret, -, ^=)

		struct post_test
		{
			post_test_unroll_no_return_0(caret, -, ^=)
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		unroll_no_return_0(ampersand, -, &=)

		struct post_test
		{
			post_test_unroll_no_return_0(ampersand, -, &=)
		};
	};
/*
	|=:
*/
	struct bar
	{
		unroll_no_return_0(bar, -, |=)

		struct post_test
		{
			post_test_unroll_no_return_0(bar, -, |=)
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		unroll_no_return_0(right_shift, -, >>=)

		struct post_test
		{
			post_test_unroll_no_return_0(right_shift, -, >>=)
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		unroll_no_return_0(left_shift, -, <<=)

		struct post_test
		{
			post_test_unroll_no_return_0(left_shift, -, <<=)
		};
	};
};

/*
	=:
*/

struct assign
{
	unroll_no_return_1(assign, -, =)
	unroll_with_return_1(assign, -, =)

	struct post_test
	{
		post_test_unroll_no_return_1(assign, -, =)
		post_test_unroll_with_return_1(assign, -, =)
	};
/*
	+=:
*/
	struct plus
	{
		unroll_no_return_1(plus, -, +=)
		unroll_with_return_1(plus, -, +=)

		struct post_test
		{
			post_test_unroll_no_return_1(plus, -, +=)
			post_test_unroll_with_return_1(plus, -, +=)
		};
	};
/*
	-=:
*/
	struct minus
	{
		unroll_no_return_1(minus, -, -=)
		unroll_with_return_1(minus, -, -=)

		struct post_test
		{
			post_test_unroll_no_return_1(minus, -, -=)
			post_test_unroll_with_return_1(minus, -, -=)
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		unroll_no_return_1(asterisk, -, *=)
		unroll_with_return_1(asterisk, -, *=)

		struct post_test
		{
			post_test_unroll_no_return_1(asterisk, -, *=)
			post_test_unroll_with_return_1(asterisk, -, *=)
		};
	};
/*
	/=:
*/
	struct slash
	{
		unroll_no_return_1(slash, -, /=)
		unroll_with_return_1(slash, -, /=)

		struct post_test
		{
			post_test_unroll_no_return_1(slash, -, /=)
			post_test_unroll_with_return_1(slash, -, /=)
		};
	};
/*
	%=:
*/
	struct percent
	{
		unroll_no_return_1(percent, -, %=)
		unroll_with_return_1(percent, -, %=)

		struct post_test
		{
			post_test_unroll_no_return_1(percent, -, %=)
			post_test_unroll_with_return_1(percent, -, %=)
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		unroll_no_return_1(caret, -, ^=)
		unroll_with_return_1(caret, -, ^=)

		struct post_test
		{
			post_test_unroll_no_return_1(caret, -, ^=)
			post_test_unroll_with_return_1(caret, -, ^=)
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		unroll_no_return_1(ampersand, -, &=)
		unroll_with_return_1(ampersand, -, &=)

		struct post_test
		{
			post_test_unroll_no_return_1(ampersand, -, &=)
			post_test_unroll_with_return_1(ampersand, -, &=)
		};
	};
/*
	|=:
*/
	struct bar
	{
		unroll_no_return_1(bar, -, |=)
		unroll_with_return_1(bar, -, |=)

		struct post_test
		{
			post_test_unroll_no_return_1(bar, -, |=)
			post_test_unroll_with_return_1(bar, -, |=)
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		unroll_no_return_1(right_shift, -, >>=)
		unroll_with_return_1(right_shift, -, >>=)

		struct post_test
		{
			post_test_unroll_no_return_1(right_shift, -, >>=)
			post_test_unroll_with_return_1(right_shift, -, >>=)
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		unroll_no_return_1(left_shift, -, <<=)
		unroll_with_return_1(left_shift, -, <<=)

		struct post_test
		{
			post_test_unroll_no_return_1(left_shift, -, <<=)
			post_test_unroll_with_return_1(left_shift, -, <<=)
		};
	};
};

struct allocate
{
	unroll_no_return_new_0(allocate, -)
	unroll_with_return_new_0(allocate, -)

	struct brackets
	{
		unroll_no_return_new_brackets_0(allocate, -)
		unroll_with_return_new_brackets_0(allocate, -)

		unroll_no_return_new_brackets_1(allocate, -)
		unroll_with_return_new_brackets_1(allocate, -)
	};

	struct post_test
	{
		post_test_unroll_no_return_new_0(allocate, -)
		post_test_unroll_with_return_new_0(allocate, -)

		struct brackets
		{
			post_test_unroll_no_return_new_brackets_0(allocate, -)
			post_test_unroll_with_return_new_brackets_0(allocate, -)

			post_test_unroll_no_return_new_brackets_1(allocate, -)
			post_test_unroll_with_return_new_brackets_1(allocate, -)
		};
	};
};

struct deallocate
{
	unroll_no_return_delete_0(deallocate, -)
	unroll_with_return_delete_0(deallocate, -)

	struct brackets
	{
		unroll_no_return_delete_brackets_0(deallocate, -)
		unroll_with_return_delete_brackets_0(deallocate, -)
	};

	struct post_test
	{
		post_test_unroll_no_return_delete_0(deallocate, -)
		post_test_unroll_with_return_delete_0(deallocate, -)

		struct brackets
		{
			post_test_unroll_no_return_delete_brackets_0(deallocate, -)
			post_test_unroll_with_return_delete_brackets_0(deallocate, -)
		};
	};
};

