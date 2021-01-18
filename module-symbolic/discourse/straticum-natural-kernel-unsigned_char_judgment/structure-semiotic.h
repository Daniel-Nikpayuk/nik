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

	#define PREFIX		snkucj_structure_ss_

#else

	#define PREFIX

#endif

//

										  template
										  <
											typename Type, typename Exp,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_s_grow_to_values
										  >
	using nik_safe(PREFIX, s_unsigned_char_judgment_)					= typename snk_unsigned_char_judgment_ss::structure::template
										  s_unsigned_char_judgment_<Type, Exp, Continuation>;

//

										  template
										  <
											typename Type,

											typename Continuation =
											typename pnk_builtin_ss::inductor::
											ch_a_grow_to_value,

											typename Image = Type
										  >
	static constexpr Image nik_safe(PREFIX, a_unsigned_char_judgment_)		= snk_unsigned_char_judgment_ss::structure::template
										  a_unsigned_char_judgment_<Type, Continuation, Image>;

//

#undef PREFIX

#undef snk_unsigned_char_judgment_ss
#undef pnk_builtin_ss

#include nik_size_type(undef)
