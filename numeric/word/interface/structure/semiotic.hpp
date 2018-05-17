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
	word type	:= (0 + 1)^n;
	word instance	:= m^j/s^k, m^j/s^l in (0 + 1)^n -> k = l;

	A word is a power of BitType.

	Although the template parameter allows for arbitrary types, word is meant specifically for register sizes:

	8 << 0, unsigned char
	8 << 1, unsigned short
	8 << 2, unsigned int
	8 << 3, unsigned long

	The bit type is assumed to have at least two instances, and basic arithmetic to navigate from one to the other.
	bit type assumes operators: ;
*/

template<typename BitType, size_type length, typename Filler = void>
struct word
{
	using type		= word;
	using type_ref		= type&;
	using type_ptr		= type*;

	using navigator		= word_navigator<BitType, length>;
	using const_navigator	= word_navigator<BitType, length, Access::readonly>;

	using power_type	= power<BitType, length>;
	using power_type_ref	= power_type&;
	using power_type_ptr	= power_type*;

	using bit_type		= BitType;
	using bit_type_ref	= bit_type&;
	using bit_type_ptr	= bit_type*;

	//

	using policy		= object
				<
					Interval::closing,
					Direction::forward
				>;

	using method		= functor
				<
					policy,
					policy
				>;

	//

	power_type value;

	word() { }
	
	word(const type_ref w)
	{
		method::assign(value.begin(), w.begin(), w.end());
	}

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

