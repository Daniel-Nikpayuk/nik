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

template<typename predicate, typename first, typename second>
struct conditional
{
	template<bool, typename, typename if_false>
	struct if_then_else { using rtn = typename if_false::rtn; };

	template<typename if_true, typename if_false>
	struct if_then_else<true, if_true, if_false>
	{
		using rtn = typename if_true::rtn;
	};

	using rtn = typename if_then_else
	<
		predicate::rtn::value,
		first,
		second

	>::rtn;
};

