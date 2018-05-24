/************************************************************************************************************************
**
** Copyright 2015-2018 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
	Given the unsafe nature of semiotic::vector policy here is composability instead of inheritance.

	Test against self-assignment!
*/

template<typename T, typename SizeType>
class identity
{
	protected:
		typedef semiotic::policy<SizeType>::npa snpa_policy;
		typedef semiotic::policy<SizeType>::npp snpp_policy;

		typedef semiotic::traits<SizeType>::nrvs snrvs_traits;
		typedef semiotic::policy<SizeType>::nrvf snrvf_policy;

		typedef typename snrvs_traits::identity<T,SizeType> weakidentity;
	public:
		typedef typename weakidentity::value_type value_type;
		typedef typename weakidentity::reference reference;
		typedef typename weakidentity::const_reference const_reference;
		typedef typename weakidentity::value_type node;
		typedef typename weakidentity::iterator iterator;
		typedef typename weakidentity::const_iterator const_iterator;
		typedef typename weakidentity::size_type size_type;
	protected:
			// subidentity.length represents the capacity.
		weakidentity subidentity; 

		size_type length; // length represents the existing length.
	public:
		identity() : length(0) { subidentity.initialize(0); }
		identity(const identity & v) : length(v.length)
			{ subidentity.copy_initialize(v.subidentity.initial, v.subidentity.length); }
		~identity() { subidentity.terminalize(); }
	public:
			// element access:
		reference at(size_type pos)
		{
			try
			{
				if (0 <= pos && pos < length) return *(subidentity.initial+pos);
				else throw;
			}
			catch(...)
			{ } // haven't yet defined "nik::error"
		}

		const_reference at(size_type pos) const
		{
			try
			{
				if (0 <= pos && pos < length) return *(subidentity.initial+pos);
				else throw;
			}
			catch(...)
			{ } // haven't yet defined "nik::error"
		}

			// terminal != end

		reference operator [] (size_type pos) { return *(subidentity.initial+pos); }
		const_reference operator [] (size_type pos) const { return *(subidentity.initial+pos); }
		reference front() { return *subidentity.initial; }
		const_reference front() const { return *subidentity.initial; }
		reference back() { return *(subidentity.initial+length-1); }
		const_reference back() const { return *(subidentity.initial+length-1); }
			// iterators:
		iterator begin() { return subidentity.initial; }
		const_iterator begin() const { return subidentity.initial; }
		const_iterator cbegin() const { return subidentity.initial; }
		iterator end() { return subidentity.initial+length; }
		const_iterator end() const { return subidentity.initial+length; }
		const_iterator cend() const { return subidentity.initial+length; }
			// capacity:
		bool empty() const { return !length; }
		size_type size() const { return length; }
		size_type max_size() const { return snpp_policy::nume::max(); }

		void reserve(size_type new_cap)
		{
			if (new_cap > subidentity.length)
			{
				weakidentity tmp;
				sicv_policy::iden::grow::after(subidentity, tmp, new_cap-subidentity.length);
			}
		}

		size_type capacity() const { return subidentity.length; }

		void shrink_to_fit()
		{
			if (subidentity.length > length)
			{
				weakidentity tmp;
				sicv_policy::iden::shrink::after(subidentity, tmp, subidentity.length-length);
			}
		}

			// modifiers:
		void clear() // sufficient ?
		{
			shrink_to_fit();
			length=0;
		}

		iterator insert(const_iterator it, const value_type & value)
		{
			iterator in=snpa_policy::meta::template recast<iterator>(it);

			if (length < subidentity.length)
			{
				iterator end=subidentity.initial+length;
				sicv_policy::bwd_over::assign::no_return(end, end-1, in-1);
				*in=value;
			}
			else snrvf_policy::iden::insert::impend(subidentity, in-subidentity.initial, value);

			++length;

			return in;
		}

		iterator insert(const_iterator it, value_type && value)
		{
			iterator in=snpa_policy::meta::template recast<iterator>(it);

			if (length < subidentity.length)
			{
				iterator end=subidentity.initial+length;
				sisnpp_policy::bwd_over::assign::no_return(end, end-1, in-1);
				*in=value;
			}
			else snrvf_policy::iden::insert::impend(subidentity, in-subidentity.initial, value);

			++length;

			return in;
		}

		iterator insert(const_iterator it, size_type count, const value_type & value)
		{
			iterator in=snpa_policy::meta::template recast<iterator>(it);

			size_type new_length=length+count;
			if (new_length <= subidentity.length)
			{
				iterator end=subidentity.initial+new_length-1;
				sisnpp_policy::bwd_over::assign::no_return(end, end-1, in-1);
				sisnpp_policy::fwd_over::repeat::no_return(in, count, value);
			}
			else snrvf_policy::iden::insert::impend(subidentity, in-subidentity.initial, count, value);

			length=new_length;
		}
/*
	Included to resolve type deduction when "count" and "value" are integer constants.
	Otherwise the template version below is privileged as a better match.
*/
		iterator insert(const_iterator it, int count, const value_type & value)
			{ return insert(it, (size_type) count, value); }

		template<typename RIterator, typename ERIterator>
		iterator insert(const_iterator it, RIterator first, ERIterator last)
		{
			if (first != last)
			{
				iterator in=snpa_policy::meta::template recast<iterator>(it);

				size_type count=last-first;
				size_type new_length=length+count;
				if (new_length <= subidentity.length)
				{
					iterator end=subidentity.initial+new_length-1;
					sicv_policy::bwd_over::assign::no_return(end, end-1, in-1);
					sicv_policy::fwd_over::assign::no_return(in, first, last);
				}
				else snrvf_policy::iden::insert::impend(subidentity, in-subidentity.initial, first, last);

				length=new_length;
			}
		}

		iterator erase(const_iterator it)
		{
			if (length)
			{
				iterator in=snpa_policy::meta::template recast<iterator>(it);

				sicv_policy::fwd_over::assign::no_return(in, in+1, subidentity.initial+length);
				--length;
			}
		}
/*
	As first and last *should be* iterators within the bounds of subidentity.initial and subidentity.terminal, a comparative approach (<=)
	is preferred, but would run in linear time. As such, although the main conditional test isn't as logically robust as it
	should be, for efficiency I've left it as is (it might change in the future).
*/
		iterator erase(const_iterator first, const_iterator last)
		{
			if (first != last)
			{
				size_type count=last-first;
				if (length >= count)
				{
					iterator in=snpa_policy::meta::template recast<iterator>(first);
					iterator end=snpa_policy::meta::template recast<iterator>(last);

					sisnpp_policy::fwd_over::assign::no_return(in, end, end+count);
					length-=count;
				}
			}
		}

/*
		void push_back(const value_type & value)
		{
			if (length < subidentity.length) *(subidentity.initial+length)=value;
			else
			{
				subidentity.initial=snrvf_policy::ptr::append::template
					with_return<node>(subidentity.initial, subidentity.length, value);

				++subidentity.length;
			}

			++length;

			return in;

			++length;
			snrvf_policy::ptr::impend::template no_return<node>(subidentity.terminal, value);
		}
		void push_back(const value_type & value)
		{
			if (subidentity.size() > length)
				subidentity[length++]=value;
			else snrvf_policy::insert(subidentity, subidentity.initial+(length++), value);
		}
*/

/*
		void push_back(value_type && value)
		{
		}

		void pop_back() { if (length) --length; }

		void push_front(const value_type & value)
		{

				if (in == subidentity.initial)
					subidentity.initial=snrvf_policy::ptr::prepend::template
						with_return<node>(subidentity.initial, subidentity.length, value);
			++length;
			subidentity.initial=snrvf_policy::ptr::prepend::template with_return<node>(subidentity.initial, value);
		}

		void push_front(value_type && value)
		{
		}

		void pop_front()
		{
			if (length)
			{
				--length;
			}
		}
*/

/*
		void resize(size_type count)
		{
			size_type cap=subidentity::size();
			if (count > cap) snrvf_policy::insert(subidentity, subidentity.terminal, count-cap, value_type());
		}
		void resize(size_type count)
		{
			size_type cap=subidentity.size();
			if (count > cap) snrvf_policy::insert(subidentity, subidentity.terminal, count-cap, value_type());
			length=count;
		}

		void resize(size_type count, const value_type & value)
		{
			size_type cap=subidentity::size();
			if (count > cap) snrvf_policy::insert(subidentity, subidentity.terminal, count-cap, value);
		}
		void resize(size_type count, const value_type & value)
		{
			size_type cap=subidentity.size();
			if (count > cap) snrvf_policy::insert(subidentity, subidentity.terminal, count-cap, value);
			length=count;
		}

*/

/*
		void swap(identity & other)
		{
			iterator oinitial=other.subidentity.initial, oterminal=other.subidentity.terminal;
			size_type olength=other.length;

			other.subidentity.initial=subidentity.initial; other.subidentity.terminal=subidentity.terminal;
			other.length=length;

			subidentity.initial=oinitial; subidentity.terminal=oterminal;
			length=olength;
		}
		void swap(identity & other)
		{
			weakidentity &tmp=other.subidentity;
			&other.subidentity=&subidentity;
			&subidentity=&tmp;
		}

*/
};
