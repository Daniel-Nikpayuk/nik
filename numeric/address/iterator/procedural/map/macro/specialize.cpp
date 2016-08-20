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

#include"macro/macro.hpp"
#include"macro/macro.hh"

#define declare_loop(													\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_interval, in_direction, in_memory, in_pointer,						\
			fast_policy, count_policy)									\
															\
template<>														\
typename s_semiotic::template type<value_type>::template iterator							\
<															\
	ModIterator::out_interval, ModIterator::out_direction,								\
	ModIterator::out_memory, ModIterator::out_pointer								\
															\
>::traits::return_type specialize											\
<															\
	typename s_semiotic::template type<value_type>::template iterator						\
	<														\
		ModIterator::out_interval, ModIterator::out_direction,							\
		ModIterator::out_memory, ModIterator::out_pointer							\
	>,														\
															\
	typename s_semiotic::template type<value_type>::template iterator						\
	<														\
		ModIterator::in_interval, ModIterator::in_direction,							\
		ModIterator::in_memory, ModIterator::in_pointer								\
	>,														\
															\
	typename s_semiotic::template type<value_type>::template optimizer						\
	<														\
		ModOptimizer::fast_policy, ModOptimizer::count_policy							\
	>														\
>::loop															\
(															\
	arg,														\
	out_interval, out_direction, out_memory, out_pointer,								\
	in_interval, in_direction, in_memory, in_pointer,								\
	omit_functor, unary, return_policy, count_policy								\
)															\


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


