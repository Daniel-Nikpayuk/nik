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

template<bool predicate, typename expression> struct control { };

//

template<typename... lines> struct condition;

template<bool predicate, typename expression, typename... lines>
struct condition<control<predicate, expression>, lines...>
{
	using type = typename if_then_else
	<
		predicate,
		expression,
		condition<lines...>

	>::type;
};

template<typename expression>
struct condition<expression>
{
	using type = typename expression::type;
};

