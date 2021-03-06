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


//#include nik_source(., patronum, natural, kernel, builtin, symbolic, semiotic)				// redundant inclusion
#include nik_source(., straticum, natural, kernel, builtin, symbolic, semiotic)				// redundant inclusion


/***********************************************************************************************************************/
/***********************************************************************************************************************/


//#include nik_source(., patronum, natural, kernel, judgment, assemblic, semiotic)				// redundant inclusion


/***********************************************************************************************************************/


//#include nik_source(., straticum, natural, kernel, bool_judgment, assemblic, semiotic)			// redundant inclusion

//#include nik_source(., straticum, natural, kernel, unsigned_char_judgment, assemblic, semiotic)		// redundant inclusion
//#include nik_source(., straticum, natural, kernel, signed_char_judgment, assemblic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, unsigned_short_judgment, assemblic, semiotic)		// redundant inclusion
//#include nik_source(., straticum, natural, kernel, signed_short_judgment, assemblic, semiotic)		// redundant inclusion
//#include nik_source(., straticum, natural, kernel, unsigned_int_judgment, assemblic, semiotic)		// redundant inclusion
//#include nik_source(., straticum, natural, kernel, signed_int_judgment, assemblic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, unsigned_long_judgment, assemblic, semiotic)		// redundant inclusion
//#include nik_source(., straticum, natural, kernel, signed_long_judgment, assemblic, semiotic)			// redundant inclusion
#include nik_source(., straticum, natural, kernel, unsigned_long_long_judgment, assemblic, semiotic)		// redundant inclusion
#include nik_source(., straticum, natural, kernel, signed_long_long_judgment, assemblic, semiotic)		// redundant inclusion

#include nik_source(., straticum, natural, kernel, char_judgment, assemblic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, wchar_t_judgment, assemblic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, char16_t_judgment, assemblic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, char32_t_judgment, assemblic, semiotic)			// redundant inclusion


/***********************************************************************************************************************/


//#include nik_source(., patronum, natural, kernel, judgment, symbolic, semiotic)				// redundant inclusion


/***********************************************************************************************************************/


#include nik_source(., straticum, natural, kernel, bool_judgment, symbolic, semiotic)			// redundant inclusion

//#include nik_source(., straticum, natural, kernel, unsigned_char_judgment, symbolic, semiotic)		// redundant inclusion
//#include nik_source(., straticum, natural, kernel, signed_char_judgment, symbolic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, unsigned_short_judgment, symbolic, semiotic)		// redundant inclusion
//#include nik_source(., straticum, natural, kernel, signed_short_judgment, symbolic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, unsigned_int_judgment, symbolic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, signed_int_judgment, symbolic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, unsigned_long_judgment, symbolic, semiotic)		// redundant inclusion
//#include nik_source(., straticum, natural, kernel, signed_long_judgment, symbolic, semiotic)			// redundant inclusion
#include nik_source(., straticum, natural, kernel, unsigned_long_long_judgment, symbolic, semiotic)		// redundant inclusion
#include nik_source(., straticum, natural, kernel, signed_long_long_judgment, symbolic, semiotic)		// redundant inclusion

#include nik_source(., straticum, natural, kernel, char_judgment, symbolic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, wchar_t_judgment, symbolic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, char16_t_judgment, symbolic, semiotic)			// redundant inclusion
//#include nik_source(., straticum, natural, kernel, char32_t_judgment, symbolic, semiotic)			// redundant inclusion


/***********************************************************************************************************************/


//#include nik_source(., patronum, natural, kernel, pair, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, copair, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, function, symbolic, semiotic)				// redundant inclusion

//#include nik_source(., patronum, natural, kernel, typename_stem, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, typename_list, symbolic, semiotic)
//#include nik_source(., patronum, natural, kernel, typename_colist, symbolic, semiotic)


/***********************************************************************************************************************/


//#include nik_source(., patronum, natural, kernel, judgment_stem, assemblic, semiotic)				// redundant inclusion
#include nik_source(., patronum, natural, kernel, judgment_list, assemblic, semiotic)
//#include nik_source(., patronum, natural, kernel, judgment_colist, assemblic, semiotic)


/***********************************************************************************************************************/


#include nik_source(., straticum, natural, kernel, char_list, assemblic, semiotic)				// 
														// string literal
														// display


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
