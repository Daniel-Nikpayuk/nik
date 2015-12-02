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

#ifndef MEDIA_ITERATOR_DISPLAY_H
#define MEDIA_ITERATOR_DISPLAY_H

#include<stddef.h>
#include<stdint.h>
#include<stdio.h>

#include"../../../../context/media/iterator/arithmetic/arithmetic.h"

namespace nik
{
	namespace media
	{
		namespace iterator
		{
			struct _printer
			{
				void print(int v) { printf("%d", v); }
				void print(unsigned int v) { printf("%u", v); }
				void print(intmax_t v) { printf("%jd", v); }
				void print(uintmax_t v) { printf("%ju", v); }

				void print(char v) { printf("%c", v); }
				void print(const char *v) { printf("%s", v); }
			};

			struct printer : public _printer
			{
				using _printer::print;
			};

			struct verbatim_printer : public _printer
			{
				using _printer::print;
/*
	Assumes descending order.
	
	Decrementing the pointers is bad practice in general, but is here optimized for efficiency.
*/
				template<size_t N, typename Filler=void>
				struct block
				{
					template<typename Iterator>
					static void print(const char *format, Iterator i)
					{
						printf(format, *i);
						block<N-1>::print(format, --i);
					}
				};

				template<typename Filler>
				struct block<1, Filler>
				{
					template<typename Iterator>
					static void print(const char *format, Iterator i) { printf(format, *i); }
				};

				template<typename Block> void print(const Block & v)
					{ block<Block::dimension>::print("%zu ", v.end()-1); }
			};

			template<typename S, typename T>
			S & operator << (S & s, T v)
			{
				s.print(v);
				return s;
			}
		}
	}

	char endl='\n'; // portable ?

	media::iterator::printer display;
	media::iterator::verbatim_printer display_verbatim;
}

#endif
