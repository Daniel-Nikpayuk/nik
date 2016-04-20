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

#ifndef NIK_SEMIOTIC_ITERATOR_CHAIN_H
#define NIK_SEMIOTIC_ITERATOR_CHAIN_H

#include"../../../context/context/node/node.h"
#include"../../../context/semiotic/iterator/expansionwise/policy/policy.h"

#include"../traits/traits.h"

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
			grow(), shrink() have been well thought out grammar points in how they relate to each other.

			The burden is on the api coder of the media space to ensure code user safeties at that level as well.
*/

namespace nik
{
 namespace semiotic
 {
  namespace iterator
  {
/*
	chain:
*/
	template<typename T, typename SizeType>
	struct chain
	{
		typedef traits::container<chain, T, SizeType> attributes;
		typedef typename attributes::value_type value_type;
		typedef typename attributes::reference reference;
		typedef typename attributes::const_reference const_reference;
		typedef context::context::link<T, SizeType> node;
		typedef context::context::const_link<T, SizeType> const_node;
		typedef typename node::pointer iterator;
		typedef typename const_node::pointer const_iterator;
		typedef SizeType size_type;

		typedef context::semiotic::iterator::expansionwise::policy<size_type> s_expa_policy;

		iterator initial;
		iterator terminal;
/*
	Assigning "terminal" first (given the possible order exchange) is semantically preferred as it
	expects an iterator without a value, while with "initial" a value is expected when the chain is non-empty.
*/
		void initialize()
			{ initial=terminal=new node(); }

		template<typename RIterator, typename ERIterator>
		void prepend(RIterator first, ERIterator last)
			{ s_expa_policy::bwd_over::assign::post_test::template no_return<node>(initial, last, first); }

		template<typename RIterator, typename ERIterator>
		void append(RIterator first, ERIterator last)
			{ s_expa_policy::fwd_over::assign::template no_return<node>(terminal, first, last); }

		void shrink()
			{ s_expa_policy::ptr::clear::no_return(initial, terminal); }

		template<typename RIterator, typename ERIterator>
		void copy_initialize(RIterator first, ERIterator last)
		{
			initialize();
			append(first, last);
		}

		void terminalize()
		{
			shrink();
			delete terminal;
		}

		chain() { }
		chain(const chain & n) { }
		~chain() { }

		const chain & operator = (const chain & n)
			{ return *this; }

		iterator begin() { return initial; }
		const_iterator cbegin() const { return initial; }
		iterator end() { return terminal; }
		const_iterator cend() const { return terminal; }
	};
  }
 }
}

#endif
