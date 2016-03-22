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

#ifndef NIK_SEMIOTIC_ITERATOR_DISPLAY_H
#define NIK_SEMIOTIC_ITERATOR_DISPLAY_H

#include"../../../context/context/display/display.h"

#include"../block/block.h"

namespace nik
{
 namespace semiotic
 {
  namespace iterator
  {
	struct printer : public context::context::printer
	{
//		using context::context::printer::print;
/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
		template<size_t N, size_t M=0, size_t L=0>
		struct unroll
		{
			template<typename Iterator>
			static void block(Iterator i, const char *format)
			{
				printf(format, *i);
				unroll<N-1>::block(--i, format);
			}
		};

		template<size_t M, size_t L>
		struct unroll<0, M, L>
		{
			template<typename Iterator>
			static void block(Iterator i, const char *format)
				{ }
		};

		template<typename Block> void print(const Block & v)
			{ unroll<Block::dimension>::block(v.end()-1, "%zu "); }
	};
  }

	iterator::printer display;
 }
}

#endif
