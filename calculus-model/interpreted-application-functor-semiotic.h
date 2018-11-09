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

	#define PREFIX		intapf_

#else

	#define PREFIX

#endif

//

							  template<typename Exps, typename Env, typename Func>
	using nik_safe(PREFIX, list_of_values)		= typename nik_module(application, interpreted, calculus, semiotic)::functor::template
							  list_of_values<Exps, Env, Func>;

							  template<typename Operator, typename Env, typename Func>
	using nik_safe(PREFIX, evaluate_application)	= typename nik_module(application, interpreted, calculus, semiotic)::functor::template
							  evaluate_application<Operator, Env, Func>;

							  template<typename Proc, typename Args>
	using nik_safe(PREFIX, apply)			= typename nik_module(application, interpreted, calculus, semiotic)::functor::template
							  apply<Proc, Args>;

//

#undef PREFIX

#include"undef-size_type.h"

