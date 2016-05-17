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

#ifndef NIK_MEDIA_NUMERIC_PROCESSOR_PRINTER_H
#define NIK_MEDIA_NUMERIC_PROCESSOR_PRINTER_H

#include<stdint.h>
#include<stdio.h>

namespace nik
{
 namespace media
 {
  namespace numeric
  {
   namespace processor
   {
	template<typename SizeType>
	struct printer
	{
		typedef SizeType size_type;

		void print(int v) { printf("%d", v); }
		void print(unsigned int v) { printf("%u", v); }
		void print(intmax_t v) { printf("%jd", v); }
		void print(uintmax_t v) { printf("%ju", v); }

		void print(char v) { printf("%c", v); }
		void print(const char *v) { printf("%s", v); }
		void print(bool v) { printf("%s", v? "true" : "false"); }
	};

	template<typename S, typename T>
	S & operator << (S & s, T v)
	{
		s.print(v);
		return s;
	}
   }
  }
 }
}

#endif
