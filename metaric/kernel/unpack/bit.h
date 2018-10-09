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

#ifdef name_safe

	#define LENGTH		met_kern_length
	#define SIGN		met_kern_sign
	#define REGISTER_TYPE	met_kern_register_type
	#define HALF_TYPE	met_kern_half_type

#else

	#define LENGTH		length
	#define SIGN		sign
	#define REGISTER_TYPE	register_type
	#define HALF_TYPE	half_type

#endif

#ifdef local_scope

	#define SIZE_TYPE size_type

#else

	#define SIZE_TYPE nik::global_size_type

#endif

//

				  template<typename RegType>
using LENGTH			= typename Kernel::bit::template length<RegType>;

				  template<typename RegType>
using SIGN			= typename Kernel::bit::template sign<RegType>;

				  template<SIZE_TYPE N, Sign sign>
using REGISTER_TYPE		= typename Kernel::bit::template register_type<N, sign>;


#define ONE 1

				  template<SIZE_TYPE N, Sign sign>
using HALF_TYPE			= register_type<(N >> ONE), sign>;

#undef ONE

//

#undef LENGTH
#undef SIGN
#undef REGISTER_TYPE
#undef HALF_TYPE

