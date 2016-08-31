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

//#include"body/peek_action.hpp"
//#include"body/main_action.hpp"
//#include"body/count_action.hpp"
//#include"body/iterate_out.hpp"
//#include"body/iterate_in.hpp"
//#include"body/memory_action_in.hpp"
//#include"body/deinitialize_variables.hpp"

/***********************************************************************************************************************/


template
<
	typename sub_adjective,
	typename ob_adjective,

	size_type sub_intervalEnum = sub_adjective::interval_enum,
	size_type ob_intervalEnum = ob_adjective::interval_enum,
	size_type ob_imageEnum = ob_adjective::image_enum
>
struct prototype;


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<typename sub_adjective, typename ob_adjective, size_type oImageEnum>
struct prototype<sub_adjective, ob_adjective, Association::closing, Association::closing, oImageEnum>
{
	template<typename sub_pointer, typename map_adverb, typename ob_pointer>
	static sub_pointer map(sub_pointer out, map_adverb ad, ob_pointer in, ob_pointer end, sub_adjective sub, ob_adjective ob)
	{
/*
		while (in != end)
		{
			main_action<adverb>::apply(out, side, in);
			count_action<adverb>::apply(side);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(in);
		}
*/

//		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, var);

		return out;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


/*
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closing, Association::closed>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
		count_action<Adverb>::apply(verb);

		iterate_out<sub_adjective>::apply(out);
		memory_action_in<ob_adjective>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closing, Association::opening, Association::mutate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		while (in != end)
		{
			iterate_in<ob_adjective, Association::mutate>::apply(variables);

			main_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
		}

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


/*
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closing, Association::opening, Association::deallocate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_in<ob_adjective, Association::mutate>::apply(variables);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective, Association::deallocate>::apply(variables);
		}

		main_action<sub_adjective, ob_adjective>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<sub_adjective>::apply(out);
		memory_action_in<ob_adjective, Association::deallocate>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closing, Association::open>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_in<ob_adjective, Association::mutate>::apply(variables);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closed, Association::closing>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		while (peek_action<ob_adjective>::test(in, end))
		{
			main_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
		count_action<Adverb>::apply(verb);

		iterate_in<ob_adjective>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closed, Association::closed>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
		count_action<Adverb>::apply(verb);

		memory_action_in<ob_adjective>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closed, Association::opening>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_in<ob_adjective, Association::mutate>::apply(variables);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
		count_action<Adverb>::apply(verb);

		memory_action_in<ob_adjective>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::closed, Association::open>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_in<ob_adjective, Association::mutate>::apply(variables);

		while (peek_action<ob_adjective>::test(in, end))
		{
			main_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
		count_action<Adverb>::apply(verb);

		iterate_in<ob_adjective>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::opening, Association::closing>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		while (in != end)
		{
			iterate_out<sub_adjective>::apply(out);

			main_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_in<ob_adjective>::apply(variables);
		}

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::opening, Association::closed>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_out<sub_adjective>::apply(out);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

		main_action<sub_adjective, ob_adjective>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<ob_adjective>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::opening, Association::opening, Association::mutate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		while (in != end)
		{
			iterate_in<ob_adjective, Association::mutate>::apply(variables);
			iterate_out<sub_adjective>::apply(out);

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);
		}

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


/*
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::opening, Association::opening, Association::deallocate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_in<ob_adjective, Association::mutate>::apply(variables);
		iterate_out<sub_adjective>::apply(out);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective, Association::deallocate>::apply(variables);
		}

		main_action<sub_adjective, ob_adjective>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<ob_adjective, Association::deallocate>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::opening, Association::open>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_in<ob_adjective, Association::mutate>::apply(variables);

		while (in != end)
		{
			iterate_out<sub_adjective>::apply(out);

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_in<ob_adjective>::apply(variables);
		}

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::open, Association::closing>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_out<sub_adjective>::apply(out);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::open, Association::closed>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_out<sub_adjective>::apply(out);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

		main_action<sub_adjective, ob_adjective>::apply(out, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<sub_adjective>::apply(out);
		memory_action_in<ob_adjective>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::open, Association::opening, Association::mutate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		while (in != end)
		{
			iterate_in<ob_adjective, Association::mutate>::apply(variables);
			iterate_out<sub_adjective>::apply(out);

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);
		}

		iterate_out<sub_adjective>::apply(out);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


/*
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::open, Association::opening, Association::deallocate>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_in<ob_adjective, Association::mutate>::apply(variables);
		iterate_out<sub_adjective>::apply(out);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective, Association::deallocate>::apply(variables);
		}

			main_action<sub_adjective, ob_adjective>::apply(out, in, side);
		count_action<Adverb>::apply(verb);

		iterate_out<sub_adjective>::apply(out);
		memory_action_in<ob_adjective, Association::deallocate>::apply(variables);

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

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
template<typename sub_adjective, typename ob_adjective>
struct prototype<sub_adjective, ob_adjective, Association::open, Association::open>
{
	static sub_pointer map(sub_pointer out, ob_pointer in)
	{
		initialize_variables<sub_adjective>::apply(out, side);

		iterate_in<ob_adjective, Association::mutate>::apply(variables);
		iterate_out<sub_adjective>::apply(out);

		while (in != end)
		{
			main_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


