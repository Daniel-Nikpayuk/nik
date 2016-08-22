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

	size_type arityEnum = Adjective::traits::arity_enum,
	size_type directionEnum = Adjective::traits::direction_enum,
	size_type imageEnum = Adjective::traits::image_enum,
	size_type iteratorEnum = Adjective::traits::iterator_enum
>
struct iterate_in { };


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename Adjective, size_type iteratorEnum>
struct iterate_in<Adjective, ModIterator::unary, ModIterator::forward, ModIterator::mutate, iteratorEnum>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.in;
	}
};


/***********************************************************************************************************************/


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::unary, ModIterator::forward, ModIterator::deallocate, ModIterator::segment>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.in;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::unary, ModIterator::forward, ModIterator::deallocate, ModIterator::hook>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		delete variables.in++;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::unary, ModIterator::forward, ModIterator::deallocate, ModIterator::link>
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
struct iterate_in<Adjective, ModIterator::unary, ModIterator::backward, ModIterator::mutate, iteratorEnum>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.in;
	}
};


/***********************************************************************************************************************/


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::unary, ModIterator::backward, ModIterator::deallocate, ModIterator::segment>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.in;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::unary, ModIterator::backward, ModIterator::deallocate, ModIterator::hook>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		delete variables.in--;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::unary, ModIterator::backward, ModIterator::deallocate, ModIterator::link>
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
struct iterate_in<Adjective, ModIterator::binary, ModIterator::forward, ModIterator::mutate, iteratorEnum>
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
struct iterate_in<Adjective, ModIterator::binary, ModIterator::forward, ModIterator::deallocate, ModIterator::segment>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		++variables.fin;
		++variables.in;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::binary, ModIterator::forward, ModIterator::deallocate, ModIterator::hook>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		delete variables.fin++;
		delete variables.in++;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::binary, ModIterator::forward, ModIterator::deallocate, ModIterator::link>
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
struct iterate_in<Adjective, ModIterator::binary, ModIterator::backward, ModIterator::mutate, iteratorEnum>
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
struct iterate_in<Adjective, ModIterator::binary, ModIterator::backward, ModIterator::deallocate, ModIterator::segment>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		--variables.fin;
		--variables.in;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::binary, ModIterator::backward, ModIterator::deallocate, ModIterator::hook>
{
	template<typename Variables>
	static void apply(Variables & variables)
	{
		delete variables.fin--;
		delete variables.in--;
	}
};


template<typename Adjective>
struct iterate_in<Adjective, ModIterator::binary, ModIterator::backward, ModIterator::deallocate, ModIterator::link>
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


/***********************************************************************************************************************/
/***********************************************************************************************************************/


