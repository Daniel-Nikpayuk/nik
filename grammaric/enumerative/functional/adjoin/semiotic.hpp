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

/*
	Assumes modifier:
*/

template<typename inBase, Parameter p, typename outBase = typename inBase::null>
struct adjoin;

template<Parameter in_first, Parameter... in_params, Parameter p, Parameter... out_params>
struct adjoin<base<in_first, in_params...>, p, base<out_params...>>
{
	using type = typename condition
	<
		control<(in_first == p),	base<out_params..., in_first, in_params...>>,
		control<(in_first > p),		base<out_params..., p, in_first, in_params...>>,

		typename adjoin<base<in_params...>, p, base<out_params..., in_first>>::type

	>::type;
};

template<Parameter p, Parameter... out_params>
struct adjoin<null_base, p, base<out_params...>>
{
	using type = base<out_params..., p>;
};

