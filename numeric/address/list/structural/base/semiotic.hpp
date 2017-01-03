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


template<typename T>
struct base
{
	typedef typename IterStrSem::template hook<T> node;
	typedef typename IterStrSem::template const_hook<T> const_node;
	typedef typename node::pointer iterator;
	typedef typename const_node::pointer const_iterator;

	iterator initial;
	iterator terminal;

	static void display(const base & b)
	{
		typename IterProcSem::Repeat::template verb<> identity;
		typename IterProcSem::Repeat::template subject<IterAssoc::hook> mutate;

		auto print = identity.as([](iterator out)
		{
			builtin.print(*out);
			builtin.print(' ');
		});

		IterProcSem::repeat(print, b.initial, b.terminal, mutate);
		builtin.print(nik::endl);
	}

//	Assigning "terminal" first (given the possible order exchange) is semantically preferred as it
//	expects an iterator without a value, while with "initial" a value is expected when the list is non-empty.

	void initialize()
		{ initial=terminal=new node; }

	template<typename RIterator, typename ERIterator>
	void initialize(RIterator first, ERIterator last)
	{
		typename IterProcSem::Map::template verb<> assign;
		typename IterProcSem::Map::template subject<IterAssoc::hook, IterAssoc::allocate> allocate;
		typename IterProcSem::Map::template object<IterAssoc::hook> immutate;

		initial=new node;
		terminal=IterProcSem::map(assign, initial, allocate, first, last, immutate);
	}

	void terminalize()
	{
		typename IterProcSem::Repeat::template verb<> identity;
		typename IterProcSem::Repeat::template subject<IterAssoc::closed, IterAssoc::deallocate, IterAssoc::hook> deallocate;

		IterProcSem::repeat(identity, initial, terminal, deallocate);
	}

	base() { }
	base(const base & n) { }
	~base() { }

	const base & operator = (const base & n)
		{ return *this; }
};


