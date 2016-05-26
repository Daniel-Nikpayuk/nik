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

struct identity
{
	typedef semiotic::size_type size_type;
	typedef iterator;
	typedef const_iterator;

	typedef typename is_traits::bit<T> memory;
	typedef typename is_traits::const_bit<T> const_memory;
	typedef typename memory::pointer iterator;
	typedef typename const_memory::pointer const_iterator;

	size_type value;

	void initialize(size_type v) { value=v; }

/*
	template<typename RIterator>
	void copy_initialize(RIterator first, size_type size)
	{
		initialize(size);
		icf_policy::fwd_over::assign::no_return(initial, first, first+size);
	}
*/

	void terminalize() { value=0; }

	identity() { }
	identity(const identity & i) { }
	~identity() { }

	const identity & operator = (const identity & i)
		{ return *this; }

	iterator begin() { return iterator(value, 1); }
	const_iterator cbegin() const { return const_iterator(value, 1); }
	iterator end() { return iterator(value, max_power); }
	const_iterator cend() const { return iterator(value, max_power); }
};

#endif
