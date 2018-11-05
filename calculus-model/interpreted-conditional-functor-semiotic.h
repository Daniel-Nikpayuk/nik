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

	#define PREFIX		intcof_

#else

	#define PREFIX

#endif

//

							  template<typename Exp, typename Env, typename Functor>
	using nik_safe(PREFIX, evaluate_if_)		= typename nik_module(conditional, interpreted, calculus, semiotic)::functor::template
							  evaluate_if_<Exp, Env, Functor>;

							  template<typename Exp>
	using nik_safe(PREFIX, cond_to_if_)		= typename nik_module(conditional, interpreted, calculus, semiotic)::functor::template
							  cond_to_if_<Exp>;

//

#undef PREFIX

#include"undef-size_type.h"

