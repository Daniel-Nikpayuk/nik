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

		// zero:

	template<typename sub_type>
	static bool zero(sub_type sub, sub_type end)
	{
		identity_zero<sub_policy> iz;

		method::compare(iz, sub, end);

		return iz.rtn;
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

		// equals:

	template<typename sub_type, typename ob_type>
	static bool equals(sub_type sub, ob_type ob, ob_type end)
	{
		identity_equal<sub_policy, ob_policy> ie;

		method::compare(ie, sub, ob, end);

		return ie.rtn;
	}

		// not equals:

	template<typename sub_type, typename ob_type>
	static bool not_equals(sub_type sub, ob_type ob, ob_type end)
	{
		identity_not_equal<sub_policy, ob_policy> ine;

		method::compare(ine, sub, ob, end);

		return ine.rtn;
	}
};

