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
	assignment_eval:

	Assumes the "set" tag has been removed.
*/

	template<typename Expression, typename Environment, typename Functor>
	struct assignment_eval
	{
		using Exp	= typename Expression::rtn;
		using Env	= typename Environment::rtn;
		using Func	= typename Functor::rtn;

		using rtn = typename environment_set
		<
			car<Exp>,			// assignment_variable

			trampoline_eval
			<
				car<Exp, one>,		// assignment_value
				Env,
				Func,
				stack_depth,
				stack_depth
			>,

			Env

		>::rtn;
	};

