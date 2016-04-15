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
	loop_no_return_1(-, =+)
	loop_with_return_1(-, =+)

	loop_no_return_2(-, +)
	loop_with_return_2(-, +)

	struct count
	{
		count_no_return_1(-, =+)
		count_with_return_1(-, =+)

		count_no_return_2(-, +)
		count_with_return_2(-, +)
	};

	struct post_test
	{
		post_test_loop_no_return_1(-, =+)
		post_test_loop_with_return_1(-, =+)

		post_test_loop_no_return_2(-, +)
		post_test_loop_with_return_2(-, +)

		struct count
		{
			post_test_count_no_return_1(-, =+)
			post_test_count_with_return_1(-, =+)

			post_test_count_no_return_2(-, +)
			post_test_count_with_return_2(-, +)
		};
	};
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	loop_no_return_1(-, =-)
	loop_with_return_1(-, =-)

	loop_no_return_2(-, -)
	loop_with_return_2(-, -)

	struct count
	{
		count_no_return_1(-, =-)
		count_with_return_1(-, =-)

		count_no_return_2(-, -)
		count_with_return_2(-, -)
	};

	struct post_test
	{
		post_test_loop_no_return_1(-, =-)
		post_test_loop_with_return_1(-, =-)

		post_test_loop_no_return_2(-, -)
		post_test_loop_with_return_2(-, -)

		struct count
		{
			post_test_count_no_return_1(-, =-)
			post_test_count_with_return_1(-, =-)

			post_test_count_no_return_2(-, -)
			post_test_count_with_return_2(-, -)
		};
	};
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	loop_no_return_1(-, =*)
	loop_with_return_1(-, =*)

	loop_no_return_2(-, *)
	loop_with_return_2(-, *)

	struct count
	{
		count_no_return_1(-, =*)
		count_with_return_1(-, =*)

		count_no_return_2(-, *)
		count_with_return_2(-, *)
	};

	struct post_test
	{
		post_test_loop_no_return_1(-, =*)
		post_test_loop_with_return_1(-, =*)

		post_test_loop_no_return_2(-, *)
		post_test_loop_with_return_2(-, *)

		struct count
		{
			post_test_count_no_return_1(-, =*)
			post_test_count_with_return_1(-, =*)

			post_test_count_no_return_2(-, *)
			post_test_count_with_return_2(-, *)
		};
	};
};

/*
	/:
*/

struct slash
{
	loop_no_return_2(-, /)
	loop_with_return_2(-, /)

	struct count
	{
		count_no_return_2(-, /)
		count_with_return_2(-, /)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, /)
		post_test_loop_with_return_2(-, /)

		struct count
		{
			post_test_count_no_return_2(-, /)
			post_test_count_with_return_2(-, /)
		};
	};
};

/*
	%:
*/

struct percent
{
	loop_no_return_2(-, %)
	loop_with_return_2(-, %)

	struct count
	{
		count_no_return_2(-, %)
		count_with_return_2(-, %)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, %)
		post_test_loop_with_return_2(-, %)

		struct count
		{
			post_test_count_no_return_2(-, %)
			post_test_count_with_return_2(-, %)
		};
	};
};

/*
	ˆ:
*/

struct caret
{
	loop_no_return_2(-, ^)
	loop_with_return_2(-, ^)

	struct count
	{
		count_no_return_2(-, ^)
		count_with_return_2(-, ^)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, ^)
		post_test_loop_with_return_2(-, ^)

		struct count
		{
			post_test_count_no_return_2(-, ^)
			post_test_count_with_return_2(-, ^)
		};
	};
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	loop_no_return_1(-, =&)
	loop_with_return_1(-, =&)

	loop_no_return_2(-, &)
	loop_with_return_2(-, &)

	struct count
	{
		count_no_return_1(-, =&)
		count_with_return_1(-, =&)

		count_no_return_2(-, &)
		count_with_return_2(-, &)
	};

	struct post_test
	{
		post_test_loop_no_return_1(-, =&)
		post_test_loop_with_return_1(-, =&)

		post_test_loop_no_return_2(-, &)
		post_test_loop_with_return_2(-, &)

		struct count
		{
			post_test_count_no_return_1(-, =&)
			post_test_count_with_return_1(-, =&)

			post_test_count_no_return_2(-, &)
			post_test_count_with_return_2(-, &)
		};
	};
};

/*
	|:
*/

struct bar
{
	loop_no_return_2(-, |)
	loop_with_return_2(-, |)

	struct count
	{
		count_no_return_2(-, |)
		count_with_return_2(-, |)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, |)
		post_test_loop_with_return_2(-, |)

		struct count
		{
			post_test_count_no_return_2(-, |)
			post_test_count_with_return_2(-, |)
		};
	};
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	loop_no_return_1(-, =~)
	loop_with_return_1(-, =~)

	struct count
	{
		count_no_return_1(-, =~)
		count_with_return_1(-, =~)
	};

	struct post_test
	{
		post_test_loop_no_return_1(-, =~)
		post_test_loop_with_return_1(-, =~)

		struct count
		{
			post_test_count_no_return_1(-, =~)
			post_test_count_with_return_1(-, =~)
		};
	};
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	loop_no_return_1(-, =!)
	loop_with_return_1(-, =!)

	struct count
	{
		count_no_return_1(-, =!)
		count_with_return_1(-, =!)
	};

	struct post_test
	{
		post_test_loop_no_return_1(-, =!)
		post_test_loop_with_return_1(-, =!)

		struct count
		{
			post_test_count_no_return_1(-, =!)
			post_test_count_with_return_1(-, =!)
		};
	};
};

/*
	<:
*/

struct less_than
{
	loop_no_return_2(-, <)
	loop_with_return_2(-, <)

	struct count
	{
		count_no_return_2(-, <)
		count_with_return_2(-, <)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, <)
		post_test_loop_with_return_2(-, <)

		struct count
		{
			post_test_count_no_return_2(-, <)
			post_test_count_with_return_2(-, <)
		};
	};
};

/*
	>:
*/

struct greater_than
{
	loop_no_return_2(-, >)
	loop_with_return_2(-, >)

	struct count
	{
		count_no_return_2(-, >)
		count_with_return_2(-, >)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, >)
		post_test_loop_with_return_2(-, >)

		struct count
		{
			post_test_count_no_return_2(-, >)
			post_test_count_with_return_2(-, >)
		};
	};
};

/*
	<<:
*/

struct left_shift
{
	loop_no_return_2(-, <<)
	loop_with_return_2(-, <<)

	struct count
	{
		count_no_return_2(-, <<)
		count_with_return_2(-, <<)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, <<)
		post_test_loop_with_return_2(-, <<)

		struct count
		{
			post_test_count_no_return_2(-, <<)
			post_test_count_with_return_2(-, <<)
		};
	};
};

/*
	>>:
*/

struct right_shift
{
	loop_no_return_2(-, >>)
	loop_with_return_2(-, >>)

	struct count
	{
		count_no_return_2(-, >>)
		count_with_return_2(-, >>)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, >>)
		post_test_loop_with_return_2(-, >>)

		struct count
		{
			post_test_count_no_return_2(-, >>)
			post_test_count_with_return_2(-, >>)
		};
	};
};

/*
	==:
*/

struct equals
{
	loop_no_return_2(-, ==)
	loop_with_return_2(-, ==)

	struct count
	{
		count_no_return_2(-, ==)
		count_with_return_2(-, ==)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, ==)
		post_test_loop_with_return_2(-, ==)

		struct count
		{
			post_test_count_no_return_2(-, ==)
			post_test_count_with_return_2(-, ==)
		};
	};
};

/*
	!=:
*/

struct not_equals
{
	loop_no_return_2(-, !=)
	loop_with_return_2(-, !=)

	struct count
	{
		count_no_return_2(-, !=)
		count_with_return_2(-, !=)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, !=)
		post_test_loop_with_return_2(-, !=)

		struct count
		{
			post_test_count_no_return_2(-, !=)
			post_test_count_with_return_2(-, !=)
		};
	};
};

/*
	<=:
*/

struct less_than_or_equal
{
	loop_no_return_2(-, <=)
	loop_with_return_2(-, <=)

	struct count
	{
		count_no_return_2(-, <=)
		count_with_return_2(-, <=)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, <=)
		post_test_loop_with_return_2(-, <=)

		struct count
		{
			post_test_count_no_return_2(-, <=)
			post_test_count_with_return_2(-, <=)
		};
	};
};

/*
	>=:
*/

struct greater_than_or_equal
{
	loop_no_return_2(-, >=)
	loop_with_return_2(-, >=)

	struct count
	{
		count_no_return_2(-, >=)
		count_with_return_2(-, >=)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, >=)
		post_test_loop_with_return_2(-, >=)

		struct count
		{
			post_test_count_no_return_2(-, >=)
			post_test_count_with_return_2(-, >=)
		};
	};
};

/*
	&&:
*/

struct logical_and
{
	loop_no_return_2(-, &&)
	loop_with_return_2(-, &&)

	struct count
	{
		count_no_return_2(-, &&)
		count_with_return_2(-, &&)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, &&)
		post_test_loop_with_return_2(-, &&)

		struct count
		{
			post_test_count_no_return_2(-, &&)
			post_test_count_with_return_2(-, &&)
		};
	};
};

/*
	||:
*/

struct logical_or
{
	loop_no_return_2(-, ||)
	loop_with_return_2(-, ||)

	struct count
	{
		count_no_return_2(-, ||)
		count_with_return_2(-, ||)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, ||)
		post_test_loop_with_return_2(-, ||)

		struct count
		{
			post_test_count_no_return_2(-, ||)
			post_test_count_with_return_2(-, ||)
		};
	};
};

/*
	++:
*/

struct left_increment
{
	loop_no_return_left_0(-, ++)

	struct count
	{
		count_no_return_left_0(-, ++)
	};

	struct post_test
	{
		post_test_loop_no_return_left_0(-, ++)

		struct count
		{
			post_test_count_no_return_left_0(-, ++)
		};
	};
};

struct right_increment
{
	loop_no_return_right_0(-, ++)

	struct count
	{
		count_no_return_right_0(-, ++)
	};

	struct post_test
	{
		post_test_loop_no_return_right_0(-, ++)

		struct count
		{
			post_test_count_no_return_right_0(-, ++)
		};
	};
};

/*
	--:
*/

struct left_decrement
{
	loop_no_return_left_0(-, --)

	struct count
	{
		count_no_return_left_0(-, --)
	};

	struct post_test
	{
		post_test_loop_no_return_left_0(-, --)

		struct count
		{
			post_test_count_no_return_left_0(-, --)
		};
	};
};

struct right_decrement
{
	loop_no_return_right_0(-, --)

	struct count
	{
		count_no_return_right_0(-, --)
	};

	struct post_test
	{
		post_test_loop_no_return_right_0(-, --)

		struct count
		{
			post_test_count_no_return_right_0(-, --)
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
	loop_no_return_2(-, ->*)
	loop_with_return_2(-, ->*)

	struct count
	{
		count_no_return_2(-, ->*)
		count_with_return_2(-, ->*)
	};

	struct post_test
	{
		post_test_loop_no_return_2(-, ->*)
		post_test_loop_with_return_2(-, ->*)

		struct count
		{
			post_test_count_no_return_2(-, ->*)
			post_test_count_with_return_2(-, ->*)
		};
	};
};

/*
	->:
*/

struct point
{
	loop_with_return_2(-, .operator->)

	struct count
	{
		count_with_return_2(-, .operator->)
	};

	struct post_test
	{
		post_test_loop_with_return_2(-, .operator->)

		struct count
		{
			post_test_count_with_return_2(-, .operator->)
		};
	};
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	loop_no_return_right_0(-, ())

	loop_no_return_right_1(-, =, ())
	loop_with_return_right_1(-, =, ())

	loop_no_return_2(-, )
	loop_with_return_2(-, )

	struct count
	{
		count_no_return_right_0(-, ())

		count_no_return_right_1(-, =, ())
		count_with_return_right_1(-, =, ())

		count_no_return_2(-, )
		count_with_return_2(-, )
	};

	struct post_test
	{
		post_test_loop_no_return_right_0(-, ())

		post_test_loop_no_return_right_1(-, =, ())
		post_test_loop_with_return_right_1(-, =, ())

		post_test_loop_no_return_2(-, )
		post_test_loop_with_return_2(-, )

		struct count
		{
			post_test_count_no_return_right_0(-, ())

			post_test_count_no_return_right_1(-, =, ())
			post_test_count_with_return_right_1(-, =, ())

			post_test_count_no_return_2(-, )
			post_test_count_with_return_2(-, )
		};
	};
};

/*
	[]:
*/

struct brackets
{
	loop_no_return_brackets_2(-, )
	loop_with_return_brackets_2(-, )

	struct count
	{
		count_no_return_brackets_2(-, )
		count_with_return_brackets_2(-, )
	};

	struct post_test
	{
		post_test_loop_no_return_brackets_2(-, )
		post_test_loop_with_return_brackets_2(-, )

		struct count
		{
			post_test_count_no_return_brackets_2(-, )
			post_test_count_with_return_brackets_2(-, )
		};
	};
};

/*
	=:
*/

struct repeat
{
	loop_no_return_0(-, =)
	loop_with_return_0(-, =)

	struct count
	{
		count_no_return_0(-, =)
		count_with_return_0(-, =)
	};

	struct post_test
	{
		post_test_loop_no_return_0(-, =)
		post_test_loop_with_return_0(-, =)

		struct count
		{
			post_test_count_no_return_0(-, =)
			post_test_count_with_return_0(-, =)
		};
	};
/*
	+=:
*/
	struct plus
	{
		loop_no_return_0(-, +=)

		struct count
		{
			count_no_return_0(-, +=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, +=)

			struct count
			{
				post_test_count_no_return_0(-, +=)
			};
		};
	};
/*
	-=:
*/
	struct minus
	{
		loop_no_return_0(-, -=)

		struct count
		{
			count_no_return_0(-, -=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, -=)

			struct count
			{
				post_test_count_no_return_0(-, -=)
			};
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		loop_no_return_0(-, *=)

		struct count
		{
			count_no_return_0(-, *=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, *=)

			struct count
			{
				post_test_count_no_return_0(-, *=)
			};
		};
	};
/*
	/=:
*/
	struct slash
	{
		loop_no_return_0(-, /=)

		struct count
		{
			count_no_return_0(-, /=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, /=)

			struct count
			{
				post_test_count_no_return_0(-, /=)
			};
		};
	};
/*
	%=:
*/
	struct percent
	{
		loop_no_return_0(-, %=)

		struct count
		{
			count_no_return_0(-, %=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, %=)

			struct count
			{
				post_test_count_no_return_0(-, %=)
			};
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		loop_no_return_0(-, ^=)

		struct count
		{
			count_no_return_0(-, ^=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, ^=)

			struct count
			{
				post_test_count_no_return_0(-, ^=)
			};
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		loop_no_return_0(-, &=)

		struct count
		{
			count_no_return_0(-, &=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, &=)

			struct count
			{
				post_test_count_no_return_0(-, &=)
			};
		};
	};
/*
	|=:
*/
	struct bar
	{
		loop_no_return_0(-, |=)

		struct count
		{
			count_no_return_0(-, |=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, |=)

			struct count
			{
				post_test_count_no_return_0(-, |=)
			};
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		loop_no_return_0(-, >>=)

		struct count
		{
			count_no_return_0(-, >>=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, >>=)

			struct count
			{
				post_test_count_no_return_0(-, >>=)
			};
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		loop_no_return_0(-, <<=)

		struct count
		{
			count_no_return_0(-, <<=)
		};

		struct post_test
		{
			post_test_loop_no_return_0(-, <<=)

			struct count
			{
				post_test_count_no_return_0(-, <<=)
			};
		};
	};
};

/*
	=:
*/

struct assign
{
	loop_no_return_1(-, =)
	loop_with_return_1(-, =)
/*
	Same as above, but additionally counts the length between first and last as a side-effect.
*/
	struct count
	{
		count_no_return_1(-, =)
		count_with_return_1(-, =)
	};

	struct post_test
	{
		post_test_loop_no_return_1(-, =)
		post_test_loop_with_return_1(-, =)
/*
	Same as above, but additionally counts the length between first and last as a side-effect.
*/
		struct count
		{
			post_test_count_no_return_1(-, =)
			post_test_count_with_return_1(-, =)
		};
	};
/*
	+=:
*/
	struct plus
	{
		loop_no_return_1(-, +=)
		loop_with_return_1(-, +=)

		struct count
		{
			count_no_return_1(-, +=)
			count_with_return_1(-, +=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, +=)
			post_test_loop_with_return_1(-, +=)

			struct count
			{
				post_test_count_no_return_1(-, +=)
				post_test_count_with_return_1(-, +=)
			};
		};
	};
/*
	-=:
*/
	struct minus
	{
		loop_no_return_1(-, -=)
		loop_with_return_1(-, -=)

		struct count
		{
			count_no_return_1(-, -=)
			count_with_return_1(-, -=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, -=)
			post_test_loop_with_return_1(-, -=)

			struct count
			{
				post_test_count_no_return_1(-, -=)
				post_test_count_with_return_1(-, -=)
			};
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		loop_no_return_1(-, *=)
		loop_with_return_1(-, *=)

		struct count
		{
			count_no_return_1(-, *=)
			count_with_return_1(-, *=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, *=)
			post_test_loop_with_return_1(-, *=)

			struct count
			{
				post_test_count_no_return_1(-, *=)
				post_test_count_with_return_1(-, *=)
			};
		};
	};
/*
	/=:
*/
	struct slash
	{
		loop_no_return_1(-, /=)
		loop_with_return_1(-, /=)

		struct count
		{
			count_no_return_1(-, /=)
			count_with_return_1(-, /=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, /=)
			post_test_loop_with_return_1(-, /=)

			struct count
			{
				post_test_count_no_return_1(-, /=)
				post_test_count_with_return_1(-, /=)
			};
		};
	};
/*
	%=:
*/
	struct percent
	{
		loop_no_return_1(-, %=)
		loop_with_return_1(-, %=)

		struct count
		{
			count_no_return_1(-, %=)
			count_with_return_1(-, %=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, %=)
			post_test_loop_with_return_1(-, %=)

			struct count
			{
				post_test_count_no_return_1(-, %=)
				post_test_count_with_return_1(-, %=)
			};
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		loop_no_return_1(-, ^=)
		loop_with_return_1(-, ^=)

		struct count
		{
			count_no_return_1(-, ^=)
			count_with_return_1(-, ^=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, ^=)
			post_test_loop_with_return_1(-, ^=)

			struct count
			{
				post_test_count_no_return_1(-, ^=)
				post_test_count_with_return_1(-, ^=)
			};
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		loop_no_return_1(-, &=)
		loop_with_return_1(-, &=)

		struct count
		{
			count_no_return_1(-, &=)
			count_with_return_1(-, &=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, &=)
			post_test_loop_with_return_1(-, &=)

			struct count
			{
				post_test_count_no_return_1(-, &=)
				post_test_count_with_return_1(-, &=)
			};
		};
	};
/*
	|=:
*/
	struct bar
	{
		loop_no_return_1(-, |=)
		loop_with_return_1(-, |=)

		struct count
		{
			count_no_return_1(-, |=)
			count_with_return_1(-, |=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, |=)
			post_test_loop_with_return_1(-, |=)

			struct count
			{
				post_test_count_no_return_1(-, |=)
				post_test_count_with_return_1(-, |=)
			};
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		loop_no_return_1(-, >>=)
		loop_with_return_1(-, >>=)

		struct count
		{
			count_no_return_1(-, >>=)
			count_with_return_1(-, >>=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, >>=)
			post_test_loop_with_return_1(-, >>=)

			struct count
			{
				post_test_count_no_return_1(-, >>=)
				post_test_count_with_return_1(-, >>=)
			};
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		loop_no_return_1(-, <<=)
		loop_with_return_1(-, <<=)

		struct count
		{
			count_no_return_1(-, <<=)
			count_with_return_1(-, <<=)
		};

		struct post_test
		{
			post_test_loop_no_return_1(-, <<=)
			post_test_loop_with_return_1(-, <<=)

			struct count
			{
				post_test_count_no_return_1(-, <<=)
				post_test_count_with_return_1(-, <<=)
			};
		};
	};
};

struct allocate
{
	loop_no_return_new_0(-)
	loop_with_return_new_0(-)

	struct brackets
	{
		loop_no_return_new_brackets_0(-)
		loop_with_return_new_brackets_0(-)

		loop_no_return_new_brackets_1(-)
		loop_with_return_new_brackets_1(-)
	};

	struct count
	{
		count_no_return_new_0(-)
		count_with_return_new_0(-)

		struct brackets
		{
			count_no_return_new_brackets_0(-)
			count_with_return_new_brackets_0(-)

			count_no_return_new_brackets_1(-)
			count_with_return_new_brackets_1(-)
		};
	};

	struct post_test
	{
		post_test_loop_no_return_new_0(-)
		post_test_loop_with_return_new_0(-)

		struct brackets
		{
			post_test_loop_no_return_new_brackets_0(-)
			post_test_loop_with_return_new_brackets_0(-)

			post_test_loop_no_return_new_brackets_1(-)
			post_test_loop_with_return_new_brackets_1(-)
		};

		struct count
		{
			post_test_count_no_return_new_0(-)
			post_test_count_with_return_new_0(-)

			struct brackets
			{
				post_test_count_no_return_new_brackets_0(-)
				post_test_count_with_return_new_brackets_0(-)

				post_test_count_no_return_new_brackets_1(-)
				post_test_count_with_return_new_brackets_1(-)
			};
		};
	};
};

struct deallocate
{
	loop_no_return_delete_0(-)
	loop_with_return_delete_0(-)

	struct brackets
	{
		loop_no_return_delete_brackets_0(-)
		loop_with_return_delete_brackets_0(-)
	};

	struct count
	{
		count_no_return_delete_0(-)
		count_with_return_delete_0(-)

		struct brackets
		{
			count_no_return_delete_brackets_0(-)
			count_with_return_delete_brackets_0(-)
		};
	};

	struct post_test
	{
		post_test_loop_no_return_delete_0(-)
		post_test_loop_with_return_delete_0(-)

		struct brackets
		{
			post_test_loop_no_return_delete_brackets_0(-)
			post_test_loop_with_return_delete_brackets_0(-)
		};

		struct count
		{
			post_test_count_no_return_delete_0(-)
			post_test_count_with_return_delete_0(-)

			struct brackets
			{
				post_test_count_no_return_delete_brackets_0(-)
				post_test_count_with_return_delete_brackets_0(-)
			};
		};
	};
};

