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


#define declare_loop_return(										\
			interval_policy, direction_policy,						\
			count_policy)									\
													\
	declare_loop											\
	(												\
		interval_policy, direction_policy,							\
		count_policy, apply_return								\
	)												\
													\
	declare_loop											\
	(												\
		interval_policy, direction_policy,							\
		count_policy, omit_return								\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_count_return(									\
			interval_policy, direction_policy)						\
													\
	declare_loop_return										\
	(												\
		interval_policy, direction_policy,							\
		omit_count										\
	)												\
													\
	declare_loop_return										\
	(												\
		interval_policy, direction_policy,							\
		apply_count										\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_direction_count_return(								\
			interval_policy)								\
													\
	declare_loop_count_return									\
	(												\
		interval_policy, forward								\
	)												\
													\
	declare_loop_count_return									\
	(												\
		interval_policy, backward								\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#define declare_loop_interval_direction_count_return()							\
													\
	declare_loop_direction_count_return								\
	(												\
		closing											\
	)												\
													\
	declare_loop_direction_count_return								\
	(												\
		closed											\
	)												\
													\
	declare_loop_direction_count_return								\
	(												\
		opening											\
	)												\
													\
	declare_loop_direction_count_return								\
	(												\
		open											\
	)


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


declare_loop_interval_direction_count_return()


