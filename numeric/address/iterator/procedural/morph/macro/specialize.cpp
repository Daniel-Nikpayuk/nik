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


#define declare_loop(													\
			out_interval, out_direction, out_memory, out_pointer,						\
			in_arity, in_interval, in_direction, in_memory, in_pointer,					\
			functor_policy, count_policy)									\
															\
template<>														\
typename s_semiotic::template type<value_type>::template iterator							\
<															\
	ModIterator::unary, ModIterator::out_interval,									\
	ModIterator::out_direction, ModIterator::mutate, ModIterator::out_pointer					\
															\
>::traits::return_type specialize											\
<															\
	typename s_semiotic::template type<value_type>::template iterator						\
	<														\
		ModIterator::unary, ModIterator::out_interval,								\
		ModIterator::out_direction, ModIterator::out_memory, ModIterator::out_pointer				\
	>,														\
															\
	typename s_semiotic::template type<value_type>::template iterator						\
	<														\
		ModIterator::in_arity, ModIterator::in_interval,							\
		ModIterator::in_direction, ModIterator::in_memory, ModIterator::in_pointer				\
	>,														\
															\
	typename s_semiotic::template type<value_type>::template optimizer						\
	<														\
		ModOptimizer::functor_policy, ModOptimizer::count_policy						\
	>														\
															\
>::loop															\
(															\
	map,														\
	out_interval, out_direction, out_memory, out_pointer,								\
	in_arity, in_interval, in_direction, in_memory, in_pointer,							\
	functor_policy, count_policy											\
)															\


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


