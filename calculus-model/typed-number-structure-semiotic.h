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

				  template<SIZE_TYPE... Values>
	using number		= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<Values...>;

				  template<SIZE_TYPE... Values>
	using n			= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<Values...>;

	using null_number	= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<>;

//

	using zero		= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<0>;

	using one		= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<1>;

	using two		= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<2>;

	using three		= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<3>;

//

	using nibble		= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<4>;

	using byte		= typename nik_module(number, typedin, calculus, semiotic)::structure::template
				  number<8>;

//

#include"undef-size_type.h"

