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

#include"define-size_type.h"

#define pnk_builtin_ss nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)
#define snk__ss nik_module(straticum, natural, kernel, , symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snk_structure_ss_

#else

	#define PREFIX

#endif

//

	bool
	char
	unsigned char
	signed char
	wchar_t
	char16_t
	char32_t
	unsigned short
	signed short
	unsigned int
	signed int
	unsigned long
	signed long
	unsigned long long
	signed long long

	bool
	char
	unsigned_char
	signed_char
	wchar_t
	char16_t
	char32_t
	unsigned_short
	signed_short
	unsigned_int
	signed_int
	unsigned_long
	signed_long
	unsigned_long_long
	signed_long_long


										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_symbolic_value
										  >
	using nik_safe(PREFIX, s_)						= typename snk__ss::structure::template
										  s_<Type, Continuation>;

//

	bool
	char
	unsigned char
	signed char
	wchar_t
	char16_t
	char32_t
	unsigned short
	signed short
	unsigned int
	signed int
	unsigned long
	signed long
	unsigned long long
	signed long long

	bool
	char
	unsigned_char
	signed_char
	wchar_t
	char16_t
	char32_t
	unsigned_short
	signed_short
	unsigned_int
	signed_int
	unsigned_long
	signed_long
	unsigned_long_long
	signed_long_long


										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_assemblic_value
										  >
	static constexpr nik_safe(PREFIX, a_)					= snk__ss::structure::template
										  a_<Type, Continuation>;

//

#undef PREFIX

#undef snk__ss
#undef pnk_builtin_ss

#include"undef-size_type.h"

