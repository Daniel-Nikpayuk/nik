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

#ifndef NIK_MEDIA_NUMERIC_RANDOM_ACCESS_CHAIN_STRUCTURAL_BASE_DEBUG_H
#define NIK_MEDIA_NUMERIC_RANDOM_ACCESS_CHAIN_STRUCTURAL_BASE_DEBUG_H

#include"../base.h"
#include"../../../../../../../debug.h"

/*
	Make sure to consider composition of grammar as part of testing.
*/

namespace nik
{
 namespace debug
 {
	struct chain
	{
		typedef media::chain<int> chain_type;
/*
		chain c;
		nik::display << "size: " << c.size() << nik::endl;

		c.insert(c.begin(), 5);
		c.insert(c.begin(), 4);
		c.insert(c.end(), 6);

		nik::media::display << c << nik::endl;
		nik::display << "size: " << c.size() << nik::endl;

		c.insert(c.begin(), 5, 3);
		nik::media::display << c << nik::endl;
		nik::display << "size: " << c.size() << nik::endl;

		chain d;
		nik::display << "size: " << d.size() << nik::endl;

		d.insert(d.begin(), c.begin(), c.end());
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;

		d.insert(d.end(), 17);
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;

		d.erase(d.begin());
		d.erase(-d.end());
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;

		d.erase(+d.begin(), d.end());
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;

		d.push_back(11);
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;

		d.pop_back();
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;

		d.push_front(11);
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;

		d.pop_front();
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;

		d.swap(c);
		nik::media::display << c << nik::endl;
		nik::display << "size: " << c.size() << nik::endl;
		nik::media::display << d << nik::endl;
		nik::display << "size: " << d.size() << nik::endl;
*/

		static void constructors()
		{
			chain_type l;

			chain_type m(l);
		}

		static void assignment_operator()
		{
		}

		static void comparison()
		{
		}

		static void clear()
		{
/*
			chain_type m;
			m.clear();
			nik::media::display << m << nik::endl;
*/
		}

		static void insert_after()
		{
			chain_type l;

			l.insert_after(l.before_begin(), 3, 5);
			l.insert_after(l.before_begin(), 3);
			l.insert_after(l.before_begin(), 1);
			l.insert_after(l.begin(), 2);

			nik::media::display << l << nik::endl;
/*
			chain_type m;
			m.insert_after(m.before_begin(), l.begin(), l.end());
			nik::media::display << m << nik::endl;
*/
		}

		static void erase_after()
		{
/*
			chain_type m;
			m.erase_after(m.before_begin());
			nik::media::display << m << nik::endl;

			m.erase_after(m.begin());
			nik::media::display << m << nik::endl;

			m.erase_after(m.begin(), m.end());
			nik::media::display << m << nik::endl;

			m.erase_after(m.before_begin());
			nik::media::display << m << nik::endl;
*/
		}

		static void push_front()
		{
/*
			chain_type m;
			m.push_front(7);
			nik::media::display << m << nik::endl;
*/
		}

		static void pop_front()
		{
/*
			chain_type m;
			m.pop_front();
			nik::media::display << m << nik::endl;
*/
		}

		static void swap()
		{
/*
			chain_type m;
			m.swap(l);
			nik::media::display << l << nik::endl;
			nik::media::display << m << nik::endl;
			nik::media::display << m << nik::endl;
*/
		}
	};
 }
}

#endif
