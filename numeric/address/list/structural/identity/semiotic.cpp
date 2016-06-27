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

template<typename T>
struct identity
{
	protected:
		typedef semiotic::base<T> base;
	public:
		typedef typename base::value_type value_type;
		typedef typename base::reference reference;
		typedef typename base::const_reference const_reference;
		typedef typename base::node node;
		typedef typename base::iterator iterator;
		typedef typename base::const_iterator const_iterator;
		typedef typename base::size_type size_type;
	protected:
			// subidentity.initial is interpreted to be "before initial".
			// subidentity.terminal is interpreted to be "this terminal".
		base subidentity;
	public:
//		identity() { fs_policy::identity::initialize::no_return(subidentity); }

//		identity(const identity & l) { fs_policy::identity::copy::no_return(subidentity, l); }

		~identity() { /*subidentity.terminalize()*/; }
	public:

// element access:

		reference	front()			{ return *+subidentity.initial; }
		const_reference	front() const		{ return *+subidentity.initial; }

// iterators:

		iterator	before_begin()		{ return subidentity.initial; }
		const_iterator	before_begin() const	{ return subidentity.initial; }
		const_iterator	cbefore_begin() const	{ return subidentity.initial; }
		iterator	begin()			{ return +subidentity.initial; }
		const_iterator	begin() const		{ return +subidentity.initial; }
		const_iterator	cbegin() const		{ return +subidentity.initial; }
		iterator	end()			{ return subidentity.terminal; }
		const_iterator	end() const		{ return subidentity.terminal; }
		const_iterator	cend() const		{ return subidentity.terminal; }

// capacity:

		bool		empty() const		{ return +subidentity.initial == subidentity.terminal; }
//		size_type max_size() const { return wufm_policy::unit::max(); }

// modifiers:

		void clear()
		{
			iphs_policy::discrete::clear::no_return(subidentity.initial+1, subidentity.terminal);
			+subidentity.initial=subidentity.terminal;
		}
};

/*

		iterator insert_after(const_iterator it, const value_type & value)
		{
			return snrlf_policy::ptr::impend::template
				with_return<node>(snpa_policy::meta::template recast<iterator>(it), value);
		}

		iterator insert_after(const_iterator it, value_type && value)
		{
			return snrlf_policy::ptr::impend::template
				with_return<node>(snpa_policy::meta::template recast<iterator>(it), value);
		}

		iterator insert_after(const_iterator it, size_type count, const value_type & value)
		{
			return snrlf_policy::ptr::impend::template
				with_return<node>(snpa_policy::meta::template recast<iterator>(it), count, value);
		}
*/
/*
	Included to resolve type deduction when "count" and "value" are integer constants. Otherwise the template version is privileged
	as a better match.
*/
/*
		iterator insert_after(const_iterator it, int count, const value_type & value)
			{ return insert_after(it, (size_type) count, value); }

		template<typename RIterator, typename ERIterator>
		iterator insert_after(const_iterator it, RIterator first, ERIterator last)
		{
			return snrlf_policy::ptr::impend::template
				with_return<node>(snpa_policy::meta::template recast<iterator>(it), first, last);
		}

		iterator erase_after(const_iterator it)
		{
			if (+subidentity.initial != subidentity.terminal)
				return snrlf_policy::ptr::eject::with_return(snpa_policy::meta::template recast<iterator>(it));
		}
*/
/*
	As first and last *should be* iterators within the bounds of subidentity.initial and subidentity.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
/*
		iterator erase_after(const_iterator first, const_iterator last)
		{
			if (+subidentity.initial != subidentity.terminal)
				return snrlf_policy::ptr::eject::with_return(
					snpa_policy::meta::template recast<iterator>(first),
					snpa_policy::meta::template recast<iterator>(last));
		}

		void push_front(const value_type & value)
			{ snrlf_policy::ptr::impend::template no_return<node>(subidentity.initial, value); }

		void push_front(value_type && value)
			{ snrlf_policy::ptr::impend::template no_return<node>(subidentity.initial, value); }

		void pop_front()
		{
			if (+subidentity.initial != subidentity.terminal)
				snrlf_policy::ptr::eject::no_return(subidentity.initial);
		}
*/

/*
		void resize(size_type count)
		{
			size_type cap=subidentity::size();
			if (count > cap) snrlf_policy::insert(subidentity, subidentity.terminal, count-cap, value_type());
		}

		void resize(size_type count, const value_type & value)
		{
			size_type cap=subidentity::size();
			if (count > cap) snrlf_policy::insert(subidentity, subidentity.terminal, count-cap, value);
		}
*/
/*
		void swap(identity & other)
		{
			iterator oinitial=other.subidentity.initial, oterminal=other.subidentity.terminal;
			other.subidentity.initial=subidentity.initial; other.subidentity.terminal=subidentity.terminal;
			subidentity.initial=oinitial; subidentity.terminal=oterminal;
		}
*/

