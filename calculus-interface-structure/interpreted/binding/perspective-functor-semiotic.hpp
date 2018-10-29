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
	using kind		= module;

	using type		= functor;

	#include nik_typedef(calculus, typedin, boolean, identity)

	#include nik_typedef(calculus, evaltin, binding, structure)

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<typename Variable, typename... Values>
	inline static void display(const binding<Variable, Values...> & b)
	{
		using is_empty = typename is_null<binding<Values...>>::rtn;

		Builtin::functor::display("binding: ");
		Variable::kind::functor::display(Variable());

		if (!is_empty::value) Dispatched::functor::display(binding<Values...>(), ", ");
	}

	inline static void display(const null_binding &)
	{
		Builtin::functor::display("binding: null");
	}
};

