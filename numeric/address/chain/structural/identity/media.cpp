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
	chain:
		Choice of the word "chain" was hard to settle on. Was tempted to use the word "cascade" as "chain"
		is overused, but I've decided on it in the sense of a LISP chain. In that way it is a singly linked chain.

		The policy here has taken into consideration two alternate designs: Have an "end" iterator,
		or a null iterator signifying the end.

			An end iterator is less memory efficient not to mention the need to relink it, but is otherwise
			more compatible with iterators for subclassing---and thus more extensible.

			A null iterator signifier is more efficient but less extensible.

			The policy I have settled upon is to maintain an "end" iterator. As this is a weak generic class,
			keep in mind it can always be composed or inherited to reinterpret the end iterator to be a "last"
			iterator---one which has a meaningful dereferentiable value. The added value is in being able to
			append to this chain without having to find the end iterator each time.

		Policy also needed to be decided on whether to leave "+terminal" uninitialized (saving cycles),
		or to safely default its initialization to zero.

			I have weighed it carefully. For example the chain_pointer class does not initialize which is inherently
			unsafe, but within the context and semiotic spaces the default policy is for the burden of safety to be
			the responsibility of the api coder. It is not unnatural for that same conclusion to be drawn here.
			The other consideration is that the burden of safety within the media space is given to the api coder.

			The expectation is that the code user does not have to worry about such safeties, but as they have access
			to the the chain::iterator they have access to some of the potentially unsafe features. I have decided
			to maintain the "uninitialized" default policy for the reason that initialize(), terminalize(), copy_initialize(),
			have been well thought out grammar points in how they relate to each other.

			The burden is on the api coder of the media space to ensure code user safeties at that level as well.
*/

/*
	Given the unsafe nature of semiotic::chain policy here is composability instead of inheritance.

	Test against self-assignment!
*/

template<typename T, typename SizeType>
class identity
{
	protected:
		typedef semiotic::policy<SizeType>::npa snpa_policy;
		typedef semiotic::policy<SizeType>::npp snpp_policy;

		typedef semiotic::traits<SizeType>::nrcs snrcs_traits;
		typedef semiotic::policy<SizeType>::nrcf snrcf_policy;

		typedef typename snrcs_traits::identity<T,SizeType> weakidentity;
	public:
		typedef typename weakidentity::value_type value_type;
		typedef typename weakidentity::reference reference;
		typedef typename weakidentity::const_reference const_reference;
		typedef typename weakidentity::node node;
		typedef typename weakidentity::iterator iterator;
		typedef typename weakidentity::const_iterator const_iterator;
		typedef typename weakidentity::size_type size_type;
	protected:
		weakidentity subidentity; 

		size_type length;
	public:
		identity() : length(0) { subidentity.initialize(); }
		identity(const identity & c) { subidentity.copy_initialize(c.begin(), c.end()); }
		~identity() { subidentity.terminalize(); }
	public:
			// element access:
		reference front() { return *subidentity.initial; }
		const_reference front() const { return *subidentity.initial; }
		reference back() { return *-subidentity.terminal; }
		const_reference back() const { return *-subidentity.terminal; }
			// iterators:
		iterator begin() { return subidentity.initial; }
		const_iterator begin() const { return subidentity.initial; }
		const_iterator cbegin() const { return subidentity.initial; }
		iterator end() { return subidentity.terminal; }
		const_iterator end() const { return subidentity.terminal; }
		const_iterator cend() const { return subidentity.terminal; }
			// capacity:
		bool empty() const { return !length; }
		size_type size() const { return length; }
		size_type max_size() const { return snpp_policy::nume::max(); }
			// modifiers:
		void clear()
		{
			subidentity.shrink();
			length=0;
		}

		iterator insert(const_iterator it, const value_type & value)
		{
			++length;
			if (it == subidentity.initial)
				return subidentity.initial=snrcf_policy::ptr::prepend::template
					with_return<node>(subidentity.initial, value);
			else return snrcf_policy::ptr::impend::template
				with_return<node>(snpa_policy::meta::template recast<iterator>(it), value);
		}

		iterator insert(const_iterator it, value_type && value)
		{
			++length;
			if (it == subidentity.initial)
				return subidentity.initial=snrcf_policy::ptr::prepend::template
					with_return<node>(subidentity.initial, value);
			else return snrcf_policy::ptr::impend::template
				with_return<node>(snpa_policy::meta::template recast<iterator>(it), value);
		}

		iterator insert(const_iterator it, size_type count, const value_type & value)
		{
			length+=count;
			if (it == subidentity.initial)
				return subidentity.initial=snrcf_policy::ptr::prepend::template
					with_return<node>(subidentity.initial, count, value);
			else return snrcf_policy::ptr::impend::template
				with_return<node>(snpa_policy::meta::template recast<iterator>(it), count, value);
		}
/*
	Included to resolve type deduction when "count" and "value" are integer constants. Otherwise the template version is privileged
	as a better match.
*/
		iterator insert(const_iterator it, int count, const value_type & value)
			{ return insert(it, (size_type) count, value); }

		template<typename RIterator, typename ERIterator>
		iterator insert(const_iterator it, RIterator first, ERIterator last)
		{
			if (it == subidentity.initial)
				return subidentity.initial=snrcf_policy::ptr::prepend::count::template
					with_return<node>(length, subidentity.initial, first, last);
			else return snrcf_policy::ptr::impend::count::template
				with_return<node>(length, snpa_policy::meta::template recast<iterator>(it), first, last);
		}

		iterator erase(const_iterator it)
		{
			if (subidentity.initial != subidentity.terminal)
			{
				--length;
				if (it == subidentity.initial)
					return subidentity.initial=snrcf_policy::ptr::deject::
						with_return(subidentity.initial);
				else return snrcf_policy::ptr::eject::
					with_return(snpa_policy::meta::template recast<iterator>(it));
			}
		}
/*
	As first and last *should be* iterators within the bounds of subidentity.initial and subidentity.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
		iterator erase(const_iterator first, const_iterator last)
		{
			if (subidentity.initial != subidentity.terminal)
				if (first == subidentity.initial)
					return subidentity.initial=snrcf_policy::ptr::deject::count::with_return(length,
						snpa_policy::meta::template recast<iterator>(first),
						snpa_policy::meta::template recast<iterator>(last));
				else return snrcf_policy::ptr::eject::count::with_return(length,
					snpa_policy::meta::template recast<iterator>(first),
					snpa_policy::meta::template recast<iterator>(last));
		}

		void push_back(const value_type & value)
		{
			++length;
			snrcf_policy::ptr::impend::template no_return<node>(subidentity.terminal, value);
		}

		void push_back(value_type && value)
		{
			++length;
			snrcf_policy::ptr::impend::template no_return<node>(subidentity.terminal, value);
		}

		void pop_back()
		{
			if (subidentity.initial != subidentity.terminal)
			{
				--length;
				snrcf_policy::ptr::eject::no_return(-subidentity.terminal);
			}
		}

		void push_front(const value_type & value)
		{
			++length;
			subidentity.initial=snrcf_policy::ptr::prepend::template with_return<node>(subidentity.initial, value);
		}

		void push_front(value_type && value)
		{
			++length;
			subidentity.initial=snrcf_policy::ptr::prepend::template with_return<node>(subidentity.initial, value);
		}

		void pop_front()
		{
			if (subidentity.initial != subidentity.terminal)
			{
				--length;
				subidentity.initial=snrcf_policy::ptr::deject::with_return(subidentity.initial);
			}
		}

/*
		void resize(size_type count)
		{
			size_type cap=subidentity::size();
			if (count > cap) snrcf_policy::insert(subidentity, subidentity.terminal, count-cap, value_type());
		}

		void resize(size_type count, const value_type & value)
		{
			size_type cap=subidentity::size();
			if (count > cap) snrcf_policy::insert(subidentity, subidentity.terminal, count-cap, value);
		}
*/

		void swap(identity & other)
		{
			iterator oinitial=other.subidentity.initial, oterminal=other.subidentity.terminal;
			size_type olength=other.length;

			other.subidentity.initial=subidentity.initial; other.subidentity.terminal=subidentity.terminal;
			other.length=length;

			subidentity.initial=oinitial; subidentity.terminal=oterminal;
			length=olength;
		}
};

