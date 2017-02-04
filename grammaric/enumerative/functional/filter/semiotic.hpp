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

template<typename predicate, typename inL, typename outL = typename inL::null>
struct filter;

template<typename predicate, Parameter in_first, Parameter... in_params, Parameter... out_params>
struct filter<predicate, list<in_first, in_params...>, list<out_params...>>
{
	using new_outL = typename if_then_else
	<
		predicate::test(in_first),
		list<out_params..., in_first>,
		list<out_params...>

	>::type;

	using type = typename filter<predicate, list<in_params...>, new_outL>::type;
};

template<typename predicate, Parameter... out_params>
struct filter<predicate, null_list, list<out_params...>>
{
	using type = list<out_params...>;
};

