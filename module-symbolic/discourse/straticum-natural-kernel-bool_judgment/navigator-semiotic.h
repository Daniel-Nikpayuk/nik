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

	#define PREFIX		snkbj_navigator_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Value,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment
										  >
	using nik_safe(PREFIX, s_bool_judgment_not)				= typename snk_bool_judgment_ss::navigator::template
										  s_bool_judgment_not
											<Value, Continuation, Kind, ListKind>;

										  template
										  <
											typename Value,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_bool_judgment_not)			= typename snk_bool_judgment_ss::navigator::template
										  s_curried_bool_judgment_not
											<Value, Continuation, Kind>;

										  template
										  <
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment
										  >
	using nik_safe(PREFIX, s_bool_judgment_and)				= typename snk_bool_judgment_ss::navigator::template
										  s_bool_judgment_and
											<Value1, Value2, Continuation, Kind, ListKind>;

										  template
										  <
											typename Value1, typename Value2,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_bool_judgment_and)			= typename snk_bool_judgment_ss::navigator::template
										  s_curried_bool_judgment_and
											<Value1, Value2, Continuation, Kind>;

										  template
										  <
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment
										  >
	using nik_safe(PREFIX, s_bool_judgment_or)				= typename snk_bool_judgment_ss::navigator::template
										  s_bool_judgment_or
											<Value1, Value2, Continuation, Kind, ListKind>;

										  template
										  <
											typename Value1, typename Value2,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_bool_judgment_or)			= typename snk_bool_judgment_ss::navigator::template
										  s_curried_bool_judgment_or
											<Value1, Value2, Continuation, Kind>;

										  template
										  <
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment
										  >
	using nik_safe(PREFIX, s_bool_judgment_implies)				= typename snk_bool_judgment_ss::navigator::template
										  s_bool_judgment_implies
											<Value1, Value2, Continuation, Kind, ListKind>;

										  template
										  <
											typename Value1, typename Value2,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_bool_judgment_implies)			= typename snk_bool_judgment_ss::navigator::template
										  s_curried_bool_judgment_implies
											<Value1, Value2, Continuation, Kind>;

										  template
										  <
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment
										  >
	using nik_safe(PREFIX, s_bool_judgment_equivalent)			= typename snk_bool_judgment_ss::navigator::template
										  s_bool_judgment_equivalent
											<Value1, Value2, Continuation, Kind, ListKind>;

										  template
										  <
											typename Value1, typename Value2,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_bool_judgment_equivalent)		= typename snk_bool_judgment_ss::navigator::template
										  s_curried_bool_judgment_equivalent
											<Value1, Value2, Continuation, Kind>;

//

										  template
										  <
											typename Value,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_bool_judgment_not)		= snk_bool_judgment_ss::navigator::template
										  a_bool_judgment_not
											<Value, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Value,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_bool_judgment_not)	= snk_bool_judgment_ss::navigator::template
										  a_curried_bool_judgment_not
											<Value, Continuation, Kind, Image>;

										  template
										  <
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_bool_judgment_and)		= snk_bool_judgment_ss::navigator::template
										  a_bool_judgment_and
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Value1, typename Value2,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_bool_judgment_and)	= snk_bool_judgment_ss::navigator::template
										  a_curried_bool_judgment_and
											<Value1, Value2, Continuation, Kind, Image>;

										  template
										  <
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_bool_judgment_or)		= snk_bool_judgment_ss::navigator::template
										  a_bool_judgment_or
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Value1, typename Value2,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_bool_judgment_or)	= snk_bool_judgment_ss::navigator::template
										  a_curried_bool_judgment_or
											<Value1, Value2, Continuation, Kind, Image>;

										  template
										  <
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_bool_judgment_implies)	= snk_bool_judgment_ss::navigator::template
										  a_bool_judgment_implies
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Value1, typename Value2,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_bool_judgment_implies) = snk_bool_judgment_ss::navigator::template
										  a_curried_bool_judgment_implies
											<Value1, Value2, Continuation, Kind, Image>;

										  template
										  <
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											snk_bool_judgment_as::inductor::template
											pattern_match_bool_judgment,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_bool_judgment_equivalent)	= snk_bool_judgment_ss::navigator::template
										  a_bool_judgment_equivalent
											<Value1, Value2, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Value1, typename Value2,
											typename Continuation = nik::ch_s_values,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_bool_judgment_equivalent) = snk_bool_judgment_ss::navigator::template
										  a_curried_bool_judgment_equivalent
											<Value1, Value2, Continuation, Kind, Image>;

//

#undef PREFIX

#undef snk_bool_judgment_ss
#undef snk_bool_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
