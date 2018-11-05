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

#include"define-size_type.h"

#ifdef safe_name

	#define PREFIX		untacf_

#else

	#define PREFIX

#endif

//

							  template<typename Exp, typename List>
	using nik_safe(PREFIX, cons)			= typename nik_module(active, untyped, calculus, semiotic)::functor::template
							  cons<Exp, List>;

							  template<typename List, SIZE_TYPE Index = 0>
	using nik_safe(PREFIX, car)			= typename nik_module(active, untyped, calculus, semiotic)::functor::template
							  car<List, Index>;

							  template<typename List, SIZE_TYPE Index = 0>
	using nik_safe(PREFIX, cdr)			= typename nik_module(active, untyped, calculus, semiotic)::functor::template
							  cdr<List, Index>;

							  template<typename List1, typename List2, typename... Lists>
	using nik_safe(PREFIX, catenate)		= typename nik_module(active, untyped, calculus, semiotic)::functor::template
							  catenate<List1, List2, Lists...>;

							  template<typename Exp, typename List>
	using nik_safe(PREFIX, push)			= typename nik_module(active, untyped, calculus, semiotic)::functor::template
							  push<Exp, List>;

							  template<typename List>
	using nik_safe(PREFIX, length)			= typename nik_module(active, untyped, calculus, semiotic)::functor::template
							  length<List>;

//

							  template<typename... Exps>
	using nik_safe(PREFIX, evaluate)		= typename nik_module(active, untyped, calculus, semiotic)::functor::template
							  evaluate<Exps...>;

//

#undef PREFIX

#include"undef-size_type.h"

