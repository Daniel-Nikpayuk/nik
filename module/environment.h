/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#include"tuple.h"
#include"branch.h"

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct environment
	{
		using SS = module
		<
			Module::	environment,
			Orientation::	structural,
			Interface::	semiotic,

			SizeType
		>;

		#define environment_import_binding()									\
															\
			template<typename Variable, typename Type, Type... Value>					\
			using binding = typename Environment::SS::template environment<Variable, Type, Value...>;	\
															\
			using null_binding = typename Environment::SS::null_binding;

/***********************************************************************************************************************/

		#define environment_import_variables()									\
															\
			template<typename... Variables>									\
			using variables = typename Environment::SS::template variables<Variables...>;			\
															\
			using null_variables = typename Environment::SS::null_variables;

/***********************************************************************************************************************/

		#define environment_import_frame()									\
															\
			template<typename... Bindings>									\
			using frame = typename Environment::SS::template frame<Bindings...>;				\
															\
			using null_frame = typename Environment::SS::null_frame;

/***********************************************************************************************************************/

		#define environment_import_environment()								\
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

		#define environment_import_extend()									\
															\
			template<typename Environment, typename Variables, typename Constants>				\
			using extend = typename Environment::FS::template extend<Environment, Variables, Constants>;
	};

}}

#include"../grammaric/environment/structural/semiotic.h"
#include"../grammaric/environment/structural/media.h"

#include"../grammaric/environment/functional/semiotic.h"
#include"../grammaric/environment/functional/media.h"

#endif
