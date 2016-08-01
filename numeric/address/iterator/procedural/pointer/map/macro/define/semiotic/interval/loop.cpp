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
	template<typename WPointer, typename EWPointer>											\
	static rtn label(WPointer in, EWPointer end, size_type m, size_type n)


		#define function_type_interval_omit_count_omit_return(label)								\
			function_type_interval_omit_count(void, label)
                                                          
		#define function_type_interval_omit_count_apply_return(label)								\
			function_type_interval_omit_count(WPointer, label)


#define function_type_interval_apply_count(rtn, label)											\
																	\
																	\
	template<typename WPointer, typename EWPointer>											\
	static rtn label(size_type & count, WPointer in, EWPointer end, size_type m, size_type n)


		#define function_type_interval_apply_count_omit_return(label)								\
			function_type_interval_apply_count(void, label)
                                                           
		#define function_type_interval_apply_count_apply_return(label)								\
			function_type_interval_apply_count(WPointer, label)


// genericity


#define function_type_genericity_omit_count(rtn, label)											\
																	\
																	\
	template<typename Functor, typename WPointer, typename EWPointer>								\
	static rtn label(Functor functor, WPointer in, EWPointer end, size_type m, size_type n)


		#define function_type_genericity_omit_count_omit_return(label)								\
			function_type_genericity_omit_count(void, label)
                                                           
		#define function_type_genericity_omit_count_apply_return(label)								\
			function_type_genericity_omit_count(WPointer, label)


#define function_type_genericity_apply_count(rtn, label)										\
																	\
																	\
	template<typename Functor, typename WPointer, typename EWPointer>								\
	static rtn label(size_type & count, Functor functor, WPointer in, EWPointer end, size_type m, size_type n)


		#define function_type_genericity_apply_count_omit_return(label)								\
			function_type_genericity_apply_count(void, label)
                                                            
		#define function_type_genericity_apply_count_apply_return(label)							\
			function_type_genericity_apply_count(WPointer, label)


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


#define interval(op_a, op_l, op_r)							(*in) op_a op_l (m) op_r;


#define genericity(op_a, op_l, op_r)							functor(in);


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define direction_policy_omit_delete(dir)						dir##dir(in);


	#define as_forward_omit_delete()					direction_policy_omit_delete(+)
	#define as_backward_omit_delete()					direction_policy_omit_delete(-)


#define direction_policy_apply_delete(dir)						delete (in)dir##dir;


	#define as_forward_apply_delete()					direction_policy_apply_delete(+)
	#define as_backward_apply_delete()					direction_policy_apply_delete(-)


/************************************************************************************************************************/


/*
	in_direction:

		as_forward
		as_backward
*/


#define as_forward(delete_policy)											\
	as_forward_##delete_policy()


#define as_backward(delete_policy)											\
	as_backward_##delete_policy()


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	delete_policy:

		omit_delete
		apply_delete
*/


#define omit_delete()


#define apply_delete()									delete in;


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


#define apply_return()									return in;


#define omit_return()


