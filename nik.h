/************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef NIK_H
#define NIK_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include"namespace.h"

//#include"error.h"

#include"printer.h"

//#include"user.h"


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define stringify(string)												\
	#string


#define build(name, path)												\
	stringify(path/nik/module/name.cpp)


#define lazy_nik(name, path)												\
	stringify(path/nik/module/name.h)


#define nik(name)													\
	stringify(module/name.h)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#ifndef LAZY


#include nik(iterator)


#endif


/***********************************************************************************************************************/
/***********************************************************************************************************************/

#endif
