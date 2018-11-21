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

	#define PREFIX		pertyf_

#else

	#define PREFIX

#endif

//

							  template
							  <
								typename Kind, typename Type,
								template<Type...> class eager, Type... Params
							  >
	using nik_safe(PREFIX, delay)			= typename nik_branch(typed, calculus, semiotic)::functor::template
							  delay<Kind, Type, eager, Params...>;

							  template<typename Exp>
	using nik_safe(PREFIX, force)			= typename nik_branch(typed, calculus, semiotic)::functor::template
							  force<Exp>;

//

							  template<typename Type, Type Value, typename List>
	using nik_safe(PREFIX, cons)			= typename nik_branch(typed, calculus, semiotic)::functor::template
							  cons<Type, Value, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, car)			= typename nik_branch(typed, calculus, semiotic)::functor::template
							  car<Type, List>;

							  template<typename Type, typename List>
	using nik_safe(PREFIX, cdr)			= typename nik_branch(typed, calculus, semiotic)::functor::template
							  cdr<Type, List>;

//

#undef PREFIX

#include"undef-size_type.h"

