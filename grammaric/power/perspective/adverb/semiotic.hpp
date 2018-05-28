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

template<typename...> struct compare_zero;
template<typename...> struct repeat_set;
template<typename...> struct repeat_digit;
template<typename...> struct repeat_space;

/***********************************************************************************************************************/

	// identity:

template
<
	Interval sub_interval, Direction sub_direction

> struct compare_zero
<
	object<sub_interval, sub_direction>
>
{
	bool value;

	compare_zero() : value(false) { }

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
		value = (*sub == 0); // using a zero::value requires knowing its type.

		return !value;
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
			value = (*sub == 0); // using a zero::value requires knowing its type.
		}
	}
};

	// functor:

template
<
	Interval sub_interval, Direction sub_direction,
	typename ob_type

> struct repeat_set
<
	object<sub_interval, sub_direction>,
	ob_type
>
{
	ob_type value;

	repeat_set(ob_type ob) : value(ob) { }

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
		*sub = value;
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
		*sub = value;
	}
};

	// printer:

template
<
	Interval sub_interval, Direction sub_direction

> struct repeat_digit
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

> struct repeat_space
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

template<typename...> struct compare_equal;
template<typename...> struct compare_not_equal;
template<typename...> struct compare_less_than;
template<typename...> struct compare_less_than_or_equal;
template<typename...> struct compare_greater_than;
template<typename...> struct compare_greater_than_or_equal;
template<typename...> struct map_assign;

/***********************************************************************************************************************/

	// identity:

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct compare_equal
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool value;

	compare_equal() : value(false) { }

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
		value = (*sub == *ob);

		return !value;
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
		value = (*sub == *ob);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct compare_not_equal
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool value;

	compare_not_equal() : value(true) { }

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
		value = (*sub != *ob);

		return value;
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
		value = (*sub != *ob);
	}
};

	// proximity:

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct compare_less_than
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool value;

	compare_less_than() : value(false) { }

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
		value = (*sub < *ob);

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
		value = (*sub < *ob);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct compare_less_than_or_equal
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool value;

	compare_less_than_or_equal() : value(false) { }

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
		value = (*sub < *ob);

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
		value = (*sub <= *ob);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct compare_greater_than
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool value;

	compare_greater_than() : value(false) { }

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
		value = (*sub > *ob);

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
		value = (*sub > *ob);
	}
};

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct compare_greater_than_or_equal
<
	object<sub_interval, sub_direction>,
	object<ob_interval, ob_direction>
>
{
	bool value;

	compare_greater_than_or_equal() : value(false) { }

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
		value = (*sub > *ob);

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
		value = (*sub >= *ob);
	}
};

	// functor:

template
<
	Interval sub_interval, Direction sub_direction,
	Interval ob_interval, Direction ob_direction

> struct map_assign
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

