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
 namespace semiotic
 {
  namespace numeric
  {
   namespace random_access
   {
    namespace vector
    {
     namespace functional
     {
	template<typename SizeType>
	struct identity
	{
		typedef SizeType size_type;

		typedef iterator::componentwise::functional::policy<size_type> icf_policy;

/*
	Classified here because custom initializations are inherently unsafe: Could lead to memory leaks.
*/
		struct copy
		{
			struct initialize
			{
				template<typename WVector, typename RVector>
				static void no_return(WVector & out, const RVector & in)
				{
					out.initialize(in.length);
					icf_policy::fwd_over::assign::no_return(out.initial, in.initial, in.end());
				}

				template<typename WVector, typename RIterator, typename ERIterator>
				static void no_return(WVector & out, RIterator in, ERIterator end)
				{
					out.initialize(end-in);
					icf_policy::fwd_over::assign::no_return(out.initial, in, end);
				}
			};

			struct shallow
			{
				template<typename WVector, typename RVector>
				static void no_return(WVector & out, const RVector & in)
				{
					out.initial=in.initial;
					out.length=in.length;
				}
			};
		};
/*
	Grows the size of out by the given length.

	out a vector.
	in an uninitialized temporary vector.
	length the size to grow the array of out by.
*/
		struct grow
		{
			struct before
			{
/*
	puts the newly allocated space before the existing array.
*/
				template<typename WVector>
				static void no_return(WVector & out, WVector & in, size_type length)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length+length);
					icf_policy::fwd_over::assign::no_return(out.initial+length, in.initial, in.end());
					in.terminalize();
				}

				template<typename WVector>
				static typename WVector::iterator with_return(WVector & out, WVector & in, size_type length)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length+length);
					icf_policy::fwd_over::assign::no_return(out.initial+length, in.initial, in.end());
					in.terminalize();

					return out.initial;
				}
			};
/*
	puts the newly allocated space after the existing array.
*/
			struct after
			{
				template<typename WVector>
				static void no_return(WVector & out, WVector & in, size_type length)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length+length);
					icf_policy::fwd_over::assign::no_return(out.initial, in.initial, in.end());
					in.terminalize();
				}

				template<typename WVector>
				static typename WVector::iterator with_return(WVector & out, WVector & in, size_type length)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length+length);
					typename WVector::iterator rtn=icf_policy::fwd_over::
						assign::with_return(out.initial, in.initial, in.end());
					in.terminalize();

					return rtn;
				}
			};
/*
	puts the newly allocated space between the existing array starting at the offset.
*/
			struct between
			{
				template<typename WVector>
				static void no_return(WVector & out, WVector & in, size_type length, size_type offset)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length+length);
					typename WVector::iterator out_middle, in_middle=in.initial+offset;
					out_middle=icf_policy::fwd_over::assign::with_return(out.initial, in.initial, in_middle);
					icf_policy::fwd_over::assign::no_return(out_middle+length, in_middle, in.end());
					in.terminalize();
				}

				template<typename WVector>
				static typename WVector::iterator with_return(WVector & out, WVector & in, size_type length, size_type offset)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length+length);
					typename WVector::iterator rtn, in_middle=in.initial+offset;
					rtn=icf_policy::fwd_over::assign::with_return(out.initial, in.initial, in_middle);
					icf_policy::fwd_over::assign::no_return(rtn+length, in_middle, in.end());
					in.terminalize();

					return rtn;
				}
			};
		};
/*
	Assumes in is uninitialized.
*/
		struct shrink
		{
			struct before
			{
				template<typename WVector>
				static void no_return(WVector & out, WVector & in, size_type length)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length-length);
					icf_policy::fwd_over::assign::no_return(out.initial, in.initial+length, in.end());
					in.terminalize();
				}
			};

			struct after
			{
				template<typename WVector>
				static void no_return(WVector & out, WVector & in, size_type length)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length-length);
					icf_policy::fwd_over::assign::no_return(out.initial, in.initial, in.initial+out.length);
					in.terminalize();
				}
			};

			struct between
			{
				template<typename WVector>
				static void no_return(WVector & out, WVector & in, size_type length, size_type offset)
				{
					copy::shallow::no_return(in, out);
					out.initialize(in.length-length);
					typename WVector::iterator out_middle, in_middle=in.initial+offset;
					out_middle=icf_policy::fwd_over::assign::with_return(out.initial, in.initial, in_middle);
					icf_policy::fwd_over::assign::no_return(out_middle, in_middle+length, in.end());
					in.terminalize();
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

