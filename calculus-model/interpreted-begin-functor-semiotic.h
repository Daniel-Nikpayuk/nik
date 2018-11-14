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

	#define PREFIX		intbef_

#else

	#define PREFIX

#endif

//

							  template<typename Exps>
	using nik_safe(PREFIX, make_begin)		= typename nik_module(begin, interpreted, calculus, semiotic)::functor::template
							  make_begin<Exps>;

							  template<typename Exps>
	using nik_safe(PREFIX, sequence_to_expression)	= typename nik_module(begin, interpreted, calculus, semiotic)::functor::template
							  sequence_to_expression<Exps>;

							  template<typename Exps, typename Env, typename Functor>
	using nik_safe(PREFIX, evaluate_sequence)	= typename nik_module(begin, interpreted, calculus, semiotic)::functor::template
							  evaluate_sequence<Exps, Env, Functor>;

//

#undef PREFIX

#include"undef-size_type.h"
