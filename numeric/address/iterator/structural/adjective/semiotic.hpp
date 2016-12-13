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


// Adjective Associations:


struct Association
{
	enum : size_type
	{
		forward,
		backward,

		closing,
		closed,
		opening,
		open,

		mutate,
		allocate,

		immutate,
		deallocate,

		segment,
		hook,
		link,

		dimension
	};
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Adjective Attributes:
				LIST data structures are appropriate here because resolution
				occurs during compile-time and the size is expected to be small.
*/


struct SubjectAttribute
{
	enum : size_type
	{
		direction,
		interval,
		image,
		iterator,

		dimension
	};

	using Relation = LIST
	<
		LIST<Association::forward, Association::backward>,						// direction
		LIST<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
		LIST<Association::mutate, Association::allocate>,						// image
		LIST<Association::segment, Association::hook, Association::link>				// iterator
	>;
};


/***********************************************************************************************************************/


struct ObjectAttribute
{
	enum : size_type
	{
		direction,
		interval,
		image,
		iterator,

		dimension
	};

	using Relation = LIST
	<
		LIST<Association::forward, Association::backward>,						// direction
		LIST<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
		LIST<Association::immutate, Association::deallocate>,						// image
		LIST<Association::segment, Association::hook, Association::link>				// iterator
	>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... params> struct Adjective { };


#define ALLOCATE_SEGMENT	LIST<directionEnum, intervalEnum, Association::allocate, Association::segment>
#define DEALLOCATE_SEGMENT	LIST<directionEnum, intervalEnum, Association::deallocate, Association::segment>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L, typename AttributeType>
struct Adjective<L, AttributeType>
{
	using parameter_list = L;

	static constexpr size_type direction_enum	= AT<L, AttributeType::direction	>::rtn;
	static constexpr size_type interval_enum	= AT<L, AttributeType::interval		>::rtn;
	static constexpr size_type image_enum		= AT<L, AttributeType::image		>::rtn;
	static constexpr size_type iterator_enum	= AT<L, AttributeType::iterator		>::rtn;

	Adjective() { }
};


/***********************************************************************************************************************/


template<size_type directionEnum, size_type intervalEnum, typename AttributeType>
struct Adjective<ALLOCATE_SEGMENT, AttributeType>
{
	using parameter_list = ALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::allocate;
	static constexpr size_type iterator_enum	= Association::segment;

	size_type length;
	size_type offset;

	Adjective(size_type l, size_type o = 0) : length(l), offset(o) { }
};


/***********************************************************************************************************************/


template<size_type directionEnum, size_type intervalEnum, typename T, typename AttributeType>
struct Adjective<DEALLOCATE_SEGMENT, T, AttributeType>
{
	using parameter_list = DEALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::deallocate;
	static constexpr size_type iterator_enum	= Association::segment;

	T *origin;

	Adjective(T *o) : origin(o) { }
};


template<size_type directionEnum, size_type intervalEnum, typename AttributeType>
struct Adjective<DEALLOCATE_SEGMENT, AttributeType>
{
	using parameter_list = DEALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::deallocate;
	static constexpr size_type iterator_enum	= Association::segment;

	template<typename T>
	static Adjective<parameter_list, T, AttributeType> with(T *o)
	{
		return Adjective<parameter_list, T, AttributeType>(o);
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L> struct SubjectAdjective : public Adjective<L, SubjectAttribute> { };


template<typename L> struct ObjectAdjective : public Adjective<L, ObjectAttribute> { };


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type... params>
using subject_adjective = SubjectAdjective<SORTFILL<SubjectAttribute, params...>::rtn>;


template<size_type... params>
using object_adjective = ObjectAdjective<SORTFILL<ObjectAttribute, params...>::rtn>;


