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
	using method					= generic<sub_policy, ob_policy>;

	static constexpr Interval sub_interval		= sub_policy::interval;
	static constexpr Direction sub_direction	= sub_policy::direction;

	static constexpr Interval ob_interval		= ob_policy::interval;
	static constexpr Direction ob_direction		= ob_policy::direction;

	struct lt_verb
	{
		bool rtn;

		lt_verb() : rtn(false) { }

		template<typename sub_type, typename ob_type>
		bool break_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub < *ob);

			return (*sub != *ob);
		}

		template<typename sub_type, typename ob_type>
		void last_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub < *ob);
		}
	};

	struct lte_verb
	{
		bool rtn;

		lte_verb() : rtn(false) { }

		template<typename sub_type, typename ob_type>
		bool break_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub < *ob);

			return (*sub != *ob);
		}

		template<typename sub_type, typename ob_type>
		void last_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub <= *ob);
		}
	};

	struct gt_verb
	{
		bool rtn;

		gt_verb() : rtn(false) { }

		template<typename sub_type, typename ob_type>
		bool break_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub > *ob);

			return (*sub != *ob);
		}

		template<typename sub_type, typename ob_type>
		void last_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub > *ob);
		}
	};

	struct gte_verb
	{
		bool rtn;

		gte_verb() : rtn(false) { }

		template<typename sub_type, typename ob_type>
		bool break_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub > *ob);

			return (*sub != *ob);
		}

		template<typename sub_type, typename ob_type>
		void last_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub >= *ob);
		}
	};

		// less than:

	template<typename sub_type, typename ob_type>
	static bool less_than(sub_type sub, ob_type ob, ob_type end)
	{
		lt_verb lt;

		method::compare(lt, sub, ob, end);

		return lt.rtn;
	}

		// less than or equal:

	template<typename sub_type, typename ob_type>
	static bool less_than_or_equal(sub_type sub, ob_type ob, ob_type end)
	{
		lte_verb lte;

		method::compare(lte, sub, ob, end);

		return lte.rtn;
	}

		// greater than:

	template<typename sub_type, typename ob_type>
	static bool greater_than(sub_type sub, ob_type ob, ob_type end)
	{
		gt_verb gt;

		method::compare(gt, sub, ob, end);

		return gt.rtn;
	}

		// greater than or equal:

	template<typename sub_type, typename ob_type>
	static bool greater_than_or_equal(sub_type sub, ob_type ob, ob_type end)
	{
		gte_verb gte;

		method::compare(gte, sub, ob, end);

		return gte.rtn;
	}
};

