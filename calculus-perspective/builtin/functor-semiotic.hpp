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
	using kind	= branch;

	using type	= functor;

	#include nik_unpack(../.., calculus, kernel, act, structure)

/*
	cons:
*/

	template<typename Type, Type, typename> struct cons;

	template<typename Type, Type Exp, Type... Exps, template<Type...> class ListType>
	struct cons<Type, Exp, ListType<Exps...>>
	{
		using rtn = ListType<Exp, Exps...>;
	};

	template<typename Type, Type Exp1, typename Exp2>
	struct cons<Type, Exp1, act<Exp2>>
	{
		using rtn = typename cons<Type, Exp1, typename Exp2::rtn>::rtn;
	};

/*
	car:
*/

	template<typename Type, typename> struct car;

	template<typename Type, Type Exp, Type... Exps, template<Type...> class ListType>
	struct car<Type, ListType<Exp, Exps...>>
	{
		static constexpr Type value		= Exp;
	};

	template<typename Type, typename Exp>
	struct car<Type, act<Exp>>
	{
		using rtn = typename car<Type, typename Exp::rtn>::rtn;
	};

/*
	cdr:
*/

	template<typename Type, typename> struct cdr;

	template<typename Type, Type Exp, Type... Exps, template<Type...> class ListType>
	struct cdr<Type, ListType<Exp, Exps...>>
	{
		using rtn = ListType<Exps...>;
	};

	template<typename Type, typename Exp>
	struct cdr<Type, act<Exp>>
	{
		using rtn = typename cdr<Type, typename Exp::rtn>::rtn;
	};

/*
	limits:
*/

	#include"functor-limits-semiotic.hpp"

/*
	unsigned_type:
*/

	#include"functor-unsigned_type-semiotic.hpp"

/*
	signed_type:
*/

	#include"functor-signed_type-semiotic.hpp"

/*
	apply:
*/

	#include"functor-apply-semiotic.hpp"

/*
	display:
*/

	#include"functor-display-semiotic.hpp"
};

