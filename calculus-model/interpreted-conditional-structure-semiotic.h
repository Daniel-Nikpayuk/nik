/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

//

				  template<typename... Exps>
	using if_		= typename nik_module(conditional, interpreted, calculus, semiotic)::structure::template
				  if_<Exps...>;

				  template<typename... Exps>
	using cond		= typename nik_module(conditional, interpreted, calculus, semiotic)::structure::template
				  cond<Exps...>;

				  template<typename... Exps>
	using else_		= typename nik_module(conditional, interpreted, calculus, semiotic)::structure::template
				  else_<Exps...>;

//

#include"undef-size_type.h"

