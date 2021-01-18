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

#define snk_char_list_as nik_module(straticum, natural, kernel, char_list, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snkcl_inductor_as_

#else

	#define PREFIX

#endif

//

										  template<typename Type>
	using nik_safe(PREFIX, pattern_match_char_list)			= typename snk_char_list_as::inductor::template
										  pattern_match_char_list<Type>;

//

#undef PREFIX

#undef snk_char_list_as

#include nik_size_type(undef)
