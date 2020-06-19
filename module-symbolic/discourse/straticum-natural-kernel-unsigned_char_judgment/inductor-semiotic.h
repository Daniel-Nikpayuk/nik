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

#define snk_unsigned_char_judgment_ss nik_module(straticum, natural, kernel, unsigned_char_judgment, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		snkucj_inductor_ss_

#else

	#define PREFIX

#endif

//

										  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_unsigned_char_judgment)			= typename snk_unsigned_char_judgment_ss::inductor::template
										  pattern_match_unsigned_char_judgment<Exp>;

										  template<typename Exp>
	using nik_safe(PREFIX, pattern_match_curried_unsigned_char_judgment)		= typename snk_unsigned_char_judgment_ss::inductor::template
										  pattern_match_curried_unsigned_char_judgment<Exp>;

//

#undef PREFIX

#undef snk_unsigned_char_judgment_ss

#include nik_size_type(undef)
