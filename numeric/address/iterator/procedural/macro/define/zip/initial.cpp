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
	#define plus_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_1(SGN, INV, =+) \
		name##_initial_with_return_1(SGN, INV, =+) \
 \
		name##_initial_no_return_2(SGN, INV, +) \
		name##_initial_with_return_2(SGN, INV, +) \
	};

	plus_interval(closing)
	plus_interval(closed)
	plus_interval(opening)
	plus_interval(open)

	#undef plus_interval
};

/*
	-:

	"=-" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct minus
{
	#define minus_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_1(SGN, INV, =-) \
		name##_initial_with_return_1(SGN, INV, =-) \
 \
		name##_initial_no_return_2(SGN, INV, -) \
		name##_initial_with_return_2(SGN, INV, -) \
	};

	minus_interval(closing)
	minus_interval(closed)
	minus_interval(opening)
	minus_interval(open)

	#undef minus_interval
};

/*
	*:

	"=*" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct asterisk
{
	#define asterisk_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_1(SGN, INV, =*) \
		name##_initial_with_return_1(SGN, INV, =*) \
 \
		name##_initial_no_return_2(SGN, INV, *) \
		name##_initial_with_return_2(SGN, INV, *) \
	};

	asterisk_interval(closing)
	asterisk_interval(closed)
	asterisk_interval(opening)
	asterisk_interval(open)

	#undef asterisk_interval
};

/*
	/:
*/

struct slash
{
	#define slash_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, /) \
		name##_initial_with_return_2(SGN, INV, /) \
	};

	slash_interval(closing)
	slash_interval(closed)
	slash_interval(opening)
	slash_interval(open)

	#undef slash_interval
};

/*
	%:
*/

struct percent
{
	#define percent_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, %) \
		name##_initial_with_return_2(SGN, INV, %) \
	};

	percent_interval(closing)
	percent_interval(closed)
	percent_interval(opening)
	percent_interval(open)

	#undef percent_interval
};

/*
	ˆ:
*/

struct caret
{
	#define caret_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, ^) \
		name##_initial_with_return_2(SGN, INV, ^) \
	};

	caret_interval(closing)
	caret_interval(closed)
	caret_interval(opening)
	caret_interval(open)

	#undef caret_interval
};

/*
	&:

	"=&" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct ampersand
{
	#define ampersand_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_1(SGN, INV, =&) \
		name##_initial_with_return_1(SGN, INV, =&) \
 \
		name##_initial_no_return_2(SGN, INV, &) \
		name##_initial_with_return_2(SGN, INV, &) \
	};

	ampersand_interval(closing)
	ampersand_interval(closed)
	ampersand_interval(opening)
	ampersand_interval(open)

	#undef ampersand_interval
};

/*
	|:
*/

struct bar
{
	#define bar_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, |) \
		name##_initial_with_return_2(SGN, INV, |) \
	};

	bar_interval(closing)
	bar_interval(closed)
	bar_interval(opening)
	bar_interval(open)

	#undef bar_interval
};

/*
	~:

	"=~" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct tilde
{
	#define tilde_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_1(SGN, INV, =~) \
		name##_initial_with_return_1(SGN, INV, =~) \
	};

	tilde_interval(closing)
	tilde_interval(closed)
	tilde_interval(opening)
	tilde_interval(open)

	#undef tilde_interval
};

/*
	!:

	"=!" might appear as a typo, but as a single inputiterator operator, it makes sense.
*/

struct exclamation
{
	#define exclamation_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_1(SGN, INV, =!) \
		name##_initial_with_return_1(SGN, INV, =!) \
	};

	exclamation_interval(closing)
	exclamation_interval(closed)
	exclamation_interval(opening)
	exclamation_interval(open)

	#undef exclamation_interval
};

/*
	<:
*/

struct less_than
{
	#define less_than_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, <) \
		name##_initial_with_return_2(SGN, INV, <) \
	};

	less_than_interval(closing)
	less_than_interval(closed)
	less_than_interval(opening)
	less_than_interval(open)

	#undef less_than_interval
};

/*
	>:
*/

struct greater_than
{
	#define greater_than_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, >) \
		name##_initial_with_return_2(SGN, INV, >) \
	};

	greater_than_interval(closing)
	greater_than_interval(closed)
	greater_than_interval(opening)
	greater_than_interval(open)

	#undef greater_than_interval
};

/*
	<<:
*/

struct left_shift
{
	#define left_shift_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, <<) \
		name##_initial_with_return_2(SGN, INV, <<) \
	};

	left_shift_interval(closing)
	left_shift_interval(closed)
	left_shift_interval(opening)
	left_shift_interval(open)

	#undef left_shift_interval
};

/*
	>>:
*/

struct right_shift
{
	#define right_shift_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, >>) \
		name##_initial_with_return_2(SGN, INV, >>) \
	};

	right_shift_interval(closing)
	right_shift_interval(closed)
	right_shift_interval(opening)
	right_shift_interval(open)

	#undef right_shift_interval
};

/*
	==:
*/

struct equals
{
	#define equals_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, ==) \
		name##_initial_with_return_2(SGN, INV, ==) \
	};

	equals_interval(closing)
	equals_interval(closed)
	equals_interval(opening)
	equals_interval(open)

	#undef equals_interval
};

/*
	!=:
*/

struct not_equals
{
	#define not_equals_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, !=) \
		name##_initial_with_return_2(SGN, INV, !=) \
	};

	not_equals_interval(closing)
	not_equals_interval(closed)
	not_equals_interval(opening)
	not_equals_interval(open)

	#undef not_equals_interval
};

/*
	<=:
*/

struct less_than_or_equal
{
	#define less_than_or_equal_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, <=) \
		name##_initial_with_return_2(SGN, INV, <=) \
	};

	less_than_or_equal_interval(closing)
	less_than_or_equal_interval(closed)
	less_than_or_equal_interval(opening)
	less_than_or_equal_interval(open)

	#undef less_than_or_equal_interval
};

/*
	>=:
*/

struct greater_than_or_equal
{
	#define greater_than_or_equal_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, >=) \
		name##_initial_with_return_2(SGN, INV, >=) \
	};

	greater_than_or_equal_interval(closing)
	greater_than_or_equal_interval(closed)
	greater_than_or_equal_interval(opening)
	greater_than_or_equal_interval(open)

	#undef greater_than_or_equal_interval
};

/*
	&&:
*/

struct logical_and
{
	#define logical_and_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, &&) \
		name##_initial_with_return_2(SGN, INV, &&) \
	};

	logical_and_interval(closing)
	logical_and_interval(closed)
	logical_and_interval(opening)
	logical_and_interval(open)

	#undef logical_and_interval
};

/*
	||:
*/

struct logical_or
{
	#define logical_or_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, ||) \
		name##_initial_with_return_2(SGN, INV, ||) \
	};

	logical_or_interval(closing)
	logical_or_interval(closed)
	logical_or_interval(opening)
	logical_or_interval(open)

	#undef logical_or_interval
};

/*
	++:
*/

struct left_increment
{
	#define left_increment_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_left_0(SGN, INV, ++) \
	};

	left_increment_interval(closing)
	left_increment_interval(closed)
	left_increment_interval(opening)
	left_increment_interval(open)

	#undef left_increment_interval
};

struct right_increment
{
	#define right_increment_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_right_0(SGN, INV, ++) \
	};

	right_increment_interval(closing)
	right_increment_interval(closed)
	right_increment_interval(opening)
	right_increment_interval(open)

	#undef right_increment_interval
};

/*
	--:
*/

struct left_decrement
{
	#define left_decrement_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_left_0(SGN, INV, --) \
	};

	left_decrement_interval(closing)
	left_decrement_interval(closed)
	left_decrement_interval(opening)
	left_decrement_interval(open)

	#undef left_decrement_interval
};

struct right_decrement
{
	#define right_decrement_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_right_0(SGN, INV, --) \
	};

	right_decrement_interval(closing)
	right_decrement_interval(closed)
	right_decrement_interval(opening)
	right_decrement_interval(open)

	#undef right_decrement_interval
};

/*
	,:
*/

struct comma
{
	#define comma_interval(name) \
	struct name \
	{ \
	};

	comma_interval(closing)
	comma_interval(closed)
	comma_interval(opening)
	comma_interval(open)

	#undef comma_interval
};

/*
	->*:
*/

struct point_asterisk
{
	#define point_asterisk_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_2(SGN, INV, ->*) \
		name##_initial_with_return_2(SGN, INV, ->*) \
	};

	point_asterisk_interval(closing)
	point_asterisk_interval(closed)
	point_asterisk_interval(opening)
	point_asterisk_interval(open)

	#undef point_asterisk_interval
};

/*
	->:
*/

struct point
{
	#define point_interval(name) \
	struct name \
	{ \
		name##_initial_with_return_2(SGN, INV, .operator->) \
	};

	point_interval(closing)
	point_interval(closed)
	point_interval(opening)
	point_interval(open)

	#undef point_interval
};

/*
	():

	if this doesn't work, you might be able to include parentheses in the macro itself and leave the macro argument "op" blank.
*/

struct parentheses
{
	#define parentheses_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_right_0(SGN, INV, ()) \
 \
		name##_initial_no_return_right_1(SGN, INV, =, ()) \
		name##_initial_with_return_right_1(SGN, INV, =, ()) \
 \
		name##_initial_no_return_2(SGN, INV, ) \
		name##_initial_with_return_2(SGN, INV, ) \
	};

	parentheses_interval(closing)
	parentheses_interval(closed)
	parentheses_interval(opening)
	parentheses_interval(open)

	#undef parentheses_interval
};

/*
	[]:
*/

struct brackets
{
	#define brackets_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_brackets_2(SGN, INV, ) \
		name##_initial_with_return_brackets_2(SGN, INV, ) \
	};

	brackets_interval(closing)
	brackets_interval(closed)
	brackets_interval(opening)
	brackets_interval(open)

	#undef brackets_interval
};

/*
	=:
*/

struct repeat
{
	#define repeat_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_0(SGN, INV, =) \
		name##_initial_with_return_0(SGN, INV, =) \
	};

	repeat_interval(closing)
	repeat_interval(closed)
	repeat_interval(opening)
	repeat_interval(open)

	#undef repeat_interval
/*
	+=:
*/
	struct plus
	{
		#define repeat_plus_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, +=) \
		};

		repeat_plus_interval(closing)
		repeat_plus_interval(closed)
		repeat_plus_interval(opening)
		repeat_plus_interval(open)

		#undef repeat_plus_interval
	};
/*
	-=:
*/
	struct minus
	{
		#define repeat_minus_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, -=) \
		};

		repeat_minus_interval(closing)
		repeat_minus_interval(closed)
		repeat_minus_interval(opening)
		repeat_minus_interval(open)

		#undef repeat_minus_interval
	};
/*
	*=:
*/
	struct asterisk
	{
		#define repeat_asterisk_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, *=) \
		};

		repeat_asterisk_interval(closing)
		repeat_asterisk_interval(closed)
		repeat_asterisk_interval(opening)
		repeat_asterisk_interval(open)

		#undef repeat_asterisk_interval
	};
/*
	/=:
*/
	struct slash
	{
		#define repeat_slash_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, /=) \
		};

		repeat_slash_interval(closing)
		repeat_slash_interval(closed)
		repeat_slash_interval(opening)
		repeat_slash_interval(open)

		#undef repeat_slash_interval
	};
/*
	%=:
*/
	struct percent
	{
		#define repeat_percent_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, %=) \
		};

		repeat_percent_interval(closing)
		repeat_percent_interval(closed)
		repeat_percent_interval(opening)
		repeat_percent_interval(open)

		#undef repeat_percent_interval
	};
/*
	ˆ=:
*/
	struct caret
	{
		#define repeat_caret_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, ^=) \
		};

		repeat_caret_interval(closing)
		repeat_caret_interval(closed)
		repeat_caret_interval(opening)
		repeat_caret_interval(open)

		#undef repeat_caret_interval
	};
/*
	&=:
*/
	struct ampersand
	{
		#define repeat_ampersand_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, &=) \
		};

		repeat_ampersand_interval(closing)
		repeat_ampersand_interval(closed)
		repeat_ampersand_interval(opening)
		repeat_ampersand_interval(open)

		#undef repeat_ampersand_interval
	};
/*
	|=:
*/
	struct bar
	{
		#define repeat_bar_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, |=) \
		};

		repeat_bar_interval(closing)
		repeat_bar_interval(closed)
		repeat_bar_interval(opening)
		repeat_bar_interval(open)

		#undef repeat_bar_interval
	};
/*
	>>=:
*/
	struct right_shift
	{
		#define repeat_right_shift_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, >>=) \
		};

		repeat_right_shift_interval(closing)
		repeat_right_shift_interval(closed)
		repeat_right_shift_interval(opening)
		repeat_right_shift_interval(open)

		#undef repeat_right_shift_interval
	};
/*
	<<=:
*/
	struct left_shift
	{
		#define repeat_left_shift_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_0(SGN, INV, <<=) \
		};

		repeat_left_shift_interval(closing)
		repeat_left_shift_interval(closed)
		repeat_left_shift_interval(opening)
		repeat_left_shift_interval(open)

		#undef repeat_left_shift_interval
	};
};

/*
	=:
*/

struct assign
{
	#define assign_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_1(SGN, INV, =) \
		name##_initial_with_return_1(SGN, INV, =) \
	};

	assign_interval(closing)
	assign_interval(closed)
	assign_interval(opening)
	assign_interval(open)

	#undef assign_interval
/*
	+=:
*/
	struct plus
	{
		#define assign_plus_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, +=) \
			name##_initial_with_return_1(SGN, INV, +=) \
		};

		assign_plus_interval(closing)
		assign_plus_interval(closed)
		assign_plus_interval(opening)
		assign_plus_interval(open)

		#undef assign_plus_interval
	};
/*
	-=:
*/
	struct minus
	{
		#define assign_minus_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, -=) \
			name##_initial_with_return_1(SGN, INV, -=) \
		};

		assign_minus_interval(closing)
		assign_minus_interval(closed)
		assign_minus_interval(opening)
		assign_minus_interval(open)

		#undef assign_minus_interval
	};
/*
	*=:
*/
	struct asterisk
	{
		#define assign_asterisk_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, *=) \
			name##_initial_with_return_1(SGN, INV, *=) \
		};

		assign_asterisk_interval(closing)
		assign_asterisk_interval(closed)
		assign_asterisk_interval(opening)
		assign_asterisk_interval(open)

		#undef assign_asterisk_interval
	};
/*
	/=:
*/
	struct slash
	{
		#define assign_slash_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, /=) \
			name##_initial_with_return_1(SGN, INV, /=) \
		};

		assign_slash_interval(closing)
		assign_slash_interval(closed)
		assign_slash_interval(opening)
		assign_slash_interval(open)

		#undef assign_slash_interval
	};
/*
	%=:
*/
	struct percent
	{
		#define assign_percent_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, %=) \
			name##_initial_with_return_1(SGN, INV, %=) \
		};

		assign_percent_interval(closing)
		assign_percent_interval(closed)
		assign_percent_interval(opening)
		assign_percent_interval(open)

		#undef assign_percent_interval
	};
/*
	ˆ=:
*/
	struct caret
	{
		#define assign_caret_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, ^=) \
			name##_initial_with_return_1(SGN, INV, ^=) \
		};

		assign_caret_interval(closing)
		assign_caret_interval(closed)
		assign_caret_interval(opening)
		assign_caret_interval(open)

		#undef assign_caret_interval
	};
/*
	&=:
*/
	struct ampersand
	{
		#define assign_ampersand_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, &=) \
			name##_initial_with_return_1(SGN, INV, &=) \
		};

		assign_ampersand_interval(closing)
		assign_ampersand_interval(closed)
		assign_ampersand_interval(opening)
		assign_ampersand_interval(open)

		#undef assign_ampersand_interval
	};
/*
	|=:
*/
	struct bar
	{
		#define assign_bar_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, |=) \
			name##_initial_with_return_1(SGN, INV, |=) \
		};

		assign_bar_interval(closing)
		assign_bar_interval(closed)
		assign_bar_interval(opening)
		assign_bar_interval(open)

		#undef assign_bar_interval
	};
/*
	>>=:
*/
	struct right_shift
	{
		#define assign_right_shift_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, >>=) \
			name##_initial_with_return_1(SGN, INV, >>=) \
		};

		assign_right_shift_interval(closing)
		assign_right_shift_interval(closed)
		assign_right_shift_interval(opening)
		assign_right_shift_interval(open)

		#undef assign_right_shift_interval
	};
/*
	<<=:
*/
	struct left_shift
	{
		#define assign_left_shift_interval(name) \
		struct name \
		{ \
			name##_initial_no_return_1(SGN, INV, <<=) \
			name##_initial_with_return_1(SGN, INV, <<=) \
		};

		assign_left_shift_interval(closing)
		assign_left_shift_interval(closed)
		assign_left_shift_interval(opening)
		assign_left_shift_interval(open)

		#undef assign_left_shift_interval
	};
};

struct allocate
{
	#define allocate_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_new_0(SGN, INV) \
		name##_initial_with_return_new_0(SGN, INV) \
 \
		struct brackets \
		{ \
			name##_initial_no_return_new_brackets_0(SGN, INV) \
			name##_initial_with_return_new_brackets_0(SGN, INV) \
 \
			name##_initial_no_return_new_brackets_1(SGN, INV) \
			name##_initial_with_return_new_brackets_1(SGN, INV) \
		}; \
	};

	allocate_interval(closing)
	allocate_interval(closed)
	allocate_interval(opening)
	allocate_interval(open)

	#undef allocate_interval
};

struct deallocate
{
	#define deallocate_interval(name) \
	struct name \
	{ \
		name##_initial_no_return_delete_0(SGN, INV) \
		name##_initial_with_return_delete_0(SGN, INV) \
 \
		struct brackets \
		{ \
			name##_initial_no_return_delete_brackets_0(SGN, INV) \
			name##_initial_with_return_delete_brackets_0(SGN, INV) \
		}; \
	};

	deallocate_interval(closing)
	deallocate_interval(closed)
	deallocate_interval(opening)
	deallocate_interval(open)

	#undef deallocate_interval
};

