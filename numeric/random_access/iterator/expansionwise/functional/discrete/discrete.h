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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_ITERATOR_EXPANSIONWISE_FUNCTIONAL_DISCRETE_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_ITERATOR_EXPANSIONWISE_FUNCTIONAL_DISCRETE_H

#include"../../../../../../../semiotic/policy/policy.h"

/*
	Generic iterator methods are classified further by "forward, backward, bidirectional, random_access",
	but as pointer specifically assumes a linked pointer there is no need for these additional namespaces.
*/

namespace nik
{
 namespace media
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace iterator
    {
     namespace expansionwise
     {
      namespace functional
      {
       namespace forward
       {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

		typedef semiotic::iterator::expansionwise::policy<SizeType> snripf_policy;

			// somewhat tested.
		struct prepend
		{
			template<typename WPointer>
			static void no_return(WPointer out, WPointer in)
			{
				+in=out;
				-out=in;
			}

			template<typename WPointer>
			static WPointer with_return(WPointer out, WPointer in)
			{
				+in=out;
				-out=in;

				return in;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static void no_return(WPointer out, ValueType value)
				{ *with_return(out, WPointer(new WNode))=value; }

			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer out, ValueType value)
			{
				WPointer in=with_return(out, WPointer(new WNode));
				*in=value;

				return in;
			}
/*
	n >= 1.
*/
			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer out, size_type n, ValueType value)
				{ return snripf_policy::bwd_over::repeat::post_test::template with_return<WNode>(out, n, value); }
/*
	in != end
*/
			struct count
			{
				template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
				static WPointer with_return(size_type & count, WPointer out, RIterator in, ERIterator end)
				{
					WPointer b=new WNode;
					WPointer e=snripf_policy::fwd_over::assign::count::template with_return<WNode>(count, b, in, end);
					no_return(out, -e);
					delete e;

					return b;
				}

				template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
				static WPointer fast_return(size_type & count, WPointer out, RIterator in, ERIterator end)
				{
					return snripf_policy::bwd_over::assign::post_test::count::template
						with_return<WNode>(count, out, end, in);
				}
			};
		};

			// somewhat tested.
		struct append
		{
			template<typename WPointer>
			static void no_return(WPointer out, WPointer in)
			{
				+out=in;
				-in=out;
			}

			template<typename WPointer>
			static WPointer with_return(WPointer out, WPointer in)
			{
				+out=in;
				-in=out;

				return in;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static void no_return(WPointer out, ValueType value)
				{ *with_return(out, WPointer(new WNode))=value; }

			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer out, ValueType value)
			{
				WPointer in=with_return(out, WPointer(new WNode));
				*in=value;

				return in;
			}
/*
	n >= 1.
*/
			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer out, size_type n, ValueType value)
				{ return snripf_policy::fwd_over::repeat::post_test::template with_return<WNode>(out, n, value); }
/*
	in != end
*/
			struct count
			{
				template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
				static WPointer with_return(size_type & count, WPointer out, RIterator in, ERIterator end)
				{
					WPointer b=with_return(out, WPointer(new WNode));
					return snripf_policy::fwd_over::assign::count::template with_return<WNode>(count, b, in, end);
				}
			};
		};

			// somewhat tested.
		struct impend
		{
			template<typename WPointer>
			static WPointer no_return(WPointer out, WPointer in)
			{
				+(-out)=in;
				-in=-out;
				+in=out;
				-out=in;
			}

			template<typename WPointer>
			static WPointer with_return(WPointer out, WPointer in)
			{
				+(-out)=in;
				-in=-out;
				+in=out;
				-out=in;

				return in;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer no_return(WPointer out, ValueType value)
				{ *with_return(out, WPointer(new WNode))=value; }

			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer out, ValueType value)
			{
				WPointer in=with_return(out, WPointer(new WNode));
				*in=value;

				return in;
			}
/*
	n >= 1.
*/
			template<typename WNode, typename WPointer, typename ValueType>
			static WPointer with_return(WPointer out, size_type n, ValueType value)
			{
				return append::with_return(-out,
					snripf_policy::bwd_over::repeat::post_test::template with_return<WNode>(out, n, value));
			}
/*
	first != last:

	Semantically nothing changes if (first == last), but a bit of unnecessary work is still done.
*/
			struct count
			{
				template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
				static WPointer with_return(size_type & count, WPointer out, RIterator in, ERIterator end)
				{
					WPointer b=new WNode;
					WPointer e=snripf_policy::fwd_over::assign::count::template with_return<WNode>(count, b, in, end);
					no_return(out, -e);
					delete e;

					return b;
				}

				template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
				static WPointer fast_return(size_type & count, WPointer out, RIterator in, ERIterator end)
				{
					return append::with_return(-out,
							snripf_policy::bwd_over::assign::post_test::count::template
								with_return<WNode>(count, out, end, in));
				}
			};
		};

			// not really tested.
		struct deject
		{
/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
*/
			template<typename WPointer>
			static void no_return(WPointer out) { delete -++out; }

			template<typename WPointer>
			static WPointer with_return(WPointer out)
			{
				delete -++out;

				return out;
			}
/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename WPointer, typename EWPointer>
			static void no_return(WPointer out, EWPointer end)
				{ snripf_policy::ptr::clear::no_return(out, end); }

			template<typename WPointer, typename EWPointer>
			static WPointer with_return(WPointer out, EWPointer end)
			{
				snripf_policy::ptr::clear::no_return(out, end);

				return end;
			}

			struct count
			{
				template<typename WPointer, typename EWPointer>
				static void no_return(size_type & count, WPointer out, EWPointer end)
					{ snripf_policy::ptr::clear::count::no_return(count, out, end); }

				template<typename WPointer, typename EWPointer>
				static WPointer with_return(size_type & count, WPointer out, EWPointer end)
				{
					snripf_policy::ptr::clear::count::no_return(count, out, end);

					return end;
				}
			};
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
			static void no_return(WPointer out)
			{
				WPointer in=+out;
				+(-out)=in;
				-in=-out;
				delete out;
			}

			template<typename WPointer>
			static WPointer with_return(WPointer out)
			{
				WPointer in=+out;
				+(-out)=in;
				-in=-out;
				delete out;

				return in;
			}
/*
	Erases everything from first to last and returns the new pointer at that same location where first was.

	No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename WPointer, typename EWPointer>
			static void no_return(WPointer out, EWPointer end)
			{
				WPointer in=-out;
				snripf_policy::ptr::clear::no_return(out, end);
				+in=end;
				-end=in;
			}

			template<typename WPointer, typename EWPointer>
			static WPointer with_return(WPointer out, EWPointer end)
			{
				WPointer in=-out;
				snripf_policy::ptr::clear::no_return(out, end);
				+in=end;
				-end=in;

				return end;
			}

			struct count
			{
				template<typename WPointer, typename EWPointer>
				static void no_return(size_type & count, WPointer out, EWPointer end)
				{
					WPointer in=-out;
					snripf_policy::ptr::clear::count::no_return(count, out, end);
					+in=end;
					-end=in;
				}

				template<typename WPointer, typename EWPointer>
				static WPointer with_return(size_type & count, WPointer out, EWPointer end)
				{
					WPointer in=-out;
					snripf_policy::ptr::clear::count::no_return(count, out, end);
					+in=end;
					-end=in;

					return end;
				}
			};
		};

		struct clear
		{
			template<typename WPointer, typename ERPointer>
			static void no_return(WPointer out, ERPointer end)
				{ while (out != end) delete -(++out); }

			struct count
			{
				template<typename WPointer, typename ERPointer>
				static void no_return(size_type & count, WPointer out, ERPointer end)
				{
					while (out != end)
					{
						delete -(++out);
						--count;
					}
				}
			};
		};

		template<size_type N, size_type M=0, size_type L=0>
		struct unroll
		{
			struct clear
			{
				template<typename WPointer, typename ERPointer>
				static void no_return(WPointer out, ERPointer end)
				{
					delete -(++out);
					unroll<N-1>::clear::no_return(out, end);
				}
			};
		};

		template<size_type M, size_type L>
		struct unroll<0, M, L>
		{
			struct clear
			{
				template<typename WPointer, typename ERPointer>
				static void no_return(WPointer out, ERPointer end)
					{ }
			};
		};
	};
       }

       namespace backward
       {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

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

       namespace bidirectional
       {
	template<typename SizeType>
	struct discrete
	{
		typedef SizeType size_type;

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
 }
}

#endif
