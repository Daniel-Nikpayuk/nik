/************************************************************************************************************************
**
** Copyright 2015-2019 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	The main intention in defining these functions are for grammatical
	formalization, though some of them will be used regularly in practice.
*/

struct functor
{
	using kind		= module;

	using rtn		= functor;

	#include nik_typedef(symbolic, kernel, core, structure)

/*
	echo:
*/

	struct echo
	{
		template<typename Type, Type Value>
		using result = memoized_value<Type, Value>;
	};

/*
	ping:
*/

	template<typename Type>
	using ping = Type;

/*
	dereference:
*/

	template<typename Type>
	using dereference = typename memoized_pointer<Type>::template pop
	<
		ping
	>;
};

