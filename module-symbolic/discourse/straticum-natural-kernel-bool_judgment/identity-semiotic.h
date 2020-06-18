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
#define snk_bool_judgment_ss nik_module(straticum, natural, kernel, bool_judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkbj_identity_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment
										  >
	using nik_safe(PREFIX, s_is_bool_judgment)				= typename snk_bool_judgment_ss::identity::template
										  s_is_bool_judgment<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_is_curried_bool_judgment)			= typename snk_bool_judgment_ss::identity::template
										  s_is_curried_bool_judgment<Exp, Continuation, Kind>;

//

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_bool_judgment)		= snk_bool_judgment_ss::identity::template
										  a_is_bool_judgment<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_curried_bool_judgment)	= snk_bool_judgment_ss::identity::template
										  a_is_curried_bool_judgment<Exp, Continuation, Image>;

//

#undef PREFIX

#undef snk_bool_judgment_ss
#undef snk_bool_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
