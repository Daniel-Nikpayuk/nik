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

#ifndef NIK_INTERFACE_NAVIGATOR_SEMIOTIC_H
#define NIK_INTERFACE_NAVIGATOR_SEMIOTIC_H


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_library_unpack(_path_, _partition_, _division_, _space_)							\
															\
	nik_stringify(_path_/interface-structure/_partition_-_division_-_space_-semiotic.h)


#define nik_lens_unpack(_path_, _lens_, _partition_, _division_, _space_)						\
															\
	nik_stringify(_path_/lens-_lens_/interface-structure/_partition_-_division_-_space_-semiotic.h)


#define nik_branch_unpack(_path_, _lens_, _branch_, _partition_, _division_, _space_)					\
															\
	nik_stringify(_path_/lens-_lens_/branch-_branch_/interface-structure/_partition_-_division_-_space_-semiotic.h)


#define nik_module_unpack(_path_, _lens_, _branch_, _module_, _space_)							\
															\
	nik_stringify(path/lens-_lens_/branch-_branch_/interface-structure/module-_module_-_space_-semiotic.h)


/***********************************************************************************************************************/


#define nik_library_typedef(_partition_, _division_, _space_)								\
															\
	nik_stringify(../interface-structure/_partition_-_division_-_space_-semiotic.h)


#define nik_lens_typedef(_lens_, _partition_, _division_, _space_)							\
															\
	nik_stringify(../../lens-_lens_/interface-structure/_partition_-_division_-_space_-semiotic.h)


#define nik_branch_typedef(_lens_, _branch_, _partition_, _division_, _space_)						\
															\
	nik_stringify(../../../lens-_lens_/branch-_branch_/interface-structure/_partition_-_division_-_space_-semiotic.h)


#define nik_module_typedef(_lens_, _branch_, _module_, _space_)								\
															\
	nik_stringify(../../../../lens-_lens_/branch-_branch_/interface-structure/module-_module_-_space_-semiotic.h)


/***********************************************************************************************************************/


#define nik_library_import(_path_, _partition_, _division_, _space_)							\
															\
	nik_stringify(_path_/interface-structure/_partition_-_division_-_space_-media.h)


#define nik_lens_import(_path_, _lens_, _partition_, _division_, _space_)						\
															\
	nik_stringify(_path_/lens-_lens_/interface-structure/_partition_-_division_-_space_-media.h)


#define nik_branch_import(_path_, _lens_, _branch_, _partition_, _division_, _space_)					\
															\
	nik_stringify(_path_/lens-_lens_/branch-_branch_/interface-structure/_partition_-_division_-_space_-media.h)


#define nik_module_import(_path_, _lens_, _branch_, _module_, _space_)							\
															\
	nik_stringify(path/lens-_lens_/branch-_branch_/interface-structure/module-_module_-_space_-media.h)


/***********************************************************************************************************************/


#define nik_library_using(_partition_, _division_, _space_)								\
															\
	nik_stringify(../interface-structure/_partition_-_division_-_space_-media.h)


#define nik_lens_using(_lens_, _partition_, _division_, _space_)							\
															\
	nik_stringify(../../lens-_lens_/interface-structure/_partition_-_division_-_space_-media.h)


#define nik_branch_using(_lens_, _branch_, _partition_, _division_, _space_)						\
															\
	nik_stringify(../../../lens-_lens_/branch-_branch_/interface-structure/_partition_-_division_-_space_-media.h)


#define nik_module_using(_lens_, _branch_, _module_, _space_)								\
															\
	nik_stringify(../../../../lens-_lens_/branch-_branch_/interface-structure/module-_module_-_space_-media.h)


/***********************************************************************************************************************/


#define nik_library_source(_path_, _partition_, _division_, _permission_)						\
															\
	nik_stringify(_path_/interface-navigator/_partition_-_division_-_permission_.h)


#define nik_lens_source(_path_, _lens_, _partition_, _division_, _permission_)						\
															\
	nik_stringify(_path_/lens-_lens_/interface-navigator/_partition_-_division_-_permission_.h)


#define nik_branch_source(_path_, _lens_, _branch_, _partition_, _division_, _permission_)				\
															\
	nik_stringify(_path_/lens-_lens_/branch-_branch_/interface-navigator/_partition_-_division_-_permission_.h)


#define nik_module_source(_path_, _lens_, _branch_, _module_, _permission_)						\
															\
	nik_stringify(_path_/lens-_lens_/branch-_branch_/interface-navigator/module-_module_-_permission_.h)


/***********************************************************************************************************************/


namespace nik
{
	enum struct Permission : global_size_type
	{
		semiotic,
		media,

		dimension // filler
	};

	enum struct Model : global_size_type
	{
		nik,
		symbolic,
		numeric,
		literic,
		graphic,
		kinetic,
		phonetic,
		interic,

		dimension // filler
	};

	enum struct Partition : global_size_type
	{
		interface,
		perspective,
//		model,

		dimension // filler
	};

	enum struct Division : global_size_type
	{
		structure,
		navigator,
		identity,
		proximity,
		functor,
//		model,

		dimension // filler
	};

	enum struct Lens : global_size_type
	{
		symbolic,
		numeric,
		literic,
		graphic,
		kinetic,
		phonetic,
		interic,

		dimension // filler
	};

	enum struct Branch : global_size_type
	{

	// symbolic:

		calculus,
		scheme,
		hott,

	// numeric:

	// literic:

	// graphic:

	// kinetic:

	// phonetic:

	// interic:

		dimension // filler
	};

	enum struct Module : global_size_type
	{

	// calculus:

		function,
		pair,
		lambda,
		copair,
		boolean,
		list,
		colist,

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
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#endif
