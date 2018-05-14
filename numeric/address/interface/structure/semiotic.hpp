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

template<typename Bit, size_type length, typename Filler = void>
struct word
{
	using type		= word;
	using type_ptr		= type*;
	using type_ref		= type&;

	using iterator		= word_navigator<Bit, length>;
	using const_iterator	= word_navigator<Bit, length, Access::readonly>;

	using product_type	= product<Bit, length>;
	using product_type_ptr	= product_type*;
	using product_type_ref	= product_type&;

	using bit_type		= Bit;
	using bit_type_ptr	= bit_type*;
	using bit_type_ref	= bit_type&;

	product_type value;

	word() { }

	~word() { }

	iterator begin()
	{
		return value.begin();
	}

	const_iterator begin() const
	{
		return value.begin();
	}

	iterator end()
	{
		return value.end();
	}

	const_iterator end() const
	{
		return value.end();
	}
};

