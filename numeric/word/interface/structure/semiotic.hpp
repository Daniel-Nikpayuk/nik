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

	bit type assumes operators: ;
*/

template<typename BitType, size_type length, typename Filler = void>
struct word
{
	using type		= word;
	using type_ptr		= type*;
	using type_ref		= type&;

	using navigator		= word_navigator<BitType, length>;
	using const_navigator	= word_navigator<BitType, length, Access::readonly>;

	using product_type	= product<BitType, length>;
	using product_type_ptr	= product_type*;
	using product_type_ref	= product_type&;

	using bit_type		= BitType;
	using bit_type_ptr	= bit_type*;
	using bit_type_ref	= bit_type&;

	//

	using policy		= typename Iterator::template object
				<
					Interval::closing,
					Direction::forward
				>;

	using functor		= typename Iterator::template functor
				<
					policy,
					policy
				>;

	//

	product_type value;

	word() { }
	
	word(const type_ref w)
	{
		functor::assign(value.begin(), w.begin(), w.end());
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

