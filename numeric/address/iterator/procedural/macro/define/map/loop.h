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

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#define declare(name)									\
											\
template<typename L, typename Filler = void>						\
struct name										\
{											\
	static_assert(true, "This method has not yet been declared.");			\
};

/************************************************************************************************************************/
/************************************************************************************************************************/

#define declare_map(name,								\
		out_interval, out_direction,						\
		in_interval, in_direction,						\
		delete_policy, count_policy)						\
											\
template<typename Filler>								\
struct name										\
<											\
	typename gss_traits::template list						\
	<										\
		out_interval, out_direction,						\
		in_interval, in_direction,						\
		delete_policy, count_policy						\
	>,										\
											\
	Filler										\
>

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

//	+:

declare(plus)

declare_map
(
	plus,
	out_as_closing, out_as_forward,
	in_as_closing, in_as_forward,
	omit_delete, omit_count
)
{
	loop_map
	(
		parentheses, =, +,  ,
		out_as_unary, out_as_closing, out_as_forward,
		in_as_binary, in_as_closing, in_as_forward,
		omit_delete, omit_count, apply_return
	)
};

//	-:

//	declare_1_2(minus, =, -, )

//	*:

//	declare_1_2(asterisk, =, *, )

//	/:

//	declare_2(slash, =, /, )

//	%:

//	declare_2(percent, =, %, )

//	ˆ:

//	declare_2(caret, =, ^, )

//	&:

//	declare_1_2(ampersand, =, &, )

//	|:

//	declare_2(bar, =, |, )

//	~:

//	declare_1(tilde, =, ~, )

//	!:

//	declare_1(exclamation, =, !, )

//	<:

//	declare_2(less_than, =, <, )

//	>:

//	declare_2(greater_than, =, <, )

//	<<:

//	declare_2(left_shift, =, <<, )

//	>>:

//	declare_2(right_shift, =, >>, )

//	==:

//	declare_2(equals, =, ==, )

//	!=:

//	declare_2(not_equals, =, !=, )

//	<=:

//	declare_2(less_than_or_equal, =, <=, )

//	>=:

//	declare_2(greater_than_or_equal, =, >=, )

//	&&:

//	declare_2(logical_and, =, &&, )

//	||:

//	declare_2(logical_or, =, ||, )

//	++:

//	declare_0(left_increment,  , ++, )
//	declare_0(right_increment,  , , ++)

//	--:

//	declare_0(left_decrement,  , --, )
//	declare_0(right_decrement,  , , --)

//	,:

struct comma { };

//	->*:

//	declare_2(point_asterisk, =, ->*, )

//	->:

//	declare_2(point, =, .operator->, )

//	():

//	declare_0_1_2(parentheses, parentheses_new, =, new Node, )

//	[]:

//	declare_2(brackets, brackets, =, , )

//	=:

struct repeat
{
	loop_map(
			parentheses, =,  ,  ,
			out_as_unary, out_as_closing, out_as_forward,
			in_as_nullary, in_as_closing, in_as_forward,
			omit_delete, omit_count, apply_return
		)
/*
	#define repeat_as_interval(name, label) \
	name##_loop_no_return##label##_0(SGN, INV, =) \
	name##_loop_with_return##label##_0(SGN, INV, =) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_0(SGN, INV, =) \
		name##_count_with_return##label##_0(SGN, INV, =) \
	}; \
 \
	struct reverse \
	{ \
		name##_reverse_no_return##label##_0(SGN, INV, =) \
		name##_reverse_with_return##label##_0(SGN, INV, =) \
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
*/
/*
	+=:
*/
	struct plus
	{
/*
		#define repeat_plus_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, +=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, +=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, +=) \
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
*/
	};
/*
	-=:
*/
	struct minus
	{
/*
		#define repeat_minus_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, -=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, -=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, -=) \
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
*/
	};
/*
	*=:
*/
	struct asterisk
	{
/*
		#define repeat_asterisk_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, *=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, *=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, *=) \
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
*/
	};
/*
	/=:
*/
	struct slash
	{
/*
		#define repeat_slash_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, /=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, /=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, /=) \
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
*/
	};
/*
	%=:
*/
	struct percent
	{
/*
		#define repeat_percent_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, %=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, %=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, %=) \
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
*/
	};
/*
	ˆ=:
*/
	struct caret
	{
/*
		#define repeat_caret_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, ^=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, ^=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, ^=) \
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
*/
	};
/*
	&=:
*/
	struct ampersand
	{
/*
		#define repeat_ampersand_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, &=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, &=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, &=) \
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
*/
	};
/*
	|=:
*/
	struct bar
	{
/*
		#define repeat_bar_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, |=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, |=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, |=) \
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
*/
	};
/*
	>>=:
*/
	struct right_shift
	{
/*
		#define repeat_right_shift_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, >>=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, >>=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, >>=) \
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
*/
	};
/*
	<<=:
*/
	struct left_shift
	{
/*
		#define repeat_left_shift_as_interval(name, label) \
		name##_loop_no_return##label##_0(SGN, INV, <<=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_0(SGN, INV, <<=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_0(SGN, INV, <<=) \
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
*/
	};
};

/*
	=:
*/

struct assign
{
/*
	#define assign_as_interval(name, label) \
	name##_loop_no_return##label##_1(SGN, INV, =) \
	name##_loop_with_return##label##_1(SGN, INV, =) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_1(SGN, INV, =) \
		name##_count_with_return##label##_1(SGN, INV, =) \
	}; \
 \
	struct reverse \
	{ \
		name##_reverse_no_return##label##_1(SGN, INV, =) \
		name##_reverse_with_return##label##_1(SGN, INV, =) \
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
*/
/*
	+=:
*/
	struct plus
	{
/*
		#define assign_plus_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, +=) \
		name##_loop_with_return##label##_1(SGN, INV, +=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, +=) \
			name##_count_with_return##label##_1(SGN, INV, +=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, +=) \
			name##_reverse_with_return##label##_1(SGN, INV, +=) \
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
*/
	};
/*
	-=:
*/
	struct minus
	{
/*
		#define assign_minus_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, -=) \
		name##_loop_with_return##label##_1(SGN, INV, -=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, -=) \
			name##_count_with_return##label##_1(SGN, INV, -=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, -=) \
			name##_reverse_with_return##label##_1(SGN, INV, -=) \
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
*/
	};
/*
	*=:
*/
	struct asterisk
	{
/*
		#define assign_asterisk_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, *=) \
		name##_loop_with_return##label##_1(SGN, INV, *=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, *=) \
			name##_count_with_return##label##_1(SGN, INV, *=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, *=) \
			name##_reverse_with_return##label##_1(SGN, INV, *=) \
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
*/
	};
/*
	/=:
*/
	struct slash
	{
/*
		#define assign_slash_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, /=) \
		name##_loop_with_return##label##_1(SGN, INV, /=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, /=) \
			name##_count_with_return##label##_1(SGN, INV, /=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, /=) \
			name##_reverse_with_return##label##_1(SGN, INV, /=) \
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
*/
	};
/*
	%=:
*/
	struct percent
	{
/*
		#define assign_percent_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, %=) \
		name##_loop_with_return##label##_1(SGN, INV, %=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, %=) \
			name##_count_with_return##label##_1(SGN, INV, %=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, %=) \
			name##_reverse_with_return##label##_1(SGN, INV, %=) \
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
*/
	};
/*
	ˆ=:
*/
	struct caret
	{
/*
		#define assign_caret_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, ^=) \
		name##_loop_with_return##label##_1(SGN, INV, ^=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, ^=) \
			name##_count_with_return##label##_1(SGN, INV, ^=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, ^=) \
			name##_reverse_with_return##label##_1(SGN, INV, ^=) \
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
*/
	};
/*
	&=:
*/
	struct ampersand
	{
/*
		#define assign_ampersand_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, &=) \
		name##_loop_with_return##label##_1(SGN, INV, &=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, &=) \
			name##_count_with_return##label##_1(SGN, INV, &=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, &=) \
			name##_reverse_with_return##label##_1(SGN, INV, &=) \
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
*/
	};
/*
	|=:
*/
	struct bar
	{
/*
		#define assign_bar_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, |=) \
		name##_loop_with_return##label##_1(SGN, INV, |=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, |=) \
			name##_count_with_return##label##_1(SGN, INV, |=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, |=) \
			name##_reverse_with_return##label##_1(SGN, INV, |=) \
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
*/
	};
/*
	>>=:
*/
	struct right_shift
	{
/*
		#define assign_right_shift_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, >>=) \
		name##_loop_with_return##label##_1(SGN, INV, >>=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, >>=) \
			name##_count_with_return##label##_1(SGN, INV, >>=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, >>=) \
			name##_reverse_with_return##label##_1(SGN, INV, >>=) \
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
*/
	};
/*
	<<=:
*/
	struct left_shift
	{
/*
		#define assign_left_shift_as_interval(name, label) \
		name##_loop_no_return##label##_1(SGN, INV, <<=) \
		name##_loop_with_return##label##_1(SGN, INV, <<=) \
 \
		struct count \
		{ \
			name##_count_no_return##label##_1(SGN, INV, <<=) \
			name##_count_with_return##label##_1(SGN, INV, <<=) \
		}; \
 \
		struct reverse \
		{ \
			name##_reverse_no_return##label##_1(SGN, INV, <<=) \
			name##_reverse_with_return##label##_1(SGN, INV, <<=) \
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
*/
	};
};

struct allocate
{
/*
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
	}; \
 \
	struct reverse \
	{ \
		name##_reverse_no_return_new##label##_0(SGN, INV) \
		name##_reverse_with_return_new##label##_0(SGN, INV) \
 \
		struct brackets \
		{ \
			name##_reverse_no_return_new_brackets##label##_0(SGN, INV) \
			name##_reverse_with_return_new_brackets##label##_0(SGN, INV) \
 \
			name##_reverse_no_return_new_brackets##label##_1(SGN, INV) \
			name##_reverse_with_return_new_brackets##label##_1(SGN, INV) \
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
*/
};

struct deallocate
{
/*
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
	}; \
 \
	struct reverse \
	{ \
		name##_reverse_no_return_delete##label##_0(SGN, INV) \
		name##_reverse_with_return_delete##label##_0(SGN, INV) \
 \
		struct brackets \
		{ \
			name##_reverse_no_return_delete_brackets##label##_0(SGN, INV) \
			name##_reverse_with_return_delete_brackets##label##_0(SGN, INV) \
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
*/
};

