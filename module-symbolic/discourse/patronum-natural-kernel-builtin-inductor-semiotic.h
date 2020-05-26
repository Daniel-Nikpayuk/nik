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

#ifdef safe_name

	#define PREFIX		pnk_builtin_ss_

#else

	#define PREFIX

#endif

//

							  template<typename Type>
	using nik_safe(PREFIX, dependent_memoization)	= typename nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)::
							  inductor::template dependent_memoization<Type>;

//

	using nik_safe(PREFIX, ch_dependent_type)	= typename nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)::
							  inductor::ch_dependent_type;

	using nik_safe(PREFIX, ch_symbolic_type)	= typename nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)::
							  inductor::ch_symbolic_type;

	using nik_safe(PREFIX, ch_symbolic_value)	= typename nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)::
							  inductor::ch_symbolic_value;

	using nik_safe(PREFIX, ch_assemblic_value)	= typename nik_module(patronum, natural, kernel, builtin, symbolic, semiotic)::
							  inductor::ch_assemblic_value;

//

#undef PREFIX

#include"undef-size_type.h"

