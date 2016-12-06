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


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(_adverb<LIST<functorEnum, tracerEnum, Connotation::specialize>, F> & ad,

	sub_pointer out,

	const _adjective<LIST<sub_directionEnum, Association::closing, sub_imageEnum, sub_iteratorEnum>> & sub,

	ob_pointer in, ob_pointer end,

	const _adjective<LIST<ob_directionEnum, Association::closing, ob_imageEnum, ob_iteratorEnum>> & ob);

/*
template<typename sub_adjective, typename ob_adjective>
struct specialize
{
	template<typename sub_pointer, typename map_adverb, typename ob_pointer>
	static sub_pointer map(sub_pointer, map_adverb, ob_pointer, ob_pointer);
};


	The ordering of the arguments are intended to privilege template parameter type deduction.

template<typename sub_pointer, typename map_adverb, typename ob_pointer, typename sub_adjective, typename ob_adjective>
static sub_pointer map(sub_pointer out, map_adverb & ad, ob_pointer in, ob_pointer end, const sub_adjective & sub, const ob_adjective & ob)
{
	using optimizer_type = CASES
	<
		(map_adverb::optimizer_enum - map_adverb::optimizer_offset),
		prototype<sub_adjective, ob_adjective>,
		specialize<sub_adjective, ob_adjective>

	>::rtn;

	return optimizer_type::map(out, ad, in, end, sub, ob);
}
*/


/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/


//#include"body/peek_action.hpp"
#include"body/functor_action.hpp"
#include"body/count_action.hpp"
#include"body/iterate_action.hpp"
//#include"body/memory_action_in.hpp"


/***********************************************************************************************************************/
/***********************************************************************************************************************/


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,
	size_type sub_imageEnum,
	size_type sub_iteratorEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(_adverb<LIST<functorEnum, tracerEnum, Connotation::prototype>, F> & ad,

	sub_pointer out,

	const _adjective<LIST<sub_directionEnum, Association::closing, sub_imageEnum, sub_iteratorEnum>> & sub,

	ob_pointer in, ob_pointer end,

	const _adjective<LIST<ob_directionEnum, Association::closing, ob_imageEnum, ob_iteratorEnum>> & ob)
{
	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_out_action(out, sub);
		iterate_in_action(in, ob);
	}

	return out;
}


/*
	allocate, segment:
*/


template
<
	size_type functorEnum,
	size_type tracerEnum,
	typename F,

	typename sub_pointer,

	size_type sub_directionEnum,

	typename ob_pointer,

	size_type ob_directionEnum,
	size_type ob_imageEnum,
	size_type ob_iteratorEnum
>
static sub_pointer map(_adverb<LIST<functorEnum, tracerEnum, Connotation::prototype>, F> & ad,

	sub_pointer & origin,

	const _adjective<LIST<sub_directionEnum, Association::closing, Association::allocate, Association::segment>> & sub,

	ob_pointer in, ob_pointer end,

	const _adjective<LIST<ob_directionEnum, Association::closing, ob_imageEnum, ob_iteratorEnum>> & ob)
{
	using value_type = typename structural<nik::semiotic>::template trim<sub_pointer>::pointer::value_type;
	origin = new value_type[sub.length];
	size_type offset = (sub_directionEnum == Association::forward) ? sub.offset : sub.length - 1 - sub.offset;
	sub_pointer out = origin + offset;

	while (in != end)
	{
		functor_action(ad, out, in);
		count_action(ad);

		iterate_action(out, sub);
		iterate_action(in, ob);
	}

	return out;
}


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
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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

			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective, Association::deallocate>::apply(variables);
		}

		functor_action<sub_adjective, ob_adjective>::apply(out, variables);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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

			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

		functor_action<sub_adjective, ob_adjective>::apply(out, variables);
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

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective, Association::deallocate>::apply(variables);
		}

		functor_action<sub_adjective, ob_adjective>::apply(out, variables);
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

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

		functor_action<sub_adjective, ob_adjective>::apply(out, variables);
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

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective, Association::deallocate>::apply(variables);
		}

			functor_action<sub_adjective, ob_adjective>::apply(out, in, side);
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
			functor_action<sub_adjective, ob_adjective>::apply(out, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sub_adjective>::apply(out);
			iterate_in<ob_adjective>::apply(variables);
		}

		deinitialize_variables<sub_adjective, ob_adjective>::apply(out, in, side);

		return out;
	}
};
*/


