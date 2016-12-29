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


#define initialize_interval(name, label) \
template<typename RIterator, typename ERIterator> \
void initialize_from_##label(RIterator first, ERIterator last) \
{ \
	initial=new node; \
	terminal=iphs_policy::zip::assign::label::as::name::template with_return<node>(initial, first, last); \
}


template<typename T>
struct base
{
	typedef typename gsm_traits::template container<base, T> attributes;

	typedef typename attributes::value_type value_type;
	typedef typename attributes::reference reference;
	typedef typename attributes::const_reference const_reference;
	typedef typename attributes::size_type size_type;

	typedef typename iss_traits::template hook<T> node;
	typedef typename iss_traits::template const_hook<T> const_node;
	typedef typename node::pointer iterator;
	typedef typename const_node::pointer const_iterator;

	static constexpr size_type interval_type=IntervalType;

	iterator initial;
	iterator terminal;

	static void print(const base & b)
	{
		for (iterator k=b.initial; k != b.terminal; ++k)
		{
			builtin.print(*k);
			builtin.print(' ');
		}

		builtin.print(endl);
	}

//	Assigning "terminal" first (given the possible order exchange) is semantically preferred as it
//	expects an iterator without a value, while with "initial" a value is expected when the list is non-empty.

	void initialize()
		{ initial=terminal=new node; }

	template<typename RIterator, typename ERIterator>
	void initialize_from(RIterator first, ERIterator last)
	{
		initial=new node;
		terminal=iphs_policy::zip::assign::closing::template with_return<node>(initial, first, last);
	}

	initialize_interval(closing, closed)
	initialize_interval(closing, opening)
	initialize_interval(closing, open)

	void terminalize()
		{ iphs_policy::identity::clear::closed::no_return(initial, terminal); }

	base() { }
	base(const base & n) { }
	~base() { }

	const base & operator = (const base & n)
		{ return *this; }
};


#undef initialize_interval


