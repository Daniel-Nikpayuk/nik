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

/*
	It is less modular to have "template<typename SizeType, SizeType N>", and so in the generic classes the design
	requires the size_type to be factored out. In the semiotic class, given the nature of representation and that
	there are intentionally no additional classes per "name", and so it is optimized for namespace/class efficiency.
*/

/*
	uinteger:
		Basic intuitive members are first (pointer), last (pointer), and length (size_type). Any one can be determined
		from the other two. For consistency of narrative (and method efficiency), first and last have been chosen.
		Assumes an iterator class to navigate its memory space (which is really just a renaming of the pointer type).

		Note, given the definitions of iterator and const_iterator (as builtin array pointers) there is no automatic conversion
		(templated class constructor) from iterator to const_iterator. This provides motivation for the definitions of
		cbegin and cend to allow for type deduction to succeed.
*/

template<typename ValueType, typename SizeType, SizeType N>
struct uinteger
{
	typedef random_access::traits<SizeType> r_traits;
	typedef typename r_traits::container<uinteger, T> attributes;

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
	static const size_type length=N;
	static const size_type bit_length=8*sizeof(value_type)*N;

	void initialize() { array=new value_type[N]; }
/*
	copy:
		Defining pointers in reference to 'v' is intentional---fewer assumptions
		made about "this" makes this function more portable for outside use.
*/
	template<typename RIterator>
	void copy_initialize(RIterator first)
	{
		initialize();
		icf_policy::fwd_over_unroll<N>::assign::no_return(initial, first);
	}

	void terminalize() { delete [] initial; }

	uinteger() { }
	uinteger(const uinteger & n) { }
	~uinteger() { }

	const uinteger & operator = (const uinteger & n)
		{ return *this; }

/*
	Useful?
*/
	reference operator [] (size_type pos) { return initial[pos]; }
	const_reference operator [] (size_type pos) const { return initial[pos]; }

	iterator begin() { return initial; }
	const_iterator cbegin() const { return initial; }
	iterator end() { return initial+length; }
	const_iterator cend() const { return initial+length; }
};

