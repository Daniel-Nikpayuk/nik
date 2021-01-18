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

/*
	continuation_make:
*/

	template<typename Args, typename Body>
	struct continuation_make
	{
		using rtn = continuation
		<
			typename Args::rtn,
			typename Body::rtn
		>;
	};

/*
	trampoline_eval:
*/

	template<typename, typename, typename, size_type, size_type...> struct trampoline_eval;

	template
	<
		typename Program, typename Env, typename Func,
		size_type index, size_type depth, size_type... depths
	>
	struct trampoline_eval
	<
		Program, Env, Func,
		index, depth, depths...
	>
	{
		using first = typename trampoline_eval
		<
			Program, Env, Func,
			depth, depths...

		>::rtn;

		using rtn = typename if_then_else
		<
			is_<first, continuation>,

			trampoline_eval
			<
				car<first>,		// Program
				car<first, one>,	// Env
				Func,
				index-1,
				depth,
				depths...
			>,

			first

		>::rtn;
	};

	template
	<
		typename Program, typename Env, typename Func,
		size_type depth, size_type... depths
	>
	struct trampoline_eval
	<
		Program, Env, Func,
		0, depth, depths...
	>
	{
		using rtn = error_nesting_depth_exceeded;
	};

	template<typename Program, typename Env, typename Func, size_type index>
	struct trampoline_eval<Program, Env, Func, index>
	{
		using first = typename Func::template eval
		<
			Program,
			Env
 
		>::rtn;

		using rtn = typename if_then_else
		<
			is_<first, continuation>,

			trampoline_eval
			<
				car<first>,		// Program
				car<first, one>,	// Env
				Func,
				index-1
			>,

			first

		>::rtn;
	};

	template<typename Program, typename Env, typename Func>
	struct trampoline_eval<Program, Env, Func, 0>
	{
		using rtn = typename Func::template eval
		<
			Program,
			Env

		>::rtn;
	};

