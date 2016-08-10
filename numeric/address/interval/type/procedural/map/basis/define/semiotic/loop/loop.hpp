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


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define template_type_omit_functor()

#define template_type_apply_functor()							template<typename Functor>


/***********************************************************************************************************************/


#define template_type(operator_policy)											\
	template_type_##operator_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define return_type_omit_return()							void

#define return_type_apply_return()							typename out_type::pointer


/***********************************************************************************************************************/


#define return_type(return_policy)											\
	return_type_##return_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define adverb_arguments_omit_count()

#define adverb_arguments_apply_count()							size_type & count,


/***********************************************************************************************************************/


#define adverb_arguments(count_policy)											\
	adverb_arguments_##count_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define subject_arguments_segment_mutate()					typename out_type::pointer out,	\
											


#define subject_arguments_segment(out_memory)										\
	subject_arguments_segment_##out_memory()


/***********************************************************************************************************************/


#define subject_arguments(out_memory, out_pointer)									\
	subject_arguments_##out_pointer(out_memory)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	function_type:

*/


#define function_type(operator_policy, out_memory, out_pointer, in_memory, in_pointer, in_arity, return_policy, count_policy)		\
	template_type(operator_policy)													\
	static return_type(return_policy) map												\
	(																\
		adverb_arguments(count_policy)												\
		subject_arguments(out_memory, out_pointer)										\
		object_arguments(in_memory, in_pointer, in_arity)									\
	)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define declare_variables_allocate_segment_out_as_forward()				out = new value_type[l];


	#define declare_variables_allocate_segment_out_as_backward()				out = (new value_type[l]) + (l-1);


#define declare_variables_allocate_segment(out_direction)								\
	declare_variables_allocate_segment_##out_direction()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define declare_variables_allocate_hook_out_as_forward()


	#define declare_variables_allocate_hook_out_as_backward()				hook current;


#define declare_variables_allocate_hook(out_direction)									\
	declare_variables_allocate_hook_##out_direction()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_variables_allocate_link(out_direction)


/***********************************************************************************************************************/


	#define declare_variables_mutate(out_direction, out_pointer)

	#define declare_variables_allocate(out_direction, out_pointer)							\
		declare_variables_allocate_##out_pointer(out_direction)


#define declare_variables(out_direction, out_memory, out_pointer)							\
	declare_variables_##out_memory(out_direction, out_pointer)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define omit_peek_unary()								m != n


/***********************************************************************************************************************/


#define omit_peek(in_arity)												\
	omit_peek_##in_arity()


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define apply_peek_unary(dir)								(m)dir != n


	#define apply_peek_unary_in_as_forward()						apply_peek_unary(+1)
	#define apply_peek_unary_in_as_backward()						apply_peek_unary(-1)


/***********************************************************************************************************************/


#define apply_peek(in_direction, in_arity)										\
	apply_peek_##in_arity##_##in_direction()


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define interval_unary(op_a)								(*out) op_a (m);


/***********************************************************************************************************************/


#define interval(op_a, in_arity)											\
	interval_##in_arity(op_a)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define functor_interval_unary(op_a)							functor(out, m);


/***********************************************************************************************************************/


#define functor_interval(op_a, in_arity)										\
	functor_interval_##in_arity(op_a)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define omit_count()


#define apply_count()									++count;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define out_mutate(dir)									dir##dir(out);


	#define iterate_out_mutate_out_as_forward(out_pointer)					out_mutate(+)
	#define iterate_out_mutate_out_as_backward(out_pointer)					out_mutate(-)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_out_allocate_hook_out_as_forward()					out = +(out) = new hook;


#define iterate_out_allocate_hook_out_as_backward()					current = out;			\
											out = new hook;			\
											+(out) = current;


/***********************************************************************************************************************/


#define iterate_out_allocate_link(dir, inv)						dir(out) = new link;		\
											inv(dir(out)) = out;		\
											dir##dir(out);


	#define iterate_out_allocate_link_out_as_forward()					iterate_out_allocate_link(+, -)
	#define iterate_out_allocate_link_out_as_backward()					iterate_out_allocate_link(-, +)


/***********************************************************************************************************************/


#define iterate_out_allocate_segment_out_as_forward()


#define iterate_out_allocate_segment_out_as_backward()


/***********************************************************************************************************************/


	#define iterate_out_mutate(out_direction, out_pointer)								\
		iterate_out_mutate_##out_direction(out_pointer)

	#define iterate_out_allocate(out_direction, out_pointer)							\
		iterate_out_allocate_##out_pointer##_##out_direction()


#define iterate_out(out_direction, out_memory, out_pointer)								\
	iterate_out_##out_memory(out_direction, out_pointer)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define in_unary_mutate_interval(dir)							dir##dir(m);


	#define iterate_in_unary_mutate_interval_in_as_forward(in_pointer)			in_unary_mutate_interval(+)
	#define iterate_in_unary_mutate_interval_in_as_backward(in_pointer)			in_unary_mutate_interval(-)


	#define iterate_in_unary_mutate_functor_interval_in_as_forward(in_pointer)		in_unary_mutate_interval(+)
	#define iterate_in_unary_mutate_functor_interval_in_as_backward(in_pointer)		in_unary_mutate_interval(-)


/***********************************************************************************************************************/


	#define iterate_in_unary_mutate_interval(in_direction, in_pointer)						\
		iterate_in_unary_mutate_interval_##in_direction(in_pointer)

	#define iterate_in_unary_mutate_functor_interval(in_direction, in_pointer)					\
		iterate_in_unary_mutate_interval_##in_direction(in_pointer)

#define iterate_in_unary_mutate(operator_policy, in_direction, in_pointer)						\
	iterate_in_unary_mutate_##operator_policy(in_direction, in_pointer)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/***********************************************************************************************************************/


	#define iterate_in_unary(operator_policy, in_direction, in_memory, in_pointer)					\
		iterate_in_unary_##in_memory(operator_policy, in_direction, in_pointer)

	#define iterate_in_binary(operator_policy, in_direction, in_memory, in_pointer)					\
		iterate_in_binary_##in_memory(operator_policy, in_direction, in_pointer)


#define iterate_in(operator_policy, in_direction, in_memory, in_pointer, in_arity)					\
	iterate_in_##in_arity(operator_policy, in_direction, in_memory, in_pointer)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define deallocate(operator_policy, in_pointer, in_arity)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define undeclare_variables(in_direction, in_pointer, in_memory)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	return_policy:

		apply_return
		omit_return
*/


#define apply_return()									return out;


#define omit_return()


