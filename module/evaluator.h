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

#ifndef GRAMMARIC_EVALUATOR_H
#define GRAMMARIC_EVALUATOR_H

#include"environment.h"

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct EvaluatorModule
	{
		using SS = module
		<
			Module::	evaluator,
			Orientation::	structural,
			Interface::	semiotic,

			SizeType
		>;

		#define evaluator_import_expression()									\
															\
			template<typename... Expressions>								\
			using expression = typename Evaluator::SS::template expression<Expressions...>;			\
															\
			using null_expression = typename Evaluator::SS::null_expression;

/***********************************************************************************************************************/

		using FS = module
		<
			Module::	evaluator,
			Orientation::	functional,
			Interface::	semiotic,

			SizeType
		>;

		#define evaluator_import_EVAL()										\
															\
			template<typename Expression, typename Environment>						\
			using EVAL = typename Evaluator::FS::template EVAL<Expression, Environment>;
	};

}}

#include"../grammaric/evaluator/structural/semiotic.h"
#include"../grammaric/evaluator/structural/media.h"

#include"../grammaric/evaluator/functional/semiotic.h"
#include"../grammaric/evaluator/functional/media.h"

#endif
