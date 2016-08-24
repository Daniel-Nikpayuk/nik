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
	typename object,

		// permutated order of parameters is for convenience of type deduction.
	size_type imageEnum = object::image_enum,
	size_type directionEnum = object::direction_enum,
	size_type iteratorEnum = object::iterator_enum
>
struct iterate_in;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename object, size_type iteratorEnum>
struct iterate_in<object, Adjective::mutate, Adjective::forward, iteratorEnum>
{
	static void apply(typename object::pointer & in)
	{
		++in;
	}
};


/***********************************************************************************************************************/


template<typename object>
struct iterate_in<object, Adjective::deallocate, Adjective::forward, Adjective::segment>
{
	static void apply(typename object::pointer & in)
	{
		++in;
	}
};


template<typename object>
struct iterate_in<object, Adjective::deallocate, Adjective::forward, Adjective::hook>
{
	static void apply(typename object::pointer & in)
	{
		delete in++;
	}
};


template<typename object>
struct iterate_in<object, Adjective::deallocate, Adjective::forward, Adjective::link>
{
	static void apply(typename object::pointer & in)
	{
		++in;
		delete -in;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename object, size_type iteratorEnum>
struct iterate_in<object, Adjective::mutate, Adjective::backward, iteratorEnum>
{
	static void apply(typename object::pointer & in)
	{
		--in;
	}
};


/***********************************************************************************************************************/


template<typename object>
struct iterate_in<object, Adjective::deallocate, Adjective::backward, Adjective::segment>
{
	static void apply(typename object::pointer & in)
	{
		--in;
	}
};


template<typename object>
struct iterate_in<object, Adjective::deallocate, Adjective::backward, Adjective::hook>
{
	static void apply(typename object::pointer & in)
	{
		delete in--;
	}
};


template<typename object>
struct iterate_in<object, Adjective::deallocate, Adjective::backward, Adjective::link>
{
	static void apply(typename object::pointer & in)
	{
		--in;
		delete +in;
	}
};


