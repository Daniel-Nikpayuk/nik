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

	#define PREFIX		typinf_

#else

	#define PREFIX

#endif

//

							  template<typename RegType>
	using nik_safe(PREFIX, min)			= typename nik_module(information, typed, calculus, semiotic)::functor::template
							  min<RegType>;

							  template<typename RegType>
	using nik_safe(PREFIX, max)			= typename nik_module(information, typed, calculus, semiotic)::functor::template
							  max<RegType>;

//

							  template<SIZE_TYPE N>
	using nik_safe(PREFIX, unsigned_type)		= typename nik_module(information, typed, calculus, semiotic)::functor::template
							  unsigned_type<N>;

							  template<SIZE_TYPE N>
	using nik_safe(PREFIX, signed_type)		= typename nik_module(information, typed, calculus, semiotic)::functor::template
							  signed_type<N>;

#define ONE 1

							  template<SIZE_TYPE N>
	using nik_safe(PREFIX, unsigned_half)		= typename nik_module(information, typed, calculus, semiotic)::functor::template
							  unsigned_type<(N >> ONE)>;

							  template<SIZE_TYPE N>
	using nik_safe(PREFIX, signed_half)		= typename nik_module(information, typed, calculus, semiotic)::functor::template
							  signed_type<(N >> ONE)>;

#undef ONE

//

							  template<typename Type, typename... Exps>
	using nik_safe(PREFIX, apply)			= typename nik_module(information, typed, calculus, semiotic)::functor::template
							  apply<Type, Exps...>;

//

#undef PREFIX

#include"undef-size_type.h"

