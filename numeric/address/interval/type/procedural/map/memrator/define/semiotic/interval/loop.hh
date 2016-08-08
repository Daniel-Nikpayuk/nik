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


#define declare_loop(													\
			out_direction, out_interval, out_pointer,							\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval)									\
															\
template<typename Filler>												\
struct _loop														\
<															\
	typename gvs_semiotic::template list										\
	<														\
			Verse::out_direction, Verse::out_interval, Verse::out_pointer,					\
			Verse::out_memory, Verse::count_policy, Verse::return_policy					\
	>,														\
															\
	typename gvs_semiotic::template list										\
	<														\
			Interval::in_direction, Interval::in_interval							\
	>,														\
															\
	Filler														\
>															\
{															\
	loop														\
	(														\
			assign, interval, =,										\
			out_direction, out_interval, out_pointer,							\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval, segment,								\
			mutate, unary											\
	)														\
															\
	loop														\
	(														\
			assign, functor_interval, =,									\
			out_direction, out_interval, out_pointer,							\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval, segment,								\
			mutate, unary											\
	)														\
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


template<typename verseList, typename intervalList, typename Filler = void>
struct _loop
{
	static_assert(true, "This method has not yet been declared.");
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_1(													\
			out_interval, out_pointer,									\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval)									\
															\
	declare_loop													\
	(														\
			forward, out_interval, out_pointer,								\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval									\
	)														\
															\
	declare_loop													\
	(														\
			backward, out_interval, out_pointer,								\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval									\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_2(													\
			out_pointer,											\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval)									\
															\
	declare_loop_1													\
	(														\
			closing, out_pointer,										\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval									\
	)														\
															\
	declare_loop_1													\
	(														\
			closed, out_pointer,										\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval									\
	)														\
															\
	declare_loop_1													\
	(														\
			opening, out_pointer,										\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval									\
	)														\
															\
	declare_loop_1													\
	(														\
			open, out_pointer,										\
			out_memory, count_policy, return_policy,							\
			in_direction, in_interval									\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_3(													\
			out_pointer,											\
			count_policy, return_policy,									\
			in_direction, in_interval)									\
															\
	declare_loop_2													\
	(														\
			out_pointer,											\
			allocate, count_policy, return_policy,								\
			in_direction, in_interval									\
	)														\
															\
	declare_loop_2													\
	(														\
			out_pointer,											\
			mutate, count_policy, return_policy,								\
			in_direction, in_interval									\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_4(													\
			out_pointer,											\
			return_policy,											\
			in_direction, in_interval)									\
															\
	declare_loop_3													\
	(														\
			out_pointer,											\
			omit_count, return_policy,									\
			in_direction, in_interval									\
	)														\
															\
	declare_loop_3													\
	(														\
			out_pointer,											\
			apply_count, return_policy,									\
			in_direction, in_interval									\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_5(													\
			out_pointer,											\
			in_direction, in_interval)									\
															\
	declare_loop_4													\
	(														\
			out_pointer,											\
			apply_return,											\
			in_direction, in_interval									\
	)														\
															\
	declare_loop_4													\
	(														\
			out_pointer,											\
			omit_return,											\
			in_direction, in_interval									\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_6(													\
			out_pointer,											\
			in_interval)											\
															\
	declare_loop_5													\
	(														\
			out_pointer,											\
			forward, in_interval										\
	)														\
															\
	declare_loop_5													\
	(														\
			out_pointer,											\
			backward, in_interval										\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_7(													\
			out_pointer)											\
															\
	declare_loop_6													\
	(														\
			out_pointer,											\
			closing												\
	)														\
															\
	declare_loop_6													\
	(														\
			out_pointer,											\
			closed												\
	)														\
															\
	declare_loop_6													\
	(														\
			out_pointer,											\
			opening												\
	)														\
															\
	declare_loop_6													\
	(														\
			out_pointer,											\
			open												\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


