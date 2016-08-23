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
 namespace semiotic
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

		typedef iterator::expansionwise::functional::policy<size_type> ipf_policy;

/*
	Classified here because custom initializations are inherently unsafe: Could lead to memory leaks.
*/
		struct initialize
		{
			struct disjoint
			{
				template<typename WChain>
				static void no_return(WChain & out)
				{
					out.initial=new typename WChain::node;
					out.terminal=new typename WChain::node;
					+out.initial=out.terminal;
					-out.terminal=out.initial;
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
				template<typename WChain, typename RChain>
				static void no_return(WChain & out, const RChain & in)
				{
					out.initialize();
					out.terminal=ipf_policy::fwd_over::assign::template
						with_return<typename WChain::node>(out.terminal, in.initial, in.terminal);
				}

				struct disjoint
				{
					template<typename WChain, typename RChain>
					static void no_return(WChain & out, const RChain & in)
					{
						initialize::disjoint::no_return(out);
						out.terminal=ipf_policy::fwd_over::assign::template
							with_return<typename WChain::node>(out.terminal, +in.initial, in.terminal);
					}
				};
			};

			struct shallow
			{
				template<typename WChain, typename RChain>
				static void no_return(WChain & out, const RChain & in)
				{
					out.initial=in.initial;
					out.terminal=in.terminal;
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

