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

template<typename, typename> struct BEGIN;

template<typename Expression, typename... Expressions, typename... Frames>
struct BEGIN<expression<Expression, Expressions...>, environment<Frames...>>
{
	using Environment = environment<Frames...>;

	using rtn = typename cons
	<
		EVAL<Expression, Environment>,
		BEGIN<expression<Expressions...>, Environment>

	>::rtn;
};

//

template<typename>
struct is_begin
{
	using rtn = boolean<false>;
};

template<typename... Expressions>
struct is_begin<BEGIN<Expressions...>>
{
	using rtn = boolean<true>;
};

