/************************************************************************************************************************
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
************************************************************************************************************************/

namespace nik
{
 namespace media
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace chain
    {
     namespace functional
     {
	template<typename SizeType>
	struct identity
	{
		typedef SizeType size_type;

		typedef semiotic::policy<size_type>::nripf snripf_policy;
		typedef semiotic::policy<size_type>::nrcf snrcf_policy;

		struct insert
		{
			// prepend:

				// somewhat tested.

			template<typename WPointer>
			static void prepend(WPointer out, WPointer in)
			{
				+in=out;
				-out=in;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static void prepend(WPointer out, ValueType value)
				{ *with_return(out, WPointer(new WNode))=value; }
/*
	n >= 1.
*/
			template<typename WNode, typename WPointer, typename ValueType>
			static void prepend(WPointer out, size_type n, ValueType value)
				{ s_expa_policy::bwd_over::repeat::post_test::template no_return<WNode>(out, n, value); }

			// append:

				// somewhat tested.

			template<typename WPointer>
			static void append(WPointer out, WPointer in)
			{
				+out=in;
				-in=out;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static void append(WPointer out, ValueType value)
				{ *with_return(out, WPointer(new WNode))=value; }
/*
	n >= 1.
*/
			template<typename WNode, typename WPointer, typename ValueType>
			static void append(WPointer out, size_type n, ValueType value)
				{ s_expa_policy::fwd_over::repeat::post_test::template no_return<WNode>(out, n, value); }

			// impend:

				// somewhat tested.

			template<typename WPointer>
			static void impend(WPointer out, WPointer in)
			{
				+(-out)=in;
				-in=-out;
				+in=out;
				-out=in;
			}

			template<typename WNode, typename WPointer, typename ValueType>
			static void impend(WPointer out, ValueType value)
				{ *with_return(out, WPointer(new WNode))=value; }
/*
	n >= 1.
*/
			template<typename WNode, typename WPointer, typename ValueType>
			static void impend(WPointer out, size_type n, ValueType value)
			{
				append::no_return(-out,
					s_expa_policy::bwd_over::repeat::post_test::template with_return<WNode>(out, n, value));
			}

			struct count
			{
/*
	in != end
*/
				template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
				static void prepend(size_type & count, WPointer out, RIterator in, ERIterator end)
				{
					WPointer b=new WNode;
					WPointer e=s_expa_policy::fwd_over::assign::count::template with_return<WNode>(count, b, in, end);
					no_return(out, -e);
					delete e;
				}
/*
	in != end
*/
				template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
				static void append(size_type & count, WPointer out, RIterator in, ERIterator end)
				{
					WPointer b=with_return(out, WPointer(new WNode));
					s_expa_policy::fwd_over::assign::count::template no_return<WNode>(count, b, in, end);
				}
/*
	first != last:

	Semantically nothing changes if (first == last), but a bit of unnecessary work is still done.
*/
				template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
				static void impend(size_type & count, WPointer out, RIterator in, ERIterator end)
				{
					WPointer b=new WNode;
					WPointer e=s_expa_policy::fwd_over::assign::count::template with_return<WNode>(count, b, in, end);
					no_return(out, -e);
					delete e;
				}

				struct fast
				{
					template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
					static void prepend(size_type & count, WPointer out, RIterator in, ERIterator end)
					{
						s_expa_policy::bwd_over::assign::post_test::count::template
							no_return<WNode>(count, out, end, in);
					}

					template<typename WNode, typename WPointer, typename RIterator, typename ERIterator>
					static void impend(size_type & count, WPointer out, RIterator in, ERIterator end)
					{
						append::no_return(-out,
								s_expa_policy::bwd_over::assign::post_test::count::template
									with_return<WNode>(count, out, end, in));
					}
				};
			};
		};

		struct erase
		{
			// deject:

				// not really tested.

/*
	Assumes 't' is the original front: detaches 't'; deletes 't'; returns the new front.

	Does not detach new front from original front resulting in a dangling pointer.
*/
			template<typename WPointer>
			static void deject(WPointer out) { delete -++out; }
/*
	Pops everything from first to last while returning last.

	Assumes first is the proper front.  No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename WPointer, typename EWPointer>
			static void deject(WPointer out, EWPointer end)
				{ s_expa_policy::ptr::clear::no_return(out, end); }

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

			// eject:

				// somewhat tested.
/*
	Erases at location of 't' and returns the new pointer at that same location.

	Assumes -t != 0 and +t != 0.
*/
			template<typename WPointer>
			static void eject(WPointer out)
			{
				WPointer in=+out;
				+(-out)=in;
				-in=-out;
				delete out;
			}
/*
	Erases everything from first to last and returns the new pointer at that same location where first was.

	No need for generic Iterator as you are erasing from a given structure.
*/
			template<typename WPointer, typename EWPointer>
			static void eject(WPointer out, EWPointer end)
			{
				WPointer in=-out;
				s_expa_policy::ptr::clear::no_return(out, end);
				+in=end;
				-end=in;
			}

			struct count
			{
				template<typename WPointer, typename EWPointer>
				static void deject(size_type & count, WPointer out, EWPointer end)
					{ s_expa_policy::ptr::clear::count::no_return(count, out, end); }

/*
				template<typename WPointer, typename ERPointer>
				static void reject(size_type & count, WPointer out, ERPointer end)
				{
					RPointer rtn=-first;
					+rtn=0;
					for (--count; (first=+first) != last; --count) delete (-first);
					delete (-first);
					delete first;
				}
*/

				template<typename WPointer, typename EWPointer>
				static void eject(size_type & count, WPointer out, EWPointer end)
				{
					WPointer in=-out;
					s_expa_policy::ptr::clear::count::no_return(count, out, end);
					+in=end;
					-end=in;
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

