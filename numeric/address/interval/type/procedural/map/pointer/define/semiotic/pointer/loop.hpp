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


#define function_type_interval_omit_count(rtn, label)											\
																	\
																	\
	template<typename WNode, typename WPointer>											\
	static rtn label(WPointer out, size_type m, size_type n)


		#define function_type_interval_omit_count_omit_return(label)								\
			function_type_interval_omit_count(void, label)

		#define function_type_interval_omit_count_apply_return(label)								\
			function_type_interval_omit_count(WPointer, label)


#define function_type_interval_apply_count(rtn, label)											\
																	\
																	\
	template<typename WNode, typename WPointer>											\
	static rtn label(size_type & count, WPointer out, size_type m, size_type n)


		#define function_type_interval_apply_count_omit_return(label)								\
			function_type_interval_apply_count(void, label)

		#define function_type_interval_apply_count_apply_return(label)								\
			function_type_interval_apply_count(WPointer, label)


// generic interval


#define function_type_generic_interval_omit_count(rtn, label)										\
																	\
																	\
	template<typename WNode, typename Functor, typename WPointer>									\
	static rtn label(Functor functor, WPointer out, size_type m, size_type n)


		#define function_type_generic_interval_omit_count_omit_return(label)							\
			function_type_generic_interval_omit_count(void, label)

		#define function_type_generic_interval_omit_count_apply_return(label)							\
			function_type_generic_interval_omit_count(WPointer, label)


#define function_type_generic_interval_apply_count(rtn, label)										\
																	\
																	\
	template<typename WNode, typename Functor, typename WPointer>									\
	static rtn label(size_type & count, Functor functor, WPointer out, size_type m, size_type n)


		#define function_type_generic_interval_apply_count_omit_return(label)							\
			function_type_generic_interval_apply_count(void, label)

		#define function_type_generic_interval_apply_count_apply_return(label)							\
			function_type_generic_interval_apply_count(WPointer, label)


/************************************************************************************************************************/


/*
	function_type:

*/


#define function_type(label, operator_policy, count_policy, return_policy)						\
	function_type_##operator_policy##_##count_policy##_##return_policy(label)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	operator_policy:

		interval
		genericity
*/


#define interval(op_a)									*out op_a m;


#define genericity(op_a)								functor(out, m);


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_variables_as_forward()


#define declare_variables_as_backward()							WPointer current;


/************************************************************************************************************************/


/*
	direction_policy:

		as_forward
		as_backward
*/


#define declare_variables(out_direction)									\
	declare_variables_##out_direction()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	direction_policy:

		as_forward
		as_backward
*/


#define out_direction(dir)								out=dir(out)=new WNode;


	#define as_forward()								out_direction(+)


	#define as_backward()								current=out;			\
											out=new WNode;			\
											+out=current;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	count_policy:

		omit_count
		apply_count
*/


#define omit_count()


#define apply_count()									++count;


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



/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


// interval


#define function_type_interval_omit_count(rtn, label)											\
																	\
																	\
	template<typename T, typename WPointer>												\
	static rtn label(WPointer out, size_type m, size_type n)


		#define function_type_interval_omit_count_omit_return(label)								\
			function_type_interval_omit_count(void, label)
                                                          
		#define function_type_interval_omit_count_apply_return(label)								\
			function_type_interval_omit_count(WPointer, label)


#define function_type_interval_apply_count(rtn, label)											\
																	\
																	\
	template<typename T, typename WPointer>												\
	static rtn label(size_type & count, WPointer out, size_type m, size_type n)


		#define function_type_interval_apply_count_omit_return(label)								\
			function_type_interval_apply_count(void, label)
                                                           
		#define function_type_interval_apply_count_apply_return(label)								\
			function_type_interval_apply_count(WPointer, label)


// genericity


#define function_type_genericity_omit_count(rtn, label)											\
																	\
																	\
	template<typename T, typename WPointer, typename Functor>									\
	static rtn label(WPointer out, Functor functor, size_type m, size_type n)


		#define function_type_genericity_omit_count_omit_return(label)								\
			function_type_genericity_omit_count(void, label)
                                                           
		#define function_type_genericity_omit_count_apply_return(label)								\
			function_type_genericity_omit_count(WPointer, label)


#define function_type_genericity_apply_count(rtn, label)										\
																	\
																	\
	template<typename T, typename WPointer, typename Functor>									\
	static rtn label(size_type & count, WPointer out, Functor functor, size_type m, size_type n)


		#define function_type_genericity_apply_count_omit_return(label)								\
			function_type_genericity_apply_count(void, label)
                                                            
		#define function_type_genericity_apply_count_apply_return(label)							\
			function_type_genericity_apply_count(WPointer, label)


/************************************************************************************************************************/


/*
	function_type:

*/


#define function_type(label, operator_policy, count_policy, return_policy, in_arity)					\
	function_type_##operator_policy##_##count_policy##_##return_policy##_##in_arity(label)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_variables_forward_hook_mutate()
#define declare_variables_backward_hook_mutate()
#define declare_variables_forward_link_mutate()
#define declare_variables_backward_link_mutate()
#define declare_variables_forward_segment_mutate()
#define declare_variables_backward_segment_mutate()


#define declare_variables_hook()						using hook = s_semiotic::hook<T>;


	#define declare_variables_forward_hook_allocate()				declare_variables_hook()


	#define declare_variables_backward_hook_allocate()				declare_variables_hook()	\
											WPointer current;


#define declare_variables_link()						using link = s_semiotic::link<T>;


	#define declare_variables_forward_link_allocate()				declare_variables_link()
	#define declare_variables_backward_link_allocate()				declare_variables_link()


#define declare_variables_forward_segment_allocate()				out = new T[n-m];


#define declare_variables_backward_segment_allocate()				static constexpr size_type l = n-m;	\
										out = (new T[l+1]) + l;


/************************************************************************************************************************/


#define declare_variables(out_direction, out_pointer, out_memory)							\
	declare_variables_##out_direction(out_pointer, out_memory)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/************************************************************************************************************************/


#define omit_peek_nullary()							m != n


#define omit_peek_unary()							in != end


#define omit_peek_binary()							in2 != end2


#define omit_peek(in_arity)												\
	omit_peek_##in_arity()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define with_peek_nullary(dir)							(m)dir != n


	#define with_peek_forward_nullary()						with_peek_nullary(+1)
	#define with_peek_backward_nullary()						with_peek_nullary(-1)


#define with_peek_unary(dir)							dir(in) != end


	#define with_peek_forward_unary()						with_peek_unary(+)
	#define with_peek_backward_unary()						with_peek_unary(-)


#define with_peek_binary(dir)							dir(in2) != end2


	#define with_peek_forward_binary()						with_peek_binary(+)
	#define with_peek_backward_binary()						with_peek_binary(-)


/************************************************************************************************************************/


#define with_peek(in_direction, in_arity)										\
	with_peek_##in_arity()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define interval_nullary(op_a)								(*out) op_a (m);


#define interval_unary(op_a)								(*out) op_a (in);


#define interval_binary(op_a)


/************************************************************************************************************************/


#define interval(op_a, in_arity)											\
	interval_##in_arity(op_a)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define genericity_nullary(op_a)							functor(out, m);


#define genericity_unary(op_a)								functor(out, in);


#define genericity_binary(op_a)								functor(out, in1, in2);


/************************************************************************************************************************/


#define genericity(op_a, in_arity)											\
	genericity_##in_arity(op_a)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	count_policy:

		omit_count
		apply_count
*/


#define omit_count()


#define apply_count()									++count;


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define out_mutate(dir)									dir##dir(out);


	#define out_as_forward_hook_mutate()							out_mutate(+)
	#define out_as_backward_hook_mutate()							out_mutate(-)


	#define out_as_forward_link_mutate()							out_mutate(+)
	#define out_as_backward_link_mutate()							out_mutate(-)


	#define out_as_forward_segment_mutate()							out_mutate(+)
	#define out_as_backward_segment_mutate()						out_mutate(-)


#define out_hook_allocate(dir)								out = dir(out) = new hook;


	#define out_as_forward_hook_allocate()							out_hook_allocate(+)
	#define out_as_backward_hook_allocate()							out_hook_allocate(-)


#define out_link_allocate(dir, inv)							dir(out) = new link;		\
											inv(dir(out)) = out;


	#define out_as_forward_link_allocate()							out_link_allocate(+, -)
	#define out_as_backward_link_allocate()							out_link_allocate(-, +)


#define out_as_forward_segment_allocate()
#define out_as_backward_segment_allocate()


/************************************************************************************************************************/


#define out_as_forward(out_pointer, out_memory)										\
	out_as_forward_##out_pointer##_##out_memory()


#define out_as_backward(out_pointer, out_memory)									\
	out_as_backward_##out_pointer##_##out_memory()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define in_mutate_nullary(dir)								dir##dir(m);


	#define in_as_forward_hook_mutate_nullary()						in_mutate_nullary(+)
	#define in_as_backward_hook_mutate_nullary()						in_mutate_nullary(-)


	#define in_as_forward_link_mutate_nullary()						in_mutate_nullary(+)
	#define in_as_backward_link_mutate_nullary()						in_mutate_nullary(-)


	#define in_as_forward_segment_mutate_nullary()						in_mutate_nullary(+)
	#define in_as_backward_segment_mutate_nullary()						in_mutate_nullary(-)


#define in_mutate_unary(dir)								dir##dir(in);


	#define in_as_forward_hook_mutate_unary()						in_mutate_unary(+)
	#define in_as_backward_hook_mutate_unary()						in_mutate_unary(-)


	#define in_as_forward_link_mutate_unary()						in_mutate_unary(+)
	#define in_as_backward_link_mutate_unary()						in_mutate_unary(-)


	#define in_as_forward_segment_mutate_unary()						in_mutate_unary(+)
	#define in_as_backward_segment_mutate_unary()						in_mutate_unary(-)


#define in_mutate_binary(dir)								dir##dir(in1);			\
											dir##dir(in2);


	#define in_as_forward_hook_mutate_binary()						in_mutate_binary(+)
	#define in_as_backward_hook_mutate_binary()						in_mutate_binary(-)


	#define in_as_forward_link_mutate_binary()						in_mutate_binary(+)
	#define in_as_backward_link_mutate_binary()						in_mutate_binary(-)


	#define in_as_forward_segment_mutate_binary()						in_mutate_binary(+)
	#define in_as_backward_segment_mutate_binary()						in_mutate_binary(-)


// hook


#define in_as_forward_hook_deallocate_nullary()
#define in_as_backward_hook_deallocate_nullary()


#define in_hook_deallocate_unary(dir)							delete (in)dir##dir;


	#define in_as_forward_hook_deallocate_unary()						in_hook_deallocate_unary(+)
	#define in_as_backward_hook_deallocate_unary()						in_hook_deallocate_unary(-)


#define in_hook_deallocate_binary(dir)							delete (in1)dir##dir;		\
											delete (in2)dir##dir;


	#define in_as_forward_hook_deallocate_binary()						in_hook_deallocate_binary(+)
	#define in_as_backward_hook_deallocate_binary()						in_hook_deallocate_binary(-)


// link


#define in_as_forward_link_deallocate_nullary()
#define in_as_backward_link_deallocate_nullary()


#define in_link_deallocate_unary(dir, inv)						dir##dir(in);			\
											delete inv(in);


	#define in_as_forward_link_deallocate_unary()						in_link_deallocate_unary(+, -)
	#define in_as_backward_link_deallocate_unary()						in_link_deallocate_unary(-, +)


#define in_link_deallocate_binary(dir, inv)						dir##dir(in1);			\
											delete inv(in1);		\
											dir##dir(in2);			\
											delete inv(in2);


	#define in_as_forward_link_deallocate_binary()						in_link_deallocate_binary(+, -)
	#define in_as_backward_link_deallocate_binary()						in_link_deallocate_binary(-, +)


// segment


#define in_as_forward_segment_deallocate_nullary()
#define in_as_backward_segment_deallocate_nullary()
#define in_as_forward_segment_deallocate_unary()
#define in_as_backward_segment_deallocate_unary()
#define in_as_forward_segment_deallocate_binary()
#define in_as_backward_segment_deallocate_binary()


/************************************************************************************************************************/


#define in_as_forward(in_pointer, in_memory, in_arity)									\
	in_as_forward_##in_pointer##_##in_memory##_##in_arity()


#define in_as_backward(in_pointer, in_memory, in_arity)									\
	in_as_backward_##in_pointer##_##in_memory##_##in_arity()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define mutate(in_pointer, in_arity)


#define deallocate_hook_nullary()
#define deallocate_link_nullary()


#define deallocate_unary()								delete in;


	#define deallocate_hook_unary()								deallocate_unary()
	#define deallocate_link_unary()								deallocate_unary()


#define deallocate_binary()								delete in1;			\
											delete in2;


	#define deallocate_hook_binary()							deallocate_binary()
	#define deallocate_link_binary()							deallocate_binary()


#define deallocate_segment_unary()
#define deallocate_segment_binary()


/************************************************************************************************************************/


#define deallocate(in_pointer, in_arity)										\
	deallocate_##in_pointer##_##in_arity()



/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define undeclare_forward_variables_hook_mutate()
#define undeclare_backward_variables_hook_mutate()

#define undeclare_forward_variables_link_mutate()
#define undeclare_backward_variables_link_mutate()

#define undeclare_forward_variables_segment_mutate()
#define undeclare_backward_variables_segment_mutate()


#define undeclare_forward_variables_hook_deallocate()
#define undeclare_backward_variables_hook_deallocate()

#define undeclare_forward_variables_link_deallocate()
#define undeclare_backward_variables_link_deallocate()


	// needs fixing! Currently filler code!!!
#define undeclare_forward_variables_segment_deallocate()				delete [] in-(n-m);


#define undeclare_backward_variables_segment_deallocate()				delete [] in;


/************************************************************************************************************************/


#define undeclare_variables(in_direction, in_pointer, in_memory)							\
	undeclare_variables_##in_direction##_##in_pointer##_##in_memory()


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


