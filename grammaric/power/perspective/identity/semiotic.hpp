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

template
<
	typename...

> struct identity;

/*
	unary:
*/

template
<
	typename sub_policy

> struct identity
<
	sub_policy
>
{
	using method = generic<sub_policy>;

		// zr_verb:

	struct zr_verb
	{
		bool rtn;

		zr_verb() : rtn(false) { }

		template<typename sub_type>
		inline bool break_match(sub_type sub)
		{
			rtn = (*sub == 0); // use a constant<>::zero in the long run.

			return !rtn;
		}

		template<typename sub_type>
		inline void last_match(sub_type sub)
		{
			rtn = (*sub == 0); // use a constant<>::zero in the long run.
		}
	};

		// zero:

	template<typename sub_type>
	static bool zero(sub_type sub, sub_type end)
	{
		zr_verb zr;

		method::compare(zr, sub, end);

		return zr.rtn;
	}
};

/*
	binary:
*/

template
<
	typename sub_policy,
	typename ob_policy

> struct identity
<
	sub_policy,
	ob_policy
>
{
	using method = generic<sub_policy, ob_policy>;

		// eq_verb:

	struct eq_verb
	{
		bool rtn;

		eq_verb() : rtn(false) { }

		template<typename sub_type, typename ob_type>
		inline bool break_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub == *ob);

			return !rtn;
		}

		template<typename sub_type, typename ob_type>
		inline void last_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub == *ob);
		}
	};

		// neq_verb:

	struct neq_verb
	{
		bool rtn;

		neq_verb() : rtn(true) { }

		template<typename sub_type, typename ob_type>
		inline bool break_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub != *ob);

			return rtn;
		}

		template<typename sub_type, typename ob_type>
		inline void last_match(sub_type sub, ob_type ob)
		{
			rtn = (*sub != *ob);
		}
	};

		// equals:

	template<typename sub_type, typename ob_type>
	static bool equals(sub_type sub, ob_type ob, ob_type end)
	{
		eq_verb eq;

		method::compare(eq, sub, ob, end);

		return eq.rtn;
	}

		// not equals:

	template<typename sub_type, typename ob_type>
	static bool not_equals(sub_type sub, ob_type ob, ob_type end)
	{
		neq_verb neq;

		method::compare(neq, sub, ob, end);

		return neq.rtn;
	}
};

