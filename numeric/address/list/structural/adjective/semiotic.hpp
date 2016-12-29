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
*/


struct Attribute
{
	enum : size_type
	{
		direction,
		interval,
		image,
		iterator,

		dimension
	};
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... params> struct Adjective { };


#define ALLOCATE_SEGMENT		LIST<directionEnum, intervalEnum, Association::allocate, Association::segment>
#define ALLOCATE_SEGMENT_INTERVAL	LIST<direction_enum, interval_enum, Association::allocate, Association::segment>

#define DEALLOCATE_SEGMENT		LIST<directionEnum, intervalEnum, Association::deallocate, Association::segment>
#define DEALLOCATE_SEGMENT_INTERVAL	LIST<direction_enum, interval_enum, Association::deallocate, Association::segment>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type directionEnum, size_type intervalEnum>
struct Adjective<ALLOCATE_SEGMENT>
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


template<size_type directionEnum, size_type intervalEnum, typename T>
struct Adjective<DEALLOCATE_SEGMENT, T>
{
	using parameter_list = DEALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::deallocate;
	static constexpr size_type iterator_enum	= Association::segment;

	T *origin;

	Adjective(T *o) : origin(o) { }
};


template<typename L>
struct Adjective<L>
{
	using parameter_list = L;

	static constexpr size_type direction_enum	= AT<L, Attribute::direction	>::rtn;
	static constexpr size_type interval_enum	= AT<L, Attribute::interval	>::rtn;
	static constexpr size_type image_enum		= AT<L, Attribute::image	>::rtn;
	static constexpr size_type iterator_enum	= AT<L, Attribute::iterator	>::rtn;

	Adjective() { }

//	Type coersion:

	static Adjective<ALLOCATE_SEGMENT_INTERVAL> with(size_type l, size_type o = 0)
	{
		return Adjective<ALLOCATE_SEGMENT_INTERVAL>(l, o);
	}

	template<typename T>
	static Adjective<DEALLOCATE_SEGMENT_INTERVAL, T> with(T *o)
	{
		return Adjective<DEALLOCATE_SEGMENT_INTERVAL, T>(o);
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


#undef ALLOCATE_SEGMENT
#undef ALLOCATE_SEGMENT_INTERVAL

#undef DEALLOCATE_SEGMENT_INTERVAL
#undef DEALLOCATE_SEGMENT


