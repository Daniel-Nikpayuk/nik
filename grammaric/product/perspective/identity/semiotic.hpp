/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
************************************************************************************************************************/

/*
	Although the template parameter allows for arbitrary types, product is meant specifically for register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	8 << 3, void*

	In the context of this library, products are the disjoint union of concurrent instances of the same type.
	This generic code is only intended for a fixed number of similar types, but the length parameter generates
        further possibilities. As such, the basic methods for the objects of this class are called as external
        static functions allowing for identity, proximity, and shape methods between various lengths.
*/

struct identity
{
		// closed, forward, closed, forward:

	template
	<
		Interval in_interval, Direction in_direction,
		Interval out_interval, Direction out_direction,
		typename in_iterator, typename out_iterator
	>
	static bool equals(in_iterator in_b, out_iterator out_b, out_iterator out_e)
	{
		while (out_b != out_e)
		{
			if (*in_b != *out_b) return false;
			++in_b, ++out_b;
		}

		return true;
	}

		// closed, forward, closed, forward:


	template<typename in_iterator, typename out_iterator>
	static bool not_equals(in_iterator in_b, out_iterator out_b, out_iterator out_e)
	{
		while (out_b != out_e)
		{
			if (*in_b != *out_b) return true;
			++in_b, ++out_b;
		}

		return false;
	}
};

