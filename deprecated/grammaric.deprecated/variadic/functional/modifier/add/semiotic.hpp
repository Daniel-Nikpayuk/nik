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

template<typename outExpression, typename inExpression>
struct add
{
	template<typename outBase, typename inBase>
	struct strict;

	template<typename... out_params, typename in_first, typename... in_params>
	struct strict<base<out_params...>, base<in_first, in_params...>>
	{
		using rtn = typename strict
		<
			typename adjoin<base<out_params...>, in_first>::rtn,
			base<in_params...>

		>::rtn;
	};

	template<typename... out_params>
	struct strict<base<out_params...>, null_base>
	{
		using rtn = base<out_params...>;
	};

	using rtn = strict
	<
		typename outExpression::rtn,
		typename inExpression::rtn

	>::rtn;
};

