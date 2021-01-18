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
#define snk_signed_char_judgment_ss nik_module(straticum, natural, kernel, signed_char_judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkscj_proximity_ss_

#else

	#define PREFIX

#endif

//

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_less_than)			= typename snk_signed_char_judgment_ss::proximity::template
											  s_signed_char_judgment_less_than
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = bool
											  >
	using nik_safe(PREFIX, s_curried_signed_char_judgment_less_than)		= typename snk_signed_char_judgment_ss::proximity::template
											  s_curried_signed_char_judgment_less_than
											<Value1, Value2, Continuation, Kind>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_less_than_or_equal)		= typename snk_signed_char_judgment_ss::proximity::template
											  s_signed_char_judgment_less_than_or_equal
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = bool
											  >
	using nik_safe(PREFIX, s_curried_signed_char_judgment_less_than_or_equal)	= typename snk_signed_char_judgment_ss::proximity::template
											  s_curried_signed_char_judgment_less_than_or_equal
											<Value1, Value2, Continuation, Kind>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_greater_than)			= typename snk_signed_char_judgment_ss::proximity::template
											  s_signed_char_judgment_greater_than
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = bool
											  >
	using nik_safe(PREFIX, s_curried_signed_char_judgment_greater_than)		= typename snk_signed_char_judgment_ss::proximity::template
											  s_curried_signed_char_judgment_greater_than
											<Value1, Value2, Continuation, Kind>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_signed_char_judgment_greater_than_or_equal)		= typename snk_signed_char_judgment_ss::proximity::template
											  s_signed_char_judgment_greater_than_or_equal
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = bool
											  >
	using nik_safe(PREFIX, s_curried_signed_char_judgment_greater_than_or_equal)	= typename snk_signed_char_judgment_ss::proximity::template
											  s_curried_signed_char_judgment_greater_than_or_equal
											<Value1, Value2, Continuation, Kind>;

//

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_char_judgment_less_than)	= snk_signed_char_judgment_ss::proximity::template
											  a_signed_char_judgment_less_than
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = bool,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_signed_char_judgment_less_than)	= snk_signed_char_judgment_ss::proximity::template
											  a_curried_signed_char_judgment_less_than
											<Value1, Value2, Continuation, Kind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_char_judgment_less_than_or_equal)	= snk_signed_char_judgment_ss::proximity::template
											  a_signed_char_judgment_less_than_or_equal
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = bool,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_signed_char_judgment_less_than_or_equal)	= snk_signed_char_judgment_ss::proximity::template
											  a_curried_signed_char_judgment_less_than_or_equal
											<Value1, Value2, Continuation, Kind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_char_judgment_greater_than)	= snk_signed_char_judgment_ss::proximity::template
											  a_signed_char_judgment_greater_than
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = bool,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_signed_char_judgment_greater_than)	= snk_signed_char_judgment_ss::proximity::template
											  a_curried_signed_char_judgment_greater_than
											<Value1, Value2, Continuation, Kind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_signed_char_judgment_greater_than_or_equal)	= snk_signed_char_judgment_ss::proximity::template
											  a_signed_char_judgment_greater_than_or_equal
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = bool,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_signed_char_judgment_greater_than_or_equal)	= snk_signed_char_judgment_ss::proximity::template
											  a_curried_signed_char_judgment_greater_than_or_equal
											<Value1, Value2, Continuation, Kind, Image>;

//

#undef PREFIX

#undef snk_signed_char_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
