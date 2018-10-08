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

#ifndef LAZY_H
#define LAZY_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_stringify(string)												\
															\
	#string


#define nik_source(path, branch, module, space)										\
															\
	nik_stringify(path/include/branch-module-space.h)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_unpack(path, branch, module, name)										\
															\
	nik_stringify(path/branch/module/unpack_##name.h)


#define nik_unpack_using(branch, module, name)										\
															\
	nik_stringify(../../branch/module/unpack_##name.h)


#define nik_unpack_typedef(name)											\
															\
	nik_stringify(../../unpack_##name.h)


/***********************************************************************************************************************/


#define nik_import(path, branch, module, name)										\
															\
	nik_stringify(path/branch/module/import_##name.h)


#define nik_import_using(branch, module, name)										\
															\
	nik_stringify(../../branch/module/import_##name.h)


#define nik_import_typedef(name)											\
															\
	nik_stringify(../../import_##name.h)


/***********************************************************************************************************************/


#define nik_printer(path)												\
															\
	nik_stringify(path/graphic/printer/verb.h)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include"global.h"


/***********************************************************************************************************************/
/***********************************************************************************************************************/


namespace nik
{
	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct metaric
	{
		static_assert
		(
			module_enum == Module::proto		||
			module_enum == Module::constant		||
			module_enum == Module::tuple		||
			module_enum == Module::conditional	||
			module_enum == Module::builtin

			, "This is not a valid metaric module!"
		);
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct grammaric
	{
		static_assert
		(
			module_enum == Module::generic	||
			module_enum == Module::pointer	||
			module_enum == Module::power

			, "This is not a valid grammaric module!"
		);
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct numeric
	{
		static_assert
		(
			module_enum == Module::bit	||
			module_enum == Module::word	||
			module_enum == Module::address

			, "This is not a valid numeric module!"
		);
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct literic
	{
/*
		static_assert
		(
			module_enum == Module::

			, "This is not a valid literic module!"
		);
*/
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct graphic
	{
/*
		static_assert
		(
			module_enum == Module::

			, "This is not a valid graphic module!"
		);
*/
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct phonetic
	{
/*
		static_assert
		(
			module_enum == Module::

			, "This is not a valid phonetic module!"
		);
*/
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct kinetic
	{
/*
		static_assert
		(
			module_enum == Module::

			, "This is not a valid kinetic module!"
		);
*/
	};

/***********************************************************************************************************************/

	template<Module module_enum, Permission permission_enum, typename SizeType = global_size_type>
	struct interic
	{
/*
		static_assert
		(
			module_enum == Module::

			, "This is not a valid interic module!"
		);
*/
	};
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_module(branch, module, name)										\
															\
	branch<Module::module, Permission::name, SizeType>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
