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
#define snk_unsigned_short_judgment_as nik_module(straticum, natural, kernel, unsigned_short_judgment, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkusj_identity_as_

#else

	#define PREFIX

#endif

//

											  template
											  <
												unsigned short Value1,
												unsigned short Value2,

												typename Continuation =
												typename pnk_builtin_ss::inductor::
												ch_s_match_to_value,

												typename Kind = bool,

												template<Kind...> class ListKind =
												pnk_builtin_ss::inductor::template
												dependent_memoization<Kind>::template
												pattern_match_values
											  >
	using nik_safe(PREFIX, s_unsigned_short_judgment_is_equal)					= typename snk_unsigned_short_judgment_as::identity::template
											  s_unsigned_short_judgment_is_equal
											<Value1, Value2, Continuation, Kind, ListKind>;

//

	static constexpr bool (*nik_safe(PREFIX, p_unsigned_short_judgment_is_equal))(unsigned short, unsigned short) =
		snk_unsigned_short_judgment_as::identity::p_unsigned_short_judgment_is_equal;

//

#undef PREFIX

#undef snk_unsigned_short_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
