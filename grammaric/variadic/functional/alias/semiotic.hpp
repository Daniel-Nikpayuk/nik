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

template<bool p>
using boolean = typename identifier::template boolean<p>;

template<typename Parameter, Parameter p>
using constant = typename identifier::template parameter<Parameter>::template constant<p>;

template<typename T>
using kind = typename identifier::template kind<T>;

//

template<typename f, typename... a>
using applicative = typename control_flow::template applicative<f, a...>;

//

template<typename p, typename t, typename f>
using conditional = typename control_flow::template conditional<p, t, f>;

//

template<typename p, typename e>
using if_then = typename control_flow::template if_then<p, e>;

template<typename p, typename e>
using else_then = typename control_flow::template else_then<p, e>;

template<typename e>
using then = typename control_flow::template then<e>;

template<typename... s>
using block = typename control_flow::template block<s...>;

//

template<typename... params>
using tuple = typename structural::template tuple<params...>;

using null_tuple = typename structural::null_tuple;

