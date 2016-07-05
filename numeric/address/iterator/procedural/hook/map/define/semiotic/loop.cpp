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
	Constraints:

	closing:	[0, n) --> [out, out + n)
	closed:		[0, n) --> [out, out + n-1], n > 0
	opening:	[0, n) --> (out, out + n]
	open:		[0, n) --> (out, out + n+1)
*/

/************************************************************************************************************************/

/*
	Constraints:

	closed:		[0, n) --> [out, out + n-1], n > 0
	closing:	[0, n) --> [out, out + n)
	open:		[0, n) --> (out, out + n+1)
	opening:	[0, n) --> (out, out + n]
*/

/************************************************************************************************************************/

/*
	Constraints:

	closed:		[0, n) --> [out, out + n-1], n > 0
	closing:	[0, n) --> [out, out + n)
	open:		[0, n) --> (out, out + n+1)
	opening:	[0, n) --> (out, out + n]
*/

/************************************************************************************************************************/

/*
	Constraints:

	closed:		[0, n) --> [out, out + n-1], n > 0
	closing:	[0, n) --> [out, out + n)
	open:		[0, n) --> (out, out + n+1)
	opening:	[0, n) --> (out, out + n]
*/

/************************************************************************************************************************/

/*
	Constraints:

	closed:		[in, end) --> [out, out + (end-in)-1], end-in > 0
	closing:	[in, end) --> [out, out + (end-in))
	open:		[in, end) --> (out, out + (end-in)+1)
	opening:	[in, end) --> (out, out + (end-in)]
*/

/************************************************************************************************************************/

/*
	Constraints:

	closed:		[in, end) --> [out, out + (end-in)-1], end-in > 0
	closing:	[in, end) --> [out, out + (end-in))
	open:		[in, end) --> (out, out + (end-in)+1)
	opening:	[in, end) --> (out, out + (end-in)]
*/

/************************************************************************************************************************/

/*
	Constraints:

	closed:		[in2, end2) --> [out, out + (end2-in2)-1], end2-in2 > 0
	closing:	[in2, end2) --> [out, out + (end2-in2))
	open:		[in2, end2) --> (out, out + (end2-in2)+1)
	opening:	[in2, end2) --> (out, out + (end2-in2)]
*/

/************************************************************************************************************************/

/*
	Constraints:

	closed:		[in2, end2) --> [out, out + (end2-in2)-1], end2-in2 > 0
	closing:	[in2, end2) --> [out, out + (end2-in2))
	open:		[in2, end2) --> (out, out + (end2-in2)+1)
	opening:	[in2, end2) --> (out, out + (end2-in2)]
*/

/************************************************************************************************************************/

/*
	Constraints:

	closing:	[out, end) --> [out, end)
*/

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#define operate_on_out_unary(op, lp, rp)						lp(*out)rp; \


#define operate_on_out_unary_constant(op, lp, rp)					(*out)op(in); \


#define operate_on_out_unary_new(op, lp, rp)						*out=new Node(); \


#define operate_on_out_unary_new_brackets(op, lp, rp)					*out=new Node[in]; \


#define operate_on_out_unary_delete(op, lp, rp)						delete *current; \
											delete current; \

#define operate_on_out_unary_delete_brackets(op, lp, rp)				delete [] *current; \
											delete current; \

#define operate_on_out_binary(op, lp, rp)						lp(*out)op(*in)rp; \


#define operate_on_out_binary_new(op, lp, rp)						*out=new Node[*in]; \


#define operate_on_out_trinary(op, lp, rp)						*out=(*in1)op(*in2); \


#define operate_on_out_trinary_brackets(op, lp, rp)					*out=(*in1)op[*in2]; \

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

#define operate_on_out(operator_type, op, lp, rp) \
	operate_on_out_##operator_type(op, lp, rp) \

/************************************************************************************************************************/

#undef operate_on_out_unary
#undef operate_on_out_unary_constant
#undef operate_on_out_unary_new
#undef operate_on_out_unary_new_brackets
#undef operate_on_out_unary_delete
#undef operate_on_out_unary_delete_brackets
#undef operate_on_out_binary
#undef operate_on_out_binary_new
#undef operate_on_out_trinary
#undef operate_on_out_trinary_brackets

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#define direct_out_as(dir, inv)								out=dir(out)=new WNode; \

	#define direct_out_out_as_forward()						direct_out_as(+, -)

//

	#define direct_out_out_as_backward()						WPointer current=out; \
											out=new WNode; \
											+out=current; \

/************************************************************************************************************************/

/*
	out_direction:

		out_as_forward
		out_as_backward
*/

#define direct_out(out_direction) \
	direct_out_##out_direction() \

/************************************************************************************************************************/

#undef direct_out_as

	#undef direct_out_out_as_forward
	#undef direct_out_out_as_backward

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#define direct_in_unary(dir, inv)							--n; \


	#define direct_in_unary_in_as_forward()						direct_in_unary(+, -)
	#define direct_in_unary_constant_in_as_forward()				direct_in_unary(+, -)
	#define direct_in_unary_new_in_as_forward()					direct_in_unary(+, -)
	#define direct_in_unary_new_brackets_in_as_forward()				direct_in_unary(+, -)

//

	#define direct_in_unary_in_as_backward()					direct_in_unary(-, +)
	#define direct_in_unary_constant_in_as_backward()				direct_in_unary(-, +)
	#define direct_in_unary_new_in_as_backward()					direct_in_unary(-, +)
	#define direct_in_unary_new_brackets_in_as_backward()				direct_in_unary(-, +)


#define direct_in_delete(dir, inv)							WPointer current=out; \
											dir##dir(out); \


	#define direct_in_unary_delete_in_as_forward()					direct_in_delete(+, -)
	#define direct_in_unary_delete_brackets_in_as_forward()				direct_in_delete(+, -)

//

	#define direct_in_unary_delete_in_as_backward()					direct_in_delete(-, +)
	#define direct_in_unary_delete_brackets_in_as_backward()			direct_in_delete(-, +)


#define direct_in_binary(dir, inv)							dir##dir(in); \


	#define direct_in_binary_in_as_forward()					direct_in_binary(+, -)
	#define direct_in_binary_new_in_as_forward()					direct_in_binary(+, -)

//

	#define direct_in_binary_in_as_backward()					direct_in_binary(-, +)
	#define direct_in_binary_new_in_as_backward()					direct_in_binary(-, +)


#define direct_in_trinary(dir, inv)							dir##dir(in1); \
											dir##dir(in2); \


	#define direct_in_trinary_in_as_forward()					direct_in_trinary(+, -)
	#define direct_in_trinary_brackets_in_as_forward()				direct_in_trinary(+, -)

//

	#define direct_in_trinary_in_as_backward()					direct_in_trinary(-, +)
	#define direct_in_trinary_brackets_in_as_backward()				direct_in_trinary(-, +)

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

#define direct_in(operator_type, in_direction) \
	direct_in_##index0##_##index1(dir, inv) \

/************************************************************************************************************************/

#undef direct_in_unary

	#undef direct_in_unary_in_as_forward
	#undef direct_in_unary_constant_in_as_forward
	#undef direct_in_unary_new_in_as_forward
	#undef direct_in_unary_new_brackets_in_as_forward

	#undef direct_in_unary_in_as_backward
	#undef direct_in_unary_constant_in_as_backward
	#undef direct_in_unary_new_in_as_backward
	#undef direct_in_unary_new_brackets_in_as_backward

#undef direct_in_delete

	#undef direct_in_unary_delete_in_as_forward
	#undef direct_in_unary_delete_brackets_in_as_forward

	#undef direct_in_unary_delete_in_as_backward
	#undef direct_in_unary_delete_brackets_in_as_backward

#undef direct_in_binary

	#undef direct_in_binary_in_as_forward
	#undef direct_in_binary_new_in_as_forward

	#undef direct_in_binary_in_as_backward
	#undef direct_in_binary_new_in_as_backward

#undef direct_in_trinary

	#undef direct_in_trinary_in_as_forward
	#undef direct_in_trinary_brackets_in_as_forward

	#undef direct_in_trinary_in_as_backward
	#undef direct_in_trinary_brackets_in_as_backward

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/////// unary


#define function_identifier_no_count_unary(rtn, type)			template<typename WNode, typename WPointer> \
									static rtn type##_return(WPointer out, size_type n) \

	#define function_identifier_no_return_no_count_unary()			function_identifier_no_count_unary(void, no)
	#define function_identifier_with_return_no_count_unary()		function_identifier_no_count_unary(WPointer, with)

#define function_identifier_with_count_unary(rtn, type)			template<typename WNode, typename WPointer> \
									static rtn type##_return(size_type & count, WPointer out, size_type n)\

	#define function_identifier_no_return_with_count_unary()		function_identifier_with_count_unary(void, no)
	#define function_identifier_with_return_with_count_unary()		function_identifier_with_count_unary(WPointer, with)


/////// unary_constant


#define function_identifier_no_count_unary_constant(rtn, type)		template<typename WNode, typename WPointer, typename ValueType> \
									static rtn type##_return(WPointer out, size_type n, ValueType in) \

	#define function_identifier_no_return_no_count_unary_constant()		function_identifier_no_count_unary_constant(void, no)
	#define function_identifier_with_return_no_count_unary_constant()	function_identifier_no_count_unary_constant(WPointer, with)

#define function_identifier_with_count_unary_constant(rtn, type)	template<typename WNode, typename WPointer, typename ValueType> \
									static rtn type##_return(size_type & count, \
											WPointer out, size_type n, ValueType in) \

	#define function_identifier_no_return_with_count_unary_constant()	function_identifier_with_count_unary_constant(void, no)
	#define function_identifier_with_return_with_count_unary_constant()	function_identifier_with_count_unary_constant(WPointer, with)


/////// unary_new


#define function_identifier_no_count_unary_new(rtn, type)		template<typename Node, typename WNode, typename WPointer> \
									static rtn type##_return(WPointer out, size_type n) \

	#define function_identifier_no_return_no_count_unary_new()		function_identifier_no_count_unary_new(void, no)
	#define function_identifier_with_return_no_count_unary_new()		function_identifier_no_count_unary_new(WPointer, with)

#define function_identifier_with_count_unary_new(rtn, type)		template<typename Node, typename WNode, typename WPointer> \
									static rtn type##_return(size_type & count, WPointer out, size_type n)\

	#define function_identifier_no_return_with_count_unary_new()		function_identifier_with_count_unary_new(void, no)
	#define function_identifier_with_return_with_count_unary_new()		function_identifier_with_count_unary_new(WPointer, with)


/////// unary_new_brackets


#define function_identifier_no_count_unary_new_brackets(rtn, type)	template<typename Node, typename WNode, typename WPointer> \
									static rtn type##_return(WPointer out, size_type n, size_type in) \

	#define function_identifier_no_return_no_count_unary_new_brackets()	function_identifier_no_count_unary_new_brackets(void, no)
	#define function_identifier_with_return_no_count_unary_new_brackets()	function_identifier_no_count_unary_new_brackets(WPointer, with)

#define function_identifier_with_count_unary_new_brackets(rtn, type)	template<typename Node, typename WNode, typename WPointer> \
									static rtn type##_return(size_type & count, \
											WPointer out, size_type n, size_type in) \

	#define function_identifier_no_return_with_count_unary_new_brackets()	function_identifier_with_count_unary_new_brackets(void, no)
	#define function_identifier_with_return_with_count_unary_new_brackets()	function_identifier_with_count_unary_new_brackets(WPointer, with)


/////// unary_delete, unary_delete_brackets


#define function_identifier_no_count_unary_delete(rtn, type)		template<typename WNode, typename WPointer, typename EWPointer> \
									static rtn type##_return(WPointer out, EWPointer end) \

	#define function_identifier_no_return_no_count_unary_delete()		function_identifier_no_count_unary_delete(void, no)
	#define function_identifier_with_return_no_count_unary_delete()		function_identifier_no_count_unary_delete(WPointer, with)

	#define function_identifier_no_return_no_count_unary_delete_brackets()	function_identifier_no_count_unary_delete(void, no)
	#define function_identifier_with_return_no_count_unary_delete_brackets()function_identifier_no_count_unary_delete(WPointer, with)

#define function_identifier_with_count_unary_delete(rtn, type)		template<typename WNode, typename WPointer, typename EWPointer> \
									static rtn type##_return(size_type & count, \
											WPointer out, EWPointer end) \

	#define function_identifier_no_return_with_count_unary_delete()		function_identifier_with_count_unary_delete(void, no)
	#define function_identifier_with_return_with_count_unary_delete()	function_identifier_with_count_unary_delete(WPointer, with)

	#define function_identifier_no_return_with_count_unary_delete_brackets()function_identifier_with_count_unary_delete(void, no)
	#define function_identifier_with_return_with_count_unary_delete_brackets()function_identifier_with_count_unary_delete(WPointer, with)


/////// binary


#define function_identifier_no_count_binary(rtn, type)			template<typename WNode, typename WPointer, \
										typename RIterator, typename ERIterator> \
									static rtn type##_return(WPointer out, RIterator in, ERIterator end) \

	#define function_identifier_no_return_no_count_binary()			function_identifier_no_count_binary(void, no)
	#define function_identifier_with_return_no_count_binary()		function_identifier_no_count_binary(WPointer, with)

#define function_identifier_with_count_binary(rtn, type)		template<typename WNode, typename WPointer, \
										typename RIterator, typename ERIterator> \
									static rtn type##_return(size_type & count, \
											WPointer out, RIterator in, ERIterator end) \

	#define function_identifier_no_return_with_count_binary()		function_identifier_with_count_binary(void, no)
	#define function_identifier_with_return_with_count_binary()		function_identifier_with_count_binary(WPointer, with)


/////// binary_new


#define function_identifier_no_count_binary_new(rtn, type)		template<typename Node, typename WNode, \
										typename WPointer, typename RPointer, typename ERPointer> \
									static rtn type##_return(WPointer out, RPointer in, ERPointer end) \

	#define function_identifier_no_return_no_count_binary_new()		function_identifier_no_count_binary_new(void, no)
	#define function_identifier_with_return_no_count_binary_new()		function_identifier_no_count_binary_new(WPointer, with)

#define function_identifier_with_count_binary_new(rtn, type)		template<typename Node, typename WNode, \
										typename WPointer, typename RPointer, typename ERPointer> \
									static rtn type##_return(size_type & count, \
											WPointer out, RPointer in, ERPointer end) \

	#define function_identifier_no_return_with_count_binary_new()		function_identifier_with_count_binary_new(void, no)
	#define function_identifier_with_return_with_count_binary_new()		function_identifier_with_count_binary_new(WPointer, with)


/////// trinary, trinary_brackets


#define function_identifier_no_count_trinary(rtn, type)			template<typename WNode, typename WPointer, \
										typename RIterator1, typename RIterator2, typename ERIterator>\
									static rtn type##_return(WPointer out, \
											RIterator1 in1, RIterator2 in2, ERIterator end2) \

	#define function_identifier_no_return_no_count_trinary()		function_identifier_no_count_trinary(void, no)
	#define function_identifier_with_return_no_count_trinary()		function_identifier_no_count_trinary(WPointer, with)

	#define function_identifier_no_return_no_count_trinary_brackets()	function_identifier_no_count_trinary(void, no)
	#define function_identifier_with_return_no_count_trinary_brackets()	function_identifier_no_count_trinary(WPointer, with)

#define function_identifier_with_count_trinary(rtn, type)		template<typename WNode, typename WPointer, \
										typename RIterator1, typename RIterator2, typename ERIterator>\
									static rtn type##_return(size_type & count, WPointer out, \
											RIterator1 in1, RIterator2 in2, ERIterator end2) \

	#define function_identifier_no_return_with_count_trinary()		function_identifier_with_count_trinary(void, no)
	#define function_identifier_with_return_with_count_trinary()		function_identifier_with_count_trinary(WPointer, with)

	#define function_identifier_no_return_with_count_trinary_brackets()	function_identifier_with_count_trinary(void, no)
	#define function_identifier_with_return_with_count_trinary_brackets()	function_identifier_with_count_trinary(WPointer, with)

/************************************************************************************************************************/

/*
	return_type:

		no_return
		with_return

	count_type:

		no_count
		with_count

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

#define function_identifier(return_type, count_type, operator_type) \
	function_identifier_##return_type##_##count_type##_##operator_type(rtn, type) \

/************************************************************************************************************************/

#undef function_identifier_no_count_unary

	#undef function_identifier_no_return_no_count_unary
	#undef function_identifier_with_return_no_count_unary

#undef function_identifier_with_count_unary

	#undef function_identifier_no_return_with_count_unary
	#undef function_identifier_with_return_with_count_unary

//

#undef function_identifier_no_count_unary_constant

	#undef function_identifier_no_return_no_count_unary_constant
	#undef function_identifier_with_return_no_count_unary_constant

#undef function_identifier_with_count_unary_constant

	#undef function_identifier_no_return_with_count_unary_constant
	#undef function_identifier_with_return_with_count_unary_constant

//

#undef function_identifier_no_count_unary_new

	#undef function_identifier_no_return_no_count_unary_new
	#undef function_identifier_with_return_no_count_unary_new

#undef function_identifier_with_count_unary_new

	#undef function_identifier_no_return_with_count_unary_new
	#undef function_identifier_with_return_with_count_unary_new

//

#undef function_identifier_no_count_unary_new_brackets

	#undef function_identifier_no_return_no_count_unary_new_brackets
	#undef function_identifier_with_return_no_count_unary_new_brackets

#undef function_identifier_with_count_unary_new_brackets

	#undef function_identifier_no_return_with_count_unary_new_brackets
	#undef function_identifier_with_return_with_count_unary_new_brackets

//

#undef function_identifier_no_count_unary_delete

	#undef function_identifier_no_return_no_count_unary_delete
	#undef function_identifier_with_return_no_count_unary_delete
	#undef function_identifier_no_return_no_count_unary_delete_brackets
	#undef function_identifier_with_return_no_count_unary_delete_brackets

#undef function_identifier_with_count_unary_delete

	#undef function_identifier_no_return_with_count_unary_delete
	#undef function_identifier_with_return_with_count_unary_delete
	#undef function_identifier_no_return_with_count_unary_delete_brackets
	#undef function_identifier_with_return_with_count_unary_delete_brackets

//

#undef function_identifier_no_count_binary

	#undef function_identifier_no_return_no_count_binary
	#undef function_identifier_with_return_no_count_binary

#undef function_identifier_with_count_binary

	#undef function_identifier_no_return_with_count_binary
	#undef function_identifier_with_return_with_count_binary

//

#undef function_identifier_no_count_binary_new

	#undef function_identifier_no_return_no_count_binary_new
	#undef function_identifier_with_return_no_count_binary_new

#undef function_identifier_with_count_binary_new

	#undef function_identifier_no_return_with_count_binary_new
	#undef function_identifier_with_return_with_count_binary_new

//

#undef function_identifier_no_count_trinary

	#undef function_identifier_no_return_no_count_trinary
	#undef function_identifier_with_return_no_count_trinary
	#undef function_identifier_no_return_no_count_trinary_brackets
	#undef function_identifier_with_return_no_count_trinary_brackets

#undef function_identifier_with_count_trinary

	#undef function_identifier_no_return_with_count_trinary
	#undef function_identifier_with_return_with_count_trinary
	#undef function_identifier_no_return_with_count_trinary_brackets
	#undef function_identifier_with_return_with_count_trinary_brackets

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#define before_loop_out_as_closed_in_as_closed(out_direction, operator_type, in_direction) \

#define before_loop_out_as_closed_in_as_closing(out_direction, operator_type, in_direction) \

#define before_loop_out_as_closed_in_as_open(out_direction, operator_type, in_direction)	direct_in(operator_type, in_direction) \

#define before_loop_out_as_closed_in_as_opening(out_direction, operator_type, in_direction)	direct_in(operator_type, in_direction) \

//

#define before_loop_out_as_closing_in_as_closed(out_direction, operator_type, in_direction) \

#define before_loop_out_as_closing_in_as_closing(out_direction, operator_type, in_direction) \

#define before_loop_out_as_closing_in_as_open(out_direction, operator_type, in_direction) \

#define before_loop_out_as_closing_in_as_opening(out_direction, operator_type, in_direction)	direct_in(operator_type, in_direction) \

//

#define before_loop_out_as_open_in_as_closed(out_direction, operator_type, in_direction) \

#define before_loop_out_as_open_in_as_closing(out_direction, operator_type, in_direction)	direct_out(out_direction) \

#define before_loop_out_as_open_in_as_open(out_direction, operator_type, in_direction)		direct_out(out_direction) \
												direct_in(operator_type, in_direction) \

#define before_loop_out_as_open_in_as_opening(out_direction, operator_type, in_direction) \

//

#define before_loop_out_as_opening_in_as_closed(out_direction, operator_type, in_direction) \

#define before_loop_out_as_opening_in_as_closing(out_direction, operator_type, in_direction) \

#define before_loop_out_as_opening_in_as_open(out_direction, operator_type, in_direction) \

#define before_loop_out_as_opening_in_as_opening(out_direction, operator_type, in_direction) \

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

#define before_loop(out_type, out_direction, operator_type, in_type, in_direction) \
	before_loop_##out_type##_##in_type(out_direction, operator_type, in_direction) \

/************************************************************************************************************************/

#undef before_loop_out_as_closed_in_as_closed
#undef before_loop_out_as_closed_in_as_closing
#undef before_loop_out_as_closed_in_as_open
#undef before_loop_out_as_closed_in_as_opening

#undef before_loop_out_as_closing_in_as_closed
#undef before_loop_out_as_closing_in_as_closing
#undef before_loop_out_as_closing_in_as_open
#undef before_loop_out_as_closing_in_as_opening

#undef before_loop_out_as_open_in_as_closed
#undef before_loop_out_as_open_in_as_closing
#undef before_loop_out_as_open_in_as_open
#undef before_loop_out_as_open_in_as_opening

#undef before_loop_out_as_opening_in_as_closed
#undef before_loop_out_as_opening_in_as_closing
#undef before_loop_out_as_opening_in_as_open
#undef before_loop_out_as_opening_in_as_opening

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

#define loop_condition_unary(dir, inv)								n


	#define loop_condition_out_as_closed_unary_in_as_closed()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_in_as_closing()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_in_as_open()					loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_in_as_opening()				loop_condition_unary( ,  )

	#define loop_condition_out_as_closing_unary_in_as_closed()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_in_as_closing()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_in_as_open()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_in_as_opening()				loop_condition_unary( ,  )

	#define loop_condition_out_as_open_unary_in_as_closed()					loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_in_as_closing()				loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_in_as_open()					loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_in_as_opening()				loop_condition_unary( ,  )

	#define loop_condition_out_as_opening_unary_in_as_closed()				loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_in_as_closing()				loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_in_as_open()				loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_in_as_opening()				loop_condition_unary( ,  )

//

	#define loop_condition_out_as_closed_unary_constant_in_as_closed()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_constant_in_as_closing()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_constant_in_as_open()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_constant_in_as_opening()			loop_condition_unary( ,  )

	#define loop_condition_out_as_closing_unary_constant_in_as_closed()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_constant_in_as_closing()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_constant_in_as_open()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_constant_in_as_opening()			loop_condition_unary( ,  )

	#define loop_condition_out_as_open_unary_constant_in_as_closed()			loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_constant_in_as_closing()			loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_constant_in_as_open()				loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_constant_in_as_opening()			loop_condition_unary( ,  )

	#define loop_condition_out_as_opening_unary_constant_in_as_closed()			loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_constant_in_as_closing()			loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_constant_in_as_open()			loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_constant_in_as_opening()			loop_condition_unary( ,  )

//

	#define loop_condition_out_as_closed_unary_new_in_as_closed()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_new_in_as_closing()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_new_in_as_open()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_new_in_as_opening()				loop_condition_unary( ,  )

	#define loop_condition_out_as_closing_unary_new_in_as_closed()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_new_in_as_closing()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_new_in_as_open()				loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_new_in_as_opening()				loop_condition_unary( ,  )

	#define loop_condition_out_as_open_unary_new_in_as_closed()				loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_new_in_as_closing()				loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_new_in_as_open()				loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_new_in_as_opening()				loop_condition_unary( ,  )

	#define loop_condition_out_as_opening_unary_new_in_as_closed()				loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_new_in_as_closing()				loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_new_in_as_open()				loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_new_in_as_opening()				loop_condition_unary( ,  )

//

	#define loop_condition_out_as_closed_unary_new_brackets_in_as_closed()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_new_brackets_in_as_closing()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_new_brackets_in_as_open()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closed_unary_new_brackets_in_as_opening()			loop_condition_unary( ,  )

	#define loop_condition_out_as_closing_unary_new_brackets_in_as_closed()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_new_brackets_in_as_closing()		loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_new_brackets_in_as_open()			loop_condition_unary( ,  )
	#define loop_condition_out_as_closing_unary_new_brackets_in_as_opening()		loop_condition_unary( ,  )

	#define loop_condition_out_as_open_unary_new_brackets_in_as_closed()			loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_new_brackets_in_as_closing()			loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_new_brackets_in_as_open()			loop_condition_unary( ,  )
	#define loop_condition_out_as_open_unary_new_brackets_in_as_opening()			loop_condition_unary( ,  )

	#define loop_condition_out_as_opening_unary_new_brackets_in_as_closed()			loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_new_brackets_in_as_closing()		loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_new_brackets_in_as_open()			loop_condition_unary( ,  )
	#define loop_condition_out_as_opening_unary_new_brackets_in_as_opening()		loop_condition_unary( ,  )


#define loop_condition_delete(dir, inv)								dir##out != end


	#define loop_condition_out_as_closed_unary_delete_in_as_closed()			loop_condition_delete( ,  )
	#define loop_condition_out_as_closed_unary_delete_in_as_closing()			loop_condition_delete( ,  )
	#define loop_condition_out_as_closed_unary_delete_in_as_open()				loop_condition_delete( ,  )
	#define loop_condition_out_as_closed_unary_delete_in_as_opening()			loop_condition_delete( ,  )

	#define loop_condition_out_as_closing_unary_delete_in_as_closed()			loop_condition_delete( ,  )
	#define loop_condition_out_as_closing_unary_delete_in_as_closing()			loop_condition_delete( ,  )
	#define loop_condition_out_as_closing_unary_delete_in_as_open()				loop_condition_delete( ,  )
	#define loop_condition_out_as_closing_unary_delete_in_as_opening()			loop_condition_delete( ,  )

	#define loop_condition_out_as_open_unary_delete_in_as_closed()				loop_condition_delete( ,  )
	#define loop_condition_out_as_open_unary_delete_in_as_closing()				loop_condition_delete( ,  )
	#define loop_condition_out_as_open_unary_delete_in_as_open()				loop_condition_delete( ,  )
	#define loop_condition_out_as_open_unary_delete_in_as_opening()				loop_condition_delete( ,  )

	#define loop_condition_out_as_opening_unary_delete_in_as_closed()			loop_condition_delete( ,  )
	#define loop_condition_out_as_opening_unary_delete_in_as_closing()			loop_condition_delete( ,  )
	#define loop_condition_out_as_opening_unary_delete_in_as_open()				loop_condition_delete( ,  )
	#define loop_condition_out_as_opening_unary_delete_in_as_opening()			loop_condition_delete( ,  )

//

	#define loop_condition_out_as_closed_unary_delete_brackets_in_as_closed()		loop_condition_delete( ,  )
	#define loop_condition_out_as_closed_unary_delete_brackets_in_as_closing()		loop_condition_delete( ,  )
	#define loop_condition_out_as_closed_unary_delete_brackets_in_as_open()			loop_condition_delete( ,  )
	#define loop_condition_out_as_closed_unary_delete_brackets_in_as_opening()		loop_condition_delete( ,  )

	#define loop_condition_out_as_closing_unary_delete_brackets_in_as_closed()		loop_condition_delete( ,  )
	#define loop_condition_out_as_closing_unary_delete_brackets_in_as_closing()		loop_condition_delete( ,  )
	#define loop_condition_out_as_closing_unary_delete_brackets_in_as_open()		loop_condition_delete( ,  )
	#define loop_condition_out_as_closing_unary_delete_brackets_in_as_opening()		loop_condition_delete( ,  )

	#define loop_condition_out_as_open_unary_delete_brackets_in_as_closed()			loop_condition_delete( ,  )
	#define loop_condition_out_as_open_unary_delete_brackets_in_as_closing()		loop_condition_delete( ,  )
	#define loop_condition_out_as_open_unary_delete_brackets_in_as_open()			loop_condition_delete( ,  )
	#define loop_condition_out_as_open_unary_delete_brackets_in_as_opening()		loop_condition_delete( ,  )

	#define loop_condition_out_as_opening_unary_delete_brackets_in_as_closed()		loop_condition_delete( ,  )
	#define loop_condition_out_as_opening_unary_delete_brackets_in_as_closing()		loop_condition_delete( ,  )
	#define loop_condition_out_as_opening_unary_delete_brackets_in_as_open()		loop_condition_delete( ,  )
	#define loop_condition_out_as_opening_unary_delete_brackets_in_as_opening()		loop_condition_delete( ,  )


#define loop_condition_binary(dir, inv)								dir##in != end


	#define loop_condition_out_as_closed_binary_in_as_closed()				loop_condition_binary( ,  )
	#define loop_condition_out_as_closed_binary_in_as_closing()				loop_condition_binary(+, -)
	#define loop_condition_out_as_closed_binary_in_as_open()				loop_condition_binary(+, -)
	#define loop_condition_out_as_closed_binary_in_as_opening()				loop_condition_binary( ,  )

	#define loop_condition_out_as_closing_binary_in_as_closed()				loop_condition_binary( ,  )
	#define loop_condition_out_as_closing_binary_in_as_closing()				loop_condition_binary( ,  )
	#define loop_condition_out_as_closing_binary_in_as_open()				loop_condition_binary( ,  )
	#define loop_condition_out_as_closing_binary_in_as_opening()				loop_condition_binary( ,  )

	#define loop_condition_out_as_open_binary_in_as_closed()				loop_condition_binary( ,  )
	#define loop_condition_out_as_open_binary_in_as_closing()				loop_condition_binary( ,  )
	#define loop_condition_out_as_open_binary_in_as_open()					loop_condition_binary( ,  )
	#define loop_condition_out_as_open_binary_in_as_opening()				loop_condition_binary( ,  )

	#define loop_condition_out_as_opening_binary_in_as_closed()				loop_condition_binary( ,  )
	#define loop_condition_out_as_opening_binary_in_as_closing()				loop_condition_binary( ,  )
	#define loop_condition_out_as_opening_binary_in_as_open()				loop_condition_binary(+, -)
	#define loop_condition_out_as_opening_binary_in_as_opening()				loop_condition_binary( ,  )

//

	#define loop_condition_out_as_closed_binary_new_in_as_closed()				loop_condition_binary( ,  )
	#define loop_condition_out_as_closed_binary_new_in_as_closing()				loop_condition_binary(+, -)
	#define loop_condition_out_as_closed_binary_new_in_as_open()				loop_condition_binary(+, -)
	#define loop_condition_out_as_closed_binary_new_in_as_opening()				loop_condition_binary( ,  )

	#define loop_condition_out_as_closing_binary_new_in_as_closed()				loop_condition_binary( ,  )
	#define loop_condition_out_as_closing_binary_new_in_as_closing()			loop_condition_binary( ,  )
	#define loop_condition_out_as_closing_binary_new_in_as_open()				loop_condition_binary( ,  )
	#define loop_condition_out_as_closing_binary_new_in_as_opening()			loop_condition_binary( ,  )

	#define loop_condition_out_as_open_binary_new_in_as_closed()				loop_condition_binary( ,  )
	#define loop_condition_out_as_open_binary_new_in_as_closing()				loop_condition_binary( ,  )
	#define loop_condition_out_as_open_binary_new_in_as_open()				loop_condition_binary( ,  )
	#define loop_condition_out_as_open_binary_new_in_as_opening()				loop_condition_binary( ,  )

	#define loop_condition_out_as_opening_binary_new_in_as_closed()				loop_condition_binary( ,  )
	#define loop_condition_out_as_opening_binary_new_in_as_closing()			loop_condition_binary( ,  )
	#define loop_condition_out_as_opening_binary_new_in_as_open()				loop_condition_binary(+, -)
	#define loop_condition_out_as_opening_binary_new_in_as_opening()			loop_condition_binary( ,  )


#define loop_condition_trinary(dir, inv)							dir##in2 != end2


	#define loop_condition_out_as_closed_trinary_in_as_closed()				loop_condition_trinary( ,  )
	#define loop_condition_out_as_closed_trinary_in_as_closing()				loop_condition_trinary(+, -)
	#define loop_condition_out_as_closed_trinary_in_as_open()				loop_condition_trinary(+, -)
	#define loop_condition_out_as_closed_trinary_in_as_opening()				loop_condition_trinary( ,  )

	#define loop_condition_out_as_closing_trinary_in_as_closed()				loop_condition_trinary( ,  )
	#define loop_condition_out_as_closing_trinary_in_as_closing()				loop_condition_trinary( ,  )
	#define loop_condition_out_as_closing_trinary_in_as_open()				loop_condition_trinary( ,  )
	#define loop_condition_out_as_closing_trinary_in_as_opening()				loop_condition_trinary( ,  )

	#define loop_condition_out_as_open_trinary_in_as_closed()				loop_condition_trinary( ,  )
	#define loop_condition_out_as_open_trinary_in_as_closing()				loop_condition_trinary( ,  )
	#define loop_condition_out_as_open_trinary_in_as_open()					loop_condition_trinary( ,  )
	#define loop_condition_out_as_open_trinary_in_as_opening()				loop_condition_trinary( ,  )

	#define loop_condition_out_as_opening_trinary_in_as_closed()				loop_condition_trinary( ,  )
	#define loop_condition_out_as_opening_trinary_in_as_closing()				loop_condition_trinary( ,  )
	#define loop_condition_out_as_opening_trinary_in_as_open()				loop_condition_trinary(+, -)
	#define loop_condition_out_as_opening_trinary_in_as_opening()				loop_condition_trinary( ,  )

//

	#define loop_condition_out_as_closed_trinary_brackets_in_as_closed()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_closed_trinary_brackets_in_as_closing()			loop_condition_trinary(+, -)
	#define loop_condition_out_as_closed_trinary_brackets_in_as_open()			loop_condition_trinary(+, -)
	#define loop_condition_out_as_closed_trinary_brackets_in_as_opening()			loop_condition_trinary( ,  )

	#define loop_condition_out_as_closing_trinary_brackets_in_as_closed()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_closing_trinary_brackets_in_as_closing()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_closing_trinary_brackets_in_as_open()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_closing_trinary_brackets_in_as_opening()			loop_condition_trinary( ,  )

	#define loop_condition_out_as_open_trinary_brackets_in_as_closed()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_open_trinary_brackets_in_as_closing()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_open_trinary_brackets_in_as_open()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_open_trinary_brackets_in_as_opening()			loop_condition_trinary( ,  )

	#define loop_condition_out_as_opening_trinary_brackets_in_as_closed()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_opening_trinary_brackets_in_as_closing()			loop_condition_trinary( ,  )
	#define loop_condition_out_as_opening_trinary_brackets_in_as_open()			loop_condition_trinary(+, -)
	#define loop_condition_out_as_opening_trinary_brackets_in_as_opening()			loop_condition_trinary( ,  )

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

#define loop_condition(out_type, operator_type, in_type) \
	loop_condition_##out_type##_##operator_type##_##in_type() \

/************************************************************************************************************************/

#undef loop_condition_unary

	#undef loop_condition_out_as_closed_unary_in_as_closed
	#undef loop_condition_out_as_closed_unary_in_as_closing
	#undef loop_condition_out_as_closed_unary_in_as_open
	#undef loop_condition_out_as_closed_unary_in_as_opening

	#undef loop_condition_out_as_closing_unary_in_as_closed
	#undef loop_condition_out_as_closing_unary_in_as_closing
	#undef loop_condition_out_as_closing_unary_in_as_open
	#undef loop_condition_out_as_closing_unary_in_as_opening

	#undef loop_condition_out_as_open_unary_in_as_closed
	#undef loop_condition_out_as_open_unary_in_as_closing
	#undef loop_condition_out_as_open_unary_in_as_open
	#undef loop_condition_out_as_open_unary_in_as_opening

	#undef loop_condition_out_as_opening_unary_in_as_closed
	#undef loop_condition_out_as_opening_unary_in_as_closing
	#undef loop_condition_out_as_opening_unary_in_as_open
	#undef loop_condition_out_as_opening_unary_in_as_opening

//

	#undef loop_condition_out_as_closed_unary_constant_in_as_closed
	#undef loop_condition_out_as_closed_unary_constant_in_as_closing
	#undef loop_condition_out_as_closed_unary_constant_in_as_open
	#undef loop_condition_out_as_closed_unary_constant_in_as_opening

	#undef loop_condition_out_as_closing_unary_constant_in_as_closed
	#undef loop_condition_out_as_closing_unary_constant_in_as_closing
	#undef loop_condition_out_as_closing_unary_constant_in_as_open
	#undef loop_condition_out_as_closing_unary_constant_in_as_opening

	#undef loop_condition_out_as_open_unary_constant_in_as_closed
	#undef loop_condition_out_as_open_unary_constant_in_as_closing
	#undef loop_condition_out_as_open_unary_constant_in_as_open
	#undef loop_condition_out_as_open_unary_constant_in_as_opening

	#undef loop_condition_out_as_opening_unary_constant_in_as_closed
	#undef loop_condition_out_as_opening_unary_constant_in_as_closing
	#undef loop_condition_out_as_opening_unary_constant_in_as_open
	#undef loop_condition_out_as_opening_unary_constant_in_as_opening

//

	#undef loop_condition_out_as_closed_unary_new_in_as_closed
	#undef loop_condition_out_as_closed_unary_new_in_as_closing
	#undef loop_condition_out_as_closed_unary_new_in_as_open
	#undef loop_condition_out_as_closed_unary_new_in_as_opening

	#undef loop_condition_out_as_closing_unary_new_in_as_closed
	#undef loop_condition_out_as_closing_unary_new_in_as_closing
	#undef loop_condition_out_as_closing_unary_new_in_as_open
	#undef loop_condition_out_as_closing_unary_new_in_as_opening

	#undef loop_condition_out_as_open_unary_new_in_as_closed
	#undef loop_condition_out_as_open_unary_new_in_as_closing
	#undef loop_condition_out_as_open_unary_new_in_as_open
	#undef loop_condition_out_as_open_unary_new_in_as_opening

	#undef loop_condition_out_as_opening_unary_new_in_as_closed
	#undef loop_condition_out_as_opening_unary_new_in_as_closing
	#undef loop_condition_out_as_opening_unary_new_in_as_open
	#undef loop_condition_out_as_opening_unary_new_in_as_opening

//

	#undef loop_condition_out_as_closed_unary_new_brackets_in_as_closed
	#undef loop_condition_out_as_closed_unary_new_brackets_in_as_closing
	#undef loop_condition_out_as_closed_unary_new_brackets_in_as_open
	#undef loop_condition_out_as_closed_unary_new_brackets_in_as_opening

	#undef loop_condition_out_as_closing_unary_new_brackets_in_as_closed
	#undef loop_condition_out_as_closing_unary_new_brackets_in_as_closing
	#undef loop_condition_out_as_closing_unary_new_brackets_in_as_open
	#undef loop_condition_out_as_closing_unary_new_brackets_in_as_opening

	#undef loop_condition_out_as_open_unary_new_brackets_in_as_closed
	#undef loop_condition_out_as_open_unary_new_brackets_in_as_closing
	#undef loop_condition_out_as_open_unary_new_brackets_in_as_open
	#undef loop_condition_out_as_open_unary_new_brackets_in_as_opening

	#undef loop_condition_out_as_opening_unary_new_brackets_in_as_closed
	#undef loop_condition_out_as_opening_unary_new_brackets_in_as_closing
	#undef loop_condition_out_as_opening_unary_new_brackets_in_as_open
	#undef loop_condition_out_as_opening_unary_new_brackets_in_as_opening

#undef loop_condition_delete

	#undef loop_condition_out_as_closed_unary_delete_in_as_closed
	#undef loop_condition_out_as_closed_unary_delete_in_as_closing
	#undef loop_condition_out_as_closed_unary_delete_in_as_open
	#undef loop_condition_out_as_closed_unary_delete_in_as_opening

	#undef loop_condition_out_as_closing_unary_delete_in_as_closed
	#undef loop_condition_out_as_closing_unary_delete_in_as_closing
	#undef loop_condition_out_as_closing_unary_delete_in_as_open
	#undef loop_condition_out_as_closing_unary_delete_in_as_opening

	#undef loop_condition_out_as_open_unary_delete_in_as_closed
	#undef loop_condition_out_as_open_unary_delete_in_as_closing
	#undef loop_condition_out_as_open_unary_delete_in_as_open
	#undef loop_condition_out_as_open_unary_delete_in_as_opening

	#undef loop_condition_out_as_opening_unary_delete_in_as_closed
	#undef loop_condition_out_as_opening_unary_delete_in_as_closing
	#undef loop_condition_out_as_opening_unary_delete_in_as_open
	#undef loop_condition_out_as_opening_unary_delete_in_as_opening

//

	#undef loop_condition_out_as_closed_unary_delete_brackets_in_as_closed
	#undef loop_condition_out_as_closed_unary_delete_brackets_in_as_closing
	#undef loop_condition_out_as_closed_unary_delete_brackets_in_as_open
	#undef loop_condition_out_as_closed_unary_delete_brackets_in_as_opening

	#undef loop_condition_out_as_closing_unary_delete_brackets_in_as_closed
	#undef loop_condition_out_as_closing_unary_delete_brackets_in_as_closing
	#undef loop_condition_out_as_closing_unary_delete_brackets_in_as_open
	#undef loop_condition_out_as_closing_unary_delete_brackets_in_as_opening

	#undef loop_condition_out_as_open_unary_delete_brackets_in_as_closed
	#undef loop_condition_out_as_open_unary_delete_brackets_in_as_closing
	#undef loop_condition_out_as_open_unary_delete_brackets_in_as_open
	#undef loop_condition_out_as_open_unary_delete_brackets_in_as_opening

	#undef loop_condition_out_as_opening_unary_delete_brackets_in_as_closed
	#undef loop_condition_out_as_opening_unary_delete_brackets_in_as_closing
	#undef loop_condition_out_as_opening_unary_delete_brackets_in_as_open
	#undef loop_condition_out_as_opening_unary_delete_brackets_in_as_opening

#undef loop_condition_binary

	#undef loop_condition_out_as_closed_binary_in_as_closed
	#undef loop_condition_out_as_closed_binary_in_as_closing
	#undef loop_condition_out_as_closed_binary_in_as_open
	#undef loop_condition_out_as_closed_binary_in_as_opening

	#undef loop_condition_out_as_closing_binary_in_as_closed
	#undef loop_condition_out_as_closing_binary_in_as_closing
	#undef loop_condition_out_as_closing_binary_in_as_open
	#undef loop_condition_out_as_closing_binary_in_as_opening

	#undef loop_condition_out_as_open_binary_in_as_closed
	#undef loop_condition_out_as_open_binary_in_as_closing
	#undef loop_condition_out_as_open_binary_in_as_open
	#undef loop_condition_out_as_open_binary_in_as_opening

	#undef loop_condition_out_as_opening_binary_in_as_closed
	#undef loop_condition_out_as_opening_binary_in_as_closing
	#undef loop_condition_out_as_opening_binary_in_as_open
	#undef loop_condition_out_as_opening_binary_in_as_opening

//

	#undef loop_condition_out_as_closed_binary_new_in_as_closed
	#undef loop_condition_out_as_closed_binary_new_in_as_closing
	#undef loop_condition_out_as_closed_binary_new_in_as_open
	#undef loop_condition_out_as_closed_binary_new_in_as_opening

	#undef loop_condition_out_as_closing_binary_new_in_as_closed
	#undef loop_condition_out_as_closing_binary_new_in_as_closing
	#undef loop_condition_out_as_closing_binary_new_in_as_open
	#undef loop_condition_out_as_closing_binary_new_in_as_opening

	#undef loop_condition_out_as_open_binary_new_in_as_closed
	#undef loop_condition_out_as_open_binary_new_in_as_closing
	#undef loop_condition_out_as_open_binary_new_in_as_open
	#undef loop_condition_out_as_open_binary_new_in_as_opening

	#undef loop_condition_out_as_opening_binary_new_in_as_closed
	#undef loop_condition_out_as_opening_binary_new_in_as_closing
	#undef loop_condition_out_as_opening_binary_new_in_as_open
	#undef loop_condition_out_as_opening_binary_new_in_as_opening

#undef loop_condition_trinary

	#undef loop_condition_out_as_closed_trinary_in_as_closed
	#undef loop_condition_out_as_closed_trinary_in_as_closing
	#undef loop_condition_out_as_closed_trinary_in_as_open
	#undef loop_condition_out_as_closed_trinary_in_as_opening

	#undef loop_condition_out_as_closing_trinary_in_as_closed
	#undef loop_condition_out_as_closing_trinary_in_as_closing
	#undef loop_condition_out_as_closing_trinary_in_as_open
	#undef loop_condition_out_as_closing_trinary_in_as_opening

	#undef loop_condition_out_as_open_trinary_in_as_closed
	#undef loop_condition_out_as_open_trinary_in_as_closing
	#undef loop_condition_out_as_open_trinary_in_as_open
	#undef loop_condition_out_as_open_trinary_in_as_opening

	#undef loop_condition_out_as_opening_trinary_in_as_closed
	#undef loop_condition_out_as_opening_trinary_in_as_closing
	#undef loop_condition_out_as_opening_trinary_in_as_open
	#undef loop_condition_out_as_opening_trinary_in_as_opening

//

	#undef loop_condition_out_as_closed_trinary_brackets_in_as_closed
	#undef loop_condition_out_as_closed_trinary_brackets_in_as_closing
	#undef loop_condition_out_as_closed_trinary_brackets_in_as_open
	#undef loop_condition_out_as_closed_trinary_brackets_in_as_opening

	#undef loop_condition_out_as_closing_trinary_brackets_in_as_closed
	#undef loop_condition_out_as_closing_trinary_brackets_in_as_closing
	#undef loop_condition_out_as_closing_trinary_brackets_in_as_open
	#undef loop_condition_out_as_closing_trinary_brackets_in_as_opening

	#undef loop_condition_out_as_open_trinary_brackets_in_as_closed
	#undef loop_condition_out_as_open_trinary_brackets_in_as_closing
	#undef loop_condition_out_as_open_trinary_brackets_in_as_open
	#undef loop_condition_out_as_open_trinary_brackets_in_as_opening

	#undef loop_condition_out_as_opening_trinary_brackets_in_as_closed
	#undef loop_condition_out_as_opening_trinary_brackets_in_as_closing
	#undef loop_condition_out_as_opening_trinary_brackets_in_as_open
	#undef loop_condition_out_as_opening_trinary_brackets_in_as_opening

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/////// out_as_closed, in_as_closed


#define during_loop_out_as_closed_in_as_closed(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


/////// out_as_closed, in_as_closing


#define during_loop_out_as_closed_in_as_closing(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


/////// out_as_closed, in_as_open


#define during_loop_out_as_closed_in_as_open(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


/////// out_as_closed, in_as_opening


#define during_loop_out_as_closed_in_as_opening(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


//


/////// out_as_closing, in_as_closed


#define during_loop_out_as_closing_in_as_closed(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


/////// out_as_closing, in_as_closing


#define during_loop_out_as_closing_in_as_closing(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


/////// out_as_closing, in_as_open


#define during_loop_out_as_closing_in_as_open(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


/////// out_as_closing, in_as_opening


#define during_loop_out_as_closing_in_as_opening(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	direct_in(operator_type, in_direction) \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \


//


/////// out_as_open, in_as_closed


#define during_loop_out_as_open_in_as_closed(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	direct_out(out_direction) \
	operate_on_out(operator_type, op, lp, rp) \
	direct_in(operator_type, in_direction) \


/////// out_as_open, in_as_closing


#define during_loop_out_as_open_in_as_closing(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


/////// out_as_open, in_as_open


#define during_loop_out_as_open_in_as_open(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	direct_in(operator_type, in_direction) \


/////// out_as_open, in_as_opening


#define during_loop_out_as_open_in_as_opening(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	direct_in(operator_type, in_direction) \
	direct_out(out_direction) \
	operate_on_out(operator_type, op, lp, rp) \


//


/////// out_as_opening, in_as_closed


#define during_loop_out_as_opening_in_as_closed(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	direct_out(out_direction) \
	operate_on_out(operator_type, op, lp, rp) \
	direct_in(operator_type, in_direction) \


/////// out_as_opening, in_as_closing


#define during_loop_out_as_opening_in_as_closing(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	direct_out(out_direction) \
	operate_on_out(operator_type, op, lp, rp) \
	direct_in(operator_type, in_direction) \


/////// out_as_opening, in_as_open


#define during_loop_out_as_opening_in_as_open(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	direct_in(operator_type, in_direction) \
	direct_out(out_direction) \
	operate_on_out(operator_type, op, lp, rp) \


/////// out_as_opening, in_as_opening


#define during_loop_out_as_opening_in_as_opening(out_direction, operator_type, op, lp, rp, in_type, in_direction) \
 \
	direct_in(operator_type, in_direction) \
	direct_out(out_direction) \
	operate_on_out(operator_type, op, lp, rp) \

/************************************************************************************************************************/
/************************************************************************************************************************/

/////// no_count

#define during_loop_no_count() \

/////// with_count

#define during_loop_with_count()							++count; \

/************************************************************************************************************************/

/*
	in_type:

		in_as_closed
		in_as_closing
		in_as_open
		in_as_opening
*/

#define during_loop(count_type, out_type, out_direction, operator_type, op, lp, rp, in_direction) \
	during_loop_##out_type##_##in_type(out_direction, operator_type, op, lp, rp, in_direction) \
	during_loop_##count_type() \

/************************************************************************************************************************/

#undef during_loop_out_as_closed_in_as_closed
#undef during_loop_out_as_closed_in_as_closing
#undef during_loop_out_as_closed_in_as_open
#undef during_loop_out_as_closed_in_as_opening

#undef during_loop_out_as_closing_in_as_closed
#undef during_loop_out_as_closing_in_as_closing
#undef during_loop_out_as_closing_in_as_open
#undef during_loop_out_as_closing_in_as_opening

#undef during_loop_out_as_open_in_as_closed
#undef during_loop_out_as_open_in_as_closing
#undef during_loop_out_as_open_in_as_open
#undef during_loop_out_as_open_in_as_opening

#undef during_loop_out_as_opening_in_as_closed
#undef during_loop_out_as_opening_in_as_closing
#undef during_loop_out_as_opening_in_as_open
#undef during_loop_out_as_opening_in_as_opening

/************************************************************************************************************************/
/************************************************************************************************************************/

#undef during_loop_no_count
#undef during_loop_with_count

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/////// no_count

#define after_loop_no_count() \

/////// with_count

#define after_loop_with_count()								++count; \

/************************************************************************************************************************/
/************************************************************************************************************************/

#define after_loop_out_as_closed_in_as_closed(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	after_loop_##count_type() \

#define after_loop_out_as_closed_in_as_closing(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	after_loop_##count_type() \

#define after_loop_out_as_closed_in_as_open(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	after_loop_##count_type() \

#define after_loop_out_as_closed_in_as_opening(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	after_loop_##count_type() \

//

#define after_loop_out_as_closing_in_as_closed(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
 \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	after_loop_##count_type() \

#define after_loop_out_as_closing_in_as_closing(count_type, out_direction, operator_type, op, lp, rp, in_direction) \

#define after_loop_out_as_closing_in_as_open(count_type, out_direction, operator_type, op, lp, rp, in_direction) \

#define after_loop_out_as_closing_in_as_opening(count_type, out_direction, operator_type, op, lp, rp, in_direction) \

//

#define after_loop_out_as_open_in_as_closed(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
 \
	direct_out(out_direction) \
	operate_on_out(operator_type, op, lp, rp) \
	direct_out(out_direction) \
	after_loop_##count_type() \

#define after_loop_out_as_open_in_as_closing(count_type, out_direction, operator_type, op, lp, rp, in_direction) \

#define after_loop_out_as_open_in_as_open(count_type, out_direction, operator_type, op, lp, rp, in_direction) \

#define after_loop_out_as_open_in_as_opening(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
	direct_out(out_direction) \

//

#define after_loop_out_as_opening_in_as_closed(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
 \
	direct_out(out_direction) \
	operate_on_out(operator_type, op, lp, rp) \
	after_loop_##count_type() \

#define after_loop_out_as_opening_in_as_closing(count_type, out_direction, operator_type, op, lp, rp, in_direction) \

#define after_loop_out_as_opening_in_as_open(count_type, out_direction, operator_type, op, lp, rp, in_direction) \

#define after_loop_out_as_opening_in_as_opening(count_type, out_direction, operator_type, op, lp, rp, in_direction) \

/************************************************************************************************************************/
/************************************************************************************************************************/

/////// no_return

#define after_loop_no_return() \

/////// with_return

#define after_loop_with_return()							return out; \

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

#define after_loop(return_type, count_type, out_type, out_direction, operator_type, op, lp, rp, in_type, in_direction) \
	after_loop##out_type##_##in_type(count_type, out_direction, operator_type, op, lp, rp, in_direction) \
	after_loop_##return_type() \

/************************************************************************************************************************/

#undef after_loop_no_count
#undef after_loop_with_count

/************************************************************************************************************************/
/************************************************************************************************************************/

#undef after_loop_out_as_closed_in_as_closed
#undef after_loop_out_as_closed_in_as_closing
#undef after_loop_out_as_closed_in_as_open
#undef after_loop_out_as_closed_in_as_opening

#undef after_loop_out_as_closing_in_as_closed
#undef after_loop_out_as_closing_in_as_closing
#undef after_loop_out_as_closing_in_as_open
#undef after_loop_out_as_closing_in_as_opening

#undef after_loop_out_as_open_in_as_closed
#undef after_loop_out_as_open_in_as_closing
#undef after_loop_out_as_open_in_as_open
#undef after_loop_out_as_open_in_as_opening

#undef after_loop_out_as_opening_in_as_closed
#undef after_loop_out_as_opening_in_as_closing
#undef after_loop_out_as_opening_in_as_open
#undef after_loop_out_as_opening_in_as_opening

/************************************************************************************************************************/
/************************************************************************************************************************/

#undef after_loop_no_return
#undef after_loop_with_return

/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/

/*
	return_type:

		no_return
		with_return

	count_type:

		no_count
		with_count

	out_type:

		out_as_closed
		out_as_closing
		out_as_open
		out_as_opening

	out_direction:

		out_as_forward
		out_as_backward

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

	in_type:

		in_as_closed
		in_as_closing
		in_as_open
		in_as_opening

	in_direction:

		in_as_forward
		in_as_backward
*/

#define map(return_type, count_type, out_type, out_direction, operator_type, op, lp, rp, in_type, in_direction) \
	function_identifier(return_type, count_type, operator_type) \
	{ \
		before_loop(out_type, out_direction, operator_type, in_type, in_direction) \
	 \
		while (loop_condition(out_type, operator_type, in_type, in_direction)) \
		{ \
			during_loop(count_type, out_type, out_direction, operator_type, op, lp, rp, in_type, in_direction) \
		} \
	 \
		after_loop(return_type, count_type, out_type, out_direction, operator_type, op, lp, rp, in_type, in_direction) \
	} \

/************************************************************************************************************************/

#undef function_identifier
#undef before_loop
#undef loop_condition
#undef during_loop
#undef after_loop

/************************************************************************************************************************/

/*

// closed

#define _closed_loop_lr_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	lp(*out)op(*in)rp; \
 \
	stmt \
}


#define _closing_loop_lr_as_closed_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (dir(in) != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	lp(*out)op(*in)rp; \
 \
	stmt \
}


#define _open_loop_lr_as_closed_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	dir##dir(in); \
 \
	while (dir(in) != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	lp(*out)op(*in)rp; \
 \
	stmt \
}


#define _opening_loop_lr_as_closed_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	dir##dir(in); \
 \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	lp(*out)op(*in)rp; \
 \
	stmt \
}

// closing


#define _closed_loop_lr_as_closing_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	lp(*out)op(*in)rp; \
	out=dir(out)=new WNode; \
 \
	stmt \
}


#define _closing_loop_lr_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	stmt \
}


#define _open_loop_lr_as_closing_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	dir##dir(in); \
 \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	stmt \
}


#define _opening_loop_lr_as_closing_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		dir##dir(in); \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
	} \
 \
	stmt \
}

// open


#define _closed_loop_lr_as_open_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		lp(*out)op(*in)rp; \
		dir##dir(in); \
	} \
 \
	out=dir(out)=new WNode; \
	lp(*out)op(*in)rp; \
	out=dir(out)=new WNode; \
 \
	stmt \
}


#define _closing_loop_lr_as_open_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	out=dir(out)=new WNode; \
 \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	stmt \
}


#define _open_loop_lr_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	dir##dir(in); \
	out=dir(out)=new WNode; \
 \
	while (in != end) \
	{ \
		lp(*out)op(*in)rp; \
		out=dir(out)=new WNode; \
		dir##dir(in); \
	} \
 \
	stmt \
}


#define _opening_loop_lr_as_open_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		dir##dir(in); \
		out=dir(out)=new WNode; \
		lp(*out)op(*in)rp; \
	} \
 \
	out=dir(out)=new WNode; \
 \
	stmt \
}

// opening


#define _closed_loop_lr_as_opening_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		lp(*out)op(*in)rp; \
		dir##dir(in); \
	} \
 \
	out=dir(out)=new WNode; \
	lp(*out)op(*in)rp; \
 \
	stmt \
}


#define _closing_loop_lr_as_opening_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		out=dir(out)=new WNode; \
		lp(*out)op(*in)rp; \
		dir##dir(in); \
	} \
 \
	stmt \
}


#define _open_loop_lr_as_opening_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (dir(in) != end) \
	{ \
		dir##dir(in); \
		out=dir(out)=new WNode; \
		lp(*out)op(*in)rp; \
	} \
 \
	stmt \
}


#define _opening_loop_lr_1(dir, inv, op, label, rtn, stmt, lp, rp) \
template<typename WNode, typename WPointer, typename RIterator, typename ERIterator> \
static rtn label##_return(WPointer out, RIterator in, ERIterator end) \
{ \
	while (in != end) \
	{ \
		dir##dir(in); \
		out=dir(out)=new WNode; \
		lp(*out)op(*in)rp; \
	} \
 \
	stmt \
}
*/

