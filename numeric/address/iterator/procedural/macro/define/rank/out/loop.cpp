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

	[out, out + n)
*/


#define loop_as_closing(													\
	label, operator_policy, op_a, op_l, op_r, direction_policy, count_policy, return_policy)				\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	declare_variables(direction_policy)											\
																\
	while (n)														\
	{															\
		operator_policy(op_a, op_l, op_r)										\
		direction_policy()												\
		count_policy()													\
		--n;														\
	}															\
																\
	return_policy()														\
}


/*************************************************************************************************************************
							closed
*************************************************************************************************************************/


/*
	Constraints:

	[out, out + n]
*/


#define loop_as_closed(														\
	label, operator_policy, op_a, op_l, op_r, direction_policy, count_policy, return_policy)				\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	declare_variables(direction_policy)											\
																\
	while (n)														\
	{															\
		operator_policy(op_a, op_l, op_r)										\
		direction_policy()												\
		count_policy()													\
		--n;														\
	}															\
																\
	operator_policy(op_a, op_l, op_r)											\
	count_policy()														\
																\
	return_policy()														\
}


/*************************************************************************************************************************
							opening
*************************************************************************************************************************/


/*
	Constraints:

	(out, out + n]
*/


#define loop_as_opening(													\
	label, operator_policy, op_a, op_l, op_r, direction_policy, count_policy, return_policy)				\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	declare_variables(direction_policy)											\
																\
	while (n)														\
	{															\
		direction_policy()												\
		operator_policy(op_a, op_l, op_r)										\
		count_policy()													\
		--n;														\
	}															\
																\
	return_policy()														\
}


/*************************************************************************************************************************
							open
*************************************************************************************************************************/


/*
	Constraints:

	(out, out + n), n > 0
*/


#define loop_as_open(														\
	label, operator_policy, op_a, op_l, op_r, direction_policy, count_policy, return_policy)				\
function_type(label, operator_policy, count_policy, return_policy)								\
{																\
	declare_variables(direction_policy)											\
	direction_policy()													\
	--n;															\
																\
	while (n)														\
	{															\
		operator_policy(op_a, op_l, op_r)										\
		direction_policy()												\
		count_policy()													\
		--n;														\
	}															\
																\
	return_policy()														\
}


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


/*
	interval_policy:

		as_closing
		as_closed
		as_opening
		as_open
*/


#define loop(										\
		label,									\
		operator_policy, op_a, op_l, op_r,					\
		interval_policy, direction_policy,					\
		count_policy, return_policy)						\
											\
	loop_##interval_policy(								\
		label,									\
		operator_policy, op_a, op_l, op_r,					\
		direction_policy,							\
		count_policy, return_policy)


