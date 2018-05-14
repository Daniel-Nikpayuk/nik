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
	There's no type t as every other instance of BinaryInterp::type not f is t.
*/

struct boolean
{
	typedef bool type;

	static const type f = false;
	static const type t = true;
};

/*
	BinaryInterp
*/

template<typename BinaryInterp, typename Filler = void>
struct bit
{
	typedef BinaryInterp::type binary_type;
	static const bit f(binary_type::f); 
	static const bit t(binary_type::t); 

	binary_type value;

	bit(binary_type & b)
	{
		static_assert(b == f || b == t, "does not match the specified binary types!");

		&location = b;
	}
	~bit() { }

	const bit & operator == (const bit & b) const
	{
		if (value != b.value) return f;
		else return t;
	}

	const bit & operator != (const bit & b) const
	{
		if (value == b.value) return f;
		else return t;
	}

	const bit & operator || (const bit & b) const
	{
		if (value == binary_type::f && b.value == binary_type::f) return f;
		else return t;
	}

	const bit & operator && (const bit & b) const
	{
		if (value == binary_type::t && b.value == binary_type::t) return t;
		else return f;
	}
};

template<typename Filler>
struct bit<boolean, Filler>
{
};

