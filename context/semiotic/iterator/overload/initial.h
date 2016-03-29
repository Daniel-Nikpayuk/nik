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
	initial_no_return_1(=+)
	initial_with_return_1(=+)

	initial_no_return_2(+)
	initial_with_return_2(+)

	struct post_test
	{
		post_test_initial_no_return_1(=+)
		post_test_initial_with_return_1(=+)

		post_test_initial_no_return_2(+)
		post_test_initial_with_return_2(+)
	};
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	initial_no_return_1(=-)
	initial_with_return_1(=-)

	initial_no_return_2(-)
	initial_with_return_2(-)

	struct post_test
	{
		post_test_initial_no_return_1(=-)
		post_test_initial_with_return_1(=-)

		post_test_initial_no_return_2(-)
		post_test_initial_with_return_2(-)
	};
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	initial_no_return_1(=*)
	initial_with_return_1(=*)

	initial_no_return_2(*)
	initial_with_return_2(*)

	struct post_test
	{
		post_test_initial_no_return_1(=*)
		post_test_initial_with_return_1(=*)

		post_test_initial_no_return_2(*)
		post_test_initial_with_return_2(*)
	};
};

/*
	/:
*/

struct slash
{
	initial_no_return_2(/)
	initial_with_return_2(/)

	struct post_test
	{
		post_test_initial_no_return_2(/)
		post_test_initial_with_return_2(/)
	};
};

/*
	%:
*/

struct percent
{
	initial_no_return_2(%)
	initial_with_return_2(%)

	struct post_test
	{
		post_test_initial_no_return_2(%)
		post_test_initial_with_return_2(%)
	};
};

/*
	ˆ:
*/

struct caret
{
	initial_no_return_2(^)
	initial_with_return_2(^)

	struct post_test
	{
		post_test_initial_no_return_2(^)
		post_test_initial_with_return_2(^)
	};
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	initial_no_return_1(=&)
	initial_with_return_1(=&)

	initial_no_return_2(&)
	initial_with_return_2(&)

	struct post_test
	{
		post_test_initial_no_return_1(=&)
		post_test_initial_with_return_1(=&)

		post_test_initial_no_return_2(&)
		post_test_initial_with_return_2(&)
	};
};

/*
	|:
*/

struct bar
{
	initial_no_return_2(|)
	initial_with_return_2(|)

	struct post_test
	{
		post_test_initial_no_return_2(|)
		post_test_initial_with_return_2(|)
	};
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	initial_no_return_1(=~)
	initial_with_return_1(=~)

	struct post_test
	{
		post_test_initial_no_return_1(=~)
		post_test_initial_with_return_1(=~)
	};
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	initial_no_return_1(=!)
	initial_with_return_1(=!)

	struct post_test
	{
		post_test_initial_no_return_1(=!)
		post_test_initial_with_return_1(=!)
	};
};

/*
	<:
*/

struct less_than
{
	initial_no_return_2(<)
	initial_with_return_2(<)

	struct post_test
	{
		post_test_initial_no_return_2(<)
		post_test_initial_with_return_2(<)
	};
};

/*
	>:
*/

struct greater_than
{
	initial_no_return_2(>)
	initial_with_return_2(>)

	struct post_test
	{
		post_test_initial_no_return_2(>)
		post_test_initial_with_return_2(>)
	};
};

/*
	<<:
*/

struct left_shift
{
	initial_no_return_2(<<)
	initial_with_return_2(<<)

	struct post_test
	{
		post_test_initial_no_return_2(<<)
		post_test_initial_with_return_2(<<)
	};
};

/*
	>>:
*/

struct right_shift
{
	initial_no_return_2(>>)
	initial_with_return_2(>>)

	struct post_test
	{
		post_test_initial_no_return_2(>>)
		post_test_initial_with_return_2(>>)
	};
};

/*
	==:
*/

struct equals
{
	initial_no_return_2(==)
	initial_with_return_2(==)

	struct post_test
	{
		post_test_initial_no_return_2(==)
		post_test_initial_with_return_2(==)
	};
};

/*
	!=:
*/

struct not_equals
{
	initial_no_return_2(!=)
	initial_with_return_2(!=)

	struct post_test
	{
		post_test_initial_no_return_2(!=)
		post_test_initial_with_return_2(!=)
	};
};

/*
	<=:
*/

struct less_than_or_equal
{
	initial_no_return_2(<=)
	initial_with_return_2(<=)

	struct post_test
	{
		post_test_initial_no_return_2(<=)
		post_test_initial_with_return_2(<=)
	};
};

/*
	>=:
*/

struct greater_than_or_equal
{
	initial_no_return_2(>=)
	initial_with_return_2(>=)

	struct post_test
	{
		post_test_initial_no_return_2(>=)
		post_test_initial_with_return_2(>=)
	};
};

/*
	&&:
*/

struct logical_and
{
	initial_no_return_2(&&)
	initial_with_return_2(&&)

	struct post_test
	{
		post_test_initial_no_return_2(&&)
		post_test_initial_with_return_2(&&)
	};
};

/*
	||:
*/

struct logical_or
{
	initial_no_return_2(||)
	initial_with_return_2(||)

	struct post_test
	{
		post_test_initial_no_return_2(||)
		post_test_initial_with_return_2(||)
	};
};

/*
	++:
*/

struct left_increment
{
	initial_no_return_left_0(++)

	struct post_test
	{
		post_test_initial_no_return_left_0(++)
	};
};

struct right_increment
{
	initial_no_return_right_0(++)

	struct post_test
	{
		post_test_initial_no_return_right_0(++)
	};
};

/*
	--:
*/

struct left_decrement
{
	initial_no_return_left_0(--)

	struct post_test
	{
		post_test_initial_no_return_left_0(--)
	};
};

struct right_decrement
{
	initial_no_return_right_0(--)

	struct post_test
	{
		post_test_initial_no_return_right_0(--)
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
	initial_no_return_2(->*)
	initial_with_return_2(->*)

	struct post_test
	{
		post_test_initial_no_return_2(->*)
		post_test_initial_with_return_2(->*)
	};
};

/*
	->:
*/

struct point
{
	initial_with_return_2(.operator->)

	struct post_test
	{
		post_test_initial_with_return_2(.operator->)
	};
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	initial_no_return_right_0(())

	initial_no_return_right_1(=, ())
	initial_with_return_right_1(=, ())

	initial_no_return_2()
	initial_with_return_2()

	struct post_test
	{
		post_test_initial_no_return_right_0(())

		post_test_initial_no_return_right_1(=, ())
		post_test_initial_with_return_right_1(=, ())

		post_test_initial_no_return_2()
		post_test_initial_with_return_2()
	};
};

/*
	[]:
*/

struct brackets
{
	initial_no_return_brackets_2()
	initial_with_return_brackets_2()

	struct post_test
	{
		post_test_initial_no_return_brackets_2()
		post_test_initial_with_return_brackets_2()
	};
};

/*
	=:
*/

struct repeat
{
	initial_no_return_0(=)
	initial_with_return_0(=)

	struct post_test
	{
		post_test_initial_no_return_0(=)
		post_test_initial_with_return_0(=)
	};
/*
	+=:
*/
	struct plus
	{
		initial_no_return_0(+=)

		struct post_test
		{
			post_test_initial_no_return_0(+=)
		};
	};
/*
	-=:
*/
	struct minus
	{
		initial_no_return_0(-=)

		struct post_test
		{
			post_test_initial_no_return_0(-=)
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		initial_no_return_0(*=)

		struct post_test
		{
			post_test_initial_no_return_0(*=)
		};
	};
/*
	/=:
*/
	struct slash
	{
		initial_no_return_0(/=)

		struct post_test
		{
			post_test_initial_no_return_0(/=)
		};
	};
/*
	%=:
*/
	struct percent
	{
		initial_no_return_0(%=)

		struct post_test
		{
			post_test_initial_no_return_0(%=)
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		initial_no_return_0(^=)

		struct post_test
		{
			post_test_initial_no_return_0(^=)
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		initial_no_return_0(&=)

		struct post_test
		{
			post_test_initial_no_return_0(&=)
		};
	};
/*
	|=:
*/
	struct bar
	{
		initial_no_return_0(|=)

		struct post_test
		{
			post_test_initial_no_return_0(|=)
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		initial_no_return_0(>>=)

		struct post_test
		{
			post_test_initial_no_return_0(>>=)
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		initial_no_return_0(<<=)

		struct post_test
		{
			post_test_initial_no_return_0(<<=)
		};
	};
};

/*
	=:
*/

struct assign
{
	initial_no_return_1(=)
	initial_with_return_1(=)

	struct post_test
	{
		post_test_initial_no_return_1(=)
		post_test_initial_with_return_1(=)
	};
/*
	+=:
*/
	struct plus
	{
		initial_no_return_1(+=)
		initial_with_return_1(+=)

		struct post_test
		{
			post_test_initial_no_return_1(+=)
			post_test_initial_with_return_1(+=)
		};
	};
/*
	-=:
*/
	struct minus
	{
		initial_no_return_1(-=)
		initial_with_return_1(-=)

		struct post_test
		{
			post_test_initial_no_return_1(-=)
			post_test_initial_with_return_1(-=)
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		initial_no_return_1(*=)
		initial_with_return_1(*=)

		struct post_test
		{
			post_test_initial_no_return_1(*=)
			post_test_initial_with_return_1(*=)
		};
	};
/*
	/=:
*/
	struct slash
	{
		initial_no_return_1(/=)
		initial_with_return_1(/=)

		struct post_test
		{
			post_test_initial_no_return_1(/=)
			post_test_initial_with_return_1(/=)
		};
	};
/*
	%=:
*/
	struct percent
	{
		initial_no_return_1(%=)
		initial_with_return_1(%=)

		struct post_test
		{
			post_test_initial_no_return_1(%=)
			post_test_initial_with_return_1(%=)
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		initial_no_return_1(^=)
		initial_with_return_1(^=)

		struct post_test
		{
			post_test_initial_no_return_1(^=)
			post_test_initial_with_return_1(^=)
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		initial_no_return_1(&=)
		initial_with_return_1(&=)

		struct post_test
		{
			post_test_initial_no_return_1(&=)
			post_test_initial_with_return_1(&=)
		};
	};
/*
	|=:
*/
	struct bar
	{
		initial_no_return_1(|=)
		initial_with_return_1(|=)

		struct post_test
		{
			post_test_initial_no_return_1(|=)
			post_test_initial_with_return_1(|=)
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		initial_no_return_1(>>=)
		initial_with_return_1(>>=)

		struct post_test
		{
			post_test_initial_no_return_1(>>=)
			post_test_initial_with_return_1(>>=)
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		initial_no_return_1(<<=)
		initial_with_return_1(<<=)

		struct post_test
		{
			post_test_initial_no_return_1(<<=)
			post_test_initial_with_return_1(<<=)
		};
	};
};

struct allocate
{
	initial_no_return_new_0()
	initial_with_return_new_0()

//	initial_no_return_new_brackets_0()
//	initial_with_return_new_brackets_0()

	struct post_test
	{
		post_test_initial_no_return_new_0()
		post_test_initial_with_return_new_0()

//		post_test_initial_no_return_new_brackets_0()
//		post_test_initial_with_return_new_brackets_0()
	};
};

struct deallocate
{
	initial_no_return_delete_0()
	initial_with_return_delete_0()

//	initial_no_return_delete_brackets_0()
//	initial_with_return_delete_brackets_0()

	struct post_test
	{
		post_test_initial_no_return_delete_0()
		post_test_initial_with_return_delete_0()

//		post_test_initial_no_return_delete_brackets_0()
//		post_test_initial_with_return_delete_brackets_0()
	};
};

