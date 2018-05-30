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
	unary:

	compare_zero
	map_set
	map_print
*/

/***********************************************************************************************************************/

	// identity:

template<typename sub_adjective>
struct compare_zero
{
	bool value;

	compare_zero() : value(false) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		sub_adjective::first_iteration(sub);
	}

	template<typename sub_type>
	inline bool break_match(sub_type sub)
	{
		value = (*sub == 0); // using a zero::value requires knowing its type.

		return !value;
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		sub_adjective::main_iteration(sub);
	}

	template<typename sub_type>
	inline void last_match(sub_type sub)
	{
		if (sub_adjective::is_terminal_closed::value)
		{
			value = (*sub == 0); // using a zero::value requires knowing the dereference type.
		}
	}
};

	// functor:

template<typename sub_adjective, typename Type>
struct map_set
{
	using value_type = Type;

	value_type value;

	map_set(value_type v) : value(v) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		sub_adjective::first_iteration(sub);
	}

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		*sub = value;
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		sub_adjective::main_iteration(sub);
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		if (sub_adjective::is_terminal_closed::value)
		{
			*sub = value;
		}
	}
};

	// printer:

template<typename...> struct map_print;

template<typename sub_adjective>
struct map_print<sub_adjective>
{
	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		sub_adjective::first_iteration(sub);
	}

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		builtin_printer::print(*sub);
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		sub_adjective::main_iteration(sub);
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		if (sub_adjective::is_terminal_closed::value)
		{
			builtin_printer::print(*sub);
		}
	}
};

template<typename sub_adjective, typename Type>
struct map_print<sub_adjective, Type>
{
	using separator_type = Type;

	separator_type separator;

	map_print(const separator_type & s) : separator(s) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		sub_adjective::first_iteration(sub);
	}

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		builtin_printer::print(*sub);
		builtin_printer::print(separator);
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		sub_adjective::main_iteration(sub);
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		if (sub_adjective::is_terminal_closed::value)
		{
			builtin_printer::print(*sub);
		}
	}
};

/***********************************************************************************************************************/

/*
	binary:

	compare_equal
	compare_not_equal
	compare_less_than
	compare_less_than_or_equal
	compare_greater_than
	compare_greater_than_or_equal
	map_assign
*/

/***********************************************************************************************************************/

	// identity:

template<typename sub_adjective, typename ob_adjective>
struct compare_equal
{
	bool value;

	compare_equal() : value(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		value = (*sub == *ob);

		return !value;
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			value = (*sub == *ob);
		}
	}
};

template<typename sub_adjective, typename ob_adjective>
struct compare_not_equal
{
	bool value;

	compare_not_equal() : value(true) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		value = (*sub != *ob);

		return value;
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			value = (*sub != *ob);
		}
	}
};

	// proximity:

template<typename sub_adjective, typename ob_adjective>
struct compare_less_than
{
	bool value;

	compare_less_than() : value(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		value = (*sub < *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			value = (*sub < *ob);
		}
	}
};

template<typename sub_adjective, typename ob_adjective>
struct compare_less_than_or_equal
{
	bool value;

	compare_less_than_or_equal() : value(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		value = (*sub < *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			value = (*sub <= *ob);
		}
	}
};

template<typename sub_adjective, typename ob_adjective>
struct compare_greater_than
{
	bool value;

	compare_greater_than() : value(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		value = (*sub > *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			value = (*sub > *ob);
		}
	}
};

template<typename sub_adjective, typename ob_adjective>
struct compare_greater_than_or_equal
{
	bool value;

	compare_greater_than_or_equal() : value(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		value = (*sub > *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			value = (*sub >= *ob);
		}
	}
};

	// functor:

template<typename sub_adjective, typename ob_adjective>
struct map_assign
{
	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::first_iteration(sub);
		ob_adjective::first_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		*sub = *ob;
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		sub_adjective::main_iteration(sub);
		ob_adjective::main_iteration(ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_action(sub_type sub, ob_type ob)
	{
		if (ob_adjective::is_terminal_closed::value)
		{
			*sub = *ob;
		}
	}
};

