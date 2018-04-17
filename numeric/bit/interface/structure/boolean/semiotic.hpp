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

struct boolean
{
	using type = bool;

	static constexpr type f = false;
	static constexpr type t = true;
};

//

template<typename Filler>
struct bit<boolean, Filler>
{
	using type		= bit;
	using type_ptr		= type*;
	using type_ref		= type&;

	using binary_type	= typename boolean::type;
	using binary_type_ptr	= binary_type*;
	using binary_type_ref	= binary_type&;

	using iterator		= bit_navigator<boolean>;
	using const_iterator	= bit_navigator<boolean, Access::readonly>;

	binary_type location;

	bit() { }

	bit(binary_type l) : location(l) { }

	~bit() { }

	const type_ref operator = (binary_type l)
	{
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

