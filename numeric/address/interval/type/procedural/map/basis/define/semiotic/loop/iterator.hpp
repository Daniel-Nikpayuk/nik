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


// iterator


/************************************************************************************************************************/
/************************************************************************************************************************/


#define iterator_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	static rtn label(out_pointer out, size_type m, size_type n)


	#define iterator_unary_mutate_mutate_omit_count_apply_return(label, out_pointer, in_pointer)					\
		iterator_unary_mutate_mutate_omit_count_return_policy(label, out_pointer::pointer &, in_pointer, out_pointer::pointer)

	#define iterator_unary_mutate_mutate_omit_count_omit_return(label, out_pointer, in_pointer)					\
		iterator_unary_mutate_mutate_omit_count_return_policy(label, out_pointer::pointer, in_pointer, void)


#define iterator_unary_mutate_mutate_omit_count(label, out_pointer, in_pointer, return_policy)						\
	iterator_unary_mutate_mutate_omit_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define iterator_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, rtn)					\
																	\
																	\
	static rtn label(size_type & count, out_pointer::pointer out, size_type m, size_type n)


	#define iterator_unary_mutate_mutate_apply_count_apply_return(label, out_pointer, in_pointer)					\
		iterator_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define iterator_unary_mutate_mutate_apply_count_omit_return(label, out_pointer, in_pointer)					\
		iterator_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, void)


#define iterator_unary_mutate_mutate_apply_count(label, out_pointer, in_pointer, return_policy)						\
	iterator_unary_mutate_mutate_apply_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/
/************************************************************************************************************************/


// functor iterator


/************************************************************************************************************************/
/************************************************************************************************************************/


#define functor_iterator_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	template<typename Functor>													\
	static rtn label(out_pointer::pointer out, Functor functor, size_type m, size_type n)


	#define functor_iterator_unary_mutate_mutate_omit_count_apply_return(label, out_pointer, in_pointer)				\
		functor_iterator_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define functor_iterator_unary_mutate_mutate_omit_count_omit_return(label, out_pointer, in_pointer)				\
		functor_iterator_unary_mutate_mutate_omit_count_return_policy(label, out_pointer, in_pointer, void)


#define functor_iterator_unary_mutate_mutate_omit_count(label, out_pointer, in_pointer, return_policy)					\
	functor_iterator_unary_mutate_mutate_omit_count_##return_policy(label, out_pointer, in_pointer)


/************************************************************************************************************************/


#define functor_iterator_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, rtn)				\
																	\
																	\
	template<typename Functor>													\
	static rtn label(size_type & count, out_pointer::pointer out, Functor functor, size_type m, size_type n)


	#define functor_iterator_unary_mutate_mutate_apply_count_apply_return(label, out_pointer, in_pointer)				\
		functor_iterator_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, out_pointer::pointer)

	#define functor_iterator_unary_mutate_mutate_apply_count_omit_return(label, out_pointer, in_pointer)				\
		functor_iterator_unary_mutate_mutate_apply_count_return_policy(label, out_pointer, in_pointer, void)


#define functor_iterator_unary_mutate_mutate_apply_count(label, out_pointer, in_pointer, return_policy)					\
	functor_iterator_unary_mutate_mutate_apply_count_##return_policy(label, out_pointer, in_pointer)


