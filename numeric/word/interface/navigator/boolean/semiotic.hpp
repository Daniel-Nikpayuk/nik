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
	Given the special nature of bit_type, we can unencapsulate the binary_type and optimize.
*/

#define GREATER_THAN false

/*
	size_type location, value, can be optimized given the length to different int types.

template<typename T, unsigned char size>
struct size_assert
{
	static_assert(sizeof(T) == size, "uint size_assert mismatch!");

	typedef T return_type;
};

typedef typename size_assert<unsigned char	, 1>::return_type identity8; 
typedef typename size_assert<unsigned short	, 2>::return_type identity16;
typedef typename size_assert<unsigned int	, 4>::return_type identity32;
typedef typename size_assert<unsigned long	, 8>::return_type identity64;
*/

template<size_type length>
struct word_navigator<bit<boolean>, length, GREATER_THAN>
{
	typedef typename boolean::type binary_type;

	typedef binary_type* binary_type_ptr;
	typedef binary_type& binary_type_ref;

	typedef word_navigator* word_navigator_ptr;
	typedef word_navigator& word_navigator_ref;

	size_type location;
	size_type *value;

	word_navigator(size_type l, size_type & b) : location(l)
	{
		value = &b;
	}

	binary_type operator * () const
	{
		return *value & location;
	}

	void operator + ()
	{
		*value ^= location;
	}

	void operator - ()
	{
		*value &= ~location;
	}

	~word_navigator() { }

	word_navigator_ref operator ++ ()
	{
		location<<=1;

		return *this;
	}

	word_navigator operator ++ (int)
	{
		return word_navigator(location<<1, value);
	}

	word_navigator_ref operator += (size_type n)
	{
		location<<=n;

		return *this;
	}

	word_navigator operator + (size_type n) const
	{
		return word_navigator(location<<n, value);
	}

	word_navigator_ref operator -- ()
	{
		location>>=1;

		return *this;
	}

	word_navigator operator -- (int)
	{
		return word_navigator(location>>1, value);
	}

	word_navigator_ref operator -= (size_type n)
	{
		location>>=n;

		return *this;
	}

	word_navigator operator - (size_type n) const
	{
		return word_navigator(location>>n, value);
	}
};

#undef GREATER_THAN
#define GREATER_THAN true

template<size_type length>
struct word_navigator<bit<boolean>, length, GREATER_THAN>
{
};

#undef GREATER_THAN

