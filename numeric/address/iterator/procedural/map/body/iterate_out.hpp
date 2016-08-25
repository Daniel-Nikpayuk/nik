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
	typename sub_adjective,

	size_type sub_directionEnum = sub_adjective::direction_enum,
	size_type sub_imageEnum = sub_adjective::image_enum,
	size_type sub_iteratorEnum = sub_adjective::iterator_enum
>
struct iterate_out;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename sub_adjective, size_type sub_iteratorEnum>
struct iterate_out<sub_adjective, Adjective::forward, Adjective::mutate, sub_iteratorEnum>
{
	static void apply(sub_pointer & out)
	{
		++out;
	}
};


/***********************************************************************************************************************/


template<typename sub_adjective>
struct iterate_out<sub_adjective, Adjective::forward, Adjective::allocate, Adjective::segment>
{
	static void apply(sub_pointer & out)
	{
		++out;
	}
};


template<typename sub_adjective>
struct iterate_out<sub_adjective, Adjective::forward, Adjective::allocate, Adjective::hook>
{
	static void apply(sub_pointer & out)
	{
		out = +out = new sub_adjective;
	}
};


template<typename sub_adjective>
struct iterate_out<sub_adjective, Adjective::forward, Adjective::allocate, Adjective::link>
{
	static void apply(sub_pointer & out)
	{
		+out = new sub_adjective;
		-+out = out;
		++out;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename sub_adjective, size_type sub_iteratorEnum>
struct iterate_out<sub_adjective, Adjective::backward, Adjective::mutate, sub_iteratorEnum>
{
	static void apply(sub_pointer & out)
	{
		--out;
	}
};


/***********************************************************************************************************************/


template<typename sub_adjective>
struct iterate_out<sub_adjective, Adjective::backward, Adjective::allocate, Adjective::segment>
{
	static void apply(sub_pointer & out)
	{
		--out;
	}
};


template<typename sub_adjective>
struct iterate_out<sub_adjective, Adjective::backward, Adjective::allocate, Adjective::hook>
{
	static void apply(sub_pointer & out)
	{
		sub_pointer tmp = out;
		out = new sub_adjective;
		+out = tmp;
	}
};


template<typename sub_adjective>
struct iterate_out<sub_adjective, Adjective::backward, Adjective::allocate, Adjective::link>
{
	static void apply(sub_pointer & out)
	{
		-out = new sub_adjective;
		+-out = out;
		--out;
	}
};


