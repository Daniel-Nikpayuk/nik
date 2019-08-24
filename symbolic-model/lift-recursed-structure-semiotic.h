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

//

				  template<typename Exp>
	using type		= typename nik_module(recursed, lift, symbolic, semiotic)::structure::template
				  type<Exp>;

				  template<typename... Exps>
	using list		= typename nik_module(recursed, lift, symbolic, semiotic)::structure::template
				  list<Exps...>;

	using null_list		= typename nik_module(recursed, lift, symbolic, semiotic)::structure::template
				  list<>;

//

				  template<typename Pred, typename Exp>
	using if_then		= typename nik_module(conditional, lift, symbolic, semiotic)::structure::template
				  if_then<Pred, Exp>;

				  template<typename Pred, typename Exp>
	using else_then		= typename nik_module(conditional, lift, symbolic, semiotic)::structure::template
				  else_then<Pred, Exp>;

				  template<typename Exp>
	using then		= typename nik_module(conditional, lift, symbolic, semiotic)::structure::template
				  then<Exp>;

//

#include"undef-size_type.h"

