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


template<typename ValueType, typename L>
class Type
{
	public:
		static constexpr size_type functor_enum = at<L, Mod::functor>::rtn;
		static constexpr size_type tracer_enum = at<L, Mod::tracer>::rtn;
		static constexpr size_type optimizer_enum = at<L, Mod::optimizer>::rtn;
	public:
		typedef ValueType value_type;
};


/***********************************************************************************************************************/


template<typename T, size_type... params>
using type = Type<T, sortFill<ModOptimizer, params...> >;


