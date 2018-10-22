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

	#define PREFIX		perbuf_

#else

	#define PREFIX

#endif

//

							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, cons)			= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  cons<Type, Value, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, car)			= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  car<Type, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, cdr)			= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  cdr<Type, List>;

							  template<typename Type, typename List1, typename List2, typename... Lists>
	using nik_safe(PREFIX, catenate)		= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  catenate<Type, List1, List2, Lists...>;

							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, push)			= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  push<Type, Value, List>;

							  template<typename Type, SIZE_TYPE Index, typename List>
	using nik_safe(PREFIX, at)			= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  at<Type, Index, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, length)			= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  length<Type, List>;

//

							  template<typename RegType>
	using nik_safe(PREFIX, limits)			= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  limits<RegType>;

//

							  template<SIZE_TYPE N>
	using nik_safe(PREFIX, unsigned_type)		= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  unsigned_type<N>;

							  template<SIZE_TYPE N>
	using nik_safe(PREFIX, signed_type)		= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  signed_type<N>;


#define ONE 1

							  template<SIZE_TYPE N>
	using nik_safe(PREFIX, half_type)		= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  unsigned_type<(N >> ONE)>;

#undef ONE

//

							  template<typename Type, typename... Exps>
	using nik_safe(PREFIX, apply)			= typename nik_branch(builtin, calculus, semiotic)::functor::template
							  apply<Type, Exps...>;

//

#undef PREFIX

#include"undef-size_type.h"

