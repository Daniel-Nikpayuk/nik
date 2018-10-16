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

	#define NOT		conbof_Not
	#define AND		conbof_And
	#define OR		conbof_Or

#else

	#define NOT		Not
	#define AND		And
	#define OR		Or

#endif

//

			  template<typename Exp>
using NOT		= typename Boolean::functor::template Not<Exp>;

			  template<typename Exp, typename... Exps>
using AND		= typename Boolean::functor::template And<Exp, Exps...>;

			  template<typename Exp, typename... Exps>
using OR		= typename Boolean::functor::template Or<Exp, Exps...>;

//

#undef NOT
#undef AND
#undef OR
