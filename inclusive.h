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

#ifndef NIK_INCLUSIVE_H
#define NIK_INCLUSIVE_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include"exclusive.h"


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include nik_library_source(., identity, symbolic, semiotic)
#include nik_library_source(., embedding, assemblic, semiotic)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include nik_universe_source(., identity, symbolic, semiotic)
#include nik_universe_source(., embedding, assemblic, semiotic)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include nik_language_source(., identity, symbolic, semiotic)
#include nik_language_source(., embedding, assemblic, semiotic)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include nik_module_source(., identity, symbolic, semiotic)
#include nik_module_source(., embedding, assemblic, semiotic)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include nik_source(., patronum, natural, kernel, builtin, symbolic, semiotic)		// redundant inclusion

//#include nik_source(., straticum, natural, kernel, builtin, symbolic, semiotic)


/***********************************************************************************************************************/


//#include nik_source(., patronum, natural, kernel, judgement, symbolic, semiotic)		// redundant inclusion
//#include nik_source(., patronum, natural, kernel, judgement, assemblic, semiotic)

//#include nik_source(., straticum, natural, kernel, judgement, symbolic, semiotic)
//#include nik_source(., straticum, natural, kernel, judgement, assemblic, semiotic)


/***********************************************************************************************************************/


//#include nik_source(., patronum, natural, kernel, pair, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, copair, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, boolean, symbolic, semiotic)

//#include nik_source(., patronum, natural, kernel, list, symbolic, semiotic)

//#include nik_source(., patronum, natural, kernel, colist, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, operate, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, literal, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, number, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, integer32, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, function, symbolic, semiotic)


/***********************************************************************************************************************/


#include nik_source(., straticum, natural, kernel, list, assemblic, semiotic)		// list_display (string literals)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
