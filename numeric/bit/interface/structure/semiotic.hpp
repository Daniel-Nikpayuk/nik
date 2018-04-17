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
	bit type	:= 0 + 1;
	bit instance	:= s^1, s^2;

	binary type assumes operators: copy constructor, =, ==;
	binary type assumes operands: f, t;
*/

template<typename Binary, typename Filler = void>
struct bit
{
	using type		= bit;
	using type_ptr		= type*;
	using type_ref		= type&;

	using binary_type	= typename Binary::type;
	using binary_type_ptr	= binary_type*;
	using binary_type_ref	= binary_type&;

	using iterator		= bit_navigator<Binary>;
	using const_iterator	= bit_navigator<Binary, Access::readonly>;

	binary_type location;

	bit() { }

	bit(const binary_type_ref l) : location(l)
	{
		static_assert
		(
			l == Binary::f || l == Binary::t,
			"does not match the specified binary types!"
		);
	}

	~bit() { }

	const type_ref operator = (const binary_type_ref l)
	{
		static_assert
		(
			l == Binary::f || l == Binary::t,
			"does not match the specified binary types!"
		);

		location = l;

		return *this;
	}

	iterator name()
	{
		return location;
	}

	const_iterator name() const
	{
		return location;
	}
};

