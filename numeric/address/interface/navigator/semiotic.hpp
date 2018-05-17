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
	address type		:= (0 + 1)^np;
	address instance	:= m^i/m^j/s^k, m^i/m^j/s^l in (0 + 1)^np -> k = l;

	binary type assumes operators: ;

	Navigators may be optimized in their methods as they have limited perspectives.
*/

/*
	1. The only reason to unroll composite navigators is to optimize.
	2. The only reason to optimize composite navigators by unrolling
	   is if the context requires frequently moving between levels of complexity.
*/

template<typename Word, size_type length, Access access = Access::readwrite>
struct address_navigator
{
	using type			= address_navigator;
	using type_ref			= type&;
	using type_ptr			= type*;

	using const_type		= address_navigator<Word, length, Access::readonly>;

	using sub_navigator		= coproduct<Word, access>;
	using sub_navigator_ref		= sub_navigator&;
	using sub_navigator_ptr		= sub_navigator*;

	using word_type			= typename read_type<Word, access>::rtn;
	using word_type_ref		= word_type&;
	using word_type_ptr		= word_type*;

	sub_navigator location;

		// type:

	address_navigator(const sub_navigator_ref l) : location(l) { }

	~address_navigator() { }

	bool operator == (const type_ref w) const
	{
		return location == w.location;
	}

	bool operator != (const type_ref w) const
	{
		return location != w.location;
	}

	operator const_type () const
	{
		return (const_type) this;
	}

		// navigator:

	type_ref operator ++ ()
	{
		++location;

		return *this;
	}

	type operator ++ (int)
	{
		return location++;
	}

	type_ref operator += (size_type n)
	{
		location += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return location + n;
	}

	type_ref operator -- ()
	{
		--location;

		return *this;
	}

	type operator -- (int)
	{
		return location--;
	}

	type_ref operator -= (size_type n)
	{
		location -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return location - n;
	}

		// value:

	word_type_ref operator * () const
	{
		return *location;
	}
};

