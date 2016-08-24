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
	typename subject,

	size_type directionEnum = subject::direction_enum,
	size_type imageEnum = subject::image_enum,
	size_type iteratorEnum = subject::iterator_enum
>
struct iterate_out;


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename subject, size_type iteratorEnum>
struct iterate_out<subject, Adjective::forward, Adjective::mutate, iteratorEnum>
{
	static void apply(typename subject::pointer & out)
	{
		++out;
	}
};


/***********************************************************************************************************************/


template<typename subject>
struct iterate_out<subject, Adjective::forward, Adjective::allocate, Adjective::segment>
{
	static void apply(typename subject::pointer & out)
	{
		++out;
	}
};


template<typename subject>
struct iterate_out<subject, Adjective::forward, Adjective::allocate, Adjective::hook>
{
	static void apply(typename subject::pointer & out)
	{
		out = +out = new subject;
	}
};


template<typename subject>
struct iterate_out<subject, Adjective::forward, Adjective::allocate, Adjective::link>
{
	static void apply(typename subject::pointer & out)
	{
		+out = new subject;
		-+out = out;
		++out;
	}
};


/***********************************************************************************************************************/
/***********************************************************************************************************************/


template<typename subject, size_type iteratorEnum>
struct iterate_out<subject, Adjective::backward, Adjective::mutate, iteratorEnum>
{
	static void apply(typename subject::pointer & out)
	{
		--out;
	}
};


/***********************************************************************************************************************/


template<typename subject>
struct iterate_out<subject, Adjective::backward, Adjective::allocate, Adjective::segment>
{
	static void apply(typename subject::pointer & out)
	{
		--out;
	}
};


template<typename subject>
struct iterate_out<subject, Adjective::backward, Adjective::allocate, Adjective::hook>
{
	static void apply(typename subject::pointer & out)
	{
		typename subject::pointer current = out;
		out = new subject;
		+out = current;
	}
};


template<typename subject>
struct iterate_out<subject, Adjective::backward, Adjective::allocate, Adjective::link>
{
	static void apply(typename subject::pointer & out)
	{
		-out = new subject;
		+-out = out;
		--out;
	}
};


