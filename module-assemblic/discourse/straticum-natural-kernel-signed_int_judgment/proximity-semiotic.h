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
#define snk_signed_int_judgment_as nik_module(straticum, natural, kernel, signed_int_judgment, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snksij_proximity_as_

#else

	#define PREFIX

#endif

//

											  template
											  <
												signed int Value1,
												signed int Value2,

												typename Continuation = nik::ch_s_values
											  >
	using nik_safe(PREFIX, s_signed_int_judgment_less_than)			= typename snk_signed_int_judgment_as::proximity::template
											  s_signed_int_judgment_less_than
												<Value1, Value2, Continuation>;

											  template
											  <
												signed int Value1,
												signed int Value2,

												typename Continuation = nik::ch_s_values
											  >
	using nik_safe(PREFIX, s_signed_int_judgment_less_than_or_equal)		= typename snk_signed_int_judgment_as::proximity::template
											  s_signed_int_judgment_less_than_or_equal
												<Value1, Value2, Continuation>;

											  template
											  <
												signed int Value1,
												signed int Value2,

												typename Continuation = nik::ch_s_values
											  >
	using nik_safe(PREFIX, s_signed_int_judgment_greater_than)			= typename snk_signed_int_judgment_as::proximity::template
											  s_signed_int_judgment_greater_than
												<Value1, Value2, Continuation>;

											  template
											  <
												signed int Value1,
												signed int Value2,

												typename Continuation = nik::ch_s_values
											  >
	using nik_safe(PREFIX, s_signed_int_judgment_greater_than_or_equal)		= typename snk_signed_int_judgment_as::proximity::template
											  s_signed_int_judgment_greater_than_or_equal
												<Value1, Value2, Continuation>;

//

	static constexpr bool (*nik_safe(PREFIX, p_signed_int_judgment_less_than))(signed int, signed int) =
		snk_signed_int_judgment_as::proximity::p_signed_int_judgment_less_than;

	static constexpr bool (*nik_safe(PREFIX, p_signed_int_judgment_less_than_or_equal))(signed int, signed int) =
		snk_signed_int_judgment_as::proximity::p_signed_int_judgment_less_than_or_equal;

	static constexpr bool (*nik_safe(PREFIX, p_signed_int_judgment_greater_than))(signed int, signed int) =
		snk_signed_int_judgment_as::proximity::p_signed_int_judgment_greater_than;

	static constexpr bool (*nik_safe(PREFIX, p_signed_int_judgment_greater_than_or_equal))(signed int, signed int) =
		snk_signed_int_judgment_as::proximity::p_signed_int_judgment_greater_than_or_equal;

//

#undef PREFIX

#undef snk_signed_int_judgment_as
#undef pnk_builtin_ss

#include nik_size_type(undef)
