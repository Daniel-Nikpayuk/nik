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
									bool Pred,
									template<typename> class Ante, typename Value,
									typename Conse
								  >
	using nik_safe(PREFIX, head_if_then_else)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template head_if_then_else<Pred, Ante, Value, Conse>;

								  template
								  <
									bool Pred,
									typename Ante,
									template<typename, typename...> class Conse,
										typename Value, typename... Values
								  >
	using nik_safe(PREFIX, tail_if_then_else)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template tail_if_then_else<Pred, Ante, Conse, Value, Values...>;

								  template
								  <
									bool Pred,
									template<typename> class Ante, typename Ante_Value,
									template<typename, typename...> class Conse,
										typename Value, typename... Values
								  >
	using nik_safe(PREFIX, handle_if_then_else)		= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template handle_if_then_else<Pred, Ante, Ante_Value,
												Conse, Value, Values...>;

//

								  template
								  <
									typename Type,

									bool Pred,

									typename Ante_Cont, Type Value,

									typename Conse_Cont, typename Cond, typename Op, SIZE_TYPE Index,

									Type... Values
								  >
	using nik_safe(PREFIX, builtin_break_fold_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_break_fold_if_then_else
								  <
									Type, Pred,
									Ante_Cont, Value,
									Conse_Cont, Cond, Op, Index,
									Values...
								  >;

								  template
								  <
									bool Pred,

									typename Value,

									typename Conse_Cont, template<typename> class Cond,
										template<typename, typename> class Op, SIZE_TYPE Index,

									typename... Values
								  >
	using nik_safe(PREFIX, typename_break_fold_if_then_else)= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_break_fold_if_then_else
								  <
									Pred,
									Value,
									Conse_Cont, Cond, Op, Index,
									Values...
								  >;

//

								  template
								  <
									typename Type, template<Type...> class ListType,

									bool Pred,

									typename Ante_Cont, Type Value,

									typename Conse_Cont, typename Cond, SIZE_TYPE Index,

									Type... Values
								  >
	using nik_safe(PREFIX, builtin_find_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template builtin_find_if_then_else
								  <
									Type, ListType, Pred,
									Ante_Cont, Value,
									Conse_Cont, Cond, Index,
									Values...
								  >;

								  template
								  <
									template<typename...> class ListType,

									bool Pred,

									typename Ante_Cont, typename Value,

									typename Conse_Cont, template<typename> class Cond, SIZE_TYPE Index,

									typename... Values
								  >
	using nik_safe(PREFIX, typename_find_if_then_else)	= typename nik_module(recurse, calculus, symbolic, semiotic)::functor::
								  template typename_find_if_then_else
								  <
									ListType, Pred,
									Ante_Cont, Value,
									Conse_Cont, Cond, Index,
									Values...
								  >;

//

#undef PREFIX

#include"undef-size_type.h"

