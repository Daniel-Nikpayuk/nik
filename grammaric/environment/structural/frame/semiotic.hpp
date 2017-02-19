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

template<typename... bindings>
struct frame
{
	using t = module::t<bindings...>;

	using rtn = frame;

	using null = frame<>;

	//

	template<typename expression>
	struct enframe
	{
		template<typename Base> struct coerce;

		template<typename... args>
		struct coerce<module::t<args...>>
		{
			using rtn = frame<args...>;
		};

		using rtn = typename coerce<typename expression::rtn>::rtn;
	};

//		Navigational:

	using binding = typename t::car;

	using enclosing = enframe<typename t::cdr>;

//		Existential:

//	using value = typename functional::template find<variable>::type;

//		Generational:

	template<typename variable, typename type>
	using add_binding = enframe
	<
		typename t::template cons
		<
			module::binding<variable, type>
		>
	>;

//		Translational:

};

using null_frame = frame<>;

