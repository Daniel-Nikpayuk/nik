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
	typename Adjective,

	size_type directionEnum = Adjective::traits::direction_enum,
	size_type imageEnum = Adjective::traits::image_enum,
	size_type iteratorEnum = Adjective::traits::iterator_enum
>
struct iterate_out { };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename Adjective, size_type iteratorEnum>
struct iterate_out<Adjective, ModIterator::forward, ModIterator::mutate, iteratorEnum>
{
	static void apply(Adjective & subject)
	{
		++subject.terminal;
	}
};


/***********************************************************************************************************************/


template<typename Adjective>
struct iterate_out<Adjective, ModIterator::forward, ModIterator::allocate, ModIterator::segment>
{
	static void apply(Adjective & subject)
	{
		++subject.terminal;
	}
};


template<typename Adjective>
struct iterate_out<Adjective, ModIterator::forward, ModIterator::allocate, ModIterator::hook>
{
	static void apply(Adjective & subject)
	{
		subject.terminal = +subject.terminal = new typename Adjective::traits::iterator_type;
	}
};


template<typename Adjective>
struct iterate_out<Adjective, ModIterator::forward, ModIterator::allocate, ModIterator::link>
{
	static void apply(Adjective & subject)
	{
		+subject.terminal = new typename Adjective::traits::iterator_type;
		-+subject.terminal = subject.terminal;
		++subject.terminal;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename Adjective, size_type iteratorEnum>
struct iterate_out<Adjective, ModIterator::backward, ModIterator::mutate, iteratorEnum>
{
	static void apply(Adjective & subject)
	{
		--subject.terminal;
	}
};


/***********************************************************************************************************************/


template<typename Adjective>
struct iterate_out<Adjective, ModIterator::backward, ModIterator::allocate, ModIterator::segment>
{
	static void apply(Adjective & subject)
	{
		--subject.terminal;
	}
};


template<typename Adjective>
struct iterate_out<Adjective, ModIterator::backward, ModIterator::allocate, ModIterator::hook>
{
	static void apply(Adjective & subject)
	{
		typename Adjective::traits::pointer_type out = subject.terminal;
		subject.terminal = new typename Adjective::traits::iterator_type;
		+subject.terminal = out;
	}
};


template<typename Adjective>
struct iterate_out<Adjective, ModIterator::backward, ModIterator::allocate, ModIterator::link>
{
	static void apply(Adjective & subject)
	{
		-subject.terminal = new typename Adjective::traits::iterator_type;
		+-subject.terminal = subject.terminal;
		--subject.terminal;
	}
};


