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
	Does not test sub, ob, for matching interior closed interval lengths or right ends.

	False conditionals are expected to be optimized out at compile time.
*/

struct generic
{
		// unary:

			// compare:

	template<typename adv_type, typename sub_type>
	static sub_type compare(adv_type & adv, sub_type sub, sub_type end)
	{
		adv.first_iteration(sub);

		while (sub != end)
		{
			if (adv.break_match(sub)) return sub;

			adv.main_iteration(sub);
		}

		adv.last_match(sub);

		return sub;
	}

			// repeat:

	template<typename adv_type, typename sub_type>
	static void repeat(adv_type & adv, sub_type sub, sub_type end)
	{
		adv.first_iteration(sub);

		while (sub != end)
		{
			adv.main_action(sub);

			adv.main_iteration(sub);
		}

		adv.last_action(sub);
	}

		// binary:

			// compare:

	template<typename adv_type, typename sub_type, typename ob_type>
	static sub_type compare(adv_type & adv, sub_type sub, ob_type ob, ob_type end)
	{
		adv.first_iteration(sub, ob);

		while (ob != end)
		{
			if (adv.break_match(sub, ob)) return sub;

			adv.main_iteration(sub, ob);
		}

		adv.last_match<ob_interval>(sub, ob);

		return sub;
	}

			// (morph,) map:

	template<typename adv_type, typename sub_type, typename ob_type>
	static sub_type map(adv_type & adv, sub_type sub, ob_type ob, ob_type end)
	{
		adv.first_iteration(sub, ob);

		while (ob != end)
		{
			adv.main_action(sub, ob);

			adv.main_iteration(sub, ob);
		}

		adv.last_action(sub, ob);

		return sub;
	}

		// trinary:

			// (morph,) map:

	template<typename adv_type, typename sub_type, typename ob1_type, typename ob_type>
	static sub_type map(adv_type & adv, sub_type sub, ob1_type ob1, ob_type ob, ob_type end)
	{
		adv.first_iteration(sub, ob1, ob);

		while (ob != end)
		{
			adv.main_action(sub, ob1, ob);

			adv.main_iteration(sub, ob1, ob);
		}

		adv.last_action(sub, ob1, ob);

		return sub;
	}
};

