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

	#define PREFIX		pk_builtin_ss_

#else

	#define PREFIX

#endif

//

							  template<typename Type, Type Value>
	using nik_safe(PREFIX, make_judgement)		= typename nik_language(patronum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_judgement<Type, Value>;

							  template<typename Type_A, typename Type_B>
	using nik_safe(PREFIX, make_pair)		= typename nik_language(patronum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_pair<Type_A, Type_B>;

							  template<typename Domain, typename Codomain>
	using nik_safe(PREFIX, make_function)		= typename nik_language(patronum, kernel, builtin, symbolic, semiotic)::
							  structure::template make_function<Domain, Codomain>;

//

#undef PREFIX

#include"undef-size_type.h"

