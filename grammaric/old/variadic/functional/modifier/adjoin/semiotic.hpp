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

template<typename expression, typename str>
struct adjoin
{
	template<typename inBase, typename s, typename outBase = typename inBase::null>
	struct strict;

	template<typename in_first, typename... in_params, typename s, typename... out_params>
	struct strict<base<in_first, in_params...>, s, base<out_params...>>
	{
		using rtn = typename block
		<
			if_then
			<
				eq<in_first, s>,
				base<out_params..., in_first, in_params...>

			>, else_then
			<
				gt<in_first, s>,
				base<out_params..., s, in_first, in_params...>

			>, then
			<
				strict<base<in_params...>, s, base<out_params..., in_first>>
			>

		>::rtn;
	};

	template<typename s, typename... out_params>
	struct strict<null_base, s, base<out_params...>>
	{
		using rtn = base<out_params..., s>;
	};

	using rtn = typename strict
	<
		typename expression::rtn,
		typename str::rtn

	>::rtn;
};

