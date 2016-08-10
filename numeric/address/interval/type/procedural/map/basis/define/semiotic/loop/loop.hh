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


#define MAIN_LOOP_ARGS			out_interval, out_direction, out_memory, out_pointer,				\
					in_interval, in_direction, in_memory, in_pointer,				\
					arity_policy, return_policy, count_policy

#define LOOP_ARGS			out_adjective, out_direction, out_memory, out_pointer,				\
					in_adjective, in_direction, in_memory, in_pointer,				\
					operator_policy, arity_policy, return_policy, count_policy

#define LOOP_ARGS_MEMORY		out_adjective, out_direction, out_memory, out_pointer,				\
					in_adjective, in_direction, in_memory, in_pointer,				\
					operator_policy, arity_policy, return_policy, count_policy


#define VERB_ARGS			verb_arguments(count_policy)
#define SUBJECT_ARGS			subject_arguments(out_memory, out_pointer)
#define OBJECT_ARGS			object_arguments(in_memory, in_pointer, in_arity)

#define TEMPLATE_TYPE			template_type(operator_policy)
#define RETURN_TYPE			return_type(return_policy)

#define DECLARE_VARIABLES		declare_variables(out_direction, out_memory, out_pointer)

#define OMIT_PEEK			omit_peek(arity_policy)
#define APPLY_PEEK			apply_peek(in_direction, arity_policy)

#define MAIN_ACTION			operator_policy(op_a, arity_policy)
#define COUNT_ACTION			count_policy()

#define ITERATE_OUT			iterate_out(out_direction, out_memory, out_pointer)
#define ITERATE_OUT_MUTATE		iterate_out(out_direction, mutate, out_pointer)

#define ITERATE_IN			iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)
#define ITERATE_IN_MUTATE		iterate_in(operator_policy, in_direction, mutate, in_pointer, arity_policy)
#define ITERATE_IN_DEALLOCATE		iterate_in(operator_policy, in_direction, deallocate, in_pointer, arity_policy)

#define IN_MEMORY			in_memory(operator_policy, in_pointer, arity_policy)
#define DEALLOCATE			deallocate(operator_policy, in_pointer, arity_policy)

#define UNDECLARE_VARIABLES		undeclare_variables(in_direction, in_memory, in_pointer)

#define RETURN_ACTION			return_policy()


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


#define loop_closing_closing( LOOP_ARGS )										\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	while (OMIT_PEEK)												\
	{														\
		MAIN_ACTION												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


#define loop_closing_closed( LOOP_ARGS )										\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	ITERATE_OUT													\
	IN_MEMORY													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


#define loop_closing_opening_mutate( LOOP_ARGS_MEMORY )									\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	while (OMIT_PEEK)												\
	{														\
		ITERATE_IN_MUTATE											\
															\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
	}														\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


#define loop_closing_opening_deallocate( LOOP_ARGS_MEMORY )								\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_IN_MUTATE												\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN_DEALLOCATE											\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	ITERATE_OUT													\
	DEALLOCATE													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


#define loop_closing_opening( LOOP_ARGS )										\
	loop_closing_opening_##in_memory( LOOP_ARGS_MEMORY )


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


#define loop_closing_open( LOOP_ARGS )											\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_IN_MUTATE												\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/


#define loop_closed_closing( LOOP_ARGS )										\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	while (APPLY_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	ITERATE_IN													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


#define loop_closed_closed( LOOP_ARGS )											\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	IN_MEMORY													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


#define loop_closed_opening( LOOP_ARGS )										\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_IN_MUTATE												\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	IN_MEMORY													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


#define loop_closed_open( LOOP_ARGS )											\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_IN_MUTATE												\
															\
	while (APPLY_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	ITERATE_IN													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/


#define loop_opening_closing( LOOP_ARGS )										\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	while (OMIT_PEEK)												\
	{														\
		ITERATE_OUT												\
															\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_IN												\
	}														\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


#define loop_opening_closed( LOOP_ARGS )										\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_OUT													\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	IN_MEMORY													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


#define loop_opening_opening_mutate( LOOP_ARGS_MEMORY )									\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	while (OMIT_PEEK)												\
	{														\
		ITERATE_IN_MUTATE											\
		ITERATE_OUT												\
															\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
	}														\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


#define loop_opening_opening_deallocate( LOOP_ARGS_MEMORY )								\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_IN_MUTATE												\
	ITERATE_OUT													\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN_DEALLOCATE											\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	DEALLOCATE													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


#define loop_opening_opening( LOOP_ARGS )										\
	loop_opening_opening_##in_memory( LOOP_ARGS_MEMORY )


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


#define loop_opening_open( LOOP_ARGS )											\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_IN_MUTATE												\
															\
	while (OMIT_PEEK)												\
	{														\
		ITERATE_OUT_MUTATE											\
															\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_IN												\
	}														\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


#define loop_open_closing( LOOP_ARGS )											\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_OUT													\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


#define loop_open_closed( LOOP_ARGS )											\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_OUT													\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	ITERATE_OUT													\
	IN_MEMORY													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


#define loop_open_opening_mutate( LOOP_ARGS_MEMORY )									\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	while (OMIT_PEEK)												\
	{														\
		ITERATE_IN_MUTATE											\
		ITERATE_OUT												\
															\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
	}														\
															\
	ITERATE_OUT													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


#define loop_open_opening_deallocate( LOOP_ARGS_MEMORY )								\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_IN_MUTATE												\
	ITERATE_OUT													\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN_DEALLOCATE											\
	}														\
															\
	OPERATOR_POLICY													\
	COUNT_ACTION													\
															\
	ITERATE_OUT													\
	DEALLOCATE													\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


#define loop_open_opening( LOOP_ARGS )											\
	loop_open_opening_##in_memory( LOOP_ARGS_MEMORY )


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


#define loop_open_open( LOOP_ARGS )											\
															\
TEMPLATE_TYPE														\
static RETURN_TYPE function_name( VERB_ARGS SUBJECT_ARGS OBJECT_ARGS )							\
{															\
	DECLARE_VARIABLES												\
															\
	ITERATE_IN_MUTATE												\
	ITERATE_OUT													\
															\
	while (OMIT_PEEK)												\
	{														\
		OPERATOR_POLICY												\
		COUNT_ACTION												\
															\
		ITERATE_OUT												\
		ITERATE_IN												\
	}														\
															\
	UNDECLARE_VARIABLES												\
															\
	RETURN_ACTION													\
}


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define loop( MAIN_LOOP_ARGS )												\
	loop_##out_interval##_##in_interval( LOOP_ARGS )


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef MAIN_LOOP_ARGS
#undef LOOP_ARGS
#undef LOOP_ARGS_MEMORY
#undef VERB_ARGS
#undef SUBJECT_ARGS
#undef OBJECT_ARGS
#undef TEMPLATE_TYPE
#undef RETURN_TYPE
#undef DECLARE_VARIABLES
#undef OMIT_PEEK
#undef APPLY_PEEK
#undef MAIN_ACTION
#undef COUNT_ACTION
#undef ITERATE_OUT
#undef ITERATE_OUT_MUTATE
#undef ITERATE_IN
#undef ITERATE_IN_MUTATE
#undef ITERATE_IN_DEALLOCATE
#undef IN_MEMORY
#undef DEALLOCATE
#undef UNDECLARE_VARIABLES
#undef RETURN_ACTION


