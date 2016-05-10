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

#ifndef NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_LIST_IDENTITY_H
#define NIK_CONTEXT_SEMIOTIC_ITERATOR_EXTENSIONWISE_LIST_IDENTITY_H

#include"../../pointer/policy/policy.h"

namespace nik
{
 namespace context
 {
  namespace semiotic
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

		typedef pointer::policy<size_type> sitp_policy;

/*
	Classified here because custom initializations are inherently unsafe: Could lead to memory leaks.
*/
		struct initialize
		{
			struct disjoint
			{
				template<typename WList>
				static void no_return(WList & out)
				{
					out.initial=new typename WList::node;
					out.terminal=new typename WList::node;
					+out.initial=out.terminal;
				}
			};
		};

/*
	Classified here because custom initializations are inherently unsafe: Could lead to memory leaks.
*/
		struct copy
		{
			struct initialize
			{
				template<typename WList, typename RList>
				static void no_return(WList & out, const RList & in)
				{
					out.initialize();
					out.terminal=sitp_policy::fwd_over::assign::template
						with_return<typename WList::node>(out.terminal, in.initial, in.terminal);
				}

				struct prepost
				{
					template<typename WList, typename RIterator, typename ERIterator>
					static void no_return(WList & out, RIterator in, ERIterator end)
					{
						out.initialize();
						out.terminal=sitp_policy::disc::copy::before::template
							with_return<typename WList::node>(out.terminal, in, end);
					}
				};

				struct disjoint
				{
					template<typename WList, typename RList>
					static void no_return(WList & out, const RList & in)
					{
						initialize::disjoint::no_return(out);
						out.terminal=sitp_policy::fwd_over::assign::template
							with_return<typename WList::node>(out.terminal, +in.initial, in.terminal);
					}
				};
			};

			struct shallow
			{
				template<typename WList, typename RList>
				static void no_return(WList & out, const RList & in)
				{
					out.initial=in.initial;
					out.terminal=in.terminal;
				}
			};
		};
/*
*/
		struct grow
		{
/*
*/
			struct before
			{
				template<typename WList, typename WPointer>
				static void no_return(WList & out, WPointer in)
				{
					+in=out.initial;
					out.initial=in;
				}

				template<typename WList, typename WPointer>
				static WPointer with_return(WList & out, WPointer in)
				{
					+in=out.initial;
					out.initial=in;

					return in;
				}

				template<typename WList, typename WPointer>
				static void no_return(WList & out, WPointer in, WPointer end)
				{
					+end=out.initial;
					out.initial=in;
				}

				template<typename WList, typename WPointer>
				static WPointer with_return(WList & out, WPointer in, WPointer end)
				{
					+end=out.initial;
					out.initial=in;

					return in;
				}
			};
/*
*/
			struct after
			{
				template<typename WList, typename WPointer>
				static void no_return(WList & out, WPointer in)
					{ out.terminal=+out.terminal=in; }

				template<typename WList, typename WPointer>
				static WPointer with_return(WList & out, WPointer in)
				{
					out.terminal=+out.terminal=in;

					return in;
				}

				template<typename WList, typename WPointer>
				static void no_return(WList & out, WPointer in, WPointer end)
				{
					+out.terminal=in;
					out.terminal=end;
				}

				template<typename WList, typename WPointer>
				static WPointer with_return(WList & out, WPointer in, WPointer end)
				{
					+out.terminal=in;
					out.terminal=end;

					return end;
				}
			};
/*
	Slightly awkward grammar, but categorization of this algorithm within the larger design takes precidence.
*/
			struct between
			{
				template<typename WList, typename WPointer>
				static void no_return(typename WList::iterator out, WPointer in)
				{
					+in=+out;
					+out=in;
				}

				template<typename WList, typename WPointer>
				static WPointer with_return(typename WList::iterator out, WPointer in)
				{
					+in=+out;
					+out=in;

					return in;
				}

				template<typename WList, typename WPointer>
				static void no_return(typename WList::iterator out, WPointer in, WPointer end)
				{
					+end=+out;
					+out=in;
				}

				template<typename WList, typename WPointer>
				static WPointer with_return(typename WList::iterator out, WPointer in, WPointer end)
				{
					+end=+out;
					+out=in;

					return in;
				}
			};
		};
/*
*/
		struct shrink
		{
/*
*/
			struct before
			{
				template<typename WList>
				static void no_return(WList & out)
					{ delete out.initial++; }
/*
*/
				template<typename WList, typename WPointer>
				static void no_return(WList & out, WPointer end)
				{
					sitp_policy::disc::clear::no_return(out.initial, end);
					out.initial=end;
				}
			};
/*
*/
			struct after
			{
				struct fast
				{
					template<typename WList, typename WPointer>
					static void no_return(WList & out, WPointer in)
					{
						delete out.terminal;
						out.terminal=in;
					}
				};

				template<typename WList, typename WPointer>
				static void no_return(WList & out, WPointer in)
				{
					sitp_policy::disc::clear::no_return(+in, out.terminal);
					delete out.terminal;
					out.terminal=in;
				}
			};
/*
	Slightly awkward grammar, but categorization of this algorithm within the larger design takes precidence.
*/
			struct between
			{
				template<typename WList>
				static void no_return(typename WList::iterator out)
				{
					typename WList::iterator in=+(+out);
					delete +out;
					+out=in;
				}

				template<typename WList, typename WPointer>
				static void no_return(typename WList::iterator out, WPointer end)
				{
					sitp_policy::disc::clear::no_return(+out, end);
					+out=end;
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

#endif
