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

template<Attribute i>
using enum_cast = typename variadic<Orientation::functional, Interface::semiotic>::template enum_cast<AttributeList, i>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	default: !segment
*/


template<typename L, typename Filler = void> struct PeekAdjective { };

template<typename Filler> struct PeekAdjective<adj_list<Association::segment>, Filler> { };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<Association directionEnum, Association intervalEnum>
using ALLOCATE_SEGMENT = adj_list<directionEnum, intervalEnum, Association::allocate, Association::segment>;

template<Association directionEnum, Association intervalEnum>
using DEALLOCATE_SEGMENT = adj_list<directionEnum, intervalEnum, Association::deallocate, Association::segment>;


/***********************************************************************************************************************/


template<typename... params>
struct Adjective { static_assert(true, "this variant is not implemented."); };


/***********************************************************************************************************************/


template<Association directionEnum, Association intervalEnum>
struct Adjective<ALLOCATE_SEGMENT<directionEnum, intervalEnum> > :
									public PeekAdjective< adj_list<Association::segment> >
{
	using parameter_list = ALLOCATE_SEGMENT<directionEnum, intervalEnum>;

	static constexpr Association direction_enum	= directionEnum;
	static constexpr Association interval_enum	= intervalEnum;
	static constexpr Association image_enum		= Association::allocate;
	static constexpr Association iterator_enum	= Association::segment;

	size_type length;
	size_type offset;

	Adjective(size_type l, size_type o = 0) : length(l), offset(o) { }
};


template<Association directionEnum, Association intervalEnum, typename T>
struct Adjective<DEALLOCATE_SEGMENT<directionEnum, intervalEnum>, T> :
									public PeekAdjective< adj_list<Association::segment> >
{
	using parameter_list = DEALLOCATE_SEGMENT<directionEnum, intervalEnum>;

	static constexpr Association direction_enum	= directionEnum;
	static constexpr Association interval_enum	= intervalEnum;
	static constexpr Association image_enum		= Association::deallocate;
	static constexpr Association iterator_enum	= Association::segment;

	T *origin;

	Adjective(T *o) : origin(o) { }
};


template<typename L>
struct Adjective<L> :
			public PeekAdjective< adj_list< at<L, enum_cast<Attribute::iterator>::rtn >::rtn >>
{
	using parameter_list = L;

	static constexpr Association direction_enum	= at<L, enum_cast<Attribute::direction	>::rtn	>::rtn;
	static constexpr Association interval_enum	= at<L, enum_cast<Attribute::interval	>::rtn	>::rtn;
	static constexpr Association image_enum		= at<L, enum_cast<Attribute::image	>::rtn	>::rtn;
	static constexpr Association iterator_enum	= at<L, enum_cast<Attribute::iterator	>::rtn	>::rtn;

	Adjective() { }

//	Type coersion:

	static Adjective<ALLOCATE_SEGMENT<direction_enum, interval_enum> > with(size_type l, size_type o = 0)
	{
		return Adjective<ALLOCATE_SEGMENT<direction_enum, interval_enum> >(l, o);
	}

	template<typename T>
	static Adjective<DEALLOCATE_SEGMENT<direction_enum, interval_enum>, T> with(T *o)
	{
		return Adjective<DEALLOCATE_SEGMENT<direction_enum, interval_enum>, T>(o);
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


