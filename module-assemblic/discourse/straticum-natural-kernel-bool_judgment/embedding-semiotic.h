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
#define snk_bool_judgment_as nik_module(straticum, natural, kernel, bool_judgment, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkbj_embedding_as_

#else

	#define PREFIX

#endif

//

								  template
								  <
									bool Value,

									typename Continuation = nik::ch_s_values
								  >
	using nik_safe(PREFIX, sf_bool_judgment_value)		= typename snk_bool_judgment_as::embedding::template
								  sf_bool_judgment_value<Value, Continuation>;

								  template
								  <
									bool Value,
									typename Antecedent,
									typename Consequent,

									typename Continuation = nik::ch_s_type
								  >
	using nik_safe(PREFIX, s_bool_judgment_if_then_else)	= typename snk_bool_judgment_as::embedding::template
								  s_bool_judgment_if_then_else<Value, Antecedent, Consequent, Continuation>;

//

	static constexpr void (*nik_safe(PREFIX, p_bool_judgment_display))(bool)		= snk_bool_judgment_as::embedding::
												  p_bool_judgment_display;

//

#undef PREFIX

#undef snk_bool_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
