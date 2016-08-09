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


#define interval_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	static rtn label(out_pointer::pointer out, size_type m, size_type n)


	#define interval_unary_mutate_mutate_omit_count_apply_return(label, out_pointer, in_pointer)					\
		interval_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define interval_unary_mutate_mutate_omit_count_omit_return(label, out_pointer, in_pointer)					\
		interval_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, void)


#define interval_unary_mutate_mutate_omit_count(label, out_pointer, in_pointer, return_policy)						\
	interval_unary_mutate_mutate_omit_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define interval_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	static rtn label(size_type & count, out_pointer::pointer out, size_type m, size_type n)


	#define interval_unary_mutate_mutate_apply_count_apply_return(label, out_pointer, in_pointer)					\
		interval_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define interval_unary_mutate_mutate_apply_count_omit_return(label, out_pointer, in_pointer)					\
		interval_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, void)


#define interval_unary_mutate_mutate_apply_count(label, out_pointer, in_pointer, return_policy)						\
	interval_unary_mutate_mutate_apply_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define interval_unary_mutate_deallocate_omit_count_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	static rtn label(out_pointer::pointer out, size_type m, size_type n)


	#define interval_unary_mutate_deallocate_omit_count_apply_return(label, out_pointer, in_pointer)				\
		interval_unary_mutate_deallocate_omit_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define interval_unary_mutate_deallocate_omit_count_omit_return(label, out_pointer, in_pointer)					\
		interval_unary_mutate_deallocate_omit_count_return_policy(label, out_pointer, in_pointer, void)


#define interval_unary_mutate_deallocate_omit_count(label, out_pointer, in_pointer, return_policy)					\
	interval_unary_mutate_deallocate_omit_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define interval_unary_mutate_deallocate_apply_count_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	static rtn label(size_type & count, out_pointer::pointer out, size_type m, size_type n)


	#define interval_unary_mutate_deallocate_apply_count_apply_return(label, out_pointer, in_pointer)				\
		interval_unary_mutate_deallocate_apply_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define interval_unary_mutate_deallocate_apply_count_omit_return(label, out_pointer, in_pointer)				\
		interval_unary_mutate_deallocate_apply_count_return_policy(label, out_pointer, in_pointer, void)


#define interval_unary_mutate_deallocate_apply_count(label, out_pointer, in_pointer, return_policy)					\
	interval_unary_mutate_deallocate_apply_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define interval_unary_allocate_mutate_omit_count_segment_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	static rtn label(out_pointer::pointer out, size_type l, size_type m, size_type n)


	#define interval_unary_allocate_mutate_omit_count_segment_apply_return(label, in_pointer)					\
		interval_unary_allocate_mutate_omit_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define interval_unary_allocate_mutate_omit_count_segment_omit_return(label, in_pointer)					\
		interval_unary_allocate_mutate_omit_count_segment_return_policy(label, segment, in_pointer, void)


	#define interval_unary_allocate_mutate_omit_count_hook_apply_return(label, in_pointer)						\
		interval_unary_mutate_mutate_omit_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define interval_unary_allocate_mutate_omit_count_hook_omit_return(label, in_pointer)						\
		interval_unary_mutate_mutate_omit_count_return_policy(label, hook, in_pointer, void)


	#define interval_unary_allocate_mutate_omit_count_link_apply_return(label, in_pointer)						\
		interval_unary_mutate_mutate_omit_count_return_policy(label, link, in_pointer, link::pointer)

	#define interval_unary_allocate_mutate_omit_count_link_omit_return(label, in_pointer)						\
		interval_unary_mutate_mutate_omit_count_return_policy(label, link, in_pointer, void)


#define interval_unary_allocate_mutate_omit_count(label, out_pointer, in_pointer, return_policy)					\
	interval_unary_allocate_mutate_omit_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/


#define interval_unary_allocate_mutate_apply_count_segment_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	static rtn label(size_type & count, out_pointer::pointer out, size_type l, size_type m, size_type n)


	#define interval_unary_allocate_mutate_apply_count_segment_apply_return(label, in_pointer)					\
		interval_unary_allocate_mutate_apply_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define interval_unary_allocate_mutate_apply_count_segment_omit_return(label, in_pointer)					\
		interval_unary_allocate_mutate_apply_count_segment_return_policy(label, segment, in_pointer, void)


	#define interval_unary_allocate_mutate_apply_count_hook_apply_return(label, in_pointer)						\
		interval_unary_mutate_mutate_apply_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define interval_unary_allocate_mutate_apply_count_hook_omit_return(label, in_pointer)						\
		interval_unary_mutate_mutate_apply_count_return_policy(label, hook, in_pointer, void)


	#define interval_unary_allocate_mutate_apply_count_link_apply_return(label, in_pointer)						\
		interval_unary_mutate_mutate_apply_count_return_policy(label, link, in_pointer, link::pointer)

	#define interval_unary_allocate_mutate_apply_count_link_omit_return(label, in_pointer)						\
		interval_unary_mutate_mutate_apply_count_return_policy(label, link, in_pointer, void)


#define interval_unary_allocate_mutate_apply_count(label, out_pointer, in_pointer, return_policy)					\
	interval_unary_allocate_mutate_apply_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/


#define interval_unary_allocate_deallocate_omit_count_segment_return_policy(label, out_pointer, in_pointer, rtn)			\
																	\
																	\
	static rtn label(out_pointer::pointer out, size_type l, size_type m, size_type n)


	#define interval_unary_allocate_deallocate_omit_count_segment_apply_return(label, in_pointer)					\
		interval_unary_allocate_deallocate_omit_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define interval_unary_allocate_deallocate_omit_count_segment_omit_return(label, in_pointer)					\
		interval_unary_allocate_deallocate_omit_count_segment_return_policy(label, segment, in_pointer, void)


	#define interval_unary_allocate_deallocate_omit_count_hook_apply_return(label, in_pointer)					\
		interval_unary_mutate_deallocate_omit_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define interval_unary_allocate_deallocate_omit_count_hook_omit_return(label, in_pointer)					\
		interval_unary_mutate_deallocate_omit_count_return_policy(label, hook, in_pointer, void)


	#define interval_unary_allocate_deallocate_omit_count_link_apply_return(label, in_pointer)					\
		interval_unary_mutate_deallocate_omit_count_return_policy(label, link, in_pointer, link::pointer)

	#define interval_unary_allocate_deallocate_omit_count_link_omit_return(label, in_pointer)					\
		interval_unary_mutate_deallocate_omit_count_return_policy(label, link, in_pointer, void)


#define interval_unary_allocate_deallocate_omit_count(label, out_pointer, in_pointer, return_policy)					\
	interval_unary_allocate_deallocate_omit_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/


#define interval_unary_allocate_deallocate_apply_count_segment_return_policy(label, out_pointer, in_pointer, rtn)			\
																	\
																	\
	static rtn label(size_type & count, out_pointer::pointer out, size_type l, size_type m, size_type n)


	#define interval_unary_allocate_deallocate_apply_count_segment_apply_return(label, in_pointer)					\
		interval_unary_allocate_deallocate_apply_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define interval_unary_allocate_deallocate_apply_count_segment_omit_return(label, in_pointer)					\
		interval_unary_allocate_deallocate_apply_count_segment_return_policy(label, segment, in_pointer, void)


	#define interval_unary_allocate_deallocate_apply_count_hook_apply_return(label, in_pointer)					\
		interval_unary_mutate_deallocate_apply_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define interval_unary_allocate_deallocate_apply_count_hook_omit_return(label, in_pointer)					\
		interval_unary_mutate_deallocate_apply_count_return_policy(label, hook, in_pointer, void)


	#define interval_unary_allocate_deallocate_apply_count_link_apply_return(label, in_pointer)					\
		interval_unary_mutate_deallocate_apply_count_return_policy(label, link, in_pointer, link::pointer)

	#define interval_unary_allocate_deallocate_apply_count_link_omit_return(label, in_pointer)					\
		interval_unary_mutate_deallocate_apply_count_return_policy(label, link, in_pointer, void)


#define interval_unary_allocate_deallocate_apply_count(label, out_pointer, in_pointer, return_policy)					\
	interval_unary_allocate_deallocate_apply_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


// functor interval


/************************************************************************************************************************/
/************************************************************************************************************************/


#define functor_interval_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	template<typename Functor>													\
	static rtn label(out_pointer::pointer out, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_mutate_mutate_omit_count_apply_return(label, out_pointer, in_pointer)				\
		functor_interval_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define functor_interval_unary_mutate_mutate_omit_count_omit_return(label, out_pointer, in_pointer)				\
		functor_interval_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, void)


#define functor_interval_unary_mutate_mutate_omit_count(label, out_pointer, in_pointer, return_policy)					\
	functor_interval_unary_mutate_mutate_omit_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define functor_interval_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	template<typename Functor>													\
	static rtn label(size_type & count, out_pointer::pointer out, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_mutate_mutate_apply_count_apply_return(label, out_pointer, in_pointer)				\
		functor_interval_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define functor_interval_unary_mutate_mutate_apply_count_omit_return(label, out_pointer, in_pointer)				\
		functor_interval_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, void)


#define functor_interval_unary_mutate_mutate_apply_count(label, out_pointer, in_pointer, return_policy)					\
	functor_interval_unary_mutate_mutate_apply_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define functor_interval_unary_mutate_deallocate_omit_count_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	template<typename Functor>													\
	static rtn label(out_pointer::pointer out, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_mutate_deallocate_omit_count_apply_return(label, out_pointer, in_pointer)			\
		functor_interval_unary_mutate_deallocate_omit_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define functor_interval_unary_mutate_deallocate_omit_count_omit_return(label, out_pointer, in_pointer)				\
		functor_interval_unary_mutate_deallocate_omit_count_return_policy(label, out_pointer, in_pointer, void)


#define functor_interval_unary_mutate_deallocate_omit_count(label, out_pointer, in_pointer, return_policy)				\
	functor_interval_unary_mutate_deallocate_omit_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define functor_interval_unary_mutate_deallocate_apply_count_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	template<typename Functor>													\
	static rtn label(size_type & count, out_pointer::pointer out, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_mutate_deallocate_apply_count_apply_return(label, out_pointer, in_pointer)			\
		functor_interval_unary_mutate_deallocate_apply_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define functor_interval_unary_mutate_deallocate_apply_count_omit_return(label, out_pointer, in_pointer)			\
		functor_interval_unary_mutate_deallocate_apply_count_return_policy(label, out_pointer, in_pointer, void)


#define functor_interval_unary_mutate_deallocate_apply_count(label, out_pointer, in_pointer, return_policy)				\
	functor_interval_unary_mutate_deallocate_apply_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


#define functor_interval_unary_allocate_mutate_omit_count_segment_return_policy(label, out_pointer, in_pointer, rtn)			\
																	\
																	\
	template<typename Functor>													\
	static rtn label(out_pointer::pointer out, size_type l, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_allocate_mutate_omit_count_segment_apply_return(label, in_pointer)				\
		functor_interval_unary_allocate_mutate_omit_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define functor_interval_unary_allocate_mutate_omit_count_segment_omit_return(label, in_pointer)				\
		functor_interval_unary_allocate_mutate_omit_count_segment_return_policy(label, segment, in_pointer, void)


	#define functor_interval_unary_allocate_mutate_omit_count_hook_apply_return(label, in_pointer)					\
		functor_interval_unary_mutate_mutate_omit_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define functor_interval_unary_allocate_mutate_omit_count_hook_omit_return(label, in_pointer)					\
		functor_interval_unary_mutate_mutate_omit_count_return_policy(label, hook, in_pointer, void)


	#define functor_interval_unary_allocate_mutate_omit_count_link_apply_return(label, in_pointer)					\
		functor_interval_unary_mutate_mutate_omit_count_return_policy(label, link, in_pointer, link::pointer)

	#define functor_interval_unary_allocate_mutate_omit_count_link_omit_return(label, in_pointer)					\
		functor_interval_unary_mutate_mutate_omit_count_return_policy(label, link, in_pointer, void)


#define functor_interval_unary_allocate_mutate_omit_count(label, out_pointer, in_pointer, return_policy)				\
	functor_interval_unary_allocate_mutate_omit_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/


#define functor_interval_unary_allocate_mutate_apply_count_segment_return_policy(label, out_pointer, in_pointer, rtn)			\
																	\
																	\
	template<typename Functor>													\
	static rtn label(size_type & count, out_pointer::pointer out, size_type l, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_allocate_mutate_apply_count_segment_apply_return(label, in_pointer)				\
		functor_interval_unary_allocate_mutate_apply_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define functor_interval_unary_allocate_mutate_apply_count_segment_omit_return(label, in_pointer)				\
		functor_interval_unary_allocate_mutate_apply_count_segment_return_policy(label, segment, in_pointer, void)


	#define functor_interval_unary_allocate_mutate_apply_count_hook_apply_return(label, in_pointer)					\
		functor_interval_unary_mutate_mutate_apply_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define functor_interval_unary_allocate_mutate_apply_count_hook_omit_return(label, in_pointer)					\
		functor_interval_unary_mutate_mutate_apply_count_return_policy(label, hook, in_pointer, void)


	#define functor_interval_unary_allocate_mutate_apply_count_link_apply_return(label, in_pointer)					\
		functor_interval_unary_mutate_mutate_apply_count_return_policy(label, link, in_pointer, link::pointer)

	#define functor_interval_unary_allocate_mutate_apply_count_link_omit_return(label, in_pointer)					\
		functor_interval_unary_mutate_mutate_apply_count_return_policy(label, link, in_pointer, void)


#define functor_interval_unary_allocate_mutate_apply_count(label, out_pointer, in_pointer, return_policy)				\
	functor_interval_unary_allocate_mutate_apply_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/


#define functor_interval_unary_allocate_deallocate_omit_count_segment_return_policy(label, out_pointer, in_pointer, rtn)		\
																	\
																	\
	template<typename Functor>													\
	static rtn label(out_pointer::pointer out, size_type l, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_allocate_deallocate_omit_count_segment_apply_return(label, in_pointer)				\
		functor_interval_unary_allocate_deallocate_omit_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define functor_interval_unary_allocate_deallocate_omit_count_segment_omit_return(label, in_pointer)				\
		functor_interval_unary_allocate_deallocate_omit_count_segment_return_policy(label, segment, in_pointer, void)


	#define functor_interval_unary_allocate_deallocate_omit_count_hook_apply_return(label, in_pointer)				\
		functor_interval_unary_mutate_deallocate_omit_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define functor_interval_unary_allocate_deallocate_omit_count_hook_omit_return(label, in_pointer)				\
		functor_interval_unary_mutate_deallocate_omit_count_return_policy(label, hook, in_pointer, void)


	#define functor_interval_unary_allocate_deallocate_omit_count_link_apply_return(label, in_pointer)				\
		functor_interval_unary_mutate_deallocate_omit_count_return_policy(label, link, in_pointer, link::pointer)

	#define functor_interval_unary_allocate_deallocate_omit_count_link_omit_return(label, in_pointer)				\
		functor_interval_unary_mutate_deallocate_omit_count_return_policy(label, link, in_pointer, void)


#define functor_interval_unary_allocate_deallocate_omit_count(label, out_pointer, in_pointer, return_policy)				\
	functor_interval_unary_allocate_deallocate_omit_count_##out_pointer##_##return_policy(label, in_pointer)


/************************************************************************************************************************/


#define functor_interval_unary_allocate_deallocate_apply_count_segment_return_policy(label, out_pointer, in_pointer, rtn)		\
																	\
																	\
	template<typename Functor>													\
	static rtn label(size_type & count, out_pointer::pointer out, size_type l, Functor functor, size_type m, size_type n)


	#define functor_interval_unary_allocate_deallocate_apply_count_segment_apply_return(label, in_pointer)				\
		functor_interval_unary_allocate_deallocate_apply_count_segment_return_policy(label, segment, in_pointer, segment::pointer)

	#define functor_interval_unary_allocate_deallocate_apply_count_segment_omit_return(label, in_pointer)				\
		functor_interval_unary_allocate_deallocate_apply_count_segment_return_policy(label, segment, in_pointer, void)


	#define functor_interval_unary_allocate_deallocate_apply_count_hook_apply_return(label, in_pointer)				\
		functor_interval_unary_mutate_deallocate_apply_count_return_policy(label, hook, in_pointer, hook::pointer)

	#define functor_interval_unary_allocate_deallocate_apply_count_hook_omit_return(label, in_pointer)				\
		functor_interval_unary_mutate_deallocate_apply_count_return_policy(label, hook, in_pointer, void)


	#define functor_interval_unary_allocate_deallocate_apply_count_link_apply_return(label, in_pointer)				\
		functor_interval_unary_mutate_deallocate_apply_count_return_policy(label, link, in_pointer, link::pointer)

	#define functor_interval_unary_allocate_deallocate_apply_count_link_omit_return(label, in_pointer)				\
		functor_interval_unary_mutate_deallocate_apply_count_return_policy(label, link, in_pointer, void)


#define functor_interval_unary_allocate_deallocate_apply_count(label, out_pointer, in_pointer, return_policy)				\
	functor_interval_unary_allocate_deallocate_apply_count_##out_pointer##_##return_policy(label, in_pointer)


