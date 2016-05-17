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

#ifndef NIK_SEMIOTIC_NUMERIC_RANDOM_ACCESS_VECTOR_STRUCTURAL_BASE_H
#define NIK_SEMIOTIC_NUMERIC_RANDOM_ACCESS_VECTOR_STRUCTURAL_BASE_H

#include"../../../traits/traits.h"

#include"../../../iterator/componentwise/structural/traits/traits.h"
#include"../../../iterator/componentwise/functional/policy/policy.h"

#include"../../functional/policy/policy.h"

/*
	vector:
		The policy here has taken into consideration two alternate designs: Have an "end" iterator,
		or an array length allowing near random access to the end.

			An end iterator is less memory efficient not to mention the need to relink it, but is otherwise
			more compatible with iterators for subclassing---and thus more extensible.

			An array length signifier is more efficient but less extensible.

			The policy I have settled upon is to maintain an array length. Given the inherent nature of the builtin
			pointer, as specified by an initial location and memory length, it makes more sense to extend this
			natural design.

			The burden is on the api coder of the media space to ensure code user safeties at that level as well.
*/

namespace nik
{
 namespace semiotic
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace vector
    {
     namespace structural
     {
/*
	base:
*/
	template<typename T, typename SizeType>
	struct base
	{
		typedef random_access::traits<SizeType> r_traits;
		typedef typename r_traits::container<base, T> attributes;

		typedef typename attributes::value_type value_type;
		typedef typename attributes::reference reference;
		typedef typename attributes::const_reference const_reference;
		typedef typename attributes::size_type size_type;

		typedef iterator::componentwise::structural::traits<size_type> ics_traits;
		typedef typename its_traits::array<T> node;
		typedef typename its_traits::const_array<T> const_node;
		typedef typename node::pointer iterator;
		typedef typename const_node::pointer const_iterator;

		typedef iterator::componentwise::functional::policy<size_type> icf_policy;
		typedef functional::policy<size_type> f_policy;

		iterator initial;
		size_type length;
/*
	Assigning "terminal" first (given the possible order exchange) is semantically preferred as it
	expects an iterator without a value, while with "initial" a value is expected when the vector is non-empty.
*/
		void initialize(size_type n)
		{
			initial=new node[n];
			length=n;
		}

		template<typename RIterator>
		void copy_initialize(RIterator first, size_type size)
		{
			initialize(size);
			icf_policy::fwd_over::assign::no_return(initial, first, first+size);
		}

		void terminalize() { delete [] initial; }

		base() { }
		base(const base & n) { }
		~base() { }

		const base & operator = (const base & n)
			{ return *this; }

		iterator begin() { return initial; }
		const_iterator cbegin() const { return initial; }
		iterator end() { return initial+length; }
		const_iterator cend() const { return initial+length; }
	};
     }
    }
   }
  }
 }
}

#endif
