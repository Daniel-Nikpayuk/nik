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


#define template_type_apply_functor()						template<typename Functor>


/***********************************************************************************************************************/


#define template_type(template_policy)											\
	template_type_##template_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define return_type_omit_return()						void


#define return_type_apply_return()						typename out_type::pointer


/***********************************************************************************************************************/


#define return_type(return_policy)											\
	return_type_##return_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define verb_args_omit_count()


#define verb_args_apply_count()							size_type & count,


/***********************************************************************************************************************/


#define verb_args(count_policy)												\
	verb_args_##count_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define subject_args_segment_mutate_omit_return()			typename out_type::pointer & out,


	#define subject_args_segment_mutate_apply_return()			typename out_type::pointer out,


#define subject_args_segment_mutate(return_policy)									\
	subject_args_segment_mutate_##return_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define subject_args_segment_allocate_omit_return()			typename out_type::pointer & origin,	\
			   							size_type length,			\
										size_type offset,


	#define subject_args_segment_allocate_apply_return()			typename out_type::pointer & origin,	\
										size_type length,			\
										size_type offset,


#define subject_args_segment_allocate(return_policy)									\
	subject_args_segment_allocate_##return_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define subject_args_segment(out_memory, return_policy)									\
	subject_args_segment_##out_memory(return_policy)


#define subject_args_hook(out_memory, return_policy)									\
	subject_args_segment_mutate_##return_policy()


#define subject_args_link(out_memory, return_policy)									\
	subject_args_segment_mutate_##return_policy()


/***********************************************************************************************************************/


#define subject_args(out_memory, out_pointer, return_policy)								\
	subject_args_##out_pointer(out_memory, return_policy)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define object_args_segment_mutate_omit_functor_unary()			typename in_type::pointer inr,		\
										typename in_type::pointer endr


	#define object_args_segment_mutate_omit_functor_binary()		typename in_type::pointer inl,		\
										typename in_type::pointer inr,		\
										typename in_type::pointer endr


#define object_args_segment_mutate_omit_functor(arity_policy)								\
	object_args_segment_mutate_omit_functor_##arity_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define object_args_segment_mutate_apply_functor_unary()		Functor functor,			\
										typename in_type::pointer inr,		\
										typename in_type::pointer endr


	#define object_args_segment_mutate_apply_functor_binary()		Functor functor,			\
										typename in_type::pointer inl,		\
										typename in_type::pointer inr,		\
										typename in_type::pointer endr


#define object_args_segment_mutate_apply_functor(arity_policy)								\
	object_args_segment_mutate_apply_functor_##arity_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define object_args_segment_deallocate_omit_functor_unary()		typename in_type::pointer originr,	\
										typename in_type::pointer inr,		\
										typename in_type::pointer endr


	#define object_args_segment_deallocate_omit_functor_binary()		typename in_type::pointer originl,	\
										typename in_type::pointer inl,		\
										typename in_type::pointer originr,	\
										typename in_type::pointer inr,		\
										typename in_type::pointer endr


#define object_args_segment_deallocate_omit_functor(arity_policy)							\
	object_args_segment_deallocate_omit_functor_##arity_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define object_args_segment_deallocate_apply_functor_unary()		Functor functor,			\
										typename in_type::pointer originr,	\
										typename in_type::pointer inr,		\
										typename in_type::pointer endr


	#define object_args_segment_deallocate_apply_functor_binary()		Functor functor,			\
										typename in_type::pointer originl,	\
										typename in_type::pointer inl,		\
										typename in_type::pointer originr,	\
										typename in_type::pointer inr,		\
										typename in_type::pointer endr


#define object_args_segment_deallocate_apply_functor(arity_policy)							\
	object_args_segment_deallocate_apply_functor_##arity_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define object_args_segment(in_memory, template_policy, arity_policy)							\
	object_args_segment_##in_memory##_##template_policy(arity_policy)


#define object_args_hook(in_memory, template_policy, arity_policy)							\
	object_args_segment_mutate_##template_policy##_##arity_policy()


#define object_args_link(in_memory, template_policy, arity_policy)							\
	object_args_segment_mutate_##template_policy##_##arity_policy()


/***********************************************************************************************************************/


#define object_args(in_memory, in_pointer, template_policy, arity_policy)						\
	object_args_##in_pointer(in_memory, template_policy, arity_policy)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define declare_variables_allocate_segment_forward()			origin = new value_type[length];	\
										typename out_type::pointer out		\
											= origin + offset;


	#define declare_variables_allocate_segment_backward()			origin = new value_type[length];	\
										typename out_type::pointer out		\
											= origin + (length-1-offset);


#define declare_variables_allocate_segment(out_direction)								\
	declare_variables_allocate_segment_##out_direction()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define declare_variables_allocate_hook_forward()


	#define declare_variables_allocate_hook_backward()			typename out_type::pointer current;


#define declare_variables_allocate_hook(out_direction)									\
	declare_variables_allocate_hook_##out_direction()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_variables_allocate_link(out_direction)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define declare_variables_mutate(out_direction, out_pointer)


#define declare_variables_allocate(out_direction, out_pointer)								\
	declare_variables_allocate_##out_pointer(out_direction)


/***********************************************************************************************************************/


#define declare_variables(out_direction, out_memory, out_pointer)							\
	declare_variables_##out_memory(out_direction, out_pointer)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define omit_peek()								inr != endr


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define apply_peek_segment_in_direction(dir)					(inr) dir 1 != endr


	#define apply_peek_segment_forward()										\
		apply_peek_segment_in_direction(+)


	#define apply_peek_segment_backward()										\
		apply_peek_segment_in_direction(-)


#define apply_peek_segment(in_direction)										\
	apply_peek_segment_##in_direction()


/***********************************************************************************************************************/


#define apply_peek_hook_in_direction(dir)					dir(inr) != endr


	#define apply_peek_hook_forward()										\
		apply_peek_hook_in_direction(+)


	#define apply_peek_hook_backward()										\
		apply_peek_hook_in_direction(-)


#define apply_peek_hook(in_direction)											\
	apply_peek_hook_##in_direction()


/***********************************************************************************************************************/


#define apply_peek_link(in_direction)											\
	apply_peek_hook_##in_direction()


/***********************************************************************************************************************/


#define apply_peek(in_direction, in_pointer)										\
	apply_peek_##in_pointer(in_direction)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define main_action_omit_functor_unary()				*out = *inr;


#define main_action_omit_functor(arity_policy)										\
	main_action_omit_functor_##arity_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define main_action_apply_functor_unary()				functor(out, inr);


	#define main_action_apply_functor_binary()				functor(out, inl, inr);


#define main_action_apply_functor(arity_policy)										\
	main_action_apply_functor_##arity_policy()


/***********************************************************************************************************************/


#define main_action(template_policy, arity_policy)									\
	main_action_##template_policy(arity_policy)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define count_action_omit_count()


#define count_action_apply_count()						++count;


/***********************************************************************************************************************/


#define count_action(count_policy)											\
	count_action_##count_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_out_mutate_out_direction(dir)					dir##dir(out);


	#define iterate_out_mutate_forward(out_pointer)									\
		iterate_out_mutate_out_direction(+)


	#define iterate_out_mutate_backward(out_pointer)								\
		iterate_out_mutate_out_direction(-)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_out_allocate_segment(out_direction)									\
	iterate_out_mutate_##out_direction()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_out_allocate_hook_forward()					out = +(out) = new out_type;


#define iterate_out_allocate_hook_backward()					current = out;				\
										out = new out_type;			\
										+(out) = current;


#define iterate_out_allocate_hook(out_direction)									\
	iterate_out_allocate_hook_##out_direction()


/***********************************************************************************************************************/


#define iterate_out_allocate_link_out_direction(dir, inv)			dir(out) = new out_type;		\
										inv(dir(out)) = out;			\
										dir##dir(out);


	#define iterate_out_allocate_link_forward()									\
		iterate_out_allocate_link_out_direction(+, -)


	#define iterate_out_allocate_link_backward()									\
		iterate_out_allocate_link_out_direction(-, +)


#define iterate_out_allocate_link(out_direction)									\
	iterate_out_allocate_link_##out_direction()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_out_mutate(out_direction, out_pointer)									\
	iterate_out_mutate_##out_direction(out_pointer)


#define iterate_out_allocate(out_direction, out_pointer)								\
	iterate_out_allocate_##out_pointer(out_direction)


/***********************************************************************************************************************/


#define iterate_out(out_direction, out_memory, out_pointer)								\
	iterate_out_##out_memory(out_direction, out_pointer)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_in_mutate_unary_in_direction(dir)				dir##dir(inr);


	#define iterate_in_mutate_unary_forward(in_pointer)								\
		iterate_in_mutate_unary_in_direction(+)


	#define iterate_in_mutate_unary_backward(in_pointer)								\
		iterate_in_mutate_unary_in_direction(-)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_in_mutate_binary_in_direction(dir)				dir##dir(inl);				\
										dir##dir(inr);


	#define iterate_in_mutate_binary_forward(in_pointer)								\
		iterate_in_mutate_binary_in_direction(+)


	#define iterate_in_mutate_binary_backward(in_pointer)								\
		iterate_in_mutate_binary_in_direction(-)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_in_deallocate_hook_unary_in_direction(dir)			delete (inr)dir##dir;


	#define iterate_in_deallocate_hook_unary_forward()								\
		iterate_in_deallocate_hook_unary_in_direction(+)


	#define iterate_in_deallocate_hook_unary_backward()								\
		iterate_in_deallocate_hook_unary_in_direction(-)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_in_deallocate_hook_binary_in_direction(dir)			delete (inl)dir##dir;			\
										delete (inr)dir##dir;


	#define iterate_in_deallocate_hook_binary_forward()								\
		iterate_in_deallocate_hook_binary_in_direction(+)


	#define iterate_in_deallocate_hook_binary_backward()								\
		iterate_in_deallocate_hook_binary_in_direction(-)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_in_deallocate_link_unary_in_direction(dir, inv)			dir##dir(inr);				\
										delete inv(inr);


	#define iterate_in_deallocate_link_unary_forward()								\
		iterate_in_deallocate_link_unary_in_direction(+, -)


	#define iterate_in_deallocate_link_unary_backward()								\
		iterate_in_deallocate_link_unary_in_direction(-, +)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_in_deallocate_link_binary_in_direction(dir, inv)		dir##dir(inl); dir##dir(inr);		\
										delete inv(inl); delete inv(inr);


	#define iterate_in_deallocate_link_binary_forward()								\
		iterate_in_deallocate_link_binary_in_direction(+, -)


	#define iterate_in_deallocate_link_binary_backward()								\
		iterate_in_deallocate_link_binary_in_direction(-, +)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_in_deallocate_segment(in_direction, arity_policy)							\
	iterate_in_mutate_##arity_policy##_##in_direction()


#define iterate_in_deallocate_hook(in_direction, arity_policy)								\
	iterate_in_deallocate_hook_##arity_policy##_##in_direction()


#define iterate_in_deallocate_link(in_direction, arity_policy)								\
	iterate_in_deallocate_link_##arity_policy##_##in_direction()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define iterate_in_mutate(in_direction, in_pointer, arity_policy)							\
	iterate_in_mutate_##arity_policy##_##in_direction(in_pointer)


#define iterate_in_deallocate(in_direction, in_pointer, arity_policy)							\
	iterate_in_deallocate_##in_pointer(in_direction, arity_policy)


/***********************************************************************************************************************/


#define iterate_in(in_direction, in_memory, in_pointer, arity_policy)							\
	iterate_in_##in_memory(in_direction, in_pointer, arity_policy)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define memory_action_in_deallocate_segment(arity_policy)


	#define memory_action_in_deallocate_hook_unary()			delete inr;


	#define memory_action_in_deallocate_hook_binary()			delete inl;				\
										delete inr;


#define memory_action_in_deallocate_hook(arity_policy)									\
	memory_action_in_deallocate_hook_##arity_policy()


	#define memory_action_in_deallocate_link_unary()								\
		memory_action_in_deallocate_hook_unary()


	#define memory_action_in_deallocate_link_binary()								\
		memory_action_in_deallocate_hook_binary()


#define memory_action_in_deallocate_link(arity_policy)									\
	memory_action_in_deallocate_link_##arity_policy()


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define memory_action_in_mutate(in_pointer, arity_policy)


#define memory_action_in_deallocate(in_pointer, arity_policy)								\
	memory_action_in_deallocate_##in_pointer(arity_policy)


/***********************************************************************************************************************/


#define memory_action_in(in_memory, in_pointer, arity_policy)								\
	memory_action_in_##in_memory(in_pointer, arity_policy)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


	#define undeclare_variables_deallocate_segment_unary()			delete [] originr;


	#define undeclare_variables_deallocate_segment_binary()			delete [] originl;			\
										delete [] originr;


#define undeclare_variables_deallocate_segment(arity_policy)								\
	undeclare_variables_deallocate_segment_##arity_policy()


#define undeclare_variables_deallocate_hook(arity_policy)


#define undeclare_variables_deallocate_link(arity_policy)


/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define undeclare_variables_mutate(in_pointer, arity_policy)


#define undeclare_variables_deallocate(in_pointer, arity_policy)							\
	undeclare_variables_deallocate_##in_pointer(arity_policy)


/***********************************************************************************************************************/


#define undeclare_variables(in_memory, in_pointer, arity_policy)							\
	undeclare_variables_##in_memory(in_pointer, arity_policy)


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#define return_action_omit_return()


#define return_action_apply_return()						return out;


/***********************************************************************************************************************/


#define return_action(return_policy)											\
	return_action_##return_policy()


