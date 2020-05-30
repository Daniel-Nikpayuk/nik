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


#define nik_assemblic_unpack(_path_, _library_, _universe_, _language_, _module_, _division_)				\
															\
	nik_stringify(_path_/module-assemblic/discourse/_library_-_universe_-_language_-_module_-_division_-semiotic.h)


/***********************************************************************************************************************/


#define nik_assemblic_typedef(_library_, _universe_, _language_, _module_, _division_)					\
															\
	nik_stringify(../../module-assemblic/discourse/_library_-_universe_-_language_-_module_-_division_-semiotic.h)


/***********************************************************************************************************************/


#define nik_assemblic_import(_path_, _library_, _universe_, _language_, _module_, _division_)				\
															\
	nik_stringify(_path_/module-assemblic/discourse/_library_-_universe_-_language_-_module_-_division_-media.h)


/***********************************************************************************************************************/


#define nik_assemblic_using(_library_, _universe_, _language_, _module_, _division_)					\
															\
	nik_stringify(../../module-assemblic/discourse/_library_-_universe_-_language_-_module_-_division_-media.h)

