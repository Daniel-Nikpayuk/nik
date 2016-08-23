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

#include"body/declare_variables.hpp"
#include"body/peek_action.hpp"
#include"body/main_action.hpp"
#include"body/count_action.hpp"
#include"body/iterate_out.hpp"
#include"body/iterate_in.hpp"
#include"body/memory_action_in.hpp"
#include"body/undeclare_variables.hpp"

/***********************************************************************************************************************/


template
<
	typename const_sAdjective,
	typename oAdjective,
	typename Adverb,

	size_type sIntervalEnum = const_sAdjective::traits::interval_enum,
	size_type oIntervalEnum = oAdjective::traits::interval_enum,
	size_type oImageEnum = oAdjective::traits::image_enum
>
struct prototype { };


/************************************************************************************************************************
							closing
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in)
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closing, ModIterator::closing>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in+1)
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closing, ModIterator::closed>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<sAdjective>::apply(subject);
		memory_action_in<oAdjective>::apply(variables);

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in)
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closing, ModIterator::opening, ModIterator::mutate>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			iterate_in<oAdjective, ModIterator::mutate>::apply(variables);

			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
		}

		undeclare_variables<oAdjective, ModIterator::mutate>::apply(variables);

		return subject;
	}
};


/*
	Constraints:

	(in, end] --> [out, out + end-in), end-in > 0
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closing, ModIterator::opening, ModIterator::deallocate>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_in<oAdjective, ModIterator::mutate>::apply(variables);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective, ModIterator::deallocate>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<sAdjective>::apply(subject);
		memory_action_in<oAdjective, ModIterator::deallocate>::apply(variables);

		undeclare_variables<oAdjective, ModIterator::deallocate>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-1), end-in > 0
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closing, ModIterator::open>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_in<oAdjective, ModIterator::mutate>::apply(variables);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/************************************************************************************************************************
							closed
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> [out, out + end-in-1], end-in > 0
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closed, ModIterator::closing>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (apply_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		iterate_in<oAdjective>::apply(variables);

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> [out, out + end-in]
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closed, ModIterator::closed>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<oAdjective>::apply(variables);

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> [out, out + end-in-1], end-in > 0
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closed, ModIterator::opening>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_in<oAdjective, ModIterator::mutate>::apply(variables);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<oAdjective>::apply(variables);

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> [out, out + end-in-2], end-in > 1
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::closed, ModIterator::open>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_in<oAdjective, ModIterator::mutate>::apply(variables);

		while (apply_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		iterate_in<oAdjective>::apply(variables);

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/************************************************************************************************************************
							opening
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in]
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::opening, ModIterator::closing>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			iterate_out<sAdjective>::apply(subject);

			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_in<oAdjective>::apply(variables);
		}

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+1]
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::opening, ModIterator::closed>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_out<sAdjective>::apply(subject);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<oAdjective>::apply(variables);

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in]
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::opening, ModIterator::opening, ModIterator::mutate>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			iterate_in<oAdjective, ModIterator::mutate>::apply(variables);
			iterate_out<sAdjective>::apply(subject);

			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);
		}

		undeclare_variables<oAdjective, ModIterator::mutate>::apply(variables);

		return subject;
	}
};


/*
	Constraints:

	(in, end] --> (out, out + end-in], end-in > 0
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::opening, ModIterator::opening, ModIterator::deallocate>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_in<oAdjective, ModIterator::mutate>::apply(variables);
		iterate_out<sAdjective>::apply(subject);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective, ModIterator::deallocate>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		memory_action_in<oAdjective, ModIterator::deallocate>::apply(variables);

		undeclare_variables<oAdjective, ModIterator::deallocate>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in-1], end-in > 0
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::opening, ModIterator::open>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_in<oAdjective, ModIterator::mutate>::apply(variables);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			iterate_out<sAdjective>::apply(subject);

			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_in<oAdjective>::apply(variables);
		}

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/************************************************************************************************************************
							open
************************************************************************************************************************/


/*
	Constraints:

	[in, end) --> (out, out + end-in+1)
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::open, ModIterator::closing>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_out<sAdjective>::apply(subject);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	[in, end] --> (out, out + end-in+2)
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::open, ModIterator::closed>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_out<sAdjective>::apply(subject);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<sAdjective>::apply(subject);
		memory_action_in<oAdjective>::apply(variables);

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end] --> (out, out + end-in+1)
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::open, ModIterator::opening, ModIterator::mutate>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			iterate_in<oAdjective, ModIterator::mutate>::apply(variables);
			iterate_out<sAdjective>::apply(subject);

			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);
		}

		iterate_out<sAdjective>::apply(subject);

		undeclare_variables<oAdjective, ModIterator::mutate>::apply(variables);

		return subject;
	}
};


/*
	Constraints:

	(in, end] --> (out, out + end-in+1), end-in > 0
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::open, ModIterator::opening, ModIterator::deallocate>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_in<oAdjective, ModIterator::mutate>::apply(variables);
		iterate_out<sAdjective>::apply(subject);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective, ModIterator::deallocate>::apply(variables);
		}

		main_action<sAdjective, oAdjective>::apply(subject, variables);
		count_action<Adverb>::apply(verb);

		iterate_out<sAdjective>::apply(subject);
		memory_action_in<oAdjective, ModIterator::deallocate>::apply(variables);

		undeclare_variables<oAdjective, ModIterator::deallocate>::apply(variables);

		return subject;
	}
};


/***********************************************************************************************************************/


/*
	Constraints:

	(in, end) --> (out, out + end-in), end-in > 0
*/


template<typename const_sAdjective, typename oAdjective, typename Adverb>
struct prototype<const_sAdjective, oAdjective, Adverb, ModIterator::open, ModIterator::open>
{
	typedef typename const_sAdjective::traits::mutate_type sAdjective;

	static sAdjective map(const const_sAdjective & const_subject, oAdjective & object, Adverb & verb)
	{
		sAdjective subject = const_subject;

		declare_variables<oAdjective> variables(object);

		iterate_in<oAdjective, ModIterator::mutate>::apply(variables);
		iterate_out<sAdjective>::apply(subject);

		while (omit_peek<oAdjective>::test(variables, object))
		{
			main_action<sAdjective, oAdjective>::apply(subject, variables);
			count_action<Adverb>::apply(verb);

			iterate_out<sAdjective>::apply(subject);
			iterate_in<oAdjective>::apply(variables);
		}

		undeclare_variables<oAdjective>::apply(variables);

		return subject;
	}
};


