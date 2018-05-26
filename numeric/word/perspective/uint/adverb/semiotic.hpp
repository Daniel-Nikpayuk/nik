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

template<size_type, typename...> struct uint_change_of_base;

/*
*/

template
<
	size_type length,
	Interval sub_interval, Direction sub_direction

> struct uint_change_of_base
<
	length,
	object<sub_interval, sub_direction>
>
{
	using reg_type = typename byte_type<length>::reg_type;

	reg_type q;
	reg_type d;

	uint_change_of_base(reg_type od) : d(od) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub, reg_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		// ob_type is reg_type.
	}

	template<typename sub_type>
	inline void main_action(sub_type sub, reg_type ob)
	{
		   q = ob / d;
		*sub = ob % d;
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub, reg_type & ob)
	{
		++sub;
		ob = q;
	}

	template<typename sub_type>
	inline void last_action(sub_type sub, reg_type ob)
	{
	}
};
