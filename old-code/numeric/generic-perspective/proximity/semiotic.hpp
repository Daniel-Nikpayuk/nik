/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename sub_adjective, typename ob_adjective>
struct proximity
{
		// less than:

	template<typename sub_type, typename ob_type>
	static bool less_than(sub_type sub, ob_type ob, ob_type end)
	{
		compare_less_than<sub_adjective, ob_adjective> clt;

		generic::compare(clt, sub, ob, end);

		return clt.value;
	}

		// less than or equal:

	template<typename sub_type, typename ob_type>
	static bool less_than_or_equal(sub_type sub, ob_type ob, ob_type end)
	{
		compare_less_than_or_equal<sub_adjective, ob_adjective> cltoe;

		generic::compare(cltoe, sub, ob, end);

		return cltoe.value;
	}

		// greater than:

	template<typename sub_type, typename ob_type>
	static bool greater_than(sub_type sub, ob_type ob, ob_type end)
	{
		compare_greater_than<sub_adjective, ob_adjective> cgt;

		generic::compare(cgt, sub, ob, end);

		return cgt.value;
	}

		// greater than or equal:

	template<typename sub_type, typename ob_type>
	static bool greater_than_or_equal(sub_type sub, ob_type ob, ob_type end)
	{
		compare_greater_than_or_equal<sub_adjective, ob_adjective> cgtoe;

		generic::compare(cgtoe, sub, ob, end);

		return cgtoe.value;
	}
};

