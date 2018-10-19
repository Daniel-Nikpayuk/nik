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

	#define PUSH		varfrf_push
	#define CONSTRUCT	varfrf_construct
	#define LOOKUP		varfrf_lookup

#else

	#define PUSH		push
	#define CONSTRUCT	construct
	#define LOOKUP		lookup

#endif

//

			  template<typename Binding, typename varfrs_Frame>
using PUSH		= typename Frame::functor::template push<Binding, varfrs_Frame>;

			  template<typename Variables, typename Values>
using CONSTRUCT		= typename Frame::functor::template construct<Variables, Values>;

			  template<typename Variable, typename varfrs_Frame>
using LOOKUP		= typename Frame::functor::template lookup<Variable, varfrs_Frame>;

//

#undef PUSH
#undef CONSTRUCT
#undef LOOKUP

