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

							  template<typename Type, Type Value>
	using builtin_inl				= typename nik_module(copair, calculus, symbolic, semiotic)::structure::template
							  builtin_inl<Type, Value>;

							  template<typename Type, Type Value>
	using builtin_inr				= typename nik_module(copair, calculus, symbolic, semiotic)::structure::template
							  builtin_inr<Type, Value>;

//

							  template<typename Value>
	using typename_inl				= typename nik_module(copair, calculus, symbolic, semiotic)::structure::template
							  typename_inl<Value>;

							  template<typename Value>
	using typename_inr				= typename nik_module(copair, calculus, symbolic, semiotic)::structure::template
							  typename_inr<Value>;

//

							  template<typename Exp>
	using pattern_match_builtin_copair		= typename nik_module(copair, calculus, symbolic, semiotic)::structure::template
							  pattern_match_builtin_copair<Exp>;

							  template<typename Exp>
	using pattern_match_typename_copair		= typename nik_module(copair, calculus, symbolic, semiotic)::structure::template
							  pattern_match_typename_copair<Exp>;

#include"undef-size_type.h"

