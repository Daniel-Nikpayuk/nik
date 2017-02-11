/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename predicate, typename inTuple, typename outTuple = typename inTuple::null>
struct filter;

template<typename predicate, typename in_first, typename... in_params, typename... out_params>
struct filter<predicate, tuple<in_first, in_params...>, tuple<out_params...>>
{
	using outTuple = typename block
	<
		if_then
		<
			typename predicate::template test<in_first>,
			tuple<out_params..., in_first>

		>, then
		<
			tuple<out_params...>
		>

	>::rtn;

	using rtn = typename filter<predicate, tuple<in_params...>, outTuple>::rtn;
};

template<typename predicate, typename... out_params>
struct filter<predicate, null_tuple, tuple<out_params...>>
{
	using rtn = tuple<out_params...>;
};

