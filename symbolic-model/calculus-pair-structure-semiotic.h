/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

							  template<typename Exp>
	using pattern_match_builtin_builtin_pair	= typename nik_module(pair, calculus, symbolic, semiotic)::structure::template
							  pattern_match_builtin_builtin_pair<Exp>;

							  template<typename Exp>
	using pattern_match_builtin_typename_pair	= typename nik_module(pair, calculus, symbolic, semiotic)::structure::template
							  pattern_match_builtin_typename_pair<Exp>;

							  template<typename Exp>
	using pattern_match_typename_builtin_pair	= typename nik_module(pair, calculus, symbolic, semiotic)::structure::template
							  pattern_match_typename_builtin_pair<Exp>;

							  template<typename Exp>
	using pattern_match_typename_typename_pair	= typename nik_module(pair, calculus, symbolic, semiotic)::structure::template
							  pattern_match_typename_typename_pair<Exp>;

#include"undef-size_type.h"

