/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	#define PREFIX		calref_

#else

	#define PREFIX

#endif

//
							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, cons)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  cons<Type, Value, List>;

							  template<typename Type, typename List, Type... Values>
	using nik_safe(PREFIX, multicons)		= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  multicons<Type, List, Values...>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, car)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  car<Type, List>;

							  template<typename Type, typename List, SIZE_TYPE Index = 0>
	using nik_safe(PREFIX, multicar)		= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  multicar<Type, List, Index>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, cdr)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  cdr<Type, List>;

							  template<typename Type, typename List, SIZE_TYPE Index = 0>
	using nik_safe(PREFIX, multicdr)		= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  multicdr<Type, List, Index>;

							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, push)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  push<Type, Value, List>;

							  template<typename Type, typename List, Type... Values>
	using nik_safe(PREFIX, multipush)		= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  multipush<Type, List, Values...>;

							  template<typename Type, typename List1, typename List2>
	using nik_safe(PREFIX, catenate)		= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  catenate<Type, List1, List2>;

							  template<typename Type, typename List1, Type Value, typename List2>
	using nik_safe(PREFIX, unite)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  unite<Type, List1, Value, List2>;

							  template<typename Type, typename List1, typename List2, Type... Values>
	using nik_safe(PREFIX, multiunite)		= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  multiunite<Type, List1, List2, Values...>;

/*
							  template<typename Type, typename List1, typename List2, typename... Lists>
	using nik_safe(PREFIX, multicatenate)		= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  multicatenate<Type, List1, List2, Lists...>;
*/

							  template<typename Type, typename List>
	using nik_safe(PREFIX, length)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  length<Type, List>;

/*
							  template<typename Type, typename Op, typename List>
	using nik_safe(PREFIX, map)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  map<Type, Op, List>;
*/

							  template
							  <
								typename Kind, template<Kind...> class ListKind,
								typename Type, typename Op, typename List1, typename List2
							  >
	using nik_safe(PREFIX, apply)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  apply<Kind, ListKind, Type, Op, List1, List2>;

							  template<typename Type, typename Op, typename List, Type seed>
	using nik_safe(PREFIX, fold)			= typename nik_branch(calculus, symbolic, semiotic)::functor::template
							  fold<Type, Op, List, seed>;

//

/*
							  template
							  <
								typename Kind, typename Type,
								template<Type...> class eager, Type... Params
							  >
	using nik_safe(PREFIX, delay)			= typename nik_branch(typed, calculus, semiotic)::functor::template
							  delay<Kind, Type, eager, Params...>;

							  template<typename Exp>
	using nik_safe(PREFIX, force)			= typename nik_branch(typed, calculus, semiotic)::functor::template
							  force<Exp>;
*/


//

#undef PREFIX

#include"undef-size_type.h"

