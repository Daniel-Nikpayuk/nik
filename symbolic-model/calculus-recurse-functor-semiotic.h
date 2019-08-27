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

								  template
								  <
									typename Type,

									bool Pred,
									typename Ante,
									typename Conse, Type Value
								  >
	using nik_safe(PREFIX, echo_if_then_else)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template echo_if_then_else
								  <
									Type,
									Pred,
									Ante,
									Conse, Value
								  >;

								  template
								  <
									typename Type,

									bool Pred,
									typename Conse, Type Value
								  >
	using nik_safe(PREFIX, echo_if_then)			= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template echo_if_then
								  <
									Type,
									Pred,
									Conse, Value
								  >;

//

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, Type... Values
								  >
	using nik_safe(PREFIX, builtin_list_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_list_if_then_else
								  <
									Type, ListType,
									Pred,
									Ante,
									Conse, Values...
								  >;

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Conse, Type... Values
								  >
	using nik_safe(PREFIX, builtin_list_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_list_if_then
								  <
									Type, ListType,
									Pred,
									Conse, Values...
								  >;

//

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename List, SIZE_TYPE Count, Type... Values
								  >
	using nik_safe(PREFIX, builtin_push_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_push_if_then_else
								  <
									Type, ListType,
									Pred,
									Ante,
									Conse, List, Count, Values...
								  >;

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Conse, typename List, SIZE_TYPE Count, Type... Values
								  >
	using nik_safe(PREFIX, builtin_push_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_push_if_then
								  <
									Type, ListType,
									Pred,
									Conse, List, Count, Values...
								  >;

//

								  template
								  <
									typename Kind, template<Kind...> class ListKind,

									bool Pred,
									typename Ante,
									typename Conse, typename Type, typename Op,
									typename List, SIZE_TYPE Count, Type... Values
								  >
	using nik_safe(PREFIX, builtin_map_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_map_if_then_else
								  <
									Kind, ListKind,
									Pred,
									Ante,
									Conse, Type, Op, List, Count, Values...
								  >;

								  template
								  <
									typename Kind, template<Kind...> class ListKind,

									bool Pred,
									typename Conse, typename Type, typename Op,
									typename List, SIZE_TYPE Count, Type... Values
								  >
	using nik_safe(PREFIX, builtin_map_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_map_if_then
								  <
									Kind, ListKind,
									Pred,
									Conse, Type, Op, List, Count, Values...
								  >;

//

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename Op, typename Cond, SIZE_TYPE Count,
									Type... Values
								  >
	using nik_safe(PREFIX, builtin_fold_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_fold_if_then_else
								  <
									Type, ListType,
									Pred,
									Ante,
									Conse, Op, Cond, Count, Values...
								  >;

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Conse, typename Op, typename Cond, SIZE_TYPE Count,
									Type... Values
								  >
	using nik_safe(PREFIX, builtin_fold_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_fold_if_then
								  <
									Type, ListType,
									Pred,
									Conse, Op, Cond, Count, Values...
								  >;

/***********************************************************************************************************************/

								  template
								  <
									bool Pred,
									typename Ante,
									typename Conse, typename Value
								  >
	using nik_safe(PREFIX, ping_if_then_else)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template ping_if_then_else
								  <
									Pred,
									Ante,
									Conse, Value
								  >;

								  template
								  <
									bool Pred,
									typename Conse, typename Value
								  >
	using nik_safe(PREFIX, ping_if_then)			= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template ping_if_then
								  <
									Pred,
									Conse, Value
								  >;

//

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename... Values
								  >
	using nik_safe(PREFIX, typename_list_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_list_if_then_else
								  <
									ListType,
									Pred,
									Ante,
									Conse, Values...
								  >;

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Conse, typename... Values
								  >
	using nik_safe(PREFIX, typename_list_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_list_if_then
								  <
									ListType,
									Pred,
									Conse, Values...
								  >;

//

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename List, SIZE_TYPE Count, typename... Values
								  >
	using nik_safe(PREFIX, typename_push_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_push_if_then_else
								  <
									ListType,
									Pred,
									Ante,
									Conse, List, Count, Values...
								  >;

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Conse, typename List, SIZE_TYPE Count, typename... Values
								  >
	using nik_safe(PREFIX, typename_push_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_push_if_then
								  <
									ListType,
									Pred,
									Conse, List, Count, Values...
								  >;

//

								  template
								  <
									template<typename...> class ListKind,

									bool Pred,
									typename Ante,
									typename Conse, typename Op,
									typename List, SIZE_TYPE Count, typename... Values
								  >
	using nik_safe(PREFIX, typename_map_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_map_if_then_else
								  <
									ListKind,
									Pred,
									Ante,
									Conse, Op, List, Count, Values...
								  >;

								  template
								  <
									template<typename...> class ListKind,

									bool Pred,
									typename Conse, typename Op,
									typename List, SIZE_TYPE Count, typename... Values
								  >
	using nik_safe(PREFIX, typename_map_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_map_if_then
								  <
									ListKind,
									Pred,
									Conse, Op, List, Count, Values...
								  >;

//

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename Op, typename Cond, SIZE_TYPE Count,
									typename... Values
								  >
	using nik_safe(PREFIX, typename_fold_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_fold_if_then_else
								  <
									ListType,
									Pred,
									Ante,
									Conse, Op, Cond, Count, Values...
								  >;

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Conse, typename Op, typename Cond, SIZE_TYPE Count,
									typename... Values
								  >
	using nik_safe(PREFIX, typename_fold_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_fold_if_then
								  <
									ListType,
									Pred,
									Conse, Op, Cond, Count, Values...
								  >;

//

#undef PREFIX

#include"undef-size_type.h"

