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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_VECTOR_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_COMPONENTWISE_VECTOR_H

#include"../../../../context/policy/policy.h"
#include"../../policy/policy.h"

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes an array pointer there is no need for these additional namespaces.

	Keep in mind any method categorized here specifically does not act on the dereferenced values of the pointer,
	only the pointer itself.
*/

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
    namespace componentwise
    {
	template<typename Vector>
	struct vector
	{
		typedef typename Vector::value_type value_type;
		typedef typename Vector::reference reference;
		typedef typename Vector::const_reference const_reference;
		typedef typename Vector::node node;
		typedef typename Vector::const_node const_node;
		typedef typename Vector::iterator iterator;
		typedef typename Vector::const_iterator const_iterator;
		typedef typename Vector::size_type size_type;

		typedef context::policy<size_type> c_policy;
		typedef policy<SizeType> s_comp_policy;
/*
	Similar to resize but optimized to increase the size, and copy the existing array starting at pos.
*/
		struct grow
		{
			static void before(Vector & out, size_type length)
			{
				size_type new_length=out.length+length;
				iterator swp=new node[new_length];

				s_comp_policy::fwd_over::assign::no_return(swp+length, out.initial, out.end());
				out.terminalize();

				out.initial=swp;
				out.length=new_length;
			}

			static void after(Vector & out, size_type length)
			{
				size_type new_length=out.length+length;
				iterator swp=new node[new_length];

				s_comp_policy::fwd_over::assign::no_return(swp, out.initial, out.end());
				out.terminalize();

				out.initial=swp;
				out.length=new_length;
			}

			static void inbetween(Vector & out, size_type length, size_type offset)
			{
				size_type new_length=out.length+length;
				iterator swp=new node[new_length];

				iterator out_middle=out.initial+offset;
				iterator swp_middle=s_comp_policy::fwd_over::assign::with_return(swp, out.initial, out_middle);
				s_comp_policy::fwd_over::assign::no_return(swp_middle+length, out_middle, out.end());
				out.terminalize();

				out.initial=swp;
				out.length=new_length;
			}
		};
/*
	Similar to resize but optimized to decrease the size, and copy the existing array starting at pos.
*/
		struct shrink
		{
			static void before(Vector & out, size_type length)
			{
				size_type new_length=out.length-length;
				iterator swp=new node[new_length];

				s_comp_policy::fwd_over::assign::no_return(swp, out.initial+length, out.end());
				out.terminalize();

				out.initial=swp;
				out.length=new_length;
			}

			static void after(Vector & out, size_type length)
			{
				size_type new_length=out.length-length;
				iterator swp=new node[new_length];

				s_comp_policy::fwd_over::assign::no_return(swp, out.initial, out.initial+new_length);
				out.terminalize();

				out.initial=swp;
				out.length=new_length;
			}

			static void inbetween(Vector & out, size_type length, size_type offset)
			{
				size_type new_length=out.length+length;
				iterator swp=new node[new_length];

				iterator out_middle=out.initial+offset;
				iterator swp_middle=s_comp_policy::fwd_over::assign::with_return(swp, out.initial, out_middle);
				s_comp_policy::fwd_over::assign::no_return(swp_middle, out_middle+length, out.end());
				out.terminalize();

				out.initial=swp;
				out.length=new_length;
			}
		};
	};
    }
   }
  }
 }
}

#endif
