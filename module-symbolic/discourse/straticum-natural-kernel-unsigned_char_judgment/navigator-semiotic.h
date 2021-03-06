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
#define snk_unsigned_char_judgment_ss nik_module(straticum, natural, kernel, unsigned_char_judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkucj_navigator_ss_

#else

	#define PREFIX

#endif

//

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_add)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_unsigned_char_judgment_add
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char
											  >
	using nik_safe(PREFIX, s_curried_unsigned_char_judgment_add)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_curried_unsigned_char_judgment_add
											<Value1, Value2, Continuation, Kind>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_subtract)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_unsigned_char_judgment_subtract
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char
											  >
	using nik_safe(PREFIX, s_curried_unsigned_char_judgment_subtract)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_curried_unsigned_char_judgment_subtract
											<Value1, Value2, Continuation, Kind>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_multiply)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_unsigned_char_judgment_multiply
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char
											  >
	using nik_safe(PREFIX, s_curried_unsigned_char_judgment_multiply)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_curried_unsigned_char_judgment_multiply
											<Value1, Value2, Continuation, Kind>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_divide)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_unsigned_char_judgment_divide
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char
											  >
	using nik_safe(PREFIX, s_curried_unsigned_char_judgment_divide)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_curried_unsigned_char_judgment_divide
											<Value1, Value2, Continuation, Kind>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_modulo)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_unsigned_char_judgment_modulo
											<Value1, Value2, Continuation, Kind, ListKind>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_s_values,
												typename Kind = unsigned char
											  >
	using nik_safe(PREFIX, s_curried_unsigned_char_judgment_modulo)				= typename snk_unsigned_char_judgment_ss::navigator::template
											  s_curried_unsigned_char_judgment_modulo
											<Value1, Value2, Continuation, Kind>;

//

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_char_judgment_add)		= snk_unsigned_char_judgment_ss::navigator::template
											  a_unsigned_char_judgment_add
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_unsigned_char_judgment_add)	= snk_unsigned_char_judgment_ss::navigator::template
											  a_curried_unsigned_char_judgment_add
											<Value1, Value2, Continuation, Kind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_char_judgment_subtract)	= snk_unsigned_char_judgment_ss::navigator::template
											  a_unsigned_char_judgment_subtract
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_unsigned_char_judgment_subtract)	= snk_unsigned_char_judgment_ss::navigator::template
											  a_curried_unsigned_char_judgment_subtract
											<Value1, Value2, Continuation, Kind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_char_judgment_multiply)	= snk_unsigned_char_judgment_ss::navigator::template
											  a_unsigned_char_judgment_multiply
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_unsigned_char_judgment_multiply)	= snk_unsigned_char_judgment_ss::navigator::template
											  a_curried_unsigned_char_judgment_multiply
											<Value1, Value2, Continuation, Kind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_char_judgment_divide)		= snk_unsigned_char_judgment_ss::navigator::template
											  a_unsigned_char_judgment_divide
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_unsigned_char_judgment_divide)	= snk_unsigned_char_judgment_ss::navigator::template
											  a_curried_unsigned_char_judgment_divide
											<Value1, Value2, Continuation, Kind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,

												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values,

												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_char_judgment_modulo)		= snk_unsigned_char_judgment_ss::navigator::template
											  a_unsigned_char_judgment_modulo
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

											  template
											  <
												typename Value1,
												typename Value2,
												typename Continuation = nik::ch_a_to_value,
												typename Kind = unsigned char,
												typename Image = Kind
											  >
	static constexpr Image nik_safe(PREFIX, a_curried_unsigned_char_judgment_modulo)	= snk_unsigned_char_judgment_ss::navigator::template
											  a_curried_unsigned_char_judgment_modulo
											<Value1, Value2, Continuation, Kind, Image>;

//

#undef PREFIX

#undef snk_unsigned_char_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
