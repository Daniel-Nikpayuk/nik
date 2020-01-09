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

	#define PREFIX		calcopf_

#else

	#define PREFIX

#endif

//

								  template<typename Type, Type Value>
	using nik_safe(PREFIX, builtin_inject_left)		= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template builtin_inject_left<Type, Value>;

								  template<typename Type, Type Value>
	using nik_safe(PREFIX, builtin_inject_right)		= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template builtin_inject_right<Type, Value>;

								  template<typename Value>
	using nik_safe(PREFIX, typename_inject_left)		= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template typename_inject_left<Value>;

								  template<typename Value>
	using nik_safe(PREFIX, typename_inject_right)		= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template typename_inject_right<Value>;

//

								  template
								  <
									typename Copair,

									typename Continuation =
									typename nik_module(kernel, core, symbolic, semiotic)::
									functor::ch_echo
								  >
	using nik_safe(PREFIX, builtin_value)			= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template builtin_value<Copair, Continuation>;

								  template<typename Copair>
	using nik_safe(PREFIX, typename_value)			= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template typename_value<Copair>;

//

								  template<typename Proj, typename Pair>
	using nik_safe(PREFIX, builtin_builtin_cpr)		= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template builtin_builtin_cpr<Proj, Pair>;

								  template<typename Proj, typename Pair>
	using nik_safe(PREFIX, builtin_typename_cpr)		= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template builtin_typename_cpr<Proj, Pair>;

								  template<typename Proj, typename Pair>
	using nik_safe(PREFIX, typename_builtin_cpr)		= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template typename_builtin_cpr<Proj, Pair>;

								  template<typename Proj, typename Pair>
	using nik_safe(PREFIX, typename_typename_cpr)		= typename nik_module(copair, calculus, symbolic, semiotic)::functor::
								  template typename_typename_cpr<Proj, Pair>;

//

#undef PREFIX

#include"undef-size_type.h"

