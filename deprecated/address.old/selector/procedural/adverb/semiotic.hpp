/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Connotations and Manners of "{omit, apply} functor" are implicit in the build and it is tempting to minimize,
	but 1) This is bad design because I would be relying on an implementation feature to enforce specification design,
	2) Without explicitly specifying them, the compiler cannot distinguish the partial specializations below.
*/


enum struct Connotation : size_type
{
	after,
	before,
	between,

	append,
	prepend,
	impend,

	reject,
	deject,
	eject,

	dimension
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


enum struct Manner : size_type
{
	fixer,
	pender,
	jector,

	dimension
};


using MannerList = typename parameter<Manner>::template list
<
	Manner::fixer,
	Manner::pender,
	Manner::jector
>;


/***********************************************************************************************************************/
/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<Connotation... params>
using adv_list = typename parameter<Connotation>::template list<params...>;

template<Manner i>
using enum_cast = typename variadic<Orientation::functional, Interface::semiotic>::template enum_cast<MannerList, i>;


/***********************************************************************************************************************/

template<typename L>
struct Adverb
{
	using parameter_list = L;

	static constexpr size_type fixer_enum	= at<L, enum_cast<Manner::fixer>::rtn	>::rtn;
	static constexpr size_type pender_enum	= at<L, enum_cast<Manner::pender>::rtn	>::rtn;
	static constexpr size_type jector_enum	= at<L, enum_cast<Manner::jector>::rtn	>::rtn;

	Adverb() { }
};


