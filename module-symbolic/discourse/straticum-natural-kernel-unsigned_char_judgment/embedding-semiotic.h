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
#define snk_unsigned_char_judgment_ss nik_module(straticum, natural, kernel, unsigned_char_judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkucj_embedding_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
										  	typename Judgment,

										  	typename Continuation = nik::ch_s_values,
										  	typename Kind = unsigned char,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											Kind (*Op)(unsigned char) = nik::p_identity<Kind>
										  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_value)			= typename snk_unsigned_char_judgment_ss::embedding::template
										  s_unsigned_char_judgment_value
											<Judgment, Continuation, Kind, ListKind, Op>;

										  template
										  <
										  	typename Judgment,
										  	typename Continuation = nik::ch_s_values,
										  	typename Kind = unsigned char,
											Kind (*Op)(unsigned char) = nik::p_identity<Kind>
										  >
	using nik_safe(PREFIX, s_curried_unsigned_char_judgment_value)		= typename snk_unsigned_char_judgment_ss::embedding::template
										  s_curried_unsigned_char_judgment_value
											<Judgment, Continuation, Kind, Op>;

//

										  template
										  <
										  	typename Judgment,

										  	typename Continuation = nik::ch_a_to_value,
										  	typename Kind = unsigned char,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											Kind (*Op)(unsigned char) = nik::p_identity<Kind>,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_char_judgment_value)	= snk_unsigned_char_judgment_ss::embedding::template
										  a_unsigned_char_judgment_value
											<Judgment, Continuation, Kind, ListKind, Op, Image>;

										  template
										  <
										  	typename Judgment,
										  	typename Continuation = nik::ch_a_to_value,
										  	typename Kind = unsigned char,
											Kind (*Op)(unsigned char) = nik::p_identity<Kind>,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_unsigned_char_judgment_value)	= snk_unsigned_char_judgment_ss::embedding::template
										  a_curried_unsigned_char_judgment_value
											<Judgment, Continuation, Kind, Op, Image>;

//

#undef PREFIX

#undef snk_unsigned_char_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
