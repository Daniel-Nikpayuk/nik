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
	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

struct printer
{
	#include nik_unpack_typedef(module)
	#include nik_unpack_typedef(structure)
	#include nik_unpack_typedef(alias)

/*
	char:
*/

	template<typename Exp, typename... Exps>
	inline static void display(const tuple<Exp, Exps...> & t)
	{
		printf("%s", "tuple:  ");

		re_display(t);
	}

	inline static void display(const null_tuple &)
	{
		printf("%s", "tuple:  null\n");
	}

	template<typename Exp, typename... Exps>
	inline static void re_display(const tuple<Exp, Exps...> &)
	{
		using Exp_is_constant	= typename is_constant<Exp>::rtn;
		using Exps_are_null	= typename identity::template is_null<tuple<Exps...>>::rtn;

		using dispatch = typename evaluate
		<
			if_then
			<
				Exp_is_constant,
				typename Constant::printer

			>, then
			<
				printer
			>

		>::rtn;

		char l = Exp_is_constant::value ? '(' : '[';
		char r = Exp_is_constant::value ? ')' : ']';

		printf("%c", l);
		dispatch::display(Exp());
		printf("%c", r);

		if (!Exps_are_null::value) printf("%s", "  ");

		re_display(tuple<Exps...>());
	}

	inline static void re_display(const null_tuple &)
	{
		// print nothing.
	}
};

