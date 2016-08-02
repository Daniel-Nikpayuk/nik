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
*/

/*
	Keep in mind you can always specify the template type to be a reference if need be (in1, in2, end2).

	These methods are less iterator algorithms than they are iterator reference algorithms---data algorithms
	in the special case where the data is only accessible through iterators.

	The ordering of "op" then "new" is intentional as it provides higher composability of these methods.
	As "out" is assign shifted when its "+out" is allocated, there is no need to increment seperately.
*/

/*
	The main design point when it comes to conversions is that the context is preserved/modified, and only
	the filler end points are gained or lost:

	[x, y) --> [x, y-1]
	[x, y) --> (x-1, y-1]
	[x, y) --> (x-1, y)
*/

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*************************************************************************************************************************
							closing
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


#define loop_closing_closing(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


#define loop_closing_closed(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	out_direction()															\
	memory_policy(out_pointer, in_arity)												\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


#define loop_closing_opening_mutate(label, operator_policy, op_a,									\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		in_direction(in_pointer, mutate, in_arity)										\
																	\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction()														\
	}																\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


#define loop_closing_opening_deallocate(label, operator_policy, op_a,									\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
																	\
	while (omit_peek(in_arity))													\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, deallocate)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	out_direction()															\
	deallocate(in_arity)														\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


#define loop_closing_opening(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
	loop_closing_opening_##memory_policy(label, operator_policy, op_a,								\
		out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


#define loop_closing_open(label, operator_policy, op_a,											\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
																	\
	while (omit_peek(in_arity))													\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/


#define loop_closed_closing(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (apply_peek(in_arity, in_direction))											\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	in_direction(in_pointer, in_memory, in_arity)											\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


#define loop_closed_closed(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	memory_policy(out_pointer, in_arity)												\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1] > end-in > 0
*/


#define loop_closed_opening(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
																	\
	while (omit_peek(in_arity))													\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	memory_policy(out_pointer, in_arity)												\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2] > end-in > 1
*/


#define loop_closed_open(label, operator_policy, op_a,											\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
																	\
	while (apply_peek(in_arity, in_direction))											\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	in_direction(in_pointer, in_memory, in_arity)											\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/


#define loop_opening_closing(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


#define loop_opening_closed(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	out_direction()															\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	memory_policy(out_pointer, in_arity)												\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


#define loop_opening_opening_mutate(label, operator_policy, op_a,									\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		in_direction(in_pointer, mutate, in_arity)										\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
	}																\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


#define loop_opening_opening_deallocate(label, operator_policy, op_a,									\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
																	\
	while (omit_peek(in_arity))													\
	{																\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		in_direction(in_pointer, deallocate, in_arity)										\
	}																\
																	\
	out_direction()															\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	deallocate(in_arity)														\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


#define loop_opening_opening(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
	loop_opening_opening_##memory_policy(label, operator_policy, op_a,								\
		out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


#define loop_opening_open_mutate(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (apply_peek(in_arity, in_direction))											\
	{																\
		in_direction(in_pointer, mutate, in_arity)										\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
	}																\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 1
*/


#define loop_opening_open_deallocate(label, operator_policy, op_a,									\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
																	\
	while (apply_peek(in_arity, in_direction))											\
	{																\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		in_direction(in_pointer, deallocate, in_arity)										\
	}																\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


#define loop_opening_open(label, operator_policy, op_a,											\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
	loop_opening_open_##memory_policy(label, operator_policy, op_a,									\
		out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


#define loop_open_closing(label, operator_policy, op_a,											\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	out_direction()															\
																	\
	while (omit_peek(in_arity))													\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


#define loop_open_closed(label, operator_policy, op_a,											\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	out_direction()															\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	out_direction()															\
	memory_policy(out_pointer, in_arity)												\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


#define loop_open_opening_mutate(label, operator_policy, op_a,										\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	while (omit_peek(in_arity))													\
	{																\
		in_direction(in_pointer, mutate, in_arity)										\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
	}																\
																	\
	out_direction()															\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


#define loop_open_opening_deallocate(label, operator_policy, op_a,									\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
																	\
	while (omit_peek(in_arity))													\
	{																\
		out_direction()														\
																	\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		in_direction(in_pointer, deallocate, in_arity)										\
	}																\
																	\
	out_direction()															\
																	\
	operator_policy(op_a)														\
	count_policy()															\
																	\
	out_direction()															\
	deallocate(in_arity)														\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


#define loop_open_opening(label, operator_policy, op_a,											\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
	loop_open_opening_##memory_policy(label, operator_policy, op_a,									\
		out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


#define loop_open_open(label, operator_policy, op_a,											\
	out_direction, out_pointer, out_memory, count_policy, return_policy, in_direction, in_pointer, in_memory, in_arity)		\
function_type(label, operator_policy, count_policy, return_policy)									\
{																	\
	declare_variables(out_direction, out_pointer, out_memory)									\
																	\
	in_direction(in_pointer, mutate, in_arity)											\
	out_direction()															\
																	\
	while (omit_peek(in_arity))													\
	{																\
		operator_policy(op_a)													\
		count_policy()														\
																	\
		out_direction(out_pointer, out_memory)											\
		in_direction(in_pointer, in_memory, in_arity)										\
	}																\
																	\
	undeclare_variables(in_pointer, in_memory)											\
																	\
	return_policy()															\
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	verse: iterator_type, interval_type, pointer_type, list_type, tracer_type, verse_type

	interval: iterator_type, interval_type
*/

#define loop(										\
		label, operator_policy, op_a,						\
		out_direction, out_interval, out_pointer,				\
		out_memory, count_policy, return_policy,				\
		in_direction, in_interval, in_pointer,					\
		in_memory, in_arity)							\
											\
	loop_##out_interval##_##in_interval(						\
		label, operator_policy, op_a,						\
		out_direction, out_pointer,						\
		out_memory, count_policy, return_policy,				\
		in_direction, in_pointer,						\
		in_memory, in_arity)

