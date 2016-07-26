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
			delete_policy, count_policy, return_policy)					\
													\
template<typename Filler>										\
struct in_loop												\
<													\
	typename gvs_semiotic::template list								\
	<												\
		in::interval_policy, in::direction_policy,						\
		in::delete_policy, in::count_policy, in::return_policy					\
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
		delete_policy, count_policy, return_policy						\
	)												\
													\
	loop												\
	(												\
		generic,										\
		genericity,  ,  ,  ,									\
		interval_policy, direction_policy,							\
		delete_policy, count_policy, return_policy						\
	)												\
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


template<typename configuration, typename Filler = void>
struct in_loop
{
	static_assert(true, "This method has not yet been declared.");
};


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_return(										\
			interval_policy, direction_policy,						\
			delete_policy, count_policy)							\
													\
	declare_loop											\
	(												\
		interval_policy, direction_policy,							\
		delete_policy, count_policy, apply_return						\
	)												\
													\
	declare_loop											\
	(												\
		interval_policy, direction_policy,							\
		delete_policy, count_policy, omit_return						\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_count_return(									\
			interval_policy, direction_policy,						\
			delete_policy)									\
													\
	declare_loop_return										\
	(												\
		interval_policy, direction_policy,							\
		delete_policy, omit_count								\
	)												\
													\
	declare_loop_return										\
	(												\
		interval_policy, direction_policy,							\
		delete_policy, apply_count								\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_delete_count_return(								\
			interval_policy, direction_policy)						\
													\
	declare_loop_count_return									\
	(												\
		interval_policy, direction_policy,							\
		omit_delete										\
	)												\
													\
	declare_loop_count_return									\
	(												\
		interval_policy, direction_policy,							\
		apply_delete										\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_direction_delete_count_return(							\
			interval_policy)								\
													\
	declare_loop_delete_count_return								\
	(												\
		interval_policy, as_forward								\
	)												\
													\
	declare_loop_delete_count_return								\
	(												\
		interval_policy, as_backward								\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_interval_direction_delete_count_return()						\
													\
	declare_loop_direction_delete_count_return							\
	(												\
		as_closing										\
	)												\
													\
	declare_loop_direction_delete_count_return							\
	(												\
		as_closed										\
	)												\
													\
	declare_loop_direction_delete_count_return							\
	(												\
		as_opening										\
	)												\
													\
	declare_loop_direction_delete_count_return							\
	(												\
		as_open											\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


declare_loop_interval_direction_delete_count_return()


