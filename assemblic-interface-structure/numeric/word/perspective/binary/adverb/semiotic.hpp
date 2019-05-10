/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	map_characteristic
*/

template<size_type reg_length>
struct map_characteristic
{
	using reg_type			= typename byte_type<reg_length>::reg_type;

	using zero			= typename Constant::template zero<reg_type>;

	using one			= typename Constant::template one<reg_type>;

	//

	reg_type value;

	map_characteristic() : value(zero::value) { }

	inline void first_iteration(reg_type & sub)
	{
		sub >>= one::value;
	}

	inline void main_action(reg_type sub)
	{
		++value;
	}

	inline void main_iteration(reg_type & sub)
	{
		sub >>= one::value;
	}

	inline void last_action(reg_type)
	{
	}
};

