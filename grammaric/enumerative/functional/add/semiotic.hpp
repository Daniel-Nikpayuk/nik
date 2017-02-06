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

template<typename outBase, typename inBase>
struct add;

template<Parameter... out_params, Parameter in_first, Parameter... in_params>
struct add<base<out_params...>, base<in_first, in_params...>>
{
	using type = typename add
	<
		typename adjoin<base<out_params...>, in_first>::type,
		base<in_params...>

	>::type;
};

template<Parameter... out_params>
struct add<base<out_params...>, null_base>
{
	using type = base<out_params...>;
};

