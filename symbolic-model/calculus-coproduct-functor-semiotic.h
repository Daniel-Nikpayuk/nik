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

	#define PREFIX		calcopf_

#else

	#define PREFIX

#endif

//

	using nik_safe(PREFIX, cp_echo_left_inject)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  cp_echo_left_inject;

	using nik_safe(PREFIX, cp_ping_left_inject)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  cp_ping_left_inject;

	using nik_safe(PREFIX, cp_echo_right_inject)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  cp_echo_right_inject;

	using nik_safe(PREFIX, cp_ping_right_inject)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  cp_ping_right_inject;

//

								  template
								  <
									typename Type, typename Copair,

									typename Continuation =
									typename nik_module(core, kernel, symbolic, semiotic)::
									functor::cp_moiz
								  >
	using nik_safe(PREFIX, builtin_copair_car)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  template builtin_copair_car<Type, Copair, Continuation>;

								  template<typename Copair>
	using nik_safe(PREFIX, typename_copair_car)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  template typename_copair_car<Copair>;

//

								  template
								  <
									typename Type, typename Copair,

									typename Continuation =
									typename nik_module(core, kernel, symbolic, semiotic)::
									functor::cp_moiz
								  >
	using nik_safe(PREFIX, builtin_copair_cdr)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  template builtin_copair_cdr<Type, Copair, Continuation>;

								  template<typename Copair>
	using nik_safe(PREFIX, typename_copair_cdr)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  template typename_copair_cdr<Copair>;

//

								  template<typename TypeX, typename TypeY, typename Proj, typename Pair>
	using nik_safe(PREFIX, builtin_builtin_cpr)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  template builtin_builtin_cpr<TypeX, TypeY, Proj, Pair>;

								  template<typename TypeX, typename Proj, typename Pair>
	using nik_safe(PREFIX, builtin_typename_cpr)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  template builtin_typename_cpr<TypeX, Proj, Pair>;

								  template<typename TypeY, typename Proj, typename Pair>
	using nik_safe(PREFIX, typename_builtin_cpr)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  template typename_builtin_cpr<TypeY, Proj, Pair>;

								  template<typename Proj, typename Pair>
	using nik_safe(PREFIX, typename_typename_cpr)		= typename nik_module(coproduct, calculus, symbolic, semiotic)::functor::
								  template typename_typename_cpr<Proj, Pair>;

//

#undef PREFIX

#include"undef-size_type.h"

