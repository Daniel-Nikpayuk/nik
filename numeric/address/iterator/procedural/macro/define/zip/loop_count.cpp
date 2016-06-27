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
	#define plus_as_interval(name, label) \
	name##_loop_no_return##label##_1(SGN, INV, =+) \
	name##_loop_with_return##label##_1(SGN, INV, =+) \
 \
	name##_loop_no_return##label##_2(SGN, INV, +) \
	name##_loop_with_return##label##_2(SGN, INV, +) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_1(SGN, INV, =+) \
		name##_count_with_return##label##_1(SGN, INV, =+) \
 \
		name##_count_no_return##label##_2(SGN, INV, +) \
		name##_count_with_return##label##_2(SGN, INV, +) \
	};

	#define plus_interval(name) \
	struct name \
	{ \
		plus_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ plus_as_interval(name, _as_closing)	}; \
			struct closed	{ plus_as_interval(name, _as_closed)	}; \
			struct opening	{ plus_as_interval(name, _as_opening)	}; \
			struct open	{ plus_as_interval(name, _as_open)	}; \
		}; \
	};

	plus_interval(closing)
	plus_interval(closed)
	plus_interval(opening)
	plus_interval(open)

	#undef plus_interval
	#undef plus_as_interval
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	#define minus_as_interval(name, label) \
	name##_loop_no_return##label##_1(SGN, INV, =-) \
	name##_loop_with_return##label##_1(SGN, INV, =-) \
 \
	name##_loop_no_return##label##_2(SGN, INV, -) \
	name##_loop_with_return##label##_2(SGN, INV, -) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_1(SGN, INV, =-) \
		name##_count_with_return##label##_1(SGN, INV, =-) \
 \
		name##_count_no_return##label##_2(SGN, INV, -) \
		name##_count_with_return##label##_2(SGN, INV, -) \
	};

	#define minus_interval(name) \
	struct name \
	{ \
		minus_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ minus_as_interval(name, _as_closing)	}; \
			struct closed	{ minus_as_interval(name, _as_closed)	}; \
			struct opening	{ minus_as_interval(name, _as_opening)	}; \
			struct open	{ minus_as_interval(name, _as_open)	}; \
		}; \
	};

	minus_interval(closing)
	minus_interval(closed)
	minus_interval(opening)
	minus_interval(open)

	#undef minus_interval
	#undef minus_as_interval
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	#define asterisk_as_interval(name, label) \
	name##_loop_no_return##label##_1(SGN, INV, =*) \
	name##_loop_with_return##label##_1(SGN, INV, =*) \
 \
	name##_loop_no_return##label##_2(SGN, INV, *) \
	name##_loop_with_return##label##_2(SGN, INV, *) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_1(SGN, INV, =*) \
		name##_count_with_return##label##_1(SGN, INV, =*) \
 \
		name##_count_no_return##label##_2(SGN, INV, *) \
		name##_count_with_return##label##_2(SGN, INV, *) \
	};

	#define asterisk_interval(name) \
	struct name \
	{ \
		asterisk_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ asterisk_as_interval(name, _as_closing)	}; \
			struct closed	{ asterisk_as_interval(name, _as_closed)	}; \
			struct opening	{ asterisk_as_interval(name, _as_opening)	}; \
			struct open	{ asterisk_as_interval(name, _as_open)		}; \
		}; \
	};

	asterisk_interval(closing)
	asterisk_interval(closed)
	asterisk_interval(opening)
	asterisk_interval(open)

	#undef asterisk_interval
	#undef asterisk_as_interval
};

/*
	/:
*/

struct slash
{
	#define slash_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, /) \
	name##_loop_with_return##label##_2(SGN, INV, /) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, /) \
		name##_count_with_return##label##_2(SGN, INV, /) \
	};

	#define slash_interval(name) \
	struct name \
	{ \
		slash_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ slash_as_interval(name, _as_closing)	}; \
			struct closed	{ slash_as_interval(name, _as_closed)	}; \
			struct opening	{ slash_as_interval(name, _as_opening)	}; \
			struct open	{ slash_as_interval(name, _as_open)	}; \
		}; \
	};

	slash_interval(closing)
	slash_interval(closed)
	slash_interval(opening)
	slash_interval(open)

	#undef slash_interval
	#undef slash_as_interval
};

/*
	%:
*/

struct percent
{
	#define percent_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, %) \
	name##_loop_with_return##label##_2(SGN, INV, %) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, %) \
		name##_count_with_return##label##_2(SGN, INV, %) \
	};

	#define percent_interval(name) \
	struct name \
	{ \
		percent_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ percent_as_interval(name, _as_closing)	}; \
			struct closed	{ percent_as_interval(name, _as_closed)		}; \
			struct opening	{ percent_as_interval(name, _as_opening)	}; \
			struct open	{ percent_as_interval(name, _as_open)		}; \
		}; \
	};

	percent_interval(closing)
	percent_interval(closed)
	percent_interval(opening)
	percent_interval(open)

	#undef percent_interval
	#undef percent_as_interval
};

/*
	ˆ:
*/

struct caret
{
	#define caret_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, ^) \
	name##_loop_with_return##label##_2(SGN, INV, ^) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, ^) \
		name##_count_with_return##label##_2(SGN, INV, ^) \
	};

	#define caret_interval(name) \
	struct name \
	{ \
		caret_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ caret_as_interval(name, _as_closing)	}; \
			struct closed	{ caret_as_interval(name, _as_closed)	}; \
			struct opening	{ caret_as_interval(name, _as_opening)	}; \
			struct open	{ caret_as_interval(name, _as_open)	}; \
		}; \
	};

	caret_interval(closing)
	caret_interval(closed)
	caret_interval(opening)
	caret_interval(open)

	#undef caret_interval
	#undef caret_as_interval
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	#define ampersand_as_interval(name, label) \
	name##_loop_no_return##label##_1(SGN, INV, =&) \
	name##_loop_with_return##label##_1(SGN, INV, =&) \
 \
	name##_loop_no_return##label##_2(SGN, INV, &) \
	name##_loop_with_return##label##_2(SGN, INV, &) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_1(SGN, INV, =&) \
		name##_count_with_return##label##_1(SGN, INV, =&) \
 \
		name##_count_no_return##label##_2(SGN, INV, &) \
		name##_count_with_return##label##_2(SGN, INV, &) \
	};

	#define ampersand_interval(name) \
	struct name \
	{ \
		ampersand_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ ampersand_as_interval(name, _as_closing)	}; \
			struct closed	{ ampersand_as_interval(name, _as_closed)	}; \
			struct opening	{ ampersand_as_interval(name, _as_opening)	}; \
			struct open	{ ampersand_as_interval(name, _as_open)		}; \
		}; \
	};

	ampersand_interval(closing)
	ampersand_interval(closed)
	ampersand_interval(opening)
	ampersand_interval(open)

	#undef ampersand_interval
	#undef ampersand_as_interval
};

/*
	|:
*/

struct bar
{
	#define bar_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, |) \
	name##_loop_with_return##label##_2(SGN, INV, |) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, |) \
		name##_count_with_return##label##_2(SGN, INV, |) \
	};

	#define bar_interval(name) \
	struct name \
	{ \
		bar_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ bar_as_interval(name, _as_closing)	}; \
			struct closed	{ bar_as_interval(name, _as_closed)	}; \
			struct opening	{ bar_as_interval(name, _as_opening)	}; \
			struct open	{ bar_as_interval(name, _as_open)	}; \
		}; \
	};

	bar_interval(closing)
	bar_interval(closed)
	bar_interval(opening)
	bar_interval(open)

	#undef bar_interval
	#undef bar_as_interval
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	#define tilde_as_interval(name, label) \
	name##_loop_no_return##label##_1(SGN, INV, =~) \
	name##_loop_with_return##label##_1(SGN, INV, =~) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_1(SGN, INV, =~) \
		name##_count_with_return##label##_1(SGN, INV, =~) \
	};

	#define tilde_interval(name) \
	struct name \
	{ \
		tilde_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ tilde_as_interval(name, _as_closing)	}; \
			struct closed	{ tilde_as_interval(name, _as_closed)	}; \
			struct opening	{ tilde_as_interval(name, _as_opening)	}; \
			struct open	{ tilde_as_interval(name, _as_open)	}; \
		}; \
	};

	tilde_interval(closing)
	tilde_interval(closed)
	tilde_interval(opening)
	tilde_interval(open)

	#undef tilde_interval
	#undef tilde_as_interval
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	#define exclamation_as_interval(name, label) \
	name##_loop_no_return##label##_1(SGN, INV, =!) \
	name##_loop_with_return##label##_1(SGN, INV, =!) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_1(SGN, INV, =!) \
		name##_count_with_return##label##_1(SGN, INV, =!) \
	};

	#define exclamation_interval(name) \
	struct name \
	{ \
		exclamation_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ exclamation_as_interval(name, _as_closing)	}; \
			struct closed	{ exclamation_as_interval(name, _as_closed)	}; \
			struct opening	{ exclamation_as_interval(name, _as_opening)	}; \
			struct open	{ exclamation_as_interval(name, _as_open)	}; \
		}; \
	};

	exclamation_interval(closing)
	exclamation_interval(closed)
	exclamation_interval(opening)
	exclamation_interval(open)

	#undef exclamation_interval
	#undef exclamation_as_interval
};

/*
	<:
*/

struct less_than
{
	#define less_than_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, <) \
	name##_loop_with_return##label##_2(SGN, INV, <) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, <) \
		name##_count_with_return##label##_2(SGN, INV, <) \
	};

	#define less_than_interval(name) \
	struct name \
	{ \
		less_than_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ less_than_as_interval(name, _as_closing)	}; \
			struct closed	{ less_than_as_interval(name, _as_closed)	}; \
			struct opening	{ less_than_as_interval(name, _as_opening)	}; \
			struct open	{ less_than_as_interval(name, _as_open)		}; \
		}; \
	};

	less_than_interval(closing)
	less_than_interval(closed)
	less_than_interval(opening)
	less_than_interval(open)

	#undef less_than_interval
	#undef less_than_as_interval
};

/*
	>:
*/

struct greater_than
{
	#define greater_than_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, >) \
	name##_loop_with_return##label##_2(SGN, INV, >) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, >) \
		name##_count_with_return##label##_2(SGN, INV, >) \
	};

	#define greater_than_interval(name) \
	struct name \
	{ \
		greater_than_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ greater_than_as_interval(name, _as_closing)	}; \
			struct closed	{ greater_than_as_interval(name, _as_closed)	}; \
			struct opening	{ greater_than_as_interval(name, _as_opening)	}; \
			struct open	{ greater_than_as_interval(name, _as_open)	}; \
		}; \
	};

	greater_than_interval(closing)
	greater_than_interval(closed)
	greater_than_interval(opening)
	greater_than_interval(open)

	#undef greater_than_interval
	#undef greater_than_as_interval
};

/*
	<<:
*/

struct left_shift
{
	#define left_shift_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, <<) \
	name##_loop_with_return##label##_2(SGN, INV, <<) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, <<) \
		name##_count_with_return##label##_2(SGN, INV, <<) \
	};

	#define left_shift_interval(name) \
	struct name \
	{ \
		left_shift_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ left_shift_as_interval(name, _as_closing)	}; \
			struct closed	{ left_shift_as_interval(name, _as_closed)	}; \
			struct opening	{ left_shift_as_interval(name, _as_opening)	}; \
			struct open	{ left_shift_as_interval(name, _as_open)	}; \
		}; \
	};

	left_shift_interval(closing)
	left_shift_interval(closed)
	left_shift_interval(opening)
	left_shift_interval(open)

	#undef left_shift_interval
	#undef left_shift_as_interval
};

/*
	>>:
*/

struct right_shift
{
	#define right_shift_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, >>) \
	name##_loop_with_return##label##_2(SGN, INV, >>) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, >>) \
		name##_count_with_return##label##_2(SGN, INV, >>) \
	};

	#define right_shift_interval(name) \
	struct name \
	{ \
		right_shift_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ right_shift_as_interval(name, _as_closing)	}; \
			struct closed	{ right_shift_as_interval(name, _as_closed)	}; \
			struct opening	{ right_shift_as_interval(name, _as_opening)	}; \
			struct open	{ right_shift_as_interval(name, _as_open)	}; \
		}; \
	};

	right_shift_interval(closing)
	right_shift_interval(closed)
	right_shift_interval(opening)
	right_shift_interval(open)

	#undef right_shift_interval
	#undef right_shift_as_interval
};

/*
	==:
*/

struct equals
{
	#define equals_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, ==) \
	name##_loop_with_return##label##_2(SGN, INV, ==) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, ==) \
		name##_count_with_return##label##_2(SGN, INV, ==) \
	};

	#define equals_interval(name) \
	struct name \
	{ \
		equals_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ equals_as_interval(name, _as_closing)	}; \
			struct closed	{ equals_as_interval(name, _as_closed)	}; \
			struct opening	{ equals_as_interval(name, _as_opening)	}; \
			struct open	{ equals_as_interval(name, _as_open)	}; \
		}; \
	};

	equals_interval(closing)
	equals_interval(closed)
	equals_interval(opening)
	equals_interval(open)

	#undef equals_interval
	#undef equals_as_interval
};

/*
	!=:
*/

struct not_equals
{
	#define not_equals_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, !=) \
	name##_loop_with_return##label##_2(SGN, INV, !=) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, !=) \
		name##_count_with_return##label##_2(SGN, INV, !=) \
	};

	#define not_equals_interval(name) \
	struct name \
	{ \
		not_equals_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ not_equals_as_interval(name, _as_closing)	}; \
			struct closed	{ not_equals_as_interval(name, _as_closed)	}; \
			struct opening	{ not_equals_as_interval(name, _as_opening)	}; \
			struct open	{ not_equals_as_interval(name, _as_open)	}; \
		}; \
	};

	not_equals_interval(closing)
	not_equals_interval(closed)
	not_equals_interval(opening)
	not_equals_interval(open)

	#undef not_equals_interval
	#undef not_equals_as_interval
};

/*
	<=:
*/

struct less_than_or_equal
{
	#define less_than_or_equal_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, <=) \
	name##_loop_with_return##label##_2(SGN, INV, <=) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, <=) \
		name##_count_with_return##label##_2(SGN, INV, <=) \
	};

	#define less_than_or_equal_interval(name) \
	struct name \
	{ \
		less_than_or_equal_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ less_than_or_equal_as_interval(name, _as_closing)	}; \
			struct closed	{ less_than_or_equal_as_interval(name, _as_closed)	}; \
			struct opening	{ less_than_or_equal_as_interval(name, _as_opening)	}; \
			struct open	{ less_than_or_equal_as_interval(name, _as_open)	}; \
		}; \
	};

	less_than_or_equal_interval(closing)
	less_than_or_equal_interval(closed)
	less_than_or_equal_interval(opening)
	less_than_or_equal_interval(open)

	#undef less_than_or_equal_interval
	#undef less_than_or_equal_as_interval
};

/*
	>=:
*/

struct greater_than_or_equal
{
	#define greater_than_or_equal_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, >=) \
	name##_loop_with_return##label##_2(SGN, INV, >=) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, >=) \
		name##_count_with_return##label##_2(SGN, INV, >=) \
	};

	#define greater_than_or_equal_interval(name) \
	struct name \
	{ \
		greater_than_or_equal_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ greater_than_or_equal_as_interval(name, _as_closing)	}; \
			struct closed	{ greater_than_or_equal_as_interval(name, _as_closed)	}; \
			struct opening	{ greater_than_or_equal_as_interval(name, _as_opening)	}; \
			struct open	{ greater_than_or_equal_as_interval(name, _as_open)	}; \
		}; \
	};

	greater_than_or_equal_interval(closing)
	greater_than_or_equal_interval(closed)
	greater_than_or_equal_interval(opening)
	greater_than_or_equal_interval(open)

	#undef greater_than_or_equal_interval
	#undef greater_than_or_equal_as_interval
};

/*
	&&:
*/

struct logical_and
{
	#define logical_and_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, &&) \
	name##_loop_with_return##label##_2(SGN, INV, &&) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, &&) \
		name##_count_with_return##label##_2(SGN, INV, &&) \
	};

	#define logical_and_interval(name) \
	struct name \
	{ \
		logical_and_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ logical_and_as_interval(name, _as_closing)	}; \
			struct closed	{ logical_and_as_interval(name, _as_closed)	}; \
			struct opening	{ logical_and_as_interval(name, _as_opening)	}; \
			struct open	{ logical_and_as_interval(name, _as_open)	}; \
		}; \
	};

	logical_and_interval(closing)
	logical_and_interval(closed)
	logical_and_interval(opening)
	logical_and_interval(open)

	#undef logical_and_interval
	#undef logical_and_as_interval
};

/*
	||:
*/

struct logical_or
{
	#define logical_or_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, ||) \
	name##_loop_with_return##label##_2(SGN, INV, ||) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, ||) \
		name##_count_with_return##label##_2(SGN, INV, ||) \
	};

	#define logical_or_interval(name) \
	struct name \
	{ \
		logical_or_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ logical_or_as_interval(name, _as_closing)	}; \
			struct closed	{ logical_or_as_interval(name, _as_closed)	}; \
			struct opening	{ logical_or_as_interval(name, _as_opening)	}; \
			struct open	{ logical_or_as_interval(name, _as_open)	}; \
		}; \
	};

	logical_or_interval(closing)
	logical_or_interval(closed)
	logical_or_interval(opening)
	logical_or_interval(open)

	#undef logical_or_interval
	#undef logical_or_as_interval
};

/*
	++:
*/

struct left_increment
{
	#define left_increment_as_interval(name, label) \
	name##_loop_no_return_left##label##_0(SGN, INV, ++) \
 \
	struct count \
	{ \
		name##_count_no_return_left##label##_0(SGN, INV, ++) \
	};

	#define left_increment_interval(name) \
	struct name \
	{ \
		left_increment_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ left_increment_as_interval(name, _as_closing)	}; \
			struct closed	{ left_increment_as_interval(name, _as_closed)	}; \
			struct opening	{ left_increment_as_interval(name, _as_opening)	}; \
			struct open	{ left_increment_as_interval(name, _as_open)	}; \
		}; \
	};

	left_increment_interval(closing)
	left_increment_interval(closed)
	left_increment_interval(opening)
	left_increment_interval(open)

	#undef left_increment_interval
	#undef left_increment_as_interval
};

struct right_increment
{
	#define right_increment_as_interval(name, label) \
	name##_loop_no_return_right##label##_0(SGN, INV, ++) \
 \
	struct count \
	{ \
		name##_count_no_return_right##label##_0(SGN, INV, ++) \
	};

	#define right_increment_interval(name) \
	struct name \
	{ \
		right_increment_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ right_increment_as_interval(name, _as_closing)	}; \
			struct closed	{ right_increment_as_interval(name, _as_closed)		}; \
			struct opening	{ right_increment_as_interval(name, _as_opening)	}; \
			struct open	{ right_increment_as_interval(name, _as_open)		}; \
		}; \
	};

	right_increment_interval(closing)
	right_increment_interval(closed)
	right_increment_interval(opening)
	right_increment_interval(open)

	#undef right_increment_interval
	#undef right_increment_as_interval
};

/*
	--:
*/

struct left_decrement
{
	#define left_decrement_as_interval(name, label) \
	name##_loop_no_return_left##label##_0(SGN, INV, --) \
 \
	struct count \
	{ \
		name##_count_no_return_left##label##_0(SGN, INV, --) \
	};

	#define left_decrement_interval(name) \
	struct name \
	{ \
		left_decrement_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ left_decrement_as_interval(name, _as_closing)	}; \
			struct closed	{ left_decrement_as_interval(name, _as_closed)	}; \
			struct opening	{ left_decrement_as_interval(name, _as_opening)	}; \
			struct open	{ left_decrement_as_interval(name, _as_open)	}; \
		}; \
	};

	left_decrement_interval(closing)
	left_decrement_interval(closed)
	left_decrement_interval(opening)
	left_decrement_interval(open)

	#undef left_decrement_interval
	#undef left_decrement_as_interval
};

struct right_decrement
{
	#define right_decrement_as_interval(name, label) \
	name##_loop_no_return_right##label##_0(SGN, INV, --) \
 \
	struct count \
	{ \
		name##_count_no_return_right##label##_0(SGN, INV, --) \
	};

	#define right_decrement_interval(name) \
	struct name \
	{ \
		right_decrement_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ right_decrement_as_interval(name, _as_closing)	}; \
			struct closed	{ right_decrement_as_interval(name, _as_closed)		}; \
			struct opening	{ right_decrement_as_interval(name, _as_opening)	}; \
			struct open	{ right_decrement_as_interval(name, _as_open)		}; \
		}; \
	};

	right_decrement_interval(closing)
	right_decrement_interval(closed)
	right_decrement_interval(opening)
	right_decrement_interval(open)

	#undef right_decrement_interval
	#undef right_decrement_as_interval
};

/*
	,:
*/

struct comma
{
	#define comma_as_interval(name, label) \
	struct count \
	{ \
	};

	#define comma_interval(name) \
	struct name \
	{ \
		comma_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ comma_as_interval(name, _as_closing)	}; \
			struct closed	{ comma_as_interval(name, _as_closed)	}; \
			struct opening	{ comma_as_interval(name, _as_opening)	}; \
			struct open	{ comma_as_interval(name, _as_open)	}; \
		}; \
	};

	comma_interval(closing)
	comma_interval(closed)
	comma_interval(opening)
	comma_interval(open)

	#undef comma_interval
	#undef comma_as_interval
};

/*
	->*:
*/

struct point_asterisk
{
	#define point_asterisk_as_interval(name, label) \
	name##_loop_no_return##label##_2(SGN, INV, ->*) \
	name##_loop_with_return##label##_2(SGN, INV, ->*) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_2(SGN, INV, ->*) \
		name##_count_with_return##label##_2(SGN, INV, ->*) \
	};

	#define point_asterisk_interval(name) \
	struct name \
	{ \
		point_asterisk_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ point_asterisk_as_interval(name, _as_closing)	}; \
			struct closed	{ point_asterisk_as_interval(name, _as_closed)	}; \
			struct opening	{ point_asterisk_as_interval(name, _as_opening)	}; \
			struct open	{ point_asterisk_as_interval(name, _as_open)	}; \
		}; \
	};

	point_asterisk_interval(closing)
	point_asterisk_interval(closed)
	point_asterisk_interval(opening)
	point_asterisk_interval(open)

	#undef point_asterisk_interval
	#undef point_asterisk_as_interval
};

/*
	->:
*/

struct point
{
	#define point_as_interval(name, label) \
	name##_loop_with_return##label##_2(SGN, INV, .operator->) \
 \
	struct count \
	{ \
		name##_count_with_return##label##_2(SGN, INV, .operator->) \
	};

	#define point_interval(name) \
	struct name \
	{ \
		point_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ point_as_interval(name, _as_closing)	}; \
			struct closed	{ point_as_interval(name, _as_closed)	}; \
			struct opening	{ point_as_interval(name, _as_opening)	}; \
			struct open	{ point_as_interval(name, _as_open)	}; \
		}; \
	};

	point_interval(closing)
	point_interval(closed)
	point_interval(opening)
	point_interval(open)

	#undef point_interval
	#undef point_as_interval
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	#define parentheses_as_interval(name, label) \
	name##_loop_no_return_right##label##_0(SGN, INV, ()) \
 \
	name##_loop_no_return_right##label##_1(SGN, INV, =, ()) \
	name##_loop_with_return_right##label##_1(SGN, INV, =, ()) \
 \
	name##_loop_no_return##label##_2(SGN, INV, ) \
	name##_loop_with_return##label##_2(SGN, INV, ) \
 \
	struct count \
	{ \
		name##_count_no_return_right##label##_0(SGN, INV, ()) \
 \
		name##_count_no_return_right##label##_1(SGN, INV, =, ()) \
		name##_count_with_return_right##label##_1(SGN, INV, =, ()) \
 \
		name##_count_no_return##label##_2(SGN, INV, ) \
		name##_count_with_return##label##_2(SGN, INV, ) \
	};

	#define parentheses_interval(name) \
	struct name \
	{ \
		parentheses_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ parentheses_as_interval(name, _as_closing)	}; \
			struct closed	{ parentheses_as_interval(name, _as_closed)	}; \
			struct opening	{ parentheses_as_interval(name, _as_opening)	}; \
			struct open	{ parentheses_as_interval(name, _as_open)	}; \
		}; \
	};

	parentheses_interval(closing)
	parentheses_interval(closed)
	parentheses_interval(opening)
	parentheses_interval(open)

	#undef parentheses_interval
	#undef parentheses_as_interval
};

/*
	[]:
*/

struct brackets
{
	#define brackets_as_interval(name, label) \
	name##_loop_no_return_brackets##label##_2(SGN, INV, ) \
	name##_loop_with_return_brackets##label##_2(SGN, INV, ) \
 \
	struct count \
	{ \
		name##_count_no_return_brackets##label##_2(SGN, INV, ) \
		name##_count_with_return_brackets##label##_2(SGN, INV, ) \
	};

	#define brackets_interval(name) \
	struct name \
	{ \
		brackets_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ brackets_as_interval(name, _as_closing)	}; \
			struct closed	{ brackets_as_interval(name, _as_closed)	}; \
			struct opening	{ brackets_as_interval(name, _as_opening)	}; \
			struct open	{ brackets_as_interval(name, _as_open)		}; \
		}; \
	};

	brackets_interval(closing)
	brackets_interval(closed)
	brackets_interval(opening)
	brackets_interval(open)

	#undef brackets_interval
	#undef brackets_as_interval
};

/*
	=:
*/

struct repeat
{
	#define repeat_as_interval(name, label) \
	name##_loop_no_return##label##_0(SGN, INV, =) \
	name##_loop_with_return##label##_0(SGN, INV, =) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_0(SGN, INV, =) \
		name##_count_with_return##label##_0(SGN, INV, =) \
	};

	#define repeat_interval(name) \
	struct name \
	{ \
		repeat_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ repeat_as_interval(name, _as_closing)	}; \
			struct closed	{ repeat_as_interval(name, _as_closed)	}; \
			struct opening	{ repeat_as_interval(name, _as_opening)	}; \
			struct open	{ repeat_as_interval(name, _as_open)	}; \
		}; \
	};

	repeat_interval(closing)
	repeat_interval(closed)
	repeat_interval(opening)
	repeat_interval(open)

	#undef repeat_interval
	#undef repeat_as_interval
/*
	+=:
*/
	struct plus
	{
		#define repeat_plus_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, +=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, +=) \
		};

		#define repeat_plus_interval(name) \
		struct name \
		{ \
			repeat_plus_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_plus_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_plus_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_plus_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_plus_as_interval(name, _as_open)	}; \
			}; \
		};

		repeat_plus_interval(closing)
		repeat_plus_interval(closed)
		repeat_plus_interval(opening)
		repeat_plus_interval(open)

		#undef repeat_plus_interval
		#undef repeat_plus_as_interval
	};
/*
	-=:
*/
	struct minus
	{
		#define repeat_minus_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, -=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, -=) \
		};

		#define repeat_minus_interval(name) \
		struct name \
		{ \
			repeat_minus_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_minus_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_minus_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_minus_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_minus_as_interval(name, _as_open)	}; \
			}; \
		};

		repeat_minus_interval(closing)
		repeat_minus_interval(closed)
		repeat_minus_interval(opening)
		repeat_minus_interval(open)

		#undef repeat_minus_interval
		#undef repeat_minus_as_interval
	};
/*
	*=:
*/
	struct asterisk
	{
		#define repeat_asterisk_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, *=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, *=) \
		};

		#define repeat_asterisk_interval(name) \
		struct name \
		{ \
			repeat_asterisk_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_asterisk_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_asterisk_as_interval(name, _as_closed)		}; \
				struct opening	{ repeat_asterisk_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_asterisk_as_interval(name, _as_open)		}; \
			}; \
		};

		repeat_asterisk_interval(closing)
		repeat_asterisk_interval(closed)
		repeat_asterisk_interval(opening)
		repeat_asterisk_interval(open)

		#undef repeat_asterisk_interval
		#undef repeat_asterisk_as_interval
	};
/*
	/=:
*/
	struct slash
	{
		#define repeat_slash_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, /=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, /=) \
		};

		#define repeat_slash_interval(name) \
		struct name \
		{ \
			repeat_slash_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_slash_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_slash_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_slash_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_slash_as_interval(name, _as_open)	}; \
			}; \
		};

		repeat_slash_interval(closing)
		repeat_slash_interval(closed)
		repeat_slash_interval(opening)
		repeat_slash_interval(open)

		#undef repeat_slash_interval
		#undef repeat_slash_as_interval
	};
/*
	%=:
*/
	struct percent
	{
		#define repeat_percent_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, %=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, %=) \
		};

		#define repeat_percent_interval(name) \
		struct name \
		{ \
			repeat_percent_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_percent_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_percent_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_percent_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_percent_as_interval(name, _as_open)	}; \
			}; \
		};

		repeat_percent_interval(closing)
		repeat_percent_interval(closed)
		repeat_percent_interval(opening)
		repeat_percent_interval(open)

		#undef repeat_percent_interval
		#undef repeat_percent_as_interval
	};
/*
	ˆ=:
*/
	struct caret
	{
		#define repeat_caret_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, ^=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, ^=) \
		};

		#define repeat_caret_interval(name) \
		struct name \
		{ \
			repeat_caret_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_caret_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_caret_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_caret_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_caret_as_interval(name, _as_open)	}; \
			}; \
		};

		repeat_caret_interval(closing)
		repeat_caret_interval(closed)
		repeat_caret_interval(opening)
		repeat_caret_interval(open)

		#undef repeat_caret_interval
		#undef repeat_caret_as_interval
	};
/*
	&=:
*/
	struct ampersand
	{
		#define repeat_ampersand_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, &=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, &=) \
		};

		#define repeat_ampersand_interval(name) \
		struct name \
		{ \
			repeat_ampersand_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_ampersand_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_ampersand_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_ampersand_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_ampersand_as_interval(name, _as_open)		}; \
			}; \
		};

		repeat_ampersand_interval(closing)
		repeat_ampersand_interval(closed)
		repeat_ampersand_interval(opening)
		repeat_ampersand_interval(open)

		#undef repeat_ampersand_interval
		#undef repeat_ampersand_as_interval
	};
/*
	|=:
*/
	struct bar
	{
		#define repeat_bar_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, |=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, |=) \
		};

		#define repeat_bar_interval(name) \
		struct name \
		{ \
			repeat_bar_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_bar_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_bar_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_bar_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_bar_as_interval(name, _as_open)	}; \
			}; \
		};

		repeat_bar_interval(closing)
		repeat_bar_interval(closed)
		repeat_bar_interval(opening)
		repeat_bar_interval(open)

		#undef repeat_bar_interval
		#undef repeat_bar_as_interval
	};
/*
	>>=:
*/
	struct right_shift
	{
		#define repeat_right_shift_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, >>=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, >>=) \
		};

		#define repeat_right_shift_interval(name) \
		struct name \
		{ \
			repeat_right_shift_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_right_shift_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_right_shift_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_right_shift_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_right_shift_as_interval(name, _as_open)	}; \
			}; \
		};

		repeat_right_shift_interval(closing)
		repeat_right_shift_interval(closed)
		repeat_right_shift_interval(opening)
		repeat_right_shift_interval(open)

		#undef repeat_right_shift_interval
		#undef repeat_right_shift_as_interval
	};
/*
	<<=:
*/
	struct left_shift
	{
		#define repeat_left_shift_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, <<=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, <<=) \
		};

		#define repeat_left_shift_interval(name) \
		struct name \
		{ \
			repeat_left_shift_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ repeat_left_shift_as_interval(name, _as_closing)	}; \
				struct closed	{ repeat_left_shift_as_interval(name, _as_closed)	}; \
				struct opening	{ repeat_left_shift_as_interval(name, _as_opening)	}; \
				struct open	{ repeat_left_shift_as_interval(name, _as_open)		}; \
			}; \
		};

		repeat_left_shift_interval(closing)
		repeat_left_shift_interval(closed)
		repeat_left_shift_interval(opening)
		repeat_left_shift_interval(open)

		#undef repeat_left_shift_interval
		#undef repeat_left_shift_as_interval
	};
};

/*
	=:
*/

struct assign
{
	#define assign_as_interval(name, label) \
	name##_loop_no_return##label##_1(SGN, INV, =) \
	name##_loop_with_return##label##_1(SGN, INV, =) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_1(SGN, INV, =) \
		name##_count_with_return##label##_1(SGN, INV, =) \
	};

	#define assign_interval(name) \
	struct name \
	{ \
		assign_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ assign_as_interval(name, _as_closing)	}; \
			struct closed	{ assign_as_interval(name, _as_closed)	}; \
			struct opening	{ assign_as_interval(name, _as_opening)	}; \
			struct open	{ assign_as_interval(name, _as_open)	}; \
		}; \
	};

	assign_interval(closing)
	assign_interval(closed)
	assign_interval(opening)
	assign_interval(open)

	#undef assign_interval
	#undef assign_as_interval
/*
	+=:
*/
	struct plus
	{
		#define assign_plus_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, +=) \
		name##_loop_with_return##label##_1(SGN, INV, +=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, +=) \
			name##_count_with_return##label##_1(SGN, INV, +=) \
		};

		#define assign_plus_interval(name) \
		struct name \
		{ \
			assign_plus_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_plus_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_plus_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_plus_as_interval(name, _as_opening)	}; \
				struct open	{ assign_plus_as_interval(name, _as_open)	}; \
			}; \
		};

		assign_plus_interval(closing)
		assign_plus_interval(closed)
		assign_plus_interval(opening)
		assign_plus_interval(open)

		#undef assign_plus_interval
		#undef assign_plus_as_interval
	};
/*
	-=:
*/
	struct minus
	{
		#define assign_minus_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, -=) \
		name##_loop_with_return##label##_1(SGN, INV, -=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, -=) \
			name##_count_with_return##label##_1(SGN, INV, -=) \
		};

		#define assign_minus_interval(name) \
		struct name \
		{ \
			assign_minus_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_minus_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_minus_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_minus_as_interval(name, _as_opening)	}; \
				struct open	{ assign_minus_as_interval(name, _as_open)	}; \
			}; \
		};

		assign_minus_interval(closing)
		assign_minus_interval(closed)
		assign_minus_interval(opening)
		assign_minus_interval(open)

		#undef assign_minus_interval
		#undef assign_minus_as_interval
	};
/*
	*=:
*/
	struct asterisk
	{
		#define assign_asterisk_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, *=) \
		name##_loop_with_return##label##_1(SGN, INV, *=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, *=) \
			name##_count_with_return##label##_1(SGN, INV, *=) \
		};

		#define assign_asterisk_interval(name) \
		struct name \
		{ \
			assign_asterisk_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_asterisk_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_asterisk_as_interval(name, _as_closed)		}; \
				struct opening	{ assign_asterisk_as_interval(name, _as_opening)	}; \
				struct open	{ assign_asterisk_as_interval(name, _as_open)		}; \
			}; \
		};

		assign_asterisk_interval(closing)
		assign_asterisk_interval(closed)
		assign_asterisk_interval(opening)
		assign_asterisk_interval(open)

		#undef assign_asterisk_interval
		#undef assign_asterisk_as_interval
	};
/*
	/=:
*/
	struct slash
	{
		#define assign_slash_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, /=) \
		name##_loop_with_return##label##_1(SGN, INV, /=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, /=) \
			name##_count_with_return##label##_1(SGN, INV, /=) \
		};

		#define assign_slash_interval(name) \
		struct name \
		{ \
			assign_slash_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_slash_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_slash_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_slash_as_interval(name, _as_opening)	}; \
				struct open	{ assign_slash_as_interval(name, _as_open)	}; \
			}; \
		};

		assign_slash_interval(closing)
		assign_slash_interval(closed)
		assign_slash_interval(opening)
		assign_slash_interval(open)

		#undef assign_slash_interval
		#undef assign_slash_as_interval
	};
/*
	%=:
*/
	struct percent
	{
		#define assign_percent_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, %=) \
		name##_loop_with_return##label##_1(SGN, INV, %=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, %=) \
			name##_count_with_return##label##_1(SGN, INV, %=) \
		};

		#define assign_percent_interval(name) \
		struct name \
		{ \
			assign_percent_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_percent_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_percent_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_percent_as_interval(name, _as_opening)	}; \
				struct open	{ assign_percent_as_interval(name, _as_open)	}; \
			}; \
		};

		assign_percent_interval(closing)
		assign_percent_interval(closed)
		assign_percent_interval(opening)
		assign_percent_interval(open)

		#undef assign_percent_interval
		#undef assign_percent_as_interval
	};
/*
	ˆ=:
*/
	struct caret
	{
		#define assign_caret_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, ^=) \
		name##_loop_with_return##label##_1(SGN, INV, ^=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, ^=) \
			name##_count_with_return##label##_1(SGN, INV, ^=) \
		};

		#define assign_caret_interval(name) \
		struct name \
		{ \
			assign_caret_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_caret_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_caret_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_caret_as_interval(name, _as_opening)	}; \
				struct open	{ assign_caret_as_interval(name, _as_open)	}; \
			}; \
		};

		assign_caret_interval(closing)
		assign_caret_interval(closed)
		assign_caret_interval(opening)
		assign_caret_interval(open)

		#undef assign_caret_interval
		#undef assign_caret_as_interval
	};
/*
	&=:
*/
	struct ampersand
	{
		#define assign_ampersand_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, &=) \
		name##_loop_with_return##label##_1(SGN, INV, &=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, &=) \
			name##_count_with_return##label##_1(SGN, INV, &=) \
		};

		#define assign_ampersand_interval(name) \
		struct name \
		{ \
			assign_ampersand_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_ampersand_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_ampersand_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_ampersand_as_interval(name, _as_opening)	}; \
				struct open	{ assign_ampersand_as_interval(name, _as_open)		}; \
			}; \
		};

		assign_ampersand_interval(closing)
		assign_ampersand_interval(closed)
		assign_ampersand_interval(opening)
		assign_ampersand_interval(open)

		#undef assign_ampersand_interval
		#undef assign_ampersand_as_interval
	};
/*
	|=:
*/
	struct bar
	{
		#define assign_bar_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, |=) \
		name##_loop_with_return##label##_1(SGN, INV, |=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, |=) \
			name##_count_with_return##label##_1(SGN, INV, |=) \
		};

		#define assign_bar_interval(name) \
		struct name \
		{ \
			assign_bar_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_bar_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_bar_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_bar_as_interval(name, _as_opening)	}; \
				struct open	{ assign_bar_as_interval(name, _as_open)	}; \
			}; \
		};

		assign_bar_interval(closing)
		assign_bar_interval(closed)
		assign_bar_interval(opening)
		assign_bar_interval(open)

		#undef assign_bar_interval
		#undef assign_bar_as_interval
	};
/*
	>>=:
*/
	struct right_shift
	{
		#define assign_right_shift_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, >>=) \
		name##_loop_with_return##label##_1(SGN, INV, >>=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, >>=) \
			name##_count_with_return##label##_1(SGN, INV, >>=) \
		};

		#define assign_right_shift_interval(name) \
		struct name \
		{ \
			assign_right_shift_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_right_shift_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_right_shift_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_right_shift_as_interval(name, _as_opening)	}; \
				struct open	{ assign_right_shift_as_interval(name, _as_open)	}; \
			}; \
		};

		assign_right_shift_interval(closing)
		assign_right_shift_interval(closed)
		assign_right_shift_interval(opening)
		assign_right_shift_interval(open)

		#undef assign_right_shift_interval
		#undef assign_right_shift_as_interval
	};
/*
	<<=:
*/
	struct left_shift
	{
		#define assign_left_shift_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, <<=) \
		name##_loop_with_return##label##_1(SGN, INV, <<=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, <<=) \
			name##_count_with_return##label##_1(SGN, INV, <<=) \
		};

		#define assign_left_shift_interval(name) \
		struct name \
		{ \
			assign_left_shift_as_interval(name, ) \
 \
			struct as \
			{ \
				struct closing	{ assign_left_shift_as_interval(name, _as_closing)	}; \
				struct closed	{ assign_left_shift_as_interval(name, _as_closed)	}; \
				struct opening	{ assign_left_shift_as_interval(name, _as_opening)	}; \
				struct open	{ assign_left_shift_as_interval(name, _as_open)		}; \
			}; \
		};

		assign_left_shift_interval(closing)
		assign_left_shift_interval(closed)
		assign_left_shift_interval(opening)
		assign_left_shift_interval(open)

		#undef assign_left_shift_interval
		#undef assign_left_shift_as_interval
	};
};

struct allocate
{
	#define allocate_as_interval(name, label) \
	name##_loop_no_return_new##label##_0(SGN, INV) \
	name##_loop_with_return_new##label##_0(SGN, INV) \
 \
	struct brackets \
	{ \
		name##_loop_no_return_new_brackets##label##_0(SGN, INV) \
		name##_loop_with_return_new_brackets##label##_0(SGN, INV) \
 \
		name##_loop_no_return_new_brackets##label##_1(SGN, INV) \
		name##_loop_with_return_new_brackets##label##_1(SGN, INV) \
	}; \
 \
	struct count \
	{ \
		name##_count_no_return_new##label##_0(SGN, INV) \
		name##_count_with_return_new##label##_0(SGN, INV) \
 \
		struct brackets \
		{ \
			name##_count_no_return_new_brackets##label##_0(SGN, INV) \
			name##_count_with_return_new_brackets##label##_0(SGN, INV) \
 \
			name##_count_no_return_new_brackets##label##_1(SGN, INV) \
			name##_count_with_return_new_brackets##label##_1(SGN, INV) \
		}; \
	};

	#define allocate_interval(name) \
	struct name \
	{ \
		allocate_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ allocate_as_interval(name, _as_closing)	}; \
			struct closed	{ allocate_as_interval(name, _as_closed)	}; \
			struct opening	{ allocate_as_interval(name, _as_opening)	}; \
			struct open	{ allocate_as_interval(name, _as_open)		}; \
		}; \
	};

	allocate_interval(closing)
	allocate_interval(closed)
	allocate_interval(opening)
	allocate_interval(open)

	#undef allocate_interval
	#undef allocate_as_interval
};

struct deallocate
{
	#define deallocate_as_interval(name, label) \
	name##_loop_no_return_delete##label##_0(SGN, INV) \
	name##_loop_with_return_delete##label##_0(SGN, INV) \
 \
	struct brackets \
	{ \
		name##_loop_no_return_delete_brackets##label##_0(SGN, INV) \
		name##_loop_with_return_delete_brackets##label##_0(SGN, INV) \
	}; \
 \
	struct count \
	{ \
		name##_count_no_return_delete##label##_0(SGN, INV) \
		name##_count_with_return_delete##label##_0(SGN, INV) \
 \
		struct brackets \
		{ \
			name##_count_no_return_delete_brackets##label##_0(SGN, INV) \
			name##_count_with_return_delete_brackets##label##_0(SGN, INV) \
		}; \
	};

	#define deallocate_interval(name) \
	struct name \
	{ \
		deallocate_as_interval(name, ) \
 \
		struct as \
		{ \
			struct closing	{ deallocate_as_interval(name, _as_closing)	}; \
			struct closed	{ deallocate_as_interval(name, _as_closed)	}; \
			struct opening	{ deallocate_as_interval(name, _as_opening)	}; \
			struct open	{ deallocate_as_interval(name, _as_open)	}; \
		}; \
	};

	deallocate_interval(closing)
	deallocate_interval(closed)
	deallocate_interval(opening)
	deallocate_interval(open)

	#undef deallocate_interval
	#undef deallocate_as_interval
};

