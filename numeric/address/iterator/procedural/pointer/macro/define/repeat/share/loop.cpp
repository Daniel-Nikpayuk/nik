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


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*************************************************************************************************************************
							closing
*************************************************************************************************************************/


/*
	Constraints:

	[in, end)
*/


#define loop_closing(														\
	label, operator_policy, op_a, op_l, op_r, direction_policy, delete_policy, count_policy, return_policy)			\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	while (in != end)													\
	{															\
		operator_policy(op_a, op_l, op_r)										\
		count_policy()													\
																\
		direction_policy(delete_policy)											\
	}															\
																\
	return_policy()														\
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[in, end]
*/


#define loop_closed(														\
	label, operator_policy, op_a, op_l, op_r, direction_policy, delete_policy, count_policy, return_policy)			\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	while (in != end)													\
	{															\
		operator_policy(op_a, op_l, op_r)										\
		count_policy()													\
																\
		direction_policy(delete_policy)											\
	}															\
																\
	operator_policy(op_a, op_l, op_r)											\
	count_policy()														\
																\
	delete_policy()														\
																\
	return_policy()														\
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	(in, end]
*/


#define loop_opening_omit_delete(												\
	label, operator_policy, op_a, op_l, op_r, direction_policy, count_policy, return_policy)				\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	while (in != end)													\
	{															\
		direction_policy(omit_delete)											\
																\
		operator_policy(op_a, op_l, op_r)										\
		count_policy()													\
	}															\
																\
	return_policy()														\
}


/*
	Constraints:

	(in, end], end-in > 0
*/


#define loop_opening_apply_delete(												\
	label, operator_policy, op_a, op_l, op_r, direction_policy, count_policy, return_policy)				\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	direction_policy(omit_delete)												\
																\
	while (in != end)													\
	{															\
		operator_policy(op_a, op_l, op_r)										\
		count_policy()													\
																\
		direction_policy(apply_delete)											\
	}															\
																\
	operator_policy(op_a, op_l, op_r)											\
	count_policy()														\
																\
	apply_delete()														\
																\
	return_policy()														\
}


#define loop_opening(														\
		label, operator_policy, op_a, op_l, op_r, direction_policy, delete_policy, count_policy, return_policy)		\
	loop_opening_##delete_policy(												\
		label, operator_policy, op_a, op_l, op_r, direction_policy, count_policy, return_policy)


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	(in, end), end-in > 0
*/


#define loop_open(														\
	label, operator_policy, op_a, op_l, op_r, direction_policy, delete_policy, count_policy, return_policy)			\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	direction_policy(omit_delete)												\
																\
	while (in != end)													\
	{															\
		operator_policy(op_a, op_l, op_r)										\
		count_policy()													\
																\
		direction_policy(delete_policy)											\
	}															\
																\
	return_policy()														\
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	interval_policy:

		closing
		closed
		opening
		open
*/


#define shared_loop(									\
		label,									\
		operator_policy, op_a, op_l, op_r,					\
		interval_policy, direction_policy,					\
		delete_policy, count_policy, return_policy)				\
											\
	loop_##interval_policy(								\
		label,									\
		operator_policy, op_a, op_l, op_r,					\
		direction_policy,							\
		delete_policy, count_policy, return_policy)


