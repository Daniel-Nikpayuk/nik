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
/***********************************************************************************************************************/


/*
	Adjective Attributes:
				TUPLE/LIST data structures are appropriate here because resolution
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

	using Relation = TUPLE
	<
		LIST<Association::forward, Association::backward>,						// direction
		LIST<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
		LIST<Association::mutate, Association::allocate>,						// image
		LIST<Association::segment, Association::hook, Association::link>				// iterator
	>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... params> struct SubjectAdjective { };


#define ALLOCATE_SEGMENT	LIST<directionEnum, intervalEnum, Association::allocate, Association::segment>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L>
struct SubjectAdjective<L>
{
	using parameter_list = L;

	static constexpr size_type direction_enum	= AT<L, SubjectAttribute::direction	>::rtn;
	static constexpr size_type interval_enum	= AT<L, SubjectAttribute::interval	>::rtn;
	static constexpr size_type image_enum		= AT<L, SubjectAttribute::image		>::rtn;
	static constexpr size_type iterator_enum	= AT<L, SubjectAttribute::iterator	>::rtn;

	SubjectAdjective() { }
};


/***********************************************************************************************************************/


template<size_type directionEnum, size_type intervalEnum>
struct SubjectAdjective<ALLOCATE_SEGMENT>
{
	using parameter_list = ALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::allocate;
	static constexpr size_type iterator_enum	= Association::segment;

	size_type length;
	size_type offset;

	SubjectAdjective(size_type l, size_type o = 0) : length(l), offset(o) { }
};


/***********************************************************************************************************************/


#undef ALLOCATE_SEGMENT


/***********************************************************************************************************************/
/***********************************************************************************************************************/
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

	using Relation = TUPLE
	<
		LIST<Association::forward, Association::backward>,						// direction
		LIST<Association::closing, Association::closed, Association::opening, Association::open>,	// interval
		LIST<Association::immutate, Association::deallocate>,						// image
		LIST<Association::segment, Association::hook, Association::link>				// iterator
	>;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... params> struct ObjectAdjective { };


#define DEALLOCATE_SEGMENT	LIST<directionEnum, intervalEnum, Association::deallocate, Association::segment>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L>
struct ObjectAdjective<L>
{
	using parameter_list = L;

	static constexpr size_type direction_enum	= AT<L, ObjectAttribute::direction	>::rtn;
	static constexpr size_type interval_enum	= AT<L, ObjectAttribute::interval	>::rtn;
	static constexpr size_type image_enum		= AT<L, ObjectAttribute::image		>::rtn;
	static constexpr size_type iterator_enum	= AT<L, ObjectAttribute::iterator	>::rtn;

	ObjectAdjective() { }
};


/***********************************************************************************************************************/


template<size_type directionEnum, size_type intervalEnum, typename T>
struct ObjectAdjective<DEALLOCATE_SEGMENT, T>
{
	using parameter_list = DEALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::deallocate;
	static constexpr size_type iterator_enum	= Association::segment;

	T *origin;

	ObjectAdjective(T *o) : origin(o) { }
};


template<size_type directionEnum, size_type intervalEnum>
struct ObjectAdjective<DEALLOCATE_SEGMENT>
{
	using parameter_list = DEALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::deallocate;
	static constexpr size_type iterator_enum	= Association::segment;

//	Type extension:

	template<typename T>
	static ObjectAdjective<parameter_list, T> with(T *o)
	{
		return ObjectAdjective<parameter_list, T>(o);
	}
};


/***********************************************************************************************************************/


#undef DEALLOCATE_SEGMENT


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type... params>
using subject_adjective = SubjectAdjective<SORTFILL<SubjectAttribute, params...>::rtn>;


template<size_type... params>
using object_adjective = ObjectAdjective<SORTFILL<ObjectAttribute, params...>::rtn>;


