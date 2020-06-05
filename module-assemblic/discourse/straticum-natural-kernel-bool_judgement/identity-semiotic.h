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

#include nik_size_type(define)

#define pnk_builtin_ss nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)
#define snk_bool_judgement_as nik_module(straticum, natural, kernel, bool_judgement, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkb_identity_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											bool Value1,
											bool Value2,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_bool_judgement_equal)			= typename snk_bool_judgement_as::identity::template
										  s_is_bool_judgement_equal<Value1, Value2, Continuation>;

//

	static constexpr bool (*nik_safe(PREFIX, p_is_bool_judgement_equal))(bool, bool)	= snk_bool_judgement_as::identity::
												  p_is_bool_judgement_equal;

//

#undef PREFIX

#undef snk_bool_judgement_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
