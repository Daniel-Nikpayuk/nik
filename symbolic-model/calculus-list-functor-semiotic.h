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

							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, builtin_cons)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_cons<Type, Value, List>;

							  template
							  <
								typename List,

								typename Continuation =
								typename nik_module(kernel, core, symbolic, semiotic)::
								functor::ch_echo
							  >
	using nik_safe(PREFIX, builtin_car)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_car<List, Continuation>;

							  template<typename List>
	using nik_safe(PREFIX, builtin_cdr)		= typename nik_module(list, calculus, symbolic, semiotic)::functor::template
							  builtin_cdr<List>;

//

#undef PREFIX

#include"undef-size_type.h"

