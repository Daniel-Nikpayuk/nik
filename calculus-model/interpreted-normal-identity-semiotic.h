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

	#define PREFIX		intnoi_

#else

	#define PREFIX

#endif

//	error:

							  template<typename Exp>
	using nik_safe(PREFIX, is_error)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_error<Exp>;

//	environment:

							  template<typename Exp>
	using nik_safe(PREFIX, is_binding)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_binding<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, is_frame)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_frame<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, is_environment)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_environment<Exp>;

//	quote:

							  template<typename Exp>
	using nik_safe(PREFIX, is_quote)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_quote<Exp>;

//	lambda:

							  template<typename Exp>
	using nik_safe(PREFIX, is_lambda)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_lambda<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, is_compound)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_compound<Exp>;

//	definition:

							  template<typename Exp>
	using nik_safe(PREFIX, is_definition)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_definition<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, is_value_definition)	= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_value_definition<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, is_compound_definition)	= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_compound_definition<Exp>;

//	assignment:

							  template<typename Exp>
	using nik_safe(PREFIX, is_assignment)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_assignment<Exp>;

//	if_:

							  template<typename Exp>
	using nik_safe(PREFIX, is_true)			= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_true<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, is_if_)			= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_if_<Exp>;

//	begin:

							  template<typename Exp>
	using nik_safe(PREFIX, is_begin)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_begin<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, is_last)			= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_last<Exp>;

//	cond:

							  template<typename Exp>
	using nik_safe(PREFIX, is_cond)			= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_cond<Exp>;

							  template<typename Exp>
	using nik_safe(PREFIX, is_else_)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_else_<Exp>;

//	application:

							  template<typename Exp>
	using nik_safe(PREFIX, is_application)		= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_application<Exp>;

//	expression:

							  template<typename Exp>
	using nik_safe(PREFIX, is_self_evaluating)	= typename nik_module(normal, interpreted, calculus, semiotic)::identity::template
							  is_self_evaluating<Exp>;

//

#undef PREFIX

#include"undef-size_type.h"

