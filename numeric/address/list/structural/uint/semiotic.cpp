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
	Given the unsafe nature of base, policy here is designed for composability instead of inheritance.

	Test against self-assignment!
*/

struct uint
{
	typedef semiotic::base<size_type, nik::closed> base;

	typedef typename base::value_type value_type;
	typedef typename base::reference reference;
	typedef typename base::const_reference const_reference;
	typedef typename base::node node;
	typedef typename base::iterator iterator;
	typedef typename base::const_iterator const_iterator;

	size_type order;
	base subint;

	static void display(const uint & u)
	{
		iterator o=new node;
		+o=u.initial;

		base rev;
		rev.initialize();
		rev.terminal=iphs_policy::sort::reverse::closed::with_return(rev.initial, o, u.terminal);

		base num;
		num.initialize();
		num.terminal=iphs_policy::arithmetic::radix::half_digit::closing::with_return(num.initial, rev.initial, rev.terminal, 10);

		semiotic::template base<size_type, nik::closing>::print(num);

		num.terminalize();
		rev.terminalize();
		delete o;
	}

	uint(size_type u=0) : order(0)
	{
		subint.initialize();
		*subint.initial=u;
	}

	uint(const uint & l) : order(l.order) { subint.initialize_from(l.initial, l.terminal); }

	~uint() { subint.terminalize(); }

	const uint & operator = (size_type u)
	{
		subint.initial=iphs_policy::identity::clear::closing::with_return(initial, terminal);
		*subint.initial=u;

		return *this;
	}

	bool		zero() const		{ return !degree && !*subint.initial; }
};

