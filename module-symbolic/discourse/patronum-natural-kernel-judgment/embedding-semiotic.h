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
#define pnk_judgment_ss nik_module(patronum, natural, kernel, judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkj_embedding_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_grow_to_type
										  >
	using nik_safe(PREFIX, s_judgment_type)					= typename pnk_judgment_ss::embedding::template
										  s_judgment_type
											<Type, Judgment, Continuation>;

//

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation = nik::ch_s_values,
											typename Kind = Type,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											Kind (*Op)(Type) = nik::p_identity<Kind>
										  >
	using nik_safe(PREFIX, s_judgment_value)				= typename pnk_judgment_ss::embedding::template
										  s_judgment_value
											<Type, Judgment, Continuation, Kind, ListKind, Op>;

//

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_grow_to_type
										  >
	using nik_safe(PREFIX, s_curried_judgment_type)				= typename pnk_judgment_ss::embedding::template
										  s_curried_judgment_type
											<Type, Judgment, Continuation>;

//

										  template
										  <
											typename Type, typename Judgment,
											typename Continuation = nik::ch_s_values,
											typename Kind = Type,
											Kind (*Op)(Type) = nik::p_identity<Kind>
										  >
	using nik_safe(PREFIX, s_curried_judgment_value)			= typename pnk_judgment_ss::embedding::template
										  s_curried_judgment_value
											<Type, Judgment, Continuation, Kind, Op>;

//

										  template
										  <
											typename Type, typename Judgment,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = Type,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											Kind (*Op)(Type) = nik::p_identity<Kind>,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_value)		= pnk_judgment_ss::embedding::template
										  a_judgment_value
										<Type, Judgment, Continuation, Kind, ListKind, Op, Image>;

//

										  template
										  <
											typename Type, typename Judgment,
											typename Continuation = nik::ch_a_to_value,
											typename Kind = Type,
											Kind (*Op)(Type) = nik::p_identity<Kind>,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_judgment_value)	= pnk_judgment_ss::embedding::template
										  a_curried_judgment_value
										<Type, Judgment, Continuation, Kind, Op, Image>;

//

#undef PREFIX

#undef pnk_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
