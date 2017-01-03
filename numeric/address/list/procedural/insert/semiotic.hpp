/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename WList, typename ValueType>
static typename WList::iterator insert(<prepend>, WList & out, <closing>, ValueType value)
{
	*snrlf_policy::iden::grow::before::no_return(out, new typename WList::node)=value;

	return out.initial;
}

/*
	n >= 1.
*/

template<typename WList, typename ValueType>
static typename WList::iterator insert(<prepend>, WList & out, <closing>, size_type n, ValueType value)
{
	typename WList::iterator in=new typename WList::node;
	*in=value;
	return snrlf_policy::iden::grow::before::with_return(out, in,
		snritf_policy::fwd_over::repeat::post_test::template
			with_return<typename WList::node>(in, n-1, value));
}

/*
	in != end
*/

template<typename WList, typename RIterator, typename ERIterator>
static typename WList::iterator insert(<prepend>, WList & out, <closing>, RIterator in, ERIterator end, <closing>)
{
	typename WList::iterator tmp=new typename WList::node;
	return snrlf_policy::iden::grow::before::with_return(out, tmp,
		snritf_policy::disc::assign::prepost::template
			with_return<typename WList::node>(tmp, in, end));
}

template<typename WList, typename ValueType>
static typename WList::iterator insert(<append>, WList & out, <closing>, ValueType value)
{
	*snrlf_policy::iden::grow::after::no_return(out, new typename WList::node)=value;

	return out.terminal;
}

/*
	n >= 1.
*/

template<typename WList, typename ValueType>
static typename WList::iterator insert(<append>, WList & out, <closing>, size_type n, ValueType value)
{
	typename WList::iterator in=new typename WList::node;
	*in=value;
	return snrlf_policy::iden::grow::after::with_return(out, in,
		snritf_policy::fwd_over::repeat::post_test::template
			with_return<typename WList::node>(in, n-1, value));
}

template<typename WList, typename RIterator, typename ERIterator>
static typename WList::iterator insert(<append>, WList & out, <closing>, RIterator in, ERIterator end, <closing>)
{
	typename WList::iterator tmp=new typename WList::node;
	return snrlf_policy::iden::grow::after::with_return(out, tmp,
		snritf_policy::fwd_over::assign::template
			with_return<typename WList::node>(tmp, in, end));
}

/*
	in != end
*/

template<typename WList, typename RIterator, typename ERIterator>
static typename WList::iterator insert(<append>, WList & out, <closing>, RIterator in, ERIterator end, <prepost>)
{
	typename WList::iterator tmp=new typename WList::node;
	return snrlf_policy::iden::grow::after::with_return(out, tmp,
		snritf_policy::disc::assign::prepost::template
			with_return<typename WList::node>(tmp, in, end));
}

template<typename WList, typename ValueType>
static typename WList::iterator insert(<impend>, WList & out, ValueType value)
{
	*snrlf_policy::iden::grow::between::no_return(out, new typename WList::node)=value;

	return out.initial;
}

/*
	n >= 1.
*/

template<typename WList, typename ValueType>
static typename WList::iterator insert(<impend>, WList & out, size_type n, ValueType value)
{
	typename WList::iterator in=new typename WList::node;
	*in=value;
	return snrlf_policy::iden::grow::between::with_return(out, in,
		snritf_policy::fwd_over::repeat::post_test::template
			with_return<typename WList::node>(in, n-1, value));
}

/*
	in != end
*/

template<typename WList, typename RIterator, typename ERIterator>
static typename WList::iterator insert(<impend>, WList & out, RIterator in, ERIterator end, <closing>)
{
	typename WList::iterator tmp=new typename WList::node;
	return snrlf_policy::iden::grow::between::with_return(out, tmp,
		snritf_policy::disc::assign::prepost::template
			with_return<typename WList::node>(tmp, in, end));
}

