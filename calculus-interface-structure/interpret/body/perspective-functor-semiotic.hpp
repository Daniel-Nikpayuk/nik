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

	#include nik_typedef(calculus, lambda, compound, module)
	#include nik_typedef(calculus, lambda, compound, structure)

	template<typename...> struct evaluate;

/*
	template<>
	struct evaluate
	<
		body<>,
		environment<>,
		typename default_functor = undefined::functor
	>
	{
	};

	template<>
	struct evaluate
	<
		lambda<>,
		body<>,
		list<>,
		environment<> = null_environment,
		typename default_functor = undefined::functor
	>
	{
	};

	template<typename, typename> struct APPLY;

	template<typename Function, typename... Parameters, typename... Frames>
	struct APPLY<tuple<Function, Parameters...>, environment<Frames...>>
	{
		using Environment = environment<Frames...>;

		using rtn = typename conditional
		<
			typename Function::is_primitive,
			typename Function::template lambda<Parameters...>,
			EVAL
			<
				typename Function::body,
				extend
				<
					Environment,
					typename Function::variables,
					typename Function::constants
				>
			>

		>::rtn::rtn;
	};

	template<typename, typename> struct EXECUTE;

	template<typename Primitive, typename... Arguments, typename... Frames>
	struct EXECUTE<expression<Primitive, Arguments...>, environment<Frames...>>
	{
		using Env = environment<Frames...>;

		using rtn = typename conditional
		<
			typename Function::is_primitive,
			typename Function::template lambda<Parameters...>,
			<
				typename Function::body,
				extend
				<
					Environment,
					typename Function::variables,
					typename Function::constants
				>
			>

		>::rtn::rtn;
	};
*/
};

