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

template<bool Value>
struct static_error
{
	static_assert(Value, "EVAL fail!");

	using rtn = void;
};

template<typename Expression, typename... Expressions, typename... Frames>
struct EVAL<tuple<Expression, Expressions...>, environment<Frames...>>
{
	using Environment = environment<Frames...>;

	using rtn = typename block
	<
		if_then
		<
			is_begin<Expression>,
			BEGIN<Expression, Environment>

		>, else_then
		<
			is_application<Expression>,
			APPLY<Expression, Environment>

		>, then
		<
			static_error<true>
		>

	>::rtn::rtn;
};

