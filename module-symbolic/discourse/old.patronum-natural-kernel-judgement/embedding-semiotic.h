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
#define pnk_judgement_ss nik_module(patronum, natural, kernel, judgement, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkj_embedding_ss_

#else

	#define PREFIX

#endif

//

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_s_judgement_type)				= typename pnk_judgement_ss::embedding::template
										  cp_s_judgement_type<Continuation>;

										  template
										  <
											typename Type, typename Judgement,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_type
										  >
	using nik_safe(PREFIX, s_judgement_type)				= typename pnk_judgement_ss::embedding::template
										  s_judgement_type<Type, Judgement, Continuation>;

//

										  template
										  <
											typename Continuation,

											typename Inductor =
											typename pnk_builtin_ss::inductor
										  >
	using nik_safe(PREFIX, cp_s_judgement_value)				= typename pnk_judgement_ss::embedding::template
										  cp_s_judgement_value<Continuation, Inductor>;

										  template
										  <
											typename Type, typename Judgement,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_judgement_value)				= typename pnk_judgement_ss::embedding::template
										  s_judgement_value<Type, Judgement, Continuation>;

//

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_s_dependent_judgement_type)			= typename pnk_judgement_ss::embedding::template
										  cp_s_dependent_judgement_type<Continuation>;

										  template
										  <
											typename Type, typename Judgement,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_type
										  >
	using nik_safe(PREFIX, s_dependent_judgement_type)			= typename pnk_judgement_ss::embedding::template
										  s_dependent_judgement_type<Type, Judgement, Continuation>;

//

										  template
										  <
											typename Type, typename Judgement,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_dependent_judgement_value)			= typename pnk_judgement_ss::embedding::template
										  s_dependent_judgement_value<Type, Judgement, Continuation>;

//

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_a_judgement_value)				= typename pnk_judgement_ss::embedding::template
										  cp_a_judgement_value<Continuation>;

										  template
										  <
											typename Type, typename Judgement,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr Type nik_safe(PREFIX, a_judgement_value)		= pnk_judgement_ss::embedding::template
										  a_judgement_value<Type, Judgement, Continuation>;

//

										  template<typename Continuation>
	using nik_safe(PREFIX, cp_a_dependent_judgement_value)			= typename pnk_judgement_ss::embedding::template
										  cp_a_dependent_judgement_value<Continuation>;

										  template
										  <
											typename Type, typename Judgement,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr Type nik_safe(PREFIX, a_dependent_judgement_value)	= pnk_judgement_ss::embedding::template
										  a_dependent_judgement_value<Type, Judgement, Continuation>;

//

#undef PREFIX

#undef pnk_judgement_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)

