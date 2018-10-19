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

#ifdef safe_name

	#define PREFIX		calpef_

#else

	#define PREFIX

#endif

//

						  template<typename Type>
using nik_safe(PREFIX, dereference)		= typename calculus::functor::template dereference<Type>;

//

						  template<global_size_type N>
using nik_safe(PREFIX, register_type)		= typename calculus::functor::template register_type<N>;


#define ONE 1

						  template<global_size_type N>
using nik_safe(PREFIX, half_type)		= typename calculus::functor::template register_type<(N >> ONE)>;

#undef ONE

//

						  template<typename Exp, typename ListType>
using nik_safe(PREFIX, cons)			= typename calculus::functor::template cons<Exp, ListType>;

						  template<typename ListType>
using nik_safe(PREFIX, car)			= typename calculus::functor::template car<ListType>;

						  template<typename ListType>
using nik_safe(PREFIX, cdr)			= typename calculus::functor::template cdr<ListType>;

//

#undef PREFIX

