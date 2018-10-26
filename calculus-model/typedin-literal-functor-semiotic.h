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

	#define PREFIX		typlif_

#else

	#define PREFIX

#endif

//

							  template
							  <
								nik_module(literal, typedin, calculus, semiotic)::register_type Value,
								typename List
							  >
	using nik_safe(PREFIX, cons)			= typename nik_module(literal, typedin, calculus, semiotic)::functor::template
							  cons<Value, List>;

							  template<typename List>
	using nik_safe(PREFIX, car)			= typename nik_module(literal, typedin, calculus, semiotic)::functor::template
							  car<List>;

							  template<typename List>
	using nik_safe(PREFIX, cdr)			= typename nik_module(literal, typedin, calculus, semiotic)::functor::template
							  cdr<List>;

							  template<typename List1, typename List2, typename... Lists>
	using nik_safe(PREFIX, catenate)		= typename nik_module(literal, typedin, calculus, semiotic)::functor::template
							  catenate<List1, List2, Lists...>;

							  template
							  <
								nik_module(literal, typedin, calculus, semiotic)::register_type Value,
								typename List
							  >
	using nik_safe(PREFIX, push)			= typename nik_module(literal, typedin, calculus, semiotic)::functor::template
							  push<Value, List>;

							  template<SIZE_TYPE Index, typename List>
	using nik_safe(PREFIX, at)			= typename nik_module(literal, typedin, calculus, semiotic)::functor::template
							  at<Index, List>;

							  template<typename List>
	using nik_safe(PREFIX, length)			= typename nik_module(literal, typedin, calculus, semiotic)::functor::template
							  length<List>;

//

							  template<typename... Exps>
	using nik_safe(PREFIX, apply)			= typename nik_module(literal, typedin, calculus, semiotic)::functor::template
							  apply<Exps...>;

//

#undef PREFIX

#include"undef-size_type.h"
