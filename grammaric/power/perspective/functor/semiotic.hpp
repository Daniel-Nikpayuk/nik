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

> struct functor;

/*
	unary:
*/

template
<
	typename sub_policy

> struct functor
<
	sub_policy
>
{
		// set:

	template<typename sub_type, typename ob_type>
	static void set(sub_type sub, sub_type end, ob_type ob)
	{
		repeat_set<sub_policy, ob_type> rs(ob);

		generic::repeat(rs, sub, end);
	}
};

/*
	binary:
*/

template
<
	typename sub_policy,
	typename ob_policy

> struct functor
<
	sub_policy,
	ob_policy
>
{
		// assign:

	template<typename sub_type, typename ob_type>
	static sub_type assign(sub_type sub, ob_type ob, ob_type end)
	{
		map_assign<sub_policy, ob_policy> ma;

		return generic::map(ma, sub, ob, end);
	}
};

