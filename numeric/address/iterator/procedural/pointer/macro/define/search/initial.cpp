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

struct find
{
	struct index
	{
		struct before
		{
			struct last
			{
				#define find_index_before_last_interval(name) \
				struct name \
				{ \
					name##_initial_no_return_find_index_before_last(SGN, INV) \
					name##_initial_with_return_find_index_before_last(SGN, INV) \
				};

				find_index_before_last_interval(closing)
				find_index_before_last_interval(closed)
				find_index_before_last_interval(opening)
				find_index_before_last_interval(open)

				#undef find_index_before_last_interval
			};

			struct end
			{
				#define find_index_before_end_interval(name) \
				struct name \
				{ \
					name##_initial_no_return_find_index_before_end(SGN, INV) \
					name##_initial_with_return_find_index_before_end(SGN, INV) \
				};

				find_index_before_end_interval(closing)
				find_index_before_end_interval(closed)
				find_index_before_end_interval(opening)
				find_index_before_end_interval(open)

				#undef find_index_before_end_interval
			};
		};
	};
};

