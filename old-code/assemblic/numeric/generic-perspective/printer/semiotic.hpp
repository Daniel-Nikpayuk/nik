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

template<typename sub_adjective>
struct printer
{
		// print:

	template<typename sub_type>
	static void print(sub_type sub, sub_type end)
	{
		map_print<sub_adjective> mp;

		generic::map(mp, sub, end);
	}

	template<typename sub_type, typename separator_type>
	static void print(sub_type sub, sub_type end, const separator_type & s)
	{
		map_print<sub_adjective, separator_type> mp(s);

		generic::map(mp, sub, end);
	}
};

