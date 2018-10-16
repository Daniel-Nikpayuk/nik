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
	map_shift_left
	map_shift_right
*/

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective, typename ob1_adjective, typename ob_adjective>
struct map_shift_left
{
	using reg_type = typename byte_type<reg_length>::reg_type;

	//

	reg_type initial_offset;
	reg_type terminal_offset;

	map_shift_left(reg_type io) : initial_offset(io), terminal_offset(reg_length - io) { }

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob1_adjective::first_iteration(ob1);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void main_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		*sub  = *ob1 << initial_offset;
		*sub += *ob >> terminal_offset;
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob1_adjective::main_iteration(ob1);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void last_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			*sub  = *ob1 << initial_offset;
			*sub += *ob >> terminal_offset;
		}
	}
};

/***********************************************************************************************************************/

/*
	We keep ob_type, ob1_type independent for higher entropy:
	They allow for different containers. reg_type is what their dereference type.

	carry needs to be set to 0 for the "normal" interpretation.
*/

template<size_type reg_length, typename sub_adjective, typename ob1_adjective, typename ob_adjective>
struct map_shift_right
{
	using reg_type = typename byte_type<reg_length>::reg_type;

	//

	reg_type initial_offset;
	reg_type terminal_offset;

	map_shift_right(reg_type io) :	initial_offset(io), terminal_offset(reg_length - io) { }

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob1_adjective::first_iteration(ob1);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void main_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		*ob1  = *ob << terminal_offset;
		*sub += *ob >> initial_offset;
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob1_type & ob1, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob1_adjective::main_iteration(ob1);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob1_type, typename ob_type>
	inline void last_action(sub_type sub, ob1_type ob1, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			*ob1  = *ob << terminal_offset;
			*sub += *ob >> initial_offset;
		}
	}
};

