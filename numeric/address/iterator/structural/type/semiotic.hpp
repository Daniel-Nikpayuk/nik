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
		using parameter_list = L;

		static constexpr size_type direction_enum = AT<L, Modifier::direction>::rtn;
		static constexpr size_type interval_enum = AT<L, Modifier::interval>::rtn;
		static constexpr size_type image_enum = AT<L, Modifier::image>::rtn;
		static constexpr size_type iterator_enum = AT<L, Modifier::iterator>::rtn;
	protected:
		static constexpr size_type iterator_offset = Adjective::template bounds<Modifier::iterator>::initial;
	public:
		using pointer = CASES
		<
			(iterator_enum - iterator_offset),
			segment_pointer<ValueType>,
			hook_pointer<ValueType>,
			link_pointer<ValueType>

		>::rtn;

		typedef ValueType value_type;
	protected:
		typedef void* void_ptr;
	public:
		static void_ptr operator new (size_t n)
			{ return new void_ptr[pointer::dimension]; }
};


/***********************************************************************************************************************/


template<typename T, size_type... params>
using type = Type<T, SORTFILL<Adjective, params...>::rtn>;


