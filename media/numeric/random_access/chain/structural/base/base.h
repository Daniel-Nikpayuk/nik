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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_CHAIN_STRUCTURAL_BASE_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_CHAIN_STRUCTURAL_BASE_H

#include"../../../../../../semiotic/numeric/processor/argument/policy/policy.h"
#include"../../../../../../semiotic/numeric/processor/parameter/policy/policy.h"

#include"../../../../../../semiotic/numeric/random_access/chain/structural/traits.h"
#include"../../../../../../semiotic/numeric/random_access/chain/functional/policy.h"

/*
	Given the unsafe nature of semiotic::chain policy here is composability instead of inheritance.

	Test against self-assignment!
*/

namespace nik
{
 namespace media
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace list
    {
     namespace structural
     {
/*
	base:
*/
	template<typename T, typename SizeType>
	class base
	{
		protected:
			typedef semiotic::numeric::processor::argument::policy<SizeType> snpa_policy;
			typedef semiotic::numeric::processor::parameter::policy<SizeType> snpp_policy;

			typedef semiotic::numeric::random_access::chain::structural::traits<SizeType> snrcs_traits;
			typedef semiotic::numeric::random_access::chain::functional::policy<SizeType> snrcf_policy;

			typedef typename snrcs_traits::base<T,SizeType> weakbase;
		public:
			typedef typename weakbase::value_type value_type;
			typedef typename weakbase::reference reference;
			typedef typename weakbase::const_reference const_reference;
			typedef typename weakbase::node node;
			typedef typename weakbase::iterator iterator;
			typedef typename weakbase::const_iterator const_iterator;
			typedef typename weakbase::size_type size_type;
		protected:
			weakbase subbase; 

			size_type length;
		public:
			base() : length(0) { subbase.initialize(); }
			base(const base & c) { subbase.copy_initialize(c.begin(), c.end()); }
			~base() { subbase.terminalize(); }
		public:
				// element access:
			reference front() { return *subbase.initial; }
			const_reference front() const { return *subbase.initial; }
			reference back() { return *-subbase.terminal; }
			const_reference back() const { return *-subbase.terminal; }
				// iterators:
			iterator begin() { return subbase.initial; }
			const_iterator begin() const { return subbase.initial; }
			const_iterator cbegin() const { return subbase.initial; }
			iterator end() { return subbase.terminal; }
			const_iterator end() const { return subbase.terminal; }
			const_iterator cend() const { return subbase.terminal; }
				// capacity:
			bool empty() const { return !length; }
			size_type size() const { return length; }
			size_type max_size() const { return snpp_policy::nume::max(); }
				// modifiers:
			void clear()
			{
				subbase.shrink();
				length=0;
			}

			iterator insert(const_iterator it, const value_type & value)
			{
				++length;
				if (it == subbase.initial)
					return subbase.initial=snrcf_policy::ptr::prepend::template
						with_return<node>(subbase.initial, value);
				else return snrcf_policy::ptr::impend::template
					with_return<node>(snpa_policy::meta::template recast<iterator>(it), value);
			}

			iterator insert(const_iterator it, value_type && value)
			{
				++length;
				if (it == subbase.initial)
					return subbase.initial=snrcf_policy::ptr::prepend::template
						with_return<node>(subbase.initial, value);
				else return snrcf_policy::ptr::impend::template
					with_return<node>(snpa_policy::meta::template recast<iterator>(it), value);
			}

			iterator insert(const_iterator it, size_type count, const value_type & value)
			{
				length+=count;
				if (it == subbase.initial)
					return subbase.initial=snrcf_policy::ptr::prepend::template
						with_return<node>(subbase.initial, count, value);
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
				if (it == subbase.initial)
					return subbase.initial=snrcf_policy::ptr::prepend::count::template
						with_return<node>(length, subbase.initial, first, last);
				else return snrcf_policy::ptr::impend::count::template
					with_return<node>(length, snpa_policy::meta::template recast<iterator>(it), first, last);
			}

			iterator erase(const_iterator it)
			{
				if (subbase.initial != subbase.terminal)
				{
					--length;
					if (it == subbase.initial)
						return subbase.initial=snrcf_policy::ptr::deject::
							with_return(subbase.initial);
					else return snrcf_policy::ptr::eject::
						with_return(snpa_policy::meta::template recast<iterator>(it));
				}
			}
/*
	As first and last *should be* iterators within the bounds of subbase.initial and subbase.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
			iterator erase(const_iterator first, const_iterator last)
			{
				if (subbase.initial != subbase.terminal)
					if (first == subbase.initial)
						return subbase.initial=snrcf_policy::ptr::deject::count::with_return(length,
							snpa_policy::meta::template recast<iterator>(first),
							snpa_policy::meta::template recast<iterator>(last));
					else return snrcf_policy::ptr::eject::count::with_return(length,
						snpa_policy::meta::template recast<iterator>(first),
						snpa_policy::meta::template recast<iterator>(last));
			}

			void push_back(const value_type & value)
			{
				++length;
				snrcf_policy::ptr::impend::template no_return<node>(subbase.terminal, value);
			}

			void push_back(value_type && value)
			{
				++length;
				snrcf_policy::ptr::impend::template no_return<node>(subbase.terminal, value);
			}

			void pop_back()
			{
				if (subbase.initial != subbase.terminal)
				{
					--length;
					snrcf_policy::ptr::eject::no_return(-subbase.terminal);
				}
			}

			void push_front(const value_type & value)
			{
				++length;
				subbase.initial=snrcf_policy::ptr::prepend::template with_return<node>(subbase.initial, value);
			}

			void push_front(value_type && value)
			{
				++length;
				subbase.initial=snrcf_policy::ptr::prepend::template with_return<node>(subbase.initial, value);
			}

			void pop_front()
			{
				if (subbase.initial != subbase.terminal)
				{
					--length;
					subbase.initial=snrcf_policy::ptr::deject::with_return(subbase.initial);
				}
			}

/*
			void resize(size_type count)
			{
				size_type cap=subbase::size();
				if (count > cap) snrcf_policy::insert(subbase, subbase.terminal, count-cap, value_type());
			}

			void resize(size_type count, const value_type & value)
			{
				size_type cap=subbase::size();
				if (count > cap) snrcf_policy::insert(subbase, subbase.terminal, count-cap, value);
			}
*/

			void swap(base & other)
			{
				iterator oinitial=other.subbase.initial, oterminal=other.subbase.terminal;
				size_type olength=other.length;

				other.subbase.initial=subbase.initial; other.subbase.terminal=subbase.terminal;
				other.length=length;

				subbase.initial=oinitial; subbase.terminal=oterminal;
				length=olength;
			}
	};
     }
    }
   }
  }
 }
}

#endif
