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
	typename ob_adjective,

	size_type ob_directionEnum = ob_adjective::direction_enum,
	size_type ob_imageEnum = ob_adjective::image_enum,
	size_type ob_iteratorEnum = ob_adjective::iterator_enum
>
struct iterate_in
{
	static void apply(ob_pointer & in) { }
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename ob_adjective, size_type ob_iteratorEnum>
struct iterate_in<ob_adjective, Adjective::forward, Adjective::mutate, ob_iteratorEnum>
{
	static void apply(ob_pointer & in)
	{
		++in;
	}
};


/***********************************************************************************************************************/


template<typename ob_adjective>
struct iterate_in<ob_adjective, Adjective::forward, Adjective::deallocate, Adjective::segment>
{
	static void apply(ob_pointer & in)
	{
		++in;
	}
};


template<typename ob_adjective>
struct iterate_in<ob_adjective, Adjective::forward, Adjective::deallocate, Adjective::hook>
{
	static void apply(ob_pointer & in)
	{
		delete in++;
	}
};


template<typename ob_adjective>
struct iterate_in<ob_adjective, Adjective::forward, Adjective::deallocate, Adjective::link>
{
	static void apply(ob_pointer & in)
	{
		delete -++in;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename ob_adjective, size_type ob_iteratorEnum>
struct iterate_in<ob_adjective, Adjective::backward, Adjective::mutate, ob_iteratorEnum>
{
	static void apply(ob_pointer & in)
	{
		--in;
	}
};


/***********************************************************************************************************************/


template<typename ob_adjective>
struct iterate_in<ob_adjective, Adjective::backward, Adjective::deallocate, Adjective::segment>
{
	static void apply(ob_pointer & in)
	{
		--in;
	}
};


template<typename ob_adjective>
struct iterate_in<ob_adjective, Adjective::backward, Adjective::deallocate, Adjective::hook>
{
	static void apply(ob_pointer & in)
	{
		delete in--;
	}
};


template<typename ob_adjective>
struct iterate_in<ob_adjective, Adjective::backward, Adjective::deallocate, Adjective::link>
{
	static void apply(ob_pointer & in)
	{
		delete +--in;
	}
};


