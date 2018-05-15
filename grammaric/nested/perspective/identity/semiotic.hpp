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

template<size_type N, typename sub_policy, typename ob_policy>
struct identity
{
	using method		= generic<N, sub_policy, ob_policy>;
	using sub_method	= generic<N-1, sub_policy, ob_policy>;

		// eq_verb:

	template<size_type N, typename Filler = void>
	struct eq_verb
	{
		bool rtn;

		eq_verb() : rtn(false) { }

		template<typename sub_type, typename ob_type>
		inline bool match(sub_type sub, ob_type ob, ob_type end)
		{
			eq_verb<N-1> eq;

			sub_method::compare(eq, sub, ob, end);

			return eq.rtn;
		}
	};

	template<typename Filler>
	struct eq_verb<Zero::value, Filler>
	{
		bool rtn;

		eq_verb() : rtn(false) { }

		template<typename sub_type, typename ob_type>
		inline bool break_match(sub_type sub, ob_type ob, ob_type end)
		{
			rtn = (*sub == *ob);

			return !rtn;
		}

		template<typename sub_type, typename ob_type>
		inline void last_match(sub_type sub, ob_type ob, ob_type end)
		{
			rtn = (*sub == *ob);
		}
	};

		// neq_verb:

	template<size_type N, typename Filler = void>
	struct neq_verb
	{
		bool rtn;

		neq_verb() : rtn(true) { }

		template<typename sub_type, typename ob_type>
		inline bool match(sub_type sub, ob_type ob, ob_type end)
		{
			neq_verb<N-1> neq;

			sub_method::compare(neq, sub, ob, end);

			return neq.rtn;
		}
	};

	template<typename Filler>
	struct neq_verb<Zero::value, Filler>
	{
		bool rtn;

		neq_verb() : rtn(true) { }

		template<typename sub_type, typename ob_type>
		inline bool break_match(sub_type sub, ob_type ob, ob_type end)
		{
			rtn = (*sub != *ob);

			return rtn;
		}

		template<typename sub_type, typename ob_type>
		inline void last_match(sub_type sub, ob_type ob, ob_type end)
		{
			rtn = (*sub != *ob);
		}
	};

		// equals:

	template<typename sub_type, typename ob_type>
	static bool equals(sub_type sub, ob_type ob, ob_type end)
	{
		eq_verb<N> eq;

		method::compare(eq, sub, ob, end);

		return eq.rtn;
	}

		// not equals:

	template<typename sub_type, typename ob_type>
	static bool not_equals(sub_type sub, ob_type ob, ob_type end)
	{
		neq_verb<N> neq;

		method::compare(neq, sub, ob, end);

		return neq.rtn;
	}
};

