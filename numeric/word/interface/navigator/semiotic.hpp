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
	Navigators may be optimized in their methods as they have limited perspectives.
*/

template<typename BinaryType, Access access = Access::readwrite>
struct coword
{
	using type			= coword;
	using type_ptr			= type*;
	using type_ref			= type&;

	using const_type		= coword<BinaryType, Access::readonly>;

	using binary_type		= typename BinaryType::builtin_type;
	using binary_type_ptr		= binary_type*;
	using binary_type_ref		= binary_type&;

	using bit_type			= cobit<binary_type, access>;
	using bit_type_ptr		= bit_type*;
	using bit_type_ref		= bit_type&;

	using bit_iterator		= bit_type;
	using bit_iterator_ptr		= bit_iterator*;
	using bit_iterator_ref		= bit_iterator&;

	using word_iterator		= copower<bit_type_ptr, access>;
	using word_iterator_ptr		= word_iterator*;
	using word_iterator_ref		= word_iterator&;

	enum struct State
	{
		word,
		bit,

		dimension
	};

	word_iterator word_location;
	State state;

		// type:

	coword(const word_iterator_ref l) : location(l) { }

	~coword() { }

	struct bit
	{
		bool operator == (const type_ref c) const
		{
			if (state == State::word)	return word_location == c.word_location;
			else				return bit_location == c.bit_location;
		}
	};

	bool operator == (const type_ref c) const
	{
		if (state == State::word)	return word_location == c.word_location;
		else				return bit_location == c.bit_location;
	}

	bool operator != (const type_ref c) const
	{
		if (state == State::word)	return word_location != c.word_location;
		else				return bit_location != c.bit_location;
	}

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	const binary_type_ref operator * () const
	{
		return *bit_location;
	}

		// navigator:

	void operator + ()
	{
		+bit_location;
	}

	void operator - ()
	{
		-bit_location;
	}

	type_ref operator ++ ()
	{
		++word_location;

		return *this;
	}

	type operator ++ (int)
	{
		return word_location++;
	}

	type_ref operator += (size_type n)
	{
		word_location += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return word_location + n;
	}

	type_ref operator -- ()
	{
		--word_location;

		return *this;
	}

	type operator -- (int)
	{
		return word_location--;
	}

	type_ref operator -= (size_type n)
	{
		word_location -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return word_location - n;
	}
};

/*
template<size_type N, typename Type, Access access = Access::readwrite>
struct mobile_copower
{
	using type		= mobile_copower;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= mobile_copower<N, Type, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	using nested_type	= nested_copower<N, Type, access>;
	using nested_type_ptr	= nested_type*;
	using nested_type_ref	= nested_type&;

	nested_type_ptr path[N+1];
	nested_type_ptr *location;

		// type:

	mobile_copower() : location(path) { }

	~mobile_copower()
	{
		// deallocate location componentwise.
	}

	bool operator == (const type_ref c) const
	{
		return *location == *c.location;
	}

	bool operator != (const type_ref c) const
	{
		return *location != *c.location;
	}

		// Exists to convert readwrite to readonly.
		// Is redundant when already readonly.

	operator const_type () const
	{
		return (const_type) this;
	}

		// value:

	value_type_ref operator * () const
	{
		return *path[N-1];
	}

		// meta:

	void operator + ()
	{
		++location;
	}
	
	void operator - ()
	{
		--location;
	}

		// navigator:

	type_ref operator ++ ()
	{
		(*location)->operator++();

		return *this;
	}

	type operator ++ (int int_value)
	{
		return (*location)->operator++(int_value);
	}

	type_ref operator += (size_type n)
	{
		(*location)->operator+=(n);

		return *this;
	}

	type operator + (size_type n) const
	{
		return (*location)->operator+(n);
	}

	type_ref operator -- ()
	{
		(*location)->operator--();

		return *this;
	}

	type operator -- (int int_value)
	{
		return (*location)->operator--(int_value);
	}

	type_ref operator -= (size_type n)
	{
		(*location)->operator-=(n);

		return *this;
	}

	type operator - (size_type n) const
	{
		return (*location)->operator-(n);
	}

	size_type operator - (const type_ref c) const
	{
		return *location - *c.location;
	}
};
*/

