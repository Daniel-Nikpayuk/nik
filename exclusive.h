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


#define nik_size_type(_macro_)												\
															\
	nik_stringify(../../../_macro_-size_type.h)


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
	using global_size_type						= signed long long;	// size_t;

	using void_ptr							= void *;		// compliment to nullptr ( = 0 )

	struct global_filler						{ };			// keyword.

	using filler							= global_filler *;	// can be passed as template judgment.

	static constexpr const char null_string_literal[]		= "";

	template<template<typename...> class...>
	using sfinae_try						= filler;

	// continuation halters:

		// symbolic:

			// type:

				struct ch_s_type
				{
					template<typename Type>
					using result = Type;
				};

				struct ch_s_types
				{
					template<template<typename...> class ListName, typename... Types>
					using result = ListName<Types...>;
				};

				template<typename Type>
				using s_identity				= ch_s_type::template result<Type>;

				struct ch_s_values
				{
					template<typename Type, template<Type...> class ListType, Type... Values>
					using result = ListType<Values...>;
				};

		// assemblic:

			// value:

				struct ch_a_value
				{
					template<typename Type, Type Value>
					static constexpr Type result = Value;
				};

				template<typename Type, Type Value>
				static constexpr Type a_identity		= ch_a_value::template result<Type, Value>;

		// procedural:

			// void:

				struct ch_p_void
				{
					static constexpr void result() { }
				};

			// identity:

				struct ch_p_identity
				{
					template<typename Type>
					static constexpr Type result(Type value) { return value; }
				};

				template<typename Type>
				static constexpr Type (*p_identity)(Type)	= ch_p_identity::template result<Type>;

	// continuation passers:

		// symbolic:

			// types to type:

				template<typename Continuation>
				struct cp_s_types_to_type
				{
					template<template<typename...> class ListName, typename Type, typename... Types>
					using result = typename Continuation::template result
					<
						Type
					>;
				};

				using ch_s_types_to_type			= cp_s_types_to_type<ch_s_type>;

			// value:

		// assemblic:

			// value:

				// values to value:

				template<typename Continuation>
				struct cp_a_values_to_value
				{
					template
					<
						typename Image, typename Type,
							template<Type...> class ListType, Type Value, Type... Values
					>
					static constexpr Image result = Continuation::template result
					<
						Image, (Image) Value
					>;
				};

				using ch_a_values_to_value			= cp_a_values_to_value<ch_a_value>;
				using ch_a_to_value				= cp_a_values_to_value<ch_a_value>;	// library default.


/***********************************************************************************************************************/


	enum struct Library	: global_size_type;
	enum struct Universe	: global_size_type;
	enum struct Language	: global_size_type;
	enum struct Module	: global_size_type;

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

#include"module-symbolic/semiotic.h"
#include"module-assemblic/semiotic.h"


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
