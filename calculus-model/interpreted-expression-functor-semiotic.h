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

	#define PREFIX		intexf_

#else

	#define PREFIX

#endif

//

							  template
							  <
								typename Exp, typename Env = typename
								nik_module(environment, interpreted, calculus, semiotic)::structure::template
								environment<>
							  >
	using nik_safe(PREFIX, evaluate)		= typename nik_module(expression, interpreted, calculus, semiotic)::functor::template
							  evaluate<Exp, Env>;

							  template
							  <
								typename Prog, typename Env = typename
								nik_module(environment, interpreted, calculus, semiotic)::structure::template
								environment<>
							  >
	using nik_safe(PREFIX, interpret)		= typename nik_module(expression, interpreted, calculus, semiotic)::functor::template
							  interpret<Prog, Env>;

//

#undef PREFIX

#include"undef-size_type.h"

