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
	Given the unsafe nature of semiotic::vector policy here is composability instead of inheritance.

	Test against self-assignment!
*/

template<typename T, typename SizeType>
struct base
{
	typedef random_access::traits<SizeType> r_traits;
	typedef typename r_traits::container<base, T> attributes;

	typedef typename attributes::value_type value_type;
	typedef typename attributes::reference reference;
	typedef typename attributes::const_reference const_reference;
	typedef typename attributes::size_type size_type;

	typedef iterator::componentwise::structural::traits<size_type> ics_traits;
	typedef typename its_traits::array<T> node;
	typedef typename its_traits::const_array<T> const_node;
	typedef typename node::pointer iterator;
	typedef typename const_node::pointer const_iterator;

	typedef iterator::componentwise::functional::policy<size_type> icf_policy;
	typedef functional::policy<size_type> f_policy;

	iterator initial;
	size_type length;
/*
	Assigning "terminal" first (given the possible order exchange) is semantically preferred as it
	expects an iterator without a value, while with "initial" a value is expected when the vector is non-empty.
*/
	void initialize(size_type n)
	{
		initial=new node[n];
		length=n;
	}

	template<typename RIterator>
	void copy_initialize(RIterator first, size_type size)
	{
		initialize(size);
		icf_policy::fwd_over::assign::no_return(initial, first, first+size);
	}

	void terminalize() { delete [] initial; }

	base() { }
	base(const base & n) { }
	~base() { }

	const base & operator = (const base & n)
		{ return *this; }

	iterator begin() { return initial; }
	const_iterator cbegin() const { return initial; }
	iterator end() { return initial+length; }
	const_iterator cend() const { return initial+length; }
};

