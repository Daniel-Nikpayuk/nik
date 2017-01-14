/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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


/*
	Adjective Associations:

				Strongly typed for improved type checking.

				Parameter pack being "typename..." requires adj_lists
				as enums themselves don't count as typenames.
*/


enum struct Association : size_type
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


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Adjective Attributes:

				Weakly typed as it makes location specification easier and does not interfere with
				type checking in practice.
*/


enum struct Attribute : size_type
{
	direction,
	interval,
	image,
	iterator,

	dimension
};


using AttributeList = typename parameter<Attribute>::template list
<
	Attribute::direction,
	Attribute::interval,
	Attribute::image,
	Attribute::iterator
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<Association... params>
using adj_list = typename parameter<Association>::template list<params...>;

using null_list = adj_list<>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/

// should be false.

template<typename... params>
struct Adjective { static_assert(true, "this variant is not implemented."); };


/************************************************************************************************************************
							1
***********************************************************************************************************************/


template<typename EnumStruct>
struct Adjective<typename parameter<Association>::template list<EnumStruct::null>> { };

template<typename EnumStruct>
struct Adjective<typename parameter<Association>::template list<EnumStruct::deallocate>> { };

template<typename EnumStruct>
struct Adjective<typename parameter<Association>::template list<EnumStruct::segment>> { };


/************************************************************************************************************************
							2
***********************************************************************************************************************/


template<typename T>
struct Adjective< adj_list<Association::deallocate, Association::segment>, T>
{
	T *origin;

	Adjective(T *o) : origin(o) { }
};


/************************************************************************************************************************
							3
***********************************************************************************************************************/


template<Association directionEnum>
struct Adjective< adj_list<directionEnum, Association::allocate, Association::segment> >
{
	size_type length;
	size_type offset;

	Adjective(size_type l, size_type o) : length(l), offset(o) { }
};


/************************************************************************************************************************
							4
***********************************************************************************************************************/


template<Association directionEnum, Association intervalEnum>
using ALLOCATE_SEGMENT = adj_list<directionEnum, intervalEnum, Association::allocate, Association::segment>;

template<Association directionEnum, Association intervalEnum>
using DEALLOCATE_SEGMENT = adj_list<directionEnum, intervalEnum, Association::deallocate, Association::segment>;


/***********************************************************************************************************************/


template<Association directionEnum, Association intervalEnum>
struct Adjective<ALLOCATE_SEGMENT<directionEnum, intervalEnum> > :

		public Adjective< adj_list<directionEnum, Association::allocate, Association::segment> >
{
	using parameter_list = ALLOCATE_SEGMENT<directionEnum, intervalEnum>;

	static constexpr Association direction_enum	= directionEnum;
	static constexpr Association interval_enum	= intervalEnum;
	static constexpr Association image_enum		= Association::allocate;
	static constexpr Association iterator_enum	= Association::segment;

	Adjective(size_type l, size_type o = 0) :

		Adjective< adj_list<directionEnum, Association::allocate, Association::segment> >(l, o) { }
};


template<Association directionEnum, Association intervalEnum, typename T>
struct Adjective<DEALLOCATE_SEGMENT<directionEnum, intervalEnum>, T> :

		public Adjective< adj_list<Association::deallocate, Association::segment>, T>
{
	using parameter_list = DEALLOCATE_SEGMENT<directionEnum, intervalEnum>;

	static constexpr Association direction_enum	= directionEnum;
	static constexpr Association interval_enum	= intervalEnum;
	static constexpr Association image_enum		= Association::deallocate;
	static constexpr Association iterator_enum	= Association::segment;

	Adjective(T *o) : Adjective< adj_list<Association::deallocate, Association::segment>, T>(o) { }
};


template<Association directionEnum, Association intervalEnum, Association imageEnum, Association iteratorEnum>
struct Adjective< adj_list<directionEnum, intervalEnum, imageEnum, iteratorEnum>, void> :

		public Adjective<null_list>
//		public Adjective< adj_list<Association::deallocate> >,
//		public Adjective< adj_list<iteratorEnum> >
{
	using parameter_list = adj_list<directionEnum, intervalEnum, imageEnum, iteratorEnum>;

	static constexpr Association direction_enum	= directionEnum;
	static constexpr Association interval_enum	= intervalEnum;
	static constexpr Association image_enum		= imageEnum;
	static constexpr Association iterator_enum	= iteratorEnum;

	Adjective() { }

//	Type coersion:

	static Adjective<ALLOCATE_SEGMENT<directionEnum, intervalEnum> > with(size_type l, size_type o = 0)
	{
		return Adjective<ALLOCATE_SEGMENT<directionEnum, intervalEnum> >(l, o);
	}

	template<typename T>
	static Adjective<DEALLOCATE_SEGMENT<directionEnum, intervalEnum>, T> with(T *o)
	{
		return Adjective<DEALLOCATE_SEGMENT<directionEnum, intervalEnum>, T>(o);
	}
};


