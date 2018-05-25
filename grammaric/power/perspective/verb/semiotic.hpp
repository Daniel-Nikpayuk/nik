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

	// identity:

struct identity_zero_verb
{
	bool rtn;

	identity_zero_verb() : rtn(false) { }

	template<typename sub_type>
	inline bool break_match(sub_type sub)
	{
		rtn = (*sub == 0); // using a zero::value requires knowing its type.

		return !rtn;
	}

	template<typename sub_type>
	inline void last_match(sub_type sub)
	{
		rtn = (*sub == 0); // using a zero::value requires knowing its type.
	}
};

	// proximity:

struct proximity_less_than_verb
{
	bool rtn;

	proximity_less_than_verb() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub < *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub < *ob);
	}
};

struct proximity_less_than_or_equal_verb
{
	bool rtn;

	proximity_less_than_or_equal_verb() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub < *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub <= *ob);
	}
};

struct proximity_greater_than_verb
{
	bool rtn;

	proximity_greater_than_verb() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub > *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub > *ob);
	}
};

struct proximity_greater_than_or_equal_verb
{
	bool rtn;

	proximity_greater_than_or_equal_verb() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub > *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub >= *ob);
	}
};

	// functor:

template<typename ob_type>
struct functor_set_verb
{
	ob_type ob;

	functor_set_verb(ob_type o) : ob(o) { }

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		*sub = ob;
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		*sub = ob;
	}
};

struct functor_assign_verb
{
	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		*sub = *ob;
	}

	template<typename sub_type, typename ob_type>
	inline void last_action(sub_type sub, ob_type ob)
	{
		*sub = *ob;
	}
};

	// printer:

struct printer_digit_verb
{
	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		builtin_printer::print(*sub);
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		builtin_printer::print(*sub);
		builtin_printer::print('\n');
	}
};

struct printer_space_verb
{
	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		builtin_printer::print(*sub);
		builtin_printer::print(' ');
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		builtin_printer::print(*sub);
		builtin_printer::print('\n');
	}
};

