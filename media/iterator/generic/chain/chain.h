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

#ifndef NIK_MEDIA_ITERATOR_GENERIC_CHAIN_H
#define NIK_MEDIA_ITERATOR_GENERIC_CHAIN_H

/*
	Given the unsafe nature of semiotic::chain policy here is composability instead of inheritance.

	Test against self-assignment!
*/

#include"../../../../context/context/policy/policy.h"
#include"../../../../context/media/iterator/expansionwise/policy/policy.h"
#include"../../../../semiotic/iterator/chain/chain.h"

namespace nik
{
 namespace media
 {
  namespace iterator
  {
   namespace generic
   {
/*
	chain:
*/
	template<typename T, typename SizeType>
	class chain
	{
		protected:
			typedef context::context::policy<SizeType> c_policy;
			typedef context::media::iterator::expansionwise::policy<SizeType> m_expa_policy;
			typedef semiotic::iterator::chain<T,SizeType> weakchain;
		public:
			typedef typename weakchain::value_type value_type;
			typedef typename weakchain::reference reference;
			typedef typename weakchain::const_reference const_reference;
			typedef typename weakchain::node node;
			typedef typename weakchain::iterator iterator;
			typedef typename weakchain::const_iterator const_iterator;
			typedef typename weakchain::size_type size_type;

			typedef typename weakchain::s_expa_policy s_expa_policy;
		protected:
			weakchain subchain; 

			size_type length;
		public:
			chain() : length(0) { subchain.initialize(); }
			chain(const chain & c) { subchain.copy_initialize(c.begin(), c.end()); }
			~chain() { subchain.terminalize(); }
		public:
				// element access:
			reference front() { return *subchain.initial; }
			const_reference front() const { return *subchain.initial; }
			reference back() { return *-subchain.terminal; }
			const_reference back() const { return *-subchain.terminal; }
				// iterators:
			iterator begin() { return subchain.initial; }
			const_iterator begin() const { return subchain.initial; }
			const_iterator cbegin() const { return subchain.initial; }
			iterator end() { return subchain.terminal; }
			const_iterator end() const { return subchain.terminal; }
			const_iterator cend() const { return subchain.terminal; }
				// capacity:
			bool empty() const { return !length; }
			size_type size() const { return length; }
			size_type max_size() const { return c_policy::par_num::max(); }
				// modifiers:
			void clear()
			{
				subchain.shrink();
				length=0;
			}

			iterator insert(const_iterator it, const value_type & value)
			{
				++length;
				if (it == subchain.initial)
					return subchain.initial=m_expa_policy::ptr::prepend::template
						with_return<node>(subchain.initial, value);
				else return m_expa_policy::ptr::impend::template
					with_return<node>(c_policy::arg_met::template recast<iterator>(it), value);
			}

			iterator insert(const_iterator it, value_type && value)
			{
				++length;
				if (it == subchain.initial)
					return subchain.initial=m_expa_policy::ptr::prepend::template
						with_return<node>(subchain.initial, value);
				else return m_expa_policy::ptr::impend::template
					with_return<node>(c_policy::arg_met::template recast<iterator>(it), value);
			}

			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				length+=count;
				if (it == subchain.initial)
					return subchain.initial=m_expa_policy::ptr::prepend::template
						with_return<node>(subchain.initial, count, value);
				else return m_expa_policy::ptr::impend::template
					with_return<node>(c_policy::arg_met::template recast<iterator>(it), count, value);
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
				if (it == subchain.initial)
					return subchain.initial=m_expa_policy::ptr::prepend::count::template
						with_return<node>(length, subchain.initial, first, last);
				else return m_expa_policy::ptr::impend::count::template
					with_return<node>(length, c_policy::arg_met::template recast<iterator>(it), first, last);
			}

/*
			iterator erase(const_iterator it)
			{
				if (+subchain.initial != subchain.terminal)
					return m_expa_policy::ptr::eject::with_return(c_policy::arg_met::template recast<iterator>(it));
			}
*/
/*
	As first and last *should be* iterators within the bounds of subchain.initial and subchain.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
/*
			iterator erase(const_iterator first, const_iterator last)
			{
				if (+subchain.initial != subchain.terminal)
					return m_expa_policy::ptr::eject::with_return(
						c_policy::arg_met::template recast<iterator>(first),
						c_policy::arg_met::template recast<iterator>(last));
			}

			void push_back(const value_type & value)
				{ m_expa_policy::ptr::impend::template no_return<node>(subchain.initial, value); }

			void push_back(value_type && value)
				{ m_expa_policy::ptr::impend::template no_return<node>(subchain.initial, value); }

			void pop_back()
			{
				if (+subchain.initial != subchain.terminal)
					m_expa_policy::ptr::eject::no_return(subchain.initial);
			}

			void push_front(const value_type & value)
				{ m_expa_policy::ptr::impend::template no_return<node>(subchain.initial, value); }

			void push_front(value_type && value)
				{ m_expa_policy::ptr::impend::template no_return<node>(subchain.initial, value); }

			void pop_front()
			{
				if (+subchain.initial != subchain.terminal)
					m_expa_policy::ptr::eject::no_return(subchain.initial);
			}
*/

/*
			void resize(size_type count)
			{
				size_type cap=subchain::size();
				if (count > cap) m_expa_policy::insert(subchain, subchain.terminal, count-cap, value_type());
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=subchain::size();
				if (count > cap) m_expa_policy::insert(subchain, subchain.terminal, count-cap, value);
			}
*/

/*
			void swap(chain & other)
			{
				iterator oinitial=other.subchain.initial, oterminal=other.subchain.terminal;
				other.subchain.initial=subchain.initial; other.subchain.terminal=subchain.terminal;
				subchain.initial=oinitial; subchain.terminal=oterminal;
			}

*/
	};
   }
  }

	template<typename T, typename SizeType=size_t>
	using chain=iterator::generic::chain<T, SizeType>;
 }
}

#endif
