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

#define pnk_builtin_ss nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkb_structure_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type, Type Value,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_to_judgement)					= typename pnk_builtin_ss::structure::template
										  s_to_judgement<Type, Value, Continuation>;

//

										  template
										  <
											typename Kind, typename Type, Type Value,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr Kind nik_safe(PREFIX, a_to_judgement)			= pnk_builtin_ss::structure::template
										  a_to_judgement<Kind, Type, Value, Continuation>;

//

#undef PREFIX

#undef pnk_builtin_ss

#include"undef-size_type.h"
