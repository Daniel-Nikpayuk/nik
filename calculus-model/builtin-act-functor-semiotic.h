/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	#define PREFIX		perbuf_

#else

	#define PREFIX

#endif

//

							  template<typename Type>
	using nik_safe(PREFIX, dereference)		= typename nik_module(act, builtin, calculus, semiotic)::functor::template
							  dereference<Type>;

//

							  template<typename Exp, typename List>
	using nik_safe(PREFIX, untyped_cons)		= typename nik_module(act, builtin, calculus, semiotic)::functor::template
							  untyped_cons<Exp, List>;

							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, typed_cons)		= typename nik_module(act, builtin, calculus, semiotic)::functor::template
							  typed_cons<Type, Value, List>;

							  template<typename List>
	using nik_safe(PREFIX, untyped_car)		= typename nik_module(act, builtin, calculus, semiotic)::functor::template
							  untyped_car<List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, typed_car)		= typename nik_module(act, builtin, calculus, semiotic)::functor::template
							  typed_car<Type, List>;

							  template<typename List>
	using nik_safe(PREFIX, untyped_cdr)		= typename nik_module(act, builtin, calculus, semiotic)::functor::template
							  untyped_cdr<List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, typed_cdr)		= typename nik_module(act, builtin, calculus, semiotic)::functor::template
							  typed_cdr<Type, List>;

//

#undef PREFIX

#include"undef-size_type.h"

