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

	using binary		= typename Power::template functor
				<
					policy,
					policy
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
		unsigned char digits[20*N];
		unsigned char *i = digits;

		reg_type r;
		reg_type d = 10;
		reg_type tmp0[N];
		reg_type tmp1[N];

		functor::assign(tmp0 + N, sub, end);

		while (!identity::zero(tmp1 + N, tmp1))
		{
			r = 0;
			division::divide(r, tmp1 + N, tmp0 + N, tmp0, d);
			*i = (unsigned char) r;

			functor::assign(tmp0 + N, tmp1 + N, tmp1);
			++i;
		}
*/
	}
};

