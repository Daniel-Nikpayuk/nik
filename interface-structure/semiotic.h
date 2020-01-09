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


	// constructors:


#define nik_begin_division(_division_, _partition_, _model_, _permission_)						\
															\
	template<typename size_type>											\
	struct division													\
	<														\
		nik::Division::_division_,										\
		nik::Partition::_partition_,										\
		nik::Model::_model_,											\
		nik::Permission::_permission_,										\
															\
		size_type												\
	>														\
	{														\
		template<typename Continuation>										\
		static constexpr bool result = Continuation::template result<true>;


#define nik_end_division(_division_, _partition_, _model_, _permission_)						\
															\
	};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_begin_module(_module_, _branch_, _lens_, _permission_)							\
															\
	template<typename size_type>											\
	struct module													\
	<														\
		nik::Module::_module_,											\
		nik::Branch::_branch_,											\
		nik::Lens::_lens_,											\
		nik::Permission::_permission_,										\
															\
		size_type												\
	>														\
	{														\
		template<typename Continuation>										\
		static constexpr bool result = Continuation::template result<true>;


#define nik_end_module(_module_, _branch_, _lens_, _permission_)							\
															\
	};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define nik_division(_division_, _partition_, _model_, _permission_)							\
															\
	nik::division													\
	<														\
		nik::Division::_division_,										\
		nik::Partition::_partition_,										\
		nik::Model::_model_,											\
		nik::Permission::_permission_,										\
															\
		SIZE_TYPE												\
	>


#define nik_module(_module_, _branch_, _lens_, _permission_)								\
															\
	nik::module													\
	<														\
		nik::Module::_module_,											\
		nik::Branch::_branch_,											\
		nik::Lens::_lens_,											\
		nik::Permission::_permission_,										\
															\
		SIZE_TYPE												\
	>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#include<stdio.h>

namespace nik
{
	using global_size_type					= signed long long;	// size_t;

	using voidptr						= void *;		// compliment to nullptr ( = 0 )

	struct global_filler					{ };			// keyword.

	using filler						= global_filler *;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	enum struct Permission	: global_size_type;

	enum struct Model	: global_size_type;
	enum struct Partition	: global_size_type;
	enum struct Division	: global_size_type;

	enum struct Lens	: global_size_type;
	enum struct Branch	: global_size_type;
	enum struct Module	: global_size_type;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template
	<
		Division	division_enum,
		Partition	partition_enum,
		Model		model_enum,
		Permission	permission_enum,

		typename	size_type = global_size_type

	> struct division
	{
		template<typename Continuation>
		static constexpr bool result = Continuation::template result<false>;
	};


/***********************************************************************************************************************/


	template<typename>
	struct memoized_division
	{
		template<typename Continuation>
		static constexpr bool result = Continuation::template result<false>;
	};

	template
	<
		Division	division_enum,
		Partition	partition_enum,
		Model		model_enum,
		Permission	permission_enum,

		typename	size_type

	> struct memoized_division<division<division_enum, partition_enum, model_enum, permission_enum, size_type>>
	{
		template<typename Continuation>
		static constexpr bool result = Continuation::template result<true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			division_enum, partition_enum, model_enum, permission_enum, size_type
		>;
	};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	template
	<
		Module		module_enum,
		Branch		branch_enum,
		Lens		lens_enum,
		Permission	permission_enum,

		typename	size_type = global_size_type

	> struct module
	{
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
		Module		module_enum,
		Branch		branch_enum,
		Lens		lens_enum,
		Permission	permission_enum,

		typename	size_type

	> struct memoized_module<module<module_enum, branch_enum, lens_enum, permission_enum, size_type>>
	{
		template<typename Continuation>
		static constexpr bool result = Continuation::template result<true>;

		template<typename Continuation>
		using induct = typename Continuation::template result
		<
			module_enum, branch_enum, lens_enum, permission_enum, size_type
		>;
	};
}

