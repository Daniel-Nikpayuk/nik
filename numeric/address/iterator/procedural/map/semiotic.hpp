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


#define ADV_SPECIALIZE		Adverb<LIST<functorEnum, tracerEnum, Connotation::specialize>, F>


/************************************************************************************************************************/


#define SUB_ADJ_CLOSING		SubjectAdjective<LIST<sub_directionEnum, Association::closing, sub_imageEnum, sub_iteratorEnum>>

#define SUB_ADJ_CLOSED		SubjectAdjective<LIST<sub_directionEnum, Association::closed, sub_imageEnum, sub_iteratorEnum>>

#define SUB_ADJ_OPENING		SubjectAdjective<LIST<sub_directionEnum, Association::opening, sub_imageEnum, sub_iteratorEnum>>

#define SUB_ADJ_OPEN		SubjectAdjective<LIST<sub_directionEnum, Association::open, sub_imageEnum, sub_iteratorEnum>>


/***********************************************************************************************************************/


#define OB_ADJ_CLOSING		ObjectAdjective<LIST<ob_directionEnum, Association::closing, ob_imageEnum, ob_iteratorEnum>, T>

#define OB_ADJ_CLOSED		ObjectAdjective<LIST<ob_directionEnum, Association::closed, ob_imageEnum, ob_iteratorEnum>, T>

#define OB_ADJ_OPENING		ObjectAdjective<LIST<ob_directionEnum, Association::opening, ob_imageEnum, ob_iteratorEnum>, T>

#define OB_ADJ_OPEN		ObjectAdjective<LIST<ob_directionEnum, Association::open, ob_imageEnum, ob_iteratorEnum>, T>


/************************************************************************************************************************/
/************************************************************************************************************************/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum,
	typename T
>
static sub_pointer map(const ADV_SPECIALIZE & ad,

			sub_pointer out, const SUB_ADJ_CLOSING & sub,

			ob_pointer in, ob_pointer end, const OB_ADJ_CLOSING & ob);


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


#include"body/peek_action.hpp"
#include"body/functor_action.hpp"
#include"body/count_action.hpp"
#include"body/iterate_action.hpp"
#include"body/memory_action.hpp"


/***********************************************************************************************************************/


#define ADV_PROTOTYPE													\
		Adverb<LIST<functorEnum, tracerEnum, Connotation::prototype>, F>


/***********************************************************************************************************************/


#define SUB_ADJ_CLOSING_MUTATE_SEGMENT											\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::closing, Association::mutate, Association::segment>	\
		>

#define SUB_ADJ_CLOSING_ALLOCATE_SEGMENT										\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::closing, Association::allocate, Association::segment>	\
		>


/***********************************************************************************************************************/

#define SUB_ADJ_CLOSED_ALLOCATE_SEGMENT											\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::closed, Association::allocate, Association::segment>	\
		>


/***********************************************************************************************************************/


#define SUB_ADJ_OPENING_ALLOCATE_SEGMENT										\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::opening, Association::allocate, Association::segment>	\
		>


/***********************************************************************************************************************/


#define SUB_ADJ_OPEN_ALLOCATE_SEGMENT											\
		SubjectAdjective											\
		<													\
			LIST<sub_directionEnum, Association::open, Association::allocate, Association::segment>	\
		>


/***********************************************************************************************************************/


#define OB_ADJ_CLOSING_IMMUTATE_SEGMENT											\
		ObjectAdjective												\
		<													\
			LIST<ob_directionEnum, Association::closing, Association::immutate, Association::segment>,	\
			T												\
		>

#define OB_ADJ_CLOSING_DEALLOCATE_SEGMENT										\
		ObjectAdjective												\
		<													\
			LIST<ob_directionEnum, Association::closing, Association::deallocate, Association::segment>,	\
			T												\
		>


/***********************************************************************************************************************/


/***********************************************************************************************************************/


/************************************************************************************************************************
							closing
************************************************************************************************************************/


#include"closing/closing.hpp"
#include"closing/closed.hpp"
#include"closing/opening.hpp"
#include"closing/open.hpp"


/************************************************************************************************************************
							closed
************************************************************************************************************************/


#include"closed/closing.hpp"
#include"closed/closed.hpp"
#include"closed/opening.hpp"
#include"closed/open.hpp"


/************************************************************************************************************************
							opening
************************************************************************************************************************/


#include"opening/closing.hpp"
#include"opening/closed.hpp"
#include"opening/opening.hpp"
#include"opening/open.hpp"


/************************************************************************************************************************
							open
************************************************************************************************************************/


#include"open/closing.hpp"
#include"open/closed.hpp"
#include"open/opening.hpp"
#include"open/open.hpp"


