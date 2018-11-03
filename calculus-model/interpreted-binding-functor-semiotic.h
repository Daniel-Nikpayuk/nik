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

	#define PREFIX		intbif_

#else

	#define PREFIX

#endif

//

							  template<typename... Exps>
	using nik_safe(PREFIX, construct)		= typename nik_module(binding, interpreted, calculus, semiotic)::functor::template
							  construct<Exps...>;

							  template<typename Exp>
	using nik_safe(PREFIX, binding_variable)	= typename nik_module(binding, interpreted, calculus, semiotic)::functor::template
							  binding_variable<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, binding_value)		= typename nik_module(binding, interpreted, calculus, semiotic)::functor::template
							  binding_value<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, binding_lambda)		= typename nik_module(binding, interpreted, calculus, semiotic)::functor::template
							  binding_lambda<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, binding_body)		= typename nik_module(binding, interpreted, calculus, semiotic)::functor::template
							  binding_body<Exp>;

//

#undef PREFIX

#include"undef-size_type.h"

