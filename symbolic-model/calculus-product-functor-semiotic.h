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

	#define PREFIX		calprf_

#else

	#define PREFIX

#endif

//

	using nik_safe(PREFIX, cp_echo_echo_cons)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  cp_echo_echo_cons;

	using nik_safe(PREFIX, cp_echo_ping_cons)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  cp_echo_ping_cons;

	using nik_safe(PREFIX, cp_ping_echo_cons)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  cp_ping_echo_cons;

	using nik_safe(PREFIX, cp_ping_ping_cons)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  cp_ping_ping_cons;

//

								  template<typename Continuation>
	using nik_safe(PREFIX, cp_builtin_builtin_car)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template cp_builtin_builtin_car<Continuation>;

								  template
								  <
									typename TypeX, typename TypeY, typename Pair,

									typename Continuation =
									typename nik_module(core, kernel, symbolic, semiotic)::
									functor::cp_moiz
								  >
	using nik_safe(PREFIX, builtin_builtin_car)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template builtin_builtin_car<TypeX, TypeY, Pair, Continuation>;

//

								  template<typename Continuation>
	using nik_safe(PREFIX, cp_builtin_typename_car)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template cp_builtin_typename_car<Continuation>;

								  template
								  <
									typename TypeX, typename Pair,

									typename Continuation =
									typename nik_module(core, kernel, symbolic, semiotic)::
									functor::cp_moiz
								  >
	using nik_safe(PREFIX, builtin_typename_car)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template builtin_typename_car<TypeX, Pair, Continuation>;

//

	using nik_safe(PREFIX, cp_typename_builtin_car)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  cp_typename_builtin_car;

								  template<typename TypeY, typename Pair>
	using nik_safe(PREFIX, typename_builtin_car)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template typename_builtin_car<TypeY, Pair>;

//

	using nik_safe(PREFIX, cp_typename_typename_car)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  cp_typename_typename_car;

								  template<typename Pair>
	using nik_safe(PREFIX, typename_typename_car)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template typename_typename_car<Pair>;

//

								  template<typename Continuation>
	using nik_safe(PREFIX, cp_builtin_builtin_cdr)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template cp_builtin_builtin_cdr<Continuation>;

								  template
								  <
									typename TypeX, typename TypeY, typename Pair,

									typename Continuation =
									typename nik_module(core, kernel, symbolic, semiotic)::
									functor::cp_moiz
								  >
	using nik_safe(PREFIX, builtin_builtin_cdr)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template builtin_builtin_cdr<TypeX, TypeY, Pair, Continuation>;

//

	using nik_safe(PREFIX, cp_builtin_typename_cdr)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  cp_builtin_typename_cdr;

								  template<typename TypeX, typename Pair>
	using nik_safe(PREFIX, builtin_typename_cdr)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template builtin_typename_cdr<TypeX, Pair>;

//

								  template<typename Continuation>
	using nik_safe(PREFIX, cp_typename_builtin_cdr)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template cp_typename_builtin_cdr<Continuation>;

								  template
								  <
									typename TypeY, typename Pair,

									typename Continuation =
									typename nik_module(core, kernel, symbolic, semiotic)::
									functor::cp_moiz
								  >
	using nik_safe(PREFIX, typename_builtin_cdr)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template typename_builtin_cdr<TypeY, Pair, Continuation>;

//

	using nik_safe(PREFIX, cp_typename_typename_cdr)	= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  cp_typename_typename_cdr;

								  template<typename Pair>
	using nik_safe(PREFIX, typename_typename_cdr)		= typename nik_module(product, calculus, symbolic, semiotic)::functor::
								  template typename_typename_cdr<Pair>;

//

#undef PREFIX

#include"undef-size_type.h"

