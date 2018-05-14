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

		#define grammaric_Evaluator_import_expression()								\
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

		#define grammaric_Evaluator_import_variables()								\
															\
			using a = typename Evaluator::FS::a;								\
			using b = typename Evaluator::FS::b;								\
			using c = typename Evaluator::FS::c;								\
			using d = typename Evaluator::FS::d;								\
			using e = typename Evaluator::FS::e;								\
							        							\
			using f = typename Evaluator::FS::f;								\
			using g = typename Evaluator::FS::g;								\
			using h = typename Evaluator::FS::h;								\
			using i = typename Evaluator::FS::i;								\
			using j = typename Evaluator::FS::j;								\
							        							\
			using k = typename Evaluator::FS::k;								\
			using l = typename Evaluator::FS::l;								\
			using m = typename Evaluator::FS::m;								\
			using n = typename Evaluator::FS::n;								\
			using o = typename Evaluator::FS::o;								\
							        							\
			using p = typename Evaluator::FS::p;								\
			using q = typename Evaluator::FS::q;								\
			using r = typename Evaluator::FS::r;								\
			using s = typename Evaluator::FS::s;								\
			using t = typename Evaluator::FS::t;								\
							        							\
			using u = typename Evaluator::FS::u;								\
			using v = typename Evaluator::FS::v;								\
			using w = typename Evaluator::FS::w;								\
			using x = typename Evaluator::FS::x;								\
			using y = typename Evaluator::FS::y;								\
															\
			using z = typename Evaluator::FS::z;

		#define grammaric_Evaluator_import_define()								\
															\
			template<typename... E>										\
			using define_ = typename Evaluator::FS::template define_<E...>;

		#define grammaric_Evaluator_import_eval()								\
															\
			template<typename... E>										\
			using eval = typename Evaluator::FS::template eval<E...>;
	};

}}

#include"../grammaric/evaluator/structural/semiotic.h"
#include"../grammaric/evaluator/structural/media.h"

#include"../grammaric/evaluator/functional/semiotic.h"
#include"../grammaric/evaluator/functional/media.h"

#endif
