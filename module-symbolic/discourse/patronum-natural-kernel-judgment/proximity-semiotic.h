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

	#define PREFIX		pnkj_proximity_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_judgment_less_than)				= typename pnk_judgment_ss::proximity::template
										  s_judgment_less_than
											<Type, Value1, Value2, Continuation, Kind, ListKind>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_judgment_less_than)			= typename pnk_judgment_ss::proximity::template
										  s_curried_judgment_less_than
											<Type, Value1, Value2, Continuation, Kind>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_judgment_less_than_or_equal)			= typename pnk_judgment_ss::proximity::template
										  s_judgment_less_than_or_equal
											<Type, Value1, Value2, Continuation, Kind, ListKind>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_judgment_less_than_or_equal)		= typename pnk_judgment_ss::proximity::template
										  s_curried_judgment_less_than_or_equal
											<Type, Value1, Value2, Continuation, Kind>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_judgment_greater_than)				= typename pnk_judgment_ss::proximity::template
										  s_judgment_greater_than
											<Type, Value1, Value2, Continuation, Kind, ListKind>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_judgment_greater_than)			= typename pnk_judgment_ss::proximity::template
										  s_curried_judgment_greater_than
											<Type, Value1, Value2, Continuation, Kind>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_judgment_greater_than_or_equal)		= typename pnk_judgment_ss::proximity::template
										  s_judgment_greater_than_or_equal
											<Type, Value1, Value2, Continuation, Kind, ListKind>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_s_values,
											typename Kind = bool
										  >
	using nik_safe(PREFIX, s_curried_judgment_greater_than_or_equal)	= typename pnk_judgment_ss::proximity::template
										  s_curried_judgment_greater_than_or_equal
											<Type, Value1, Value2, Continuation, Kind>;

//

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_less_than)		= pnk_judgment_ss::proximity::template
										  a_judgment_less_than
										<Type, Value1, Value2, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_judgment_less_than)	= pnk_judgment_ss::proximity::template
										  a_curried_judgment_less_than
											<Type, Value1, Value2, Continuation, Kind, Image>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_less_than_or_equal)	= pnk_judgment_ss::proximity::template
										  a_judgment_less_than_or_equal
										<Type, Value1, Value2, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_judgment_less_than_or_equal)	= pnk_judgment_ss::proximity::template
										  a_curried_judgment_less_than_or_equal
											<Type, Value1, Value2, Continuation, Kind, Image>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_greater_than)	= pnk_judgment_ss::proximity::template
										  a_judgment_greater_than
										<Type, Value1, Value2, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_judgment_greater_than)	= pnk_judgment_ss::proximity::template
										  a_curried_judgment_greater_than
											<Type, Value1, Value2, Continuation, Kind, Image>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values,

											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_judgment_greater_than_or_equal) = pnk_judgment_ss::proximity::template
										  a_judgment_greater_than_or_equal
										<Type, Value1, Value2, Continuation, Kind, ListKind, Image>;

										  template
										  <
											typename Type,
											typename Value1, typename Value2,

											typename Continuation = nik::ch_a_to_value,
											typename Kind = bool,
											typename Image = Kind
										  >
	static constexpr Image nik_safe(PREFIX, a_curried_judgment_greater_than_or_equal)	= pnk_judgment_ss::proximity::template
										  a_curried_judgment_greater_than_or_equal
											<Type, Value1, Value2, Continuation, Kind, Image>;

//

#undef PREFIX

#undef pnk_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
