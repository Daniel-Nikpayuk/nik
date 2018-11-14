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

	#define PREFIX		intasf_

#else

	#define PREFIX

#endif

//

							  template<typename Exp>
	using nik_safe(PREFIX, assignment_variable)	= typename nik_module(assignment, interpreted, calculus, semiotic)::functor::template
							  assignment_variable<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, assignment_value)	= typename nik_module(assignment, interpreted, calculus, semiotic)::functor::template
							  assignment_value<Exp>;

							  template<typename Exp, typename Env, typename Functor>
	using nik_safe(PREFIX, evaluate_assignment)	= typename nik_module(assignment, interpreted, calculus, semiotic)::functor::template
							  evaluate_assignment<Exp, Env, Functor>;

//

#undef PREFIX

#include"undef-size_type.h"
