/************************************************************************************************************************
**
** Copyright 2015-2021 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	// pattern match:

		template<typename> struct pattern_match_list;

		template<template<auto...> class ListName, auto... Values>
		struct pattern_match_list<ListName<Values...>>
		{
			template
			<
				template
				<
					template<auto...> class, typename, auto...

				> class Continuation, typename Type, auto... Args
			>
			using induct = Continuation<ListName, Type, Args..., Values...>;
		};

		//

		template<auto...> struct value_list		  { };

		template<typename... Types> using type_list	= value_list<U_type_T<Types>...>;

	// cons:

		template<template<auto...> class ListName, typename _NA_, auto... Values>
		using cons_cont = ListName<Values...>;

		template<typename... Types>
		using cons = typename pattern_match_list<value_list<>>::template induct
		<
			cons_cont, void, U_type_T<Types>...
		>;

	// car:

		template<template<auto...> class ListName, typename _NA_, auto First, auto... Rest>
		using car_cont = T_type_U<First>;

		template<typename List>
		using car = typename pattern_match_list<List>::template induct
		<
			car_cont, void
		>;

	// cdr:

		template<template<auto...> class ListName, typename _NA_, auto First, auto... Rest>
		using cdr_cont = ListName<Rest...>;

		template<typename List>
		using cdr = typename pattern_match_list<List>::template induct
		<
			cdr_cont, void
		>;

	// catenate:

		template<template<auto...> class ListName, typename List2, auto... Values>
		using catenate_cont = typename pattern_match_list<List2>::template induct
		<
			cons_cont, void, Values...
		>;

		template<typename List1, typename List2>
		using catenate = typename pattern_match_list<List1>::template induct
		<
			catenate_cont, List2
		>;

/***********************************************************************************************************************/

	// example:

	int main(int argc, char *argv[])
	{
		using list1	= cons<int, char>;
		using list2	= cons<bool, double, unsigned>;

		using list3	= catenate<list1, list2>; // returns: type_list<int, char, bool, double, unsigned>

		// get the 4th value of the list (== double):

		using list_val	= car<
				    cdr<
				      cdr<
				        cdr<
					  list3>>>>;

		printf("%s\n", V_equal_TxT<list_val, bool> ? "true" : "false");		// prints: false
		printf("%s\n", V_equal_TxT<list_val, double> ? "true" : "false");	// prints: true

		return 0;
	}

