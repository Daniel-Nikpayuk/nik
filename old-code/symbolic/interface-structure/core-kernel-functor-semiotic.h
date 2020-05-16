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

	#define PREFIX		corkef_

#else

	#define PREFIX

#endif

//

	using nik_safe(PREFIX, ch_echo)			= typename nik_module(kernel, core, symbolic, semiotic)::functor::
							  ch_echo;

							  template<typename Type>
	using nik_safe(PREFIX, ping)			= typename nik_module(kernel, core, symbolic, semiotic)::functor::template
							  ping<Type>;

//

							  template<typename Type>
	using nik_safe(PREFIX, dereference)		= typename nik_module(kernel, core, symbolic, semiotic)::functor::template
							  dereference<Type>;

//

#undef PREFIX

#include"undef-size_type.h"

