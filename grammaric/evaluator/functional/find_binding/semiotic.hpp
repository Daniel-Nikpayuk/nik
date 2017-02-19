/************************************************************************************************************************
**
** Copyright 2016, 2017 Daniel Nikpayuk
**
** This file is part of POCC.
**
** POCC is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
**
** POCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
** of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along with POCC. If not, see
** <http://www.gnu.org/licenses/>.
**
************************************************************************************************************************/

template<typename Frame, typename variable>
struct find_binding
{
	template<typename Frame> struct strict;

	template<typename Variable, typename Type, typename... bindings>
	struct strict<frame< binding<Variable, Type>, bindings...>>
	{
		using rtn = typename conditional
		<
			equal<Variable, variable>,
			binding<Variable, Type>,
			strict<bindings...>

		>::rtn;
	};

	using rtn = typename strict<Frame>::rtn;
};

