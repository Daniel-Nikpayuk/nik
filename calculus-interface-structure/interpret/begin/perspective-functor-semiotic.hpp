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

struct functor
{
	using kind				= module;

	using type				= functor;

	#include nik_typedef(calculus, interpret, begin, module)
	#include nik_typedef(calculus, interpret, begin, structure)
	#include nik_typedef(calculus, interpret, begin, alias)

/*
	evaluate:
*/

	template<typename...> struct evaluate;

	template<typename Exp, typename... Exps, typename Environment, typename Functor>
	struct evaluate<begin<Exp, Exps...>, Environment, Functor>
	{
				  template<typename... Params>
		using eval	= typename Functor::template evaluate<Params...>;

		//

		using rtn = typename cons
		<
			typename eval<Exp, Environment>::rtn,

			typename evaluate<begin<Exps...>, Environment, Functor>::rtn

		>::rtn;
	};

	template<typename Environment, typename Functor>
	struct evaluate<null_begin, Environment, Functor>
	{
		using rtn = null_begin;
	};
};

