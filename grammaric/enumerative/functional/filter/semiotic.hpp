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

template<typename predicate, typename inBase, typename outBase = typename inBase::null>
struct filter;

template<typename predicate, Parameter in_first, Parameter... in_params, Parameter... out_params>
struct filter<predicate, base<in_first, in_params...>, base<out_params...>>
{
	using outBase = typename block
	<
		if_then
		<
			predicate::test(in_first),
			base<out_params..., in_first>

		>, then
		<
			base<out_params...>
		>

	>::type;

	using type = typename filter<predicate, base<in_params...>, outBase>::type;
};

template<typename predicate, Parameter... out_params>
struct filter<predicate, null_base, base<out_params...>>
{
	using type = base<out_params...>;
};

