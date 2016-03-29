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
	loop_no_return_1(DIRECTION, =+)
	loop_with_return_1(DIRECTION, =+)

	loop_no_return_2(DIRECTION, +)
	loop_with_return_2(DIRECTION, +)

	struct count
	{
		count_no_return_1(DIRECTION, =+)
		count_with_return_1(DIRECTION, =+)

		count_no_return_2(DIRECTION, +)
		count_with_return_2(DIRECTION, +)
	};

	struct post_test
	{
		post_test_loop_no_return_1(DIRECTION, =+)
		post_test_loop_with_return_1(DIRECTION, =+)

		post_test_loop_no_return_2(DIRECTION, +)
		post_test_loop_with_return_2(DIRECTION, +)

		struct count
		{
			post_test_count_no_return_1(DIRECTION, =+)
			post_test_count_with_return_1(DIRECTION, =+)

			post_test_count_no_return_2(DIRECTION, +)
			post_test_count_with_return_2(DIRECTION, +)
		};
	};
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	loop_no_return_1(DIRECTION, =-)
	loop_with_return_1(DIRECTION, =-)

	loop_no_return_2(DIRECTION, -)
	loop_with_return_2(DIRECTION, -)

	struct count
	{
		count_no_return_1(DIRECTION, =-)
		count_with_return_1(DIRECTION, =-)

		count_no_return_2(DIRECTION, -)
		count_with_return_2(DIRECTION, -)
	};

	struct post_test
	{
		post_test_loop_no_return_1(DIRECTION, =-)
		post_test_loop_with_return_1(DIRECTION, =-)

		post_test_loop_no_return_2(DIRECTION, -)
		post_test_loop_with_return_2(DIRECTION, -)

		struct count
		{
			post_test_count_no_return_1(DIRECTION, =-)
			post_test_count_with_return_1(DIRECTION, =-)

			post_test_count_no_return_2(DIRECTION, -)
			post_test_count_with_return_2(DIRECTION, -)
		};
	};
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	loop_no_return_1(DIRECTION, =*)
	loop_with_return_1(DIRECTION, =*)

	loop_no_return_2(DIRECTION, *)
	loop_with_return_2(DIRECTION, *)

	struct count
	{
		count_no_return_1(DIRECTION, =*)
		count_with_return_1(DIRECTION, =*)

		count_no_return_2(DIRECTION, *)
		count_with_return_2(DIRECTION, *)
	};

	struct post_test
	{
		post_test_loop_no_return_1(DIRECTION, =*)
		post_test_loop_with_return_1(DIRECTION, =*)

		post_test_loop_no_return_2(DIRECTION, *)
		post_test_loop_with_return_2(DIRECTION, *)

		struct count
		{
			post_test_count_no_return_1(DIRECTION, =*)
			post_test_count_with_return_1(DIRECTION, =*)

			post_test_count_no_return_2(DIRECTION, *)
			post_test_count_with_return_2(DIRECTION, *)
		};
	};
};

/*
	/:
*/

struct slash
{
	loop_no_return_2(DIRECTION, /)
	loop_with_return_2(DIRECTION, /)

	struct count
	{
		count_no_return_2(DIRECTION, /)
		count_with_return_2(DIRECTION, /)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, /)
		post_test_loop_with_return_2(DIRECTION, /)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, /)
			post_test_count_with_return_2(DIRECTION, /)
		};
	};
};

/*
	%:
*/

struct percent
{
	loop_no_return_2(DIRECTION, %)
	loop_with_return_2(DIRECTION, %)

	struct count
	{
		count_no_return_2(DIRECTION, %)
		count_with_return_2(DIRECTION, %)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, %)
		post_test_loop_with_return_2(DIRECTION, %)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, %)
			post_test_count_with_return_2(DIRECTION, %)
		};
	};
};

/*
	ˆ:
*/

struct caret
{
	loop_no_return_2(DIRECTION, ^)
	loop_with_return_2(DIRECTION, ^)

	struct count
	{
		count_no_return_2(DIRECTION, ^)
		count_with_return_2(DIRECTION, ^)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, ^)
		post_test_loop_with_return_2(DIRECTION, ^)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, ^)
			post_test_count_with_return_2(DIRECTION, ^)
		};
	};
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	loop_no_return_1(DIRECTION, =&)
	loop_with_return_1(DIRECTION, =&)

	loop_no_return_2(DIRECTION, &)
	loop_with_return_2(DIRECTION, &)

	struct count
	{
		count_no_return_1(DIRECTION, =&)
		count_with_return_1(DIRECTION, =&)

		count_no_return_2(DIRECTION, &)
		count_with_return_2(DIRECTION, &)
	};

	struct post_test
	{
		post_test_loop_no_return_1(DIRECTION, =&)
		post_test_loop_with_return_1(DIRECTION, =&)

		post_test_loop_no_return_2(DIRECTION, &)
		post_test_loop_with_return_2(DIRECTION, &)

		struct count
		{
			post_test_count_no_return_1(DIRECTION, =&)
			post_test_count_with_return_1(DIRECTION, =&)

			post_test_count_no_return_2(DIRECTION, &)
			post_test_count_with_return_2(DIRECTION, &)
		};
	};
};

/*
	|:
*/

struct bar
{
	loop_no_return_2(DIRECTION, |)
	loop_with_return_2(DIRECTION, |)

	struct count
	{
		count_no_return_2(DIRECTION, |)
		count_with_return_2(DIRECTION, |)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, |)
		post_test_loop_with_return_2(DIRECTION, |)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, |)
			post_test_count_with_return_2(DIRECTION, |)
		};
	};
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	loop_no_return_1(DIRECTION, =~)
	loop_with_return_1(DIRECTION, =~)

	struct count
	{
		count_no_return_1(DIRECTION, =~)
		count_with_return_1(DIRECTION, =~)
	};

	struct post_test
	{
		post_test_loop_no_return_1(DIRECTION, =~)
		post_test_loop_with_return_1(DIRECTION, =~)

		struct count
		{
			post_test_count_no_return_1(DIRECTION, =~)
			post_test_count_with_return_1(DIRECTION, =~)
		};
	};
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	loop_no_return_1(DIRECTION, =!)
	loop_with_return_1(DIRECTION, =!)

	struct count
	{
		count_no_return_1(DIRECTION, =!)
		count_with_return_1(DIRECTION, =!)
	};

	struct post_test
	{
		post_test_loop_no_return_1(DIRECTION, =!)
		post_test_loop_with_return_1(DIRECTION, =!)

		struct count
		{
			post_test_count_no_return_1(DIRECTION, =!)
			post_test_count_with_return_1(DIRECTION, =!)
		};
	};
};

/*
	<:
*/

struct less_than
{
	loop_no_return_2(DIRECTION, <)
	loop_with_return_2(DIRECTION, <)

	struct count
	{
		count_no_return_2(DIRECTION, <)
		count_with_return_2(DIRECTION, <)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, <)
		post_test_loop_with_return_2(DIRECTION, <)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, <)
			post_test_count_with_return_2(DIRECTION, <)
		};
	};
};

/*
	>:
*/

struct greater_than
{
	loop_no_return_2(DIRECTION, >)
	loop_with_return_2(DIRECTION, >)

	struct count
	{
		count_no_return_2(DIRECTION, >)
		count_with_return_2(DIRECTION, >)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, >)
		post_test_loop_with_return_2(DIRECTION, >)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, >)
			post_test_count_with_return_2(DIRECTION, >)
		};
	};
};

/*
	<<:
*/

struct left_shift
{
	loop_no_return_2(DIRECTION, <<)
	loop_with_return_2(DIRECTION, <<)

	struct count
	{
		count_no_return_2(DIRECTION, <<)
		count_with_return_2(DIRECTION, <<)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, <<)
		post_test_loop_with_return_2(DIRECTION, <<)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, <<)
			post_test_count_with_return_2(DIRECTION, <<)
		};
	};
};

/*
	>>:
*/

struct right_shift
{
	loop_no_return_2(DIRECTION, >>)
	loop_with_return_2(DIRECTION, >>)

	struct count
	{
		count_no_return_2(DIRECTION, >>)
		count_with_return_2(DIRECTION, >>)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, >>)
		post_test_loop_with_return_2(DIRECTION, >>)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, >>)
			post_test_count_with_return_2(DIRECTION, >>)
		};
	};
};

/*
	==:
*/

struct equals
{
	loop_no_return_2(DIRECTION, ==)
	loop_with_return_2(DIRECTION, ==)

	struct count
	{
		count_no_return_2(DIRECTION, ==)
		count_with_return_2(DIRECTION, ==)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, ==)
		post_test_loop_with_return_2(DIRECTION, ==)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, ==)
			post_test_count_with_return_2(DIRECTION, ==)
		};
	};
};

/*
	!=:
*/

struct not_equals
{
	loop_no_return_2(DIRECTION, !=)
	loop_with_return_2(DIRECTION, !=)

	struct count
	{
		count_no_return_2(DIRECTION, !=)
		count_with_return_2(DIRECTION, !=)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, !=)
		post_test_loop_with_return_2(DIRECTION, !=)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, !=)
			post_test_count_with_return_2(DIRECTION, !=)
		};
	};
};

/*
	<=:
*/

struct less_than_or_equal
{
	loop_no_return_2(DIRECTION, <=)
	loop_with_return_2(DIRECTION, <=)

	struct count
	{
		count_no_return_2(DIRECTION, <=)
		count_with_return_2(DIRECTION, <=)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, <=)
		post_test_loop_with_return_2(DIRECTION, <=)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, <=)
			post_test_count_with_return_2(DIRECTION, <=)
		};
	};
};

/*
	>=:
*/

struct greater_than_or_equal
{
	loop_no_return_2(DIRECTION, >=)
	loop_with_return_2(DIRECTION, >=)

	struct count
	{
		count_no_return_2(DIRECTION, >=)
		count_with_return_2(DIRECTION, >=)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, >=)
		post_test_loop_with_return_2(DIRECTION, >=)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, >=)
			post_test_count_with_return_2(DIRECTION, >=)
		};
	};
};

/*
	&&:
*/

struct logical_and
{
	loop_no_return_2(DIRECTION, &&)
	loop_with_return_2(DIRECTION, &&)

	struct count
	{
		count_no_return_2(DIRECTION, &&)
		count_with_return_2(DIRECTION, &&)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, &&)
		post_test_loop_with_return_2(DIRECTION, &&)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, &&)
			post_test_count_with_return_2(DIRECTION, &&)
		};
	};
};

/*
	||:
*/

struct logical_or
{
	loop_no_return_2(DIRECTION, ||)
	loop_with_return_2(DIRECTION, ||)

	struct count
	{
		count_no_return_2(DIRECTION, ||)
		count_with_return_2(DIRECTION, ||)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, ||)
		post_test_loop_with_return_2(DIRECTION, ||)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, ||)
			post_test_count_with_return_2(DIRECTION, ||)
		};
	};
};

/*
	++:
*/

struct left_increment
{
	loop_no_return_left_0(DIRECTION, ++)

	struct count
	{
		count_no_return_left_0(DIRECTION, ++)
	};

	struct post_test
	{
		post_test_loop_no_return_left_0(DIRECTION, ++)

		struct count
		{
			post_test_count_no_return_left_0(DIRECTION, ++)
		};
	};
};

struct right_increment
{
	loop_no_return_right_0(DIRECTION, ++)

	struct count
	{
		count_no_return_right_0(DIRECTION, ++)
	};

	struct post_test
	{
		post_test_loop_no_return_right_0(DIRECTION, ++)

		struct count
		{
			post_test_count_no_return_right_0(DIRECTION, ++)
		};
	};
};

/*
	--:
*/

struct left_decrement
{
	loop_no_return_left_0(DIRECTION, --)

	struct count
	{
		count_no_return_left_0(DIRECTION, --)
	};

	struct post_test
	{
		post_test_loop_no_return_left_0(DIRECTION, --)

		struct count
		{
			post_test_count_no_return_left_0(DIRECTION, --)
		};
	};
};

struct right_decrement
{
	loop_no_return_right_0(DIRECTION, --)

	struct count
	{
		count_no_return_right_0(DIRECTION, --)
	};

	struct post_test
	{
		post_test_loop_no_return_right_0(DIRECTION, --)

		struct count
		{
			post_test_count_no_return_right_0(DIRECTION, --)
		};
	};
};

/*
	,:
*/

struct comma
{
	struct count
	{
	};

	struct post_test
	{
		struct count
		{
		};
	};
};

/*
	->*:
*/

struct point_asterisk
{
	loop_no_return_2(DIRECTION, ->*)
	loop_with_return_2(DIRECTION, ->*)

	struct count
	{
		count_no_return_2(DIRECTION, ->*)
		count_with_return_2(DIRECTION, ->*)
	};

	struct post_test
	{
		post_test_loop_no_return_2(DIRECTION, ->*)
		post_test_loop_with_return_2(DIRECTION, ->*)

		struct count
		{
			post_test_count_no_return_2(DIRECTION, ->*)
			post_test_count_with_return_2(DIRECTION, ->*)
		};
	};
};

/*
	->:
*/

struct point
{
	loop_with_return_2(DIRECTION, .operator->)

	struct count
	{
		count_with_return_2(DIRECTION, .operator->)
	};

	struct post_test
	{
		post_test_loop_with_return_2(DIRECTION, .operator->)

		struct count
		{
			post_test_count_with_return_2(DIRECTION, .operator->)
		};
	};
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	loop_no_return_right_0(DIRECTION, ())

	loop_no_return_right_1(DIRECTION, =, ())
	loop_with_return_right_1(DIRECTION, =, ())

	loop_no_return_2(DIRECTION, )
	loop_with_return_2(DIRECTION, )

	struct count
	{
		count_no_return_right_0(DIRECTION, ())

		count_no_return_right_1(DIRECTION, =, ())
		count_with_return_right_1(DIRECTION, =, ())

		count_no_return_2(DIRECTION, )
		count_with_return_2(DIRECTION, )
	};

	struct post_test
	{
		post_test_loop_no_return_right_0(DIRECTION, ())

		post_test_loop_no_return_right_1(DIRECTION, =, ())
		post_test_loop_with_return_right_1(DIRECTION, =, ())

		post_test_loop_no_return_2(DIRECTION, )
		post_test_loop_with_return_2(DIRECTION, )

		struct count
		{
			post_test_count_no_return_right_0(DIRECTION, ())

			post_test_count_no_return_right_1(DIRECTION, =, ())
			post_test_count_with_return_right_1(DIRECTION, =, ())

			post_test_count_no_return_2(DIRECTION, )
			post_test_count_with_return_2(DIRECTION, )
		};
	};
};

/*
	[]:
*/

struct brackets
{
	loop_no_return_bracket_2(DIRECTION, )
	loop_with_return_bracket_2(DIRECTION, )

	struct count
	{
		count_no_return_bracket_2(DIRECTION, )
		count_with_return_bracket_2(DIRECTION, )
	};

	struct post_test
	{
		post_test_loop_no_return_bracket_2(DIRECTION, )
		post_test_loop_with_return_bracket_2(DIRECTION, )

		struct count
		{
			post_test_count_no_return_bracket_2(DIRECTION, )
			post_test_count_with_return_bracket_2(DIRECTION, )
		};
	};
};

/*
	=:
*/

struct repeat
{
	loop_no_return_0(DIRECTION, =)
	loop_with_return_0(DIRECTION, =)

	struct count
	{
		count_no_return_0(DIRECTION, =)
		count_with_return_0(DIRECTION, =)
	};

	struct post_test
	{
		post_test_loop_no_return_0(DIRECTION, =)
		post_test_loop_with_return_0(DIRECTION, =)

		struct count
		{
			post_test_count_no_return_0(DIRECTION, =)
			post_test_count_with_return_0(DIRECTION, =)
		};
	};
/*
	+=:
*/
	struct plus
	{
		loop_no_return_0(DIRECTION, +=)

		struct count
		{
			count_no_return_0(DIRECTION, +=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, +=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, +=)
			};
		};
	};
/*
	-=:
*/
	struct minus
	{
		loop_no_return_0(DIRECTION, -=)

		struct count
		{
			count_no_return_0(DIRECTION, -=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, -=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, -=)
			};
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		loop_no_return_0(DIRECTION, *=)

		struct count
		{
			count_no_return_0(DIRECTION, *=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, *=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, *=)
			};
		};
	};
/*
	/=:
*/
	struct slash
	{
		loop_no_return_0(DIRECTION, /=)

		struct count
		{
			count_no_return_0(DIRECTION, /=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, /=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, /=)
			};
		};
	};
/*
	%=:
*/
	struct percent
	{
		loop_no_return_0(DIRECTION, %=)

		struct count
		{
			count_no_return_0(DIRECTION, %=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, %=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, %=)
			};
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		loop_no_return_0(DIRECTION, ^=)

		struct count
		{
			count_no_return_0(DIRECTION, ^=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, ^=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, ^=)
			};
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		loop_no_return_0(DIRECTION, &=)

		struct count
		{
			count_no_return_0(DIRECTION, &=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, &=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, &=)
			};
		};
	};
/*
	|=:
*/
	struct bar
	{
		loop_no_return_0(DIRECTION, |=)

		struct count
		{
			count_no_return_0(DIRECTION, |=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, |=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, |=)
			};
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		loop_no_return_0(DIRECTION, >>=)

		struct count
		{
			count_no_return_0(DIRECTION, >>=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, >>=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, >>=)
			};
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		loop_no_return_0(DIRECTION, <<=)

		struct count
		{
			count_no_return_0(DIRECTION, <<=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(DIRECTION, <<=)

			struct count
			{
				post_test_count_no_return_0(DIRECTION, <<=)
			};
		};
	};
};

/*
	=:
*/

struct assign
{
	loop_no_return_1(DIRECTION, =)
	loop_with_return_1(DIRECTION, =)
/*
	Same as above, but additionally counts the length between first and last as a side-effect.
*/
	struct count
	{
		count_no_return_1(DIRECTION, =)
		count_with_return_1(DIRECTION, =)
	};

	struct post_test
	{
		post_test_loop_no_return_1(DIRECTION, =)
		post_test_loop_with_return_1(DIRECTION, =)
/*
	Same as above, but additionally counts the length between first and last as a side-effect.
*/
		struct count
		{
			post_test_count_no_return_1(DIRECTION, =)
			post_test_count_with_return_1(DIRECTION, =)
		};
	};
/*
	+=:
*/
	struct plus
	{
		loop_no_return_1(DIRECTION, +=)
		loop_with_return_1(DIRECTION, +=)

		struct count
		{
			count_no_return_1(DIRECTION, +=)
			count_with_return_1(DIRECTION, +=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, +=)
			post_test_loop_with_return_1(DIRECTION, +=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, +=)
				post_test_count_with_return_1(DIRECTION, +=)
			};
		};
	};
/*
	-=:
*/
	struct minus
	{
		loop_no_return_1(DIRECTION, -=)
		loop_with_return_1(DIRECTION, -=)

		struct count
		{
			count_no_return_1(DIRECTION, -=)
			count_with_return_1(DIRECTION, -=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, -=)
			post_test_loop_with_return_1(DIRECTION, -=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, -=)
				post_test_count_with_return_1(DIRECTION, -=)
			};
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		loop_no_return_1(DIRECTION, *=)
		loop_with_return_1(DIRECTION, *=)

		struct count
		{
			count_no_return_1(DIRECTION, *=)
			count_with_return_1(DIRECTION, *=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, *=)
			post_test_loop_with_return_1(DIRECTION, *=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, *=)
				post_test_count_with_return_1(DIRECTION, *=)
			};
		};
	};
/*
	/=:
*/
	struct slash
	{
		loop_no_return_1(DIRECTION, /=)
		loop_with_return_1(DIRECTION, /=)

		struct count
		{
			count_no_return_1(DIRECTION, /=)
			count_with_return_1(DIRECTION, /=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, /=)
			post_test_loop_with_return_1(DIRECTION, /=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, /=)
				post_test_count_with_return_1(DIRECTION, /=)
			};
		};
	};
/*
	%=:
*/
	struct percent
	{
		loop_no_return_1(DIRECTION, %=)
		loop_with_return_1(DIRECTION, %=)

		struct count
		{
			count_no_return_1(DIRECTION, %=)
			count_with_return_1(DIRECTION, %=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, %=)
			post_test_loop_with_return_1(DIRECTION, %=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, %=)
				post_test_count_with_return_1(DIRECTION, %=)
			};
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		loop_no_return_1(DIRECTION, ^=)
		loop_with_return_1(DIRECTION, ^=)

		struct count
		{
			count_no_return_1(DIRECTION, ^=)
			count_with_return_1(DIRECTION, ^=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, ^=)
			post_test_loop_with_return_1(DIRECTION, ^=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, ^=)
				post_test_count_with_return_1(DIRECTION, ^=)
			};
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		loop_no_return_1(DIRECTION, &=)
		loop_with_return_1(DIRECTION, &=)

		struct count
		{
			count_no_return_1(DIRECTION, &=)
			count_with_return_1(DIRECTION, &=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, &=)
			post_test_loop_with_return_1(DIRECTION, &=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, &=)
				post_test_count_with_return_1(DIRECTION, &=)
			};
		};
	};
/*
	|=:
*/
	struct bar
	{
		loop_no_return_1(DIRECTION, |=)
		loop_with_return_1(DIRECTION, |=)

		struct count
		{
			count_no_return_1(DIRECTION, |=)
			count_with_return_1(DIRECTION, |=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, |=)
			post_test_loop_with_return_1(DIRECTION, |=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, |=)
				post_test_count_with_return_1(DIRECTION, |=)
			};
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		loop_no_return_1(DIRECTION, >>=)
		loop_with_return_1(DIRECTION, >>=)

		struct count
		{
			count_no_return_1(DIRECTION, >>=)
			count_with_return_1(DIRECTION, >>=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, >>=)
			post_test_loop_with_return_1(DIRECTION, >>=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, >>=)
				post_test_count_with_return_1(DIRECTION, >>=)
			};
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		loop_no_return_1(DIRECTION, <<=)
		loop_with_return_1(DIRECTION, <<=)

		struct count
		{
			count_no_return_1(DIRECTION, <<=)
			count_with_return_1(DIRECTION, <<=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(DIRECTION, <<=)
			post_test_loop_with_return_1(DIRECTION, <<=)

			struct count
			{
				post_test_count_no_return_1(DIRECTION, <<=)
				post_test_count_with_return_1(DIRECTION, <<=)
			};
		};
	};
};

struct allocate
{
	loop_no_return_new_0(DIRECTION)
	loop_with_return_new_0(DIRECTION)

	struct count
	{
		count_no_return_new_0(DIRECTION)
		count_with_return_new_0(DIRECTION)
	};

	struct post_test
	{
		post_test_loop_no_return_new_0(DIRECTION)
		post_test_loop_with_return_new_0(DIRECTION)

		struct count
		{
			post_test_count_no_return_new_0(DIRECTION)
			post_test_count_with_return_new_0(DIRECTION)
		};
	};
};

struct deallocate
{
	loop_no_return_delete_0(DIRECTION)
	loop_with_return_delete_0(DIRECTION)

	struct count
	{
		count_no_return_delete_0(DIRECTION)
		count_with_return_delete_0(DIRECTION)
	};

	struct post_test
	{
		post_test_loop_no_return_delete_0(DIRECTION)
		post_test_loop_with_return_delete_0(DIRECTION)

		struct count
		{
			post_test_count_no_return_delete_0(DIRECTION)
			post_test_count_with_return_delete_0(DIRECTION)
		};
	};
};

