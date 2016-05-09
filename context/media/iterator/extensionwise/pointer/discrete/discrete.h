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

#ifndef NIK_CONTEXT_MEDIA_ITERATOR_EXTENSIONWISE_POINTER_DISCRETE_H
#define NIK_CONTEXT_MEDIA_ITERATOR_EXTENSIONWISE_POINTER_DISCRETE_H

#include"../../../../context/policy/policy.h"
#include"../../../../semiotic/iterator/extensionwise/policy/policy.h"

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes a linked pointer there is no need for these additional namespaces.

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
    namespace extensionwise
    {
     namespace pointer
     {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

		typedef context::policy<size_type> c_policy;
		typedef semiotic::iterator::extensionwise::policy<SizeType> s_exte_policy;

			// not really tested.
		struct prepend
		{
			template<typename WNode, typename WPointer, typename ValueType>
			static void no_return(WPointer in, ValueType value)
			{
				WPointer out=new WNode;
				*out=value;
				+out=in;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer in, ValueType value)
			{
				WPointer out=new WNode;
				*out=value;
				+out=in;

				return out;
			}
/*
	n >= 1.
			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer in, size_type n, ValueType value)
			{
				WPointer out=new WNode;
				no_return(in, s_exte_policy::fwd_over::repeat::post_test::template with_return<WNode>(out, n-1, value));
				*out=value;

				return out;
			}
*/
/*
	in != end
			template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
			static WPointer with_return(WPointer in0, RIterator in, ERIterator end)
			{
				WPointer out=new WNode;
				*out=*in;
				no_return(in0, s_exte_policy::fwd_over::assign::post_test::
					template with_return<WNode>(out, in, end));

				return out;
			}
*/
		};

			// not really tested.
		struct append
		{
			template<typename WNode, typename WPointer, typename ValueType>
			static void no_return(WPointer out, ValueType value)
			{
				out=+out=new WNode;
				*out=value;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer out, ValueType value)
			{
				out=+out=new WNode;
				*out=value;

				return out;
			}

/*
			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer in, size_type n, ValueType value)
			{
				WPointer out=new WNode;
				no_return(in, s_exte_policy::fwd_over::repeat::post_test::template with_return<WNode>(out, n-1, value));
				*out=value;

				return out;
			}
*/
		};

			// somewhat tested.
		struct impend
		{
			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer no_return(WPointer in, ValueType value)
			{
				WPointer out=new WNode;
				*out=value;
				+out=+in;
				+in=out;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer in, ValueType value)
			{
				WPointer out=new WNode;
				*out=value;
				+out=+in;
				+in=out;

				return out;
			}
/*
	n >= 1.
*/
			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer in, size_type n, ValueType value)
			{
				WPointer out=+in;
				+s_exte_policy::fwd_over::repeat::post_test::template with_return<WNode>(in, n, value)=out;

				return +in;
			}
/*
	first != last:

	Semantically nothing changes if (first == last), but a bit of unnecessary work is still done.
*/
			template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
			static WPointer with_return(WPointer in, RIterator first, ERIterator last)
			{
				WPointer out=+in, in0=in;
				while (first != last)
				{
					in0=+in0=new WNode;
					*in0=*first;
					++first;
				}

				+in0=out;

				return +in;
			}
		};

			// not really tested.
		struct deject
		{
/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
			template<typename WPointer>
			static WPointer with_return(WPointer out)
			{
				++out;
				delete -out;
				-out=0;

				return out;
			}
*/
/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
			template<typename WPointer, typename ERPointer>
			static WPointer with_return(WPointer out, ERPointer end)
			{
				-last=0;
				while ((first=+first) != last) delete (-first);
				delete (-first);

				return out;
			}
*/
		};

			// not really tested.
		struct reject
		{
/*
	Assumes 't' is the original back: detaches 't'; deletes 't'; returns the new back.

	Does not detach new back from original back resulting in a dangling pointer.
			template<typename WPointer>
			static WPointer with_return(WPointer out)
			{
				t=-t;
				delete (+t);
				+t=0;

				return out;
			}
*/
/*
	Pops everything from first to last while returning before first.

	Assumes last is the proper back.  No need for generic Iterator as you are erasing from a given structure.
			template<typename WPointer, typename ERPointer>
			static WPointer with_return(WPointer out, ERPointer end)
			{
				RPointer rtn=-first;
				+rtn=0;
				while ((first=+first) != last) delete (-first);
				delete (-first);
				delete first;

				return out;
			}
*/
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
			struct count
			{
				template<typename WPointer, typename ERPointer>
				static WPointer with_return(size_type & count, WPointer out, ERPointer end)
				{
					RPointer rtn=-first;
					+rtn=0;
					for (--count; (first=+first) != last; --count) delete (-first);
					delete (-first);
					delete first;

					return out;
				}
			};
*/
		};

			// somewhat tested.
		struct eject
		{
/*
	Erases at location of 't' and returns the new pointer at that same location.

	Assumes -t != 0 and +t != 0.
*/
			template<typename WPointer>
			static void no_return(WPointer in)
			{
				WPointer out=+(+in);
				delete +in;
				+in=out;
			}

			template<typename WPointer>
			static WPointer with_return(WPointer in)
			{
				WPointer out=+(+in);
				delete +in;
				+in=out;

				return +in;
			}
/*
	Erases everything from first to last and returns the new pointer at that same location where first was.

	No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename WPointer, typename EWPointer>
			static void no_return(WPointer in, EWPointer end)
			{
				s_exte_policy::ptr::clear::no_return(+in, end);
				+in=end;
			}

			template<typename WPointer, typename EWPointer>
			static WPointer with_return(WPointer in, EWPointer end)
			{
				s_exte_policy::ptr::clear::no_return(+in, end);
				+in=end;

				return +in;
			}
		};

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
		};
	};
     }
    }
   }
  }
 }
}

#endif
