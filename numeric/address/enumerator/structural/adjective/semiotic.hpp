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
	succeed,
	accede,

	forward,
	backward,

	closing,
	closed,
	opening,
	open,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


/*
	Adjective Attributes:
				TUPLE/LIST data structures are appropriate here because resolution
				occurs during compile-time and the size is expected to be small.
*/


enum struct Attribute : size_type
{
	increment,

	direction,
	interval,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


using bitmask = typename bit::template bitmask<Association>;

template<Association... params>
using list_cast = typename bitmask::template list_cast<params...>;

template<size_type mask>
using pattern = typename bitmask::template pattern<mask>;

template<size_type mask, typename... params>
using match = typename pattern<mask>::template match<params...>;

template<size_type mask, typename S>
using tail = typename pattern<mask>::template tail<S::bitmask>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


struct Succeed
{
	static constexpr size_type bitmask = list_cast
	<
		Association::succeed

	>::rtn;
};


struct Accede
{
	static constexpr size_type bitmask = list_cast
	<
		Association::accede

	>::rtn;
};


struct Closing
{
	static constexpr size_type bitmask = list_cast
	<
		Association::closing

	>::rtn;
};

struct Closed
{
	static constexpr size_type bitmask = list_cast
	<
		Association::closed

	>::rtn;
};

struct Opening
{
	static constexpr size_type bitmask = list_cast
	<
		Association::opening

	>::rtn;
};

struct Open
{
	static constexpr size_type bitmask = list_cast
	<
		Association::open

	>::rtn;
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename... params> struct Adjective;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<size_type mask>
struct Adjective<mask, Succeed>
{
	static constexpr size_type bitmask = Succeed::bitmask;

	static constexpr size_type accede_mask = mask | Accede::bitmask;

	using Interval = typename match<mask, Closing, Closed, Opening, Open>::rtn;

	template<typename A>
	static Adjective<accede_mask, Interval, A> cast(const A & a)
	{
		return Adjective<accede_mask, Interval, A>(a);
	}
};


template<size_type mask, typename A>
struct Adjective<mask, Accede, A>
{
	static constexpr size_type bitmask = Accede::bitmask;

	A accessor;

	Adjective(const A & a) : accessor(a) { }
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


/************************************************************************************************************************
							3
************************************************************************************************************************/


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename S>
using Adjective_Tail = Adjective< tail<mask, S>::rtn, S>;

template<size_type mask, typename S, typename A>
using Adjective_Tail_A = Adjective< tail<mask, S>::rtn, S, A>;

template<size_type mask, typename A>
using match_accede = typename match
<
	mask,

	Adjective_Tail_A<mask, Accede, A>

>::rtn;

template<size_type mask>
using match_increment = typename match
<
	mask,

	Adjective_Tail<mask, Succeed>

>::rtn;

template<size_type mask>
using match_interval = typename match
<
	mask,

	Adjective<mask, Closing>,
	Adjective<mask, Closed>,
	Adjective<mask, Opening>,
	Adjective<mask, Open>

>::rtn;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<size_type mask, typename Interval>
struct Adjective<mask, Interval> : public match_increment<mask>
{
	static constexpr size_type bitmask = Interval::bitmask;
};

template<size_type mask, typename Interval, typename A>
struct Adjective<mask, Interval, A> : public match_accede<mask, A>
{
	static constexpr size_type bitmask = Interval::bitmask;

	Adjective(const A & a) : match_accede<mask, A>(a) { }
};


/***********************************************************************************************************************/


template<size_type mask>
struct Adjective<mask> : public match_interval<mask> { };


