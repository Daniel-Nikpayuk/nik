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
	using kind						= module;

	using type						= functor;

	#include nik_typedef(calculus, builtin, constant, module)
	#include nik_typedef(calculus, builtin, constant, structure)

	template<typename...> struct apply;

/*
	Arithmetic operators

	+ (addition)
	- (subtraction)
	* (multiplication)
	/ (division)
	% (modulus)
*/

	template<register_type Value1, register_type Value2>
	struct apply
	<
		op<'+'>,

		integer32<Value1>,
		integer32<Value2>
	>
	{
		using rtn = integer32<(Value1 + Value2)>;
	};

/*
	display:

	As there is no (direct/builtin) compile time screen in C++,
	there is no loss implementing as run time here.
*/

	template<register_type Value>
	inline static void display(const integer32<Value> &)
	{
		printf("%s", "integer32: ");
		calculus::functor::display(Value);
	}
};

