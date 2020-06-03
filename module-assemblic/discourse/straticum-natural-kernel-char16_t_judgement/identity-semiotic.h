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
#define snk_char16_t_judgement_as nik_module(straticum, natural, kernel, char16_t_judgement, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkc_identity_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											char16_t Value1,
											char16_t Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_char16_t_equal)				= typename snk_char16_t_judgement_as::identity::template
										  s_is_char16_t_equal<Value1, Value2, Continuation>;

//

										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr void nik_safe(PREFIX, a_char16_t_judgement_)			= snk_char16_t_judgement_as::identity::template
										  a_char16_t_judgement_<Type, Continuation>;

//

	static constexpr bool (*nik_safe(PREFIX, p_is_char16_t_equal))(char16_t, char16_t) =
		snk_char16_t_judgement_as::identity::p_is_char16_t_equal;

//

#undef PREFIX

#undef snk_char16_t_judgement_as
#undef pnk_builtin_ss

#include"undef-size_type.h"
