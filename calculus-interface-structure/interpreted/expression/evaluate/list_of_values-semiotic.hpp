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

template<typename, typename> struct list_of_values;

template<typename Exp, typename... Exps, typename Env>
struct list_of_values<e<Exp, Exps...>, Env>
{
	using rtn = actlif_cons
	<
		evaluate<Exp, Env>,

		list_of_values
		<
			e<Exps...>,

			Env
		>

	>::rtn;
};

template<typename Env>
struct list_of_values<null_expression, Env>
{
	using rtn = null_expression;
};

