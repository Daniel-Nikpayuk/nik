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

#ifndef GRAMMARIC_TUPLE_H
#define GRAMMARIC_TUPLE_H

#include"constant.h"

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct TupleModule
	{
		using SS = module
		<
			Module::	tuple,
			Orientation::	structural,
			Interface::	semiotic,

			SizeType
		>;

		#define grammaric_Tuple_import_tuple()									\
															\
			template<typename... Expressions>								\
			using tuple = typename Tuple::SS::template tuple<Expressions...>;				\
															\
			using null_tuple = typename Tuple::SS::null_tuple;

		using FS = module
		<
			Module::	tuple,
			Orientation::	functional,
			Interface::	semiotic,

			SizeType
		>;

		#define grammaric_Tuple_import_car()									\
															\
			template<typename E1>										\
			using car = typename Tuple::FS::template car<E1>;

		#define grammaric_Tuple_import_cdr()									\
															\
			template<typename E1>										\
			using cdr = typename Tuple::FS::template cdr<E1>;

/***********************************************************************************************************************/

		#define grammaric_Tuple_import_length()									\
															\
			template<typename E1>										\
			using length = typename Tuple::FS::template length<E1>;

/***********************************************************************************************************************/

		#define grammaric_Tuple_import_cons()									\
															\
			template<typename E1, typename E2>								\
			using cons = typename Tuple::FS::template cons<E1, E2>;

		#define grammaric_Tuple_import_push()									\
															\
			template<typename E1, typename E2>								\
			using push = typename Tuple::FS::template push<E1, E2>;

		#define grammaric_Tuple_import_catenate()								\
															\
			template<typename E1, typename E2, typename... E>						\
			using catenate = typename Tuple::FS::template catenate<E1, E2, E...>;

/***********************************************************************************************************************/

		#define grammaric_Tuple_import_parameter()								\
															\
			template<typename Type, Type... Values>								\
			using parameter = typename Tuple::FS::template parameter<Type, Values...>;
	};

}}

#include"../grammaric/tuple/structural/semiotic.h"
#include"../grammaric/tuple/structural/media.h"

#include"../grammaric/tuple/functional/semiotic.h"
#include"../grammaric/tuple/functional/media.h"

#endif
