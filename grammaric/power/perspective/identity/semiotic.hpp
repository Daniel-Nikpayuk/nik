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
		// zero:

	template<typename sub_type>
	static bool zero(sub_type sub, sub_type end)
	{
		compare_zero<sub_policy> cz;

		generic::compare(cz, sub, end);

		return cz.value;
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
		// equals:

	template<typename sub_type, typename ob_type>
	static bool equals(sub_type sub, ob_type ob, ob_type end)
	{
		compare_equal<sub_policy, ob_policy> ce;

		generic::compare(ce, sub, ob, end);

		return ce.value;
	}

		// not equals:

	template<typename sub_type, typename ob_type>
	static bool not_equals(sub_type sub, ob_type ob, ob_type end)
	{
		compare_not_equal<sub_policy, ob_policy> cne;

		generic::compare(cne, sub, ob, end);

		return cne.value;
	}
};

