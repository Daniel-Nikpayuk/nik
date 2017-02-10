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

/*
template<typename f, typename... a>
using interpretive = typename control_flow::template interpretive<f, a...>;
*/

//

/*
template<bool p>
using boolean = typename control_flow::template boolean<p>;

template<typename p, typename e>
using if_then = typename control_flow::template if_then<p, e>;

template<typename p, typename e>
using else_then = typename control_flow::template else_then<p, e>;

template<typename e>
using then = typename control_flow::template then<e>;

template<typename... s>
using block = typename control_flow::template block<s...>;
*/

//

/*
template<Parameter v>
using constant = typename control_flow::template parameter<Parameter>::template constant<v>;

template<typename... s>
using branch = typename control_flow::template parameter<Parameter>::template branch<s...>;
*/

//

template<typename... params>
using base = typename structural::template base<params...>;

using null_base = base<>;

