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

template<typename Parameter, Parameter... params>
using list = typename identifier::template parameter<Parameter>::template list<params...>;

template<typename Parameter>
using null_list = typename identifier::template parameter<Parameter>::null_list;

template<typename T>
using kind = typename identifier::template kind<T>;

//

template<typename str1, typename str2>
using eq = typename identifier::template eq<str1, str2>;

template<typename str1, typename str2>
using equal = typename identifier::template equal<str1, str2>;

template<typename str1, typename str2>
using less_than = typename identifier::template less_than<str1, str2>;

template<typename str1, typename str2>
using less_than_or_equal = typename identifier::template less_than_or_equal<str1, str2>;

template<typename str1, typename str2>
using greater_than = typename identifier::template greater_than<str1, str2>;

template<typename str1, typename str2>
using greater_than_or_equal = typename identifier::template greater_than_or_equal<str1, str2>;

//

template<typename... expressions>
using empty = typename identifier::template empty<expressions...>;

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
using base = typename structural::template base<params...>;

using null_base = typename structural::null_base;

