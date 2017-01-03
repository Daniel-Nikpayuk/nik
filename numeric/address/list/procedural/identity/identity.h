/************************************************************************************************************************
**
** Copyright 2015, 2016, 2017 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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
     namespace functional
     {
	template<typename SizeType>
	struct identity
	{
		typedef SizeType size_type;

		typedef semiotic::policy<size_type>::nritf snritf_policy;
		typedef semiotic::policy<size_type>::nrlf snrlf_policy;

		struct insert
		{
				// not really tested.
			struct prepend
			{
				template<typename WList, typename ValueType>
				static void no_return(WList & out, ValueType value)
					{ *snrlf_policy::iden::grow::before::with_return(out, new typename WList::node)=value; }

				template<typename WList, typename ValueType>
				static typename WList::iterator with_return(WList & out, ValueType value)
				{
					*snrlf_policy::iden::grow::before::no_return(out, new typename WList::node)=value;

					return out.initial;
				}
/*
	n >= 1.
*/
				template<typename WList, typename ValueType>
				static void no_return(WList & out, size_type n, ValueType value)
				{
					typename WList::iterator in=new typename WList::node;
					*in=value;
					snrlf_policy::iden::grow::before::no_return(out, in,
						snritf_policy::fwd_over::repeat::post_test::template
							with_return<typename WList::node>(in, n-1, value));
				}

				template<typename WList, typename ValueType>
				static typename WList::iterator with_return(WList & out, size_type n, ValueType value)
				{
					typename WList::iterator in=new typename WList::node;
					*in=value;
					return snrlf_policy::iden::grow::before::with_return(out, in,
						snritf_policy::fwd_over::repeat::post_test::template
							with_return<typename WList::node>(in, n-1, value));
				}
/*
	in != end
*/
				template<typename WList, typename RIterator, typename ERIterator>
				static void no_return(WList & out, RIterator in, ERIterator end)
				{
					typename WList::iterator tmp=new typename WList::node;
					snrlf_policy::iden::grow::before::no_return(out, tmp,
						snritf_policy::disc::assign::prepost::template
							with_return<typename WList::node>(tmp, in, end));
				}

				template<typename WList, typename RIterator, typename ERIterator>
				static typename WList::iterator with_return(WList & out, RIterator in, ERIterator end)
				{
					typename WList::iterator tmp=new typename WList::node;
					return snrlf_policy::iden::grow::before::with_return(out, tmp,
						snritf_policy::disc::assign::prepost::template
							with_return<typename WList::node>(tmp, in, end));
				}
			};

				// not really tested.
			struct append
			{
				template<typename WList, typename ValueType>
				static void no_return(WList & out, ValueType value)
					{ *snrlf_policy::iden::grow::after::with_return(out, new typename WList::node)=value; }

				template<typename WList, typename ValueType>
				static typename WList::iterator with_return(WList & out, ValueType value)
				{
					*snrlf_policy::iden::grow::after::no_return(out, new typename WList::node)=value;

					return out.terminal;
				}
/*
	n >= 1.
*/
				template<typename WList, typename ValueType>
				static void no_return(WList & out, size_type n, ValueType value)
				{
					typename WList::iterator in=new typename WList::node;
					*in=value;
					snrlf_policy::iden::grow::after::no_return(out, in,
						snritf_policy::fwd_over::repeat::post_test::template
							with_return<typename WList::node>(in, n-1, value));
				}

				template<typename WList, typename ValueType>
				static typename WList::iterator with_return(WList & out, size_type n, ValueType value)
				{
					typename WList::iterator in=new typename WList::node;
					*in=value;
					return snrlf_policy::iden::grow::after::with_return(out, in,
						snritf_policy::fwd_over::repeat::post_test::template
							with_return<typename WList::node>(in, n-1, value));
				}

				template<typename WList, typename RIterator, typename ERIterator>
				static void no_return(WList & out, RIterator in, ERIterator end)
				{
					typename WList::iterator tmp=new typename WList::node;
					snrlf_policy::iden::grow::after::no_return(out, tmp,
						snritf_policy::fwd_over::assign::template
							with_return<typename WList::node>(tmp, in, end));
				}

				template<typename WList, typename RIterator, typename ERIterator>
				static typename WList::iterator with_return(WList & out, RIterator in, ERIterator end)
				{
					typename WList::iterator tmp=new typename WList::node;
					return snrlf_policy::iden::grow::after::with_return(out, tmp,
						snritf_policy::fwd_over::assign::template
							with_return<typename WList::node>(tmp, in, end));
				}

				struct prepost
				{
/*
	in != end
*/
					template<typename WList, typename RIterator, typename ERIterator>
					static void no_return(WList & out, RIterator in, ERIterator end)
					{
						typename WList::iterator tmp=new typename WList::node;
						snrlf_policy::iden::grow::after::no_return(out, tmp,
							snritf_policy::disc::assign::prepost::template
								with_return<typename WList::node>(tmp, in, end));
					}

					template<typename WList, typename RIterator, typename ERIterator>
					static typename WList::iterator with_return(WList & out, RIterator in, ERIterator end)
					{
						typename WList::iterator tmp=new typename WList::node;
						return snrlf_policy::iden::grow::after::with_return(out, tmp,
							snritf_policy::disc::assign::prepost::template
								with_return<typename WList::node>(tmp, in, end));
					}
				};
			};

				// not really tested.
			struct impend
			{
				template<typename WList, typename ValueType>
				static void no_return(WList & out, ValueType value)
					{ *snrlf_policy::iden::grow::between::with_return(out, new typename WList::node)=value; }

				template<typename WList, typename ValueType>
				static typename WList::iterator with_return(WList & out, ValueType value)
				{
					*snrlf_policy::iden::grow::between::no_return(out, new typename WList::node)=value;

					return out.initial;
				}
/*
	n >= 1.
*/
				template<typename WList, typename ValueType>
				static void no_return(WList & out, size_type n, ValueType value)
				{
					typename WList::iterator in=new typename WList::node;
					*in=value;
					snrlf_policy::iden::grow::between::no_return(out, in,
						snritf_policy::fwd_over::repeat::post_test::template
							with_return<typename WList::node>(in, n-1, value));
				}

				template<typename WList, typename ValueType>
				static typename WList::iterator with_return(WList & out, size_type n, ValueType value)
				{
					typename WList::iterator in=new typename WList::node;
					*in=value;
					return snrlf_policy::iden::grow::between::with_return(out, in,
						snritf_policy::fwd_over::repeat::post_test::template
							with_return<typename WList::node>(in, n-1, value));
				}
/*
	in != end
*/
				template<typename WList, typename RIterator, typename ERIterator>
				static void no_return(WList & out, RIterator in, ERIterator end)
				{
					typename WList::iterator tmp=new typename WList::node;
					snrlf_policy::iden::grow::between::no_return(out, tmp,
						snritf_policy::disc::assign::prepost::template
							with_return<typename WList::node>(tmp, in, end));
				}

				template<typename WList, typename RIterator, typename ERIterator>
				static typename WList::iterator with_return(WList & out, RIterator in, ERIterator end)
				{
					typename WList::iterator tmp=new typename WList::node;
					return snrlf_policy::iden::grow::between::with_return(out, tmp,
						snritf_policy::disc::assign::prepost::template
							with_return<typename WList::node>(tmp, in, end));
				}
			};
		};

		struct erase
		{
				// not really tested.
			struct deject
			{
/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
				template<typename WPointer>
				static void no_return(WPointer out)
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
				static void no_return(WPointer out, ERPointer end)
				{
					-last=0;
					while ((first=+first) != last) delete (-first);
					delete (-first);
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
				static void no_return(WPointer out)
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
				static void no_return(WPointer out, ERPointer end)
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
					static void no_return(size_type & count, WPointer out, ERPointer end)
					{
						RPointer rtn=-first;
						+rtn=0;
						for (--count; (first=+first) != last; --count) delete (-first);
						delete (-first);
						delete first;
					}
				};
*/
			};

			struct eject
			{
/*
*/
				template<typename WPointer>
				static void no_return(WPointer out)
				{
					WPointer in=+(+out);
					delete +out;
					+out=in;
				}

				template<typename WPointer>
				static WPointer with_return(WPointer out)
				{
					WPointer in=+(+out);
					delete +out;
					+out=in;

					return in;
				}
/*
*/
				template<typename WPointer, typename EWPointer>
				static void no_return(WPointer out, EWPointer end)
				{
					clear::no_return(+out, end);
					+out=end;
				}

				template<typename WPointer, typename EWPointer>
				static WPointer with_return(WPointer out, EWPointer end)
				{
					clear::no_return(+out, end);
					+out=end;

					return end;
				}
			};
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

