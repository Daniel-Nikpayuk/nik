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
	Given the special nature of WordInterp, we can unencapsulate the binary_type and optimize.
*/

template<typename WordInterp>
struct proximity
{
	typedef WordInterp word_type;
	typedef typename word_type::binary_type binary_type;

	typedef binary_type* binary_type_ptr;
	typedef binary_type& binary_type_ref;

	typedef proximity* proximity_ptr;
	typedef proximity& proximity_ref;

	// if they're of the same word_type it is assumed they have the same word_length.

	static bool less_than(const word_type & u, const word_type & v)
	{
		size_type last_position = word_type::word_length - 1;

		const binary_type *b = u.bit_array;
		const binary_type *k = b + last_position;

		for (const binary_type *l = v.bit_array + last_position; k != b; --k, --l) if (*k > *l) return false;

		return (*k < *v.bit_array);
	}

	static bool less_than_or_equal(const word_type & u, const word_type & v)
	{
		size_type last_position = word_type::word_length - 1;

		const binary_type *b = u.bit_array;
		const binary_type *k = b + last_position;

		for (const binary_type *l = v.bit_array + last_position; k != b; --k, --l) if (*k > *l) return false;

		return (*k <= *v.bit_array);
	}

	static bool greater_than(const word_type & u, const word_type & v)
	{
		size_type last_position = word_type::word_length - 1;

		const binary_type *b = u.bit_array;
		const binary_type *k = b + last_position;

		for (const binary_type *l = v.bit_array + last_position; k != b; --k, --l) if (*k < *l) return false;

		return (*k > *v.bit_array);
	}

	static bool greater_than_or_equal(const word_type & u, const word_type & v)
	{
		size_type last_position = word_type::word_length - 1;

		const binary_type *b = u.bit_array;
		const binary_type *k = b + last_position;

		for (const binary_type *l = v.bit_array + last_position; k != b; --k, --l) if (*k < *l) return false;

		return (*k >= *v.bit_array);
	}
};

