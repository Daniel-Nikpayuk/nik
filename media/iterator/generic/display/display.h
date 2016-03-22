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

#ifndef NIK_MEDIA_ITERATOR_DISPLAY_H
#define NIK_MEDIA_ITERATOR_DISPLAY_H

#include"../../../../context/context/display/display.h"

#include"../../numeric/uint/uint.h"

namespace nik
{
 namespace media
 {
  namespace iterator
  {
	struct printer : public context::context::printer
	{
//		using context::context::printer::print;

/*
		template<typename ValueType>
		void print(const node<ValueType> & n)
		{
//			printf("%zu", u);
		}

		template<size_type N>
		void print(const uint<N> & u)
		{
			node<size_type> n;
			while (!u.zero())
			{
				bwd_arit::unroll<u::dimension>::divide::
				n.append();
			}

			print(n);
		}
*/
	};
  }

	iterator::printer display;
 }
}

#endif
