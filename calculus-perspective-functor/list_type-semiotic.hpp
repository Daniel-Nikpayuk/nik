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

/*
	cons:
*/

template<typename...> struct cons;

template<typename Exp, typename... Exps, template<typename...> class ListType>
struct cons<Exp, ListType<Exps...>>
{
	using rtn = ListType<Exp, Exps...>;
};

/*
	car:
*/

template<typename...> struct car;

template<typename Exp, typename... Exps, template<typename...> class ListType>
struct car<ListType<Exp, Exps...>>
{
	using rtn = Exp;
};

/*
	cdr:
*/

template<typename...> struct cdr;

template<typename Exp, typename... Exps, template<typename...> class ListType>
struct cdr<ListType<Exp, Exps...>>
{
	using rtn = ListType<Exps...>;
};

