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

#ifdef safe_name

	#define PREFIX		pnkb_embedding_ss_

#else

	#define PREFIX

#endif

//

									  template
									  <
										typename Type,
										template<typename> class Op,
										typename Continuation = nik::ch_a_to_value,
										typename Kind = const char*
									  >
	using nik_safe(PREFIX, s_type_literal)				= typename pnk_builtin_ss::embedding::template
									  s_type_literal<Type, Op, Continuation, Kind>;

//

									  template
									  <
										typename Type,
										template<typename> class Op,
										typename Continuation = nik::ch_a_to_value,
										typename Kind = const char*,
										typename Image = Kind
									  >
	static constexpr Image nik_safe(PREFIX, a_type_literal)		= pnk_builtin_ss::embedding::template
									  a_type_literal<Type, Op, Continuation, Kind, Image>;

//

#undef PREFIX

#undef pnk_builtin_ss

#include nik_size_type(undef)
