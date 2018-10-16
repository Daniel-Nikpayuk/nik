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

namespace nik		{
namespace grammaric	{

	template<typename SizeType>
	struct module<Module::evaluator, Orientation::functional, Interface::semiotic, SizeType>
	{
		typedef SizeType size_type;

		nik_using(grammaric, Constant)
		nik_using(grammaric, Branch)
		nik_using(grammaric, Environment)
		nik_using(grammaric, Evaluator)

		#include"alias/semiotic.hpp"

		//

		#include"variable/semiotic.hpp"
		#include"primitive/semiotic.hpp"

		#include"is_self_evaluating/semiotic.hpp"
		#include"is_variable/semiotic.hpp"

		template<typename, typename Environment = null_environment> struct eval;

		#include"define/semiotic.hpp"
		#include"if/semiotic.hpp"
//		#include"begin/semiotic.hpp"
//		#include"execute/semiotic.hpp"
//		#include"apply/semiotic.hpp"

		#include"eval/semiotic.hpp"

//		#include"define/semiotic.hpp"
	};

}}

