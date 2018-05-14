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

template<typename predicate, typename expression>
struct filter
{
	template<typename inBase, typename outBase = typename inBase::null>
	struct strict;

	template<typename in_first, typename... in_params, typename... out_params>
	struct strict<base<in_first, in_params...>, base<out_params...>>
	{
		using outBase = typename block
		<
			if_then
			<
				typename predicate::template test<in_first>,
				base<out_params..., in_first>
		
			>, then
			<
				base<out_params...>
			>

		>::rtn;

		using rtn = typename strict<base<in_params...>, outBase>::rtn;
	};

	template<typename... out_params>
	struct strict<null_base, base<out_params...>>
	{
		using rtn = base<out_params...>;
	};

	using rtn = typename strict<typename expression::rtn>::rtn;
};

