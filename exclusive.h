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
	using global_size_type					= signed long long;	// size_t;

	using voidptr						= void *;		// compliment to nullptr ( = 0 )

	struct global_filler					{ };			// keyword.

	using filler						= global_filler *;


/***********************************************************************************************************************/


	enum struct Library	: global_size_type;
	enum struct Universe	: global_size_type;
	enum struct Language	: global_size_type;

	enum struct Reading	: global_size_type;
	enum struct Permission	: global_size_type;


/***********************************************************************************************************************/


	template
	<
		Library		library_enum,
		Universe	universe_enum,
		Language	language_enum,

		Reading		reading_enum,
		Permission	permission_enum,

		typename	size_type = global_size_type

	> struct module
	{
		// Check to see if a given module has been partially specialized.

		template<typename Continuation>
		static constexpr bool result = Continuation::template result<false>;
	};


/***********************************************************************************************************************/


	template<typename>
	struct memoized_module
	{
		template<typename Continuation>
		static constexpr bool result = Continuation::template result<false>;
	};

	template
	<
		Library		library_enum,
		Universe	universe_enum,
		Language	language_enum,

		Reading		reading_enum,
		Permission	permission_enum,

		typename	size_type

	> struct memoized_module<module<library_enum, universe_enum, language_enum, reading_enum, permission_enum, size_type>>
	{
		template<typename Continuation>
		static constexpr bool result = Continuation::template result<true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			library_enum, universe_enum, language_enum, reading_enum, permission_enum, size_type
		>;
	};
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_begin_module(_library_, _universe_, _language_, _reading_, _permission_)					\
															\
	template<typename size_type>											\
	struct module													\
	<														\
		nik::Library::_library_,										\
		nik::Universe::_universe_,										\
		nik::Language::_language_,										\
															\
		nik::Reading::_reading_,										\
		nik::Permission::_permission_,										\
															\
		size_type												\
	>														\
	{														\
		template<typename Continuation>										\
		static constexpr bool result = Continuation::template result<true>;


#define nik_end_module(_library_, _universe_, _language_, _reading_, _permission_)					\
															\
	};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_module(_library_, _universe_, _language_, _reading_, _permission_)						\
															\
	nik::module													\
	<														\
		nik::Library::_library_,										\
		nik::Universe::_universe_,										\
		nik::Language::_language_,										\
															\
		nik::Reading::_reading_,										\
		nik::Permission::_permission_,										\
															\
		SIZE_TYPE												\
	>

/***********************************************************************************************************************/
/***********************************************************************************************************************/


//	navigator definitions:


namespace nik
{
	enum struct Library : global_size_type
	{
		straticum,
		patronum,

	// symbolic:

		calculus,
		scheme,
		hott,

	// assemblic:

		numeric,
		literic,
		graphic,
		kinetic,
		phonetic,
		interic,

		dimension // filler
	};

	enum struct Universe : global_size_type
	{
		kernel,

		dimension // filler
	};

	enum struct Language : global_size_type
	{
		builtin,

	// calculus:

		pair,
		lambda,
		copair,
		boolean,
		list,
		colist,
		function,

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

	// scheme:

		applicative,
		normal,

	// hott:

		judgement,

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


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_assemblic_unpack(_path_, _library_, _universe_, _language_, _module_)					\
															\
	nik_stringify(path/discourse/_library_-_universe_-_language_-_module_-assemblic-semiotic.h)


/***********************************************************************************************************************/


#define nik_assemblic_typedef(_library_, _universe_, _language_, _module_)						\
															\
	nik_stringify(../../discourse/_library_-_universe_-_language_-_module_-assemblic-semiotic.h)


/***********************************************************************************************************************/


#define nik_assemblic_import(_path_, _library_, _universe_, _language_, _module_)					\
															\
	nik_stringify(path/discourse/_library_-_universe_-_language_-_module_-assemblic-media.h)


/***********************************************************************************************************************/


#define nik_assemblic_using(_library_, _universe_, _language_, _module_)						\
															\
	nik_stringify(../../discourse/_library_-_universe_-_language_-_module_-assemblic-media.h)


/***********************************************************************************************************************/


#define nik_source(_path_, _reading_, _permission_)									\
															\
	nik_stringify(_path_/_reading_/_permission_.h)


#define nik_library_source(_path_, _library_, _reading_, _permission_)							\
															\
	nik_stringify(_path_/_library_/_reading_/_permission_.h)


#define nik_universe_source(_path_, _library_, _universe_, _reading_, _permission_)					\
															\
	nik_stringify(_path_/_library_/_universe_-_reading_/_permission_.h)


#define nik_language_source(_path_, _library_, _universe_, _language_, _reading_, _permission_)				\
															\
	nik_stringify(_path_/_library_/_universe_-_language_-_reading_/_permission_.h)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
