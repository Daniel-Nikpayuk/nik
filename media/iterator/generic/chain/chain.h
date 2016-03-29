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
#include"../../../../context/semiotic/iterator/extensionwise/policy/policy.h"
#include"../../../../context/media/iterator/extensionwise/policy/policy.h"
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
			typedef context::semiotic::iterator::extensionwise::policy<SizeType> s_exte_policy;
			typedef context::media::iterator::extensionwise::policy<SizeType> m_exte_policy;
			typedef semiotic::iterator::chain<T,SizeType> weakchain;
		public:
			typedef typename subchain::value_type value_type;
			typedef typename subchain::reference reference;
			typedef typename subchain::const_reference const_reference;
			typedef typename subchain::iterator iterator;
			typedef typename subchain::const_iterator const_iterator;
			typedef typename subchain::size_type size_type;
		protected:
			weakchain subchain; 

			size_type length;
		public:
			chain() : length(0) { subchain.initialize(); }
			~chain() { subchain.terminalize(); }
		public:
				// element access:
			reference front() { return *subchain.initial; }
			const_reference front() const { return *subchain.initial; }
			reference back() { return **-subchain.terminal; }
			const_reference back() const { return **-subchain.terminal; }
				// iterators:
			iterator begin() { return subchain.initial; }
			const_iterator begin() const { return subchain.initial; }
			const_iterator cbegin() const { return subchain.initial; }
			iterator end() { return subchain.terminal; }
			const_iterator end() const { return subchain.terminal; }
			const_iterator cend() const { return subchain.terminal; }
				// capacity:
			bool empty() const { return length; }
			size_type size() const { return length; }
			size_type max_size() const { return c_policy::par_num::max(); }
				// modifiers:
			void clear() { subchain.shrink(); }
/*
			iterator insert(const_iterator it, const value_type & value)
			{
				++length;
				if (it == subchain.initial)
					return subchain.initial=s_exte_policy::bid_chai::prepend::with_return(subchain.initial, value);
				else return s_exte_policy::bid_chai::impend::with_return(it, value);
			}

			iterator insert(const_iterator it, value_type && value)
			{
				++length;
				if (it == subchain.initial)
					return subchain.initial=s_exte_policy::bid_chai::prepend::with_return(subchain.initial, value);
				else return s_exte_policy::bid_chai::impend::with_return(it, value);
			}

			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				length+=count;
				if (it == subchain.initial)
				{
					-subchain.initial=new weakchain::iterator();
					return subchain.initial=s_exte_policy::bwd_over::repeat::with_return(-subchain.initial, count, value);
				}
				else
				{
					weakchain::iterator i=new weakchain::iterator(),
						t=s_exte_policy::fwd_over::repeat::with_return(, count, value);
					return s_exte_policy::impend::with_return(it, i, t);
				}
			}
*/
/*
	Included to resolve type deduction when "count" and "value" are integer constants. Otherwise the template version is privileged
	as a better match.
*/
/*
			iterator insert(const_iterator it, int count, const value_type & value)
				{ return insert(it, (size_type) count, value); }

			template<typename RIterator, typename ERIterator>
			iterator insert(const_iterator it, InputIterator first, InputIterator last)
			{
				if (first != last)
				{
					if (it == subchain.initial)
					{
						-subchain.initial=new weakchain::iterator();
						return subchain.initial=s_exte_policy::bid_chai::
							prepend::count::with_return(length, -subchain.initial, first, last);
					}
					else return s_exte_policy::bid_chai::impend::count::with_return(length, it, first, last);
				}
			}

			iterator erase(const_iterator it)
			{
				if (subchain.initial != subchain.terminal)
				{
					--length;
					if (it == subchain.initial)
						return subchain.initial=s_exte_policy::bid_chai::deject::with_return(subchain.initial);
					else return s_exte_policy::bid_chai::eject::with_return(it);
				}
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
				if (subchain.initial != subchain.terminal && first != last)
				{
					if (first == subchain.initial) return subchain.initial=
						s_exte_policy::bid_chai::deject::count::with_return(length, first, last);
					else return s_exte_policy::bid_chai::eject::count::with_return(length, first, last);
				}
			}

			void push_back(const value_type & value)
			{
				++length;
				if (subchain.initial == subchain.terminal)
					subchain.initial=s_exte_policy::bid_chai::append::with_return(subchain.initial, value);
				else s_exte_policy::bid_chai::append::no_return(subchain.terminal, value);
			}

			void push_back(value_type && value)
			{
				++length;
				if (subchain.initial == subchain.terminal)
					subchain.initial=s_exte_policy::bid_chai::append::with_return(subchain.initial, value);
				else s_exte_policy::bid_chai::append::no_return(subchain.terminal, value);
			}

			void pop_back()
			{
				if (subchain.initial != subchain.terminal)
				{
					--length;
					if (+subchain.initial == subchain.terminal)
						subchain.initial=s_exte_policy::bid_chai::deject::with_return(subchain.initial);
					else s_exte_policy::bid_chai::eject::no_return(-subchain.terminal);
				}
			}

			void push_front(const value_type & value)
			{
				++length;
				subchain.initial=s_exte_policy::bid_chai::prepend::with_return(subchain.initial, value);
			}

			void push_front(value_type && value)
			{
				++length;
				subchain.initial=s_exte_policy::bid_chai::prepend::with_return(subchain.initial, value);
			}

			void pop_front()
			{
				if (subchain.initial != subchain.terminal)
				{
					--length;
					subchain.initial=s_exte_policy::bid_chai::deject::with_return(subchain.initial);
				}
			}

			void resize(size_type count)
			{
				size_type cap=subchain::size();
				if (count > cap) s_exte_policy::insert(subchain, subchain.terminal, count-cap, value_type());
				length=count;
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=subchain::size();
				if (count > cap) s_exte_policy::insert(subchain, subchain.terminal, count-cap, value);
				length=count;
			}

			void swap(chain & other)
			{
				weakchain::iterator oinitial=other.initial, oterminal=other.terminal;
				other.initial=subchain.initial; other.terminal=subchain.terminal;
				subchain.initial=oinitial; subchain.terminal=oterminal;

				size_type olength=other.length;
				other.length=length;
				length=olength;
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
