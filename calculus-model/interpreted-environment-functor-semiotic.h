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

	#define PREFIX		intenf_

#else

	#define PREFIX

#endif

//

							  template<typename Variables, typename Values, typename Environment>
	using nik_safe(PREFIX, construct)		= typename nik_module(environment, interpreted, calculus, semiotic)::functor::template
							  construct<Variables, Values, Environment>;

							  template<typename Variable, typename Environment>
	using nik_safe(PREFIX, lookup)			= typename nik_module(environment, interpreted, calculus, semiotic)::functor::template
							  lookup<Variable, Environment>;

							  template<typename Variable, typename Value, typename Env>
	using nik_safe(PREFIX, set)			= typename nik_module(environment, interpreted, calculus, semiotic)::functor::template
							  set<Variable, Value, Env>;

							  template<typename Variable, typename Value, typename Env>
	using nik_safe(PREFIX, define)			= typename nik_module(environment, interpreted, calculus, semiotic)::functor::template
							  define<Variable, Value, Env>;

//

#undef PREFIX

#include"undef-size_type.h"
