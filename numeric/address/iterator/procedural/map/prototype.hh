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

#include"body/peek_action.hpp"
#include"body/count_action.hpp"
#include"body/iterate_out.hpp"
#include"body/iterate_in.hpp"
//#include"body/memory_action_in.hpp"

/***********************************************************************************************************************/


template
<
	typename subject,
	typename object,

	size_type sIntervalEnum = subject::interval_enum,
	size_type oIntervalEnum = object::interval_enum,
	size_type oImageEnum = object::image_enum
>
struct prototype;


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<typename subject, typename object, size_type oImageEnum>
struct prototype<subject, object, Adjective::closing, Adjective::closing, oImageEnum>
{
	template<typename Functor>
	static typename subject::pointer map(size_type & count, typename subject::pointer out,
		Functor functor, typename object::pointer in, typename object::pointer end)
	{
		while (in != end)
		{
			functor(out, in);
			count_action<Type>::apply(count);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(in);
		}

		return out;
	}

	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in, typename object::pointer end)
	{
		size_type count;

		return map(count, out, [](typename subject::pointer & o, typename object::pointer i) { *o = *i; }, in, end);
	}

	static typename subject::pointer map(typename subject::pointer & out,
		size_type length, size_type offset, typename object::pointer in, typename object::pointer end)
	{
		out=new value_type[length];

		return map(out + offset, in, end);
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::closing, Adjective::closed>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<subject>::apply(out);
		memory_action_in<object>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::closing, Adjective::opening, Adjective::mutate>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		while (in != end)
		{
			iterate_in<object, Adjective::mutate>::apply(variables);

			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
		}

		return out;
	}
};
*/


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::closing, Adjective::opening, Adjective::deallocate>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_in<object, Adjective::mutate>::apply(variables);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object, Adjective::deallocate>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<subject>::apply(out);
		memory_action_in<object, Adjective::deallocate>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::closing, Adjective::open>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_in<object, Adjective::mutate>::apply(variables);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		return out;
	}
};
*/


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::closed, Adjective::closing>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		while (peek_action<object>::test(in, end))
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate_in<object>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::closed, Adjective::closed>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<object>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::closed, Adjective::opening>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_in<object, Adjective::mutate>::apply(variables);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<object>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::closed, Adjective::open>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_in<object, Adjective::mutate>::apply(variables);

		while (peek_action<object>::test(in, end))
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate_in<object>::apply(variables);

		return out;
	}
};
*/


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::opening, Adjective::closing>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		while (in != end)
		{
			iterate_out<subject>::apply(out);

			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_in<object>::apply(variables);
		}

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::opening, Adjective::closed>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_out<subject>::apply(out);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<object>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::opening, Adjective::opening, Adjective::mutate>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		while (in != end)
		{
			iterate_in<object, Adjective::mutate>::apply(variables);
			iterate_out<subject>::apply(out);

			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);
		}

		return out;
	}
};
*/


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::opening, Adjective::opening, Adjective::deallocate>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_in<object, Adjective::mutate>::apply(variables);
		iterate_out<subject>::apply(out);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object, Adjective::deallocate>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<object, Adjective::deallocate>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::opening, Adjective::open>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_in<object, Adjective::mutate>::apply(variables);

		while (in != end)
		{
			iterate_out<subject>::apply(out);

			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_in<object>::apply(variables);
		}

		return out;
	}
};
*/


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::open, Adjective::closing>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_out<subject>::apply(out);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::open, Adjective::closed>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_out<subject>::apply(out);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<subject>::apply(out);
		memory_action_in<object>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::open, Adjective::opening, Adjective::mutate>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		while (in != end)
		{
			iterate_in<object, Adjective::mutate>::apply(variables);
			iterate_out<subject>::apply(out);

			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);
		}

		iterate_out<subject>::apply(out);

		return out;
	}
};
*/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::open, Adjective::opening, Adjective::deallocate>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_in<object, Adjective::mutate>::apply(variables);
		iterate_out<subject>::apply(out);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object, Adjective::deallocate>::apply(variables);
		}

		main_action<subject, object>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<subject>::apply(out);
		memory_action_in<object, Adjective::deallocate>::apply(variables);

		return out;
	}
};
*/


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


/*
template<typename subject, typename object>
struct prototype<subject, object, Adjective::open, Adjective::open>
{
	static typename subject::pointer map(typename subject::pointer out, typename object::pointer in)
	{
		iterate_in<object, Adjective::mutate>::apply(variables);
		iterate_out<subject>::apply(out);

		while (in != end)
		{
			main_action<subject, object>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<subject>::apply(out);
			iterate_in<object>::apply(variables);
		}

		return out;
	}
};
*/


