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

#define snk_signed_short_judgement_as nik_module(straticum, natural, kernel, signed_short_judgement, assemblic, semiotic)

#ifdef safe_name

	#define PREFIX		snks_inductor_as_

#else

	#define PREFIX

#endif

//

										  template<typename Type>
	using nik_safe(PREFIX, pattern_match_signed_short_judgement)			= typename snk_signed_short_judgement_as::inductor::template
										  pattern_match_signed_short_judgement<Type>;

//

#undef PREFIX

#undef snk_signed_short_judgement_as

#include"undef-size_type.h"
