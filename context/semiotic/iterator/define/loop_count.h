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
	closing_loop_no_return_1(SGN, INV, =+)
	closing_loop_with_return_1(SGN, INV, =+)

	closing_loop_no_return_2(SGN, INV, +)
	closing_loop_with_return_2(SGN, INV, +)

	struct count
	{
		closing_count_no_return_1(SGN, INV, =+)
		closing_count_with_return_1(SGN, INV, =+)

		closing_count_no_return_2(SGN, INV, +)
		closing_count_with_return_2(SGN, INV, +)
	};

	struct closed
	{
		closed_loop_no_return_1(SGN, INV, =+)
		closed_loop_with_return_1(SGN, INV, =+)

		closed_loop_no_return_2(SGN, INV, +)
		closed_loop_with_return_2(SGN, INV, +)

		struct count
		{
			closed_count_no_return_1(SGN, INV, =+)
			closed_count_with_return_1(SGN, INV, =+)

			closed_count_no_return_2(SGN, INV, +)
			closed_count_with_return_2(SGN, INV, +)
		};
	};

	struct opening
	{
		opening_loop_no_return_1(SGN, INV, =+)
		opening_loop_with_return_1(SGN, INV, =+)

		opening_loop_no_return_2(SGN, INV, +)
		opening_loop_with_return_2(SGN, INV, +)

		struct count
		{
			opening_count_no_return_1(SGN, INV, =+)
			opening_count_with_return_1(SGN, INV, =+)

			opening_count_no_return_2(SGN, INV, +)
			opening_count_with_return_2(SGN, INV, +)
		};
	};

	struct open
	{
		open_loop_no_return_1(SGN, INV, =+)
		open_loop_with_return_1(SGN, INV, =+)

		open_loop_no_return_2(SGN, INV, +)
		open_loop_with_return_2(SGN, INV, +)

		struct count
		{
			open_count_no_return_1(SGN, INV, =+)
			open_count_with_return_1(SGN, INV, =+)

			open_count_no_return_2(SGN, INV, +)
			open_count_with_return_2(SGN, INV, +)
		};
	};
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	closing_loop_no_return_1(SGN, INV, =-)
	closing_loop_with_return_1(SGN, INV, =-)

	closing_loop_no_return_2(SGN, INV, -)
	closing_loop_with_return_2(SGN, INV, -)

	struct count
	{
		closing_count_no_return_1(SGN, INV, =-)
		closing_count_with_return_1(SGN, INV, =-)

		closing_count_no_return_2(SGN, INV, -)
		closing_count_with_return_2(SGN, INV, -)
	};

	struct closed
	{
		closed_loop_no_return_1(SGN, INV, =-)
		closed_loop_with_return_1(SGN, INV, =-)

		closed_loop_no_return_2(SGN, INV, -)
		closed_loop_with_return_2(SGN, INV, -)

		struct count
		{
			closed_count_no_return_1(SGN, INV, =-)
			closed_count_with_return_1(SGN, INV, =-)

			closed_count_no_return_2(SGN, INV, -)
			closed_count_with_return_2(SGN, INV, -)
		};
	};

	struct opening
	{
		opening_loop_no_return_1(SGN, INV, =-)
		opening_loop_with_return_1(SGN, INV, =-)

		opening_loop_no_return_2(SGN, INV, -)
		opening_loop_with_return_2(SGN, INV, -)

		struct count
		{
			opening_count_no_return_1(SGN, INV, =-)
			opening_count_with_return_1(SGN, INV, =-)

			opening_count_no_return_2(SGN, INV, -)
			opening_count_with_return_2(SGN, INV, -)
		};
	};

	struct open
	{
		open_loop_no_return_1(SGN, INV, =-)
		open_loop_with_return_1(SGN, INV, =-)

		open_loop_no_return_2(SGN, INV, -)
		open_loop_with_return_2(SGN, INV, -)

		struct count
		{
			open_count_no_return_1(SGN, INV, =-)
			open_count_with_return_1(SGN, INV, =-)

			open_count_no_return_2(SGN, INV, -)
			open_count_with_return_2(SGN, INV, -)
		};
	};
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	closing_loop_no_return_1(SGN, INV, =*)
	closing_loop_with_return_1(SGN, INV, =*)

	closing_loop_no_return_2(SGN, INV, *)
	closing_loop_with_return_2(SGN, INV, *)

	struct count
	{
		closing_count_no_return_1(SGN, INV, =*)
		closing_count_with_return_1(SGN, INV, =*)

		closing_count_no_return_2(SGN, INV, *)
		closing_count_with_return_2(SGN, INV, *)
	};

	struct closed
	{
		closed_loop_no_return_1(SGN, INV, =*)
		closed_loop_with_return_1(SGN, INV, =*)

		closed_loop_no_return_2(SGN, INV, *)
		closed_loop_with_return_2(SGN, INV, *)

		struct count
		{
			closed_count_no_return_1(SGN, INV, =*)
			closed_count_with_return_1(SGN, INV, =*)

			closed_count_no_return_2(SGN, INV, *)
			closed_count_with_return_2(SGN, INV, *)
		};
	};

	struct opening
	{
		opening_loop_no_return_1(SGN, INV, =*)
		opening_loop_with_return_1(SGN, INV, =*)

		opening_loop_no_return_2(SGN, INV, *)
		opening_loop_with_return_2(SGN, INV, *)

		struct count
		{
			opening_count_no_return_1(SGN, INV, =*)
			opening_count_with_return_1(SGN, INV, =*)

			opening_count_no_return_2(SGN, INV, *)
			opening_count_with_return_2(SGN, INV, *)
		};
	};

	struct open
	{
		open_loop_no_return_1(SGN, INV, =*)
		open_loop_with_return_1(SGN, INV, =*)

		open_loop_no_return_2(SGN, INV, *)
		open_loop_with_return_2(SGN, INV, *)

		struct count
		{
			open_count_no_return_1(SGN, INV, =*)
			open_count_with_return_1(SGN, INV, =*)

			open_count_no_return_2(SGN, INV, *)
			open_count_with_return_2(SGN, INV, *)
		};
	};
};

/*
	/:
*/

struct slash
{
	closing_loop_no_return_2(SGN, INV, /)
	closing_loop_with_return_2(SGN, INV, /)

	struct count
	{
		closing_count_no_return_2(SGN, INV, /)
		closing_count_with_return_2(SGN, INV, /)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, /)
		closed_loop_with_return_2(SGN, INV, /)

		struct count
		{
			closed_count_no_return_2(SGN, INV, /)
			closed_count_with_return_2(SGN, INV, /)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, /)
		opening_loop_with_return_2(SGN, INV, /)

		struct count
		{
			opening_count_no_return_2(SGN, INV, /)
			opening_count_with_return_2(SGN, INV, /)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, /)
		open_loop_with_return_2(SGN, INV, /)

		struct count
		{
			open_count_no_return_2(SGN, INV, /)
			open_count_with_return_2(SGN, INV, /)
		};
	};
};

/*
	%:
*/

struct percent
{
	closing_loop_no_return_2(SGN, INV, %)
	closing_loop_with_return_2(SGN, INV, %)

	struct count
	{
		closing_count_no_return_2(SGN, INV, %)
		closing_count_with_return_2(SGN, INV, %)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, %)
		closed_loop_with_return_2(SGN, INV, %)

		struct count
		{
			closed_count_no_return_2(SGN, INV, %)
			closed_count_with_return_2(SGN, INV, %)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, %)
		opening_loop_with_return_2(SGN, INV, %)

		struct count
		{
			opening_count_no_return_2(SGN, INV, %)
			opening_count_with_return_2(SGN, INV, %)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, %)
		open_loop_with_return_2(SGN, INV, %)

		struct count
		{
			open_count_no_return_2(SGN, INV, %)
			open_count_with_return_2(SGN, INV, %)
		};
	};
};

/*
	ˆ:
*/

struct caret
{
	closing_loop_no_return_2(SGN, INV, ^)
	closing_loop_with_return_2(SGN, INV, ^)

	struct count
	{
		closing_count_no_return_2(SGN, INV, ^)
		closing_count_with_return_2(SGN, INV, ^)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, ^)
		closed_loop_with_return_2(SGN, INV, ^)

		struct count
		{
			closed_count_no_return_2(SGN, INV, ^)
			closed_count_with_return_2(SGN, INV, ^)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, ^)
		opening_loop_with_return_2(SGN, INV, ^)

		struct count
		{
			opening_count_no_return_2(SGN, INV, ^)
			opening_count_with_return_2(SGN, INV, ^)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, ^)
		open_loop_with_return_2(SGN, INV, ^)

		struct count
		{
			open_count_no_return_2(SGN, INV, ^)
			open_count_with_return_2(SGN, INV, ^)
		};
	};
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	closing_loop_no_return_1(SGN, INV, =&)
	closing_loop_with_return_1(SGN, INV, =&)

	closing_loop_no_return_2(SGN, INV, &)
	closing_loop_with_return_2(SGN, INV, &)

	struct count
	{
		closing_count_no_return_1(SGN, INV, =&)
		closing_count_with_return_1(SGN, INV, =&)

		closing_count_no_return_2(SGN, INV, &)
		closing_count_with_return_2(SGN, INV, &)
	};

	struct closed
	{
		closed_loop_no_return_1(SGN, INV, =&)
		closed_loop_with_return_1(SGN, INV, =&)

		closed_loop_no_return_2(SGN, INV, &)
		closed_loop_with_return_2(SGN, INV, &)

		struct count
		{
			closed_count_no_return_1(SGN, INV, =&)
			closed_count_with_return_1(SGN, INV, =&)

			closed_count_no_return_2(SGN, INV, &)
			closed_count_with_return_2(SGN, INV, &)
		};
	};

	struct opening
	{
		opening_loop_no_return_1(SGN, INV, =&)
		opening_loop_with_return_1(SGN, INV, =&)

		opening_loop_no_return_2(SGN, INV, &)
		opening_loop_with_return_2(SGN, INV, &)

		struct count
		{
			opening_count_no_return_1(SGN, INV, =&)
			opening_count_with_return_1(SGN, INV, =&)

			opening_count_no_return_2(SGN, INV, &)
			opening_count_with_return_2(SGN, INV, &)
		};
	};

	struct open
	{
		open_loop_no_return_1(SGN, INV, =&)
		open_loop_with_return_1(SGN, INV, =&)

		open_loop_no_return_2(SGN, INV, &)
		open_loop_with_return_2(SGN, INV, &)

		struct count
		{
			open_count_no_return_1(SGN, INV, =&)
			open_count_with_return_1(SGN, INV, =&)

			open_count_no_return_2(SGN, INV, &)
			open_count_with_return_2(SGN, INV, &)
		};
	};
};

/*
	|:
*/

struct bar
{
	closing_loop_no_return_2(SGN, INV, |)
	closing_loop_with_return_2(SGN, INV, |)

	struct count
	{
		closing_count_no_return_2(SGN, INV, |)
		closing_count_with_return_2(SGN, INV, |)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, |)
		closed_loop_with_return_2(SGN, INV, |)

		struct count
		{
			closed_count_no_return_2(SGN, INV, |)
			closed_count_with_return_2(SGN, INV, |)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, |)
		opening_loop_with_return_2(SGN, INV, |)

		struct count
		{
			opening_count_no_return_2(SGN, INV, |)
			opening_count_with_return_2(SGN, INV, |)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, |)
		open_loop_with_return_2(SGN, INV, |)

		struct count
		{
			open_count_no_return_2(SGN, INV, |)
			open_count_with_return_2(SGN, INV, |)
		};
	};
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	closing_loop_no_return_1(SGN, INV, =~)
	closing_loop_with_return_1(SGN, INV, =~)

	struct count
	{
		closing_count_no_return_1(SGN, INV, =~)
		closing_count_with_return_1(SGN, INV, =~)
	};

	struct closed
	{
		closed_loop_no_return_1(SGN, INV, =~)
		closed_loop_with_return_1(SGN, INV, =~)

		struct count
		{
			closed_count_no_return_1(SGN, INV, =~)
			closed_count_with_return_1(SGN, INV, =~)
		};
	};

	struct opening
	{
		opening_loop_no_return_1(SGN, INV, =~)
		opening_loop_with_return_1(SGN, INV, =~)

		struct count
		{
			opening_count_no_return_1(SGN, INV, =~)
			opening_count_with_return_1(SGN, INV, =~)
		};
	};

	struct open
	{
		open_loop_no_return_1(SGN, INV, =~)
		open_loop_with_return_1(SGN, INV, =~)

		struct count
		{
			open_count_no_return_1(SGN, INV, =~)
			open_count_with_return_1(SGN, INV, =~)
		};
	};
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	closing_loop_no_return_1(SGN, INV, =!)
	closing_loop_with_return_1(SGN, INV, =!)

	struct count
	{
		closing_count_no_return_1(SGN, INV, =!)
		closing_count_with_return_1(SGN, INV, =!)
	};

	struct closed
	{
		closed_loop_no_return_1(SGN, INV, =!)
		closed_loop_with_return_1(SGN, INV, =!)

		struct count
		{
			closed_count_no_return_1(SGN, INV, =!)
			closed_count_with_return_1(SGN, INV, =!)
		};
	};

	struct opening
	{
		opening_loop_no_return_1(SGN, INV, =!)
		opening_loop_with_return_1(SGN, INV, =!)

		struct count
		{
			opening_count_no_return_1(SGN, INV, =!)
			opening_count_with_return_1(SGN, INV, =!)
		};
	};

	struct open
	{
		open_loop_no_return_1(SGN, INV, =!)
		open_loop_with_return_1(SGN, INV, =!)

		struct count
		{
			open_count_no_return_1(SGN, INV, =!)
			open_count_with_return_1(SGN, INV, =!)
		};
	};
};

/*
	<:
*/

struct less_than
{
	closing_loop_no_return_2(SGN, INV, <)
	closing_loop_with_return_2(SGN, INV, <)

	struct count
	{
		closing_count_no_return_2(SGN, INV, <)
		closing_count_with_return_2(SGN, INV, <)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, <)
		closed_loop_with_return_2(SGN, INV, <)

		struct count
		{
			closed_count_no_return_2(SGN, INV, <)
			closed_count_with_return_2(SGN, INV, <)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, <)
		opening_loop_with_return_2(SGN, INV, <)

		struct count
		{
			opening_count_no_return_2(SGN, INV, <)
			opening_count_with_return_2(SGN, INV, <)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, <)
		open_loop_with_return_2(SGN, INV, <)

		struct count
		{
			open_count_no_return_2(SGN, INV, <)
			open_count_with_return_2(SGN, INV, <)
		};
	};
};

/*
	>:
*/

struct greater_than
{
	closing_loop_no_return_2(SGN, INV, >)
	closing_loop_with_return_2(SGN, INV, >)

	struct count
	{
		closing_count_no_return_2(SGN, INV, >)
		closing_count_with_return_2(SGN, INV, >)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, >)
		closed_loop_with_return_2(SGN, INV, >)

		struct count
		{
			closed_count_no_return_2(SGN, INV, >)
			closed_count_with_return_2(SGN, INV, >)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, >)
		opening_loop_with_return_2(SGN, INV, >)

		struct count
		{
			opening_count_no_return_2(SGN, INV, >)
			opening_count_with_return_2(SGN, INV, >)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, >)
		open_loop_with_return_2(SGN, INV, >)

		struct count
		{
			open_count_no_return_2(SGN, INV, >)
			open_count_with_return_2(SGN, INV, >)
		};
	};
};

/*
	<<:
*/

struct left_shift
{
	closing_loop_no_return_2(SGN, INV, <<)
	closing_loop_with_return_2(SGN, INV, <<)

	struct count
	{
		closing_count_no_return_2(SGN, INV, <<)
		closing_count_with_return_2(SGN, INV, <<)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, <<)
		closed_loop_with_return_2(SGN, INV, <<)

		struct count
		{
			closed_count_no_return_2(SGN, INV, <<)
			closed_count_with_return_2(SGN, INV, <<)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, <<)
		opening_loop_with_return_2(SGN, INV, <<)

		struct count
		{
			opening_count_no_return_2(SGN, INV, <<)
			opening_count_with_return_2(SGN, INV, <<)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, <<)
		open_loop_with_return_2(SGN, INV, <<)

		struct count
		{
			open_count_no_return_2(SGN, INV, <<)
			open_count_with_return_2(SGN, INV, <<)
		};
	};
};

/*
	>>:
*/

struct right_shift
{
	closing_loop_no_return_2(SGN, INV, >>)
	closing_loop_with_return_2(SGN, INV, >>)

	struct count
	{
		closing_count_no_return_2(SGN, INV, >>)
		closing_count_with_return_2(SGN, INV, >>)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, >>)
		closed_loop_with_return_2(SGN, INV, >>)

		struct count
		{
			closed_count_no_return_2(SGN, INV, >>)
			closed_count_with_return_2(SGN, INV, >>)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, >>)
		opening_loop_with_return_2(SGN, INV, >>)

		struct count
		{
			opening_count_no_return_2(SGN, INV, >>)
			opening_count_with_return_2(SGN, INV, >>)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, >>)
		open_loop_with_return_2(SGN, INV, >>)

		struct count
		{
			open_count_no_return_2(SGN, INV, >>)
			open_count_with_return_2(SGN, INV, >>)
		};
	};
};

/*
	==:
*/

struct equals
{
	closing_loop_no_return_2(SGN, INV, ==)
	closing_loop_with_return_2(SGN, INV, ==)

	struct count
	{
		closing_count_no_return_2(SGN, INV, ==)
		closing_count_with_return_2(SGN, INV, ==)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, ==)
		closed_loop_with_return_2(SGN, INV, ==)

		struct count
		{
			closed_count_no_return_2(SGN, INV, ==)
			closed_count_with_return_2(SGN, INV, ==)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, ==)
		opening_loop_with_return_2(SGN, INV, ==)

		struct count
		{
			opening_count_no_return_2(SGN, INV, ==)
			opening_count_with_return_2(SGN, INV, ==)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, ==)
		open_loop_with_return_2(SGN, INV, ==)

		struct count
		{
			open_count_no_return_2(SGN, INV, ==)
			open_count_with_return_2(SGN, INV, ==)
		};
	};
};

/*
	!=:
*/

struct not_equals
{
	closing_loop_no_return_2(SGN, INV, !=)
	closing_loop_with_return_2(SGN, INV, !=)

	struct count
	{
		closing_count_no_return_2(SGN, INV, !=)
		closing_count_with_return_2(SGN, INV, !=)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, !=)
		closed_loop_with_return_2(SGN, INV, !=)

		struct count
		{
			closed_count_no_return_2(SGN, INV, !=)
			closed_count_with_return_2(SGN, INV, !=)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, !=)
		opening_loop_with_return_2(SGN, INV, !=)

		struct count
		{
			opening_count_no_return_2(SGN, INV, !=)
			opening_count_with_return_2(SGN, INV, !=)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, !=)
		open_loop_with_return_2(SGN, INV, !=)

		struct count
		{
			open_count_no_return_2(SGN, INV, !=)
			open_count_with_return_2(SGN, INV, !=)
		};
	};
};

/*
	<=:
*/

struct less_than_or_equal
{
	closing_loop_no_return_2(SGN, INV, <=)
	closing_loop_with_return_2(SGN, INV, <=)

	struct count
	{
		closing_count_no_return_2(SGN, INV, <=)
		closing_count_with_return_2(SGN, INV, <=)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, <=)
		closed_loop_with_return_2(SGN, INV, <=)

		struct count
		{
			closed_count_no_return_2(SGN, INV, <=)
			closed_count_with_return_2(SGN, INV, <=)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, <=)
		opening_loop_with_return_2(SGN, INV, <=)

		struct count
		{
			opening_count_no_return_2(SGN, INV, <=)
			opening_count_with_return_2(SGN, INV, <=)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, <=)
		open_loop_with_return_2(SGN, INV, <=)

		struct count
		{
			open_count_no_return_2(SGN, INV, <=)
			open_count_with_return_2(SGN, INV, <=)
		};
	};
};

/*
	>=:
*/

struct greater_than_or_equal
{
	closing_loop_no_return_2(SGN, INV, >=)
	closing_loop_with_return_2(SGN, INV, >=)

	struct count
	{
		closing_count_no_return_2(SGN, INV, >=)
		closing_count_with_return_2(SGN, INV, >=)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, >=)
		closed_loop_with_return_2(SGN, INV, >=)

		struct count
		{
			closed_count_no_return_2(SGN, INV, >=)
			closed_count_with_return_2(SGN, INV, >=)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, >=)
		opening_loop_with_return_2(SGN, INV, >=)

		struct count
		{
			opening_count_no_return_2(SGN, INV, >=)
			opening_count_with_return_2(SGN, INV, >=)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, >=)
		open_loop_with_return_2(SGN, INV, >=)

		struct count
		{
			open_count_no_return_2(SGN, INV, >=)
			open_count_with_return_2(SGN, INV, >=)
		};
	};
};

/*
	&&:
*/

struct logical_and
{
	closing_loop_no_return_2(SGN, INV, &&)
	closing_loop_with_return_2(SGN, INV, &&)

	struct count
	{
		closing_count_no_return_2(SGN, INV, &&)
		closing_count_with_return_2(SGN, INV, &&)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, &&)
		closed_loop_with_return_2(SGN, INV, &&)

		struct count
		{
			closed_count_no_return_2(SGN, INV, &&)
			closed_count_with_return_2(SGN, INV, &&)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, &&)
		opening_loop_with_return_2(SGN, INV, &&)

		struct count
		{
			opening_count_no_return_2(SGN, INV, &&)
			opening_count_with_return_2(SGN, INV, &&)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, &&)
		open_loop_with_return_2(SGN, INV, &&)

		struct count
		{
			open_count_no_return_2(SGN, INV, &&)
			open_count_with_return_2(SGN, INV, &&)
		};
	};
};

/*
	||:
*/

struct logical_or
{
	closing_loop_no_return_2(SGN, INV, ||)
	closing_loop_with_return_2(SGN, INV, ||)

	struct count
	{
		closing_count_no_return_2(SGN, INV, ||)
		closing_count_with_return_2(SGN, INV, ||)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, ||)
		closed_loop_with_return_2(SGN, INV, ||)

		struct count
		{
			closed_count_no_return_2(SGN, INV, ||)
			closed_count_with_return_2(SGN, INV, ||)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, ||)
		opening_loop_with_return_2(SGN, INV, ||)

		struct count
		{
			opening_count_no_return_2(SGN, INV, ||)
			opening_count_with_return_2(SGN, INV, ||)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, ||)
		open_loop_with_return_2(SGN, INV, ||)

		struct count
		{
			open_count_no_return_2(SGN, INV, ||)
			open_count_with_return_2(SGN, INV, ||)
		};
	};
};

/*
	++:
*/

struct left_increment
{
	closing_loop_no_return_left_0(SGN, INV, ++)

	struct count
	{
		closing_count_no_return_left_0(SGN, INV, ++)
	};

	struct closed
	{
		closed_loop_no_return_left_0(SGN, INV, ++)

		struct count
		{
			closed_count_no_return_left_0(SGN, INV, ++)
		};
	};

	struct opening
	{
		opening_loop_no_return_left_0(SGN, INV, ++)

		struct count
		{
			opening_count_no_return_left_0(SGN, INV, ++)
		};
	};

	struct open
	{
		open_loop_no_return_left_0(SGN, INV, ++)

		struct count
		{
			open_count_no_return_left_0(SGN, INV, ++)
		};
	};
};

struct right_increment
{
	closing_loop_no_return_right_0(SGN, INV, ++)

	struct count
	{
		closing_count_no_return_right_0(SGN, INV, ++)
	};

	struct closed
	{
		closed_loop_no_return_right_0(SGN, INV, ++)

		struct count
		{
			closed_count_no_return_right_0(SGN, INV, ++)
		};
	};

	struct opening
	{
		opening_loop_no_return_right_0(SGN, INV, ++)

		struct count
		{
			opening_count_no_return_right_0(SGN, INV, ++)
		};
	};

	struct open
	{
		open_loop_no_return_right_0(SGN, INV, ++)

		struct count
		{
			open_count_no_return_right_0(SGN, INV, ++)
		};
	};
};

/*
	--:
*/

struct left_decrement
{
	closing_loop_no_return_left_0(SGN, INV, --)

	struct count
	{
		closing_count_no_return_left_0(SGN, INV, --)
	};

	struct closed
	{
		closed_loop_no_return_left_0(SGN, INV, --)

		struct count
		{
			closed_count_no_return_left_0(SGN, INV, --)
		};
	};

	struct opening
	{
		opening_loop_no_return_left_0(SGN, INV, --)

		struct count
		{
			opening_count_no_return_left_0(SGN, INV, --)
		};
	};

	struct open
	{
		open_loop_no_return_left_0(SGN, INV, --)

		struct count
		{
			open_count_no_return_left_0(SGN, INV, --)
		};
	};
};

struct right_decrement
{
	closing_loop_no_return_right_0(SGN, INV, --)

	struct count
	{
		closing_count_no_return_right_0(SGN, INV, --)
	};

	struct closed
	{
		closed_loop_no_return_right_0(SGN, INV, --)

		struct count
		{
			closed_count_no_return_right_0(SGN, INV, --)
		};
	};

	struct opening
	{
		opening_loop_no_return_right_0(SGN, INV, --)

		struct count
		{
			opening_count_no_return_right_0(SGN, INV, --)
		};
	};

	struct open
	{
		open_loop_no_return_right_0(SGN, INV, --)

		struct count
		{
			open_count_no_return_right_0(SGN, INV, --)
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

	struct closed
	{
		struct count
		{
		};
	};

	struct opening
	{
		struct count
		{
		};
	};

	struct open
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
	closing_loop_no_return_2(SGN, INV, ->*)
	closing_loop_with_return_2(SGN, INV, ->*)

	struct count
	{
		closing_count_no_return_2(SGN, INV, ->*)
		closing_count_with_return_2(SGN, INV, ->*)
	};

	struct closed
	{
		closed_loop_no_return_2(SGN, INV, ->*)
		closed_loop_with_return_2(SGN, INV, ->*)

		struct count
		{
			closed_count_no_return_2(SGN, INV, ->*)
			closed_count_with_return_2(SGN, INV, ->*)
		};
	};

	struct opening
	{
		opening_loop_no_return_2(SGN, INV, ->*)
		opening_loop_with_return_2(SGN, INV, ->*)

		struct count
		{
			opening_count_no_return_2(SGN, INV, ->*)
			opening_count_with_return_2(SGN, INV, ->*)
		};
	};

	struct open
	{
		open_loop_no_return_2(SGN, INV, ->*)
		open_loop_with_return_2(SGN, INV, ->*)

		struct count
		{
			open_count_no_return_2(SGN, INV, ->*)
			open_count_with_return_2(SGN, INV, ->*)
		};
	};
};

/*
	->:
*/

struct point
{
	closing_loop_with_return_2(SGN, INV, .operator->)

	struct count
	{
		closing_count_with_return_2(SGN, INV, .operator->)
	};

	struct closed
	{
		closed_loop_with_return_2(SGN, INV, .operator->)

		struct count
		{
			closed_count_with_return_2(SGN, INV, .operator->)
		};
	};

	struct opening
	{
		opening_loop_with_return_2(SGN, INV, .operator->)

		struct count
		{
			opening_count_with_return_2(SGN, INV, .operator->)
		};
	};

	struct open
	{
		open_loop_with_return_2(SGN, INV, .operator->)

		struct count
		{
			open_count_with_return_2(SGN, INV, .operator->)
		};
	};
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	closing_loop_no_return_right_0(SGN, INV, ())

	closing_loop_no_return_right_1(SGN, INV, =, ())
	closing_loop_with_return_right_1(SGN, INV, =, ())

	closing_loop_no_return_2(SGN, INV, )
	closing_loop_with_return_2(SGN, INV, )

	struct count
	{
		closing_count_no_return_right_0(SGN, INV, ())

		closing_count_no_return_right_1(SGN, INV, =, ())
		closing_count_with_return_right_1(SGN, INV, =, ())

		closing_count_no_return_2(SGN, INV, )
		closing_count_with_return_2(SGN, INV, )
	};

	struct closed
	{
		closed_loop_no_return_right_0(SGN, INV, ())

		closed_loop_no_return_right_1(SGN, INV, =, ())
		closed_loop_with_return_right_1(SGN, INV, =, ())

		closed_loop_no_return_2(SGN, INV, )
		closed_loop_with_return_2(SGN, INV, )

		struct count
		{
			closed_count_no_return_right_0(SGN, INV, ())

			closed_count_no_return_right_1(SGN, INV, =, ())
			closed_count_with_return_right_1(SGN, INV, =, ())

			closed_count_no_return_2(SGN, INV, )
			closed_count_with_return_2(SGN, INV, )
		};
	};

	struct opening
	{
		opening_loop_no_return_right_0(SGN, INV, ())

		opening_loop_no_return_right_1(SGN, INV, =, ())
		opening_loop_with_return_right_1(SGN, INV, =, ())

		opening_loop_no_return_2(SGN, INV, )
		opening_loop_with_return_2(SGN, INV, )

		struct count
		{
			opening_count_no_return_right_0(SGN, INV, ())

			opening_count_no_return_right_1(SGN, INV, =, ())
			opening_count_with_return_right_1(SGN, INV, =, ())

			opening_count_no_return_2(SGN, INV, )
			opening_count_with_return_2(SGN, INV, )
		};
	};

	struct open
	{
		open_loop_no_return_right_0(SGN, INV, ())

		open_loop_no_return_right_1(SGN, INV, =, ())
		open_loop_with_return_right_1(SGN, INV, =, ())

		open_loop_no_return_2(SGN, INV, )
		open_loop_with_return_2(SGN, INV, )

		struct count
		{
			open_count_no_return_right_0(SGN, INV, ())

			open_count_no_return_right_1(SGN, INV, =, ())
			open_count_with_return_right_1(SGN, INV, =, ())

			open_count_no_return_2(SGN, INV, )
			open_count_with_return_2(SGN, INV, )
		};
	};
};

/*
	[]:
*/

struct brackets
{
	closing_loop_no_return_brackets_2(SGN, INV, )
	closing_loop_with_return_brackets_2(SGN, INV, )

	struct count
	{
		closing_count_no_return_brackets_2(SGN, INV, )
		closing_count_with_return_brackets_2(SGN, INV, )
	};

	struct closed
	{
		closed_loop_no_return_brackets_2(SGN, INV, )
		closed_loop_with_return_brackets_2(SGN, INV, )

		struct count
		{
			closed_count_no_return_brackets_2(SGN, INV, )
			closed_count_with_return_brackets_2(SGN, INV, )
		};
	};

	struct opening
	{
		opening_loop_no_return_brackets_2(SGN, INV, )
		opening_loop_with_return_brackets_2(SGN, INV, )

		struct count
		{
			opening_count_no_return_brackets_2(SGN, INV, )
			opening_count_with_return_brackets_2(SGN, INV, )
		};
	};

	struct open
	{
		open_loop_no_return_brackets_2(SGN, INV, )
		open_loop_with_return_brackets_2(SGN, INV, )

		struct count
		{
			open_count_no_return_brackets_2(SGN, INV, )
			open_count_with_return_brackets_2(SGN, INV, )
		};
	};
};

/*
	=:
*/

struct repeat
{
	closing_loop_no_return_0(SGN, INV, =)
	closing_loop_with_return_0(SGN, INV, =)

	struct count
	{
		closing_count_no_return_0(SGN, INV, =)
		closing_count_with_return_0(SGN, INV, =)
	};

	struct closed
	{
		closed_loop_no_return_0(SGN, INV, =)
		closed_loop_with_return_0(SGN, INV, =)

		struct count
		{
			closed_count_no_return_0(SGN, INV, =)
			closed_count_with_return_0(SGN, INV, =)
		};
	};

	struct opening
	{
		opening_loop_no_return_0(SGN, INV, =)
		opening_loop_with_return_0(SGN, INV, =)

		struct count
		{
			opening_count_no_return_0(SGN, INV, =)
			opening_count_with_return_0(SGN, INV, =)
		};
	};

	struct open
	{
		open_loop_no_return_0(SGN, INV, =)
		open_loop_with_return_0(SGN, INV, =)

		struct count
		{
			open_count_no_return_0(SGN, INV, =)
			open_count_with_return_0(SGN, INV, =)
		};
	};
/*
	+=:
*/
	struct plus
	{
		closing_loop_no_return_0(SGN, INV, +=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, +=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, +=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, +=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, +=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, +=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, +=)

			struct count
			{
				open_count_no_return_0(SGN, INV, +=)
			};
		};
	};
/*
	-=:
*/
	struct minus
	{
		closing_loop_no_return_0(SGN, INV, -=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, -=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, -=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, -=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, -=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, -=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, -=)

			struct count
			{
				open_count_no_return_0(SGN, INV, -=)
			};
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		closing_loop_no_return_0(SGN, INV, *=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, *=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, *=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, *=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, *=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, *=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, *=)

			struct count
			{
				open_count_no_return_0(SGN, INV, *=)
			};
		};
	};
/*
	/=:
*/
	struct slash
	{
		closing_loop_no_return_0(SGN, INV, /=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, /=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, /=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, /=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, /=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, /=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, /=)

			struct count
			{
				open_count_no_return_0(SGN, INV, /=)
			};
		};
	};
/*
	%=:
*/
	struct percent
	{
		closing_loop_no_return_0(SGN, INV, %=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, %=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, %=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, %=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, %=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, %=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, %=)

			struct count
			{
				open_count_no_return_0(SGN, INV, %=)
			};
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		closing_loop_no_return_0(SGN, INV, ^=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, ^=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, ^=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, ^=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, ^=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, ^=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, ^=)

			struct count
			{
				open_count_no_return_0(SGN, INV, ^=)
			};
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		closing_loop_no_return_0(SGN, INV, &=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, &=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, &=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, &=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, &=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, &=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, &=)

			struct count
			{
				open_count_no_return_0(SGN, INV, &=)
			};
		};
	};
/*
	|=:
*/
	struct bar
	{
		closing_loop_no_return_0(SGN, INV, |=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, |=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, |=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, |=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, |=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, |=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, |=)

			struct count
			{
				open_count_no_return_0(SGN, INV, |=)
			};
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		closing_loop_no_return_0(SGN, INV, >>=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, >>=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, >>=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, >>=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, >>=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, >>=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, >>=)

			struct count
			{
				open_count_no_return_0(SGN, INV, >>=)
			};
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		closing_loop_no_return_0(SGN, INV, <<=)

		struct count
		{
			closing_count_no_return_0(SGN, INV, <<=)
		};

		struct closed
		{
			closed_loop_no_return_0(SGN, INV, <<=)

			struct count
			{
				closed_count_no_return_0(SGN, INV, <<=)
			};
		};

		struct opening
		{
			opening_loop_no_return_0(SGN, INV, <<=)

			struct count
			{
				opening_count_no_return_0(SGN, INV, <<=)
			};
		};

		struct open
		{
			open_loop_no_return_0(SGN, INV, <<=)

			struct count
			{
				open_count_no_return_0(SGN, INV, <<=)
			};
		};
	};
};

/*
	=:
*/

struct assign
{
	closing_loop_no_return_1(SGN, INV, =)
	closing_loop_with_return_1(SGN, INV, =)
/*
	Same as above, but additionally counts the length between first and last as a side-effect.
*/
	struct count
	{
		closing_count_no_return_1(SGN, INV, =)
		closing_count_with_return_1(SGN, INV, =)
	};

	struct closed
	{
		closed_loop_no_return_1(SGN, INV, =)
		closed_loop_with_return_1(SGN, INV, =)
/*
	Same as above, but additionally counts the length between first and last as a side-effect.
*/
		struct count
		{
			closed_count_no_return_1(SGN, INV, =)
			closed_count_with_return_1(SGN, INV, =)
		};
	};

	struct opening
	{
		opening_loop_no_return_1(SGN, INV, =)
		opening_loop_with_return_1(SGN, INV, =)
/*
	Same as openingditionally counts the length between first and last as a side-effect.
*/
		struct count
		{
			opening_count_no_return_1(SGN, INV, =)
			opening_count_with_return_1(SGN, INV, =)
		};
	};

	struct open
	{
		open_loop_no_return_1(SGN, INV, =)
		open_loop_with_return_1(SGN, INV, =)
/*
	Same as openditionally counts the length between first and last as a side-effect.
*/
		struct count
		{
			open_count_no_return_1(SGN, INV, =)
			open_count_with_return_1(SGN, INV, =)
		};
	};
/*
	+=:
*/
	struct plus
	{
		closing_loop_no_return_1(SGN, INV, +=)
		closing_loop_with_return_1(SGN, INV, +=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, +=)
			closing_count_with_return_1(SGN, INV, +=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, +=)
			closed_loop_with_return_1(SGN, INV, +=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, +=)
				closed_count_with_return_1(SGN, INV, +=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, +=)
			opening_loop_with_return_1(SGN, INV, +=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, +=)
				opening_count_with_return_1(SGN, INV, +=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, +=)
			open_loop_with_return_1(SGN, INV, +=)

			struct count
			{
				open_count_no_return_1(SGN, INV, +=)
				open_count_with_return_1(SGN, INV, +=)
			};
		};
	};
/*
	-=:
*/
	struct minus
	{
		closing_loop_no_return_1(SGN, INV, -=)
		closing_loop_with_return_1(SGN, INV, -=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, -=)
			closing_count_with_return_1(SGN, INV, -=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, -=)
			closed_loop_with_return_1(SGN, INV, -=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, -=)
				closed_count_with_return_1(SGN, INV, -=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, -=)
			opening_loop_with_return_1(SGN, INV, -=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, -=)
				opening_count_with_return_1(SGN, INV, -=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, -=)
			open_loop_with_return_1(SGN, INV, -=)

			struct count
			{
				open_count_no_return_1(SGN, INV, -=)
				open_count_with_return_1(SGN, INV, -=)
			};
		};
	};
/*
	*=:
*/
	struct asterisk
	{
		closing_loop_no_return_1(SGN, INV, *=)
		closing_loop_with_return_1(SGN, INV, *=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, *=)
			closing_count_with_return_1(SGN, INV, *=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, *=)
			closed_loop_with_return_1(SGN, INV, *=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, *=)
				closed_count_with_return_1(SGN, INV, *=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, *=)
			opening_loop_with_return_1(SGN, INV, *=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, *=)
				opening_count_with_return_1(SGN, INV, *=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, *=)
			open_loop_with_return_1(SGN, INV, *=)

			struct count
			{
				open_count_no_return_1(SGN, INV, *=)
				open_count_with_return_1(SGN, INV, *=)
			};
		};
	};
/*
	/=:
*/
	struct slash
	{
		closing_loop_no_return_1(SGN, INV, /=)
		closing_loop_with_return_1(SGN, INV, /=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, /=)
			closing_count_with_return_1(SGN, INV, /=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, /=)
			closed_loop_with_return_1(SGN, INV, /=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, /=)
				closed_count_with_return_1(SGN, INV, /=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, /=)
			opening_loop_with_return_1(SGN, INV, /=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, /=)
				opening_count_with_return_1(SGN, INV, /=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, /=)
			open_loop_with_return_1(SGN, INV, /=)

			struct count
			{
				open_count_no_return_1(SGN, INV, /=)
				open_count_with_return_1(SGN, INV, /=)
			};
		};
	};
/*
	%=:
*/
	struct percent
	{
		closing_loop_no_return_1(SGN, INV, %=)
		closing_loop_with_return_1(SGN, INV, %=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, %=)
			closing_count_with_return_1(SGN, INV, %=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, %=)
			closed_loop_with_return_1(SGN, INV, %=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, %=)
				closed_count_with_return_1(SGN, INV, %=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, %=)
			opening_loop_with_return_1(SGN, INV, %=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, %=)
				opening_count_with_return_1(SGN, INV, %=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, %=)
			open_loop_with_return_1(SGN, INV, %=)

			struct count
			{
				open_count_no_return_1(SGN, INV, %=)
				open_count_with_return_1(SGN, INV, %=)
			};
		};
	};
/*
	ˆ=:
*/
	struct caret
	{
		closing_loop_no_return_1(SGN, INV, ^=)
		closing_loop_with_return_1(SGN, INV, ^=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, ^=)
			closing_count_with_return_1(SGN, INV, ^=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, ^=)
			closed_loop_with_return_1(SGN, INV, ^=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, ^=)
				closed_count_with_return_1(SGN, INV, ^=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, ^=)
			opening_loop_with_return_1(SGN, INV, ^=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, ^=)
				opening_count_with_return_1(SGN, INV, ^=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, ^=)
			open_loop_with_return_1(SGN, INV, ^=)

			struct count
			{
				open_count_no_return_1(SGN, INV, ^=)
				open_count_with_return_1(SGN, INV, ^=)
			};
		};
	};
/*
	&=:
*/
	struct ampersand
	{
		closing_loop_no_return_1(SGN, INV, &=)
		closing_loop_with_return_1(SGN, INV, &=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, &=)
			closing_count_with_return_1(SGN, INV, &=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, &=)
			closed_loop_with_return_1(SGN, INV, &=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, &=)
				closed_count_with_return_1(SGN, INV, &=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, &=)
			opening_loop_with_return_1(SGN, INV, &=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, &=)
				opening_count_with_return_1(SGN, INV, &=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, &=)
			open_loop_with_return_1(SGN, INV, &=)

			struct count
			{
				open_count_no_return_1(SGN, INV, &=)
				open_count_with_return_1(SGN, INV, &=)
			};
		};
	};
/*
	|=:
*/
	struct bar
	{
		closing_loop_no_return_1(SGN, INV, |=)
		closing_loop_with_return_1(SGN, INV, |=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, |=)
			closing_count_with_return_1(SGN, INV, |=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, |=)
			closed_loop_with_return_1(SGN, INV, |=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, |=)
				closed_count_with_return_1(SGN, INV, |=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, |=)
			opening_loop_with_return_1(SGN, INV, |=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, |=)
				opening_count_with_return_1(SGN, INV, |=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, |=)
			open_loop_with_return_1(SGN, INV, |=)

			struct count
			{
				open_count_no_return_1(SGN, INV, |=)
				open_count_with_return_1(SGN, INV, |=)
			};
		};
	};
/*
	>>=:
*/
	struct right_shift
	{
		closing_loop_no_return_1(SGN, INV, >>=)
		closing_loop_with_return_1(SGN, INV, >>=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, >>=)
			closing_count_with_return_1(SGN, INV, >>=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, >>=)
			closed_loop_with_return_1(SGN, INV, >>=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, >>=)
				closed_count_with_return_1(SGN, INV, >>=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, >>=)
			opening_loop_with_return_1(SGN, INV, >>=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, >>=)
				opening_count_with_return_1(SGN, INV, >>=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, >>=)
			open_loop_with_return_1(SGN, INV, >>=)

			struct count
			{
				open_count_no_return_1(SGN, INV, >>=)
				open_count_with_return_1(SGN, INV, >>=)
			};
		};
	};
/*
	<<=:
*/
	struct left_shift
	{
		closing_loop_no_return_1(SGN, INV, <<=)
		closing_loop_with_return_1(SGN, INV, <<=)

		struct count
		{
			closing_count_no_return_1(SGN, INV, <<=)
			closing_count_with_return_1(SGN, INV, <<=)
		};

		struct closed
		{
			closed_loop_no_return_1(SGN, INV, <<=)
			closed_loop_with_return_1(SGN, INV, <<=)

			struct count
			{
				closed_count_no_return_1(SGN, INV, <<=)
				closed_count_with_return_1(SGN, INV, <<=)
			};
		};

		struct opening
		{
			opening_loop_no_return_1(SGN, INV, <<=)
			opening_loop_with_return_1(SGN, INV, <<=)

			struct count
			{
				opening_count_no_return_1(SGN, INV, <<=)
				opening_count_with_return_1(SGN, INV, <<=)
			};
		};

		struct open
		{
			open_loop_no_return_1(SGN, INV, <<=)
			open_loop_with_return_1(SGN, INV, <<=)

			struct count
			{
				open_count_no_return_1(SGN, INV, <<=)
				open_count_with_return_1(SGN, INV, <<=)
			};
		};
	};
};

struct allocate
{
	closing_loop_no_return_new_0(SGN, INV)
	closing_loop_with_return_new_0(SGN, INV)

	struct brackets
	{
		closing_loop_no_return_new_brackets_0(SGN, INV)
		closing_loop_with_return_new_brackets_0(SGN, INV)

		closing_loop_no_return_new_brackets_1(SGN, INV)
		closing_loop_with_return_new_brackets_1(SGN, INV)
	};

	struct count
	{
		closing_count_no_return_new_0(SGN, INV)
		closing_count_with_return_new_0(SGN, INV)

		struct brackets
		{
			closing_count_no_return_new_brackets_0(SGN, INV)
			closing_count_with_return_new_brackets_0(SGN, INV)

			closing_count_no_return_new_brackets_1(SGN, INV)
			closing_count_with_return_new_brackets_1(SGN, INV)
		};
	};

	struct closed
	{
		closed_loop_no_return_new_0(SGN, INV)
		closed_loop_with_return_new_0(SGN, INV)

		struct brackets
		{
			closed_loop_no_return_new_brackets_0(SGN, INV)
			closed_loop_with_return_new_brackets_0(SGN, INV)

			closed_loop_no_return_new_brackets_1(SGN, INV)
			closed_loop_with_return_new_brackets_1(SGN, INV)
		};

		struct count
		{
			closed_count_no_return_new_0(SGN, INV)
			closed_count_with_return_new_0(SGN, INV)

			struct brackets
			{
				closed_count_no_return_new_brackets_0(SGN, INV)
				closed_count_with_return_new_brackets_0(SGN, INV)

				closed_count_no_return_new_brackets_1(SGN, INV)
				closed_count_with_return_new_brackets_1(SGN, INV)
			};
		};
	};

	struct opening
	{
		opening_loop_no_return_new_0(SGN, INV)
		opening_loop_with_return_new_0(SGN, INV)

		struct brackets
		{
			opening_loop_no_return_new_brackets_0(SGN, INV)
			opening_loop_with_return_new_brackets_0(SGN, INV)

			opening_loop_no_return_new_brackets_1(SGN, INV)
			opening_loop_with_return_new_brackets_1(SGN, INV)
		};

		struct count
		{
			opening_count_no_return_new_0(SGN, INV)
			opening_count_with_return_new_0(SGN, INV)

			struct brackets
			{
				opening_count_no_return_new_brackets_0(SGN, INV)
				opening_count_with_return_new_brackets_0(SGN, INV)

				opening_count_no_return_new_brackets_1(SGN, INV)
				opening_count_with_return_new_brackets_1(SGN, INV)
			};
		};
	};

	struct open
	{
		open_loop_no_return_new_0(SGN, INV)
		open_loop_with_return_new_0(SGN, INV)

		struct brackets
		{
			open_loop_no_return_new_brackets_0(SGN, INV)
			open_loop_with_return_new_brackets_0(SGN, INV)

			open_loop_no_return_new_brackets_1(SGN, INV)
			open_loop_with_return_new_brackets_1(SGN, INV)
		};

		struct count
		{
			open_count_no_return_new_0(SGN, INV)
			open_count_with_return_new_0(SGN, INV)

			struct brackets
			{
				open_count_no_return_new_brackets_0(SGN, INV)
				open_count_with_return_new_brackets_0(SGN, INV)

				open_count_no_return_new_brackets_1(SGN, INV)
				open_count_with_return_new_brackets_1(SGN, INV)
			};
		};
	};
};

struct deallocate
{
	closing_loop_no_return_delete_0(SGN, INV)
	closing_loop_with_return_delete_0(SGN, INV)

	struct brackets
	{
		closing_loop_no_return_delete_brackets_0(SGN, INV)
		closing_loop_with_return_delete_brackets_0(SGN, INV)
	};

	struct count
	{
		closing_count_no_return_delete_0(SGN, INV)
		closing_count_with_return_delete_0(SGN, INV)

		struct brackets
		{
			closing_count_no_return_delete_brackets_0(SGN, INV)
			closing_count_with_return_delete_brackets_0(SGN, INV)
		};
	};

	struct closed
	{
		closed_loop_no_return_delete_0(SGN, INV)
		closed_loop_with_return_delete_0(SGN, INV)

		struct brackets
		{
			closed_loop_no_return_delete_brackets_0(SGN, INV)
			closed_loop_with_return_delete_brackets_0(SGN, INV)
		};

		struct count
		{
			closed_count_no_return_delete_0(SGN, INV)
			closed_count_with_return_delete_0(SGN, INV)

			struct brackets
			{
				closed_count_no_return_delete_brackets_0(SGN, INV)
				closed_count_with_return_delete_brackets_0(SGN, INV)
			};
		};
	};

	struct opening
	{
		opening_loop_no_return_delete_0(SGN, INV)
		opening_loop_with_return_delete_0(SGN, INV)

		struct brackets
		{
			opening_loop_no_return_delete_brackets_0(SGN, INV)
			opening_loop_with_return_delete_brackets_0(SGN, INV)
		};

		struct count
		{
			opening_count_no_return_delete_0(SGN, INV)
			opening_count_with_return_delete_0(SGN, INV)

			struct brackets
			{
				opening_count_no_return_delete_brackets_0(SGN, INV)
				opening_count_with_return_delete_brackets_0(SGN, INV)
			};
		};
	};

	struct open
	{
		open_loop_no_return_delete_0(SGN, INV)
		open_loop_with_return_delete_0(SGN, INV)

		struct brackets
		{
			open_loop_no_return_delete_brackets_0(SGN, INV)
			open_loop_with_return_delete_brackets_0(SGN, INV)
		};

		struct count
		{
			open_count_no_return_delete_0(SGN, INV)
			open_count_with_return_delete_0(SGN, INV)

			struct brackets
			{
				open_count_no_return_delete_brackets_0(SGN, INV)
				open_count_with_return_delete_brackets_0(SGN, INV)
			};
		};
	};
};

