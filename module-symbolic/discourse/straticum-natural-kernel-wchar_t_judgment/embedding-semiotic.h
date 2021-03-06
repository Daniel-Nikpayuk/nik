/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
#define snk_wchar_t_judgment_ss nik_module(straticum, natural, kernel, wchar_t_judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkwtj_embedding_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
										  	typename Judgment,

										  	typename Continuation = nik::ch_s_values,
										  	typename Kind = wchar_t,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											Kind (*Op)(wchar_t) = nik::p_identity<Kind>
										  >
	using nik_safe(PREFIX, s_wchar_t_judgment_value)			= typename snk_wchar_t_judgment_ss::embedding::template
										  s_wchar_t_judgment_value
											<Judgment, Continuation, Kind, ListKind, Op>;

										  template
										  <
										  	typename Judgment,
										  	typename Continuation = nik::ch_s_values,
										  	typename Kind = wchar_t,
											Kind (*Op)(wchar_t) = nik::p_identity<Kind>
										  >
	using nik_safe(PREFIX, s_curried_wchar_t_judgment_value)		= typename snk_wchar_t_judgment_ss::embedding::template
										  s_curried_wchar_t_judgment_value
											<Judgment, Continuation, Kind, Op>;

//

										  template
										  <
										  	typename Judgment,

										  	typename Continuation = nik::ch_a_to_value,
										  	typename Kind = wchar_t,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											Kind (*Op)(wchar_t) = nik::p_identity<Kind>,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_wchar_t_judgment_value)	= snk_wchar_t_judgment_ss::embedding::template
										  a_wchar_t_judgment_value
											<Judgment, Continuation, Kind, ListKind, Op, Image>;

										  template
										  <
										  	typename Judgment,
										  	typename Continuation = nik::ch_a_to_value,
										  	typename Kind = wchar_t,
											Kind (*Op)(wchar_t) = nik::p_identity<Kind>,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_wchar_t_judgment_value)	= snk_wchar_t_judgment_ss::embedding::template
										  a_curried_wchar_t_judgment_value
											<Judgment, Continuation, Kind, Op, Image>;

//

#undef PREFIX

#undef snk_wchar_t_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
