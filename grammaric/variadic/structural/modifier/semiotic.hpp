/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<Parameter... params>
struct modifier
{
	using base = module::base<params...>;

	using type = modifier;

	using null = modifier<>;

//		Translational:

/*
	lazy type resolution:
*/

	template<typename expression>
	struct modify
	{
		template<typename Tuple> struct coerce;

		template<typename... args>
		struct coerce<module::base<args...>>
		{
			using type = modifier<args...>;
		};

		using type = typename coerce<typename Method::type>::type;
	};

//		Navigational:

	using car = typename base::car;

	using cdr = modify<typename base::cdr>;

//		Generational:

	template<Parameter p>
	using adjoin = modify<typename f_parameter::template adjoin<base, p>>;

	template<typename Modifier>
	using add = modify<typename f_parameter::template add<base, typename Modifier::base>>;

	template<typename Modifier>
	using cross = modify<typename f_parameter::template cross<base, typename Modifier::base>>;

	template<typename Modifier>
	using subtract = modify<typename f_parameter::template subtract<base, typename Modifier::base>>;

	template<typename Ordering>
	using fill = modify<typename f_parameter::template fill<Ordering, base>>;

	template<Parameter from, Parameter to>
	using cast = modify
	<
		typename f_parameter::template add
		<
			typename f_parameter::template subtract
			<
				base,
				module::base<from>

			>::type,

			module::base<to>
		>
	>;

//		Existential:

	template<Parameter p>
	using contains = typename f_parameter::template contains<base, p>;

	template<typename Modifier>
	using covers = typename f_parameter::template covers<base, typename Modifier::base>;

	template<typename... Modifiers>
	using match = typename f_parameter::template match<base, Modifiers...>;

	template<typename... Modifiers>
	using dispatch = typename f_parameter::template dispatch<base, Modifiers...>;

	//

	static void print() { base::print(); }
};

