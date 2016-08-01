/*************************************************************************************************************************
**
** Copyright 2015, 2016 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
*************************************************************************************************************************/

/*
	This code is not intended to be used standalone.
	It needs to be equipped with a context to be interpreted by the compiler.
	It is meant to be bootstrapped with a given macro interpretation.
*/


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop(									\
			out_interval, out_direction,					\
			in_interval, in_direction,					\
			count_policy, return_policy)					\
											\
template<typename Filler>								\
struct allocate_loop									\
<											\
	typename gvs_semiotic::template list						\
	<										\
		arg::list::out_interval, arg::list::out_direction,			\
		arg::list::in_interval, arg::list::in_direction,			\
		arg::list::count_policy, arg::list::return_policy			\
	>,										\
											\
	Filler										\
>											\
{											\
	loop										\
	(										\
		assign, no_delete,							\
		constant,  ,  ,  ,							\
		out_interval, out_direction,						\
		in_as_unary, in_interval, in_direction,					\
		delete_policy, count_policy, return_policy				\
	)										\
											\
	loop_map									\
	(										\
		assign,									\
		parentheses, =,  ,  ,							\
		out_as_unary, out_interval, out_direction,				\
		in_as_unary, in_interval, in_direction,					\
		delete_policy, count_policy, return_policy				\
	)										\
											\
	loop_map									\
	(										\
		generic,								\
		genericity,  ,  ,  ,							\
		out_as_unary, out_interval, out_direction,				\
		in_as_nullary, in_interval, in_direction,				\
		delete_policy, count_policy, return_policy				\
	)										\
											\
	loop_map									\
	(										\
		generic,								\
		genericity,  ,  ,  ,							\
		out_as_unary, out_interval, out_direction,				\
		in_as_unary, in_interval, in_direction,					\
		delete_policy, count_policy, return_policy				\
	)										\
											\
	loop_map									\
	(										\
		generic,								\
		genericity,  ,  ,  ,							\
		out_as_unary, out_interval, out_direction,				\
		in_as_binary, in_interval, in_direction,				\
		delete_policy, count_policy, return_policy				\
	)										\
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


template<typename configuration, typename Filler = void>
struct allocate_loop
{
	static_assert(true, "This method has not yet been declared.");
};


