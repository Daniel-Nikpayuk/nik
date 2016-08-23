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

		// permutated order of parameters is for convenience of type deduction.
	size_type imageEnum = Adjective::traits::image_enum,
	size_type directionEnum = Adjective::traits::direction_enum,
	size_type iteratorEnum = Adjective::traits::iterator_enum,
	size_type arityEnum = Adjective::traits::arity_enum
>
struct iterate_in { };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename Adjective, size_type iteratorEnum>
struct iterate_in<Adjective, ModIterator::mutate, ModIterator::forward, iteratorEnum, ModIterator::unary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.in;
	}
};


/***********************************************************************************************************************/


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::forward, ModIterator::segment, ModIterator::unary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.in;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::forward, ModIterator::hook, ModIterator::unary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		delete variables.in++;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::forward, ModIterator::link, ModIterator::unary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.in;
		delete -variables.in;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename Adjective, size_type iteratorEnum>
struct iterate_in<Adjective, ModIterator::mutate, ModIterator::backward, iteratorEnum, ModIterator::unary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.in;
	}
};


/***********************************************************************************************************************/


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::backward, ModIterator::segment, ModIterator::unary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.in;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::backward, ModIterator::hook, ModIterator::unary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		delete variables.in--;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::backward, ModIterator::link, ModIterator::unary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.in;
		delete +variables.in;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename Adjective, size_type iteratorEnum>
struct iterate_in<Adjective, ModIterator::mutate, ModIterator::forward, iteratorEnum, ModIterator::binary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.fin;
		++variables.in;
	}
};


/***********************************************************************************************************************/


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::forward, ModIterator::segment, ModIterator::binary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.fin;
		++variables.in;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::forward, ModIterator::hook, ModIterator::binary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		delete variables.fin++;
		delete variables.in++;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::forward, ModIterator::link, ModIterator::binary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.fin;
		++variables.in;

		delete -variables.fin;
		delete -variables.in;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename Adjective, size_type iteratorEnum>
struct iterate_in<Adjective, ModIterator::mutate, ModIterator::backward, iteratorEnum, ModIterator::binary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.fin;
		--variables.in;
	}
};


/***********************************************************************************************************************/


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::backward, ModIterator::segment, ModIterator::binary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.fin;
		--variables.in;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::backward, ModIterator::hook, ModIterator::binary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		delete variables.fin--;
		delete variables.in--;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::deallocate, ModIterator::backward, ModIterator::link, ModIterator::binary>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.fin;
		--variables.in;

		delete +variables.fin;
		delete +variables.in;
	}
};


