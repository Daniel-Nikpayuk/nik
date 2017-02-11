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

template<typename Parameter, Parameter... params>
struct parameter
{
	template<typename List, typename Filler = void>
	struct strict;

	template<Parameter first, Parameter... args, typename Filler>
	struct strict<list<Parameter, first, args...>, Filler>
	{
		using rtn = typename catenate
		<
			base<constant<Parameter, first>>,
			strict<list<Parameter, args...>, Filler>

		>::rtn;
	};

	template<typename Filler>
	struct strict<null_list<Parameter>, Filler>
	{
		using rtn = null_base;
	};

	using rtn = typename strict<list<Parameter, params...>>::rtn;
};

