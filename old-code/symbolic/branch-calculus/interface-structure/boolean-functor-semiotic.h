/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	#define PREFIX		lifbof_

#else

	#define PREFIX

#endif

//

							  template<typename List>
	using nik_safe(PREFIX, length)			= typename nik_module(boolean, lift, symbolic, semiotic)::functor::template
							  length<List>;

							  template
							  <
								typename nik_module(boolean, lift, symbolic, semiotic)::register_type
								Value, typename List
							  >
	using nik_safe(PREFIX, cons)			= typename nik_module(boolean, lift, symbolic, semiotic)::functor::template
							  cons<Value, List>;

							  template
							  <
								typename nik_module(boolean, lift, symbolic, semiotic)::register_type
								Value, typename List
							  >
	using nik_safe(PREFIX, push)			= typename nik_module(boolean, lift, symbolic, semiotic)::functor::template
							  push<Value, List>;

							  template<typename List, SIZE_TYPE Index = 0>
	using nik_safe(PREFIX, car)			= typename nik_module(boolean, lift, symbolic, semiotic)::functor::template
							  car<List, Index>;

							  template<typename List, SIZE_TYPE Index = 0>
	using nik_safe(PREFIX, cdr)			= typename nik_module(boolean, lift, symbolic, semiotic)::functor::template
							  cdr<List, Index>;

//

							  template<typename Op, typename Bool0, typename Bool1, typename... Bools>
	using nik_safe(PREFIX, apply)			= typename nik_module(boolean, lift, symbolic, semiotic)::functor::template
							  apply<Op, Bool0, Bool1, Bools...>;

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
									typename Conse, typename List, Type... Values
								  >
	using nik_safe(PREFIX, builtin_grow_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_grow_if_then_else
								  <
									Type, ListType,
									Pred,
									Ante,
									Conse, List, Values...
								  >;

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Conse, typename List, Type... Values
								  >
	using nik_safe(PREFIX, builtin_grow_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_grow_if_then
								  <
									Type, ListType,
									Pred,
									Conse, List, Values...
								  >;

//

								  template
								  <
									typename Kind, template<Kind...> class ListKind,
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename Op, typename List, Type... Values
								  >
	using nik_safe(PREFIX, builtin_mutate_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_mutate_if_then_else
								  <
									Kind, ListKind,
									Type, ListType,
									Pred,
									Ante,
									Conse, Op, List, Values...
								  >;

								  template
								  <
									typename Kind, template<Kind...> class ListKind,
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Conse, typename Op, typename List, Type... Values
								  >
	using nik_safe(PREFIX, builtin_mutate_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_mutate_if_then
								  <
									Kind, ListKind,
									Type, ListType,
									Pred,
									Conse, Op, List, Values...
								  >;

//

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename Op_Cond, SIZE_TYPE Count, typename List,
									Type... Values
								  >
	using nik_safe(PREFIX, builtin_shrink_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_shrink_if_then_else
								  <
									Type, ListType,
									Pred,
									Ante,
									Conse, Op_Cond, Count, List, Values...
								  >;

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Conse, typename Op_Cond, SIZE_TYPE Count, typename List,
									Type... Values
								  >
	using nik_safe(PREFIX, builtin_shrink_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_shrink_if_then
								  <
									Type, ListType,
									Pred,
									Conse, Op_Cond, Count, List, Values...
								  >;

//

								  template
								  <
									typename Kind, template<Kind...> class ListKind,
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename Op_Cond, typename Side,
									SIZE_TYPE Count, typename List0, typename List1,
									Type... Values
								  >
	using nik_safe(PREFIX, builtin_split_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_split_if_then_else
								  <
									Kind, ListKind,
									Type, ListType,
									Pred,
									Ante,
									Conse, Op_Cond, Side, Count, List0, List1, Values...
								  >;

								  template
								  <
									typename Kind, template<Kind...> class ListKind,
									typename Type, template<Type...> class ListType,

									bool Pred,
									typename Conse, typename Op_Cond, typename Side,
									SIZE_TYPE Count, typename List0, typename List1,
									Type... Values
								  >
	using nik_safe(PREFIX, builtin_split_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_split_if_then
								  <
									Kind, ListKind,
									Type, ListType,
									Pred,
									Conse, Op_Cond, Side, Count, List0, List1, Values...
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
									typename Conse, typename List, typename... Values
								  >
	using nik_safe(PREFIX, typename_grow_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_grow_if_then_else
								  <
									ListType,
									Pred,
									Ante,
									Conse, List, Values...
								  >;

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Conse, typename List, typename... Values
								  >
	using nik_safe(PREFIX, typename_grow_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_grow_if_then
								  <
									ListType,
									Pred,
									Conse, List, Values...
								  >;

//

								  template
								  <
									template<typename...> class ListKind,
									template<typename...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename Op, typename List, typename... Values
								  >
	using nik_safe(PREFIX, typename_mutate_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_mutate_if_then_else
								  <
									ListKind,
									ListType,
									Pred,
									Ante,
									Conse, Op, List, Values...
								  >;

								  template
								  <
									template<typename...> class ListKind,
									template<typename...> class ListType,

									bool Pred,
									typename Conse, typename Op, typename List, typename... Values
								  >
	using nik_safe(PREFIX, typename_mutate_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_mutate_if_then
								  <
									ListKind,
									ListType,
									Pred,
									Conse, Op, List, Values...
								  >;

//

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename Op_Cond, SIZE_TYPE Count, typename List,
									typename... Values
								  >
	using nik_safe(PREFIX, typename_shrink_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_shrink_if_then_else
								  <
									ListType,
									Pred,
									Ante,
									Conse, Op_Cond, Count, List, Values...
								  >;

								  template
								  <
									template<typename...> class ListType,

									bool Pred,
									typename Conse, typename Op_Cond, SIZE_TYPE Count, typename List,
									typename... Values
								  >
	using nik_safe(PREFIX, typename_shrink_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_shrink_if_then
								  <
									ListType,
									Pred,
									Conse, Op_Cond, Count, List, Values...
								  >;

//

								  template
								  <
									template<typename...> class ListKind,
									template<typename...> class ListType,

									bool Pred,
									typename Ante,
									typename Conse, typename Op_Cond, typename Side,
									SIZE_TYPE Count, typename List0, typename List1,
									typename... Values
								  >
	using nik_safe(PREFIX, typename_split_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_split_if_then_else
								  <
									ListKind,
									ListType,
									Pred,
									Ante,
									Conse, Op_Cond, Side, Count, List0, List1, Values...
								  >;

								  template
								  <
									template<typename...> class ListKind,
									template<typename...> class ListType,

									bool Pred,
									typename Conse, typename Op_Cond, typename Side,
									SIZE_TYPE Count, typename List0, typename List1,
									typename... Values
								  >
	using nik_safe(PREFIX, typename_split_if_then)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_split_if_then
								  <
									ListKind,
									ListType,
									Pred,
									Conse, Op_Cond, Side, Count, List0, List1, Values...
								  >;

//


#undef PREFIX

#include"undef-size_type.h"

