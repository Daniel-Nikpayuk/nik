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

#define pnk_typename_stem_ss nik_module(patronum, natural, kernel, typename_stem, symbolic, semiotic)

#ifdef safe_name

	#define PREFIX		pnkts_inductor_ss_

#else

	#define PREFIX

#endif

//

										  template<typename Type>
	using nik_safe(PREFIX, pattern_match_typename_stem)			= typename pnk_typename_stem_ss::inductor::template
										  pattern_match_typename_stem<Type>;

//

#undef PREFIX

#undef pnk_typename_stem_ss

#include nik_size_type(undef)
