/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	#define PREFIX		calhaf_

#else

	#define PREFIX

#endif

//

							  template
							  <
								typename Kind, typename Handle, typename Type, Type Value,

								typename Continuation =
								typename nik_module(kernel, core, symbolic, semiotic)::
								functor::ch_echo
							  >
	using nik_safe(PREFIX, pose)			= typename nik_module(handle, calculus, symbolic, semiotic)::functor::template
							  pose<Kind, Handle, Type, Value, Continuation>;

							  template
							  <
								typename Type, typename Handle,

								typename Continuation =
								typename nik_module(kernel, core, symbolic, semiotic)::
								functor::ch_echo
							  >
	using nik_safe(PREFIX, turn)			= typename nik_module(handle, calculus, symbolic, semiotic)::functor::template
							  turn<Type, Handle, Continuation>;

							  template
							  <
								typename Type, template<typename, Type> class Handle, Type Value
							  >
	using nik_safe(PREFIX, moiz)			= typename nik_module(handle, calculus, symbolic, semiotic)::functor::template
							  moiz<Type, Handle, Value>;

							  template<typename Handle>
	using nik_safe(PREFIX, call)			= typename nik_module(handle, calculus, symbolic, semiotic)::functor::template
							  call<Handle>;

//

#undef PREFIX

#include"undef-size_type.h"

