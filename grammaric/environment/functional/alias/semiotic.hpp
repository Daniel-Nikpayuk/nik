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

template<typename Type, Type... Value>
using constant = typename constant::template constant<Type, Value...>;

//

template<typename... Expressions>
using tuple = typename tuple::template tuple<constants...>;

using null_tuple = typename tuple::null_tuple;

//

template<typename P, typename E1, typename E2>
using conditional = typename branch::template conditional<P, E1, E2>;

//

template<typename Variable, typename Type, Type... values>
using binding = typename structural::template b<Variable, Type, values...>;

using null_b = typename structural::null_b;

//

template<typename... variables>
using v = typename structural::template v<variables...>;

using null_v = typename structural::null_v;

//

template<typename... bindings>
using f = typename structural::template f<bindings...>;

using null_f = typename structural::null_f;

//

template<typename... frames>
using e = typename structural::template e<frames...>;

using null_e = typename structural::null_e;

