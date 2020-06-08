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

	#define PREFIX		pnkb_inductor_ss_

#else

	#define PREFIX

#endif

//

	using nik_safe(PREFIX, ch_symbolic_type)					= typename pnk_builtin_ss::inductor::
											  ch_symbolic_type;

	using nik_safe(PREFIX, ch_symbolic_types)					= typename pnk_builtin_ss::inductor::
											  ch_symbolic_types;

	using nik_safe(PREFIX, ch_symbolic_values)					= typename pnk_builtin_ss::inductor::
											  ch_symbolic_values;

	using nik_safe(PREFIX, ch_assemblic_value)					= typename pnk_builtin_ss::inductor::
											  ch_assemblic_value;

//

											  template<typename Type>
	using nik_safe(PREFIX, dependent_memoization)					= typename pnk_builtin_ss::inductor::template
											  dependent_memoization<Type>;

//

#undef PREFIX

#undef pnk_builtin_ss

#include nik_size_type(undef)
