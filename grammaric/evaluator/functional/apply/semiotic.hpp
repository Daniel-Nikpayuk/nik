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

//

template<typename>
struct is_application
{
	using rtn = boolean<false>;
};

template<typename E1, typename Env>
struct is_application<APPLY<E1, Env>>
{
	using rtn = boolean<true>;
};

