/************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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


template
<
	typename sub_pointer,
	typename sub_adjective,

	size_type sub_directionEnum = sub_adjective::direction_enum,
	size_type sub_imageEnum = sub_adjective::image_enum,
	size_type sub_iteratorEnum = sub_adjective::iterator_enum
>
struct initialize_variables
{
	sub_pointer current;

	initialize_variables(sub_pointer & out, const sub_adjective & sub) { }
};


/***********************************************************************************************************************/


template<typename sub_pointer, typename sub_adjective>
struct initialize_variables<sub_pointer, sub_adjective, Association::forward, Association::allocate, Association::segment>
{
	using value_type = typename structural<nik::semiotic>::template trim<sub_pointer>::pointer;

	sub_pointer origin;

	initialize_variables(sub_pointer & out, const sub_adjective & sub)
	{
		origin = new value_type[sub.length];
		out = origin + sub.offset;
	}
};


template<typename sub_pointer, typename sub_adjective>
struct initialize_variables<sub_pointer, sub_adjective, Association::backward, Association::allocate, Association::segment>
{
	using value_type = typename structural<nik::semiotic>::template trim<sub_pointer>::pointer;

	sub_pointer origin;

	initialize_variables(sub_pointer & out, const sub_adjective & sub)
	{
		origin = new value_type[sub.length];
		out = origin + (sub.length - 1 - sub.offset);
	}
};


