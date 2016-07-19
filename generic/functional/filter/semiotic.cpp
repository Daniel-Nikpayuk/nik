/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

template<typename test, typename filtered, typename unfiltered>
struct filter { };

//

template<typename test, typename filtered, size_type current, size_type... params>
struct filter<test, filtered, slist<current, params...> >
{
	using new_filtered = typename gfm_policy::template if_then_else
		<
			test::template keep<current>::rtn,
			typename append<current, filtered>::rtn,
			filtered
		>::return_type;

	using rtn = typename filter<test, new_filtered, slist<params...> >::rtn;
};

template<typename test, typename filtered>
struct filter<test, filtered, null_slist>
{
	using rtn = filtered;
};

//

template<typename test, typename filtered, size_type current, size_type... params>
struct filter<test, filtered, mlist<current, params...> >
{
	using new_filtered = typename gfm_policy::template if_then_else
		<
			test::template keep<current>::rtn,
			typename append<current, filtered>::rtn,
			filtered
		>::return_type;

	using rtn = typename filter<test, new_filtered, mlist<params...> >::rtn;
};

template<typename test, typename filtered>
struct filter<test, filtered, null_mlist>
{
	using rtn = filtered;
};

