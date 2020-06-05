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

	#define PREFIX		pnkj_identity_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type, typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_judgement)					= typename pnk_judgement_ss::identity::template
										  s_is_judgement<Type, Exp, Continuation>;

										  template
										  <
											typename Type, typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_values
										  >
	using nik_safe(PREFIX, s_is_dependent_judgement)			= typename pnk_judgement_ss::identity::template
										  s_is_dependent_judgement<Type, Exp, Continuation>;

//

										  template
										  <
											typename Type, typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_judgement)			= pnk_judgement_ss::identity::template
										  a_is_judgement<Type, Exp, Continuation>;

										  template
										  <
											typename Type, typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr bool nik_safe(PREFIX, a_is_dependent_judgement)	= pnk_judgement_ss::identity::template
										  a_is_dependent_judgement<Type, Exp, Continuation>;

//

#undef PREFIX

#undef pnk_judgement_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
