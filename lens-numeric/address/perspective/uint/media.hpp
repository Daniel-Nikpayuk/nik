/************************************************************************************************************************
**
** Copyright 2015-2020 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

	using adjective		= object
				<
					Interval::closing,
					Direction::forward
				>;

	using binary		= typename Power::template functor
				<
					adjective,
					adjective
				>;

	//

	value_type value;

	uint() { }
	
	uint(const type & w)
	{
		binary::assign(value.begin(), w.begin(), w.end());
	}

	~uint() { }

	void print()
	{
/*
	Concept:

	The number of digits required for the numeral character array.

	log(2^64N) == 64N*lg(2)/lg(10) == 64N/(1+lg(5)) < 20N

	unsigned char digits[20*N];
*/
	}
};

