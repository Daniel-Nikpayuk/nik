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

	#define PREFIX		kercof_

#else

	#define PREFIX

#endif

//

	using nik_safe(PREFIX, echo)			= typename nik_module(core, kernel, symbolic, semiotic)::functor::
							  echo;

							  template<typename Type>
	using nik_safe(PREFIX, ping)			= typename nik_module(core, kernel, symbolic, semiotic)::functor::template
							  ping<Type>;

	using nik_safe(PREFIX, cp_moiz)			= typename nik_module(core, kernel, symbolic, semiotic)::functor::
							  cp_moiz;

							  template
							  <
								typename Op, typename Type, Type Value,

								typename Continuation =
								typename nik_module(core, kernel, symbolic, semiotic)::
								functor::cp_moiz
							  >
	using nik_safe(PREFIX, pose)			= typename nik_module(core, kernel, symbolic, semiotic)::functor::template
							  pose<Continuation, Op, Type, Value>;

							  template
							  <
								typename Type, typename Dual,

								typename Continuation =
								typename nik_module(core, kernel, symbolic, semiotic)::
								functor::cp_moiz
							  >
	using nik_safe(PREFIX, turn)			= typename nik_module(core, kernel, symbolic, semiotic)::functor::template
							  turn<Continuation, Type, Dual>;

							  template<typename Dual>
	using nik_safe(PREFIX, call)			= typename nik_module(core, kernel, symbolic, semiotic)::functor::template
							  call<Dual>;

//

							  template<typename Type>
	using nik_safe(PREFIX, dereference)		= typename nik_module(core, kernel, symbolic, semiotic)::functor::template
							  dereference<Type>;

//

#undef PREFIX

#include"undef-size_type.h"

