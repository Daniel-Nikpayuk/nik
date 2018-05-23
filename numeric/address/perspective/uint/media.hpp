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
*/

template<size_type length>
struct uint
{
	using type			= uint;
	using type_ref			= type&;
	using type_ptr			= type*;

	using value_type		= power<size_type, length>;
	using value_type_ref		= value_type&;
	using value_type_ptr		= value_type*;

	using iterator			= typename power<size_type, length>::iterator;
	using const_iterator		= typename power<size_type, length>::const_iterator;

	//

	using policy		= object
				<
					Interval::closing,
					Direction::forward
				>;

	using method		= functor
				<
					policy,
					policy
				>;

	//

	value_type value;

	address() { }
	
	address(const type & w)
	{
		method::assign(value.begin(), w.begin(), w.end());
	}

	~address() { }

	void print()
	{
		Word::division::half();
	}
};

