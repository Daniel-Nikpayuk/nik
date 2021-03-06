/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef SYMBOLIC_INTERFACE_STRUCTURE_SEMIOTIC_H
#define SYMBOLIC_INTERFACE_STRUCTURE_SEMIOTIC_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


namespace nik
{
	template<filler...> struct list_filler								{ }; // keyword.

	template<typename...> struct tuple_filler							{ }; // keyword.

	template<template<typename> class> struct call							{ }; // keyword

	template<typename> struct turn									{ }; // keyword

	template<template<nik_nullptr, typename> class> struct moiz					{ }; // keyword

	template<nik_nullptr(*)nik_nullptr> struct pose							{ }; // keyword


}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
