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

template<typename Pointer>
class array
{
	public:
		typedef Pointer pointer;
		typedef semiotic::size_type size_type;
		typedef semiotic::value_type value_type;
	protected:
		typedef void* void_ptr;
	public:
		operator pointer () const
			{ return (pointer) this; }

		static void_ptr operator new (size_t n)
			{ return new value_type; }
};

using segment_pointer = semiotic::value_type*;

using const_segment_pointer = semiotic::value_type const *;

using segment = array<segment_pointer>;

using const_segment = array<const_segment_pointer>;

