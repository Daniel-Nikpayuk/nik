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


/*
	out as nullary, in as _ary
*/

/*************************************************************************************************************************
							closing
*************************************************************************************************************************/


/*
	Constraints:

	[out, end)
*/

#define loop_map_out_as_nullary_in_as_closing( \
	operator_policy, op_a, op_l, op_r, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	return_policy() \
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[out, end]
*/

#define loop_map_out_as_nullary_in_as_closed( \
	operator_policy, op_a, op_l, op_r, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	delete_policy(in_arity) \
	count_policy() \
 \
	return_policy() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	(out, end]
*/

#define loop_map_out_as_nullary_in_as_opening( \
	operator_policy, op_a, op_l, op_r, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(omit_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(delete_policy, in_arity) \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
	} \
 \
	return_policy() \
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	(out, end)
*/

#define loop_map_out_as_nullary_in_as_open( \
	operator_policy, op_a, op_l, op_r, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(omit_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	out as unary, in as nullary
*/

/*************************************************************************************************************************
							closing
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> [out, out + n)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_closing( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> [out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_closed( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	++n; \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> [out, out + n)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> [out, out + n-1), n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	--n; \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> [out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_closing( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	--n; \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> [out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_closed( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> [out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	--n; \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> [out, out + n-2], n > 1
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	n-=2; \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	count_policy() \
 \
	return_policy() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> (out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_closing( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (n) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> (out, out + n+1]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_closed( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	++n; \
 \
	while (n) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> (out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (n) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> (out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	--n; \
 \
	while (n) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> (out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_closing( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	out_direction() \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> (out, out + n+2)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_closed( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	++n; \
 \
	while (n) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
		--n; \
	} \
 \
	out_direction() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> (out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (n) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
		--n; \
	} \
 \
	out_direction() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> (out, out + n), n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	out_direction() \
	--n; \
 \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	out as unary, in as _ary
*/


/*************************************************************************************************************************
							closing
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/

#define loop_map_out_as_unary_out_as_closing_in_as_closing( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/

#define loop_map_out_as_unary_out_as_closing_in_as_closed( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	out_direction() \
	delete_policy(in_arity) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/

#define loop_map_omit_delete_out_as_unary_out_as_closing_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(omit_delete, in_arity) \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
	} \
 \
	return_policy() \
}

/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/

#define loop_map_apply_delete_out_as_unary_out_as_closing_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	in_direction(omit_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(apply_delete, in_arity) \
		count_policy() \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	out_direction() \
	apply_delete(in_arity) \
	count_policy() \
 \
	return_policy() \
}

#define loop_map_out_as_unary_out_as_closing_in_as_opening( \
		operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
	loop_map_##delete_policy##_out_as_unary_out_as_closing_in_as_opening( \
		operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/

#define loop_map_out_as_unary_out_as_closing_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	in_direction(omit_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	return_policy() \
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/

#define loop_map_out_as_unary_out_as_closed_in_as_closing( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (with_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	in_direction(delete_policy, in_arity) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/

#define loop_map_out_as_unary_out_as_closed_in_as_closed( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	delete_policy(in_arity) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1] > end-in > 0
*/

#define loop_map_out_as_unary_out_as_closed_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	in_direction(omit_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	delete_policy(in_arity) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2] > end-in > 1
*/

#define loop_map_out_as_unary_out_as_closed_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	in_direction(omit_delete, in_arity) \
 \
	while (with_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	in_direction(delete_policy, in_arity) \
	count_policy() \
 \
	return_policy() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/

#define loop_map_out_as_unary_out_as_opening_in_as_closing( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/

#define loop_map_out_as_unary_out_as_opening_in_as_closed( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	out_direction() \
	operator_policy(op_a, op_l, op_r) \
	delete_policy(in_arity) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/

#define loop_map_omit_delete_out_as_unary_out_as_opening_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(omit_delete, in_arity) \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
	} \
 \
	return_policy() \
}

/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/

#define loop_map_apply_delete_out_as_unary_out_as_opening_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	in_direction(omit_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(apply_delete, in_arity) \
		count_policy() \
	} \
 \
	out_direction() \
	operator_policy(op_a, op_l, op_r) \
	apply_delete(in_arity) \
	count_policy() \
 \
	return_policy() \
}

#define loop_map_out_as_unary_out_as_opening_in_as_opening( \
		operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
	loop_map_##delete_policy##_out_as_unary_out_as_opening_in_as_opening( \
		operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/

#define loop_map_omit_delete_out_as_unary_out_as_opening_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (with_peek(in_arity, in_direction)) \
	{ \
		in_direction(omit_delete, in_arity) \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
	} \
 \
	in_direction(omit_delete, in_arity) \
 \
	return_policy() \
}

/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 1
*/

#define loop_map_apply_delete_out_as_unary_out_as_opening_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	in_direction(omit_delete, in_arity) \
 \
	while (with_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(apply_delete, in_arity) \
		count_policy() \
	} \
 \
	return_policy() \
}

#define loop_map_out_as_unary_out_as_opening_in_as_open( \
		operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
	loop_map_##delete_policy##_out_as_unary_out_as_opening_in_as_open( \
		operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy)


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/

#define loop_map_out_as_unary_out_as_open_in_as_closing( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	out_direction() \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/

#define loop_map_out_as_unary_out_as_open_in_as_closed( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	out_direction() \
	operator_policy(op_a, op_l, op_r) \
	out_direction() \
	delete_policy(in_arity) \
	count_policy() \
 \
	return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/

#define loop_map_omit_delete_out_as_unary_out_as_open_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(omit_delete, in_arity) \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
	} \
 \
	out_direction() \
 \
	return_policy() \
}

/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/

#define loop_map_apply_delete_out_as_unary_out_as_open_in_as_opening( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	in_direction(omit_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(apply_delete, in_arity) \
		count_policy() \
	} \
 \
	out_direction() \
	operator_policy(op_a, op_l, op_r) \
	out_direction() \
	apply_delete(in_arity) \
	count_policy() \
 \
	return_policy() \
}

#define loop_map_out_as_unary_out_as_open_in_as_opening( \
		operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
	loop_map_##delete_policy##_out_as_unary_out_as_open_in_as_opening( \
		operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, count_policy, return_policy)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/

#define loop_map_out_as_unary_out_as_open_in_as_open( \
	operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction, delete_policy, count_policy, return_policy) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	declare_variables(out_direction) \
	in_direction(omit_delete, in_arity) \
	out_direction() \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	return_policy() \
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	out_interval:

		out_as_closing
		out_as_closed
		out_as_opening
		out_as_open

	in_interval:

		in_as_closing
		in_as_closed
		in_as_opening
		in_as_open
*/

// out as nullary


#define loop_map_out_as_nullary_in_as_unary(						\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction,						\
		delete_policy, count_policy, return_policy)				\
											\
	loop_map_out_as_nullary_##out_interval##_##in_interval(				\
		out_as_nullary_in_as_unary_##operator_policy, op_a, op_l, op_r,		\
		in_as_unary, in_direction,						\
		delete_policy, count_policy, return_policy)


// out as unary


#define loop_map_out_as_unary_in_as_nullary(						\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction,						\
		delete_policy, count_policy, return_policy)				\
											\
	loop_map_out_as_unary_in_as_nullary_##out_interval##_##in_interval(		\
		out_as_unary_in_as_nullary_##operator_policy, op_a, op_l, op_r,		\
		out_direction,								\
		delete_policy, count_policy, return_policy)

#define loop_map_out_as_unary_in_as_unary(						\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction,						\
		delete_policy, count_policy, return_policy)				\
											\
	loop_map_out_as_unary_##out_interval##_##in_interval(				\
		out_as_unary_in_as_unary_##operator_policy, op_a, op_l, op_r,		\
		out_direction,								\
		in_as_unary, in_direction,						\
		delete_policy, count_policy, return_policy)

#define loop_map_out_as_unary_in_as_binary(						\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction,						\
		delete_policy, count_policy, return_policy)				\
											\
	loop_map_out_as_unary_##out_interval##_##in_interval(				\
		out_as_unary_in_as_binary_##operator_policy, op_a, op_l, op_r,		\
		out_direction,								\
		in_as_binary, in_direction,						\
		delete_policy, count_policy, return_policy)



/************************************************************************************************************************/

#define loop_map(									\
		operator_policy, op_a, op_l, op_r,					\
		out_arity, out_interval, out_direction,					\
		in_arity, in_interval, in_direction,					\
		delete_policy, count_policy, return_policy)				\
											\
	loop_map_##out_arity##_##in_arity(						\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction,						\
		delete_policy, count_policy, return_policy)

