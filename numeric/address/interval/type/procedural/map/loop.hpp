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

/*
	out_memory != deallocate,
	in_memory != allocate
*/


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


template<size_type out_interval, size_type in_interval, typename Filler = void>
struct _loop { };


/*************************************************************************************************************************
							closing
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<typename Filler>
struct _loop<ArgPointer::closing, ArgPointer::closing, Filler>
{
	static typename out_type::pointer map(typename out_type::pointer out, size_type m, size_type n)
	{
		while (m != n)
		{
			*out = m;

			out=+out=new out_type;
			++m;
		}

		return out;
	}
};


#define loop_closing_closing(label, operator_policy, op_a,										\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


#define loop_closing_closed(label, operator_policy, op_a,										\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	iterate_out(out_direction, out_memory, out_pointer)										\
	in_memory(operator_policy, in_pointer, arity_policy)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


#define loop_closing_opening_mutate(label, operator_policy, op_a,									\
	out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)			\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)						\
																	\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
	}																\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


#define loop_closing_opening_deallocate(label, operator_policy, op_a,									\
	out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)			\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)							\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, deallocate, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	iterate_out(out_direction, out_memory, out_pointer)										\
	deallocate(operator_policy, in_pointer, arity_policy)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


#define loop_closing_opening(label, operator_policy, op_a,										\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
	loop_closing_opening_##in_memory(label, operator_policy, op_a,									\
		out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


#define loop_closing_open(label, operator_policy, op_a,											\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)							\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
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
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	while (apply_peek(in_direction, arity_policy))											\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)							\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


#define loop_closed_closed(label, operator_policy, op_a,										\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	in_memory(operator_policy, in_pointer, arity_policy)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


#define loop_closed_opening(label, operator_policy, op_a,										\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)							\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	in_memory(operator_policy, in_pointer, arity_policy)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


#define loop_closed_open(label, operator_policy, op_a,											\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)							\
																	\
	while (apply_peek(in_direction, arity_policy))											\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)							\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
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
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		iterate_out(out_direction, out_memory, out_pointer)									\
																	\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


#define loop_opening_closed(label, operator_policy, op_a,										\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_out(out_direction, out_memory, out_pointer)										\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	in_memory(operator_policy, in_pointer, arity_policy)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


#define loop_opening_opening_mutate(label, operator_policy, op_a,									\
	out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)			\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)						\
		iterate_out(out_direction, out_memory, out_pointer)									\
																	\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
	}																\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


#define loop_opening_opening_deallocate(label, operator_policy, op_a,									\
	out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)			\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)							\
	iterate_out(out_direction, out_memory, out_pointer)										\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, deallocate, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	deallocate(operator_policy, in_pointer, arity_policy)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


#define loop_opening_opening(label, operator_policy, op_a,										\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
	loop_opening_opening_##in_memory(label, operator_policy, op_a,									\
		out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


#define loop_opening_open(label, operator_policy, op_a,											\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)							\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		iterate_out(out_direction, mutate, out_pointer)										\
																	\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


#define loop_open_closing(label, operator_policy, op_a,											\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_out(out_direction, out_memory, out_pointer)										\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


#define loop_open_closed(label, operator_policy, op_a,											\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_out(out_direction, out_memory, out_pointer)										\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	iterate_out(out_direction, out_memory, out_pointer)										\
	in_memory(operator_policy, in_pointer, arity_policy)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


#define loop_open_opening_mutate(label, operator_policy, op_a,										\
	out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)			\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)						\
		iterate_out(out_direction, out_memory, out_pointer)									\
																	\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
	}																\
																	\
	iterate_out(out_direction, out_memory, out_pointer)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


#define loop_open_opening_deallocate(label, operator_policy, op_a,									\
	out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)			\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)							\
	iterate_out(out_direction, out_memory, out_pointer)										\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, deallocate, in_pointer, arity_policy)						\
	}																\
																	\
	operator_policy(op_a, arity_policy)												\
	count_policy()															\
																	\
	iterate_out(out_direction, out_memory, out_pointer)										\
	deallocate(operator_policy, in_pointer, arity_policy)										\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


#define loop_open_opening(label, operator_policy, op_a,											\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
	loop_open_opening_##in_memory(label, operator_policy, op_a,									\
		out_direction, out_memory, out_pointer, in_direction, in_pointer, arity_policy, return_policy, count_policy)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


#define loop_open_open(label, operator_policy, op_a,											\
	out_direction, out_memory, out_pointer, in_direction, in_memory, in_pointer, arity_policy, return_policy, count_policy)		\
function_type(label, operator_policy, out_memory, out_pointer, in_memory, in_pointer, arity_policy, return_policy, count_policy)	\
{																	\
	declare_variables(out_direction, out_memory, out_pointer)									\
																	\
	iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)							\
	iterate_out(out_direction, out_memory, out_pointer)										\
																	\
	while (omit_peek(arity_policy))													\
	{																\
		operator_policy(op_a, arity_policy)											\
		count_policy()														\
																	\
		iterate_out(out_direction, out_memory, out_pointer)									\
		iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)						\
	}																\
																	\
	undeclare_variables(in_direction, in_memory, in_pointer)									\
																	\
	return_policy()															\
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


using loop = _loop<out_interval, in_interval>;


