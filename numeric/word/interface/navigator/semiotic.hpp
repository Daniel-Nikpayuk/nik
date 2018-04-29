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
	word instance	:= m^j/s^k = m^j/s^l -> k = l;

	binary type assumes operators: ;

	Navigators may be optimized in their methods as they have limited perspectives.
*/

template<typename Bit, size_type length, Access access = Access::readwrite>
struct word_navigator
{
	using type			= word_navigator;
	using type_ptr			= type*;
	using type_ref			= type&;

	using const_type		= word_navigator<Bit, length, Access::readonly>;

	using sub_navigator		= typename product_s::template product_navigator<typename Bit::coproduct_type, access>;
	using sub_navigator_ptr		= sub_navigator*;
	using sub_navigator_ref		= sub_navigator&;

	using bit_type			= typename read_type<Bit, access>::rtn;
	using bit_type_ptr		= bit_type*;
	using bit_type_ref		= bit_type&;

	sub_navigator location;

		// type:

	word_navigator(sub_navigator l) : location(*l) { }

	~word_navigator() { }

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

	bit_type_ref operator * () const
	{
		return *location;
	}
};

