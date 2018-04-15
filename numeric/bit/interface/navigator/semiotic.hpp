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
*/

template<typename BinaryInterp, typename Filler = void>
struct bit_navigator
{
	typedef typename BinaryInterp::type binary_type;

	typedef binary_type* binary_type_ptr;
	typedef binary_type& binary_type_ref;

	typedef bit_navigator* bit_navigator_ptr;
	typedef bit_navigator& bit_navigator_ref;

	binary_type_ptr location;

	bit_navigator(binary_type & b)
	{
		location = &b;
	}

	binary_type_ref operator * () const
	{
		return *location;
	}

	binary_type_ptr operator & () const
	{
		return &location;
	}

	~bit_navigator() { }
};

