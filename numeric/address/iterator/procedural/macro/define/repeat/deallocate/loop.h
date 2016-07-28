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
	It is meant to be bootstrapped with a given macro interpretation.
*/


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop(											\
			interval_policy, direction_policy,						\
			count_policy, return_policy)							\
													\
template<typename Filler>										\
struct deallocate_loop											\
<													\
	typename gvs_semiotic::template list								\
	<												\
		arg::list::interval_policy, arg::list::direction_policy,				\
		arg::list::count_policy, arg::list::return_policy					\
	>,												\
													\
	Filler												\
>													\
{													\
	loop												\
	(												\
		empty,											\
		emptiness, =,  ,  ,									\
		interval_policy, direction_policy,							\
		apply_delete, count_policy, return_policy						\
	)												\
													\
	loop												\
	(												\
		generic,										\
		genericity,  ,  ,  ,									\
		interval_policy, direction_policy,							\
		apply_delete, count_policy, return_policy						\
	)												\
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


template<typename configuration, typename Filler = void>
struct deallocate_loop
{
	static_assert(true, "This method has not yet been declared.");
};


