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


// Adjective Attributes:


using SubjectAttribute = LIST
<
	direction,	LIST<forward, backward>,
	interval,	LIST<closing, closed, opening, open>,
	image,		LIST<mutate, allocate>,
	iterator,	LIST<segment, hook, link>
>;


using ObjectAttribute = LIST
<
	direction,	LIST<forward, backward>,
	interval,	LIST<closing, closed, opening, open>,
	image,		LIST<immutate, deallocate>,
	iterator,	LIST<segment, hook, link>
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename... params> struct _adjective { };


#define ALLOCATE_SEGMENT	LIST<directionEnum, intervalEnum, Association::allocate, Association::segment>
#define DEALLOCATE_SEGMENT	LIST<directionEnum, intervalEnum, Association::deallocate, Association::segment>


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename L>
struct _adjective<L>
{
	using parameter_list = L;

	static constexpr size_type direction_enum	= AT<L, Attribute::direction	>::rtn;
	static constexpr size_type interval_enum	= AT<L, Attribute::interval	>::rtn;
	static constexpr size_type image_enum		= AT<L, Attribute::image	>::rtn;
	static constexpr size_type iterator_enum	= AT<L, Attribute::iterator	>::rtn;

	_adjective() { }
};


/***********************************************************************************************************************/


template<size_type directionEnum, size_type intervalEnum>
struct _adjective<ALLOCATE_SEGMENT>
{
	using parameter_list = ALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::allocate;
	static constexpr size_type iterator_enum	= Association::segment;

	size_type length;
	size_type offset;

	_adjective(size_type l, size_type o = 0) : length(l), offset(o) { }
};


/***********************************************************************************************************************/


template<size_type directionEnum, size_type intervalEnum, typename T>
struct _adjective<DEALLOCATE_SEGMENT, T>
{
	using parameter_list = DEALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::deallocate;
	static constexpr size_type iterator_enum	= Association::segment;

	T *origin;

	_adjective(T *o) : origin(o) { }
};

template<size_type directionEnum, size_type intervalEnum>
struct _adjective<DEALLOCATE_SEGMENT>
{
	using parameter_list = DEALLOCATE_SEGMENT;

	static constexpr size_type direction_enum	= directionEnum;
	static constexpr size_type interval_enum	= intervalEnum;
	static constexpr size_type image_enum		= Association::deallocate;
	static constexpr size_type iterator_enum	= Association::segment;

	template<typename T>
	static _adjective<parameter_list, T> with(T *o)
	{
		return _adjective<parameter_list, T>(o);
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type... params>
using adjective = _adjective<SORTFILL<Association, params...>::rtn>;


