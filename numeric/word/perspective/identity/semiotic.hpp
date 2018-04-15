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
struct identity
{
	typedef WordInterp word_type;
	typedef typename word_type::binary_type binary_type;

	typedef binary_type* binary_type_ptr;
	typedef binary_type& binary_type_ref;

	typedef identity* identity_ptr;
	typedef identity& identity_ref;

	//

	static bool equals(const word_type & u, const word_type & v)
		// if they're of the same word_type it is assumed they have the same word_length.
	{
		const binary_type *k = u.bit_array;
		const binary_type *e = k + word_type::word_length;

		for (const binary_type *l = v.bit_array; k != e; ++k, ++l) if (*k != *l) return false;

		return true;
	}

	static bool not_equals(const word_type & u, const word_type & v)
		// if they're of the same word_type it is assumed they have the same word_length.
	{
		const binary_type *k = u.bit_array;
		const binary_type *e = k + word_type::word_length;

		for (const binary_type *l = v.bit_array; k != e; ++k, ++l) if (*k != *l) return true;

		return false;
	}
};

