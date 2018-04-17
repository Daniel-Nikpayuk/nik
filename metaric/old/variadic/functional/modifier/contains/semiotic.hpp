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

template<typename expression, typename str>
struct contains
{
	template<typename Base, typename s>
	struct strict;

	template<typename first, typename... params, typename s>
	struct strict<base<first, params...>, s>
	{
		using rtn = typename And
		<
			less_than_or_equal<first, s>,
			Or
			<
				eq<first, s>,
				strict<base<params...>, s>
			>

		>::rtn;
	};

	template<typename s>
	struct strict<null_base, s>
	{
		struct rtn
		{
			static constexpr bool value = false;
		};
	};

	using rtn = typename strict
	<
		typename expression::rtn,
		typename str::rtn

	>::rtn;
};

