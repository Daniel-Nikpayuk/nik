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


enum struct Module : global_size_type
{
// kernel:

	builtin,
	judgement,

	pair,
	copair,
	boolean,
	stem,
	list,
	colist,
	function,
	lambda,

	operate,
	literal,
	number,
	natural8,
	natural16,
	natural32,
	natural64,
	integer8,
	integer16,
	integer32,
	integer64,

// real:

// scheme:

	applicative,
	normal,

// numeric:

	pointer,
	power,
	bit,
	word,
	address,

// literic:

// graphic:

	printer,

// kinetic:

// phonetic:

// interic:

	dimension // filler
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_module(_library_, _universe_, _language_, _module_, _reading_, _permission_)				\
															\
	nik::module													\
	<														\
		nik::Library::_library_,										\
		nik::Universe::_universe_,										\
		nik::Language::_language_,										\
		nik::Module::_module_,											\
															\
		nik::Reading::_reading_,										\
		nik::Permission::_permission_,										\
															\
		SIZE_TYPE												\
	>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_module_source(_path_, _division_, _reading_, _permission_)							\
															\
	nik_stringify(_path_/module-_reading_/_division_-_permission_.hpp)


#define nik_source(_path_, _library_, _universe_, _language_, _module_, _reading_, _permission_)			\
															\
	nik_stringify(_path_/module-_reading_/narrative/_library_-_universe_-_language_-_module_-_permission_.h)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_symbolic_unpack(_path_, _library_, _universe_, _language_, _module_, _division_)				\
															\
	nik_stringify(_path_/module-symbolic/discourse/_library_-_universe_-_language_-_module_-_division_-semiotic.h)


/***********************************************************************************************************************/


#define nik_symbolic_typedef(_library_, _universe_, _language_, _module_, _division_)					\
															\
	nik_stringify(../../module-symbolic/discourse/_library_-_universe_-_language_-_module_-_division_-semiotic.h)


/***********************************************************************************************************************/


#define nik_symbolic_import(_path_, _library_, _universe_, _language_, _module_, _division_)				\
															\
	nik_stringify(_path_/module-symbolic/discourse/_library_-_universe_-_language_-_module_-_division_-media.h)


/***********************************************************************************************************************/


#define nik_symbolic_using(_library_, _universe_, _language_, _module_, _division_)					\
															\
	nik_stringify(../../module-symbolic/discourse/_library_-_universe_-_language_-_module_-_division_-media.h)

