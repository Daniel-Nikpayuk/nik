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

template<typename Type, Access access = Access::readwrite>
struct copair
{
	using type		= copair;
	using type_ptr		= type*;
	using type_ref		= type&;

	using const_type	= copair<Type, Access::readonly>;

	using value_type	= typename read_type<Type, access>::rtn;
	using value_type_ptr	= value_type*;
	using value_type_ref	= value_type&;

	value_type initial;
	value_type terminal;

		// type:

	copair(const value_type_ref & i, const value_type_ref & t) : initial(i), terminal(t) { }

	~copair() { }

	bool operator == (const type_ref s) const
	{
		return initial == s.initial && terminal == s.terminal;
	}

	bool operator != (const type_ref s) const
	{
		return initial != s.initial || terminal != s.terminal;
	}

	operator const_type () const
	{
		return (const_type) this;
	}

		// navigator:

	value_type_ref operator - () const
	{
		return initial;
	}

	value_type_ref operator + () const
	{
		return terminal;
	}

	type_ref operator ++ ()
	{
		++initial;
		++terminal;

		return *this;
	}

	type operator ++ (int)
	{
		return copair(initial++, terminal++);
	}

	type_ref operator += (size_type n)
	{
		initial += n;
		terminal += n;

		return *this;
	}

	type operator + (size_type n) const
	{
		return copair(initial + n, terminal + n);
	}

	type_ref operator -- ()
	{
		--initial;
		--terminal;

		return *this;
	}

	type operator -- (int)
	{
		return copair(initial--, terminal--);
	}

	type_ref operator -= (size_type n)
	{
		initial -= n;
		terminal -= n;

		return *this;
	}

	type operator - (size_type n) const
	{
		return copair(initial - n, terminal - n);
	}
};

