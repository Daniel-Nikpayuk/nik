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

#ifndef NIK_H
#define NIK_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include"keyword.h"

#include"namespace.h"

#include"printer.h"

//#include"error.h"

//#include"user.h"


/***********************************************************************************************************************/
/***********************************************************************************************************************/

/*
	Currently deprecated, needs updating:

#define nik_using(branch, name)												\
															\
	using name = nik::branch::name##Module<size_type>;


#define nik_import(branch, module, name)										\
															\
	branch##_##module##_import_##name()
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#ifndef LAZY


#define nik_stringify(string)												\
															\
	#string


#define nik_module(name)												\
															\
	nik_stringify(header/name.h)


#include nik_module(word)


#endif


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
