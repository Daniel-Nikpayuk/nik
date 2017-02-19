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

template<typename Environment, typename variable>
struct lookup
{
	template<typename Env> struct env_strict;

	template<typename Frame, typename Frames...>
	struct env_strict<environment<Frame, Frames...>>
	{
		using has = find<Frame, variable>;

		using rtn = typename conditional
		<
			has,

		>::rtn;
	};

	template<typename Filler>
	struct env_strict<null_environment>
	{
	};

	using rtn = typename env_strict<>;
};

