/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

template<typename T, typename SizeType>
struct base
{
	typedef random_access::traits<SizeType> r_traits;
	typedef typename r_traits::container<base, T> attributes;

	typedef typename attributes::value_type value_type;
	typedef typename attributes::reference reference;
	typedef typename attributes::const_reference const_reference;
	typedef typename attributes::size_type size_type;

	typedef iterator::expansionwise::structural::traits<size_type> ips_traits;
	typedef typename ips_traits::link<T> node;
	typedef typename ips_traits::const_link<T> const_node;
	typedef typename node::pointer iterator;
	typedef typename const_node::pointer const_iterator;

	typedef iterator::expansionwise::functional::policy<size_type> ipf_policy;
	typedef functional::policy<size_type> f_policy;

	iterator initial;
	iterator terminal;
/*
	Assigning "terminal" first (given the possible order exchange) is semantically preferred as it
	expects an iterator without a value, while with "initial" a value is expected when the chain is non-empty.
*/
	void initialize()
		{ initial=terminal=new node; }

	template<typename RIterator, typename ERIterator>
	void copy_initialize(RIterator first, ERIterator last)
	{
		initialize();
		terminal=ipf_policy::fwd_over::assign::template with_return<node>(terminal, first, last);
	}

	void terminalize()
	{
		ipf_policy::disc::clear::no_return(initial, terminal);
		delete terminal;
	}

	base() { }
	base(const base & n) { }
	~base() { }

	const base & operator = (const base & n)
		{ return *this; }

	iterator begin() { return initial; }
	const_iterator cbegin() const { return initial; }
	iterator end() { return terminal; }
	const_iterator cend() const { return terminal; }
};

