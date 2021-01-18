/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

/*
	Development status: experimental.

	Numeric ranges are an ideal abstraction of iterator positions, regardless of iterator type.
	This module is as of yet experimental as I haven't settled on how best to extend these iterators
	into more complex recursive structures. As such, I also haven't settled on a natural algebra
	for such ranges.

	Semantic note:

	The operators in this module act on abstract iterator types.

	On the one hand, iterators only exist to navigate specific data structures, which means by extension
	the operators in this module are effectively acting on data structures instead of iterators.
	This raises the question: Where do we categorize these operators, with structures or their navigators?

	The specification I have taken is that we categorize such operators with the navigators of structures.
	The idea is these operators are acting on iterators: It just so happens that these iterators maintain
	relationships with each other that coincide with particular data structures.
*/

namespace nik
{
	template<typename SizeType>
	struct space<Branch::grammaric, Module::range, Permission::semiotic, SizeType>
	{
		using size_type		= SizeType;

		//

		#include"interface/navigator/semiotic.hpp"

		#include"interface/structure/semiotic.hpp"

		//

//		#include"perspective/generic/semiotic.hpp"
//		#include"perspective/identity/semiotic.hpp"
//		#include"perspective/proximity/semiotic.hpp"
//		#include"perspective/functor/semiotic.hpp"
//		#include"perspective/printer/semiotic.hpp"
	};
}

