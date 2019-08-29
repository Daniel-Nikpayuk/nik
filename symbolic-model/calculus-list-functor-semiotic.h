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

	using local_callif_ch_echo			= typename nik_module(kernel, core, symbolic, semiotic)::functor::
							  ch_echo;

	using local_callif_ch_builtin_list		= typename nik_module(list, calculus, symbolic, semiotic)::functor::
							  ch_builtin_list;

//

							  template
							  <
								typename Type, typename List,
								typename Continuation = local_callif_ch_echo
							  >
	using nik_safe(PREFIX, builtin_length)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_length<Type, List, Continuation>;

//

							  template
							  <
								typename Type, Type Value, typename List,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_cons)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_cons<Type, Value, List, Continuation>;

							  template
							  <
								typename Type, typename List, Type... Values
							  >
	using nik_safe(PREFIX, builtin_multicons)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_multicons<Type, List, local_callif_ch_builtin_list, Values...>;

//

							  template
							  <
								typename Type, Type Value, typename List,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_push)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_push<Type, Value, List, Continuation>;

							  template
							  <
								typename Type, typename List, Type... Values
							  >
	using nik_safe(PREFIX, builtin_multipush)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_multipush<Type, List, local_callif_ch_builtin_list, Values...>;

//

							  template
							  <
								typename Type, typename List1, typename List2,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_catenate)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_catenate<Type, List1, List2, Continuation>;

//

							  template
							  <
								typename Kind, template<Kind...> class ListKind,
								typename Type, typename Op, typename List,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_map)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_map<Kind, ListKind, Type, Op, List, Continuation>;

//

							  template
							  <
								typename Type, template<Type...> class ListType, typename List,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_relist)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_relist<Type, ListType, List, Continuation>;

//

							  template
							  <
								typename Kind, template<Kind...> class ListKind,
								typename Type, typename Op, typename List1, typename List2,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_zip)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_zip<Kind, ListKind, Type, Op, List1, List2, Continuation>;

//

							  template
							  <
								typename Type, typename List,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_cdr)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_cdr<Type, List, Continuation>;

							  template
							  <
								typename Type, typename List, SIZE_TYPE Index = 0,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_multicdr)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_multicdr<Type, List, Index, Continuation>;

//

							  template
							  <
								typename Type, typename List,
								typename Continuation = local_callif_ch_echo
							  >
	using nik_safe(PREFIX, builtin_car)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_car<Type, List, Continuation>;

							  template
							  <
								typename Type, typename List, SIZE_TYPE Index = 0,
								typename Continuation = local_callif_ch_echo
							  >
	using nik_safe(PREFIX, builtin_multicar)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_multicar<Type, List, Index, Continuation>;

//

							  template<typename Type, typename List>
	using nik_safe(PREFIX, builtin_null)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_null<Type, List>;

//

							  template
							  <
								typename Type, typename List1, Type Value, typename List2,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_unite)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_unite<Type, List1, Value, List2, Continuation>;

							  template
							  <
								typename Type, typename List1, typename List2, Type... Values
							  >
	using nik_safe(PREFIX, builtin_multiunite)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_multiunite<Type, List1, List2, local_callif_ch_builtin_list, Values...>;

//

							  template
							  <
								typename Type, typename List
							  >
	using nik_safe(PREFIX, builtin_reverse)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_reverse<Type, List>;

//

							  template
							  <
								typename Type, typename Op, Type Result, typename List,
								typename Continuation = local_callif_ch_echo
							  >
	using nik_safe(PREFIX, builtin_fold)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_fold<Type, Op, Result, List, Continuation>;

							  template
							  <
								typename Type, typename Op, typename Cond, Type Result, typename List,
								typename Continuation = local_callif_ch_echo
							  >
	using nik_safe(PREFIX, builtin_break_fold)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_break_fold<Type, Op, Cond, Result, List, Continuation>;

//

							  template
							  <
								typename Type, typename Cond, typename List,
								typename Continuation = local_callif_ch_builtin_list
							  >
	using nik_safe(PREFIX, builtin_find)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_find<Type, Cond, List, Continuation>;

//

							  template<typename Type, typename Cond, typename List, typename Continuation>
	using nik_safe(PREFIX, builtin_split)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_split<Type, Cond, List, Continuation>;


/***********************************************************************************************************************/


	using local_callif_ch_typename_list		= typename nik_module(list, calculus, symbolic, semiotic)::functor::
							  ch_typename_list;

//

							  template
							  <
								typename List,
								typename Continuation = local_callif_ch_echo
							  >
	using nik_safe(PREFIX, typename_length)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_length<List, Continuation>;

//

							  template
							  <
								typename Value, typename List,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_cons)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_cons<Value, List, Continuation>;

							  template
							  <
								typename List, typename... Values
							  >
	using nik_safe(PREFIX, typename_multicons)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_multicons<List, local_callif_ch_typename_list, Values...>;

//

							  template
							  <
								typename Value, typename List,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_push)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_push<Value, List, Continuation>;

							  template
							  <
								typename List, typename... Values
							  >
	using nik_safe(PREFIX, typename_multipush)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_multipush<List, local_callif_ch_typename_list, Values...>;

//

							  template
							  <
								typename List1, typename List2,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_catenate)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_catenate<List1, List2, Continuation>;

//

							  template
							  <
								template<typename...> class ListKind,
								typename Op, typename List,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_map)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_map<ListKind, Op, List, Continuation>;

//

							  template
							  <
								template<typename...> class ListType, typename List,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_relist)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_relist<ListType, List, Continuation>;

//

							  template
							  <
								template<typename...> class ListKind,
								typename Op, typename List1, typename List2,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_zip)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_zip<ListKind, Op, List1, List2, Continuation>;

//

							  template
							  <
								typename List,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_cdr)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_cdr<List, Continuation>;

							  template
							  <
								typename List, SIZE_TYPE Index = 0,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_multicdr)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_multicdr<List, Index, Continuation>;

//

							  template
							  <
								typename List
							  >
	using nik_safe(PREFIX, typename_car)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_car<List>;

							  template
							  <
								typename List, SIZE_TYPE Index = 0
							  >
	using nik_safe(PREFIX, typename_multicar)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_multicar<List, Index>;

//

							  template<typename List>
	using nik_safe(PREFIX, typename_null)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_null<List>;

//

							  template
							  <
								typename List1, typename Value, typename List2,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_unite)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_unite<List1, Value, List2, Continuation>;

							  template
							  <
								typename List1, typename List2, typename... Values
							  >
	using nik_safe(PREFIX, typename_multiunite)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_multiunite<List1, List2, local_callif_ch_typename_list, Values...>;

//

							  template
							  <
								typename List
							  >
	using nik_safe(PREFIX, typename_reverse)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_reverse<List>;

//

							  template
							  <
								typename Op, typename Result, typename List
							  >
	using nik_safe(PREFIX, typename_fold)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_fold<Op, Result, List>;

							  template
							  <
								typename Op, typename Cond, typename Result, typename List
							  >
	using nik_safe(PREFIX, typename_break_fold)	= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_break_fold<Op, Cond, Result, List>;

//

							  template
							  <
								typename Cond, typename List,
								typename Continuation = local_callif_ch_typename_list
							  >
	using nik_safe(PREFIX, typename_find)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_find<Cond, List, Continuation>;

//

							  template<typename Cond, typename List, typename Continuation>
	using nik_safe(PREFIX, typename_split)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  typename_split<Cond, List, Continuation>;

//

#undef PREFIX

#include"undef-size_type.h"

