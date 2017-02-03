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
	Adjective Associations:

				Strongly typed for improved type checking.

				Parameter pack being "typename..." requires adj_lists
				as enums themselves don't count as typenames.
*/


enum struct Association : size_type
{
	succeed,
	accede,

	forward,
	backward,

	closing,
	closed,
	opening,
	open,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Adjective Attributes:
				TUPLE/LIST data structures are appropriate here because resolution
				occurs during compile-time and the size is expected to be small.
*/


enum struct Attribute : size_type
{
	increment,

	direction,
	interval,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename... params>
struct adjective;


template<size_type mask>
struct adjective<mask> { static constexpr size_type bitmask = mask; };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<Association... params>
using adj_list = typename parameter<Association>::template list<params...>;

using null_adj = adj_list<>;


template<Association... params>
using adj_cast = typename bit::mask::template cast<adj_list<params...>>;

// "using" for polymorphic dispatching.

template<Association... params>
using Adjective = adjective<adj_cast<params...>::rtn>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


static constexpr size_type Accede = adj_cast<Association::accede>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<typename A>
struct adjective<Accede, A>
{
	static constexpr size_type bitmask = Accede;

	A accessor;

	adjective(const A & a) : accessor(a) { }
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


/************************************************************************************************************************
							3
************************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


