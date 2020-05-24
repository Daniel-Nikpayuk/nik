/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

struct structure
{
	#include nik_symbolic_typedef(patronum, kernel, builtin, inductor)

	// judgement:

	template<typename Type, Type Value>
	using make_judgement = typename dependent_memoization<Type>::template coinduct_values<Value>;

	// pair:

	template<typename Type_A, typename Type_B>
	using make_pair = typename dependent_memoization<Type_A>::template coinduct_type<Type_B>;

	// function:

	template<typename Domain, typename Codomain>
	using make_function = typename dependent_memoization<Domain>::template coinduct_type<Codomain>;
};

