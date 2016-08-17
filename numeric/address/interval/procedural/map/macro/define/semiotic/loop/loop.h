/************************************************************************************************************************
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
************************************************************************************************************************/

/*
	This code is not intended to be used standalone.
	It needs to be equipped with a context to be interpreted by the compiler.
*/

#define declare_loop(													\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, in_pointer,						\
			return_policy, count_policy)									\
															\
template<typename Filler>												\
struct Loop														\
<															\
	typename gvs_semiotic::template list										\
	<														\
		ArgPointer::out_interval, ArgPointer::out_direction,							\
		ArgPointer::out_memory, ArgPointer::out_pointer								\
	>,														\
															\
	typename gvs_semiotic::template list										\
	<														\
		ArgPointer::in_interval, ArgPointer::in_direction,							\
		ArgPointer::in_memory, ArgPointer::in_pointer								\
	>,														\
															\
	typename gvs_semiotic::template list										\
	<														\
		ArgTracer::return_policy, ArgTracer::count_policy							\
	>,														\
															\
	Filler														\
>															\
{															\
	loop														\
	(														\
		arg,													\
		out_interval, out_direction, out_memory, out_pointer,							\
		in_interval, in_direction, in_memory, in_pointer,							\
		omit_functor, unary, return_policy, count_policy							\
	)														\
															\
	loop														\
	(														\
		arg,													\
		out_interval, out_direction, out_memory, out_pointer,							\
		in_interval, in_direction, in_memory, in_pointer,							\
		apply_functor, unary, return_policy, count_policy							\
	)														\
															\
	loop														\
	(														\
		arg,													\
		out_interval, out_direction, out_memory, out_pointer,							\
		in_interval, in_direction, in_memory, in_pointer,							\
		apply_functor, binary, return_policy, count_policy							\
	)														\
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_loop_9(													\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, in_pointer,						\
			return_policy)											\
															\
	declare_loop													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, in_pointer,						\
			return_policy, omit_count									\
	)														\
															\
	declare_loop													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, in_pointer,						\
			return_policy, apply_count									\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_loop_8(													\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, in_pointer)						\
															\
	declare_loop_9													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, in_pointer,						\
			omit_return											\
	)														\
															\
	declare_loop_9													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, in_pointer,						\
			apply_return											\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_loop_7(													\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory)								\
															\
	declare_loop_8													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, segment							\
	)														\
															\
	declare_loop_8													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, hook							\
	)														\
															\
	declare_loop_8													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, link							\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_loop_6(													\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction)									\
															\
	declare_loop_7													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, mutate								\
	)														\
															\
	declare_loop_7													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, deallocate								\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_loop_5(													\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval)											\
															\
	declare_loop_6													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, forward										\
	)														\
															\
	declare_loop_6													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, backward										\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_loop_4(													\
			out_interval, out_direction, out_memory, out_pointer)						\
															\
	declare_loop_5													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			closing												\
	)														\
															\
	declare_loop_5													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			closed												\
	)														\
															\
	declare_loop_5													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			opening												\
	)														\
															\
	declare_loop_5													\
	(														\
			out_interval, out_direction, out_memory, out_pointer,						\
			open												\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_loop_3(													\
			out_interval, out_direction, out_pointer)							\
															\
	declare_loop_4													\
	(														\
			out_interval, out_direction, mutate, out_pointer						\
	)														\
															\
	declare_loop_4													\
	(														\
			out_interval, out_direction, allocate, out_pointer						\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_loop_2(													\
			out_interval, out_pointer)									\
															\
	declare_loop_3													\
	(														\
			out_interval, forward, out_pointer								\
	)														\
															\
	declare_loop_3													\
	(														\
			out_interval, backward, out_pointer								\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declareLoop(out_pointer)											\
															\
	declare_loop_2													\
	(														\
		closing, out_pointer											\
	)														\
															\
	declare_loop_2													\
	(														\
		closed, out_pointer											\
	)														\
															\
/*
	declare_loop_2													\
	(														\
		opening, out_pointer											\
	)														\
															\
	declare_loop_2													\
	(														\
		open, out_pointer											\
	)
*/


