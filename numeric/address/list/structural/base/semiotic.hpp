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


/*
	Classified here because custom initializations are inherently unsafe: Could lead to memory leaks.

struct initialize
{
	struct disjoint
	{
		template<typename WList>
		static void no_return(WList & out)
		{
			out.initial=new typename WList::node;
			out.terminal=new typename WList::node;
			+out.initial=out.terminal;
		}
	};
};
*/

/*
	Classified here because custom initializations are inherently unsafe: Could lead to memory leaks.

struct copy
{
	struct initialize
	{
		template<typename WList, typename RList>
		static void no_return(WList & out, const RList & in)
		{
			out.initialize();
			out.terminal=ief_policy::fwd_over::assign::template
				with_return<typename WList::node>(out.terminal, in.initial, in.terminal);
		}

		struct prepost
		{
			template<typename WList, typename RIterator, typename ERIterator>
			static void no_return(WList & out, RIterator in, ERIterator end)
			{
				out.initialize();
				out.terminal=ief_policy::disc::copy::before::template
					with_return<typename WList::node>(out.terminal, in, end);
			}
		};

		struct disjoint
		{
			template<typename WList, typename RList>
			static void no_return(WList & out, const RList & in)
			{
				initialize::disjoint::no_return(out);
				out.terminal=ief_policy::fwd_over::assign::template
					with_return<typename WList::node>(out.terminal, +in.initial, in.terminal);
			}
		};
	};

	struct shallow
	{
		template<typename WList, typename RList>
		static void no_return(WList & out, const RList & in)
		{
			out.initial=in.initial;
			out.terminal=in.terminal;
		}
	};
};
*/


template<typename T>
struct base
{
	typedef T value_type;

	typedef typename IterStrSem::template hook<T> node;
	typedef typename IterStrSem::template const_hook<T> const_node;
	typedef typename node::pointer iterator;
	typedef typename const_node::pointer const_iterator;

	typename IterProcSem::Repeat::template verb<> identity;
	typename IterProcSem::Morph::template verb<> assign;
	typename IterProcSem::Map::template verb<> copy;

	iterator initial;
	iterator terminal;

	static void display(const base & b)
	{
		typename IterProcSem::Repeat::template subject<IterAssoc::hook> mutate;

		auto print = IterProcSem::Repeat::template verb<>::as
		(
			[] (iterator out) { builtin.print(*out); builtin.print(' '); }
		);

		IterProcSem::repeat(print, b.initial, b.terminal, mutate);
		builtin.print(nik::endl);
	}

//	Assigning "terminal" first (given the possible order exchange) is semantically preferred as it
//	expects an iterator without a value, while with "initial" a value is expected when the list is non-empty.

	void initialize()
		{ initial = terminal = new node; }

	void terminalize()
	{
		typename IterProcSem::Repeat::template subject<IterAssoc::closed, IterAssoc::deallocate, IterAssoc::hook> deallocate;

		initial = IterProcSem::repeat(identity, initial, terminal, deallocate);
	}

	base() { }
	base(const base & n) { }
	~base() { }

	const base & operator = (const base & n)
		{ return *this; }

// back:

	void push_back(const value_type & value)
	{
		*terminal = value;
		terminal = +terminal = new node;
	}

	void repeat_back(size_type n, const value_type & value)
	{
		auto constant = identity.as( [value](iterator out){ *out = value; } );
		typename IterProcSem::Repeat::template subject<IterAssoc::hook, IterAssoc::allocate> allocate;

		terminal = IterProcSem::repeat(constant, terminal, allocate, n);
	}

	void assign_back(const value_type & first, const value_type & last)
	{
		typename IterProcSem::Morph::template subject<IterAssoc::hook, IterAssoc::allocate> allocate;
		typename IterProcSem::Morph::template object<> normal;

		terminal = IterProcSem::morph(assign, terminal, allocate, first, last, normal);
	}

	template<typename RIterator, typename ERIterator>
	void copy_back(RIterator first, ERIterator last)
	{
		typename IterProcSem::Map::template subject<IterAssoc::hook, IterAssoc::allocate> allocate;
		typename IterProcSem::Map::template object<IterAssoc::hook> immutate;

		terminal = IterProcSem::map(copy, terminal, allocate, first, last, immutate);
	}

// front:

	void push_front(const value_type & value)
	{
		iterator tmp = initial;
		IterProcSem::noderize(initial, value);
		+initial = tmp;
	}

	void repeat_front(size_type n, const value_type & value)
	{
		auto constant = identity.as( [value](iterator out){ *out = value; } );
		typename IterProcSem::Repeat::template subject
		<
			IterAssoc::hook,
			IterAssoc::allocate,
			IterAssoc::opening,
			IterAssoc::backward

		> allocate;

		initial = IterProcSem::repeat(constant, initial, allocate, n);
	}

	void assign_front(const value_type & first, const value_type & last)
	{
		typename IterProcSem::Morph::template subject<IterAssoc::hook, IterAssoc::allocate, IterAssoc::opening> allocate;
		typename IterProcSem::Morph::template object<EnumAssoc::open> normal;

		iterator tmp = initial;
		IterProcSem::noderize(initial, first);
		+ IterProcSem::morph(assign, initial, allocate, first, last, normal) = tmp;
	}

	template<typename RIterator, typename ERIterator>
	void copy_front(RIterator first, ERIterator last)
	{
		typename IterProcSem::Map::template subject<IterAssoc::hook, IterAssoc::allocate, IterAssoc::opening> allocate;
		typename IterProcSem::Map::template object<IterAssoc::hook, IterAssoc::open> immutate;

		iterator tmp = initial;
		IterProcSem::noderize(initial, first);
		+ IterProcSem::map(copy, initial, allocate, first, last, immutate) = tmp;
	}
};


