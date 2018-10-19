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


#define nik_catenate(label1, label2)											\
															\
	label1##label2


#define nik_safe(label1, label2)											\
															\
	nik_catenate(label1, label2)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_source(path, narrative, branch, module, space)								\
															\
	nik_stringify(path/narrative-interface-navigator/branch-module-space.h)


/***********************************************************************************************************************/


#define nik_module(name, branch, lens, permission)									\
															\
	nik::module													\
	<														\
		nik::Name::name,											\
		nik::Branch::branch,											\
		nik::Lens::lens,											\
		nik::Permission::permission,										\
															\
		SIZE_TYPE												\
	>


/***********************************************************************************************************************/


#define nik_lensdef(narrative, partition, division, space)								\
															\
	nik_stringify(../../../narrative-model/narrative-partition-division-space.h)


#define nik_lens(path, narrative, partition, division, space)								\
															\
	nik_stringify(path/narrative-model/narrative-partition-division-space.h)


/***********************************************************************************************************************/


#define nik_typedef(narrative, branch, module, name)									\
															\
	nik_stringify(../../../narrative-model/branch-module-name-semiotic.h)


#define nik_unpack(path, narrative, branch, module, name)								\
															\
	nik_stringify(path/narrative-model/branch-module-name-semiotic.h)


/***********************************************************************************************************************/


#define nik_using(narrative, branch, module, name)									\
															\
	nik_stringify(../../../narrative-model/branch-module-name-media.h)


#define nik_import(path, narrative, branch, module, name)								\
															\
	nik_stringify(path/narrative-model/branch-module-name-media.h)


/***********************************************************************************************************************/


#define nik_printer(path)												\
															\
	nik_stringify(path/hardware-model/graphic-printer-media.h)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include"global.h"


/***********************************************************************************************************************/
/***********************************************************************************************************************/


namespace nik
{
	template
	<
		Name		name_enum,
		Branch		branch_enum,
		Lens		lens_enum,
		Permission	permission_enum,

		typename	SizeType = global_size_type
	>
	struct module
	{
		using lens	= module;

		using type	= module;

		static_assert
		(
			name_enum == Name::undefined			||
			name_enum == Name::act				||

			name_enum == Name::op				||
			name_enum == Name::boolean			||
			name_enum == Name::literal			||
			name_enum == Name::number			||
			name_enum == Name::natural8			||
			name_enum == Name::natural16			||
			name_enum == Name::natural32			||
			name_enum == Name::natural64			||
			name_enum == Name::natural			||
			name_enum == Name::integer8			||
			name_enum == Name::integer16			||
			name_enum == Name::integer32			||
			name_enum == Name::integer64			||
			name_enum == Name::integer			||

/*
			name_enum == Name::conditional			||

			name_enum == Name::list				||

			name_enum == Name::binding			||
			name_enum == Name::frame			||
			name_enum == Name::environment			||

			name_enum == Name::begin			||
			name_enum == Name::body				||
			name_enum == Name::program			||
*/

			name_enum == Name::pointer			||
			name_enum == Name::power			||

			name_enum == Name::bit				||
			name_enum == Name::word				||
			name_enum == Name::address

			, "This is not a valid module!"
		);

		static_assert
		(
			branch_enum == Branch::kernel			||
			branch_enum == Branch::builtin			||
			branch_enum == Branch::dispatch			||
			branch_enum == Branch::variable			||
			branch_enum == Branch::interpret		||

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

	struct calculus
	{
		using lens	= calculus;

		using type	= calculus;

		#include"calculus-perspective-identity/semiotic.hpp"
		#include"calculus-perspective-functor/semiotic.hpp"
	};

/***********************************************************************************************************************/

	struct hardware
	{
		using lens	= hardware;

		using type	= hardware;

//		#include"hardware-perspective-identity/semiotic.hpp"
//		#include"hardware-perspective-functor/semiotic.hpp"
	};
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
