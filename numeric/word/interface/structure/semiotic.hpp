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
	Given the special nature of BitInterp, we can unencapsulate the binary_type and optimize.
*/

template<typename BitInterp, size_type length, bool greaterThan = (length > 8*sizeof(size_type))>
struct word
{
	typedef typename BitInterp::binary_type binary_type;

	typedef binary_type* binary_type_ptr;
	typedef binary_type& binary_type_ref;

	typedef word* word_ptr;
	typedef word& word_ref;

	typedef word_navigator<BitInterp, length, greaterThan> iterator;

	static constexpr size_type word_length = length;

	binary_type bit_array[word_length];

	word() { }

	~word() { }

	iterator begin()
	{
		return iterator(bit_array);
	}
};

