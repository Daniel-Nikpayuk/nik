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

	#define PREFIX		snkb_embedding_as_

#else

	#define PREFIX

#endif

//

										  template
										  <
											bool Value,
											typename Antecedent,
											typename Consequent,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, if_then_else)					= typename snk_bool_judgement_as::embedding::template
										  if_then_else<Value, Antecedent, Consequent, Continuation>;

										  template
										  <
											bool Value,
											typename Antecedent,
											typename Consequent
										  >
	using nik_safe(PREFIX, fast_if_then_else)				= typename snk_bool_judgement_as::embedding::template
										  fast_if_then_else<Value, Antecedent, Consequent>;

//

	static constexpr void (*nik_safe(PREFIX, p_bool_judgement_display))(bool)		= snk_bool_judgement_as::embedding::
												  p_bool_judgement_display;

//

#undef PREFIX

#undef snk_bool_judgement_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
