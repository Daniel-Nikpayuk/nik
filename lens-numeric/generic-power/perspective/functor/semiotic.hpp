/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename...> struct functor;

/*
	unary:
*/

template<typename sub_adjective>
struct functor<sub_adjective>
{
		// set:

	template<typename sub_type, typename value_type>
	static void set(sub_type sub, sub_type end, value_type value)
	{
		map_set<sub_adjective, value_type> ms(value);

		generic::map(ms, sub, end);
	}
};

/*
	binary:
*/

template<typename sub_adjective, typename ob_adjective>
struct functor<sub_adjective, ob_adjective>
{
		// assign:

	template<typename sub_type, typename ob_type>
	static sub_type assign(sub_type sub, ob_type ob, ob_type end)
	{
		map_assign<sub_adjective, ob_adjective> ma;

		return generic::map(ma, sub, ob, end);
	}
};

