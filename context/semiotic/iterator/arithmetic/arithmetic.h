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

#ifndef CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_H
#define CONTEXT_SEMIOTIC_ITERATOR_ARITHMETIC_H

// overhead dependencies:

#include"arithmetic_1.h"

/*
	The main difference between "componentwise" and "arithmetic" from an algorithmic lens is that with componentwise is
	each location is conditionally independent, whereas arithmetic is similar but also dependent on the previous value
	(recursive; maybe the simplest variety of recursive?).

	Incrementing and decrementing pointers which should otherwise maintain a constant location is bad practice in general,
	but is here used for optimized efficiency.

	Template unrolling is very memory expensive. The tradeoff in theory is speed improvement---though that should be tested
	regardless. The assumption is if you're using these such unrolling in the first place you have some memory to spare;
	as well, it's expected you're doing some heavy number theoretic computations and so the speed optimization is preferred.
*/

namespace nik
{
 namespace context
 {
  namespace semiotic
  {
   namespace iterator
   {
    namespace forward
    {
	template<typename size_type>
	struct arithmetic : public arithmetic_1<size_type>
	{
		typedef meta::constant<size_type> constant;

		template<size_type N, typename Filler=void>
		struct unroll : public arithmetic::template unroll_1<N, Filler>
		{
		};

		template<typename Filler>
		struct unroll<0, Filler>
		{
		};
	};
    }

    namespace backward
    {
	template<typename size_type>
	struct arithmetic : public arithmetic_1<size_type>
	{
		typedef meta::constant<size_type> constant;

		template<size_type N, typename Filler=void>
		struct unroll : public arithmetic::template unroll_1<N, Filler>
		{
		};

		template<typename Filler>
		struct unroll<0, Filler>
		{
		};
	};
    }

    namespace bidirectional
    {
	template<typename size_type>
	struct arithmetic : public arithmetic_1<size_type>
	{
		template<size_type N, typename Filler=void>
		struct unroll : public arithmetic::template unroll_1<N, Filler>
		{
		};

		template<typename Filler>
		struct unroll<0, Filler>
		{
		};
	};
    }
    
    namespace random_access
    {
	template<typename size_type>
	struct arithmetic : public arithmetic_1<size_type>
	{
		template<size_type N, typename Filler=void>
		struct unroll : public arithmetic::template unroll_1<N, Filler>
		{
			template<size_type M, typename SubFiller=void>
			struct subroll : public unroll::template subroll_1<M, SubFiller>
			{
			};

			template<typename SubFiller>
			struct subroll<0, SubFiller>
			{
			};
		};

		template<typename Filler>
		struct unroll<0, Filler>
		{
		};
	};
    }
   }
  }
 }
}

#endif
