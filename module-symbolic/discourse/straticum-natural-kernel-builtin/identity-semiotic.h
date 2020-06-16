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
#define snk_builtin_ss nik_module(straticum, natural, kernel, builtin, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkb_identity_ss_

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
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_bool)					= typename snk_builtin_ss::identity::template
										  s_is_bool<Exp, Continuation, Kind, ListKind>;

//

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_char)				= typename snk_builtin_ss::identity::template
										  s_is_unsigned_char<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_signed_char)				= typename snk_builtin_ss::identity::template
										  s_is_signed_char<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_short)				= typename snk_builtin_ss::identity::template
										  s_is_unsigned_short<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_signed_short)				= typename snk_builtin_ss::identity::template
										  s_is_signed_short<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_int)				= typename snk_builtin_ss::identity::template
										  s_is_unsigned_int<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_signed_int)					= typename snk_builtin_ss::identity::template
										  s_is_signed_int<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_long)				= typename snk_builtin_ss::identity::template
										  s_is_unsigned_long<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_signed_long)				= typename snk_builtin_ss::identity::template
										  s_is_signed_long<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_unsigned_long_long)				= typename snk_builtin_ss::identity::template
										  s_is_unsigned_long_long<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_signed_long_long)				= typename snk_builtin_ss::identity::template
										  s_is_signed_long_long<Exp, Continuation, Kind, ListKind>;

//

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_char)					= typename snk_builtin_ss::identity::template
										  s_is_char<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_wchar_t)					= typename snk_builtin_ss::identity::template
										  s_is_wchar_t<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_char16_t)					= typename snk_builtin_ss::identity::template
										  s_is_char16_t<Exp, Continuation, Kind, ListKind>;

										  template
										  <
											typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_match_to_value,

											typename Kind = bool,

											template<Kind...> class ListKind =
											pnk_builtin_ss::inductor::template
											dependent_memoization<Kind>::template
											pattern_match_values
										  >
	using nik_safe(PREFIX, s_is_char32_t)					= typename snk_builtin_ss::identity::template
										  s_is_char32_t<Exp, Continuation, Kind, ListKind>;

//

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_bool)			= snk_builtin_ss::identity::template
										  a_is_bool<Exp, Continuation, Image>;

//

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_unsigned_char)		= snk_builtin_ss::identity::template
										  a_is_unsigned_char<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_signed_char)		= snk_builtin_ss::identity::template
										  a_is_signed_char<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_unsigned_short)		= snk_builtin_ss::identity::template
										  a_is_unsigned_short<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_signed_short)		= snk_builtin_ss::identity::template
										  a_is_signed_short<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_unsigned_int)		= snk_builtin_ss::identity::template
										  a_is_unsigned_int<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_signed_int)			= snk_builtin_ss::identity::template
										  a_is_signed_int<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_unsigned_long)		= snk_builtin_ss::identity::template
										  a_is_unsigned_long<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_signed_long)		= snk_builtin_ss::identity::template
										  a_is_signed_long<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_unsigned_long_long)		= snk_builtin_ss::identity::template
										  a_is_unsigned_long_long<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_signed_long_long)		= snk_builtin_ss::identity::template
										  a_is_signed_long_long<Exp, Continuation, Image>;

//

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_char)			= snk_builtin_ss::identity::template
										  a_is_char<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_wchar_t)			= snk_builtin_ss::identity::template
										  a_is_wchar_t<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_char16_t)			= snk_builtin_ss::identity::template
										  a_is_char16_t<Exp, Continuation, Image>;

										  template
										  <
											typename Exp,
											typename Continuation = nik::ch_a_value,
											typename Image = bool
										  >
	static constexpr Image nik_safe(PREFIX, a_is_char32_t)			= snk_builtin_ss::identity::template
										  a_is_char32_t<Exp, Continuation, Image>;

//

#undef PREFIX

#undef snk_builtin_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
