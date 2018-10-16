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

#ifdef safe_name

	#define LENGTH		calpef_length
	#define SIGN		calpef_sign
	#define REGISTER_TYPE	calpef_register_type
	#define HALF_TYPE	calpef_half_type

#else

	#define LENGTH		length
	#define SIGN		sign
	#define REGISTER_TYPE	register_type
	#define HALF_TYPE	half_type

#endif

//

using Sign			= typename calculus::functor::Sign;

//

				  template<typename RegType, typename SizeType = global_size_type>
using LENGTH			= typename calculus::functor::template length<RegType, SizeType>;

				  template<typename RegType>
using SIGN			= typename calculus::functor::template sign<RegType>;

				  template<global_size_type N, Sign sign>
using REGISTER_TYPE		= typename calculus::functor::template register_type<N, sign>;


#define ONE 1

				  template<global_size_type N, Sign sign>
using HALF_TYPE			= register_type<(N >> ONE), sign>;

#undef ONE

//

#undef LENGTH
#undef SIGN
#undef REGISTER_TYPE
#undef HALF_TYPE

