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

	#define PREFIX		pk_builtin_as_

#else

	#define PREFIX

#endif

//

									  template<const char* (*type_literal)()>
	static constexpr auto nik_safe(PREFIX, display_type_literal)	= nik_language(patronum, kernel, builtin, assemblic, semiotic)::
									  embedding::template display_type_literal<type_literal>;

//

#undef PREFIX

#include"undef-size_type.h"
