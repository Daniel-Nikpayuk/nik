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


/************************************************************************************************************************/
/************************************************************************************************************************/


#define interval_unary_mutate_omit_count_return_policy(label, out_pointer, in_pointer, rtn)						\
																	\
																	\
	static rtn label(out_pointer::pointer out, size_type m, size_type n)


	#define interval_unary_mutate_omit_count_apply_return(label, out_pointer, in_pointer)						\
		interval_unary_mutate_omit_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define interval_unary_mutate_omit_count_omit_return(label, out_pointer, in_pointer)						\
		interval_unary_mutate_omit_count_return_policy(label, out_pointer, in_pointer, void)


#define interval_unary_mutate_omit_count(label, out_pointer, in_pointer, return_policy)							\
	interval_unary_mutate_omit_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define interval_unary_mutate_apply_count_return_policy(label, out_pointer, in_pointer, rtn)						\
																	\
																	\
	static rtn label(size_type & count, out_pointer::pointer out, size_type m, size_type n)


	#define interval_unary_mutate_apply_count_apply_return(label, out_pointer, in_pointer)						\
		interval_unary_mutate_apply_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define interval_unary_mutate_apply_count_omit_return(label, out_pointer, in_pointer)						\
		interval_unary_mutate_apply_count_return_policy(label, out_pointer, in_pointer, void)


#define interval_unary_mutate_apply_count(label, out_pointer, in_pointer, return_policy)						\
	interval_unary_mutate_apply_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define interval_unary_allocate_omit_count_segment_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	static rtn label(out_pointer::pointer out, size_type l, size_type m, size_type n)


	#define interval_unary_allocate_omit_count_segment_apply_return(label, in_pointer)						\
		interval_unary_allocate_omit_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define interval_unary_allocate_omit_count_segment_omit_return(label, in_pointer)						\
		interval_unary_allocate_omit_count_segment_return_policy(label, segment, in_pointer, void)


	#define interval_unary_allocate_omit_count_hook_apply_return(label, in_pointer)							\
		interval_unary_mutate_omit_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define interval_unary_allocate_omit_count_hook_omit_return(label, in_pointer)							\
		interval_unary_mutate_omit_count_return_policy(label, hook, in_pointer, void)


	#define interval_unary_allocate_omit_count_link_apply_return(label, in_pointer)							\
		interval_unary_mutate_omit_count_return_policy(label, link, in_pointer, link::pointer)

	#define interval_unary_allocate_omit_count_link_omit_return(label, in_pointer)							\
		interval_unary_mutate_omit_count_return_policy(label, link, in_pointer, void)


#define interval_unary_allocate_omit_count(label, out_pointer, in_pointer, return_policy)						\
	interval_unary_allocate_omit_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/


#define interval_unary_allocate_apply_count_segment_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	static rtn label(size_type & count, out_pointer::pointer out, size_type l, size_type m, size_type n)


	#define interval_unary_allocate_apply_count_segment_apply_return(label, in_pointer)						\
		interval_unary_allocate_apply_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define interval_unary_allocate_apply_count_segment_omit_return(label, in_pointer)						\
		interval_unary_allocate_apply_count_segment_return_policy(label, segment, in_pointer, void)


	#define interval_unary_allocate_apply_count_hook_apply_return(label, in_pointer)						\
		interval_unary_mutate_apply_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define interval_unary_allocate_apply_count_hook_omit_return(label, in_pointer)							\
		interval_unary_mutate_apply_count_return_policy(label, hook, in_pointer, void)


	#define interval_unary_allocate_apply_count_link_apply_return(label, in_pointer)						\
		interval_unary_mutate_apply_count_return_policy(label, link, in_pointer, link::pointer)

	#define interval_unary_allocate_apply_count_link_omit_return(label, in_pointer)							\
		interval_unary_mutate_apply_count_return_policy(label, link, in_pointer, void)


#define interval_unary_allocate_apply_count(label, out_pointer, in_pointer, return_policy)						\
	interval_unary_allocate_apply_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


	#define interval_unary_mutate(label, out_pointer, in_pointer, return_policy, count_policy)					\
		interval_unary_mutate_##count_policy(label, out_pointer, in_pointer, return_policy)

	#define interval_unary_allocate(label, out_pointer, in_pointer, return_policy, count_policy)					\
		interval_unary_allocate_##count_policy(label, out_pointer, in_pointer, return_policy)

	#define interval_unary(label, out_memory, out_pointer, in_pointer, return_policy, count_policy)					\
		interval_unary_##out_memory(label, out_pointer, in_pointer, return_policy, count_policy)


#define function_type_interval(label, out_memory, out_pointer, in_pointer, arity_policy, return_policy, count_policy)			\
	interval_##arity_policy(label, out_memory, out_pointer, in_pointer, return_policy, count_policy)


/************************************************************************************************************************/
/************************************************************************************************************************/


// functor interval


/************************************************************************************************************************/
/************************************************************************************************************************/


#define functor_interval_unary_mutate_omit_count_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	template<typename Functor>													\
	static rtn label(out_pointer::pointer out, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_mutate_omit_count_apply_return(label, out_pointer, in_pointer)					\
		functor_interval_unary_mutate_omit_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define functor_interval_unary_mutate_omit_count_omit_return(label, out_pointer, in_pointer)					\
		functor_interval_unary_mutate_omit_count_return_policy(label, out_pointer, in_pointer, void)


#define functor_interval_unary_mutate_omit_count(label, out_pointer, in_pointer, return_policy)						\
	functor_interval_unary_mutate_omit_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define functor_interval_unary_mutate_apply_count_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	template<typename Functor>													\
	static rtn label(size_type & count, out_pointer::pointer out, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_mutate_apply_count_apply_return(label, out_pointer, in_pointer)					\
		functor_interval_unary_mutate_apply_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define functor_interval_unary_mutate_apply_count_omit_return(label, out_pointer, in_pointer)					\
		functor_interval_unary_mutate_apply_count_return_policy(label, out_pointer, in_pointer, void)


#define functor_interval_unary_mutate_apply_count(label, out_pointer, in_pointer, return_policy)					\
	functor_interval_unary_mutate_apply_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define functor_interval_unary_allocate_omit_count_segment_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	template<typename Functor>													\
	static rtn label(out_pointer::pointer out, size_type l, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_allocate_omit_count_segment_apply_return(label, in_pointer)					\
		functor_interval_unary_allocate_omit_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define functor_interval_unary_allocate_omit_count_segment_omit_return(label, in_pointer)					\
		functor_interval_unary_allocate_omit_count_segment_return_policy(label, segment, in_pointer, void)


	#define functor_interval_unary_allocate_omit_count_hook_apply_return(label, in_pointer)						\
		functor_interval_unary_mutate_omit_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define functor_interval_unary_allocate_omit_count_hook_omit_return(label, in_pointer)						\
		functor_interval_unary_mutate_omit_count_return_policy(label, hook, in_pointer, void)


	#define functor_interval_unary_allocate_omit_count_link_apply_return(label, in_pointer)						\
		functor_interval_unary_mutate_omit_count_return_policy(label, link, in_pointer, link::pointer)

	#define functor_interval_unary_allocate_omit_count_link_omit_return(label, in_pointer)						\
		functor_interval_unary_mutate_omit_count_return_policy(label, link, in_pointer, void)


#define functor_interval_unary_allocate_omit_count(label, out_pointer, in_pointer, return_policy)					\
	functor_interval_unary_allocate_omit_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/


#define functor_interval_unary_allocate_apply_count_segment_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	template<typename Functor>													\
	static rtn label(size_type & count, out_pointer::pointer out, size_type l, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_allocate_apply_count_segment_apply_return(label, in_pointer)					\
		functor_interval_unary_allocate_apply_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define functor_interval_unary_allocate_apply_count_segment_omit_return(label, in_pointer)					\
		functor_interval_unary_allocate_apply_count_segment_return_policy(label, segment, in_pointer, void)


	#define functor_interval_unary_allocate_apply_count_hook_apply_return(label, in_pointer)					\
		functor_interval_unary_mutate_apply_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define functor_interval_unary_allocate_apply_count_hook_omit_return(label, in_pointer)						\
		functor_interval_unary_mutate_apply_count_return_policy(label, hook, in_pointer, void)


	#define functor_interval_unary_allocate_apply_count_link_apply_return(label, in_pointer)					\
		functor_interval_unary_mutate_apply_count_return_policy(label, link, in_pointer, link::pointer)

	#define functor_interval_unary_allocate_apply_count_link_omit_return(label, in_pointer)						\
		functor_interval_unary_mutate_apply_count_return_policy(label, link, in_pointer, void)


#define functor_interval_unary_allocate_apply_count(label, out_pointer, in_pointer, return_policy)					\
	functor_interval_unary_allocate_apply_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


	#define functor_interval_unary_mutate(label, out_pointer, in_pointer, return_policy, count_policy)				\
		functor_interval_unary_mutate_##count_policy(label, out_pointer, in_pointer, return_policy)

	#define functor_interval_unary_allocate(label, out_pointer, in_pointer, return_policy, count_policy)				\
		functor_interval_unary_allocate_##count_policy(label, out_pointer, in_pointer, return_policy)

	#define functor_interval_unary(label, out_memory, out_pointer, in_pointer, return_policy, count_policy)				\
		functor_interval_unary_##out_memory(label, out_pointer, in_pointer, return_policy, count_policy)


#define function_type_functor_interval(label, out_memory, out_pointer, in_pointer, arity_policy, return_policy, count_policy)		\
	functor_interval_##arity_policy(label, out_memory, out_pointer, in_pointer, return_policy, count_policy)


/************************************************************************************************************************/


/*
	function_type:

*/


#define function_type(label, operator_policy, out_memory, out_pointer, in_pointer, arity_policy, return_policy, count_policy)	\
	function_type_##operator_policy(label, out_memory, out_pointer, in_pointer, arity_policy, return_policy, count_policy)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


	#define declare_variables_allocate_segment_out_as_forward()				out = new value_type[l];


	#define declare_variables_allocate_segment_out_as_backward()				out = (new value_type[l]) + (l-1);


#define declare_variables_allocate_segment(out_direction)								\
	declare_variables_allocate_segment_##out_direction()


/************************************************************************************************************************/
/************************************************************************************************************************/


	#define declare_variables_allocate_hook_out_as_forward()


	#define declare_variables_allocate_hook_out_as_backward()				hook current;


#define declare_variables_allocate_hook(out_direction)									\
	declare_variables_allocate_hook_##out_direction()


/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_variables_allocate_link(out_direction)


/************************************************************************************************************************/


	#define declare_variables_mutate(out_direction, out_pointer)

	#define declare_variables_allocate(out_direction, out_pointer)							\
		declare_variables_allocate_##out_pointer(out_direction)


#define declare_variables(out_direction, out_memory, out_pointer)							\
	declare_variables_##out_memory(out_direction, out_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define omit_peek_unary()								m != n


/************************************************************************************************************************/


#define omit_peek(arity_policy)												\
	omit_peek_##arity_policy()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define apply_peek_unary(dir)								(m)dir != n


	#define apply_peek_unary_in_as_forward()						apply_peek_unary(+1)
	#define apply_peek_unary_in_as_backward()						apply_peek_unary(-1)


/************************************************************************************************************************/


#define apply_peek(in_direction, arity_policy)										\
	apply_peek_##arity_policy##_##in_direction()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define interval_unary(op_a)								(*out) op_a (m);


/************************************************************************************************************************/


#define interval(op_a, arity_policy)											\
	interval_##arity_policy(op_a)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define functor_interval_unary(op_a)							functor(out, m);


/************************************************************************************************************************/


#define functor_interval(op_a, arity_policy)										\
	functor_interval_##arity_policy(op_a)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define omit_count()


#define apply_count()									++count;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define out_mutate(dir)									dir##dir(out);


	#define iterate_out_mutate_out_as_forward(out_pointer)					out_mutate(+)
	#define iterate_out_mutate_out_as_backward(out_pointer)					out_mutate(-)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define iterate_out_allocate_hook_out_as_forward()					out = +(out) = new hook;


#define iterate_out_allocate_hook_out_as_backward()					current = out;			\
											out = new hook;			\
											+(out) = current;


/************************************************************************************************************************/


#define iterate_out_allocate_link(dir, inv)						dir(out) = new link;		\
											inv(dir(out)) = out;		\
											dir##dir(out);


	#define iterate_out_allocate_link_out_as_forward()					iterate_out_allocate_link(+, -)
	#define iterate_out_allocate_link_out_as_backward()					iterate_out_allocate_link(-, +)


/************************************************************************************************************************/


#define iterate_out_allocate_segment_out_as_forward()


#define iterate_out_allocate_segment_out_as_backward()


/************************************************************************************************************************/


	#define iterate_out_mutate(out_direction, out_pointer)								\
		iterate_out_mutate_##out_direction(out_pointer)

	#define iterate_out_allocate(out_direction, out_pointer)							\
		iterate_out_allocate_##out_pointer##_##out_direction()


#define iterate_out(out_direction, out_memory, out_pointer)								\
	iterate_out_##out_memory(out_direction, out_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define in_unary_mutate_interval(dir)							dir##dir(m);


	#define iterate_in_unary_mutate_interval_in_as_forward(in_pointer)			in_unary_mutate_interval(+)
	#define iterate_in_unary_mutate_interval_in_as_backward(in_pointer)			in_unary_mutate_interval(-)


	#define iterate_in_unary_mutate_functor_interval_in_as_forward(in_pointer)		in_unary_mutate_interval(+)
	#define iterate_in_unary_mutate_functor_interval_in_as_backward(in_pointer)		in_unary_mutate_interval(-)


/************************************************************************************************************************/


	#define iterate_in_unary_mutate_interval(in_direction, in_pointer)						\
		iterate_in_unary_mutate_interval_##in_direction(in_pointer)

	#define iterate_in_unary_mutate_functor_interval(in_direction, in_pointer)					\
		iterate_in_unary_mutate_interval_##in_direction(in_pointer)

#define iterate_in_unary_mutate(operator_policy, in_direction, in_pointer)						\
	iterate_in_unary_mutate_##operator_policy(in_direction, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


/************************************************************************************************************************/


	#define iterate_in_unary(operator_policy, in_direction, in_memory, in_pointer)					\
		iterate_in_unary_##in_memory(operator_policy, in_direction, in_pointer)

	#define iterate_in_binary(operator_policy, in_direction, in_memory, in_pointer)					\
		iterate_in_binary_##in_memory(operator_policy, in_direction, in_pointer)


#define iterate_in(operator_policy, in_direction, in_memory, in_pointer, arity_policy)					\
	iterate_in_##arity_policy(operator_policy, in_direction, in_memory, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define deallocate(operator_policy, in_pointer, arity_policy)


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


