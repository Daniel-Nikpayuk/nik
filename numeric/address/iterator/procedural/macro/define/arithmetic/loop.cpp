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
*/

struct zero
{
	#define zero_interval(name) \
	struct name \
	{ \
		name##_loop_no_break_zero(SGN, INV) \
		name##_loop_with_break_zero(SGN, INV) \
 \
		struct fast \
		{ \
			name##_loop_no_break_zero_fast(SGN, INV) \
			name##_loop_with_break_zero_fast(SGN, INV) \
		}; \
 \
		struct count \
		{ \
			name##_count_no_break_zero(SGN, INV) \
			name##_count_with_break_zero(SGN, INV) \
 \
			struct fast \
			{ \
				name##_count_no_break_zero_fast(SGN, INV) \
				name##_count_with_break_zero_fast(SGN, INV) \
			}; \
		}; \
	};

	zero_interval(closing)
	zero_interval(closed)
	zero_interval(opening)
	zero_interval(open)

	#undef zero_interval
};

struct equal
{
	#define equal_interval(name) \
	struct name \
	{ \
		name##_loop_no_break_equal(SGN, INV) \
		name##_loop_with_break_equal(SGN, INV) \
 \
		struct fast \
		{ \
			name##_loop_no_break_equal_fast(SGN, INV) \
			name##_loop_with_break_equal_fast(SGN, INV) \
		}; \
 \
		struct count \
		{ \
			name##_count_no_break_equal(SGN, INV) \
			name##_count_with_break_equal(SGN, INV) \
 \
			struct fast \
			{ \
				name##_count_no_break_equal_fast(SGN, INV) \
				name##_count_with_break_equal_fast(SGN, INV) \
			}; \
		}; \
	};

	equal_interval(closing)
	equal_interval(closed)
	equal_interval(opening)
	equal_interval(open)

	#undef equal_interval
};

struct not_equal
{
	#define not_equal_interval(name) \
	struct name \
	{ \
		name##_loop_no_break_not_equal(SGN, INV) \
		name##_loop_with_break_not_equal(SGN, INV) \
 \
		struct fast \
		{ \
			name##_loop_no_break_not_equal_fast(SGN, INV) \
			name##_loop_with_break_not_equal_fast(SGN, INV) \
		}; \
 \
		struct count \
		{ \
			name##_count_no_break_not_equal(SGN, INV) \
			name##_count_with_break_not_equal(SGN, INV) \
 \
			struct fast \
			{ \
				name##_count_no_break_not_equal_fast(SGN, INV) \
				name##_count_with_break_not_equal_fast(SGN, INV) \
			}; \
		}; \
	};

	not_equal_interval(closing)
	not_equal_interval(closed)
	not_equal_interval(opening)
	not_equal_interval(open)

	#undef not_equal_interval
};

struct less_than
{
	#define less_than_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_less_than(SGN, INV) \
		name##_loop_with_return_less_than(SGN, INV) \
		name##_loop_fast_return_less_than(SGN, INV) \
 \
		struct count \
		{ \
			name##_count_no_return_less_than(SGN, INV) \
			name##_count_with_return_less_than(SGN, INV) \
			name##_count_fast_return_less_than(SGN, INV) \
		}; \
	};

	less_than_interval(closing)
	less_than_interval(closed)
	less_than_interval(opening)
	less_than_interval(open)

	#undef less_than_interval
};

struct less_than_or_equal
{
	#define less_than_or_equal_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_less_than_or_equal(SGN, INV) \
		name##_loop_with_return_less_than_or_equal(SGN, INV) \
		name##_loop_fast_return_less_than_or_equal(SGN, INV) \
 \
		struct count \
		{ \
			name##_count_no_return_less_than_or_equal(SGN, INV) \
			name##_count_with_return_less_than_or_equal(SGN, INV) \
			name##_count_fast_return_less_than_or_equal(SGN, INV) \
		}; \
	};

	less_than_or_equal_interval(closing)
	less_than_or_equal_interval(closed)
	less_than_or_equal_interval(opening)
	less_than_or_equal_interval(open)

	#undef less_than_or_equal_interval
};

struct greater_than
{
	#define greater_than_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_greater_than(SGN, INV) \
		name##_loop_with_return_greater_than(SGN, INV) \
		name##_loop_fast_return_greater_than(SGN, INV) \
 \
		struct count \
		{ \
			name##_count_no_return_greater_than(SGN, INV) \
			name##_count_with_return_greater_than(SGN, INV) \
			name##_count_fast_return_greater_than(SGN, INV) \
		}; \
	};

	greater_than_interval(closing)
	greater_than_interval(closed)
	greater_than_interval(opening)
	greater_than_interval(open)

	#undef greater_than_interval
};

struct greater_than_or_equal
{
	#define greater_than_or_equal_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_greater_than_or_equal(SGN, INV) \
		name##_loop_with_return_greater_than_or_equal(SGN, INV) \
		name##_loop_fast_return_greater_than_or_equal(SGN, INV) \
 \
		struct count \
		{ \
			name##_count_no_return_greater_than_or_equal(SGN, INV) \
			name##_count_with_return_greater_than_or_equal(SGN, INV) \
			name##_count_fast_return_greater_than_or_equal(SGN, INV) \
		}; \
	};

	greater_than_or_equal_interval(closing)
	greater_than_or_equal_interval(closed)
	greater_than_or_equal_interval(opening)
	greater_than_or_equal_interval(open)

	#undef greater_than_or_equal_interval
};

struct plus
{
	#define plus_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_plus(SGN, INV) \
		name##_loop_with_return_plus(SGN, INV) \
 \
		struct half \
		{ \
			name##_loop_no_return_plus_half(SGN, INV) \
			name##_loop_with_return_plus_half(SGN, INV) \
		}; \
 \
		struct count \
		{ \
			name##_count_no_return_plus(SGN, INV) \
			name##_count_with_return_plus(SGN, INV) \
 \
			struct half \
			{ \
				name##_count_no_return_plus_half(SGN, INV) \
				name##_count_with_return_plus_half(SGN, INV) \
			}; \
		}; \
	};

	plus_interval(closing)
	plus_interval(closed)
	plus_interval(opening)
	plus_interval(open)

	#undef plus_interval
};

struct minus
{
	#define minus_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_minus(SGN, INV) \
		name##_loop_with_return_minus(SGN, INV) \
 \
		struct half \
		{ \
			name##_loop_no_return_minus_half(SGN, INV) \
			name##_loop_with_return_minus_half(SGN, INV) \
		}; \
 \
		struct count \
		{ \
			name##_count_no_return_minus(SGN, INV) \
			name##_count_with_return_minus(SGN, INV) \
 \
			struct half \
			{ \
				name##_count_no_return_minus_half(SGN, INV) \
				name##_count_with_return_minus_half(SGN, INV) \
			}; \
		}; \
	};

	minus_interval(closing)
	minus_interval(closed)
	minus_interval(opening)
	minus_interval(open)

	#undef minus_interval
};

struct scale
{
	#define scale_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_scale(SGN, INV) \
		name##_loop_with_return_scale(SGN, INV) \
 \
		struct half \
		{ \
			name##_loop_no_return_scale_half(SGN, INV) \
			name##_loop_with_return_scale_half(SGN, INV) \
		}; \
 \
		struct count \
		{ \
			name##_count_no_return_scale(SGN, INV) \
			name##_count_with_return_scale(SGN, INV) \
 \
			struct half \
			{ \
				name##_count_no_return_scale_half(SGN, INV) \
				name##_count_with_return_scale_half(SGN, INV) \
			}; \
		}; \
	};

	scale_interval(closing)
	scale_interval(closed)
	scale_interval(opening)
	scale_interval(open)

	#undef scale_interval
};

struct divide
{
	#define divide_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_divide(SGN, INV) \
		name##_loop_with_return_divide(SGN, INV) \
 \
		struct half_digit \
		{ \
			name##_loop_no_return_divide_half_digit(SGN, INV) \
			name##_loop_with_return_divide_half_digit(SGN, INV) \
		}; \
 \
		struct single_digit \
		{ \
			name##_loop_no_return_divide_single_digit(SGN, INV) \
			name##_loop_with_return_divide_single_digit(SGN, INV) \
 \
			struct half \
			{ \
				name##_loop_no_return_divide_single_digit_half(SGN, INV) \
				name##_loop_with_return_divide_single_digit_half(SGN, INV) \
			}; \
		}; \
 \
		struct count \
		{ \
			name##_count_no_return_divide(SGN, INV) \
			name##_count_with_return_divide(SGN, INV) \
 \
			struct half_digit \
			{ \
				name##_count_no_return_divide_half_digit(SGN, INV) \
				name##_count_with_return_divide_half_digit(SGN, INV) \
			}; \
 \
			struct single_digit \
			{ \
				name##_count_no_return_divide_single_digit(SGN, INV) \
				name##_count_with_return_divide_single_digit(SGN, INV) \
 \
				struct half \
				{ \
					name##_count_no_return_divide_single_digit_half(SGN, INV) \
					name##_count_with_return_divide_single_digit_half(SGN, INV) \
				}; \
			}; \
		}; \
	};

	divide_interval(closing)
	divide_interval(closed)
	divide_interval(opening)
	divide_interval(open)

	#undef divide_interval
};

struct multiply
{
	#define multiply_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_multiply(SGN, INV) \
		name##_loop_with_return_multiply(SGN, INV) \
 \
		struct half \
		{ \
			name##_loop_no_return_multiply_half(SGN, INV) \
			name##_loop_with_return_multiply_half(SGN, INV) \
		}; \
 \
		struct count \
		{ \
			name##_count_no_return_multiply(SGN, INV) \
			name##_count_with_return_multiply(SGN, INV) \
 \
			struct half \
			{ \
				name##_count_no_return_multiply_half(SGN, INV) \
				name##_count_with_return_multiply_half(SGN, INV) \
			}; \
		}; \
	};

	multiply_interval(closing)
	multiply_interval(closed)
	multiply_interval(opening)
	multiply_interval(open)

	#undef multiply_interval
};

struct assign
{
	struct plus
	{
		#define assign_plus_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_assign_plus(SGN, INV) \
			name##_loop_with_return_assign_plus(SGN, INV) \
 \
			struct half \
			{ \
				name##_loop_no_return_assign_plus_half(SGN, INV) \
				name##_loop_with_return_assign_plus_half(SGN, INV) \
			}; \
 \
			struct count \
			{ \
				name##_count_no_return_assign_plus(SGN, INV) \
				name##_count_with_return_assign_plus(SGN, INV) \
 \
				struct half \
				{ \
					name##_count_no_return_assign_plus_half(SGN, INV) \
					name##_count_with_return_assign_plus_half(SGN, INV) \
				}; \
			}; \
		};

		assign_plus_interval(closing)
		assign_plus_interval(closed)
		assign_plus_interval(opening)
		assign_plus_interval(open)

		#undef assign_plus_interval
	};

	struct minus
	{
		#define assign_minus_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_assign_minus(SGN, INV) \
			name##_loop_with_return_assign_minus(SGN, INV) \
 \
			struct half \
			{ \
				name##_loop_no_return_assign_minus_half(SGN, INV) \
				name##_loop_with_return_assign_minus_half(SGN, INV) \
			}; \
 \
			struct count \
			{ \
				name##_count_no_return_assign_minus(SGN, INV) \
				name##_count_with_return_assign_minus(SGN, INV) \
 \
				struct half \
				{ \
					name##_count_no_return_assign_minus_half(SGN, INV) \
					name##_count_with_return_assign_minus_half(SGN, INV) \
				}; \
			}; \
		};

		assign_minus_interval(closing)
		assign_minus_interval(closed)
		assign_minus_interval(opening)
		assign_minus_interval(open)

		#undef assign_minus_interval
	};

	struct scale
	{
		#define assign_scale_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_assign_scale(SGN, INV) \
			name##_loop_with_return_assign_scale(SGN, INV) \
 \
			struct half \
			{ \
				name##_loop_no_return_assign_scale_half(SGN, INV) \
				name##_loop_with_return_assign_scale_half(SGN, INV) \
			}; \
 \
			struct count \
			{ \
				name##_count_no_return_assign_scale(SGN, INV) \
				name##_count_with_return_assign_scale(SGN, INV) \
 \
				struct half \
				{ \
					name##_count_no_return_assign_scale_half(SGN, INV) \
					name##_count_with_return_assign_scale_half(SGN, INV) \
				}; \
			}; \
		};

		assign_scale_interval(closing)
		assign_scale_interval(closed)
		assign_scale_interval(opening)
		assign_scale_interval(open)

		#undef assign_scale_interval
	};

	struct divide
	{
		#define assign_divide_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_assign_divide(SGN, INV) \
			name##_loop_with_return_assign_divide(SGN, INV) \
 \
			struct half_digit \
			{ \
				name##_loop_no_return_assign_divide_half_digit(SGN, INV) \
				name##_loop_with_return_assign_divide_half_digit(SGN, INV) \
			}; \
 \
			struct single_digit \
			{ \
				name##_loop_no_return_assign_divide_single_digit(SGN, INV) \
				name##_loop_with_return_assign_divide_single_digit(SGN, INV) \
 \
				struct half \
				{ \
					name##_loop_no_return_assign_divide_single_digit_half(SGN, INV) \
					name##_loop_with_return_assign_divide_single_digit_half(SGN, INV) \
				}; \
			}; \
 \
			struct count \
			{ \
				name##_count_no_return_assign_divide(SGN, INV) \
				name##_count_with_return_assign_divide(SGN, INV) \
 \
				struct half_digit \
				{ \
					name##_count_no_return_assign_divide_half_digit(SGN, INV) \
					name##_count_with_return_assign_divide_half_digit(SGN, INV) \
				}; \
 \
				struct single_digit \
				{ \
					name##_count_no_return_assign_divide_single_digit(SGN, INV) \
					name##_count_with_return_assign_divide_single_digit(SGN, INV) \
 \
					struct half \
					{ \
						name##_count_no_return_assign_divide_single_digit_half(SGN, INV) \
						name##_count_with_return_assign_divide_single_digit_half(SGN, INV) \
					}; \
				}; \
			}; \
		};

		assign_divide_interval(closing)
		assign_divide_interval(closed)
		assign_divide_interval(opening)
		assign_divide_interval(open)

		#undef assign_divide_interval
	};

	struct multiply
	{
		#define assign_multiply_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_assign_multiply(SGN, INV) \
			name##_loop_with_return_assign_multiply(SGN, INV) \
 \
			struct half \
			{ \
				name##_loop_no_return_assign_multiply_half(SGN, INV) \
				name##_loop_with_return_assign_multiply_half(SGN, INV) \
			}; \
 \
			struct count \
			{ \
				name##_count_no_return_assign_multiply(SGN, INV) \
				name##_count_with_return_assign_multiply(SGN, INV) \
 \
				struct half \
				{ \
					name##_count_no_return_assign_multiply_half(SGN, INV) \
					name##_count_with_return_assign_multiply_half(SGN, INV) \
				}; \
			}; \
		};

		assign_multiply_interval(closing)
		assign_multiply_interval(closed)
		assign_multiply_interval(opening)
		assign_multiply_interval(open)

		#undef assign_multiply_interval
	};
};

