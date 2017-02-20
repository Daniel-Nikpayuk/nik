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

using Constant_Functional_Semiotic = typename nik::grammaric::module
<
	nik::Module::		constant,
	nik::Orientation::	functional,
	nik::Interface::	semiotic
>;

/***********************************************************************************************************************/

template<typename E1, typename E2>
using equal = typename Constant_Functional_Semiotic::template equal<E1, E2>;

template<typename E1, typename E2>
using less_than = typename Constant_Functional_Semiotic::template less_than<E1, E2>;

template<typename E1, typename E2>
using less_than_or_equal = typename Constant_Functional_Semiotic::template less_than_or_equal<E1, E2>;

template<typename E1, typename E2>
using greater_than = typename Constant_Functional_Semiotic::template greater_than<E1, E2>;

template<typename E1, typename E2>
using greater_than_or_equal = typename Constant_Functional_Semiotic::template greater_than_or_equal<E1, E2>;

template<typename... E>
using empty = typename Constant_Functional_Semiotic::template empty<E...>;

template<typename E1>
using is_constant = typename Constant_Functional_Semiotic::template is_constant<E1>;

/***********************************************************************************************************************/

template<typename E1>
using Not = typename Constant_Functional_Semiotic::template Not<E1>;

template<typename E1, typename E2, typename... E>
using And = typename Constant_Functional_Semiotic::template And<E1, E2, E...>;

template<typename E1, typename E2, typename... E>
using Or = typename Constant_Functional_Semiotic::template Or<E1, E2, E...>;

