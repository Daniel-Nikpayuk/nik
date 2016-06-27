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

struct clear
{
	#define clear_interval(name) \
	struct name \
	{ \
		name##_loop_no_return_clear(SGN, INV) \
		name##_loop_with_return_clear(SGN, INV) \
 \
		struct count \
		{ \
			name##_count_no_return_clear(SGN, INV) \
			name##_count_with_return_clear(SGN, INV) \
		}; \
	};

	clear_interval(closing)
	clear_interval(closed)
	clear_interval(opening)
	clear_interval(open)

	#undef clear_interval
};

struct close
{
	struct left
	{
		#define close_left_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_close_left(SGN, INV) \
			name##_loop_with_return_close_left(SGN, INV) \
 \
			struct count \
			{ \
				name##_count_no_return_close_left(SGN, INV) \
				name##_count_with_return_close_left(SGN, INV) \
			}; \
		};

		close_left_interval(closing)
		close_left_interval(closed)
		close_left_interval(opening)
		close_left_interval(open)

		#undef close_left_interval
	};

	struct right
	{
		#define close_right_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_close_right(SGN, INV) \
			name##_loop_with_return_close_right(SGN, INV) \
 \
			struct count \
			{ \
				name##_count_no_return_close_right(SGN, INV) \
				name##_count_with_return_close_right(SGN, INV) \
			}; \
		};

		close_right_interval(closing)
		close_right_interval(closed)
		close_right_interval(opening)
		close_right_interval(open)

		#undef close_right_interval
	};
};

struct open
{
	struct left
	{
		#define open_left_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_open_left(SGN, INV) \
			name##_loop_with_return_open_left(SGN, INV) \
 \
			struct count \
			{ \
				name##_count_no_return_open_left(SGN, INV) \
				name##_count_with_return_open_left(SGN, INV) \
			}; \
		};

		open_left_interval(closing)
		open_left_interval(closed)
		open_left_interval(opening)
		open_left_interval(open)

		#undef open_left_interval
	};

	struct right
	{
		#define open_right_interval(name) \
		struct name \
		{ \
			name##_loop_no_return_open_right(SGN, INV) \
			name##_loop_with_return_open_right(SGN, INV) \
 \
			struct count \
			{ \
				name##_count_no_return_open_right(SGN, INV) \
				name##_count_with_return_open_right(SGN, INV) \
			}; \
		};

		open_right_interval(closing)
		open_right_interval(closed)
		open_right_interval(opening)
		open_right_interval(open)

		#undef open_right_interval
	};
};

struct catenate
{
	#define catenate_with_interval(name, label) \
	name##_loop_no_return##label##_catenate(SGN, INV) \
	name##_loop_with_return##label##_catenate(SGN, INV) \
 \
	struct count \
	{ \
		name##_count_no_return##label##_catenate(SGN, INV) \
		name##_count_with_return##label##_catenate(SGN, INV) \
	};

	#define catenate_interval(name) \
	struct name \
	{ \
		struct with \
		{ \
			catenate_with_interval(name, ) \
 \
			struct closing	{ catenate_with_interval(name, _with_closing)	}; \
			struct closed	{ catenate_with_interval(name, _with_closed)	}; \
			struct opening	{ catenate_with_interval(name, _with_opening)	}; \
			struct open	{ catenate_with_interval(name, _with_open)	}; \
		}; \
	};

	catenate_interval(closing)
	catenate_interval(closed)
	catenate_interval(opening)
	catenate_interval(open)

	#undef catenate_interval
	#undef catenate_with_interval
};

