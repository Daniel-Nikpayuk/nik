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

/*
	The default policy for a componentwise expression is lazy evaluation.
	This can be overridden by encapsulating the statement within an act<>:
*/

struct functor
{
	using kind		= module;

	using type		= functor;

	#define safe_name

		#include nik_typedef(calculus, perspective, kernel, functor)

	#undef safe_name

	#include nik_typedef(calculus, kernel, active, structure)

/*
	evaluate:
*/

	template<typename Exp>
	struct evaluate
	{
		using rtn = typename Exp::rtn;
	};

	template<typename Exp>
	struct evaluate<pass<Exp>>
	{
		using rtn = Exp;
	};

/*
	dereference:
*/

	template<typename Exp>
	struct dereference
	{
		using rtn = typename perkef_dereference<typename evaluate<Exp>::rtn>::rtn;
	};

/*
	if_then_else:
*/

	template<bool True, typename Ante, typename Conse>
	struct if_then_else
	{
		using rtn = typename evaluate<Ante>::rtn;
	};

	template<typename Ante, typename Conse>
	struct if_then_else<false, Ante, Conse>
	{
		using rtn = typename evaluate<Conse>::rtn;
	};
};

