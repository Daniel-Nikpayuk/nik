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

				  template
				  <
					typename nik_module(integer32, typedin, calculus, semiotic)::register_type... Values
				  >
	using integer32		= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<Values...>;

				  template
				  <
					typename nik_module(integer32, typedin, calculus, semiotic)::register_type... Values
				  >
	using i32		= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<Values...>;

	using null_integer32	= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<>;

//

	using zero32		= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<0>;

	using one32		= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<1>;

	using two32		= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<2>;

	using three32		= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<3>;

//

	using nibble32		= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<4>;

	using byte32		= typename nik_module(integer32, typedin, calculus, semiotic)::structure::template
				  integer32<8>;

//

#include"undef-size_type.h"

