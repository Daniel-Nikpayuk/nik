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

template<typename expression>
struct length
{
	template<typename Base, size_type count = 0>
	struct strict;

	template<typename first, typename... params, size_type count>
	struct strict<base<first, params...>, count>
	{
		static constexpr size_type value = strict<base<params...>, count+1>::value;
	};

	template<size_type count>
	struct strict<null_base, count>
	{
		static constexpr size_type value = count;
	};

	struct rtn
	{
		static constexpr size_type value = strict<typename expression::rtn>::value;
	};
};

