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

	#define PREFIX		callif_

#else

	#define PREFIX

#endif

//

							  template
							  <
								typename Type, typename List,

								typename Continuation =
								typename nik_module(kernel, core, symbolic, semiotic)::
								functor::ch_echo
							  >
	using nik_safe(PREFIX, builtin_length)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_length<Type, List, Continuation>;

//

							  template
							  <
								typename Type, Type Value, typename List,

								typename Continuation =
								typename nik_module(list, calculus, symbolic, semiotic)::
								functor::ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_cons)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_cons<Type, Value, List, Continuation>;

							  template
							  <
								typename Type, Type Value, typename List,

								typename Continuation =
								typename nik_module(list, calculus, symbolic, semiotic)::
								functor::ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_push)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_push<Type, Value, List, Continuation>;

//

							  template
							  <
								typename Type, typename List1, typename List2,

								typename Continuation =
								typename nik_module(list, calculus, symbolic, semiotic)::
								functor::ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_catenate)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_catenate<Type, List1, List2, Continuation>;

//

							  template
							  <
								typename Type, typename List, SIZE_TYPE Index = 0,

								typename Continuation =
								typename nik_module(kernel, core, symbolic, semiotic)::
								functor::ch_echo
							  >
	using nik_safe(PREFIX, builtin_car)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_car<Type, List, Index, Continuation>;

							  template
							  <
								typename Type, typename List, SIZE_TYPE Index = 0,

								typename Continuation =
								typename nik_module(list, calculus, symbolic, semiotic)::
								functor::ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_cdr)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_cdr<Type, List, Index, Continuation>;

//

							  template<typename Type, typename List>
	using nik_safe(PREFIX, builtin_null)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_null<Type, List>;

//

							  template
							  <
								typename Type, typename List1, Type Value, typename List2,

								typename Continuation =
								typename nik_module(list, calculus, symbolic, semiotic)::
								functor::ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_unite)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_unite<Type, List1, Value, List2, Continuation>;

//

							  template<typename Type, typename List>
	using nik_safe(PREFIX, builtin_reverse)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_reverse<Type, List>;

//

							  template
							  <
								typename Type, typename Pred, typename List,

								typename Continuation =
								typename nik_module(list, calculus, symbolic, semiotic)::
								functor::ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_find)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_find<Type, Pred, List, Continuation>;

//

/*
							  template<template<typename> class Pred, typename Maybe, typename List>
	using nik_safe(PREFIX, typename_find)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_find<Pred, Maybe, List>;
*/

#undef PREFIX

#include"undef-size_type.h"

