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
	BinaryInterp
*/

template<typename BinaryInterp, typename Filler = void>
struct bit
{
	typedef BinaryInterp::type binary_type;

	static const bit f(binary_type::f); 
	static const bit t(binary_type::t); 

	typedef bit_navigator<BinaryInterp, Filler> navigator;

	binary_type location;

	bit(binary_type & b)
	{
		static_assert(b == f || b == t, "does not match the specified binary types!");

		&location = b;
	}

	~bit() { }

	const bit & operator = (const binary_type & b)
	{
		static_assert(b == f || b == t, "does not match the specified binary types!");
		location = b;

		return *this;
	}

	navigator name()
	{
		return navigator(location);
	}
};

