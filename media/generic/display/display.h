/*************************************************************************************************************************
**
** Copyright 2015 Daniel Nikpayuk, Inuit Nunangat, The Inuit Nation
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

#ifndef MEDIA_DISPLAY_H
#define MEDIA_DISPLAY_H

#include<stdio.h>

#include"../../../context/block/block.h"

namespace nik
{
	namespace media
	{
		struct printer
		{
			void print(int v) { printf("%d", v); }
			void print(char v) { printf("%c", v); }
		};

		struct verbatim_printer
		{
			void print(int v) { printf("%d", v); }
			void print(char v) { printf("%c", v); }
/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
			template<typename Iterator, size_t N>
			struct _block
			{
				static void print(const char *format, Iterator i)
				{
					printf(format, *i);
					_block<Iterator, N-1>::print(format, --i);
				}
			};

			template<typename Iterator>
			struct _block<Iterator, 1>
			{
				static void print(const char *format, Iterator i) { printf(format, *i); }
			};

			template<typename Block> void print(const Block & v)
				{ _block<typename Block::const_iterator, Block::dimension>::print("%zu ", v.end()-1); }
		};

		template<typename S, typename T>
		S & operator << (S & s, T v)
		{
			s.print(v);
			return s;
		}
	}

	char endl='\n'; // portable ?

	media::printer display;
	media::verbatim_printer display_verbatim;
}

#endif
