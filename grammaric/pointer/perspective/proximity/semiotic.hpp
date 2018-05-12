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

template<typename policy>
struct proximity
{
	static constexpr Interval sub_interval		= policy::subject_interval;
	static constexpr Direction sub_direction	= policy::subject_direction;

	static constexpr Interval ob_interval		= policy::object_interval;
	static constexpr Direction ob_direction		= policy::object_direction;

	struct lt_verb
	{
		bool rtn;

		lt_verb() : rtn(false) { }

		template<typename type_ptr>
		bool break_match(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub < *ob);

			return (*sub != *ob);
		}

		template<typename type_ptr>
		void last_match(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub < *ob);
		}
	};

	struct lte_verb
	{
		bool rtn;

		lte_verb() : rtn(false) { }

		template<typename type_ptr>
		bool break_match(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub < *ob);

			return (*sub != *ob);
		}

		template<typename type_ptr>
		void last_match(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub <= *ob);
		}
	};

	struct gt_verb
	{
		bool rtn;

		gt_verb() : rtn(false) { }

		template<typename type_ptr>
		bool break_match(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub > *ob);

			return (*sub != *ob);
		}

		template<typename type_ptr>
		void last_match(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub > *ob);
		}
	};

	struct gte_verb
	{
		bool rtn;

		gte_verb() : rtn(false) { }

		template<typename type_ptr>
		bool break_match(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub > *ob);

			return (*sub != *ob);
		}

		template<typename type_ptr>
		void last_match(type_ptr sub, type_ptr ob)
		{
			rtn = (*sub >= *ob);
		}
	};

		//

	template<typename type_ptr>
	static bool less_than(type_ptr sub, type_ptr ob, type_ptr end)
	{
		lt_verb lt;

		generic<policy>::compare(lt, sub, ob, end);

		return lt.rtn;
	}

	template<typename type_ptr>
	static bool less_than_or_equal(type_ptr sub, type_ptr ob, type_ptr end)
	{
		lte_verb lte;

		generic<policy>::compare(lte, sub, ob, end);

		return lte.rtn;
	}

	template<typename type_ptr>
	static bool greater_than(type_ptr sub, type_ptr ob, type_ptr end)
	{
		gt_verb gt;

		generic<policy>::compare(gt, sub, ob, end);

		return gt.rtn;
	}

	template<typename type_ptr>
	static bool greater_than_or_equal(type_ptr sub, type_ptr ob, type_ptr end)
	{
		gte_verb gte;

		generic<policy>::compare(gte, sub, ob, end);

		return gte.rtn;
	}
};

