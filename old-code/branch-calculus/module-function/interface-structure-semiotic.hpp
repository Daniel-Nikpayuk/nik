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

struct structure
{

	template<typename, typename, typename>
	struct memoized_function
	{
		template<typename Continuation>
		using match = typename Continuation::template result<false>;
	};

	// call ( typename  -->  typename ):

	template<template<template<typename> class> class function, template<typename> class F>
	struct memoized_function<universe, universe, function<F>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		template<typename Continuation, typename Value>
		using induct = typename Continuation::template result<universe, universe, function, F, Value>;
	};

	// turn ( typename  -->  builtin ):

		// this case is implemented for theoretical reasons, in practice it is memoization expensive.

		// update: wrong! ch_symbol::result is memoized regardless (sunk cost), so focus this grammar on such cases.

		// F returns a symbol, which is then downcast.

	template<typename Range, template<template<typename> class> class function, template<typename> class F>
	struct memoized_function<universe, Range, function<F>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		template<typename Discontinuation, typename Value>
		static constexpr Range induct = memoized_symbol<F<Value>>::template reduct<Discontinuation>;
	};

/*
	template<typename Range, template<typename> class function, typename F>
	struct memoized_function<universe, Range, function<F>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		template<typename Continuation, typename Value>
		using induct = typename Continuation::template result<Range, F::template result<Value>>;
	};
*/

	// moiz ( builtin  -->  typename ):

	template<typename Domain, template<template<Domain, typename> class> class function, template<Domain, typename> class F>
	struct memoized_function<Domain, universe, function<F>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		template<typename Continuation, Domain Value>
		using induct = F<Value, Continuation>;
	};

	// pose ( builtin  -->  builtin ):

	template<typename Domain, typename Range, template<Range(*)(Domain)> class function, Range(*F)(Domain)>
	struct memoized_function<Domain, Range, function<F>>
	{
		template<typename Continuation>
		using match = typename Continuation::template result<true>;

		template<typename Continuation, Domain Value>
		using induct = typename Continuation::template result<Range, F(Value)>;
	};

	//

	// call ( typename  -->  typename ):

	template<template<typename> class> struct call				{ }; // keyword

	// turn ( typename  -->  builtin ):

	template<template<typename>> struct turn				{ }; // keyword

	// moiz ( builtin  -->  typename ):

		// auto ?

	template<template<void_ptr, typename> class> struct moiz		{ }; // keyword

	// pose ( builtin  -->  builtin ):

	template<void_ptr(*)(void_ptr)> struct pose				{ }; // keyword
};

