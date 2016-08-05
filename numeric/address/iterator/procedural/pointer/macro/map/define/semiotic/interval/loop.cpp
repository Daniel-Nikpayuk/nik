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


// interval


#define function_type_interval_omit_count_unary(rtn, label)								\
															\
															\
	template<typename WPointer>											\
	static rtn label(WPointer out, size_type m, size_type n)


		#define function_type_interval_omit_count_omit_return_unary(label)					\
			function_type_interval_omit_count_unary(void, label)
                                                          
		#define function_type_interval_omit_count_apply_return_unary(label)					\
			function_type_interval_omit_count_unary(WPointer, label)


#define function_type_interval_apply_count_unary(rtn, label)								\
															\
															\
	template<typename WPointer>											\
	static rtn label(size_type & count, WPointer out, size_type m, size_type n)


		#define function_type_interval_apply_count_omit_return_unary(label)					\
			function_type_interval_apply_count_unary(void, label)
                                                           
		#define function_type_interval_apply_count_apply_return_unary(label)					\
			function_type_interval_apply_count_unary(WPointer, label)


// functor_interval


#define function_type_functor_interval_omit_count_unary(rtn, label)							\
															\
															\
	template<typename WPointer, typename Functor>									\
	static rtn label(WPointer out, Functor functor, size_type m, size_type n)


		#define function_type_functor_interval_omit_count_omit_return_unary(label)				\
			function_type_functor_interval_omit_count_unary(void, label)
                                                           
		#define function_type_functor_interval_omit_count_apply_return_unary(label)				\
			function_type_functor_interval_omit_count_unary(WPointer, label)


#define function_type_functor_interval_apply_count_unary(rtn, label)							\
															\
															\
	template<typename WPointer, typename Functor>									\
	static rtn label(size_type & count, WPointer out, Functor functor, size_type m, size_type n)


		#define function_type_functor_interval_apply_count_omit_return_unary(label)				\
			function_type_functor_interval_apply_count_unary(void, label)
                                                            
		#define function_type_functor_interval_apply_count_apply_return_unary(label)				\
			function_type_functor_interval_apply_count_unary(WPointer, label)


/************************************************************************************************************************/


/*
	function_type:

*/


//#define function_type(label, operator_policy, out_memory, count_policy, return_policy, in_memory, in_arity)		\

#define function_type(label, operator_policy, count_policy, return_policy, in_arity)					\
	function_type_##operator_policy##_##count_policy##_##return_policy##_##in_arity(label)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


	#define declare_variables_out_as_forward_hook_allocate()


	#define declare_variables_out_as_backward_hook_allocate()			WPointer current;


#define declare_variables_hook_allocate(out_direction)									\
	declare_variables_##out_direction##_hook_allocate()


/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_variables_link_allocate(out_direction)


/************************************************************************************************************************/
/************************************************************************************************************************/


// policy hasn't stabilized, so this code is currently filler!


	#define declare_variables_out_as_forward_segment_allocate()			out = new segment;


	#define declare_variables_out_as_backward_segment_allocate()			out = new segment;


#define declare_variables_segment_allocate(out_direction)								\
	declare_variables_##out_direction##_segment_allocate()


/************************************************************************************************************************/


#define declare_variables_mutate(out_direction, out_pointer)


#define declare_variables_allocate(out_direction, out_pointer)								\
	declare_variables_##out_pointer##_##allocate(out_direction)


/************************************************************************************************************************/


#define declare_variables(out_direction, out_pointer, out_memory)							\
	declare_variables_##out_memory(out_direction, out_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define omit_peek_unary()							m != n


/************************************************************************************************************************/


#define omit_peek(in_arity)												\
	omit_peek_##in_arity()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define apply_peek_unary(dir)							(m)dir != n


	#define apply_peek_in_as_forward_unary()					apply_peek_unary(+1)
	#define apply_peek_in_as_backward_unary()					apply_peek_unary(-1)


/************************************************************************************************************************/


#define apply_peek(in_direction, in_arity)										\
	apply_peek_##in_arity()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define interval_unary(op_a)								(*out) op_a (m);


/************************************************************************************************************************/


#define interval(op_a, in_arity)											\
	interval_##in_arity(op_a)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define functor_interval_unary(op_a)							functor(out, m);


/************************************************************************************************************************/


#define functor_interval(op_a, in_arity)										\
	functor_interval_##in_arity(op_a)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define omit_count()


#define apply_count()									++count;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define out_mutate(dir)									dir##dir(out);


	#define iterate_out_as_forward_mutate(out_pointer)					out_mutate(+)
	#define iterate_out_as_backward_mutate(out_pointer)					out_mutate(-)


#define iterate_out_mutate(out_direction, out_pointer)									\
	iterate_##out_direction##_mutate(out_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define iterate_out_as_forward_hook_allocate()						out = +(out) = new hook;


#define iterate_out_as_backward_hook_allocate()						current = out;			\
											out = new hook;			\
											+(out) = current;


/************************************************************************************************************************/


#define iterate_out_link_allocate(dir, inv)						dir(out) = new link;		\
											inv(dir(out)) = out;		\
											dir##dir(out);


	#define iterate_out_as_forward_link_allocate()						iterate_out_link_allocate(+, -)
	#define iterate_out_as_backward_link_allocate()						iterate_out_link_allocate(-, +)


/************************************************************************************************************************/


#define iterate_out_as_forward_segment_allocate()


#define iterate_out_as_backward_segment_allocate()


/************************************************************************************************************************/


#define iterate_out_allocate(out_direction, out_pointer)								\
	iterate_##out_direction##_##out_pointer##_allocate()


/************************************************************************************************************************/


#define iterate_out(out_direction, out_pointer, out_memory)								\
	iterate_out_##out_memory(out_direction, out_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define in_mutate_unary(dir)								dir##dir(m);


	#define in_as_forward_mutate_unary(in_pointer)						in_mutate_unary(+)
	#define in_as_backward_mutate_unary(in_pointer)						in_mutate_unary(-)


/************************************************************************************************************************/


#define in_as_mutate(in_direction, in_pointer, in_arity)								\
	in_as_##in_direction##_mutate_##in_arity(in_pointer)


#define in_as_forward(in_pointer, in_memory, in_arity)									\
	in_as_##in_memory(forward, in_pointer, in_arity)


#define in_as_backward(in_pointer, in_memory, in_arity)									\
	in_as_##in_memory(backward, in_pointer, in_arity)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define mutate(in_pointer, in_arity)


#define deallocate(in_pointer, in_arity)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define undeclare_variables(in_direction, in_pointer, in_memory)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	return_policy:

		apply_return
		omit_return
*/


#define apply_return()									return out;


#define omit_return()


