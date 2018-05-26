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
*/

template<typename...> struct identity_zero;
template<typename...> struct functor_set;
template<typename...> struct printer_digit;
template<typename...> struct printer_space;

/***********************************************************************************************************************/

	// identity:

template
<
	Interval sub_interval, Direction sub_direction

> struct identity_zero
<
	object<sub_interval, sub_direction>
>
{
	bool rtn;

	identity_zero() : rtn(false) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}
	}

	template<typename sub_type>
	inline bool break_match(sub_type sub)
	{
		rtn = (*sub == 0); // using a zero::value requires knowing its type.

		return !rtn;
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;
	}

	template<typename sub_type>
	inline void last_match(sub_type sub)
	{
		if (sub_interval == Interval::closed || sub_interval == Interval::opening)
		{
			rtn = (*sub == 0); // using a zero::value requires knowing its type.
		}
	}
};

	// functor:

template
<
	Interval sub_interval, Direction sub_direction,
	typename ob_type

> struct functor_set
<
	object<sub_interval, sub_direction>,
	ob_type
>
{
	ob_type ob;

	functor_set(ob_type o) : ob(o) { }

	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}
	}

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		*sub = ob;
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		*sub = ob;
	}
};

	// printer:

template
<
	Interval sub_interval, Direction sub_direction

> struct printer_digit
<
	object<sub_interval, sub_direction>
>
{
	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}
	}

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		builtin_printer::print(*sub);
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		builtin_printer::print(*sub);
		builtin_printer::print('\n');
	}
};

template
<
	Interval sub_interval, Direction sub_direction

> struct printer_space
<
	object<sub_interval, sub_direction>
>
{
	template<typename sub_type>
	inline void first_iteration(sub_type & sub)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}
	}

	template<typename sub_type>
	inline void main_action(sub_type sub)
	{
		builtin_printer::print(*sub);
		builtin_printer::print(' ');
	}

	template<typename sub_type>
	inline void main_iteration(sub_type & sub)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;
	}

	template<typename sub_type>
	inline void last_action(sub_type sub)
	{
		builtin_printer::print(*sub);
		builtin_printer::print('\n');
	}
};

/***********************************************************************************************************************/

/*
	binary:
*/

template<typename...> struct proximity_less_than;
template<typename...> struct proximity_less_than_or_equal;
template<typename...> struct proximity_greater_than;
template<typename...> struct proximity_greater_than_or_equal;
template<typename...> struct functor_assign;
template<typename...> struct identity_equal;
template<typename...> struct identity_not_equal;

/***********************************************************************************************************************/

	// identity:

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct identity_equal
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool rtn;

	identity_equal() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub == *ob);

		return !rtn;
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub == *ob);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct identity_not_equal
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool rtn;

	identity_not_equal() : rtn(true) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub != *ob);

		return rtn;
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub != *ob);
	}
};

	// proximity:

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct proximity_less_than
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool rtn;

	proximity_less_than() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub < *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub < *ob);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct proximity_less_than_or_equal
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool rtn;

	proximity_less_than_or_equal() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub < *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub <= *ob);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct proximity_greater_than
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool rtn;

	proximity_greater_than() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub > *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub > *ob);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct proximity_greater_than_or_equal
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool rtn;

	proximity_greater_than_or_equal() : rtn(false) { }

	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
	}

	template<typename sub_type, typename ob_type>
	inline bool break_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub > *ob);

		return (*sub != *ob);
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	template<typename sub_type, typename ob_type>
	inline void last_match(sub_type sub, ob_type ob)
	{
		rtn = (*sub >= *ob);
	}
};

	// functor:

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct functor_assign
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	template<typename sub_type, typename ob_type>
	inline void first_iteration(sub_type & sub, ob_type & ob)
	{
		if (sub_interval == Interval::opening || sub_interval == Interval::open)
		{
			if	(sub_direction == Direction::forward)	++sub;
			else if	(sub_direction == Direction::backward)	--sub;
		}

		if (ob_interval == Interval::opening || ob_interval == Interval::open)
		{
			if	(ob_direction == Direction::forward)	++ob;
			else if	(ob_direction == Direction::backward)	--ob;
		}
	}

	template<typename sub_type, typename ob_type>
	inline void main_action(sub_type sub, ob_type ob)
	{
		*sub = *ob;
	}

	template<typename sub_type, typename ob_type>
	inline void main_iteration(sub_type & sub, ob_type & ob)
	{
		if	(sub_direction == Direction::forward)	++sub;
		else if	(sub_direction == Direction::backward)	--sub;

		if	(ob_direction == Direction::forward)	++ob;
		else if	(ob_direction == Direction::backward)	--ob;
	}

	template<typename sub_type, typename ob_type>
	inline void last_action(sub_type sub, ob_type ob)
	{
		*sub = *ob;
	}
};

