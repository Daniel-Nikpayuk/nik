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

template<Parameter v>
struct constant
{
	static constexpr Parameter value = v;
};

//

template<typename, typename...>
struct applicative;

template<typename function, typename first, typename... params>
struct applicative<function, first, params...>
{
	struct partial
	{
		template<Parameter... args>
		using lambda = typename function::template lambda<first::value, args...>;
	};

	static constexpr Parameter value = applicative<partial, params...>::value;
};

template<typename function>
struct applicative<function>
{
	static constexpr Parameter value = function::template lambda<>::value;
};

