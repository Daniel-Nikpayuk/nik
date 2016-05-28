/*************************************************************************************************************************
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
*************************************************************************************************************************/

/*
	Given the unsafe nature of semiotic::list, policy here is designed for composability instead of inheritance.

	Test against self-assignment!
*/

template<typename T, typename SizeType>
struct identity
{
	typedef random_access::traits<SizeType> r_traits;
	typedef typename r_traits::container<identity, T> attributes;

	typedef typename attributes::value_type value_type;
	typedef typename attributes::reference reference;
	typedef typename attributes::const_reference const_reference;
	typedef typename attributes::size_type size_type;

	typedef iterator::extensionwise::structural::traits<size_type> its_traits;
	typedef typename its_traits::hook<T> node;
	typedef typename its_traits::const_hook<T> const_node;
	typedef typename node::pointer iterator;
	typedef typename const_node::pointer const_iterator;

	typedef iterator::extensionwise::functional::policy<size_type> itf_policy;
	typedef functional::policy<size_type> f_policy;

	iterator initial;
	iterator terminal;
/*
	Assigning "terminal" first (given the possible order exchange) is semantically preferred as it
	expects an iterator without a value, while with "initial" a value is expected when the list is non-empty.
*/
	void initialize()
		{ initial=terminal=new node; }

	template<typename RIterator, typename ERIterator>
	void copy_initialize(RIterator first, ERIterator last)
	{
		initialize();
		terminal=itf_policy::fwd_over::assign::template with_return<node>(terminal, first, last);
	}

	void terminalize()
	{
		itf_policy::disc::clear::no_return(initial, terminal);
		delete terminal;
	}

	identity() { }
	identity(const identity & n) { }
	~identity() { }

	const identity & operator = (const identity & n)
		{ return *this; }

	iterator begin() { return initial; }
	const_iterator cbegin() const { return (const_iterator) initial; }
	iterator end() { return terminal; }
	const_iterator cend() const { return (const_iterator) terminal; }
};

