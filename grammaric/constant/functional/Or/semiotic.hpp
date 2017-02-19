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

template<typename E1, typename E2, typename... E>
struct Or
{
	template<typename, typename, typename...> struct strict;

	template<bool value1, bool value2, typename e3, typename... e>
	struct strict<b<value1>, b<value2>, e3, e...>
	{
		static constexpr bool value = value1 || strict
		<
			b<value2>,
			typename e3::rtn,
			e...

		>::value;
	};

	template<bool value1, bool value2>
	struct strict<b<value1>, b<value2>>
	{
		static constexpr bool value = (value1 || value2);
	};

	using rtn = b
	<
		strict
		<
			typename E1::rtn,
			typename E2::rtn,
			E...

		>::value
	>;
};

