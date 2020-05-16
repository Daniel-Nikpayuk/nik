/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef NIK_EXCLUSIVE_H
#define NIK_EXCLUSIVE_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_stringify(_string_)												\
															\
	#_string_


#define nik_catenate(_label1_, _label2_)										\
															\
	_label1_##_label2_


	// preprocessor hack:

#define nik_safe(_label1_, _label2_)											\
															\
	nik_catenate(_label1_, _label2_)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


//	inductor definitions:


#include<stdio.h>

namespace nik
{
	using global_size_type		= signed long long;	// size_t;

	using voidptr			= void *;		// compliment to nullptr ( = 0 )

	struct global_filler		{ };			// keyword.

	using filler			= global_filler *;


/***********************************************************************************************************************/


	enum struct Library	: global_size_type;
	enum struct Universe	: global_size_type;
	enum struct Language	: global_size_type;

	enum struct Reading	: global_size_type;
	enum struct Permission	: global_size_type;
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include"library-symbolic/semiotic.h"
//#include"library-assemblic/semiotic.h"

#include"universe-symbolic/semiotic.h"
//#include"universe-assemblic/semiotic.h"

#include"language-symbolic/semiotic.h"
//#include"language-assemblic/semiotic.h"


/***********************************************************************************************************************/
/***********************************************************************************************************************/


//	navigator definitions:


namespace nik
{
	enum struct Reading : global_size_type
	{
		symbolic,
		assemblic,

		dimension // filler
	};

	enum struct Permission : global_size_type
	{
		semiotic,
		media,

		dimension // filler
	};
}


#endif
