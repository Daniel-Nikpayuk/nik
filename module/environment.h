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

#ifndef GRAMMARIC_ENVIRONMENT_H
#define GRAMMARIC_ENVIRONMENT_H

#include"branch.h"
#include"tuple.h"

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct EnvironmentModule
	{
		using SS = module
		<
			Module::	environment,
			Orientation::	structural,
			Interface::	semiotic,

			SizeType
		>;

		#define grammaric_Environment_import_binding()								\
															\
			template<typename Variable, typename Value>							\
			using binding = typename Environment::SS::template binding<Variable, Value>;			\
															\
			using null_binding = typename Environment::SS::null_binding;

/***********************************************************************************************************************/

		#define grammaric_Environment_import_storage()								\
															\
			template<typename... Variables>									\
			using storage = typename Environment::SS::template storage<Variables...>;			\
															\
			using null_storage = typename Environment::SS::null_storage;

/***********************************************************************************************************************/

		#define grammaric_Environment_import_frame()								\
															\
			template<typename... Bindings>									\
			using frame = typename Environment::SS::template frame<Bindings...>;				\
															\
			using null_frame = typename Environment::SS::null_frame;

/***********************************************************************************************************************/

		#define grammaric_Environment_import_environment()							\
															\
			template<typename... Frames>									\
			using environment = typename Environment::SS::template environment<Frames...>;			\
															\
			using null_environment = typename Environment::SS::null_environment;

		using FS = module
		<
			Module::	environment,
			Orientation::	functional,
			Interface::	semiotic,

			SizeType
		>;

		#define grammaric_Environment_import_find()								\
															\
			template<typename Frame, typename variable>							\
			using find = typename Environment::FS::template find<Frame, variable>;

		#define grammaric_Environment_import_lookup()								\
															\
			template<typename Env, typename variable>							\
			using lookup = typename Environment::FS::template lookup<Env, variable>;

/***********************************************************************************************************************/

		#define grammaric_Environment_import_add()								\
															\
			template<typename Binding, typename Frame>							\
			using add = typename Environment::FS::template add<Binding, Frame>;

		#define grammaric_Environment_import_make()								\
															\
			template<typename Variables, typename Constants>						\
			using make = typename Environment::FS::template make<Variables, Constants>;

		#define grammaric_Environment_import_extend()								\
															\
			template<typename Env, typename Variables, typename Constants>					\
			using extend = typename Environment::FS::template extend<Env, Variables, Constants>;
	};

}}

#include"../grammaric/environment/structural/semiotic.h"
#include"../grammaric/environment/structural/media.h"

#include"../grammaric/environment/functional/semiotic.h"
#include"../grammaric/environment/functional/media.h"

#endif
