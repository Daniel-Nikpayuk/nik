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

#ifndef NIK_CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_POINTER_H
#define NIK_CONTEXT_MEDIA_ITERATOR_COMPONENTWISE_POINTER_H

#include"../../../../context/policy/policy.h"
#include"../../../../semiotic/iterator/componentwise/policy/policy.h"

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
  namespace media
  {
   namespace iterator
   {
    namespace componentwise
    {
	template<typename SizeType>
	struct pointer
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::componentwise::policy<SizeType> s_comp_policy;
/*
	Similar to resize but optimized to increase the size, and copy the existing array starting at pos.
*/
		struct upsize
		{
			template<typename WNode, typename WIterator>
			static void no_return(WIterator out, size_type length, size_type new_length, size_type offset)
			{
				WIterator in=out;
				out=new WNode[new_length];
				s_comp_policy::fwd_over::assign::no_return(out+offset, in, in+length);
				delete [] in;
			}

			template<typename WNode, typename WIterator>
			static WIterator with_return(WIterator out, size_type length, size_type new_length, size_type offset)
			{
				WIterator in=out;
				out=new WNode[new_length];
				s_comp_policy::fwd_over::assign::no_return(out+offset, in, in+length);
				delete [] in;

				return out;
			}

			struct split
			{
				template<typename WNode, typename WIterator>
				static void no_return(WIterator out, size_type length, size_type new_length, size_type offset)
				{
					WIterator in=out, mid=out+offset;
					out=new WNode[new_length];
					WIterator out1=s_comp_policy::fwd_over::assign::with_return(out, in, mid);
					s_comp_policy::fwd_over::assign::no_return(out1+(new_length-length), mid, in+length);
					delete [] in;
				}

				template<typename WNode, typename WIterator>
				static WIterator with_return(WIterator out, size_type length, size_type new_length, size_type offset)
				{
					WIterator in=out, mid=out+offset;
					out=new WNode[new_length];
					WIterator out1=s_comp_policy::fwd_over::assign::with_return(out, in, mid);
					s_comp_policy::fwd_over::assign::no_return(out1+(new_length-length), mid, in+length);
					delete [] in;

					return out;
				}
			};
		};
/*
	Similar to resize but optimized to decrease the size, and copy the existing array starting at pos.
*/
		struct downsize
		{
			template<typename WNode, typename WIterator>
			static void no_return(WIterator out, size_type new_length, size_type offset)
			{
				WIterator in0=out, in1=out+offset;
				out=new WNode[new_length];
				s_comp_policy::fwd_over::assign::no_return(out, in1, in1+new_length);
				delete [] in0;
			}

			template<typename WNode, typename WIterator>
			static WIterator with_return(WIterator out, size_type new_length, size_type offset)
			{
				WIterator in0=out, in1=out+offset;
				out=new WNode[new_length];
				s_comp_policy::fwd_over::assign::no_return(out, in1, in1+new_length);
				delete [] in0;

				return out;
			}
		};

		struct prepend
		{
			template<typename WNode, typename WIterator, typename ValueType>
			static void no_return(WIterator out, size_type length, ValueType value)
				{ *upsize::template with_return<WNode>(out, length, length+1, 1)=value; }

			template<typename WNode, typename WIterator, typename ValueType>
			static WIterator with_return(WIterator out, size_type length, ValueType value)
			{
				out=upsize::template with_return<WNode>(out, length, length+1, 1);
				*out=value;

				return out;
			}

			template<typename WNode, typename WIterator, typename ValueType>
			static void no_return(WIterator out, size_type length, size_type count, ValueType value)
			{
				out=upsize::template with_return<WNode>(out, length, length+count, count);
				s_comp_policy::fwd_over::repeat::no_return(out, count, value);
			}

			template<typename WNode, typename WIterator, typename ValueType>
			static WIterator with_return(WIterator out, size_type length, size_type count, ValueType value)
			{
				out=upsize::template with_return<WNode>(out, length, length+count, count);
				s_comp_policy::fwd_over::repeat::no_return(out, count, value);

				return out;
			}

			template<typename WNode, typename WIterator, typename RIterator, typename ERIterator>
			static void no_return(WIterator out, size_type length, size_type new_length, RIterator in, ERIterator end)
			{
				out=upsize::template with_return<WNode>(out, length, new_length, new_length-length);
				s_comp_policy::fwd_over::assign::no_return(out, in, end);
			}

			template<typename WNode, typename WIterator, typename RIterator, typename ERIterator>
			static WIterator with_return(WIterator out, size_type length, size_type new_length, RIterator in, ERIterator end)
			{
				size_type count=end-in;
				out=upsize::template with_return<WNode>(out, length, new_length, new_length-length);
				s_comp_policy::fwd_over::assign::no_return(out, in, end);

				return out;
			}
		};

		struct append
		{
		};

		struct impend
		{
			template<typename WNode, typename WIterator, typename ValueType>
			static void no_return(WIterator out, size_type length, size_type offset, ValueType value)
			{
				out=upsize::split::template with_return<WNode>(out, length, length+1, offset);
				*(out+offset)=value;
			}

			template<typename WNode, typename WIterator, typename ValueType>
			static WIterator with_return(WIterator out, size_type length, size_type offset, ValueType value)
			{
				out=upsize::split::template with_return<WNode>(out, length, length+1, offset);
				*(out+offset)=value;

				return out;
			}

			template<typename WNode, typename WIterator, typename ValueType>
			static void no_return(WIterator out, size_type length, size_type offset, size_type count, ValueType value)
			{
				out=upsize::split::template with_return<WNode>(out, length, length+count, offset);
				s_comp_policy::fwd_over::repeat::no_return(out+offset, count, value);
			}

			template<typename WNode, typename WIterator, typename ValueType>
			static WIterator with_return(WIterator out, size_type length, size_type offset, size_type count, ValueType value)
			{
				out=upsize::split::template with_return<WNode>(out, length, length+count, offset);
				s_comp_policy::fwd_over::repeat::no_return(out+offset, count, value);

				return out;
			}

			template<typename WNode, typename WIterator, typename RIterator, typename ERIterator>
			static void no_return(WIterator out, size_type length,
				size_type new_length, size_type offset, RIterator in, ERIterator end)
			{
				out=upsize::split::template with_return<WNode>(out, length, new_length, offset);
				s_comp_policy::fwd_over::assign::no_return(out+offset, in, end);
			}

			template<typename WNode, typename WIterator, typename RIterator, typename ERIterator>
			static WIterator with_return(WIterator out, size_type length,
				size_type new_length, size_type offset, RIterator in, ERIterator end)
			{
				out=upsize::split::template with_return<WNode>(out, length, new_length, offset);
				s_comp_policy::fwd_over::assign::no_return(out+offset, in, end);

				return out;
			}
		};
	};
    }
   }
  }
 }
}

#endif
