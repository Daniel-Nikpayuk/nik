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

	judgment,

	bool_judgment,

	unsigned_char_judgment,
	signed_char_judgment,
	unsigned_short_judgment,
	signed_short_judgment,
	unsigned_int_judgment,
	signed_int_judgment,
	unsigned_long_judgment,
	signed_long_judgment,
	unsigned_long_long_judgment,
	signed_long_long_judgment,

	char_judgment,
	wchar_t_judgment,
	char16_t_judgment,
	char32_t_judgment,

	pair,
	copair,
	function,

	judgment_stem,
	judgment_list,
	judgment_colist,

	bool_list,

	unsigned_char_list,
	signed_char_list,
	unsigned_short_list,
	signed_short_list,
	unsigned_int_list,
	signed_int_list,
	unsigned_long_list,
	signed_long_list,
	unsigned_long_long_list,
	signed_long_long_list,

	char_list,
	wchar_t_list,
	char16_t_list,
	char32_t_list,

	typename_stem,
	typename_list,
	typename_colist,

	builtin_judgment, // dispatch by builtin judgment

	regular_text,

	literal,

	natural8,
	natural16,
	natural32,
	natural64,

	integer8,
	integer16,
	integer32,
	integer64,

	number,

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
	nik_stringify(_path_/module-symbolic/discourse/_library_-_universe_-_language_-_module_/_division_-semiotic.h)


/***********************************************************************************************************************/


#define nik_symbolic_typedef(_library_, _universe_, _language_, _module_, _division_)					\
															\
	nik_stringify(../../module-symbolic/discourse/_library_-_universe_-_language_-_module_/_division_-semiotic.h)


/***********************************************************************************************************************/


#define nik_symbolic_import(_path_, _library_, _universe_, _language_, _module_, _division_)				\
															\
	nik_stringify(_path_/module-symbolic/discourse/_library_-_universe_-_language_-_module_/_division_-media.h)


/***********************************************************************************************************************/


#define nik_symbolic_using(_library_, _universe_, _language_, _module_, _division_)					\
															\
	nik_stringify(../../module-symbolic/discourse/_library_-_universe_-_language_-_module_/_division_-media.h)


