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

#ifndef NIK_CONTEXT_MEDIA_ITERATOR_EXTENSIONWISE_LIST_IDENTITY_H
#define NIK_CONTEXT_MEDIA_ITERATOR_EXTENSIONWISE_LIST_IDENTITY_H

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes a linked pointer there is no need for these additional namespaces.
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
     namespace list
     {
	template<typename SizeType>
	struct identity
	{
		typedef SizeType size_type;

		typedef semiotic::iterator::extensionwise::pointer::policy<size_type> sitp_policy;
		typedef semiotic::iterator::extensionwise::list::policy<size_type> sitl_policy;

		struct insert
		{
			// prepend:

				// not really tested.

			template<typename WList, typename ValueType>
			static void prepend(WList & out, ValueType value)
			{
				typename WList::iterator in=out.initial;
				out.initial=new typename WList::node;
				+out.initial=in;
				*out.initial=value;
			}
/*
	n >= 1.
*/
			template<typename WList, typename ValueType>
			static void prepend(WList & out, size_type n, ValueType value)
			{
				typename WList::iterator in=out.initial;
				out.initial=new typename WList::node;
				*out.initial=value;
				+sitp_policy::fwd_over::repeat::post_test::template
					with_return<typename WList::node>(out.initial, n-1, value)=in;
			}
/*
	in != end
*/
			template<typename WList, typename RIterator, typename ERIterator>
			static void prepend(WList & out, RIterator in, ERIterator end)
			{
				typename WList::iterator tmp=out.initial;
				out.initial=new typename WList::node;
				*out.initial=*in;
				+sitp_policy::disc::copy::before::template
					with_return<typename WList::node>(out.initial, in, end)=tmp;
			}

			// append:

				// not really tested.

			template<typename WList, typename ValueType>
			static void append(WList & out, ValueType value)
			{
				out.terminal=+out.terminal=new typename WList::node;
				*out.terminal=value;
			}

			template<typename WList, typename ValueType>
			static void append(WList & out, size_type n, ValueType value)
			{
				out.terminal=sitp_policy::fwd_over::repeat::post_test::template
					with_return<typename WList::node>(out.terminal, n, value);
			}

			// impend:

				// somewhat tested.

			template<typename WNode, typename WPointer, typename ValueType>
			static void impend(WPointer in, ValueType value)
			{
				WPointer out=new WNode;
				*out=value;
				+out=+in;
				+in=out;
			}
/*
	n >= 1.
*/
			template<typename WNode, typename WPointer, typename ValueType>
			static void impend(WPointer in, size_type n, ValueType value)
			{
				WPointer out=+in;
				+s_exte_policy::fwd_over::repeat::post_test::template with_return<WNode>(in, n, value)=out;
			}
/*
	first != last:

	Semantically nothing changes if (first == last), but a bit of unnecessary work is still done.
*/
			template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
			static void impend(WPointer in, RIterator first, ERIterator last)
			{
				WPointer out=+in, in0=in;
				while (first != last)
				{
					in0=+in0=new WNode;
					*in0=*first;
					++first;
				}

				+in0=out;
			}
		};

		struct erase
		{
			// deject:

				// not really tested.

/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
			template<typename WPointer>
			static void deject(WPointer out)
			{
				++out;
				delete -out;
				-out=0;
			}
*/
/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
			template<typename WPointer, typename ERPointer>
			static void deject(WPointer out, ERPointer end)
			{
				-last=0;
				while ((first=+first) != last) delete (-first);
				delete (-first);
			}
*/

			// reject:

				// not really tested.

/*
	Assumes 't' is the original back: detaches 't'; deletes 't'; returns the new back.

	Does not detach new back from original back resulting in a dangling pointer.
			template<typename WPointer>
			static void reject(WPointer out)
			{
				t=-t;
				delete (+t);
				+t=0;
			}
*/
/*
	Pops everything from first to last while returning before first.

	Assumes last is the proper back.  No need for generic Iterator as you are erasing from a given structure.
			template<typename WPointer, typename ERPointer>
			static void reject(WPointer out, ERPointer end)
			{
				RPointer rtn=-first;
				+rtn=0;
				while ((first=+first) != last) delete (-first);
				delete (-first);
				delete first;
			}
*/
/*
	Same as above but additionally decrements count as a side-effect (counting the length between first and last).
			struct count
			{
				template<typename WPointer, typename ERPointer>
				static void reject(size_type & count, WPointer out, ERPointer end)
				{
					RPointer rtn=-first;
					+rtn=0;
					for (--count; (first=+first) != last; --count) delete (-first);
					delete (-first);
					delete first;
				}
			};
*/

			// eject:

				// somewhat tested.
/*
	Erases at location of 't' and returns the new pointer at that same location.

	Assumes -t != 0 and +t != 0.
*/
			template<typename WPointer>
			static void eject(WPointer in)
			{
				WPointer out=+(+in);
				delete +in;
				+in=out;
			}
/*
	Erases everything from first to last and returns the new pointer at that same location where first was.

	No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename WPointer, typename EWPointer>
			static void eject(WPointer in, EWPointer end)
			{
				s_exte_policy::ptr::clear::no_return(+in, end);
				+in=end;
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
