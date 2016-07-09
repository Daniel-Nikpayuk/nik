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

/////// unary

/*
template<typename WNode, typename WPointer, typename EWPointer> \
static rtn label##_return(WPointer in, EWPointer end) \
{ \
	while (in != end) \
	{ \
		delete op *in; \
		delete (in)dir##dir; \
		count_type() \
	} \
 \
	_##return_type() \
}
*/



#define function_type_no_count_unary(rtn, label) \
 \
	template<typename WNode, typename WPointer> \
	static rtn label##_return(WPointer out, size_type n) \


		#define function_type_no_return_no_count_unary()		function_type_no_count_unary(void, no)
		#define function_type_with_return_no_count_unary()		function_type_no_count_unary(WPointer, with)


#define function_type_with_count_unary(rtn, label) \
 \
	template<typename WNode, typename WPointer> \
	static rtn label##_return(size_type & count, WPointer out, size_type n) \


		#define function_type_no_return_with_count_unary()		function_type_with_count_unary(void, no)
		#define function_type_with_return_with_count_unary()		function_type_with_count_unary(WPointer, with)


/////// unary_constant


#define function_type_no_count_unary_constant(rtn, label) \
 \
	template<typename WNode, typename WPointer, typename ValueType> \
	static rtn label##_return(WPointer out, size_type n, ValueType in) \


		#define function_type_no_return_no_count_unary_constant()	function_type_no_count_unary_constant(void, no)
		#define function_type_with_return_no_count_unary_constant()	function_type_no_count_unary_constant(WPointer, with)


#define function_type_with_count_unary_constant(rtn, label) \
 \
	template<typename WNode, typename WPointer, typename ValueType> \
	static rtn label##_return(size_type & count, WPointer out, size_type n, ValueType in) \


		#define function_type_no_return_with_count_unary_constant()	function_type_with_count_unary_constant(void, no)
		#define function_type_with_return_with_count_unary_constant()	function_type_with_count_unary_constant(WPointer, with)


/////// unary_new


#define function_type_no_count_unary_new(rtn, label) \
 \
	template<typename Node, typename WNode, typename WPointer> \
	static rtn label##_return(WPointer out, size_type n) \


		#define function_type_no_return_no_count_unary_new()		function_type_no_count_unary_new(void, no)
		#define function_type_with_return_no_count_unary_new()		function_type_no_count_unary_new(WPointer, with)


#define function_type_with_count_unary_new(rtn, label) \
 \
	template<typename Node, typename WNode, typename WPointer> \
	static rtn label##_return(size_type & count, WPointer out, size_type n) \


		#define function_type_no_return_with_count_unary_new()		function_type_with_count_unary_new(void, no)
		#define function_type_with_return_with_count_unary_new()	function_type_with_count_unary_new(WPointer, with)


/////// unary_new_brackets


#define function_type_no_count_unary_new_brackets(rtn, label) \
 \
	template<typename Node, typename WNode, typename WPointer> \
	static rtn label##_return(WPointer out, size_type n, size_type in) \


		#define function_type_no_return_no_count_unary_new_brackets()	function_type_no_count_unary_new_brackets(void, no)
		#define function_type_with_return_no_count_unary_new_brackets()	function_type_no_count_unary_new_brackets(WPointer, with)


#define function_type_with_count_unary_new_brackets(rtn, label) \
 \
	template<typename Node, typename WNode, typename WPointer> \
	static rtn label##_return(size_type & count, WPointer out, size_type n, size_type in) \


		#define function_type_no_return_with_count_unary_new_brackets()	function_type_with_count_unary_new_brackets(void, no)
		#define function_type_with_return_with_count_unary_new_brackets()function_type_with_count_unary_new_brackets(WPointer, with)


/////// unary_delete, unary_delete_brackets


#define function_type_no_count_unary_delete(rtn, label) \
 \
	template<typename WNode, typename WPointer, typename EWPointer> \
	static rtn label##_return(WPointer out, EWPointer end) \


		#define function_type_no_return_no_count_unary_delete()		function_type_no_count_unary_delete(void, no)
		#define function_type_with_return_no_count_unary_delete()	function_type_no_count_unary_delete(WPointer, with)

		#define function_type_no_return_no_count_unary_delete_brackets()function_type_no_count_unary_delete(void, no)
		#define function_type_with_return_no_count_unary_delete_brackets()function_type_no_count_unary_delete(WPointer, with)


#define function_type_with_count_unary_delete(rtn, label) \
 \
	template<typename WNode, typename WPointer, typename EWPointer> \
	static rtn label##_return(size_type & count, WPointer out, EWPointer end) \


		#define function_type_no_return_with_count_unary_delete()	function_type_with_count_unary_delete(void, no)
		#define function_type_with_return_with_count_unary_delete()	function_type_with_count_unary_delete(WPointer, with)

		#define function_type_no_return_with_count_unary_delete_brackets()function_type_with_count_unary_delete(void, no)
		#define function_type_with_return_with_count_unary_delete_brackets()function_type_with_count_unary_delete(WPointer, with)


/////// binary


#define function_type_no_count_binary(rtn, label) \
 \
	template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
	static rtn label##_return(WPointer out, RIterator in, ERIterator end) \


		#define function_type_no_return_no_count_binary()		function_type_no_count_binary(void, no)
		#define function_type_with_return_no_count_binary()		function_type_no_count_binary(WPointer, with)


#define function_type_with_count_binary(rtn, label) \
 \
	template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
	static rtn label##_return(size_type & count, WPointer out, RIterator in, ERIterator end) \


		#define function_type_no_return_with_count_binary()		function_type_with_count_binary(void, no)
		#define function_type_with_return_with_count_binary()		function_type_with_count_binary(WPointer, with)


/////// binary_new


#define function_type_no_count_binary_new(rtn, label) \
 \
	template<typename Node, typename WNode, typename WPointer, typename RPointer, typename ERPointer> \
	static rtn label##_return(WPointer out, RPointer in, ERPointer end) \


		#define function_type_no_return_no_count_binary_new()		function_type_no_count_binary_new(void, no)
		#define function_type_with_return_no_count_binary_new()		function_type_no_count_binary_new(WPointer, with)


#define function_type_with_count_binary_new(rtn, label) \
 \
	template<typename Node, typename WNode, typename WPointer, typename RPointer, typename ERPointer> \
	static rtn label##_return(size_type & count, WPointer out, RPointer in, ERPointer end) \


		#define function_type_no_return_with_count_binary_new()		function_type_with_count_binary_new(void, no)
		#define function_type_with_return_with_count_binary_new()	function_type_with_count_binary_new(WPointer, with)


/////// trinary, trinary_brackets


#define function_type_no_count_trinary(rtn, label) \
 \
	template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
	static rtn label##_return(WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \


		#define function_type_no_return_no_count_trinary()		function_type_no_count_trinary(void, no)
		#define function_type_with_return_no_count_trinary()		function_type_no_count_trinary(WPointer, with)

		#define function_type_no_return_no_count_trinary_brackets()	function_type_no_count_trinary(void, no)
		#define function_type_with_return_no_count_trinary_brackets()	function_type_no_count_trinary(WPointer, with)


#define function_type_with_count_trinary(rtn, label) \
 \
	template<typename WNode, typename WPointer, typename RIterator1, typename RIterator2, typename ERIterator> \
	static rtn label##_return(size_type & count, WPointer out, RIterator1 in1, RIterator2 in2, ERIterator end2) \


		#define function_type_no_return_with_count_trinary()		function_type_with_count_trinary(void, no)
		#define function_type_with_return_with_count_trinary()		function_type_with_count_trinary(WPointer, with)

		#define function_type_no_return_with_count_trinary_brackets()	function_type_with_count_trinary(void, no)
		#define function_type_with_return_with_count_trinary_brackets()	function_type_with_count_trinary(WPointer, with)


/************************************************************************************************************************/

/*
	function_type:

*/


#define function_type(return_type, count_type, operator_type) \
	function_type_##return_type##_##count_type##_##operator_type() \


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	operator_type:

		unary
		unary_constant
		unary_new
		unary_new_brackets
		unary_delete
		unary_delete_brackets
		binary
		binary_new
		trinary
		trinary_brackets
*/


#define unary(opm, opl, opr)							opl(*out)opr; \


#define unary_constant(opm, opl, opr)						(*out)opm(in); \


#define unary_new(opm, opl, opr)						*out=new Node(); \


#define unary_new_brackets(opm, opl, opr)					*out=new Node[in]; \


#define unary_delete(opm, opl, opr)						delete *current; \
										delete current; \

#define unary_delete_brackets(opm, opl, opr)					delete [] *current; \
										delete current; \

#define binary(opm, opl, opr)							opl(*out)opm(*in)opr; \


#define binary_new(opm, opl, opr)						*out=new Node[*in]; \


#define trinary(opm, opl, opr)							*out=(*in1)opm(*in2); \


#define trinary_brackets(opm, opl, opr)						*out=(*in1)opm[*in2]; \


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	out_direction:

		out_as_forward
		out_as_backward
*/


#define out_direction(dir)							out=dir(out)=new WNode; \


	#define out_as_forward()						out_direction(+) \


	#define out_as_backward()						WPointer current=out; \
										out=new WNode; \
										+out=current; \


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#define in_direction_binary(dir)						dir##dir(in); \


	#define in_as_forward_binary()						in_direction_binary(+)
	#define in_as_forward_binary_new()					in_direction_binary(+)

	#define in_as_backward_binary()						in_direction_binary(-)
	#define in_as_backward_binary_new()					in_direction_binary(-)


#define in_direction_trinary(dir)						dir##dir(in1); \
										dir##dir(in2); \


	#define in_as_forward_trinary()						in_direction_trinary(+)
	#define in_as_forward_trinary_brackets()				in_direction_trinary(+)

	#define in_as_backward_trinary()					in_direction_trinary(-)
	#define in_as_backward_trinary_brackets()				in_direction_trinary(-)

/************************************************************************************************************************/

/*
	in_direction:

		in_as_forward
		in_as_backward
*/


#define in_as_forward(operator_type) \
	in_as_forward_##operator_type() \

#define in_as_backward(operator_type) \
	in_as_backward_##operator_type() \


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#define peek_type_binary(dir)							dir##in != end \


	#define no_peek_in_as_forward_binary()					peek_type_binary( )
	#define no_peek_in_as_backward_binary()					peek_type_binary( )

	#define no_peek_in_as_forward_binary_new()				peek_type_binary( )
	#define no_peek_in_as_backward_binary_new()				peek_type_binary( )

	#define with_peek_in_as_forward_binary()				peek_type_binary(+)
	#define with_peek_in_as_backward_binary()				peek_type_binary(-)

	#define with_peek_in_as_forward_binary_new()				peek_type_binary(+)
	#define with_peek_in_as_backward_binary_new()				peek_type_binary(-)


#define peek_type_trinary(dir)							dir##in2 != end2 \


	#define no_peek_in_as_forward_trinary()					peek_type_trinary( )
	#define no_peek_in_as_backward_trinary()				peek_type_trinary( )

	#define no_peek_in_as_forward_trinary_brackets()			peek_type_trinary( )
	#define no_peek_in_as_backward_trinary_brackets()			peek_type_trinary( )

	#define with_peek_in_as_forward_trinary()				peek_type_trinary(+)
	#define with_peek_in_as_backward_trinary()				peek_type_trinary(-)

	#define with_peek_in_as_forward_trinary_brackets()			peek_type_trinary(+)
	#define with_peek_in_as_backward_trinary_brackets()			peek_type_trinary(-)

/************************************************************************************************************************/

/*
	peek_type:

		no_peek
		with_peek
*/


#define no_peek(in_direction, operator_type) \
	no_peek_##in_direction##_##operator_type() \

#define with_peek(in_direction, operator_type) \
	with_peek_##in_direction##_##operator_type() \


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	count_type:

		no_count
		with_count
*/


#define no_count()


#define with_count()								++count; \


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	return_type:

		no_return
		with_return
*/


#define no_return()


#define _with_return()								return out; \


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
	return_type, count_type, delete_type, operator_type, opm, opl, opr, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	_##return_type() \
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[out, end]
*/

#define loop_map_out_as_nullary_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	operator_type(opm, opl, opr) \
	delete_type(in_arity) \
	count_type() \
 \
	_##return_type() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	(out, end]
*/

#define loop_map_out_as_nullary_in_as_opening( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(delete_type, in_arity) \
		operator_type(opm, opl, opr) \
		count_type() \
	} \
 \
	_##return_type() \
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	(out, end)
*/

#define loop_map_out_as_nullary_in_as_open( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	_##return_type() \
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
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> [out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	++n; \
 \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> [out, out + n)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_opening( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> [out, out + n-1), n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closing_in_as_open( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	--n; \
 \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> [out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_closing( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	--n; \
 \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	operator_type(opm, opl, opr) \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> [out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	operator_type(opm, opl, opr) \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> [out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_opening( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	--n; \
 \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	operator_type(opm, opl, opr) \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> [out, out + n-2], n > 1
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_closed_in_as_open( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	n-=2; \
 \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	operator_type(opm, opl, opr) \
	count_type() \
 \
	_##return_type() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> (out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_closing( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (n) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> (out, out + n+1]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> (out, out + n]
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_opening( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (n) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> (out, out + n-1], n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_opening_in_as_open( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	--n; \
 \
	while (n) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	[0, n) --> (out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_closing( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	out_direction() \
 \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[0, n] --> (out, out + n+2)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	++n; \
 \
	while (n) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
		--n; \
	} \
 \
	out_direction() \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n] --> (out, out + n+1)
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_opening( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (n) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
		--n; \
	} \
 \
	out_direction() \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(0, n) --> (out, out + n), n > 0
*/

#define loop_map_out_as_unary_in_as_nullary_out_as_open_in_as_open( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	out_direction() \
	--n; \
 \
	while (n) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
		--n; \
	} \
 \
	_##return_type() \
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
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/

#define loop_map_out_as_unary_out_as_closing_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	operator_type(opm, opl, opr) \
	out_direction() \
	delete_type(in_arity) \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/

#define loop_map_no_delete_out_as_unary_out_as_closing_in_as_opening( \
	return_type, count_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(no_delete, in_arity) \
		operator_type(opm, opl, opr) \
		out_direction() \
		count_type() \
	} \
 \
	_##return_type() \
}

/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/

#define loop_map_with_delete_out_as_unary_out_as_closing_in_as_opening( \
	return_type, count_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(with_delete, in_arity) \
		count_type() \
	} \
 \
	operator_type(opm, opl, opr) \
	out_direction() \
	with_delete(in_arity) \
	count_type() \
 \
	_##return_type() \
}

#define loop_map_out_as_unary_out_as_closing_in_as_opening( \
		return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
	loop_map_##delete_type##_out_as_unary_out_as_closing_in_as_opening( \
		return_type, count_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction)


/************************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/

#define loop_map_no_delete_out_as_unary_out_as_closing_in_as_open( \
	return_type, count_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(no_delete, in_arity) \
		count_type() \
	} \
 \
	_##return_type() \
}

/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/

#define loop_map_with_delete_out_as_unary_out_as_closing_in_as_open( \
	return_type, count_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	in_direction(no_delete, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(with_delete, in_arity) \
		count_type() \
	} \
 \
	_##return_type() \
}

#define loop_map_out_as_unary_out_as_closing_in_as_open( \
		return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
	loop_map_##delete_type##_out_as_unary_out_as_closing_in_as_open( \
		return_type, count_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction)


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/

#define loop_map_out_as_unary_out_as_closed_in_as_closing( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (with_peek(in_direction, operator_type)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	operator_type(opm, opl, opr) \
	in_direction(delete_type, in_arity) \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/

#define loop_map_out_as_unary_out_as_closed_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	operator_type(opm, opl, opr) \
	delete_type(in_arity) \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/

#define loop_map_out_as_unary_out_as_closed_in_as_opening( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	in_direction(delete_type, in_arity) \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	operator_type(opm, opl, opr) \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/

#define loop_map_out_as_unary_out_as_closed_in_as_open( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	in_direction(delete_type, in_arity) \
 \
	while (with_peek(in_direction, operator_type)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	operator_type(opm, opl, opr) \
	count_type() \
 \
	_##return_type() \
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


#define loop_map_out_as_unary_out_as_opening_in_as_closing( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/

#define loop_map_out_as_unary_out_as_opening_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	out_direction() \
	operator_type(opm, opl, opr) \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/

#define loop_map_out_as_unary_out_as_opening_in_as_opening( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(delete_type, in_arity) \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/

#define loop_map_out_as_unary_out_as_opening_in_as_open( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (with_peek(in_direction, operator_type)) \
	{ \
		in_direction(delete_type, in_arity) \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
	} \
 \
	_##return_type() \
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


#define loop_map_out_as_unary_out_as_open_in_as_closing( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	out_direction() \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/

#define loop_map_out_as_unary_out_as_open_in_as_closed( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		out_direction() \
		operator_type(opm, opl, opr) \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	out_direction() \
	operator_type(opm, opl, opr) \
	out_direction() \
	count_type() \
 \
	_##return_type() \
}


/************************************************************************************************************************/

#define loop_map_out_as_unary_out_as_open_in_as_opening( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	while (no_peek(in_arity, in_direction)) \
	{ \
		in_direction(delete_type, in_arity) \
		out_direction() \
		operator_type(opm, opl, opr) \
		count_type() \
	} \
 \
	out_direction() \
 \
	_##return_type() \
}


/************************************************************************************************************************/

#define loop_map_out_as_unary_out_as_open_in_as_open( \
	return_type, count_type, delete_type, operator_type, opm, opl, opr, out_direction, in_arity, in_direction) \
function_type(return_type, count_type, operator_type) \
{ \
	in_direction(delete_type, in_arity) \
	out_direction() \
 \
	while (no_peek(in_arity, in_direction)) \
	{ \
		operator_type(opm, opl, opr) \
		out_direction() \
		in_direction(delete_type, in_arity) \
		count_type() \
	} \
 \
	_##return_type() \
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	out_type:

		out_as_closing
		out_as_closed
		out_as_opening
		out_as_open

	in_type:

		in_as_closing
		in_as_closed
		in_as_opening
		in_as_open
*/

// out as nullary


#define loop_map_out_as_nullary_in_as_unary(				\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_type, out_direction,				\
		in_type, in_direction)					\
									\
	loop_map_out_as_nullary_##out_type##_##in_type(			\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		in_as_unary, in_direction)


// out as unary


#define loop_map_out_as_unary_in_as_nullary(				\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_type, out_direction,				\
		in_type, in_direction)					\
									\
	loop_map_out_as_unary_in_as_nullary_##out_type##_##in_type(	\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_direction)						\

#define loop_map_out_as_unary_in_as_unary(				\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_type, out_direction,				\
		in_type, in_direction)					\
									\
	loop_map_out_as_unary_##out_type##_##in_type(			\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_direction,						\
		in_as_unary, in_direction)

#define loop_map_out_as_unary_in_as_binary(				\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_type, out_direction,				\
		in_type, in_direction)					\
									\
	loop_map_out_as_unary_##out_type##_##in_type(			\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_direction,						\
		in_as_binary, in_direction)



/************************************************************************************************************************/

#define loop_map(							\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_arity, out_type, out_direction,			\
		in_arity, in_type, in_direction)			\
									\
	loop_map_##out_arity##_##in_arity(				\
		return_type, count_type, delete_type,			\
		operator_type, opm, opl, opr,				\
		out_type, out_direction,				\
		in_type, in_direction)

