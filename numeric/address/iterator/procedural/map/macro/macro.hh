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
	subject: interval_type, iterator_type, memrator_type, pointer_type
	object: interval_type, iterator_type, memrator_type, pointer_type
	verb: verse_type, tracer_type
*/


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


#define loop_closing_closing(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


#define loop_closing_closed(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	iterate_out(out_direction, out_memory, out_pointer)								\
	memory_action_in(in_memory, in_pointer, arity_policy)								\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


#define loop_closing_opening_mutate(											\
															\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(mutate, in_pointer, template_policy, arity_policy))				\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	while (omit_peek())												\
	{														\
		iterate_in(in_direction, mutate, in_pointer, arity_policy)						\
															\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
	}														\
															\
	undeclare_variables(mutate, in_pointer, arity_policy)								\
															\
	return_action(return_policy)											\
}


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


#define loop_closing_opening_deallocate(										\
															\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(deallocate, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_in(in_direction, mutate, in_pointer, arity_policy)							\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, deallocate, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	iterate_out(out_direction, out_memory, out_pointer)								\
	memory_action_in(deallocate, in_pointer, arity_policy)								\
															\
	undeclare_variables(deallocate, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


#define loop_closing_opening(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
	loop_closing_opening_##in_memory										\
	(														\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy				\
	)


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


#define loop_closing_open(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_in(in_direction, mutate, in_pointer, arity_policy)							\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/


#define loop_closed_closing(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	while (apply_peek(in_direction, in_pointer))									\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	iterate_in(in_direction, in_memory, in_pointer, arity_policy)							\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


#define loop_closed_closed(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	memory_action_in(in_memory, in_pointer, arity_policy)								\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


#define loop_closed_opening(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_in(in_direction, mutate, in_pointer, arity_policy)							\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	memory_action_in(in_memory, in_pointer, arity_policy)								\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


#define loop_closed_open(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_in(in_direction, mutate, in_pointer, arity_policy)							\
															\
	while (apply_peek(in_direction, in_pointer))									\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	iterate_in(in_direction, in_memory, in_pointer, arity_policy)							\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/


#define loop_opening_closing(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	while (omit_peek())												\
	{														\
		iterate_out(out_direction, out_memory, out_pointer)							\
															\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


#define loop_opening_closed(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_out(out_direction, out_memory, out_pointer)								\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	memory_action_in(in_memory, in_pointer, arity_policy)								\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


#define loop_opening_opening_mutate(											\
															\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(mutate, in_pointer, template_policy, arity_policy))				\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	while (omit_peek())												\
	{														\
		iterate_in(in_direction, mutate, in_pointer, arity_policy)						\
		iterate_out(out_direction, out_memory, out_pointer)							\
															\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
	}														\
															\
	undeclare_variables(mutate, in_pointer, arity_policy)								\
															\
	return_action(return_policy)											\
}


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


#define loop_opening_opening_deallocate(										\
															\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(deallocate, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_in(in_direction, mutate, in_pointer, arity_policy)							\
	iterate_out(out_direction, out_memory, out_pointer)								\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, deallocate, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	memory_action_in(deallocate, in_pointer, arity_policy)								\
															\
	undeclare_variables(deallocate, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


#define loop_opening_opening(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
	loop_opening_opening_##in_memory										\
	(														\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy				\
	)


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


#define loop_opening_open(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_in(in_direction, mutate, in_pointer, arity_policy)							\
															\
	while (omit_peek())												\
	{														\
		iterate_out(out_direction, out_memory, out_pointer)							\
															\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


#define loop_open_closing(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_out(out_direction, out_memory, out_pointer)								\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


#define loop_open_closed(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_out(out_direction, out_memory, out_pointer)								\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	iterate_out(out_direction, out_memory, out_pointer)								\
	memory_action_in(in_memory, in_pointer, arity_policy)								\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


#define loop_open_opening_mutate(											\
															\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(mutate, in_pointer, template_policy, arity_policy))				\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	while (omit_peek())												\
	{														\
		iterate_in(in_direction, mutate, in_pointer, arity_policy)						\
		iterate_out(out_direction, out_memory, out_pointer)							\
															\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
	}														\
															\
	iterate_out(out_direction, out_memory, out_pointer)								\
															\
	undeclare_variables(mutate, in_pointer, arity_policy)								\
															\
	return_action(return_policy)											\
}


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


#define loop_open_opening_deallocate(											\
															\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(deallocate, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_in(in_direction, mutate, in_pointer, arity_policy)							\
	iterate_out(out_direction, out_memory, out_pointer)								\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, deallocate, in_pointer, arity_policy)						\
	}														\
															\
	main_action(template_policy, arity_policy)									\
	count_action(count_policy)											\
															\
	iterate_out(out_direction, out_memory, out_pointer)								\
	memory_action_in(deallocate, in_pointer, arity_policy)								\
															\
	undeclare_variables(deallocate, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


#define loop_open_opening(												\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
	loop_open_opening_##in_memory											\
	(														\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_pointer,								\
				template_policy, arity_policy, return_policy, count_policy				\
	)


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


#define loop_open_open(													\
				label,											\
				out_direction, out_memory, out_pointer,							\
				in_direction, in_memory, in_pointer,							\
				template_policy, arity_policy, return_policy, count_policy)				\
															\
template_type(template_policy)												\
static return_type(return_policy) label(										\
															\
				verb_args(count_policy)									\
				subject_args(out_memory, out_pointer, return_policy)					\
				object_args(in_memory, in_pointer, template_policy, arity_policy))			\
{															\
	declare_variables(out_direction, out_memory, out_pointer)							\
															\
	iterate_in(in_direction, mutate, in_pointer, arity_policy)							\
	iterate_out(out_direction, out_memory, out_pointer)								\
															\
	while (omit_peek())												\
	{														\
		main_action(template_policy, arity_policy)								\
		count_action(count_policy)										\
															\
		iterate_out(out_direction, out_memory, out_pointer)							\
		iterate_in(in_direction, in_memory, in_pointer, arity_policy)						\
	}														\
															\
	undeclare_variables(in_memory, in_pointer, arity_policy)							\
															\
	return_action(return_policy)											\
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define loop(														\
		label,													\
		out_interval, out_direction, out_memory, out_pointer,							\
		in_interval, in_direction, in_memory, in_pointer,							\
		template_policy, arity_policy, return_policy, count_policy)						\
															\
	loop_##out_interval##_##in_interval										\
	(														\
		label,													\
		out_direction, out_memory, out_pointer,									\
		in_direction, in_memory, in_pointer,									\
		template_policy, arity_policy, return_policy, count_policy						\
	)


