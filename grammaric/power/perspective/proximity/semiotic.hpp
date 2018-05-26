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

template<typename sub_policy, typename ob_policy>
struct proximity
{
	using method = generic<sub_policy, ob_policy>;

		// less than:

	template<typename sub_type, typename ob_type>
	static bool less_than(sub_type sub, ob_type ob, ob_type end)
	{
		proximity_less_than<sub_policy, ob_policy> plt;

		method::compare(plt, sub, ob, end);

		return plt.rtn;
	}

		// less than or equal:

	template<typename sub_type, typename ob_type>
	static bool less_than_or_equal(sub_type sub, ob_type ob, ob_type end)
	{
		proximity_less_than_or_equal<sub_policy, ob_policy> pltoe;

		method::compare(pltoe, sub, ob, end);

		return pltoe.rtn;
	}

		// greater than:

	template<typename sub_type, typename ob_type>
	static bool greater_than(sub_type sub, ob_type ob, ob_type end)
	{
		proximity_greater_than<sub_policy, ob_policy> pgt;

		method::compare(pgt, sub, ob, end);

		return pgt.rtn;
	}

		// greater than or equal:

	template<typename sub_type, typename ob_type>
	static bool greater_than_or_equal(sub_type sub, ob_type ob, ob_type end)
	{
		proximity_greater_than_or_equal<sub_policy, ob_policy> pgtoe;

		method::compare(pgtoe, sub, ob, end);

		return pgtoe.rtn;
	}
};

