/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	#define PREFIX		calref_

#else

	#define PREFIX

#endif

//

	using nik_safe(PREFIX, echo_if_then_else)		= typename nik_module(boolean, calculus, symbolic, semiotic)::functor::
								  echo_if_then_else;

								  template<bool Pred, typename Ante, typename Conse>
	using nik_safe(PREFIX, ping_if_then_else)		= typename nik_module(boolean, calculus, symbolic, semiotic)::functor::
								  template ping_if_then_else<Pred, Ante, Conse>;

								  template<bool Pred, typename Ante, typename Conse>
	using nik_safe(PREFIX, call_if_then_else)		= typename nik_module(boolean, calculus, symbolic, semiotic)::functor::
								  template call_if_then_else<Pred, Ante, Conse>;

								  template<bool Pred, typename Ante, typename Conse>
	using nik_safe(PREFIX, head_if_then_else)		= typename nik_module(boolean, calculus, symbolic, semiotic)::functor::
								  template head_if_then_else<Pred, Ante, Conse>;

								  template<bool Pred, typename Ante, typename Conse>
	using nik_safe(PREFIX, tail_if_then_else)		= typename nik_module(boolean, calculus, symbolic, semiotic)::functor::
								  template tail_if_then_else<Pred, Ante, Conse>;

//

#undef PREFIX

#include"undef-size_type.h"

