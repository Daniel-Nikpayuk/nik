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

template<typename Type1, typename Type2>
struct equal
{
	using rtn = boolean<false>;
};

template<typename Type>
struct equal<Type, Type>
{
	using rtn = boolean<true>;
};

//

template<typename Type, typename Exp>
struct equal<Type, act<Exp>>
{
	using rtn = typename equal<Type, typename Exp::rtn>::rtn;
};

template<typename Exp, typename Type>
struct equal<act<Exp>, Type>
{
	using rtn = typename equal<typename Exp::rtn, Type>::rtn;
};

template<typename Exp1, typename Exp2>
struct equal<act<Exp1>, act<Exp2>>
{
	using rtn = typename equal<typename Exp1::rtn, typename Exp2::rtn>::rtn;
};

