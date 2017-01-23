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


template<Association... params>
using adj_list = typename parameter<Association>::template list<params...>;

using null_adj = adj_list<>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


// should be false.

template<typename... params>
struct Adjective { static_assert(true, "this variant is not implemented."); };


/************************************************************************************************************************
							1
************************************************************************************************************************/


template<typename A>
struct Adjective< adj_list<Association::accede>, A>
{
	A accessor;

	Adjective(const A & a) : accessor(a) { }
};


/************************************************************************************************************************
							2
************************************************************************************************************************/


/************************************************************************************************************************
							3
************************************************************************************************************************/


template<Association directionEnum, Association intervalEnum, typename A>
struct Adjective< adj_list<Association::accede, directionEnum, intervalEnum>, A> :

		public Adjective< null_adj >,
		public Adjective< adj_list<Association::accede>, A>
{
/*
	using parameter_list = adj_list<Association::accede, directionEnum, intervalEnum>;

	static constexpr Association increment_enum	= Association::accede;
	static constexpr Association direction_enum	= directionEnum;
	static constexpr Association interval_enum	= intervalEnum;
*/

	Adjective(const A & a) :

		Adjective< adj_list<Association::accede>, A>(a) { }
};


template<Association directionEnum, Association intervalEnum>
struct Adjective< adj_list<Association::succeed, directionEnum, intervalEnum>, void> :

		public Adjective< null_adj >,
		public Adjective< adj_list<Association::succeed, directionEnum> >
{
/*
	using parameter_list = adj_list<Association::succeed, directionEnum, intervalEnum>;

	static constexpr Association increment_enum	= Association::succeed;
	static constexpr Association direction_enum	= directionEnum;
	static constexpr Association interval_enum	= intervalEnum;
*/

//	Type coersion:

	template<typename A>
	static Adjective< adj_list<Association::accede, directionEnum, intervalEnum>, A> with(const A & a)
	{
		return Adjective< adj_list<Association::accede, directionEnum, intervalEnum>, A>(a);
	}
};


