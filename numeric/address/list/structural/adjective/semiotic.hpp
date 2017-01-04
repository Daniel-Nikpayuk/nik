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


// Adjective Associations:


enum struct Association : size_type
{
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
*/


enum struct Attribute : size_type
{
	interval,

	dimension
};


using AttributeList = typename parameter<Attribute>::template list
<
	Attribute::interval
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<Association... params>
using adj_list = typename parameter<Association>::template list<params...>;

template<Attribute i>
using enum_cast = typename variadic<Orientation::functional, Interface::semiotic>::template enum_cast<AttributeList, i>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L>
struct Adjective
{
	using parameter_list = L;

	static constexpr Association interval_enum	= at<L, enum_cast<Attribute::interval>::rtn	>::rtn;

	Adjective() { }
};



