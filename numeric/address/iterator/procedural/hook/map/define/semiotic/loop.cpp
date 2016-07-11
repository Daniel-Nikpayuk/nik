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


/////// out_as_nullary, in_as_unary


// parentheses


#define function_type_no_count_out_as_nullary_in_as_unary_parentheses(rtn, label)					\
															\
	template<typename WPointer, typename EWPointer>									\
	static rtn label##_return(WPointer in, EWPointer end)


		#define function_type_no_return_no_count_out_as_nullary_in_as_unary_parentheses()			\
			function_type_no_count_out_as_nullary_in_as_unary_parentheses(void, no)

		#define function_type_with_return_no_count_out_as_nullary_in_as_unary_parentheses()			\
			function_type_no_count_out_as_nullary_in_as_unary_parentheses(WPointer, with)

#define function_type_with_count_out_as_nullary_in_as_unary_parentheses(rtn, label)					\
															\
	template<typename WPointer, typename EWPointer>									\
	static rtn label##_return(size_type & count, WPointer in, EWPointer end)


		#define function_type_no_return_with_count_out_as_nullary_in_as_unary_parentheses()			\
			function_type_with_count_out_as_nullary_in_as_unary_parentheses(void, no)

		#define function_type_with_return_with_count_out_as_nullary_in_as_unary_parentheses()			\
			function_type_with_count_out_as_nullary_in_as_unary_parentheses(WPointer, with)


/////// out_as_unary, in_as_nullary


// parentheses


#define function_type_no_count_out_as_unary_in_as_nullary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename ValueType>							\
	static rtn label##_return(WPointer out, size_type n, ValueType value)


		#define function_type_no_return_no_count_out_as_unary_in_as_nullary_parentheses()			\
			function_type_no_count_out_as_unary_in_as_nullary_parentheses(void, no)

		#define function_type_with_return_no_count_out_as_unary_in_as_nullary_parentheses()			\
			function_type_no_count_out_as_unary_in_as_nullary_parentheses(WPointer, with)

#define function_type_with_count_out_as_unary_in_as_nullary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename ValueType>							\
	static rtn label##_return(size_type & count, WPointer out, size_type n, ValueType value)


		#define function_type_no_return_with_count_out_as_unary_in_as_nullary_parentheses()			\
			function_type_with_count_out_as_unary_in_as_nullary_parentheses(void, no)

		#define function_type_with_return_with_count_out_as_unary_in_as_nullary_parentheses()			\
			function_type_with_count_out_as_unary_in_as_nullary_parentheses(WPointer, with)


// parentheses_new


#define function_type_no_count_out_as_unary_in_as_nullary_parentheses_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer>							\
	static rtn label##_return(WPointer out, size_type n)


		#define function_type_no_return_no_count_out_as_unary_in_as_nullary_parentheses_new()			\
			function_type_no_count_out_as_unary_in_as_nullary_parentheses_new(void, no)

		#define function_type_with_return_no_count_out_as_unary_in_as_nullary_parentheses_new()			\
			function_type_no_count_out_as_unary_in_as_nullary_parentheses_new(WPointer, with)

#define function_type_with_count_out_as_unary_in_as_nullary_parentheses_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer>							\
	static rtn label##_return(size_type & count, WPointer out, size_type n)


		#define function_type_no_return_with_count_out_as_unary_in_as_nullary_parentheses_new()			\
			function_type_with_count_out_as_unary_in_as_nullary_parentheses_new(void, no)

		#define function_type_with_return_with_count_out_as_unary_in_as_nullary_parentheses_new()			\
			function_type_with_count_out_as_unary_in_as_nullary_parentheses_new(WPointer, with)


// brackets_new


#define function_type_no_count_out_as_unary_in_as_nullary_brackets_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer>							\
	static rtn label##_return(WPointer out, size_type n, size_type in)


		#define function_type_no_return_no_count_out_as_unary_in_as_nullary_brackets_new()			\
			function_type_no_count_out_as_unary_in_as_nullary_brackets_new(void, no)

		#define function_type_with_return_no_count_out_as_unary_in_as_nullary_brackets_new()			\
			function_type_no_count_out_as_unary_in_as_nullary_brackets_new(WPointer, with)

#define function_type_with_count_out_as_unary_in_as_nullary_brackets_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer>							\
	static rtn label##_return(size_type & count, WPointer out, size_type n, size_type in)


		#define function_type_no_return_with_count_out_as_unary_in_as_nullary_brackets_new()			\
			function_type_with_count_out_as_unary_in_as_nullary_brackets_new(void, no)

		#define function_type_with_return_with_count_out_as_unary_in_as_nullary_brackets_new()			\
			function_type_with_count_out_as_unary_in_as_nullary_brackets_new(WPointer, with)


/////// out_as_unary, in_as_unary


// parentheses


#define function_type_no_count_out_as_unary_in_as_unary_parentheses(rtn, label)						\
															\
	template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>				\
	static rtn label##_return(WPointer out, RIterator in, ERIterator end)


		#define function_type_no_return_no_count_out_as_unary_in_as_unary_parentheses()			\
			function_type_no_count_out_as_unary_in_as_unary_parentheses(void, no)

		#define function_type_with_return_no_count_out_as_unary_in_as_unary_parentheses()			\
			function_type_no_count_out_as_unary_in_as_unary_parentheses(WPointer, with)

#define function_type_with_count_out_as_unary_in_as_unary_parentheses(rtn, label)						\
															\
	template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>				\
	static rtn label##_return(size_type & count, WPointer out, RIterator in, ERIterator end)


		#define function_type_no_return_with_count_out_as_unary_in_as_unary_parentheses()			\
			function_type_with_count_out_as_unary_in_as_unary_parentheses(void, no)

		#define function_type_with_return_with_count_out_as_unary_in_as_unary_parentheses()			\
			function_type_with_count_out_as_unary_in_as_unary_parentheses(WPointer, with)


// brackets_new


#define function_type_no_count_out_as_unary_in_as_unary_brackets_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer, typename RIterator, typename ERIterator>		\
	static rtn label##_return(WPointer out, RIterator in, ERIterator end)


		#define function_type_no_return_no_count_out_as_unary_in_as_unary_brackets_new()			\
			function_type_no_count_out_as_unary_in_as_unary_brackets_new(void, no)

		#define function_type_with_return_no_count_out_as_unary_in_as_unary_brackets_new()			\
			function_type_no_count_out_as_unary_in_as_unary_brackets_new(WPointer, with)

#define function_type_with_count_out_as_unary_in_as_unary_brackets_new(rtn, label)					\
															\
	template<typename Node, typename WNode, typename WPointer, typename RIterator, typename ERIterator>		\
	static rtn label##_return(size_type & count, WPointer out, RIterator in, ERIterator end)


		#define function_type_no_return_with_count_out_as_unary_in_as_unary_brackets_new()			\
			function_type_with_count_out_as_unary_in_as_unary_brackets_new(void, no)

		#define function_type_with_return_with_count_out_as_unary_in_as_unary_brackets_new()			\
			function_type_with_count_out_as_unary_in_as_unary_brackets_new(WPointer, with)


/////// out_as_unary, in_as_binary


// parentheses


#define function_type_no_count_out_as_unary_in_as_binary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator>	\
	static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2)


		#define function_type_no_return_no_count_out_as_unary_in_as_binary_parentheses()			\
			function_type_no_count_out_as_unary_in_as_binary_parentheses(void, no)

		#define function_type_with_return_no_count_out_as_unary_in_as_binary_parentheses()			\
			function_type_no_count_out_as_unary_in_as_binary_parentheses(WPointer, with)

		#define function_type_no_return_no_count_out_as_unary_in_as_binary_brackets()				\
			function_type_no_count_out_as_unary_in_as_binary_parentheses(void, no)

		#define function_type_with_return_no_count_out_as_unary_in_as_binary_brackets()				\
			function_type_no_count_out_as_unary_in_as_binary_parentheses(WPointer, with)

#define function_type_with_count_out_as_unary_in_as_binary_parentheses(rtn, label)					\
															\
	template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator>	\
	static rtn label##_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2)


		#define function_type_no_return_with_count_out_as_unary_in_as_binary_parentheses()			\
			function_type_with_count_out_as_unary_in_as_binary_parentheses(void, no)

		#define function_type_with_return_with_count_out_as_unary_in_as_binary_parentheses()			\
			function_type_with_count_out_as_unary_in_as_binary_parentheses(WPointer, with)

		#define function_type_no_return_with_count_out_as_unary_in_as_binary_brackets()				\
			function_type_with_count_out_as_unary_in_as_binary_parentheses(void, no)

		#define function_type_with_return_with_count_out_as_unary_in_as_binary_brackets()			\
			function_type_with_count_out_as_unary_in_as_binary_parentheses(WPointer, with)



/************************************************************************************************************************/

/*
	function_type:

*/


#define function_type(return_policy, count_policy, operator_policy) \
	function_type_##return_policy##_##count_policy##_##operator_policy()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	operator_policy:

		out_as_nullary_in_as_unary_parentheses

		out_as_unary_in_as_nullary_parentheses
		out_as_unary_in_as_nullary_parentheses_new
		out_as_unary_in_as_nullary_brackets_new

		out_as_unary_in_as_unary_parentheses
		out_as_unary_in_as_unary_brackets_new

		out_as_unary_in_as_binary_parentheses
		out_as_unary_in_as_binary_brackets
*/


#define out_as_nullary_in_as_unary_parentheses(op_a, op_l, op_r)		op_a op_l (*in) op_r;


//


#define out_as_unary_in_as_nullary_parentheses(op_a, op_l, op_r)		(*out) op_a op_l (value) op_r;


#define out_as_unary_in_as_nullary_parentheses_new(op_a, op_l, op_r)		(*out) op_a op_l () op_r;


#define out_as_unary_in_as_nullary_brackets_new(op_a, op_l, op_r)		(*out) op_a op_l [value] op_r;


//


#define out_as_unary_in_as_unary_parentheses(op_a, op_l, op_r)			(*out) op_a op_l (*in) op_r;


#define out_as_unary_in_as_unary_brackets_new(op_a, op_l, op_r)			(*out) op_a op_l [*in] op_r;


//


#define out_as_unary_in_as_binary_parentheses(op_a, op_l, op_r)			(*out) op_a (*in1) op_l (*in2) op_r;


#define out_as_Unary_in_as_binary_brackets(op_a, op_l, op_r)			(*out) op_a (*in1) op_l [*in2] op_r;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	out_direction:

		out_as_forward
		out_as_backward
*/


#define out_direction(dir)							out=dir(out)=new WNode;


	#define out_as_forward()						out_direction(+)


	#define out_as_backward()						WPointer current=out; \
										out=new WNode; \
										+out=current;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define in_direction_no_delete_binary(dir)					dir##dir(in);


	#define in_as_forward_no_delete_binary()				in_direction_no_delete_binary(+)
	#define in_as_backward_no_delete_binary()				in_direction_no_delete_binary(-)


#define in_direction_with_delete_binary(dir)					delete (in)dir##dir;


	#define in_as_forward_with_delete_binary()				in_direction_with_delete_binary(+)
	#define in_as_backward_with_delete_binary()				in_direction_with_delete_binary(-)


#define in_direction_no_delete_trinary(dir)					dir##dir(in1); \
										dir##dir(in2);


	#define in_as_forward_no_delete_trinary()				in_direction_no_delete_trinary(+)
	#define in_as_backward_no_delete_trinary()				in_direction_no_delete_trinary(-)


#define in_direction_with_delete_trinary(dir)					delete (in1)dir##dir; \
										delete (in2)dir##dir;


	#define in_as_forward_with_delete_trinary()				in_direction_with_delete_trinary(+)
	#define in_as_backward_with_delete_trinary()				in_direction_with_delete_trinary(-)


/************************************************************************************************************************/


/*
	in_direction:

		in_as_forward
		in_as_backward
*/


#define in_as_forward(delete_policy, in_arity) \
	in_as_forward_##delete_policy##_##in_arity()

#define in_as_backward(delete_policy, in_arity) \
	in_as_backward_##delete_policy##_##in_arity()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define peek_type_binary(dir)							dir##in != end


	#define no_peek_binary_in_as_forward()					peek_type_binary( )
	#define no_peek_binary_in_as_backward()					peek_type_binary( )

	#define with_peek_binary_in_as_forward()				peek_type_binary(+)
	#define with_peek_binary_in_as_backward()				peek_type_binary(-)


#define peek_type_trinary(dir)							dir##in2 != end2


	#define no_peek_trinary_in_as_forward()					peek_type_trinary( )
	#define no_peek_trinary_in_as_backward()				peek_type_trinary( )

	#define with_peek_trinary_in_as_forward()				peek_type_trinary(+)
	#define with_peek_trinary_in_as_backward()				peek_type_trinary(-)


/************************************************************************************************************************/

/*
	peek_type:

		no_peek
		with_peek
*/


#define no_peek(in_arity, in_direction) \
	no_peek_##in_arity##_##in_direction()

#define with_peek(in_arity, in_direction) \
	with_peek_##in_arity##_##in_direction()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	count_policy:

		no_count
		with_count
*/


#define no_count()


#define with_count()								++count;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	return_policy:

		no_return
		with_return
*/


#define no_return()


#define _with_return()								return out;


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
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	_##return_policy() \
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[out, end]
*/

#define loop_map_out_as_nullary_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, in_arity, in_direction) \
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
	_##return_policy() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	(out, end]
*/

#define loop_map_out_as_nullary_in_as_opening( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(delete_policy, in_arity) \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
	} \
 \
	_##return_policy() \
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	(out, end)
*/

#define loop_map_out_as_nullary_in_as_open( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	_##return_policy() \
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
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> [out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> [out, out + n)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_opening( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (n) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
		--n; \
	} \
 \
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> [out, out + n-1), n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_open( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> [out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_closing( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> [out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> [out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_opening( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> [out, out + n-2], n > 1
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_open( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> (out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_closing( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (n) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
		--n; \
	} \
 \
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> (out, out + n+1]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> (out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_opening( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (n) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
		--n; \
	} \
 \
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> (out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_open( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> (out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_closing( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> (out, out + n+2)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> (out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_opening( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> (out, out + n), n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_open( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
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
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/

#define loop_map_out_as_unary_out_as_closing_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/

#define loop_map_no_delete_out_as_unary_out_as_closing_in_as_opening( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(no_delete, in_arity) \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		count_policy() \
	} \
 \
	_##return_policy() \
}

/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/

#define loop_map_with_delete_out_as_unary_out_as_closing_in_as_opening( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(with_delete, in_arity) \
		count_policy() \
	} \
 \
	operator_policy(op_a, op_l, op_r) \
	out_direction() \
	with_delete(in_arity) \
	count_policy() \
 \
	_##return_policy() \
}

#define loop_map_out_as_unary_out_as_closing_in_as_opening( \
		return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
	loop_map_##delete_policy##_out_as_unary_out_as_closing_in_as_opening( \
		return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/

#define loop_map_out_as_unary_out_as_closing_in_as_open( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_policy(op_a, op_l, op_r) \
		out_direction() \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	_##return_policy() \
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/

#define loop_map_out_as_unary_out_as_closed_in_as_closing( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/

#define loop_map_out_as_unary_out_as_closed_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1] > end-in > 0
*/

#define loop_map_out_as_unary_out_as_closed_in_as_opening( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2] > end-in > 1
*/

#define loop_map_out_as_unary_out_as_closed_in_as_open( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
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
	_##return_policy() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/

#define loop_map_out_as_unary_out_as_opening_in_as_closing( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(delete_policy, in_arity) \
		count_policy() \
	} \
 \
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/

#define loop_map_out_as_unary_out_as_opening_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/

#define loop_map_no_delete_out_as_unary_out_as_opening_in_as_opening( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(no_delete, in_arity) \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
	} \
 \
	_##return_policy() \
}

/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/

#define loop_map_with_delete_out_as_unary_out_as_opening_in_as_opening( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(with_delete, in_arity) \
		count_policy() \
	} \
 \
	out_direction() \
	operator_policy(op_a, op_l, op_r) \
	with_delete(in_arity) \
	count_policy() \
 \
	_##return_policy() \
}

#define loop_map_out_as_unary_out_as_opening_in_as_opening( \
		return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
	loop_map_##delete_policy##_out_as_unary_out_as_opening_in_as_opening( \
		return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/

#define loop_map_no_delete_out_as_unary_out_as_opening_in_as_open( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (with_peek(in_arity, in_direction)) \
	{ \
		in_direction(no_delete, in_arity) \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
	} \
 \
	in_direction(no_delete, in_arity) \
 \
	_##return_policy() \
}

/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 1
*/

#define loop_map_with_delete_out_as_unary_out_as_opening_in_as_open( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (with_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(with_delete, in_arity) \
		count_policy() \
	} \
 \
	_##return_policy() \
}

#define loop_map_out_as_unary_out_as_opening_in_as_open( \
		return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
	loop_map_##delete_policy##_out_as_unary_out_as_opening_in_as_open( \
		return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/

#define loop_map_out_as_unary_out_as_open_in_as_closing( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/

#define loop_map_out_as_unary_out_as_open_in_as_closed( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
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
	_##return_policy() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/

#define loop_map_no_delete_out_as_unary_out_as_open_in_as_opening( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(no_delete, in_arity) \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		count_policy() \
	} \
 \
	out_direction() \
 \
	_##return_policy() \
}

/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/

#define loop_map__delete_out_as_unary_out_as_open_in_as_opening( \
	return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_policy(op_a, op_l, op_r) \
		in_direction(with_delete, in_arity) \
		count_policy() \
	} \
 \
	out_direction() \
	operator_policy(op_a, op_l, op_r) \
	out_direction() \
	with_delete(in_arity) \
	count_policy() \
 \
	_##return_policy() \
}

#define loop_map_out_as_unary_out_as_open_in_as_opening( \
		return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
	loop_map_##delete_policy##_out_as_unary_out_as_open_in_as_opening( \
		return_policy, count_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/

#define loop_map_out_as_unary_out_as_open_in_as_open( \
	return_policy, count_policy, delete_policy, operator_policy, op_a, op_l, op_r, out_direction, in_arity, in_direction) \
function_type(return_policy, count_policy, operator_policy) \
{ \
	in_direction(no_delete, in_arity) \
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
	_##return_policy() \
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
		return_policy, count_policy, delete_policy,				\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction)						\
											\
	loop_map_out_as_nullary_##out_interval##_##in_interval(				\
		return_policy, count_policy, delete_policy,				\
		out_as_nullary_in_as_unary_##operator_policy, op_a, op_l, op_r,		\
		in_as_unary, in_direction)


// out as unary


#define loop_map_out_as_unary_in_as_nullary(						\
		return_policy, count_policy, delete_policy,				\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction)						\
											\
	loop_map_out_as_unary_in_as_nullary_##out_interval##_##in_interval(		\
		return_policy, count_policy, delete_policy,				\
		out_as_unary_in_as_nullary_##operator_policy, op_a, op_l, op_r,		\
		out_direction)								\

#define loop_map_out_as_unary_in_as_unary(						\
		return_policy, count_policy, delete_policy,				\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction)						\
											\
	loop_map_out_as_unary_##out_interval##_##in_interval(				\
		return_policy, count_policy, delete_policy,				\
		out_as_unary_in_as_unary_##operator_policy, op_a, op_l, op_r,		\
		out_direction,								\
		in_as_unary, in_direction)

#define loop_map_out_as_unary_in_as_binary(						\
		return_policy, count_policy, delete_policy,				\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction)						\
											\
	loop_map_out_as_unary_##out_interval##_##in_interval(				\
		return_policy, count_policy, delete_policy,				\
		out_as_unary_in_as_binary_##operator_policy, op_a, op_l, op_r,		\
		out_direction,								\
		in_as_binary, in_direction)



/************************************************************************************************************************/

#define loop_map(									\
		return_policy, count_policy, delete_policy,				\
		operator_policy, op_a, op_l, op_r,					\
		out_arity, out_interval, out_direction,					\
		in_arity, in_interval, in_direction)					\
											\
	loop_map_##out_arity##_##in_arity(						\
		return_policy, count_policy, delete_policy,				\
		operator_policy, op_a, op_l, op_r,					\
		out_interval, out_direction,						\
		in_interval, in_direction)

