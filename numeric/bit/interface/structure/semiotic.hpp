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

	A bit is a coproduct of a Binary type. The binary type is assumed to have at least two instances,
	and basic arithmetic to navigate from one to the other. As the user of the bit type has no interest
        in coproducts, direct construction from the Binary type is necessitated.

	binary type assumes operators: copy constructor, =, ==;
	binary type assumes operands: f, t;
*/

template<typename Binary, typename Filler = void>
struct bit
{
	using type			= bit;
	using type_ptr			= type*;
	using type_ref			= type&;

	using iterator			= bit_navigator<Binary>;
	using const_iterator		= bit_navigator<Binary, Access::readonly>;

	using coproduct_type		= coproduct<typename Binary::type>;
	using coproduct_type_ptr	= coproduct_type*;
	using coproduct_type_ref	= coproduct_type&;

	using binary_type		= typename Binary::type;
	using binary_type_ptr		= binary_type*;
	using binary_type_ref		= binary_type&;

	coproduct_type value;

	bit() { }

	bit(const binary_type_ref b) : value(b) { }

	~bit() { }

	iterator name()
	{
		return value.name();
	}

	const_iterator name() const
	{
		return value.name();
	}
};

