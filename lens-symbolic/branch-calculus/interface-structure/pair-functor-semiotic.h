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

	#define PREFIX		calpaf_

#else

	#define PREFIX

#endif

//

	using nik_safe(PREFIX, ch_builtin_builtin_cons)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_builtin_builtin_cons;

	using nik_safe(PREFIX, ch_builtin_typename_cons)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_builtin_typename_cons;

	using nik_safe(PREFIX, ch_typename_builtin_cons)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_typename_builtin_cons;

	using nik_safe(PREFIX, ch_typename_typename_cons)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_typename_typename_cons;

//

								  template<typename Continuation>
	using nik_safe(PREFIX, cp_builtin_builtin_car)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template cp_builtin_builtin_car<Continuation>;

								  template
								  <
									typename Pair,

									typename Continuation =
									typename nik_module(kernel, core, symbolic, semiotic)::
									functor::ch_echo
								  >
	using nik_safe(PREFIX, builtin_builtin_car)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template builtin_builtin_car<Pair, Continuation>;

//

								  template<typename Continuation>
	using nik_safe(PREFIX, cp_builtin_typename_car)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template cp_builtin_typename_car<Continuation>;

								  template
								  <
									typename Pair,

									typename Continuation =
									typename nik_module(kernel, core, symbolic, semiotic)::
									functor::ch_echo
								  >
	using nik_safe(PREFIX, builtin_typename_car)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template builtin_typename_car<Pair, Continuation>;

//

	using nik_safe(PREFIX, ch_typename_builtin_car)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_typename_builtin_car;

								  template<typename Pair>
	using nik_safe(PREFIX, typename_builtin_car)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template typename_builtin_car<Pair>;

//

	using nik_safe(PREFIX, ch_typename_typename_car)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_typename_typename_car;

								  template<typename Pair>
	using nik_safe(PREFIX, typename_typename_car)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template typename_typename_car<Pair>;

//

								  template<typename Continuation>
	using nik_safe(PREFIX, cp_builtin_builtin_cdr)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template cp_builtin_builtin_cdr<Continuation>;

								  template
								  <
									typename Pair,

									typename Continuation =
									typename nik_module(kernel, core, symbolic, semiotic)::
									functor::ch_echo
								  >
	using nik_safe(PREFIX, builtin_builtin_cdr)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template builtin_builtin_cdr<TypeX, TypeY, Pair, Continuation>;

//

	using nik_safe(PREFIX, ch_builtin_typename_cdr)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_builtin_typename_cdr;

								  template<typename Pair>
	using nik_safe(PREFIX, builtin_typename_cdr)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template builtin_typename_cdr<Pair>;

//

								  template<typename Continuation>
	using nik_safe(PREFIX, cp_typename_builtin_cdr)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template cp_typename_builtin_cdr<Continuation>;

								  template
								  <
									typename Pair,

									typename Continuation =
									typename nik_module(kernel, core, symbolic, semiotic)::
									functor::ch_echo
								  >
	using nik_safe(PREFIX, typename_builtin_cdr)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template typename_builtin_cdr<Pair, Continuation>;

//

	using nik_safe(PREFIX, ch_typename_typename_cdr)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_typename_typename_cdr;

								  template<typename Pair>
	using nik_safe(PREFIX, typename_typename_cdr)		= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template typename_typename_cdr<Pair>;

//

	using nik_safe(PREFIX, ch_builtin_builtin_left_type)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_builtin_builtin_left_type;

								  template<typename Pair>
	using nik_safe(PREFIX, builtin_builtin_left_type)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template builtin_builtin_left_type<Pair>;

//

	using nik_safe(PREFIX, ch_builtin_typename_left_type)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_builtin_typename_left_type;

								  template<typename Pair>
	using nik_safe(PREFIX, builtin_typename_left_type)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template builtin_typename_left_type<Pair>;

//

	using nik_safe(PREFIX, ch_builtin_builtin_right_type)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_builtin_builtin_right_type;

								  template<typename Pair>
	using nik_safe(PREFIX, builtin_builtin_right_type)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template builtin_builtin_right_type<Pair>;

//

	using nik_safe(PREFIX, ch_builtin_typename_right_type)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  ch_builtin_typename_right_type;

								  template<typename Pair>
	using nik_safe(PREFIX, builtin_typename_right_type)	= typename nik_module(pair, calculus, symbolic, semiotic)::functor::
								  template builtin_typename_right_type<Pair>;

//

#undef PREFIX

#include"undef-size_type.h"

