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

struct reverse
{
	#define reverse_interval(name) \
	struct name \
	{ \
		name##_unroll_no_return_reverse(SGN, INV) \
		name##_unroll_with_return_reverse(SGN, INV) \
	};

	reverse_interval(closing)
	reverse_interval(closed)
	reverse_interval(opening)
	reverse_interval(open)

	#undef reverse_interval
};

struct assign
{
	struct reverse
	{
		#define assign_reverse_interval(name) \
		struct name \
		{ \
			name##_unroll_no_return_assign_reverse(SGN, INV) \
			name##_unroll_with_return_assign_reverse(SGN, INV) \
		};

		assign_reverse_interval(closing)
		assign_reverse_interval(closed)
		assign_reverse_interval(opening)
		assign_reverse_interval(open)

		#undef assign_reverse_interval
	};
};

