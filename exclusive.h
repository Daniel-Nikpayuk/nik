/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef EXCLUSIVE_H
#define EXCLUSIVE_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_stringify(string)												\
															\
	#string


#define nik_catenate(label1, label2)											\
															\
	label1##label2


#define nik_safe(label1, label2)											\
															\
	nik_catenate(label1, label2)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_source(path, lens, branch, module, space)									\
															\
	nik_stringify(path/lens-interface-navigator/branch-module-space.h)


/***********************************************************************************************************************/


#define nik_typedef(lens, branch, module, name)										\
															\
	nik_stringify(../../../lens-model/branch-module-name-semiotic.h)


#define nik_unpack(path, lens, branch, module, name)									\
															\
	nik_stringify(path/lens-model/branch-module-name-semiotic.h)


/***********************************************************************************************************************/


#define nik_using(lens, branch, module, name)										\
															\
	nik_stringify(../../../lens-model/branch-module-name-media.h)


#define nik_import(path, lens, branch, module, name)									\
															\
	nik_stringify(path/lens-model/branch-module-name-media.h)


/***********************************************************************************************************************/


#define nik_printer(path)												\
															\
	nik_stringify(path/assemblic-model/graphic-printer-media.h)


/***********************************************************************************************************************/


#define nik_branch(name, lens, permission)										\
															\
	nik::branch													\
	<														\
		nik::Branch::name,											\
		nik::Lens::lens,											\
		nik::Permission::permission,										\
															\
		SIZE_TYPE												\
	>


#define nik_module(name, branch, lens, permission)									\
															\
	nik::module													\
	<														\
		nik::Module::name,											\
		nik::Branch::branch,											\
		nik::Lens::lens,											\
		nik::Permission::permission,										\
															\
		SIZE_TYPE												\
	>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include"global.h"


/***********************************************************************************************************************/
/***********************************************************************************************************************/


namespace nik
{
	template
	<
		Branch		branch_enum,
		Lens		lens_enum,
		Permission	permission_enum,

		typename	SizeType = global_size_type
	>
	struct branch
	{
		using type	= branch;

		static_assert
		(
			branch_enum == Branch::core			||

//			branch_enum == Branch::core			||
			branch_enum == Branch::calculus			||
			branch_enum == Branch::lift			||
			branch_enum == Branch::scheme			||
			branch_enum == Branch::kin			||

			branch_enum == Branch::generic			||
			branch_enum == Branch::numeric			||
			branch_enum == Branch::literic			||
			branch_enum == Branch::graphic			||
			branch_enum == Branch::phonetic			||
			branch_enum == Branch::kinetic			||
			branch_enum == Branch::interic

			, "This is not a valid branch!"
		);
	};


/***********************************************************************************************************************/


	template
	<
		Module		module_enum,
		Branch		branch_enum,
		Lens		lens_enum,
		Permission	permission_enum,

		typename	SizeType = global_size_type
	>
	struct module
	{
		using type	= module;

		static_assert
		(

		// kernel:

			module_enum == Module::kernel			||

		// calculus:

			module_enum == Module::pair			||
			module_enum == Module::handle			||
			module_enum == Module::copair			||
			module_enum == Module::boolean			||
			module_enum == Module::recurse			||

			module_enum == Module::list			||
			module_enum == Module::colist			||

		// lift:

			module_enum == Module::operate			||

//			module_enum == Module::boolean			||
			module_enum == Module::literal			||
			module_enum == Module::number			||

			module_enum == Module::natural8			||
			module_enum == Module::natural16		||
			module_enum == Module::natural32		||
			module_enum == Module::natural64		||

			module_enum == Module::integer8			||
			module_enum == Module::integer16		||
			module_enum == Module::integer32		||
			module_enum == Module::integer64		||

		// scheme:

			module_enum == Module::normal			||
			module_enum == Module::lazy			||

		// kin:

			module_enum == Module::concept			||
			module_enum == Module::instance			||
			module_enum == Module::type			||
			module_enum == Module::judgement		||

		// generic:

			module_enum == Module::pointer			||
			module_enum == Module::power			||

		// numeric:

			module_enum == Module::bit			||
			module_enum == Module::word			||
			module_enum == Module::address

			, "This is not a valid module!"
		);

		static_assert
		(
			branch_enum == Branch::core			||

//			branch_enum == Branch::core			||
			branch_enum == Branch::calculus			||
			branch_enum == Branch::lift			||
			branch_enum == Branch::scheme			||
			branch_enum == Branch::kin			||

			branch_enum == Branch::generic			||
			branch_enum == Branch::numeric			||
			branch_enum == Branch::literic			||
			branch_enum == Branch::graphic			||
			branch_enum == Branch::phonetic			||
			branch_enum == Branch::kinetic			||
			branch_enum == Branch::interic

			, "This is not a valid branch!"
		);
	};
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
