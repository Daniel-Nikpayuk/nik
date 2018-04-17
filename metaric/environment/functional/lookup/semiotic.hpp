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

template<typename, typename> struct lookup;

template<typename Frame, typename... Frames, typename variable>
struct lookup<environment<Frame, Frames...>, variable>
{
	using Value = typename find<Frame, variable>::rtn;

	using rtn = typename conditional
	<
		equal<Value, undefined>,
		act
		<
			lookup<environment<Frames...>, variable>
		>,
		Value

	>::rtn;
};

template<typename variable>
struct lookup<null_environment, variable>
{
	using rtn = undefined;
};

